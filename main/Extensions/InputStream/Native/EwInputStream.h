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

#ifndef EWINPUTSTREAM_H
#define EWINPUTSTREAM_H


/*******************************************************************************
* MACRO:
*   EW_INPUT_STREAM_SEEK_X
*
* DESCRIPTION:
*   This is a definition of possible origins in call to the InputStreamSeek()
*
* ELEMENTS:
*   EW_INPUT_STREAM_SEEK_SET - Seek relative to the begin of the stream.
*   EW_INPUT_STREAM_SEEK_END - Seek relative to the end of the stream.
*   EW_INPUT_STREAM_SEEK_CUR - Seek relative to the current stream's read pointer.
*
*******************************************************************************/
#define EW_INPUT_STREAM_SEEK_SET         1
#define EW_INPUT_STREAM_SEEK_END         2
#define EW_INPUT_STREAM_SEEK_CUR         3


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
typedef struct XInputStreamStruct* XInputStream;


/*******************************************************************************
* TYPE:
*   XInputStreamRead
*
* DESCRIPTION:
*   This prototype defines a method an input stream interface has to implement
*   in order to read bytes from a stream. The method reads up to aCount
*   bytes and stores them within aBuffer. If successful, the method
*   returns the number of read bytes. This returned value can be less than the
*   aCount argument if the end of stream has been reached. After the read
*   operation the streams's read pointer is moved.
*
* ARGUMENTS:
*   aThis   - The pointer to the affected input stream instance.
*   aBuffer - The pointer to the buffer where the read bytes should be stored in.
*   aCount  - The number of bytes to read from the stream.
*
* RETURN VALUE:
*   The number of read bytes or 0 (zero) if the end of file has been reached.
*******************************************************************************/
typedef long (*XInputStreamRead)
(
  XInputStream     aThis,
  void*            aBuffer,
  long             aCount
);


/*******************************************************************************
* TYPE:
*   XInputStreamSeek
*
* DESCRIPTION:
*   This prototype defines a method an input stream interface has to implement
*   in order to move the stream's read pointer. This pointer defines the
*   position where the next read operation starts.
*
* ARGUMENTS:
*   aThis   - The pointer to the affected file stream instance.
*   aOrigin - The origin for the seek operation
*             (one of the EW_INPUT_STREAM_SEEK_X values).
*   aOffset - Number of bytes relative to the origin.
*
* RETURN VALUE:
*   A value != 0 if the seek operation was successful.
*******************************************************************************/
typedef int (*XInputStreamSeek)
(
  XInputStream     aThis,
  int              aOrigin,
  long             aOffset
);


/*******************************************************************************
* TYPE:
*   XInputStreamTell
*
* DESCRIPTION:
*   This prototype defines a method an input stream interface has to implement
*   in order to return the current position of the stream's read pointer.
*   This pointer defines the position where the next read operation starts.
*
* ARGUMENTS:
*   aThis  - The pointer to the affected file stream instance.
*
* RETURN VALUE:
*   The current position of the file's read/write pointer.
*******************************************************************************/
typedef long (*XInputStreamTell)
(
  XInputStream aThis
);



/*******************************************************************************
* TYPE:
*   XInputStreamRelease
*
* DESCRIPTION:
*   This prototype defines a method an interface has to implement in order to
*   release itself.
*
* ARGUMENTS:
*   aThis - The pointer to the affected file stream instance.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
typedef void (*XInputStreamRelease)
(
  XInputStream aThis
);


/*******************************************************************************
* TYPE:
*   XInputStreamCreate
*
* DESCRIPTION:
*   This prototype defines a method to create a new InputStream.
*
* ARGUMENTS:
*   aPath - The path including scheme of the source the new InputStream is
*           created from.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
typedef XInputStream (*XInputStreamCreate)
(
  char* aPath
);


/*******************************************************************************
* TYPE:
*   XInputStreamOps
*
* DESCRIPTION:
*   This is a prototype of the input stream operations.
*
* ELEMENTS:
*   Release - Closes the input stream and frees all affected resources.
*   Read    - Reads bytes from the input stream.
*   Seek    - Moves the read pointer of the input stream.
*   Tell    - Returns the current read pointer position of the input stream.
*
*******************************************************************************/
struct XInputStreamOps
{
  XInputStreamRelease  Release;
  XInputStreamRead     Read;
  XInputStreamSeek     Seek;
  XInputStreamTell     Tell;
};


/*******************************************************************************
* FUNCTION:
*   EwInputStreamRegisterSource
*
* DESCRIPTION:
*   registers a InputStream source by an uniqe name.
*
* ARGUMENTS:
*   aScheme               - The scheme, the given InputStream is registered.
*   aInputStreamCreateFkt - The function to create an InputStream for this scheme.
*
* RETURN:
*   A non zero value, if registration was successfull.
*
*******************************************************************************/
int EwInputStreamRegisterSource(
  const char*        aScheme,
  XInputStreamCreate aInputStreamCreateFkt
);


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
EwInputStreamCreate( char* aFilePath );


/*******************************************************************************
* FUNCTION:
*   EwInputStreamRelease
*
* DESCRIPTION:
*   Closes the stream and frees all affected resources.
*
* ARGUMENTS:
*   This - The input stream instance.
*
*******************************************************************************/
void
EwInputStreamRelease( XInputStream This );


/*******************************************************************************
* FUNCTION:
*   EwInputStreamRead
*
* DESCRIPTION:
*   Reads bytes from the input stream.
*
* ARGUMENTS:
*   This    - The input stream instance.
*   aBuffer - The buffer where the read bytes should be stored to.
*   aCount  - The number of bytes to read from the stream.
*
*******************************************************************************/
long
EwInputStreamRead( XInputStream This, void* aBuffer, long aCount );



/*******************************************************************************
* FUNCTION:
*   EwInputStreamSeek
*
* DESCRIPTION:
*   Moves the read pointer of the input stream.
*
* ARGUMENTS:
*   This    - The input stream instance.
*   aOrigin - The origin for the seek operation
*             (one of the EW_INPUT_STREAM_SEEK_X values).
*   aOffset - Number of bytes relative to the origin.
*
*******************************************************************************/
int
EwInputStreamSeek( XInputStream This, int aOrigin, long aOffset );


/*******************************************************************************
* FUNCTION:
*   EwInputStreamell
*
* DESCRIPTION:
*   Returns the current read pointer position of the input stream.
*
* ARGUMENTS:
*   This    - The input stream instance.
*
*******************************************************************************/
long
EwInputStreamell( XInputStream This );


#endif
