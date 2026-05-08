/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This software is delivered "as is" and shows the usage of other software
* components. It is provided as an example software which is intended to be
* modified and extended according to particular requirements.
*
* TARA Systems hereby disclaims all warranties and conditions with regard to the
* software, including all implied warranties and conditions of merchantability
* and non-infringement of any third party IPR or other rights which may result
* from the use or the inability to use the software.
*
********************************************************************************
*
* DESCRIPTION:
*   This file declares the API to integrate ExternVideo within Embedded Wizard.
*
*******************************************************************************/

#ifndef EWEXTVIDEO_H
#define EWEXTVIDEO_H


#include "ewrte.h"
#include "ewgfx.h"


#ifdef __cplusplus
  extern "C"
  {
#endif

/* An enumeration with the possible states of a ExternVideo instance. */
#define EW_EXTERN_VIDEO_STATE_UNKNOWN                 0
#define EW_EXTERN_VIDEO_STATE_BUFFERING               1
#define EW_EXTERN_VIDEO_STATE_READY                   2
#define EW_EXTERN_VIDEO_STATE_RESUMING                3
#define EW_EXTERN_VIDEO_STATE_PLAYING                 4
#define EW_EXTERN_VIDEO_STATE_PAUSED                  5
#define EW_EXTERN_VIDEO_STATE_END_OF_STREAM           6
#define EW_EXTERN_VIDEO_STATE_ERROR                   7


/* An enumeration with the possible errors of a ExternVideo instance. */
#define EW_EXTERN_VIDEO_ERROR_NONE                    0
#define EW_EXTERN_VIDEO_ERROR_NAME_NOT_FOUND          1
#define EW_EXTERN_VIDEO_ERROR_ACCESS_ERROR            2
#define EW_EXTERN_VIDEO_ERROR_CONTENT_ERROR           3
#define EW_EXTERN_VIDEO_ERROR_OTHER_ERROR             4


/*******************************************************************************
* FUNCTION:
*   EwExternVideoCreate
*
* DESCRIPTION:
*   The function EwExternVideoCreate() creates a new ExternVideo instance to
*   decode the provided aSource video or image file. The new created instance
*   is per default paused. The decoder should decode and provide the first
*   frame only. To start the playback use the function EwExternVideoResume().
*
* ARGUMENTS:
*   aSource - File name or URL identifying the data to decode.
*
* RETURN VALUE:
*   The function returns a new instance of the created ExternVideo glue-layer.
*
*******************************************************************************/
XHandle EwExternVideoCreate
(
  XString           aSource
);


/*******************************************************************************
* FUNCTION:
*   EwExternVideoDestroy
*
* DESCRIPTION:
*   The function EwExternVideoDestroy() stops the ExternVideo and waits for its
*   finalization. Then all still existing ExternVideo resources are released.
*
* ARGUMENTS:
*   aInstance - The ExternVideo instance.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwExternVideoDestroy
(
  XHandle           aInstance
);


/*******************************************************************************
* FUNCTION:
*   EwExternVideoPause
*
* DESCRIPTION:
*   The function EwExternVideoPause() pauses the ExternVideo. The decoder stops
*   at the latest decoded frame.
*
* ARGUMENTS:
*   aInstance - The ExternVideo instance.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwExternVideoPause
(
  XHandle           aInstance
);


/*******************************************************************************
* FUNCTION:
*   EwExternVideoResume
*
* DESCRIPTION:
*   The function EwExternVideoResume() reactivates the ExternVideo.
*
* ARGUMENTS:
*   aInstance - The ExternVideo instance.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwExternVideoResume
(
  XHandle           aInstance
);


/*******************************************************************************
* FUNCTION:
*   EwExternVideoGetNewBitmap
*
* DESCRIPTION:
*   The function EwExternVideoGetNewBitmap() verifies whether there is a new
*   buffer provided by ExternVideo. If this is the case the function return an
*   Embedded Wizard bitmap envolving the content of this buffer. If there is no
*   new buffer available, the function returns NULL.
*
*   Please note, the returned bitmap remains in the property of the ExternVideo
*   decoder. The caller of the function may not free the bitmap! If NULL is
*   returned by the function, the previous bitmap is still valid.
*
* ARGUMENTS:
*   aInstance - The ExternVideo instance.
*
* RETURN VALUE:
*   The function returns an Embedded Wizard bitmap containing the new frame or
*   NULL if there is no new frame to display. In this case the previously
*   obtained bitmap is still valid.
*
*******************************************************************************/
XBitmap* EwExternVideoGetNewBitmap
(
  XHandle           aInstance
);


/*******************************************************************************
* FUNCTION:
*   EwExternVideoGetState
*
* DESCRIPTION:
*   The function EwExternVideoGetState() returns the latest known state of the
*   ExternVideo processing.
*
* ARGUMENTS:
*   aInstance - The ExternVideo instance.
*
* RETURN VALUE:
*   The latest known state. See the defines EW_EXTERN_VIDEO_STATE_XXX.
*
*******************************************************************************/
int EwExternVideoGetState
(
  XHandle           aInstance
);


/*******************************************************************************
* FUNCTION:
*   EwExternVideoGetNoOfFrames
*
* DESCRIPTION:
*   The function EwExternVideoGetNoOfFrames() returns the duration of the
*   currently selected media expressed in frames.
*
* ARGUMENTS:
*   aInstance - The ExternVideo instance.
*
* RETURN VALUE:
*   The number of frames belonging to the media.
*
*******************************************************************************/
int EwExternVideoGetNoOfFrames
(
  XHandle aInstance
);


/*******************************************************************************
* FUNCTION:
*   EwExternVideoGetCurrentFrame
*
* DESCRIPTION:
*   The function EwExternVideoGetCurrentFrame() returns the position of the
*   playback as the number of the current frame.
*
* ARGUMENTS:
*   aInstance - The ExternVideo instance.
*
* RETURN VALUE:
*   The frame number as current playback position. The first frame has the
*   number 0, the second 1, and so far.
*
*******************************************************************************/
int EwExternVideoGetCurrentFrame
(
  XHandle aInstance
);


/*******************************************************************************
* FUNCTION:
*   EwExternVideoSetCurrentFrame
*
* DESCRIPTION:
*   The function EwExternVideoSetCurrentFrame() sets a the currently selected
*   media to the given frame as current playback position. When changing the
*   current frame number while the video playback is paused (see the function
*   EwExternVideoPause()), the decoder should skip to the new frame, decode it
*   and provide it via EwExternVideoGetNewBitmap().
*
* ARGUMENTS:
*   aInstance     - The ExternVideo instance.
*   aCurrentFrame - The new position as frame number. The first frame has the
*     number 0, the second 1, and so far.
*
* RETURN VALUE:
*   A non zero value, if successfull.
*
*******************************************************************************/
int EwExternVideoSetCurrentFrame
(
  XHandle aInstance,
  int     aCurrentFrame
);


/*******************************************************************************
* FUNCTION:
*   EwExternVideoGetFrameRate
*
* DESCRIPTION:
*   The function EwExternVideoGetFrameRate() returns the number of frames per
*   second, the currently playbacked media is providing.
*
* ARGUMENTS:
*   aInstance - The ExternVideo instance.
*
* RETURN VALUE:
*   The number of frames per second.
*
*******************************************************************************/
float EwExternVideoGetFrameRate
(
  XHandle aInstance
);


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
*   aInstance - The ExternVideo instance.
*
* RETURN VALUE:
*   The currently set play speed.
*
*******************************************************************************/
int EwExternVideoGetSpeed
(
  XHandle aInstance
);


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
*   aInstance - The ExternVideo instance.
*   aSpeed    - The new play speed.
*
* RETURN VALUE:
*   A non zero value, if successfull.
*
*******************************************************************************/
int EwExternVideoSetSpeed
(
  XHandle aInstance,
  int     aSpeed
);


/*******************************************************************************
* FUNCTION:
*   EwExternVideoGetError
*
* DESCRIPTION:
*   The function EwExternVideoGetError() returns the latest known error of the
*   ExternVideo processing. The possible errors reflect the common errors found
*   in all decoders.
*
*   For more detailed error information the function EwExternVideoGetErrorCode()
*   is available.
*
* ARGUMENTS:
*   aInstance - The ExternVideo instance.
*
* RETURN VALUE:
*   The latest known error. See the defines EW_EXTERN_VIDEO_ERROR_XXX.
*
*******************************************************************************/
int EwExternVideoGetError
(
  XHandle aInstance
);


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
unsigned int EwExternVideoGetErrorCode
(
  XHandle aInstance
);


#ifdef __cplusplus
  }
#endif

#endif /* EWEXTERNVIDEO_H */
