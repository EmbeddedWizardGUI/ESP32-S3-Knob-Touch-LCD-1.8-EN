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
*   This file implements the InputStream base class.
*
*******************************************************************************/

#include "EwInputStream.h"
#include "EwInputStreamSpiffs.h"
#include <string.h>

#define EW_INPUTSTREAM_MAX_SOURCES  8
#define EW_INPUT_STREAM_SCHEME_MAX_LEN 15




/*******************************************************************************
* TYPE:
*   XInputStream
*
* DESCRIPTION:
*   This is the prototype of EW input streams.
*
* ELEMENTS:
*   Ops - Refers to the interface of the stream instance.
*
*******************************************************************************/
typedef struct XInputStreamStruct
{
  struct XInputStreamOps* Ops;
} XInputStreamStruct;


/*******************************************************************************
* TYPE:
*   XInputStream
*
* DESCRIPTION:
*   This is the prototype of EW input streams.
*
* ELEMENTS:
*   Ops - Refers to the interface of the stream instance.
*
*******************************************************************************/
typedef struct XInputStreamRegisterStruct
{
  const char*             Scheme;
  XInputStreamCreate    Create;
} XInputStreamRegisterStruct;


static XInputStreamRegisterStruct Sources[ EW_INPUTSTREAM_MAX_SOURCES ];
static int NbOfRegisteredSources = 0;
static int EwInputStreamInitialized = 0;


/*******************************************************************************
* FUNCTION:
*   EwInputStreamRegisterSource
*
* DESCRIPTION:
*   registers a InputStream source by an unique name.
*
* ARGUMENTS:
*   aScheme               - The scheme, the given InputStream is registered.
*   aInputStreamCreateFkt - The function to create an InputStream for this scheme.
*
* RETURN:
*   A non zero value, if registration was successful.
*
*******************************************************************************/
int
EwInputStreamRegisterSource( const char* aScheme, XInputStreamCreate aInputStreamCreateFkt )
{
  int i = 0;

  if ( ! aScheme || ! aInputStreamCreateFkt )
    return 0;

  if ( NbOfRegisteredSources >= EW_INPUTSTREAM_MAX_SOURCES )
    return 0;

  /* check, if the given scheme is already in use */

  while ( i < NbOfRegisteredSources )
  {
    if ( strcmp( aScheme, Sources[ i ].Scheme ) == 0 )
      break;
    i++;
  }

  if ( i != NbOfRegisteredSources )
    return 0;

  Sources[ NbOfRegisteredSources ].Scheme = aScheme;
  Sources[ NbOfRegisteredSources ].Create = aInputStreamCreateFkt;

  NbOfRegisteredSources++;
  return 1;
}


/*******************************************************************************
* FUNCTION:
*   EwInputStreamCreate
*
* DESCRIPTION:
*   Closes the stream and frees all affected resources.
*
* ARGUMENTS:
*   aFilePath - The file to be opened (e.g. file://image.jpg).
*
*******************************************************************************/
XInputStream
EwInputStreamCreate( char* aFilePath )
{
  char   scheme[ EW_INPUT_STREAM_SCHEME_MAX_LEN + 1 ];
  char*  delimiter;
  int    len;
  int    i = 0;

  if ( ! aFilePath )
    return NULL;


  if ( ! EwInputStreamInitialized )
  {
    /* register SPIFFS source for flash:// scheme */
    EwInputStreamRegisterSource( "flash", EwInputStreamSpiffsCreate );
    EwInputStreamInitialized = 1;
  }

  delimiter = strchr( aFilePath, ':');
  if ( ! delimiter )
    return NULL;

  len = delimiter - aFilePath;
  if ( len > EW_INPUT_STREAM_SCHEME_MAX_LEN )
    return NULL;

  strncpy( scheme, aFilePath, len );
  scheme[ len ] = 0;

  while ( i < NbOfRegisteredSources )
  {
    if ( strcmp( scheme, Sources[ i ].Scheme ) == 0 )
      break;

    i++;
  }

  if ( i == NbOfRegisteredSources )
    return NULL;

  return Sources[ i ].Create( aFilePath + len + 3 );
}


/*******************************************************************************
* FUNCTION:
*   EwInputStreamRelease
*
* DESCRIPTION:
*   Closes the stream and frees all affected resources.
*
* ARGUMENTS:
*   aThis - The input stream instance.
*
*******************************************************************************/
void
EwInputStreamRelease( XInputStream aThis )
{
  if ( ! aThis )
    return;

  if ( aThis->Ops->Release )
    aThis->Ops->Release( aThis );
}


/*******************************************************************************
* FUNCTION:
*   EwInputStreamRead
*
* DESCRIPTION:
*   Reads bytes from the input stream.
*
* ARGUMENTS:
*   aThis   - The input stream instance.
*   aBuffer - The buffer where the read bytes should be stored to.
*   aCount  - The number of bytes to read from the stream.
*
*******************************************************************************/
long
EwInputStreamRead( XInputStream aThis, void* aBuffer, long aCount )
{
  if ( ! aThis )
    return 0;

  if ( aThis->Ops->Read )
    return aThis->Ops->Read( aThis, aBuffer, aCount );

  return 0;
}


/*******************************************************************************
* FUNCTION:
*   EwInputStreamSeek
*
* DESCRIPTION:
*   Moves the read pointer of the input stream.
*
* ARGUMENTS:
*   aThis   - The input stream instance.
*   aOrigin - The origin for the seek operation
*             (one of the EW_INPUT_STREAM_SEEK_X values).
*   aOffset - Number of bytes relative to the origin.
*
*******************************************************************************/
int
EwInputStreamSeek( XInputStream aThis, int aOrigin, long aOffset )
{
  if ( ! aThis )
    return 0;

  if ( aThis->Ops->Seek )
    return aThis->Ops->Seek( aThis, aOrigin, aOffset );

  return 0;
}


/*******************************************************************************
* FUNCTION:
*   EwInputStreamTell
*
* DESCRIPTION:
*   Returns the current read pointer position of the input stream.
*
* ARGUMENTS:
*   aThis   - The input stream instance.
*
*******************************************************************************/
long
EwInputStreamTell( XInputStream aThis )
{
  if ( ! aThis )
    return 0;

  if ( aThis->Ops->Tell )
    return aThis->Ops->Tell( aThis );

  return 0;
}

