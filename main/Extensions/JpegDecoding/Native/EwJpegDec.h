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
*   This file defines the interface to an Embedded Wizard JPEG decoder.
*
*******************************************************************************/

#ifndef EWJPEGDEC_H
#define EWJPEGDEC_H

#define EW_JPEG_DEC_LIBJPEG   1
#define EW_JPEG_DEC_HW        2
#define EW_JPEG_DEC_PICOJPEG  3


/****************************************************************************
 * TYPE: XJpegDec
 *
 * DESCRIPTION:
 *   This type defines an Embedded Wizard JPEG decoder instance.
 ****************************************************************************/
typedef struct XJpegDecInstance* XJpegDec;


/****************************************************************************
 * TYPE: XJpegDecInfo
 *
 * DESCRIPTION:
 *   This type defines the JPEG image info structure.
 ****************************************************************************/
typedef struct XJpegDecInfo
{
  int Width;
  int Height;
} XJpegDecInfo;


/*******************************************************************************
* FUNCTION:
*   EwJpegDecCreate
*
* DESCRIPTION:
*   This function creates a new Embedded Wizard JPEG decoder instance.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   XJpegDec - A Embedded Wizard JPEG decoder instance.
*
*******************************************************************************/
XJpegDec EwJpegDecCreate( void );


/*******************************************************************************
* FUNCTION:
*   EwJpegDecDestroy
*
* DESCRIPTION:
*   This function destroys an Embedded Wizard JPEG decoder instance.
*   Call this function, if the Embedded Wizard JPEG decoder instance is no
*   longer needed.
*
* ARGUMENTS:
*   aThis - The Embedded Wizard JPEG decoder instance.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwJpegDecDestroy( XJpegDec aThis );



/*******************************************************************************
* FUNCTION:
*   EwBspJpegDecGetInfo
*
* DESCRIPTION:
*   This function returns a JPEG image infor structure for the given JPEG image.
*
* ARGUMENTS:
*   This             - The Embedded Wizard JPEG decoder instance.
*   aJpegImage       - The buffer containing the whole JPEG image file.
*   aJpegImageSize   - The size of the JPEG image buffer.
*
* RETURN VALUE:
*   1 if successful, 0 otherwise.
*
*******************************************************************************/
int EwJpegDecGetInfo( XJpegDec aThis, unsigned char * aJpegImage,
  int aJpegImageSize, XJpegDecInfo* aJpeginfo );


/*******************************************************************************
* FUNCTION:
*   EwJpegDecDecode
*
* DESCRIPTION:
*   This function decodes the given JPEG image.
*
* ARGUMENTS:
*   This             - The Embedded Wizard JPEG decoder instance.
*   aJpegImage       - The buffer containing the whole JPEG image file.
*   aJpegImageSize   - The size of the JPEG image buffer.
*   aOutputBuffer    - The destination pixel buffer.
*   aPitchY          - The Distance in bytes between two pixel rows.
*
* RETURN VALUE:
*   1 if successful, 0 otherwise.
*
*******************************************************************************/
int EwJpegDecDecode( XJpegDec aThis, unsigned char * aJpegImage,
  int aJpegImageSize, void * aOutputBuffer, int aPitchY );


#endif
/* EOF */