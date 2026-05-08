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
*   This file implements a set of functions to decode JPEG frames.
*
*******************************************************************************/
#include "ewconfig.h"
#include "ewrte.h"
#include "ewgfx.h"

#include <stdint.h>
#include <string.h>

#include "ewrte.h"
#include "EwJpegDec.h"

#ifndef EW_USED_JPEG_DEC
  #define EW_USED_JPEG_DEC EW_JPEG_DEC_LIBJPEG
#endif

#if EW_USED_JPEG_DEC == EW_JPEG_DEC_LIBJPEG

#include "jpeglib.h"

#define XJpegDecLibJpegInstance     XJpegDecInstance
#define EwJpegDecLibJpegCreate      EwJpegDecCreate
#define EwJpegDecLibJpegDestroy     EwJpegDecDestroy
#define EwJpegDecLibJpegDecode      EwJpegDecDecode
#define EwJpegDecLibJpegDecGetInfo  EwJpegDecGetInfo


#if EW_JPEG_IMAGE_PIXEL_FORMAT == EW_PIXEL_FORMAT_RGB565
  #define EW_TURBO_JPEG_COLOR_SPACE JCS_RGB565
#else
  #define EW_TURBO_JPEG_COLOR_SPACE JCS_EXT_BGRA
#endif


/*******************************************************************************
* Section: global data
*******************************************************************************/

/*******************************************************************************
* FUNCTION:
*   EwJpegDecLibJpegCreate
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
XJpegDec EwJpegDecLibJpegCreate( void )
{
  return ( XJpegDec ) 1;
}


/*******************************************************************************
* FUNCTION:
*   EwJpegDecLibJpegDestroy
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
void EwJpegDecLibJpegDestroy( XJpegDec aThis  )
{
}


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
int EwJpegDecLibJpegDecGetInfo( XJpegDec aThis, unsigned char * aJpegImage,
  int aJpegImageSize, XJpegDecInfo* aJpeginfo )
{
  struct jpeg_decompress_struct cinfo;
  struct jpeg_error_mgr         jerr;
  int                           result;
  int                           success = 0;


  /* Step 1: allocate and initialize JPEG decompression object */
  cinfo.err = jpeg_std_error(&jerr);

  /* Initialize the JPEG decompression object */
  jpeg_create_decompress(&cinfo);

  jpeg_mem_src (&cinfo, aJpegImage, aJpegImageSize);

  /* Step 3: read image parameters with jpeg_read_header() */
  result = jpeg_read_header(&cinfo, TRUE);

  if ( result != JPEG_HEADER_OK )
    goto onError;

  memset( aJpeginfo, 0, sizeof( *aJpeginfo ));
  aJpeginfo->Width  = cinfo.image_width;
  aJpeginfo->Height = cinfo.image_height;
  success = 1;


onError:

  /* Step 4: Release JPEG decompression object */
  jpeg_destroy_decompress(&cinfo);

  return success;
}


/*******************************************************************************
* FUNCTION:
*   EwBspJpegDecDecode
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
int EwJpegDecLibJpegDecode( XJpegDec aThis, unsigned char * aJpegImage,
  int aJpegImageSize, void * aOutputBuffer, int aPitchY )
{
  struct jpeg_decompress_struct cinfo;
  struct jpeg_error_mgr         jerr;
  JSAMPROW                      buffer;

  buffer = (uint8_t*)aOutputBuffer;

  /* Step 1: allocate and initialize JPEG decompression object */
  cinfo.err = jpeg_std_error(&jerr);

  /* Initialize the JPEG decompression object */
  jpeg_create_decompress(&cinfo);

  jpeg_mem_src (&cinfo, aJpegImage, aJpegImageSize);

  /* Step 3: read image parameters with jpeg_read_header() */
  jpeg_read_header(&cinfo, TRUE);

  /* Step 4: set parameters for decompression */
  cinfo.dct_method      = JDCT_IFAST;
  cinfo.dither_mode     = JDITHER_FS;
  cinfo.out_color_space = EW_TURBO_JPEG_COLOR_SPACE;

  /* Step 5: start decompressor */
  jpeg_start_decompress(&cinfo);
  while (cinfo.output_scanline < cinfo.output_height)
  {
    int nbOfLines = jpeg_read_scanlines( &cinfo, &buffer, 1 );
    buffer += aPitchY * nbOfLines;
  }

  /* Step 6: Finish decompression */
  jpeg_finish_decompress(&cinfo);

  /* Step 7: Release JPEG decompression object */
  jpeg_destroy_decompress(&cinfo);

  return 1;
}

#endif

/* EOF */