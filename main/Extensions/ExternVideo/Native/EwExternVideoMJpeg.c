/*******************************************************************************
*
* Embedded Wizard - GUI Solutions by TARA Systems
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This software is provided as example code to demonstrate the use of Embedded
* Wizard and related software components. It may be used in production systems
* after you have reviewed, tested and adapted it to your specific requirements.
*
* Use of this example code is subject to the Embedded Wizard license terms
* (as published at https://www.embedded-wizard.de/legal), including in
* particular:
*
*   - Embedded Wizard Terms and Conditions (EWTC)
*   - Embedded Wizard License Agreement (EWLA)
*   - Embedded Wizard Community License (EWCL)
*
* The specific agreement(s) applicable to you depend on your contractual
* relationship with TARA Systems GmbH and/or your use of the Community License.
*
* Subject to your compliance with the applicable Embedded Wizard license terms
* and/or any separate written agreement with TARA Systems, you are granted a
* non-exclusive, worldwide, royalty-free license to use, copy, modify and
* integrate this example code into your own software products and projects.
* You may redistribute this code only as part of your products and not as a
* standalone library, framework or development tool.
*
* THE SOFTWARE IS PROVIDED "AS IS" AND "AS AVAILABLE", WITHOUT WARRANTY OF ANY
* KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT.
* TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, IN NO EVENT SHALL TARA
* SYSTEMS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
* ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
* WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
********************************************************************************
*
* DESCRIPTION:
*   This file implements the API to integrate ExternVideo within Embedded Wizard.
*
*******************************************************************************/

#include "ewconfig.h"
#include "EwExternVideo.h"
#include "EwJpegDec.h"
#include "string.h"
#include "stdarg.h"


#include "ewrte.h"
#include "ewgfx.h"

#include "EwJpegDec.h"
#include "EwInputStream.h"
#include "EwAviParser.h"

#include "ew_bsp_os.h"


/* defines */
#ifndef EW_JPEG_DEC_MULTI_THREADING
  #define EW_JPEG_DEC_MULTI_THREADING 0
#endif

#ifndef EW_EXTERN_VIDEO_DROP_FRAMES_TO_KEEP_FPS
  #define EW_EXTERN_VIDEO_DROP_FRAMES_TO_KEEP_FPS 1
#endif

#ifndef EW_JPEG_IMAGE_PIXEL_FORMAT
  #define EW_JPEG_IMAGE_PIXEL_FORMAT EW_PIXEL_FORMAT_NATIVE
#endif


#if EW_JPEG_DEC_MULTI_THREADING == 1
  #define EW_EXTERN_VIDEO_NUM_BUFFERS 2
#else
  #define EW_EXTERN_VIDEO_NUM_BUFFERS 1
#endif

#define EW_EXTERN_VIDEO_DECODING_THREAD_STACK_SIZE 4096


#define MJPEG_VID_BUFFER_SIZE ((uint32_t)(1024 * 128))
#define MJPEG_AUD_BUFFER_SIZE ((uint32_t)(1024 * 16))


#define EW_EXTERN_VIDEO_LOG_LEVEL_OFF     0
#define EW_EXTERN_VIDEO_LOG_LEVEL_ERROR   1
#define EW_EXTERN_VIDEO_LOG_LEVEL_WARNING 2
#define EW_EXTERN_VIDEO_LOG_LEVEL_INFO    3
#define EW_EXTERN_VIDEO_LOG_LEVEL_DEBUG   4


#ifndef EW_EXTERN_VIDEO_LOG_LEVEL
#define EW_EXTERN_VIDEO_LOG_LEVEL EW_EXTERN_VIDEO_LOG_LEVEL_ERROR
#endif

#define LogMessage EwPrint

#define VA_ARGS(...) , ##__VA_ARGS__
#if EW_EXTERN_VIDEO_LOG_LEVEL >= EW_EXTERN_VIDEO_LOG_LEVEL_DEBUG
  #define LogDebug( aFormat, ... )  LogMessage( "[D] EwExtVid: " aFormat VA_ARGS(__VA_ARGS__))
#else
  #define LogDebug( aFormat, ... )
#endif

#define VA_ARGS(...) , ##__VA_ARGS__
#if EW_EXTERN_VIDEO_LOG_LEVEL >= EW_EXTERN_VIDEO_LOG_LEVEL_INFO
  #define LogInfo( aFormat, ... )  LogMessage( "[I] EwExtVid: " aFormat VA_ARGS(__VA_ARGS__))
#else
  #define LogInfo( aFormat, ... )
#endif

#if EW_EXTERN_VIDEO_LOG_LEVEL >= EW_EXTERN_VIDEO_LOG_LEVEL_WARNING
  #define LogWarning( aFormat, ... )  LogMessage( "[W] EwExtVid: " aFormat VA_ARGS(__VA_ARGS__))
#else
  #define LogWarning( aFormat, ... )
#endif

#if EW_EXTERN_VIDEO_LOG_LEVEL >= EW_EXTERN_VIDEO_LOG_LEVEL_ERROR
  #define LogError( aFormat, ... )  LogMessage( "[E] EwExtVid: " aFormat VA_ARGS(__VA_ARGS__))
#else
  #define LogError( aFormat, ... )
#endif


/* Following structure stores the ExternVideo state information.
   It represents the This of the video or image decoder and
   serves a glue-layer between Embedded Wizard and the ExternVideo. */
typedef struct
{
  /* String containing the source uri. */
  unsigned char*    SourceUri;

  XBitmap*          Bitmap[ EW_EXTERN_VIDEO_NUM_BUFFERS];
  XBitmapLock*      BitmapLock[ EW_EXTERN_VIDEO_NUM_BUFFERS];

  XSemaphoreHandle  SemaphoreDecode;
  XSemaphoreHandle  SemaphoreDisplay;

  XThreadHandle     DecodingThread;

  volatile int      DecodingThreadTerminate;

  int               DecodeBufferIndex;
  int               DisplayBufferIndex;

  XRect             Bounds;


  /* The following variables reflect the current state of the ExternVideo
     instance. */
  char              State_Started;
  char              State_Paused;
  char              State_Resuming;
  char              State_Error;
  char              State_EOS;
  char              State_Buffering;

  char              SingeStep;
  char              IsFirstFrame;
  char              DropFramesToKeepFps;

  unsigned int      Error;
  unsigned int      ErrorCode;

  uint32_t          NewFrameNumber;
  uint32_t          CurrentFrameNumber;
  uint32_t          DroppedFrames;
  uint32_t          PlayerStartTicks;
  uint32_t          NbOfFrames;
  uint32_t          FramesSinceResume;
  uint32_t          MsPerFrame;
  uint32_t          TicksAtLastFrame;
  uint32_t          PresentationTime;
  uint32_t          DecodingDuration;
  int32_t           Speed;

  XJpegDec          JpegDec;
  XAviParser        AviParser;
  XInputStream      InputStream;

} XExtVideoInstance;

#if EW_JPEG_DEC_MULTI_THREADING == 1
static void
EwExternVideoDecodingThread( const void* aContext );
#endif

static int
EwExternVideoDecodeNextFrame( XExtVideoInstance* aInstance );


/*******************************************************************************
* FUNCTION:
*   EwExternVideoCreate
*
* DESCRIPTION:
*   The function EwExternVideoCreate() creates a new ExternVideo instance to decode
*   the provided aSource video or image file. The new created instance is per
*   default paused. To start the playback use the function EwExternVideoResume().
*
* ARGUMENTS:
*   aSource - File name or URL identifying the data to decode.
*
* RETURN VALUE:
*   The function returns a new instance of the created ExternVideo glue-layer.
*
*******************************************************************************/
XHandle EwExternVideoCreate( XString aSource )
{
  XExtVideoInstance*   instance;
  int                  sourceUriLength;
  int                  i;
  XAviParserStreamInfo aviParserStreamInfo;

  /* No data to process. */
  if ( !aSource || !*aSource )
    return 0;

  /* Reserve memory for a data structure representing the glue-layer between
     Embedded Wizard and ExternVideo. */
  instance = EwAlloc( sizeof( XExtVideoInstance ));

  /* Failed to reserve memory for the new glue-layer instance. */
  if ( !instance )
    return 0;

  memset( instance, 0, sizeof( * instance ));

  #if EW_JPEG_DEC_MULTI_THREADING == 1
  instance->SemaphoreDecode  = EwBspOsSemaphoreCreate( EW_EXTERN_VIDEO_NUM_BUFFERS, EW_EXTERN_VIDEO_NUM_BUFFERS );
  instance->SemaphoreDisplay = EwBspOsSemaphoreCreate( EW_EXTERN_VIDEO_NUM_BUFFERS, 0 );
  #endif

  instance->DisplayBufferIndex = -1;

  /* Initialize JPEG decoder */
  instance->JpegDec = EwJpegDecCreate();
  if ( ! instance->JpegDec )
    goto onFatalError;

  sourceUriLength = EwGetUtf8StringLength( aSource );
  instance->SourceUri = EwAlloc( sourceUriLength + 1 );
  if ( ! instance->SourceUri )
  {
    instance->Error = EW_EXTERN_VIDEO_ERROR_NAME_NOT_FOUND;
    instance->State_Error = 1;
    goto onError;
  }

  EwStringToUtf8( aSource, instance->SourceUri, sourceUriLength + 1 );

  LogDebug( "instance->SourceUri: %s\n", instance->SourceUri );

  instance->InputStream = EwInputStreamCreate( (char*)instance->SourceUri );
  if ( ! instance->InputStream )
  {
    LogError( "EwInputStreamCreate failed\n" );
    instance->Error = EW_EXTERN_VIDEO_ERROR_NAME_NOT_FOUND;
    instance->State_Error = 1;
    goto onError;
  }

  instance->AviParser = EwAviParserCreate( instance->InputStream, MJPEG_VID_BUFFER_SIZE, MJPEG_AUD_BUFFER_SIZE );
  if ( ! instance->AviParser )
  {
    LogError( "EwAviParserCreate failed\n" );
    instance->Error = EW_EXTERN_VIDEO_ERROR_CONTENT_ERROR;
    instance->State_Error = 1;
    goto onError;
  }

  instance->CurrentFrameNumber  =  0;
  instance->NewFrameNumber      = -1;
  instance->IsFirstFrame        =  1;
  instance->State_Paused        =  1;
  instance->SingeStep           =  1;
  instance->DropFramesToKeepFps =  EW_EXTERN_VIDEO_DROP_FRAMES_TO_KEEP_FPS;
  instance->Speed               =  100;

  EwAviParserGetStreamInfo(  instance->AviParser, &aviParserStreamInfo );

  instance->NbOfFrames  = aviParserStreamInfo.TotalFrames;
  instance->MsPerFrame  = aviParserStreamInfo.SecPerFrame / 1000;

  if ( instance->MsPerFrame == 0 )
  {
    LogInfo( "Got invalid frame rate - setting 25fps per default\n" );
    instance->MsPerFrame = 40;
  }

  LogInfo( "Streaminfo: Format: %u x %u,  NbOfFrames: %u, Fps: %u\n",
    aviParserStreamInfo.Width, aviParserStreamInfo.Height, instance->NbOfFrames, 1000 / instance->MsPerFrame );


  /* set bounds depending on EW_SURFACE_ROTATION, since JPEG frame is always decoded
     without rotation, while EmWi bitmaps are rotated according to EW_SURFACE_ROTATION */
  #if ( EW_SURFACE_ROTATION == 0 ) || ( EW_SURFACE_ROTATION == 180 )
  instance->Bounds = EwNewRect( 0, 0, aviParserStreamInfo.Width, aviParserStreamInfo.Height );
  #else
  instance->Bounds = EwNewRect( 0, 0, aviParserStreamInfo.Height, aviParserStreamInfo.Width );
  #endif

  for ( i = 0; i < EW_EXTERN_VIDEO_NUM_BUFFERS; i++ )
  {
    instance->Bitmap[ i ] = EwCreateBitmap( EW_JPEG_IMAGE_PIXEL_FORMAT, instance->Bounds.Point2, 0, 1 );
    if ( ! instance->Bitmap[ i ] )
    {
      LogError( "Creating video buffer failed\n" );
      goto onFatalError;
    }

    /* preset the bitmaps, also to ensure alpha channel = 0xFF */
    instance->BitmapLock[ i ] = EwLockBitmap( instance->Bitmap[ i ], 0, instance->Bounds, 0, 1 );
    if ( ! instance->BitmapLock[ i ] )
    {
      LogError( "Locking video buffer failed\n" );
      goto onFatalError;
    }

    /* aviParserStreamInfo.Height has to be used here to be independend from EW_SURFACE_ROTATION */
    memset( instance->BitmapLock[ i ]->Pixel1, 0xFF,
      aviParserStreamInfo.Height * instance->BitmapLock[ i ]->Pitch1Y );

    EwUnlockBitmap( instance->BitmapLock[ i ]);
    instance->BitmapLock[ i ] = 0;

    #if EW_JPEG_DEC_MULTI_THREADING == 1

    instance->BitmapLock[ i ] = EwLockBitmap( instance->Bitmap[ i ], 0, instance->Bounds, 0, 1 );
    if ( ! instance->BitmapLock[ i ] )
    {
      LogError( "Locking video buffer failed\n" );
      goto onFatalError;
    }

    #endif
  }

  instance->FramesSinceResume = 0;
  instance->PlayerStartTicks = EwGetTicks();

  #if EW_JPEG_DEC_MULTI_THREADING == 1
  /* start decoding thread */
  instance->DecodingThread = EwBspOsThreadCreate( EwExternVideoDecodingThread,
    EW_BSP_OS_THREAD_PRIORITY_LOW, EW_EXTERN_VIDEO_DECODING_THREAD_STACK_SIZE, instance );
  #endif

  instance->State_Started = 1;

onError:

  return (XHandle)instance;

onFatalError:
  EwExternVideoDestroy(( XHandle ) instance );
  return 0;
}


/*******************************************************************************
* FUNCTION:
*   EwExternVideoDestroy
*
* DESCRIPTION:
*   The function EwExternVideoDestroy() stops the ExternVideo and waits for its
*   finalization. Then all still existing GStremer resources are released.
*
* ARGUMENTS:
*   instance - The ExternVideo instance.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwExternVideoDestroy( XHandle aInstance )
{
  XExtVideoInstance* instance = (XExtVideoInstance*)aInstance;
  int i;

  /* No glue-layer instance passed */
  if ( !instance )
    return;

  #if EW_JPEG_DEC_MULTI_THREADING == 1
  /* exit decoding thread */
  if ( instance->DecodingThread )
  {
    instance->DecodingThreadTerminate = 1;
    EwBspOsSemaphoreRelease( instance->SemaphoreDecode );

    while( instance->DecodingThread )
      EwBspOsDelay(1);
  }
  #endif

  if ( instance->AviParser )
    EwAviParserDestroy( instance->AviParser );

  if ( instance->JpegDec )
    EwJpegDecDestroy( instance->JpegDec );

  if ( instance->InputStream )
    EwInputStreamRelease( instance->InputStream );

  if ( instance->SourceUri )
  {
    EwFree( instance->SourceUri );
    instance->SourceUri = 0;
  }

  for ( i = 0; i < EW_EXTERN_VIDEO_NUM_BUFFERS; i++ )
  {
    if ( instance->BitmapLock[ i ] )
    {
      EwUnlockBitmap( instance->BitmapLock[ i ]);
      instance->BitmapLock[ i ] = 0;
    }

    if ( instance->Bitmap[ i ] )
    {
      EwFreeBitmap( instance->Bitmap[ i ] );
      instance->Bitmap[ i ]  = 0;
    }
  }

  #if EW_JPEG_DEC_MULTI_THREADING == 1
  if ( instance->SemaphoreDisplay )
  {
    EwBspOsSemaphoreDestroy( instance->SemaphoreDisplay );
    instance->SemaphoreDisplay = 0;
  }

  if ( instance->SemaphoreDecode )
  {
    EwBspOsSemaphoreDestroy( instance->SemaphoreDecode );
    instance->SemaphoreDecode = 0;
  }
  #endif

  /* Finally free the glue-layer instance. */
  EwFree( instance );
}


/*******************************************************************************
* FUNCTION:
*   EwExternVideoGetNewBitmap
*
* DESCRIPTION:
*   The function EwExternVideoGetNewBitmap() verifies whether there is a new
*   buffer provided by ExternVideo. If this is the case the function creates a
*   new Embedded Wizard bitmap envolving the content of this buffer. If there
*   is no new ExternVideo buffer available, the function returns NULL.
*
*   The caller of the function becomes the owner of the new created bitmap. It
*   is responsable for freeing the bitmap if it is not in use anymore.
*
* ARGUMENTS:
*   instance - The ExternVideo instance.
*
* RETURN VALUE:
*   The function returns a new created Embedded Wizard bitmap or NULL if there
*   is no new ExternVideo buffer to process.
*
*******************************************************************************/
XBitmap* EwExternVideoGetNewBitmap( XHandle aInstance )
{
  XExtVideoInstance* instance = (XExtVideoInstance*)aInstance;

  /* No glue-layer instance passed */
  if ( !instance || ! instance->State_Started )
    return 0;

  #if EW_JPEG_DEC_MULTI_THREADING == 1
  if ( EwBspOsSemaphoreWait( instance->SemaphoreDisplay, 1 ) < 1 )
    return 0;

  if ( instance->DisplayBufferIndex >= 0 )
  {
    /* lock current display buffer */
    int i = instance->DisplayBufferIndex;
    instance->BitmapLock[ i ] = EwLockBitmap( instance->Bitmap[ i ], 0, instance->Bounds, 0, 1 );

    /* ... and hand it over to the decoder */
    EwBspOsSemaphoreRelease( instance->SemaphoreDecode );
  }

  /* Take next buffer for displaying */
  instance->DisplayBufferIndex++;
  if ( instance->DisplayBufferIndex >= EW_EXTERN_VIDEO_NUM_BUFFERS )
    instance->DisplayBufferIndex = 0;

  EwUnlockBitmap( instance->BitmapLock[ instance->DisplayBufferIndex ] );
  instance->BitmapLock[ instance->DisplayBufferIndex ] = 0;

  return instance->Bitmap[ instance->DisplayBufferIndex ];

  #else

  if ( instance->State_Paused && ! instance->SingeStep )
    return 0;

  instance->SingeStep = 0;
  instance->BitmapLock[ 0 ] = EwLockBitmap( instance->Bitmap[ 0 ], 0, instance->Bounds, 0, 1 );
  int isValidFrame = EwExternVideoDecodeNextFrame( instance );
  EwUnlockBitmap( instance->BitmapLock[ 0 ] );
  instance->BitmapLock[ 0 ] = 0;
  if ( isValidFrame )
    return instance->Bitmap[ 0 ];
  else
    return 0;

  #endif

}


/*******************************************************************************
* FUNCTION:
*   EwExternVideoPause
*
* DESCRIPTION:
*   The function EwExternVideoPause() pauses the ExternVideo.
*
* ARGUMENTS:
*   instance - The ExternVideo instance.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwExternVideoPause( XHandle aInstance )
{
  XExtVideoInstance* instance = (XExtVideoInstance*)aInstance;

  if ( !instance )
    return;

  instance->State_Paused = 1;

}


/*******************************************************************************
* FUNCTION:
*   EwExternVideoResume
*
* DESCRIPTION:
*   The function EwExternVideoResume() reactivates the ExternVideo.
*
* ARGUMENTS:
*   instance - The ExternVideo instance.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwExternVideoResume( XHandle aInstance )
{
  XExtVideoInstance* instance = (XExtVideoInstance*)aInstance;

  /* No glue-layer instance passed */
  if ( !instance )
    return;

  instance->IsFirstFrame = 1;
  instance->State_Paused = 0;
}


/*******************************************************************************
* FUNCTION:
*   EwExternVideoGetState
*
* DESCRIPTION:
*   The function EwExternVideoGetState() returns the latest known state of the
*   ExternVideo processing.
*
* ARGUMENTS:
*   instance - The ExternVideo instance.
*
* RETURN VALUE:
*   The latest known state. See the defines EW_EXTERN_VIDEO_STATE_XXX.
*
*******************************************************************************/
int EwExternVideoGetState( XHandle aInstance )
{
  XExtVideoInstance* instance = (XExtVideoInstance*)aInstance;

  if ( !instance )
    return EW_EXTERN_VIDEO_STATE_ERROR;

  /* print pending log messages */
//  PrintLogMessages();

  if ( instance->State_Error )
    return EW_EXTERN_VIDEO_STATE_ERROR;

  if ( instance->State_EOS )
    return EW_EXTERN_VIDEO_STATE_END_OF_STREAM;

  if ( instance->State_Started && !instance->State_Paused )
    return EW_EXTERN_VIDEO_STATE_PLAYING;

  if ( instance->State_Started && instance->State_Paused )
    return EW_EXTERN_VIDEO_STATE_PAUSED;

  if ( instance->State_Resuming )
    return EW_EXTERN_VIDEO_STATE_RESUMING;

  return EW_EXTERN_VIDEO_STATE_READY;
}


/*******************************************************************************
* FUNCTION:
*   EwExternVideoGetNoOfFrames
*
* DESCRIPTION:
*   The function EwExternVideoGetNoOfVideoFrames() returns the number of video
*   frames of the currently selected video stream.
*
* ARGUMENTS:
*   instance - The ExternVideo instance.
*
* RETURN VALUE:
*   The umber of video frames.
*
*******************************************************************************/
int EwExternVideoGetNoOfFrames( XHandle aInstance )
{
  XExtVideoInstance* instance = (XExtVideoInstance*)aInstance;
  if ( instance->State_Error || ! instance->State_Started )
    return 0;

  return  instance->NbOfFrames;
}


/*******************************************************************************
* FUNCTION:
*   EwExternVideoGetFrameRate
*
* DESCRIPTION:
*   The function EwExternVideoGetFrameRate() returns the framerate (frames per
*   second) of the selected video stream.
*
* ARGUMENTS:
*   instance - The ExternVideo instance.
*
* RETURN VALUE:
*   The framerate in frames per second.
*
*******************************************************************************/
float EwExternVideoGetFrameRate( XHandle aInstance )
{
  XExtVideoInstance* instance = ( XExtVideoInstance* ) aInstance;
  return  (float)1000 / instance->MsPerFrame;
}


/*******************************************************************************
* FUNCTION:
*   EwExternVideoGetCurrentFrame
*
* DESCRIPTION:
*   The function EwExternVideoGetCurrentFrame() returns frame number of the
*   currently displayed video frame.
*
* ARGUMENTS:
*   instance - The ExternVideo instance.
*
* RETURN VALUE:
*   The frame number of the currently displayed video frame.
*
*******************************************************************************/
int EwExternVideoGetCurrentFrame( XHandle aInstance )
{
  XExtVideoInstance* instance = (XExtVideoInstance*)aInstance;
  int                position;

  if ( instance->State_Error || ! instance->State_Started )
    return 0;

  if ( instance->NewFrameNumber != -1 )
    position = instance->NewFrameNumber;
  else
    position = instance->CurrentFrameNumber;

  return  position;
}


/*******************************************************************************
* FUNCTION:
*   EwExternVideoSetCurrentFrame
*
* DESCRIPTION:
*   The function EwExternVideoSetCurrentFrame() sets the currently selected
*   video stram to the given frame number.
*
* ARGUMENTS:
*   instance     - The ExternVideo instance.
*   aFrameNumber - The new frame number.
*
* RETURN VALUE:
*   A non zero value, if successfull.
*
*******************************************************************************/
int EwExternVideoSetCurrentFrame( XHandle aInstance, int aFrameNumber )
{
  XExtVideoInstance* instance = (XExtVideoInstance*)aInstance;

  if ( instance->State_Error || ! instance->State_Started )
    return 0;

  /* set new position */
  LogInfo( "EwExternVideoSetCurrentFrame: %u\n", aFrameNumber );

  instance->NewFrameNumber = aFrameNumber;
  instance->IsFirstFrame =  1;
  instance->SingeStep    = 1;
  instance->State_EOS    = 0;

  return  0;
}


/*******************************************************************************
* FUNCTION:
*   EwExternVideoRewind
*
* DESCRIPTION:
*   The function EwExternVideoRewind() seeks back to the given frame and
*   continues playback without entering single-step mode. Unlike
*   SetCurrentFrame, this is designed for seamless looping: it clears the
*   end-of-stream flag and resets timing without pausing.
*
* ARGUMENTS:
*   aInstance    - The ExternVideo instance.
*   aFrameNumber - The frame to seek to (typically 0 for loop restart).
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwExternVideoRewind( XHandle aInstance, int aFrameNumber )
{
  XExtVideoInstance* instance = (XExtVideoInstance*)aInstance;

  if ( !instance || instance->State_Error || !instance->State_Started )
    return;

  LogInfo( "EwExternVideoRewind: %u\n", aFrameNumber );

  instance->NewFrameNumber = aFrameNumber;
  instance->IsFirstFrame   = 1;
  instance->State_EOS      = 0;
}


/*******************************************************************************
* FUNCTION:
*   EwExternVideoGetSpeed
*
* DESCRIPTION:
*   The function EwExternVideoGetSpeed() returns the currently set play speed.
*   The given speed value is interpreted as a procentual value,
*   e. g. 100 means normal play speed, -400 means 4x rewind.
*
* ARGUMENTS:
*   instance - The ExternVideo instance.
*
* RETURN VALUE:
*   The currently set play speed.
*
*******************************************************************************/
int EwExternVideoGetSpeed( XHandle aInstance )
{
  XExtVideoInstance* instance = (XExtVideoInstance*)aInstance;

  if ( instance->State_Error || ! instance->State_Started )
    return 0;

  /* return the currently set play speed */

  return  instance->Speed;
}


/*******************************************************************************
* FUNCTION:
*   EwExternVideoSetSpeed
*
* DESCRIPTION:
*   The function EwExternVideoSetSpeed() sets a play speed for the currently
*   selected media. The given speed value is interpreted as a procentual value,
*   e. g. 100 means normal play speed, -400 means 4x rewind.
*
* ARGUMENTS:
*   instance     - The ExternVideo object.
*   aSpeed   - The new play speed.
*
* RETURN VALUE:
*   A non zero value, if successfull.
*
*******************************************************************************/
int EwExternVideoSetSpeed( XHandle aInstance, int aSpeed )
{
  XExtVideoInstance* instance = (XExtVideoInstance*)aInstance;

  if ( instance->State_Error || ! instance->State_Started )
    return 0;

  if ( aSpeed <= 0 )
    return 0;

  /* set new play speed */
  instance->Speed = aSpeed;

  return  1;
}


/*******************************************************************************
* FUNCTION:
*   EwExternVideoGetError
*
* DESCRIPTION:
*   The function EwExternVideoGetError() returns the latest error number, if
*   any. The concrete interpretation of the error numbers depends on the used
*   decoder functionality. If there is no error, the function should return
*   0 (zero).
*
* ARGUMENTS:
*   aInstance - The ExternVideo instance.
*
* RETURN VALUE:
*   The latest error number.
*
*******************************************************************************/
int EwExternVideoGetError( XHandle aInstance )
{
  XExtVideoInstance* instance = (XExtVideoInstance*)aInstance;

  if ( ! instance )
    return EW_EXTERN_VIDEO_ERROR_OTHER_ERROR;

  return instance->Error;
}


/*******************************************************************************
* FUNCTION:
*   EwExternVideoGetErrorCode
*
* DESCRIPTION:
*   The function EwExternVideoGetErrorCode() returns the latest error number, if
*   any. The concrete interpretation of the error numbers depends on the used
*   decoder functionality. If there is no error, the function should return 0
*   (zero).
*
* ARGUMENTS:
*   aInstance - The ExternVideo instance.
*
* RETURN VALUE:
*   The latest error number.
*
*******************************************************************************/
unsigned int EwExternVideoGetErrorCode( XHandle aInstance )
{
  XExtVideoInstance* instance = (XExtVideoInstance*)aInstance;

  if ( ! instance )
    return 0;

  return instance->ErrorCode;
}


#if EW_JPEG_DEC_MULTI_THREADING == 1
/*******************************************************************************
* FUNCTION:
*   EwExternVideoDecodingThread
*
* DESCRIPTION:
*   instance thread decodes the video stream.
*
* ARGUMENTS:
*   instance - The ExternVideo object.
*
* RETURN VALUE:
*   The function returns a new instance of the created ExternVideo glue-layer.
*
*******************************************************************************/
static void
EwExternVideoDecodingThread( const void* aContext )
{
  XExtVideoInstance *  instance = ( XExtVideoInstance * ) aContext;
  char                 frameWasDropped = 0;
  XThreadHandle        threadId;

  while ( ! instance->DecodingThreadTerminate )
  {
    if ( instance->State_EOS || ( instance->State_Paused && ! instance->SingeStep ))
    {
      /* if paused and no single step processing, just pause */
      EwBspOsDelay( 20 );
      continue;
    }

    instance->SingeStep = 0;

    if ( ! frameWasDropped )
    {
      /* check for a available decoding buffer */
      if ( EwBspOsSemaphoreWait( instance->SemaphoreDecode, 20 ) < 1 )
        continue;
    }

    /* terminate thread, if termination is requested */
    if ( instance->DecodingThreadTerminate )
      break;

    frameWasDropped = 0;

    if ( EwExternVideoDecodeNextFrame( instance ))
    {
      EwBspOsSemaphoreRelease( instance->SemaphoreDisplay );
    }
    else
      frameWasDropped = 1;
  }

  threadId = instance->DecodingThread;
  instance->DecodingThread = 0;
  EwBspOsThreadDestroy( threadId );
}
#endif


/*******************************************************************************
* FUNCTION:
*   EwExternVideoDecodeNextFrame
*
* DESCRIPTION:
*   decodes the next video frame.
*
* ARGUMENTS:
*   instance - The ExternVideo object.
*
* RETURN VALUE:
*   The function returns 1, if a new frame is decoded.
*
*******************************************************************************/
static int
EwExternVideoDecodeNextFrame( XExtVideoInstance* instance )
{
  uint32_t             frameType = 0;
  XAviParserFrameInfo  frameInfo;
  unsigned long        ticks;
  long                 timeUntilPresentation;
  int                  timePerFrame;

  if ( instance->NewFrameNumber != -1 )
  {
    EwAviParserSetFrameNumber( instance->AviParser, instance->NewFrameNumber );
    instance->CurrentFrameNumber = instance->NewFrameNumber;
    instance->NewFrameNumber = -1;
  }

  timePerFrame = instance->MsPerFrame * 100 / instance->Speed;

  /* Check if we need to skip frames BEFORE the expensive I/O read.
     On systems with slow flash I/O (e.g. SPIFFS), reading frames just to drop
     them wastes time and causes cascading frame drops. Instead, calculate how
     many frames to skip and seek ahead in one step. */
  if ( ! instance->IsFirstFrame && instance->DropFramesToKeepFps )
  {
    ticks = EwGetTicks();
    if ((long)(( instance->PresentationTime + 2 * timePerFrame ) - ( ticks + instance->DecodingDuration )) < 0 )
    {
      int framesToSkip = (int)(( ticks + instance->DecodingDuration - instance->PresentationTime ) / timePerFrame );
      if ( framesToSkip < 1 )
        framesToSkip = 1;

      instance->DroppedFrames      += framesToSkip;
      instance->CurrentFrameNumber += framesToSkip * (( instance->Speed > 0 ) ? 1 : -1);
      instance->PresentationTime   += framesToSkip * timePerFrame;

      /* Seek to new position and reset timing for next decode */
      instance->NewFrameNumber = instance->CurrentFrameNumber;
      instance->IsFirstFrame   = 1;

      return 0;
    }
  }

  frameType = EwAviParserGetNextFrame( instance->AviParser, &frameInfo );

  if ( frameType == EW_AVI_PARSER_VIDEO_FRAME )
  {
    if ( frameInfo.Size > 0 )
    {
      int i = instance->DecodeBufferIndex;

      instance->DecodeBufferIndex++;
      if ( instance->DecodeBufferIndex >= EW_EXTERN_VIDEO_NUM_BUFFERS )
        instance->DecodeBufferIndex = 0;

      ticks = EwGetTicks();
      EwJpegDecDecode( instance->JpegDec, frameInfo.Buffer, frameInfo.Size,
        instance->BitmapLock[ i ]->Pixel1, instance->BitmapLock[ i ]->Pitch1Y );
      instance->DecodingDuration = EwGetTicks() - ticks;

      if ( instance->IsFirstFrame )
      {
        instance->PresentationTime = EwGetTicks();
        instance->IsFirstFrame = 0;
      }
      else
      {
        /* calculate presentation time of this frame */
        instance->PresentationTime += timePerFrame;
        timeUntilPresentation = instance->PresentationTime - EwGetTicks();
        if ( timeUntilPresentation > 0 )
        {
          /* wait until presentation time */
          EwBspOsDelay( timeUntilPresentation );
        }
      }

      instance->CurrentFrameNumber+= ( instance->Speed > 0 ) ? 1 : -1;
      return 1;
    }
  }

  if ( frameType == EW_AVI_PARSER_END_FILE )
  {
    instance->State_EOS = 1;
    return 0;
  }

  if ( frameType == EW_AVI_PARSER_ERROR )
  {
    instance->State_Error = 1;
    instance->Error = EW_EXTERN_VIDEO_ERROR_CONTENT_ERROR;
    return 0;
  }

  return 1;
}
