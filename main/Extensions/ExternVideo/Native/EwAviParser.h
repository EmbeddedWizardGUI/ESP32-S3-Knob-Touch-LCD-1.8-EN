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

#ifndef  EW_AVI_PARSER_H
#define  EW_AVI_PARSER_H

#include <stdint.h>
#include <string.h>

#if defined(__cplusplus)
extern "C" {
#endif


#define  EW_AVI_PARSER_END_FILE     0
#define  EW_AVI_PARSER_VIDEO_FRAME  1
#define  EW_AVI_PARSER_AUDIO_FRAME  2
#define  EW_AVI_PARSER_ERROR        3


typedef struct XAviParserStruct* XAviParser;


typedef struct XAviParserStreamInfo
{
  unsigned long   TotalFrames;
  unsigned long   SecPerFrame;
  uint32_t        FrameRate;
  uint32_t        Width;
  uint32_t        Height;

  uint32_t        SampleRate;
  uint16_t        Channels;
  uint16_t        AudioType;

} XAviParserStreamInfo;


typedef struct XAviParserFrameInfo
{
  unsigned long   Size;
  unsigned char*  Buffer;

} XAviParserFrameInfo;


/*******************************************************************************
* FUNCTION:
*   EwAviParserCreate
*
* DESCRIPTION:
*   Creates a EW AVI parser and parses the stream header.
*
* ARGUMENTS:
*
*
* RETURN VALUE:
*   The new EwAviParser, if successsfull, NULL otherwise.
*
*******************************************************************************/
XAviParser
EwAviParserCreate( XInputStream  aInputStream, unsigned long aVideoBufferSize, unsigned long aAudioBufferSize );


/*******************************************************************************
* FUNCTION:
*   EwAviParserGetStreamInfo
*
* DESCRIPTION:
*   Returns the stream info.
*
* ARGUMENTS:
*
*
* RETURN VALUE:
*   The stream info.
*
*******************************************************************************/
int
EwAviParserGetStreamInfo(  XAviParser This, XAviParserStreamInfo* aStreamInfo );


/*******************************************************************************
* FUNCTION:
*   EwAviParserDestroy
*
* DESCRIPTION:
*   Destroys the given EW AVI parser.
*
* ARGUMENTS:
*
*
*******************************************************************************/
void
EwAviParserDestroy( XAviParser This );


/*******************************************************************************
* FUNCTION:
*   EwAviParserGetNextFrame
*
* DESCRIPTION:
*   Gets the next audio or video frame.
*
* ARGUMENTS:
*
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwAviParserSetFrameNumber( XAviParser This, int aFrameNumber );
uint32_t EwAviParserGetNextFrame( XAviParser This, XAviParserFrameInfo* aFrameInfo );


#if defined(__cplusplus)
}
#endif

#endif
