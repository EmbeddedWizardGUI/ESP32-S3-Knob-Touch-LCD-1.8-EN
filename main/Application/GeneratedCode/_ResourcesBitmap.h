/*******************************************************************************
*
* Embedded Wizard - GUI Solutions by TARA Systems
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This file was generated automatically by Embedded Wizard tools based on the
* GUI project configuration and resources provided by you.
*
* Please do not modify this file! Any changes will be lost when it is generated
* again by the Embedded Wizard code generation process.
*
* The template of this heading text can be found in the file 'head.ewt' in the
* directory 'Platforms' of your Embedded Wizard installation directory. If you
* wish to adapt this text, please copy 'head.ewt' into your project directory
* and edit only that copy. Please avoid any modifications of the original
* template file.
*
* License, ownership and responsibility:
*
*   - The generated code is based on your project configuration and forms part
*     of your application. The application-specific content of this file
*     (including project-specific classes, resources and UI logic) is owned by
*     you or your licensors. You remain responsible for the overall design,
*     implementation, testing and validation of your application, including any
*     project-specific code and any changes or additions you make to the
*     generated code. TARA Systems GmbH is not responsible for defects or
*     malfunctions caused by such project-specific content or modifications.
*
*   - The use of Embedded Wizard Studio, the Embedded Wizard command line code
*     generator (ChoraC), the Embedded Wizard technology used to generate this
*     file and any Embedded Wizard Platform Packages and Runtime Components
*     required to build and run the generated code is subject to the Embedded
*     Wizard license terms (as published at https://www.embedded-wizard.de/legal),
*     including in particular:
*
*       - Embedded Wizard Terms and Conditions (EWTC)
*       - Embedded Wizard License Agreement (EWLA)
*       - Embedded Wizard Community License (EWCL)
*
*     The specific agreement(s) applicable to you and the applicable warranties
*     and limitations of liability are exclusively governed by these license
*     terms.
*
* Version  : 15.03
* Profile  : ESP32
* Platform : Espressif.ESP32.RGB565
*
*******************************************************************************/

#ifndef _ResourcesBitmap_H
#define _ResourcesBitmap_H

#ifdef __cplusplus
  extern "C"
  {
#endif

#include "ewrte.h"
#if ( EW_RTE_VERSION >> 16 ) != 15
  #error Wrong version of Embedded Wizard Runtime Environment.
#endif

#include "ewgfx.h"
#if ( EW_GFX_VERSION >> 16 ) != 15
  #error Wrong version of Embedded Wizard Graphics Engine.
#endif

#include "_CoreResource.h"

/* Forward declaration of the class Resources::Bitmap */
#ifndef _ResourcesBitmap_
  EW_DECLARE_CLASS( ResourcesBitmap )
#define _ResourcesBitmap_
#endif


/* The class Resources::Bitmap provides the base functionality to handle bitmaps. 
   A bitmap consists of at least one frame (an image). If there are more than one 
   frame stored within the bitmap, the bitmap is called 'multi-frame'. Such multi-frame 
   bitmaps are very useful e.g. to run short video sequences.
   This class implements a set of properties to query or change bitmap attributes. 
   For example, the property @FrameSize stores the size of a single bitmap frame 
   in pixel. The property @NoOfFrames determines how many frames are available in 
   the bitmap.
   Usually, bitmaps are created at the design time by drag-and-drop them from the 
   Embedded Wizard Gallery into the Composer window where you are editing your GUI 
   project. The bitmap attributes will be determined in the Embedded Wizard Inspector. */
EW_DEFINE_FIELDS( ResourcesBitmap, CoreResource )
  EW_VARIABLE( bitmap,          XHandle )
  EW_PROPERTY( FrameDelay,      XInt32 )
  EW_PROPERTY( NoOfFrames,      XInt32 )
  EW_PROPERTY( FrameSize,       XPoint )
  EW_VARIABLE( Animated,        XBool )
  EW_VARIABLE( Mutable,         XBool )
EW_END_OF_FIELDS( ResourcesBitmap )

/* Virtual Method Table (VMT) for the class : 'Resources::Bitmap' */
EW_DEFINE_METHODS( ResourcesBitmap, CoreResource )
  EW_METHOD( OnSetFrameSize,    void )( ResourcesBitmap _this, XPoint value )
  EW_METHOD( Update,            void )( ResourcesBitmap _this )
EW_END_OF_METHODS( ResourcesBitmap )

/* 'C' function for method : 'Resources::Bitmap.Done()' */
void ResourcesBitmap_Done( ResourcesBitmap _this );

/* 'C' function for method : 'Resources::Bitmap.Init()' */
void ResourcesBitmap_Init( ResourcesBitmap _this, XHandle aArg );

/* 'C' function for method : 'Resources::Bitmap.OnSetFrameSize()' */
void ResourcesBitmap_OnSetFrameSize( ResourcesBitmap _this, XPoint value );

/* Wrapper function for the virtual method : 'Resources::Bitmap.OnSetFrameSize()' */
void ResourcesBitmap__OnSetFrameSize( void* _this, XPoint value );

/* 'C' function for method : 'Resources::Bitmap.SetBitmap()' */
ResourcesBitmap ResourcesBitmap_SetBitmap( ResourcesBitmap _this, XHandle aBitmap );

/* Wrapper function for the non virtual method : 'Resources::Bitmap.SetBitmap()' */
ResourcesBitmap ResourcesBitmap__SetBitmap( void* _this, XHandle aBitmap );

/* The following define announces the presence of the method Resources::Bitmap.SetBitmap(). */
#define _ResourcesBitmap__SetBitmap_

/* 'C' function for method : 'Resources::Bitmap.Update()' */
void ResourcesBitmap_Update( ResourcesBitmap _this );

/* Wrapper function for the virtual method : 'Resources::Bitmap.Update()' */
void ResourcesBitmap__Update( void* _this );

#ifdef __cplusplus
  }
#endif

#endif /* _ResourcesBitmap_H */

/* Embedded Wizard */
