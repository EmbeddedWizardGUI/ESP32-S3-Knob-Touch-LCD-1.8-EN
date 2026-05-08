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
*   This file implements a basic AVI file parser to get grab JPEG images of a
*   MJPEG video file.
*
*******************************************************************************/

#include "ewrte.h"
#include "EwInputStream.h"
#include "EwAviParser.h"

/* AVI stream constants */
#define AVI_RIFF_ID      0x46464952     /* "RIFF" */
#define AVI_AVI_ID       0x20495641     /* "AVI " */
#define AVI_LIST_ID      0x5453494C     /* "LIST" */
#define AVI_HDRL_ID      0x6C726468     /* "hdrl" */
#define AVI_MOVI_ID      0x69766F6D     /* "movi" */
#define AVI_STRL_ID      0x6C727473     /* "strl" */

#define AVI_AVIH_ID      0x68697661      /* "avih" */
#define AVI_STRH_ID      0x68727473      /* "strh" */
#define AVI_STRF_ID      0x66727473      /* "strf" */
#define AVI_STRD_ID      0x64727473      /* "strd" */

#define AVI_VIDS_STREAM  0x73646976     /* "vids" */
#define AVI_AUDS_STREAM  0x73647561     /* "auds" */


#define AVI_VIDS_FLAG    0x6463         /* "dc" */
#define AVI_AUDS_FLAG    0x7762         /* "bw" */


#define AVI_FORMAT_MJPG  0x47504A4D     /* "MJPG" */



typedef struct
{
  uint32_t RiffID;
  uint32_t FileSize;
  uint32_t AviID;
} AVI_HEADER;

typedef struct
{
  uint32_t FrameID;
  uint32_t FrameSize;
} FRAME_HEADER;

typedef struct
{
  uint32_t ListID;
  uint32_t BlockSize;
  uint32_t ListType;
} LIST_HEADER;

typedef struct
{
  uint32_t BlockID;
  uint32_t BlockSize;
  uint32_t SecPerFrame;
  uint32_t MaxByteSec;
  uint32_t PaddingGranularity;
  uint32_t Flags;
  uint32_t TotalFrame;
  uint32_t InitFrames;
  uint32_t Streams;
  uint32_t RefBufSize;
  uint32_t Width;
  uint32_t Height;
  uint32_t Reserved[4];
} AVIH_HEADER;


typedef struct
{
  uint32_t BlockID;
  uint32_t BlockSize;
  uint32_t StreamType;
  uint32_t Handler;
  uint32_t Flags;
  uint16_t Priority;
  uint16_t Language;
  uint32_t InitFrames;
  uint32_t Scale;
  uint32_t Rate;
  uint32_t Start;
  uint32_t Length;
  uint32_t RefBufSize;
  uint32_t Quality;
  uint32_t SampleSize;
  struct
  {
    uint16_t  Left;
    uint16_t  Top;
    uint16_t  Right;
    uint16_t  Bottom;
  }Frame;
} STRH_HEADER;


typedef struct
{
  uint32_t     BmpSize;
  uint32_t     Width;
  uint32_t     Height;
  uint16_t     Planes;
  uint16_t     BitCount;
  uint32_t     Compression;
  uint32_t     SizeImage;
  uint32_t     XpixPerMeter;
  uint32_t     YpixPerMeter;
  uint32_t     ClrUsed;
  uint32_t     ClrImportant;
} BMP_HEADER;


typedef struct
{
  uint8_t  rgbBlue;
  uint8_t  rgbGreen;
  uint8_t  rgbRed;
  uint8_t  rgbReserved;
} AVIRGBQUAD;

typedef struct
{
  uint32_t BlockID;
  uint32_t BlockSize;
  BMP_HEADER bmiHeader;
  AVIRGBQUAD bmColors[1];
} STRF_BMPHEADER;


typedef struct
{
  uint32_t BlockID;
  uint32_t BlockSize;
  uint16_t FormatTag;
  uint16_t Channels;
  uint32_t SampleRate;
  uint32_t BaudRate;
  uint16_t BlockAlign;
  uint16_t Size;
} STRF_WAVHEADER;



#define  AVI_MAKEWORD(ptr)   (uint16_t)(((uint16_t)*((uint8_t*)(ptr))<<8)|(uint16_t)*(uint8_t*)((ptr)+1))
#define  AVI_MAKEDWORD(ptr)  (uint32_t)(((uint16_t)*(uint8_t*)(ptr)|(((uint16_t)*(uint8_t*)(ptr+1))<<8)|\
            (((uint16_t)*(uint8_t*)(ptr+2))<<16)|(((uint16_t)*(uint8_t*)(ptr+3))<<24)))


static const char*  FlagTableVid[ 2 ] = { "00dc", "01dc" };
static const char*  FlagTableAud[ 2 ] = { "00wb", "01wb" };

/* privat functions */
static int
EwAviParserInitialize( XAviParser This );
static uint32_t
EwAviParserSearchId( unsigned char* aBuffer, unsigned long aSize, const char* aId );
static int
EwAviParserGetFrameInfo( XAviParser This, uint8_t* aBuffer );


typedef struct XAviParserStruct
{
  XInputStream  InputStream;
  unsigned long   VideoBufferSize;
  unsigned long   AudioBufferSize;
  unsigned char*  VideoBuffer;
  unsigned char*  AudioBuffer;
  long            CurrentImage;
  uint16_t        StreamID;
  uint32_t        FrameSize;

  XAviParserStreamInfo StreamInfo;

  uint8_t*  VideoFLAG;
  uint8_t*  AudioFLAG;

} XAviParserStruct;



/*******************************************************************************
* FUNCTION:
*   EwAviParserCreate
*
* DESCRIPTION:
*   Creates a EW AVI parser and parses the stream header.
*
* ARGUMENTS:
*   aInputStream     - The inputstream video data come from.
*   aVideoBufferSize - This size of the video frame input buffer.
*   aAudioBufferSize - This size of the audio frame input buffer.
*
* RETURN VALUE:
*   The new XAviParser, if successsfull, NULL otherwise.
*
*******************************************************************************/
XAviParser
EwAviParserCreate( XInputStream aInputStream, unsigned long aVideoBufferSize, unsigned long aAudioBufferSize )
{
  XAviParser This;

  if ( ! aInputStream )
    return 0;

  This = EwAlloc( sizeof( XAviParserStruct ));
  if ( ! This )
    return 0;

  This->InputStream = aInputStream;
  This->VideoBuffer = EwAlloc( aVideoBufferSize );
  This->AudioBuffer = EwAlloc( aAudioBufferSize );
  This->AudioBufferSize = aAudioBufferSize;
  This->VideoBufferSize = aVideoBufferSize;

  if ( ! This->VideoBuffer || ! This->AudioBuffer )
  {
    EwAviParserDestroy( This );
    return 0;
  }

  if ( ! EwAviParserInitialize( This ))
  {
    EwAviParserDestroy( This );
    return 0;
  }

  This->CurrentImage = -1;

  return This;
}


/*******************************************************************************
* FUNCTION:
*   EwAviParserGetStreamInfo
*
* DESCRIPTION:
*   Returns the stream info.
*
* ARGUMENTS:
*   This        - This AviParser instance.
*   aStreamInfo - The AviParserStreamInfo buffer, the stream info should be 
*                 stored.
*
* RETURN VALUE:
*   The stream info.
*
*******************************************************************************/
int
EwAviParserGetStreamInfo(  XAviParser This, XAviParserStreamInfo* aStreamInfo )
{
  if ( ! This )
    return 0;

  * aStreamInfo = This->StreamInfo;
  return 1;
}


/*******************************************************************************
* FUNCTION:
*   EwAviParserDestroy
*
* DESCRIPTION:
*   Destroys the given EW AVI parser.
*
* ARGUMENTS:
*   This - This AviParser instance.
*
*******************************************************************************/
void
EwAviParserDestroy( XAviParser This )
{
  if ( ! This )
    return;

  if ( This->VideoBuffer )
    EwFree( This->VideoBuffer );

  if ( This->AudioBuffer )
    EwFree( This->AudioBuffer );

  EwFree( This );
}


/*******************************************************************************
* FUNCTION:
*   EwAviParserGetFrame
*
* DESCRIPTION:
*   Gets the next audio or video frame beginning from the given video frame 
*   number.
*
* ARGUMENTS:
*   This         - This AviParser instance.
*   aFrameNumber - The frame number.
*   aFrameInfo   - The reqired frame info structure.
*
* RETURN VALUE:
*   EW_AVI_PARSER_AUDIO_FRAME, EW_AVI_PARSER_VIDEO_FRAME, EW_AVI_PARSER_END_FILE 
*   or EW_AVI_PARSER_ERROR.
*
*******************************************************************************/
static uint32_t 
EwAviParserGetFrame( XAviParser This, int aFrameNumber, XAviParserFrameInfo* aFrameInfo )
{
  uint32_t offset ;
  uint32_t readSize = 0;
  uint32_t result = EW_AVI_PARSER_END_FILE;

  if ( aFrameNumber < This->CurrentImage )
    This->CurrentImage = -1;
  
  if( This->CurrentImage == -1 )
  {
    /* rewind the file */
    EwInputStreamSeek( This->InputStream, EW_INPUT_STREAM_SEEK_SET, 0 );

    /* Read data */
    readSize = EwInputStreamRead( This->InputStream, This->VideoBuffer, This->VideoBufferSize );
    if ( readSize == 0 )
      return EW_AVI_PARSER_ERROR;

    /* Check for "movi" tag */
    offset = EwAviParserSearchId( This->VideoBuffer, This->VideoBufferSize, "movi" );
    /* Read first Frame info*/
    EwAviParserGetFrameInfo( This, This->VideoBuffer + offset + 4 );
    /* go to the first frame offset in the avi file*/
    EwInputStreamSeek( This->InputStream, EW_INPUT_STREAM_SEEK_SET, offset + 12 );
  }
  
  while ( aFrameNumber > This->CurrentImage )
  {
    if((This->StreamID  ==  AVI_VIDS_FLAG) && (This->FrameSize <= This->VideoBufferSize))
    {
      /* the Frame is a Video Frame */

      /* Read The current frame + the header of the next frame (8 bytes) */
      readSize = EwInputStreamRead( This->InputStream, This->VideoBuffer, This->FrameSize + 8 );
      if ( readSize == 0 )
        return EW_AVI_PARSER_ERROR;

      aFrameInfo->Buffer = This->VideoBuffer;
      aFrameInfo->Size   = This->FrameSize;

      /* Get the info of the next frame */
      EwAviParserGetFrameInfo( This, This->VideoBuffer + This->FrameSize );
      This->CurrentImage++;
      
      result = EW_AVI_PARSER_VIDEO_FRAME;
    }
    
    else if (( This->StreamID == AVI_AUDS_FLAG ) && ( This->FrameSize <= This->AudioBufferSize ))
    { /* the Frame is an Audio Frame */

      /* Read The current frame + the header of the next frame (8 bytes) */
      readSize = EwInputStreamRead( This->InputStream, This->AudioBuffer, This->FrameSize + 8 );
      if ( readSize == 0 )
        return EW_AVI_PARSER_ERROR;

      aFrameInfo->Buffer = This->AudioBuffer;
      aFrameInfo->Size   = This->FrameSize;

      /* Get the info of the next frame */
      EwAviParserGetFrameInfo( This, This->AudioBuffer + This->FrameSize );
      result = EW_AVI_PARSER_AUDIO_FRAME;
    }
    else
    {
      result = EW_AVI_PARSER_END_FILE;
      break;
    }
  } 
  
  return result;
}


/*******************************************************************************
* FUNCTION:
*   EwAviParserSetFrameNumber
*
* DESCRIPTION:
*   Sets the frame number, that should be displayed next.
*
* ARGUMENTS:
*   This         - This AviParser instance.
*   aFrameNumber - The frame number.
*
* RETURN VALUE:
*   1, if successsfull, 0 otherwise.
*
*******************************************************************************/
void EwAviParserSetFrameNumber( XAviParser This, int aFrameNumber )
{
  XAviParserFrameInfo frameInfo;
  EwAviParserGetFrame( This, aFrameNumber, &frameInfo );
}


/*******************************************************************************
* FUNCTION:
*   EwAviParserGetFrameInfo
*
* DESCRIPTION:
*   Gets the frame info of current frame.
*
* ARGUMENTS:
*   This         - This AviParser instance.
*   aFrameInfo   - The reqired frame info structure.
*
* RETURN VALUE:
*   1, if successsfull, 0 otherwise.
*
*******************************************************************************/
uint32_t EwAviParserGetNextFrame( XAviParser This, XAviParserFrameInfo* aFrameInfo )
{
  return EwAviParserGetFrame( This, This->CurrentImage + 1, aFrameInfo );
}


/*******************************************************************************
* FUNCTION:
*   EwAviParserGetFrameInfo
*
* DESCRIPTION:
*   Gets the frame info of current frame.
*
* ARGUMENTS:
*   This    - This AviParser instance.
*   aBuffer - the input buffer
*
* RETURN VALUE:
*   1, if successsfull, 0 otherwise.
*
*******************************************************************************/
static int
EwAviParserGetFrameInfo( XAviParser This, uint8_t* aBuffer )
{

  This->StreamID   = AVI_MAKEWORD( aBuffer + 2 );
  This->FrameSize = AVI_MAKEDWORD( aBuffer + 4 );

  if( This->FrameSize % 2 )
    This->FrameSize++;

  if(( This->StreamID  ==  AVI_VIDS_FLAG) ||
     ( This->StreamID  ==  AVI_AUDS_FLAG ))
  {
    return 1;
  }

  return 0;
}


/*******************************************************************************
* FUNCTION:
*   EwAviParserSearchId
*
* DESCRIPTION:
*   Helper function to searches for the given AVI ID.
*
* ARGUMENTS:
*   aBuffer    - The stream buffer.
*   aSize      - The stream buffer size.
*   aId        - The requested AVI Id.
*
* RETURN VALUE:
*   The offset in the buffer, the given Id was found or 0, if the requested
*   AVI Id was not found.
*
*******************************************************************************/
static uint32_t
EwAviParserSearchId( unsigned char* aBuffer,  unsigned long aSize, const char* aId )
{
  uint16_t i;

  aSize -= 4;
  for( i = 0; i < aSize; i++ )
  {
    if ( aBuffer[ i ] == aId[ 0 ])
      if ( aBuffer[ i + 1 ] == aId[ 1 ])
        if ( aBuffer[ i + 2 ] == aId[ 2 ])
          if ( aBuffer[ i + 3 ] == aId[ 3 ])
            return i;
  }
  return 0;
}

/*******************************************************************************
* FUNCTION:
*   EwAviParserInitialize
*
* DESCRIPTION:
*   Creates a EW AVI parser and parses the stream header.
*
* ARGUMENTS:
*   This    - This AviParser instance.
*
* RETURN VALUE:
*   1, if successsfull, 0 otherwise.
*
*******************************************************************************/
static int
EwAviParserInitialize( XAviParser This )
{
  uint8_t*        tbuf1;
  uint8_t*        tbuf2;
  uint32_t        readSize;
  AVI_HEADER*     aviHeader;
  LIST_HEADER*    listHeader;
  AVIH_HEADER*    avihHeader;
  STRH_HEADER*    strhHeader;
  STRF_BMPHEADER* bmpHeader;
  STRF_WAVHEADER* wavHeader;

  /* reset AVI file */
  EwInputStreamSeek( This->InputStream, EW_INPUT_STREAM_SEEK_SET, 0 );

  /* fill video buffer with AVI header to  */
  readSize = EwInputStreamRead( This->InputStream, This->VideoBuffer, This->VideoBufferSize );

  if ( readSize == 0)
    return 0;

  tbuf1  = This->VideoBuffer;
  tbuf2 = This->VideoBuffer;
  aviHeader = ( AVI_HEADER* ) tbuf1;

  /* check for AVI RIFF id */
  if ( aviHeader->RiffID != AVI_RIFF_ID )
    return 0;

  /* check for AVI id */
  if ( aviHeader->AviID != AVI_AVI_ID )
    return 0;

  /* skip AVI header */
  tbuf1 += sizeof( AVI_HEADER );
  listHeader = ( LIST_HEADER* ) tbuf1;

  /* check for AVI list id */
  if ( listHeader->ListID != AVI_LIST_ID)
    return 0;

  /* check for list type AVI HDRL id */
  if ( listHeader->ListType != AVI_HDRL_ID )
    return 0;

  /* skip AVI list header */
  tbuf1 += sizeof( LIST_HEADER );
  avihHeader = ( AVIH_HEADER* ) tbuf1;

  /* check for block id avih */
  if ( avihHeader->BlockID != AVI_AVIH_ID )
    return 0;

  This->StreamInfo.SecPerFrame = avihHeader->SecPerFrame;
  This->StreamInfo.TotalFrames = avihHeader->TotalFrame;

  /* skip AVI header */
  tbuf1 += avihHeader->BlockSize + 8;

  listHeader=( LIST_HEADER* ) tbuf1;

  /* check for list id "LIST" */
  if ( listHeader->ListID != AVI_LIST_ID )
    return 0;

  /* check for list type "strl" */
  if ( listHeader->ListType != AVI_STRL_ID )
    return 0;


  strhHeader = ( STRH_HEADER* ) (tbuf1 + 12);

  /* check for block id strh */
  if ( strhHeader->BlockID != AVI_STRH_ID )
    return 0;

  if ( strhHeader->StreamType == AVI_VIDS_STREAM )
  {
    /* check for AVI format MJPG */
    if ( strhHeader->Handler != AVI_FORMAT_MJPG )
      return 0;

    This->VideoFLAG = (uint8_t*)FlagTableVid[ 0 ];
    This->AudioFLAG = (uint8_t*)FlagTableAud[ 1 ];

    bmpHeader = ( STRF_BMPHEADER* ) ( tbuf1 + 12 + strhHeader->BlockSize + 8 );

    /* check for block id "strf" */
    if ( bmpHeader->BlockID != AVI_STRF_ID )
      return 0;

    This->StreamInfo.Width  = bmpHeader->bmiHeader.Width;
    This->StreamInfo.Height = bmpHeader->bmiHeader.Height;

    /* skip list header */
    tbuf1 += listHeader->BlockSize + 8;

    listHeader = ( LIST_HEADER* ) tbuf1;

    /* check for list id */
    if( listHeader->ListID != AVI_LIST_ID )
    {
      This->StreamInfo.SampleRate = 0;
      This->StreamInfo.Channels   = 0;
      This->StreamInfo.AudioType  = 0;
    }
    else
    {
      /* check for list type "strl" */
      if( listHeader->ListType != AVI_STRL_ID )
        return 0;

      strhHeader = ( STRH_HEADER* ) ( tbuf1 + 12 );

      /* check for block id "strh" */
      if ( strhHeader->BlockID != AVI_STRH_ID )
        return 0;

      if ( strhHeader->StreamType != AVI_AUDS_STREAM )
        return 0;

      wavHeader = ( STRF_WAVHEADER* ) ( tbuf1 + 12 + strhHeader->BlockSize + 8 );

      /* check for block id "strf" */
      if ( wavHeader->BlockID != AVI_STRF_ID )
        return 0;

      This->StreamInfo.SampleRate = wavHeader->SampleRate;
      This->StreamInfo.Channels   = wavHeader->Channels;
      This->StreamInfo.AudioType  = wavHeader->FormatTag;
    }
  }
  else if( strhHeader->StreamType == AVI_AUDS_STREAM )
  {
    This->VideoFLAG =(uint8_t*) FlagTableVid[ 1 ];
    This->AudioFLAG =(uint8_t*) FlagTableAud[ 0 ];
    wavHeader = ( STRF_WAVHEADER* ) ( tbuf1 + 12 + strhHeader->BlockSize + 8 );

    /* check for block id "strf" */
    if ( wavHeader->BlockID != AVI_STRF_ID )
      return 0;

    This->StreamInfo.SampleRate  = wavHeader->SampleRate;
    This->StreamInfo.Channels    = wavHeader->Channels;
    This->StreamInfo.AudioType   = wavHeader->FormatTag;

    tbuf1 += listHeader->BlockSize + 8;

    listHeader = ( LIST_HEADER* ) tbuf1;

    /* check for list id */
    if ( listHeader->ListID != AVI_LIST_ID )
      return 0;

    /* check for list type "strl" */
    if ( listHeader->ListType != AVI_STRL_ID )
      return 0;

    strhHeader = ( STRH_HEADER* ) ( tbuf1 + 12 );

    /* check for block id "strh" */
    if(strhHeader->BlockID != AVI_STRH_ID)
      return 0;

    if(strhHeader->StreamType != AVI_VIDS_STREAM)
      return 0;

    bmpHeader = ( STRF_BMPHEADER* ) ( tbuf1 + 12 + strhHeader->BlockSize + 8 );

    if ( bmpHeader->BlockID != AVI_STRF_ID )
      return 0;

    if ( bmpHeader->bmiHeader.Compression != AVI_FORMAT_MJPG )
      return 0;

    This->StreamInfo.Width  = bmpHeader->bmiHeader.Width;
    This->StreamInfo.Height = bmpHeader->bmiHeader.Height;
  }

  return 1;
}
