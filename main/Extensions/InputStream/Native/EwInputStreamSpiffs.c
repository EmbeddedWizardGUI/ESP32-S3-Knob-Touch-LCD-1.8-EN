/*******************************************************************************
*
* Embedded Wizard - GUI Solutions by TARA Systems
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* DESCRIPTION:
*   This file implements the LittleFS InputStream interface for ESP32.
*   Video files are read from a LittleFS partition mounted at /littlefs/.
*   (Source-file and function names retain the historical "Spiffs" naming
*    from when the project used a real SPIFFS partition.)
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include "ewrte.h"
#include "EwInputStream.h"
#include "EwInputStreamSpiffs.h"


#define EW_INPUT_STREAM_SPIFFS_MAX_LEN_PATH   255
#define EW_INPUT_STREAM_SPIFFS_MOUNT_POINT    "/littlefs/"

static void
EwInputStreamSpiffsRelease( XInputStream This );
static long
EwInputStreamSpiffsRead( XInputStream This, void* aBuffer, long aCount );
static int
EwInputStreamSpiffsSeek( XInputStream This, int aOrigin, long aOffset );
static long
EwInputStreamSpiffsTell( XInputStream This );


/*******************************************************************************
* TYPE:
*   EwInputStreamSpiffs
*
* DESCRIPTION:
*   SPIFFS input stream instance.
*
*******************************************************************************/
typedef struct EwInputStreamSpiffsStruct * EwInputStreamSpiffs;

typedef struct EwInputStreamSpiffsStruct
{
  const struct XInputStreamOps*  Ops;
  FILE*                          Fd;

} EwInputStreamSpiffsStruct;


static const struct XInputStreamOps SpiffsOps =
{
  EwInputStreamSpiffsRelease,
  EwInputStreamSpiffsRead,
  EwInputStreamSpiffsSeek,
  EwInputStreamSpiffsTell
};


/*******************************************************************************
* FUNCTION:
*   EwInputStreamSpiffsCreate
*
* DESCRIPTION:
*   Opens the given file from SPIFFS and creates a new input stream.
*
* ARGUMENTS:
*   aFilePath - The file to be opened (without scheme prefix).
*
*******************************************************************************/
XInputStream
EwInputStreamSpiffsCreate( char* aFilePath )
{
  EwInputStreamSpiffs  This;
  char  path[ EW_INPUT_STREAM_SPIFFS_MAX_LEN_PATH + 1 ];

  if ( ! aFilePath )
    return 0;

  if ( strlen( EW_INPUT_STREAM_SPIFFS_MOUNT_POINT ) + strlen( aFilePath ) > EW_INPUT_STREAM_SPIFFS_MAX_LEN_PATH )
    return 0;

  sprintf( path, "%s%s", EW_INPUT_STREAM_SPIFFS_MOUNT_POINT, aFilePath );

  This = ( EwInputStreamSpiffs ) EwAlloc( sizeof( EwInputStreamSpiffsStruct ));
  memset( This, 0, sizeof( EwInputStreamSpiffsStruct ));

  This->Ops = &SpiffsOps;

  This->Fd = fopen(( const char* )path, "rb" );
  if ( ! This->Fd )
  {
    EwPrint( "EwInputStreamSpiffsCreate - file '%s' not found\n", path );
    goto onError;
  }

  // EwPrint( "EwInputStreamSpiffsCreate - opened '%s'\n", path );
  return ( XInputStream ) This;

onError:
  EwInputStreamSpiffsRelease(( XInputStream ) This );
  return 0;
}


/*******************************************************************************
* FUNCTION:
*   EwInputStreamSpiffsRelease
*
* DESCRIPTION:
*   Closes the stream and frees all affected resources.
*
*******************************************************************************/
static void
EwInputStreamSpiffsRelease( XInputStream aThis )
{
  EwInputStreamSpiffs This = ( EwInputStreamSpiffs )aThis;

  if ( This->Fd )
    fclose( This->Fd );

  EwFree( This );
}


/*******************************************************************************
* FUNCTION:
*   EwInputStreamSpiffsRead
*
* DESCRIPTION:
*   Reads bytes from the input stream.
*
*******************************************************************************/
static long
EwInputStreamSpiffsRead( XInputStream aThis, void* aBuffer, long aCount )
{
  EwInputStreamSpiffs This = ( EwInputStreamSpiffs )aThis;
  int readBytes = 0;

  if ( This->Fd )
    readBytes = fread( aBuffer, 1, aCount, This->Fd );

  return readBytes;
}


/*******************************************************************************
* FUNCTION:
*   EwInputStreamSpiffsSeek
*
* DESCRIPTION:
*   Moves the read pointer of the input stream.
*
*******************************************************************************/
static int
EwInputStreamSpiffsSeek( XInputStream aThis, int aOrigin, long aOffset )
{
  EwInputStreamSpiffs This = ( EwInputStreamSpiffs )aThis;
  int whence;

  switch( aOrigin )
  {
    case EW_INPUT_STREAM_SEEK_SET:  whence = SEEK_SET; break;
    case EW_INPUT_STREAM_SEEK_CUR:  whence = SEEK_CUR; break;
    case EW_INPUT_STREAM_SEEK_END:  whence = SEEK_END; break;
    default:
      EwPrint( "EwInputStreamSpiffsSeek - unsupported origin\n" );
      return 0;
  }

  if ( This->Fd )
    fseek( This->Fd, aOffset, whence );

  return 1;
}


/*******************************************************************************
* FUNCTION:
*   EwInputStreamSpiffsTell
*
* DESCRIPTION:
*   Returns the current read pointer position of the input stream.
*
*******************************************************************************/
static long
EwInputStreamSpiffsTell( XInputStream aThis )
{
  EwInputStreamSpiffs This = ( EwInputStreamSpiffs )aThis;

  if ( This->Fd )
    return ftell( This->Fd );

  return 0;
}
