/*******************************************************************************
*
* Embedded Wizard - GUI Solutions by TARA Systems
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This software and related documentation (the "Library") are intellectual
* property of TARA Systems GmbH.
*
* Use of this file and the Library is governed as follows:
*
*   (1) To the extent your use is covered by the Embedded Wizard License
*       Agreement (EWLA) and the Embedded Wizard Terms and Conditions (EWTC),
*       or by another written commercial license agreement with TARA Systems
*       GmbH that expressly covers this Library, that agreement governs;
*       otherwise
*
*   (2) Your use is governed by the Embedded Wizard Community License (EWCL).
*
* Absent such a commercial license as in (1), distribution of products including
* this Library may require you to provide the complete corresponding Application
* Source Code, as described in the Embedded Wizard Community License (EWCL).
*
* Any use, modification, copying, reproduction, or redistribution of this file
* not in accordance with the applicable license is expressly prohibited. The
* removal of this preamble is expressly prohibited.
*
* License information:
*   EWTC: https://www.embedded-wizard.de/legal/ewtc
*   EWLA: https://www.embedded-wizard.de/legal/ewla
*   EWCL: https://www.embedded-wizard.de/legal/ewcl
*
********************************************************************************
*
* DESCRIPTION:
*   This module implements the interface between the Graphics Engine and the
*   target specific graphics subsystem.
*   All graphics operations that can be accelerated by a graphics hardware are
*   delegated to the corresponding hardware functionality.
*   This module is responsible to manage the framebuffer(s) and to support the
*   synchronization between CPU, display controller and graphics accelerator.
*
*******************************************************************************/

#include "ewrte.h"
#include "ewgfx.h"
#include "ewextpxl_RGB565.h"

#include "ew_bsp_display.h"
#include "ew_bsp_system.h"

/* The color format of the framebuffer has to correspond to color format of the
   Graphics Engine, because the Graphics engine is prepared and optimized for
   one dedicated color format. */
#if ( EW_FRAME_BUFFER_COLOR_FORMAT != EW_FRAME_BUFFER_COLOR_FORMAT_RGB565 )
  #error The given EW_FRAME_BUFFER_COLOR_FORMAT is not supported! Use RGB565 within your makefile!
#endif

/* Error messages */
#define Err01 "Invalid framebuffer address!"
#define Err02 "Size of framebuffer device (display size) does not match with given application size!"
#define Err03 "Could not allocate memory!"
#define Err04 "Invalid double-buffer address!"
#define Err06 "Full screen update cannot be done within scratch-pad buffer!"
#define Err07 "Partial screen update cannot be combined with double buffering!"

/* Flags to indicate the current status of a surface */
#define EW_SURFACE_PREALLOCATED        0x01000000
#define EW_SURFACE_FRAMEBUFFER         0x02000000

/* The following defines are used to align pixel memory to the size of a single
   CPU cache line and to invalidate or clean the data cache of an address range.
   These settings are only mandatory when pixel data is accessed by both the CPU and
   a graphics accelerator. In this case it is important to ensure that the pixel
   data will never be in the same CPU cache line than any other programm data. */
#define EW_CACHE_LINE_SIZE                0
#define EW_ALIGN_TO_CACHE( addr )         (void*)( addr )
#define EW_INVALIDATE_CACHE( addr, size )
#define EW_CLEAN_CACHE( addr, size )

/* External flash reader for constant surfaces */
#ifdef EW_USE_READER_FOR_CONST_SURFACES
  extern XFlashAreaReaderProc EwFlashAreaReaderProc;
#endif

/* Descriptor of a target specific surface. This type is used for framebuffers and
   internal surfaces (bitmaps). The pixel memory of the surface may be preallocated
   for framebuffers or direct access bitmaps. In all other cases, the pixel memory
   is allocated and freed dynamically. */
typedef struct
{
  int              Width;
  int              Height;
  int              Flags;
  int              BytesPerPixel;
  int              Format;
  int              AllocSize;
  void*            AllocAddress;
  void*            Pixel;
  int              OrigHeight;
  void*            OrigPixel;
} XGfxSurface;


/* Descriptor of the target specific viewport. It contains pointers to the different
   surfaces (framebuffers) that are used for the display update. */
typedef struct
{
  XGfxSurface*     FrameBuffer;
  XGfxSurface*     DoubleBuffer;
} XGfxViewport;


/* Memory usage profiler */
extern int EwResourcesMemory;
extern int EwResourcesMemoryPeak;
extern int EwObjectsMemory;
extern int EwStringsMemory;
extern int EwMemoryPeak;

/* Helper function to track the maximum memory pressure */
static void TrackMemoryUsage( void )
{
  if ( EwResourcesMemory > EwResourcesMemoryPeak )
    EwResourcesMemoryPeak = EwResourcesMemory;

  if (( EwObjectsMemory + EwStringsMemory + EwResourcesMemory ) > EwMemoryPeak )
    EwMemoryPeak = EwObjectsMemory + EwStringsMemory + EwResourcesMemory;
}


/*******************************************************************************
* FUNCTION:
*   GfxInitGfx
*
* DESCRIPTION:
*   The function GfxInitGfx is called from the Graphics Engine during the
*   initialization in order to make target specific configurations of the
*   Graphics Engine
*
* ARGUMENTS:
*   aArgs - Optional argument passed to the Graphics Engine init function.
*
* RETURN VALUE:
*   If successful, returns != 0.
*
*******************************************************************************/
int GfxInitGfx( void* aArgs )
{
  EW_UNUSED_ARG( aArgs );

  /* In case of pure double-buffering mode, the Mosaic class library has to
     combine the dirty rectangles of two consecutive screen updates.
     To achieve this, the variable EwPreserveFramebufferContent has to be set to 0.
     Normally, the variable EwPreserveFramebufferContent is set to 1, which means
     that the graphics subsystem retains the content of the framebuffer between
     two consecutive screen update frames. */
  #if EW_USE_DOUBLE_BUFFER
    EwPreserveFramebufferContent = 0;
  #endif

  return 1;
}


/*******************************************************************************
* FUNCTION:
*   GfxInitViewport
*
* DESCRIPTION:
*   The function GfxInitViewport is called from the Graphics Engine,
*   to create a new viewport on the target. The function uses the given
*   buffers passed in the arguments aDisplay1 and aDisplay2.
*
* ARGUMENTS:
*   aWidth,
*   aHeight       - Size of the application in pixel.
*   aExtentX,
*   aExtentY      - not used.
*   aExtentWidth,
*   aExtentHeight - Size of the physical or virtual framebuffer in pixel.
*   aOrient       - not used.
*   aOpacity      - not used.
*   aDisplay1     - Address of the framebuffer / scratch-pad buffer.
*   aDisplay2     - Address of the back-buffer in case of double-buffering.
*   aDisplay3     - not used.
*
* RETURN VALUE:
*   Handle of the surface descriptor (viewport).
*
*******************************************************************************/
void* GfxInitViewport( int aWidth, int aHeight, int aExtentX,
  int aExtentY, int aExtentWidth, int aExtentHeight, int aOrient, int aOpacity,
  void* aDisplay1, void* aDisplay2, void* aDisplay3 )
{
  EW_UNUSED_ARG( aExtentX );
  EW_UNUSED_ARG( aExtentY );
  EW_UNUSED_ARG( aOrient );
  EW_UNUSED_ARG( aOpacity );
  EW_UNUSED_ARG( aDisplay3 );

  #if !EW_USE_SCRATCHPAD_BUFFER

    /* compare metrics of display with metrics of application */
    if (( aWidth > aExtentWidth ) || ( aHeight != aExtentHeight ))
    {
      EW_ERROR( Err02 );
      return 0;
    }

  #endif

  /* verify that the given framebuffer or scratch-pad buffer address is valid */
  if ( !aDisplay1 )
  {
    EW_ERROR( Err01 );
    return 0;
  }

  /* verify that the given back-buffer address matchs the choosen configuration */
  #if EW_USE_DOUBLE_BUFFER

    if ( !aDisplay2 )
    {
      EW_ERROR( Err04 );
      return 0;
    }

  #endif

  /* allocate memory for the descriptor structure */
  XGfxViewport* viewport = (XGfxViewport*)EwAlloc( sizeof( XGfxViewport ));
  if ( !viewport )
  {
    EW_ERROR( Err03 );
    return 0;
  }
  viewport->FrameBuffer      = 0;
  viewport->DoubleBuffer     = 0;

  /* allocate memory for the framebuffer descriptor */
  viewport->FrameBuffer = (XGfxSurface*)EwAlloc( sizeof( XGfxSurface ));
  if ( !viewport->FrameBuffer )
  {
    EW_ERROR( Err03 );
    return 0;
  }
  EwZero( viewport->FrameBuffer, sizeof( XGfxSurface ));

  /* initialize the framebuffer descriptor */
  viewport->FrameBuffer->Width          = aExtentWidth;
  viewport->FrameBuffer->Height         = aExtentHeight;
  viewport->FrameBuffer->Flags          = EW_SURFACE_FRAMEBUFFER;
  viewport->FrameBuffer->BytesPerPixel  = 2;
  viewport->FrameBuffer->Format         = EW_PIXEL_FORMAT_SCREEN;
  viewport->FrameBuffer->Pixel          = aDisplay1;
  viewport->FrameBuffer->OrigHeight     = aExtentHeight;
  viewport->FrameBuffer->OrigPixel      = aDisplay1;

  #if EW_USE_DOUBLE_BUFFER

    /* allocate memory for the double-buffer descriptor */
    viewport->DoubleBuffer = (XGfxSurface*)EwAlloc( sizeof( XGfxSurface ));
    if ( !viewport->DoubleBuffer )
    {
      EW_ERROR( Err03 );
      return 0;
    }
    EwZero( viewport->DoubleBuffer, sizeof( XGfxSurface ));

    /* initialize the double-buffer descriptor */
    viewport->DoubleBuffer->Width          = aExtentWidth;
    viewport->DoubleBuffer->Height         = aExtentHeight;
    viewport->DoubleBuffer->Flags          = EW_SURFACE_FRAMEBUFFER;
    viewport->DoubleBuffer->BytesPerPixel  = 2;
    viewport->DoubleBuffer->Format         = EW_PIXEL_FORMAT_SCREEN;
    viewport->DoubleBuffer->Pixel          = aDisplay2;
    viewport->DoubleBuffer->OrigHeight     = aExtentHeight;
    viewport->DoubleBuffer->OrigPixel      = aDisplay2;

  #endif

  /* adjust memory usage */
  EwResourcesMemory += sizeof( XGfxViewport );
  EwResourcesMemory += sizeof( XGfxSurface );

  #if EW_USE_DOUBLE_BUFFER
    EwResourcesMemory += sizeof( XGfxSurface );
  #endif

  /* track maximum memory pressure */
  TrackMemoryUsage();

  return viewport;
}


/*******************************************************************************
* FUNCTION:
*   GfxDoneViewport
*
* DESCRIPTION:
*   The function GfxDoneViewport is called from the Graphics Engine, to
*   release a previously created viewport on the target.
*
* ARGUMENTS:
*   aHandle - Handle of the surface descriptor (viewport).
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void GfxDoneViewport( void* aHandle )
{
  XGfxViewport* viewport = (XGfxViewport*)aHandle;

  /* destroy the double-buffer descriptor */
  if ( viewport->DoubleBuffer )
    EwFree( viewport->DoubleBuffer );

  /* destroy the framebuffer descriptor */
  if ( viewport->FrameBuffer )
    EwFree( viewport->FrameBuffer );

  /* destroy the viewport */
  EwFree( viewport );

  /* adjust memory usage */
  EwResourcesMemory -= sizeof( XGfxViewport );
  EwResourcesMemory -= sizeof( XGfxSurface );

  #if EW_USE_DOUBLE_BUFFER
    EwResourcesMemory -= sizeof( XGfxSurface );
  #endif
}


/*******************************************************************************
* FUNCTION:
*   GfxBeginUpdate
*
* DESCRIPTION:
*   The function GfxBeginUpdate is called from the Graphics Engine, to
*   initiate the screen update cycle.
*
* ARGUMENTS:
*   aHandle - Handle of the surface descriptor (viewport).
*
* RETURN VALUE:
*   Handle of the destination surface, used for all drawing operations.
*
*******************************************************************************/
void* GfxBeginUpdate( void* aHandle )
{
  /* log the operation */
  #if EW_PRINT_GFX_TASK_DETAILS
    EwPrint( "GfxBeginUpdate( 0x%p )\n", aHandle );
  #endif

  /* ensure that display controller is finished with previous buffer */
  EwBspDisplayWaitForCompletion();

  #if EW_USE_SCRATCHPAD_BUFFER

    EW_ERROR( Err06 );
    return 0;

  #elif EW_USE_DOUBLE_BUFFER

    XGfxViewport* viewport = (XGfxViewport*)aHandle;
    return viewport->DoubleBuffer;

  #else

    XGfxViewport* viewport = (XGfxViewport*)aHandle;
    return viewport->FrameBuffer;

  #endif
}


/*******************************************************************************
* FUNCTION:
*   GfxBeginUpdateArea
*
* DESCRIPTION:
*   The function GfxBeginUpdateArea is called from the Graphics Engine, to
*   initiate a partial screen update cycle.
*
* ARGUMENTS:
*   aHandle - Handle of the surface descriptor (viewport).
*   aX,
*   aY,
*   aWidth,
*   aHeight - Position and size of the area affected by the screen update
*     (dirty rectangle).
*
* RETURN VALUE:
*   Handle of the destination surface, used for all drawing operations.
*
*******************************************************************************/
void* GfxBeginUpdateArea( void* aHandle, int aX, int aY,
  int aWidth, int aHeight )
{
  /* log the operation */
  #if EW_PRINT_GFX_TASK_DETAILS
    EwPrint( "GfxBeginUpdateArea( 0x%p, ( %d, %d, %d, %d ))\n", aHandle,
      aX, aY, aWidth, aHeight );
  #endif

  /* ensure that display controller is finished with previous buffer */
  EwBspDisplayWaitForCompletion();

  #if EW_USE_SCRATCHPAD_BUFFER

    #if EW_USE_DOUBLE_BUFFER
    {
      XGfxViewport* viewport = (XGfxViewport*)aHandle;

      /* adapt size of double-scratch-pad buffer */
      viewport->DoubleBuffer->Width = aWidth;
      viewport->DoubleBuffer->Height = aHeight;

      /* return handle of double-scratch-pad buffer */
      return viewport->DoubleBuffer;
    }
    #else
    {
      XGfxViewport* viewport = (XGfxViewport*)aHandle;

      /* adapt size of scratch-pad buffer */
      viewport->FrameBuffer->Width = aWidth;
      viewport->FrameBuffer->Height = aHeight;

      /* return handle of scratch-pad buffer */
      return viewport->FrameBuffer;
    }
    #endif

  #else

    #if EW_USE_DOUBLE_BUFFER

      EW_ERROR( Err07 );
      return 0;

    #else

      XGfxViewport* viewport = (XGfxViewport*)aHandle;

      /* adapt size and start address of framebuffer */
      viewport->FrameBuffer->Height = aHeight;
      viewport->FrameBuffer->Pixel  = (unsigned char *)viewport->FrameBuffer->OrigPixel
        + (( aY * viewport->FrameBuffer->Width ) + aX ) * viewport->FrameBuffer->BytesPerPixel;

      return viewport->FrameBuffer;

    #endif

  #endif
}


/*******************************************************************************
* FUNCTION:
*   GfxEndUpdate
*
* DESCRIPTION:
*   The function GfxEndUpdate is called from the Graphics Engine, to
*   finalize the screen update cycle.
*
* ARGUMENTS:
*   aHandle - Handle of the surface descriptor (viewport).
*   aX,
*   aY,
*   aWidth,
*   aHeight - Position and size of the area affected from the screen update
*     (dirty rectangle).
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void GfxEndUpdate( void* aHandle, int aX, int aY, int aWidth, int aHeight )
{
  XGfxViewport* viewport = (XGfxViewport*)aHandle;

  /* log the operation */
  #if EW_PRINT_GFX_TASK_DETAILS
    EwPrint( "GfxEndUpdate( 0x%p, ( %d, %d, %d, %d ))\n", aHandle, aX, aY, aWidth, aHeight );
  #endif

  /* nothing to do */
  if (( aWidth <= 0 ) || ( aHeight <= 0 ))
    return;

  #if EW_USE_DOUBLE_BUFFER
  {
    /* exchange front- and back-buffer objects */
    XGfxSurface* tmp = viewport->DoubleBuffer;
    viewport->DoubleBuffer = viewport->FrameBuffer;
    viewport->FrameBuffer = tmp;
  }
  #endif

  /* restore framebuffer parameter (patched for synchronous single-buffer) */
  viewport->FrameBuffer->Height = viewport->FrameBuffer->OrigHeight;
  viewport->FrameBuffer->Pixel  = viewport->FrameBuffer->OrigPixel;

  /* inform display driver that buffer content is now updated */
  EwBspDisplayCommitBuffer( viewport->FrameBuffer->Pixel, aX, aY, aWidth, aHeight );
}


/*******************************************************************************
* FUNCTION:
*   GfxCreateSurface
*
* DESCRIPTION:
*   The function GfxCreateSurface() reserves pixel memory for a new surface
*   with the given size and color format. The function returns a handle to the
*   new surface.
*
* ARGUMENTS:
*   aFormat  - Color format of the surface. (See EW_PIXEL_FORMAT_XXX).
*   aWidth,
*   aHeight  - Size of the surface in pixel to create.
*
* RETURN VALUE:
*   The function returns a handle to the created surface. This can be a pointer
*   to a dynamically allocated data structure, an index in a list of surfaces,
*   or a handle returned by the lower level API.
*
*   If the creation is failed, the function should return 0.
*
*******************************************************************************/
void* GfxCreateSurface( int aFormat, int aWidth, int aHeight )
{
  XGfxSurface*            surface       = 0;
  int                     bytesPerPixel = 0;
  int                     bitmapSize    = 0;
  void*                   pixelBuffer   = 0;

  /* log the operation */
  #if EW_PRINT_GFX_TASK_DETAILS
    EwPrint( "GfxCreateSurface( %d, ( %d, %d ))\n", aFormat, aWidth, aHeight );
  #endif

  /* Remark: In case that pixel data is accessed by both CPU and GA, it has
     to be ensured that the pixel data will never be in the same CPU cache line
     than any other data => pixel memory has to be aligned. */

  /* determine expected size of one pixel */
  if ( aFormat == EW_PIXEL_FORMAT_NATIVE )
    bytesPerPixel = 4;
  else if ( aFormat == EW_PIXEL_FORMAT_SCREEN )
    bytesPerPixel = 2;
  else
    return 0;

  /* determine the size the entire bitmap */
  bitmapSize = aWidth * aHeight * bytesPerPixel + 2 * EW_CACHE_LINE_SIZE;

  /* try to allocate the memory for the surface structure and the pixel buffer */
  surface = (XGfxSurface*)EwAlloc( sizeof( XGfxSurface ));
  pixelBuffer = EwAllocVideo( bitmapSize );
  if ( !surface || !pixelBuffer )
  {
    if ( surface )
      EwFree( surface );
    if ( pixelBuffer )
      EwFreeVideo( pixelBuffer );
    return 0;
  }
  EwZero( surface, sizeof( XGfxSurface ));

  /* fill all members of the surface descriptor */
  surface->Width          = aWidth;
  surface->Height         = aHeight;
  surface->Flags          = 0;
  surface->BytesPerPixel  = bytesPerPixel;
  surface->Format         = aFormat;
  surface->AllocSize      = bitmapSize;
  surface->AllocAddress   = pixelBuffer;
  surface->Pixel          = EW_ALIGN_TO_CACHE( pixelBuffer );

  /* invalidate the cache for the complete address range of the pixel data
     to avoid that cache is written after modifications by graphics hardware */
  EW_INVALIDATE_CACHE( surface->Pixel, aWidth * aHeight * bytesPerPixel );

  /* log the operation */
  #if EW_PRINT_GFX_TASK_DETAILS
    EwPrint( "GfxCreateSurface() returned 0x%p\n", surface );
  #endif

  /* adjust memory usage */
  EwResourcesMemory += sizeof( XGfxSurface ) + surface->AllocSize;

  /* track maximum memory pressure */
  TrackMemoryUsage();

  return surface;
}


/*******************************************************************************
* FUNCTION:
*   GfxCreateConstSurface
*
* DESCRIPTION:
*   The function GfxCreateConstSurface() creates a surface structure
*   that refers to a constant pixel memory. The function returns a handle to the
*   new surface.
*
* ARGUMENTS:
*   aFormat - Color format of the surface. (See EW_PIXEL_FORMAT_XXX).
*   aWidth,
*   aHeight - Size of the surface in pixel.
*   aMemory - Pointer to constant pixel memory.
*
* RETURN VALUE:
*   The function returns a handle to the created surface.
*   If the creation is failed, the function should return 0.
*
*******************************************************************************/
void* GfxCreateConstSurface( int aFormat, int aWidth, int aHeight,
  XSurfaceMemory* aMemory )
{
  XGfxSurface*            surface       = 0;
  int                     bytesPerPixel = 0;

  /* log the operation */
  #if EW_PRINT_GFX_TASK_DETAILS
    EwPrint( "GfxCreateConstSurface( %d, ( %d, %d ), 0x%p )\n", aFormat,
      aWidth, aHeight, aMemory );
  #endif

  /* determine expected size of one pixel */
  if ( aFormat == EW_PIXEL_FORMAT_NATIVE )
    bytesPerPixel = 4;
  else
    return 0;

  /* verify superficially the passed pixel memory */
  if ( !aMemory || !aMemory->Pixel1 || ( aMemory->Pitch1X != bytesPerPixel ) ||
     ( aMemory->Pitch1Y < (int)( aWidth * bytesPerPixel )))
    return 0;

  /* allocate memory only for the administration structure */
  surface = (XGfxSurface*)EwAlloc( sizeof( XGfxSurface ));
  if ( !surface )
    return 0;
  EwZero( surface, sizeof( XGfxSurface ));

  /* fill all members of the surface descriptor */
  surface->Width          = aWidth;
  surface->Height         = aHeight;
  surface->Flags          = EW_SURFACE_PREALLOCATED;
  surface->BytesPerPixel  = bytesPerPixel;
  surface->Format         = aFormat;
  surface->Pixel          = (void*)( aMemory->Pixel1 );

  /* log the operation */
  #if EW_PRINT_GFX_TASK_DETAILS
    EwPrint( "GfxCreateConstSurface() returned 0x%p\n", surface );
  #endif

  /* adjust memory usage */
  EwResourcesMemory += sizeof( XGfxSurface );

  /* track maximum memory pressure */
  TrackMemoryUsage();

  return surface;
}


/*******************************************************************************
* FUNCTION:
*   GfxDestroySurface
*
* DESCRIPTION:
*   The function GfxDestroySurface() frees the resources of the given surface.
*   This function is a counterpart to GfxCreateSurface().
*
* ARGUMENTS:
*   aHandle - Handle to the surface to free.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void GfxDestroySurface( void* aHandle )
{
  XGfxSurface* surface = (XGfxSurface*)aHandle;

  /* log the operation */
  #if EW_PRINT_GFX_TASK_DETAILS
    EwPrint( "GfxDestroySurface( 0x%p )\n", aHandle );
  #endif

  /* adjust memory usage */
  EwResourcesMemory -= sizeof( XGfxSurface ) + surface->AllocSize;

  /* release the video memory of allocated surfaces */
  if ( !(surface->Flags & ( EW_SURFACE_PREALLOCATED | EW_SURFACE_FRAMEBUFFER )))
    EwFreeVideo( surface->AllocAddress );

  /* release the surface structure */
  EwFree( surface );
}


/*******************************************************************************
* FUNCTION:
*   GfxLockSurface
*
* DESCRIPTION:
*   The function GfxLockSurface() provides a direct access to the pixel memory of
*   the given surface. The function returns a lock object containing pointers to
*   memory, where the caller can read/write the surface pixel values. Additional
*   pitch values also returned in the object allow the caller to calculate the
*   desired pixel addresses.
*
* ARGUMENTS:
*   aHandle     - Handle to the surface to obtain the direct memory access.
*   aX, aY,
*   aWidth,
*   aHeight     - Area within the surface affected by the access operation.
*     (Relative to the top-left corner of the surface). This is the area, the
*     caller wish to read/write the pixel data.
*   aIndex,
*   Count       - Optional start index and number of entries within the CLUT,
*     the caller wish to read/write. These paramaters are used for surfaces
*     with the index8 color format only.
*   aReadPixel  - Is != 0, if the caller intends to read the pixel information
*     from the surface memory. If == 0, the memory content may remain undefined
*     depending on the underlying graphics sub-system and its video-memory
*     management.
*   aWritePixel - Is != 0, if the caller intends to modify the pixel information
*     within the surface memory. If == 0, any modifications within the memory
*     may remain ignored depending on the underlying graphics sub-system and its
*     video-memory management.
*   aReadClut   - Is != 0, if the caller intends to read the CLUT information.
*     If == 0, the CLUT content may remain undefined.
*   aWriteClut  - Is != 0, if the caller intends to modify the CLUT information.
*     If == 0, any modifications within the memory may remain ignored depending
*     on the underlying graphics sub-system and its video-memory management.
*   aMemory     - Pointer to an object, where the desired surface pointers
*     should be stored.
*
* RETURN VALUE:
*   If successful, the function should return a kind of a lock object. This
*   object can contain additional information needed when the surface is
*   unlocked again. If you don't want to return additional information, return
*   any value != 0.
*
*   If there was not possible to lock the surface, or the desired access mode
*   is just not supported by the underlying graphics sub-system, the function
*   fails and returns zero.
*
*******************************************************************************/
void* GfxLockSurface( void* aHandle, int aX, int aY,
  int aWidth, int aHeight, int aIndex, int aCount, int aReadPixel, int aWritePixel,
  int aReadClut, int aWriteClut, XSurfaceMemory* aMemory )
{
  XGfxSurface* surface = (XGfxSurface*)aHandle;

  EW_UNUSED_ARG( aWidth );
  EW_UNUSED_ARG( aHeight );
  EW_UNUSED_ARG( aIndex );
  EW_UNUSED_ARG( aCount );
  EW_UNUSED_ARG( aReadPixel );
  EW_UNUSED_ARG( aWritePixel );
  EW_UNUSED_ARG( aReadClut );
  EW_UNUSED_ARG( aWriteClut );

  /* log the operation */
  #if EW_PRINT_GFX_TASK_DETAILS
    EwPrint( "GfxLockSurface( 0x%p, ( %d, %d, %d, %d ), %d, %d, %d, %d, %d, %d )\n",
      aHandle, aX, aY, aWidth, aHeight, aIndex, aCount, aReadPixel, aWritePixel,
      aReadClut, aWriteClut );
  #endif

  EwZero( aMemory, sizeof( XSurfaceMemory ));

  /* return the details of the surface */
  aMemory->Pixel1  = (unsigned char*)surface->Pixel + (( aY * surface->Width ) + aX ) * surface->BytesPerPixel;
  aMemory->Pitch1Y = surface->Width * surface->BytesPerPixel;
  aMemory->Pitch1X = surface->BytesPerPixel;

  #ifdef EW_USE_READER_FOR_CONST_SURFACES

    /* if the constant surface is not accessible by the CPU, a reader has to be
       used in order to load and map the pixel pointers */
    if ( surface->Flags & EW_SURFACE_PREALLOCATED )
      aMemory->Reader = EwFlashAreaReaderProc;

  #endif

  return (void*)1;
}


/*******************************************************************************
* FUNCTION:
*   GfxUnlockSurface
*
* DESCRIPTION:
*   The function GfxUnlockSurface() has the job to unlock the given surface and
*   if necessary free any temporary used resources.
*   This function is a counterpart to GfxLockSurface().
*
* ARGUMENTS:
*   aSurfaceHandle - Handle to the surface to release the direct memory access.
*   aLockHandle    - value returned by the corresponding LockSurface() call.
*     If LockSurface() has allocated memory for the lock object, you will need
*     to free it now.
*   aX, aY,
*   aWidth,
*   aHeight     - Area within the surface affected by the access operation.
*     (Relative to the top-left corner of the surface). This is the area, the
*     caller wished to read/write the pixel data.
*   aIndex,
*   Count       - Optional start index and number of entries within the CLUT,
*     the caller wished to read/write. These paramaters are used for surfaces
*     with the index8 color format only.
*   aWritePixel - Is != 0, if the caller has modified the pixel information
*     within the surface memory. If == 0, no modification took place, so no
*     surface updates are needed.
*   aWriteClut  - Is != 0, if the caller has modified the CLUT information.
*     If == 0, no modification took place, so no surface updates are needed.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void GfxUnlockSurface( void* aSurfaceHandle, void* aLockHandle,
  int aX, int aY, int aWidth, int aHeight, int aIndex, int aCount, int aWritePixel,
  int aWriteClut )
{
  EW_UNUSED_ARG( aSurfaceHandle );
  EW_UNUSED_ARG( aLockHandle );
  EW_UNUSED_ARG( aX );
  EW_UNUSED_ARG( aY );
  EW_UNUSED_ARG( aWidth );
  EW_UNUSED_ARG( aHeight );
  EW_UNUSED_ARG( aIndex );
  EW_UNUSED_ARG( aCount );
  EW_UNUSED_ARG( aWritePixel );
  EW_UNUSED_ARG( aWriteClut );

  /* log the operation */
  #if EW_PRINT_GFX_TASK_DETAILS
    EwPrint( "GfxUnlockSurface( 0x%p, ( %d, %d, %d, %d ), %d, %d, %d, %d )\n",
      aSurfaceHandle, aX, aY, aWidth, aHeight, aIndex, aCount, aWritePixel, aWriteClut );
  #endif
}

/* msy */
