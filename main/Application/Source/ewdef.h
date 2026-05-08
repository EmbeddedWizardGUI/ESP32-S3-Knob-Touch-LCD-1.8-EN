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
*   This file contains basic defines and useful configuration macros.
*
*******************************************************************************/

#ifndef EWDEF_H
#define EWDEF_H

/* defines for different framebuffer color formats */
#define EW_FRAME_BUFFER_COLOR_FORMAT_Index8   1
#define EW_FRAME_BUFFER_COLOR_FORMAT_LumA44   2
#define EW_FRAME_BUFFER_COLOR_FORMAT_RGB565   3
#define EW_FRAME_BUFFER_COLOR_FORMAT_RGB888   4
#define EW_FRAME_BUFFER_COLOR_FORMAT_RGBA4444 5
#define EW_FRAME_BUFFER_COLOR_FORMAT_RGBA8888 6

#if ( EW_FRAME_BUFFER_COLOR_FORMAT == EW_FRAME_BUFFER_COLOR_FORMAT_RGBA8888 )
  #define EW_FRAME_BUFFER_COLOR_FORMAT_STRING "RGBA8888"
  #define EW_FRAME_BUFFER_DEPTH  4
#elif ( EW_FRAME_BUFFER_COLOR_FORMAT == EW_FRAME_BUFFER_COLOR_FORMAT_RGB888 )
  #define EW_FRAME_BUFFER_COLOR_FORMAT_STRING "RGB888"
  #define EW_FRAME_BUFFER_DEPTH  3
#elif ( EW_FRAME_BUFFER_COLOR_FORMAT == EW_FRAME_BUFFER_COLOR_FORMAT_RGBA4444 )
  #define EW_FRAME_BUFFER_COLOR_FORMAT_STRING "RGBA4444"
  #define EW_FRAME_BUFFER_DEPTH  2
#elif ( EW_FRAME_BUFFER_COLOR_FORMAT == EW_FRAME_BUFFER_COLOR_FORMAT_RGB565 )
  #define EW_FRAME_BUFFER_COLOR_FORMAT_STRING "RGB565"
  #define EW_FRAME_BUFFER_DEPTH  2
#elif ( EW_FRAME_BUFFER_COLOR_FORMAT == EW_FRAME_BUFFER_COLOR_FORMAT_Index8 )
  #define EW_FRAME_BUFFER_COLOR_FORMAT_STRING "Index8"
  #define EW_FRAME_BUFFER_DEPTH  1
#elif ( EW_FRAME_BUFFER_COLOR_FORMAT == EW_FRAME_BUFFER_COLOR_FORMAT_LumA44 )
  #define EW_FRAME_BUFFER_COLOR_FORMAT_STRING "LumA44"
  #define EW_FRAME_BUFFER_DEPTH  1
#else
  #error "EW_FRAME_BUFFER_COLOR_FORMAT not supported"
#endif

#endif

/* mli, msy */
