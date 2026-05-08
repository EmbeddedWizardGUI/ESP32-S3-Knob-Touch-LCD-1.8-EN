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

#ifndef _ResourcesExternVideo_H
#define _ResourcesExternVideo_H

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

#include "_CoreTimer.h"
#include "_ResourcesBitmap.h"

/* Forward declaration of the class Resources::ExternVideo */
#ifndef _ResourcesExternVideo_
  EW_DECLARE_CLASS( ResourcesExternVideo )
#define _ResourcesExternVideo_
#endif


/* The class Resources::ExternVideo provides the functionality to represent bitmaps 
   loaded at the runtime by an extern video decoder. Bitmaps loaded in this manner 
   can be used as regular bitmap resources -> they can be shown in all adequate 
   views like Views::Image, Views::Wallpaper, Views::Frame, Views::WarpImage and 
   Views::AttrText.
   To identify the video content, the property @Name is available. It can be used, 
   for example, to specify the path to a video file. The playback speed and the 
   position can be determined and queried by using the properties @Speed and @CurrentVideoFrame. 
   The property @NoOfVideoFrames, in turn, is useful to query the length of the 
   video content. To query the frame rate (the number of frames per second) the 
   method @GetFrameRate is available.
   To control the playback use the property @Paused or the slot methods @Pause and 
   @Resume. The properties @OnChangeState and @OnNewVideoFrame are suitable to react 
   to corresponding events.
   Please note, this class depends on a video decoder implementation which of course 
   is specific for each target and pixel format. It is thus up to you to provide 
   this loader implementation for your particular target system. You will need to 
   implement a set of 'C' functions and link them with the generated GUI application 
   code. Following list provides an overview of the 'C' functions this class depends 
   on:
   - XHandle EwExternVideoCreate( XString aName ) --> creates a new instance of 
   the extern video decoder to load and process the video specified in the parameter 
   aName. The decoding is paused per default.
   - void EwExternVideoDestroy( XHandle aInstance ) --> stops the extern video decoder 
   identified by aInstance and releases all associated resources.
   - void EwExternVideoPause( XHandle aInstance ) --> Pauses the extern video decoder 
   identified by aInstance. See also the property @Paused and the slot method @Pause.
   - void EwExternVideoResume( XHandle aInstance ) --> Resumes the extern video 
   decoder identified by aInstance. See also the property @Paused and the slot method 
   @Resume.
   - void EwExternVideoSetSpeed( XHandle aInstance, int aSpeed ) --> Changes the 
   video decoding speed for the extern video decoder identified by aInstance. The 
   parameter aSpeed is expressed in percent. See also the property @Speed.
   - void EwExternVideoSetCurrentFrame( XHandle aInstance, int aCurrentFrame ) --> 
   Changes the video decoding position for the extern video decoder identified by 
   aInstance. The parameter aCurrentFrame addresses the new position as frame number. 
   The first frame has the number 0, the secind 1, and so far. See also the property 
   @CurrentVideoFrame.
   - int  EwExternVideoGetCurrentFrame( XHandle aInstance ) --> Returns the current 
   video decoding position for the extern video decoder identified by aInstance 
   as frame number. The first frame has the number 0, the second 1, and so far. 
   See also the property @CurrentVideoFrame.
   - int  EwExternVideoGetNoOfFrames( XHandle aInstance ) --> Returns the number 
   of frames belonging to the video content for the extern video decoder identified 
   by aInstance. See also the property @NoOfVideoFrames.
   - float EwExternVideoGetFrameRate( XHandle aInstance ) --> Returns the number 
   of frames per second, the currently played video content is providing. See also 
   the method @GetFrameRate().
   - int  EwExternVideoGetState( XHandle aInstance ) --> Returns the state for the 
   extern video decoder identified by aInstance. See also the method @GetState().
   - int  EwExternVideoGetError( XHandle aInstance ) --> Returns a common error 
   for the extern video decoder identified by aInstance. See also the method @GetError().
   - unsigned int EwExternVideoGetErrorCode( XHandle aInstance ) --> Returns a decoder 
   specific error code for the extern video decoder identified by aInstance. See 
   also the method @GetErrorCode().
   - XBitmap* EwExternVideoGetNewBitmap( XHandle aInstance ) --> Verifies whether 
   the extern video decoder identified by aInstance has decoded a new video frame. 
   If this is the case the function returns Embedded Wizard bitmap envolving the 
   content of this frame. If there is no new frame content available, the function 
   returns NULL. */
EW_DEFINE_FIELDS( ResourcesExternVideo, ResourcesBitmap )
  EW_OBJECT  ( updateTimer,     CoreTimer )
  EW_PROPERTY( OnChangeState,   XSlot )
  EW_VARIABLE( name,            XString )
  EW_PROPERTY( Name,            XString )
  EW_VARIABLE( state,           XEnum )
  EW_VARIABLE( instance,        XHandle )
  EW_PROPERTY( NoOfVideoFrames, XInt32 )
  EW_PROPERTY( CurrentVideoFrame, XInt32 )
  EW_PROPERTY( Speed,           XInt32 )
  EW_PROPERTY( Paused,          XBool )
EW_END_OF_FIELDS( ResourcesExternVideo )

/* Virtual Method Table (VMT) for the class : 'Resources::ExternVideo' */
EW_DEFINE_METHODS( ResourcesExternVideo, ResourcesBitmap )
  EW_METHOD( OnSetFrameSize,    void )( ResourcesBitmap _this, XPoint value )
  EW_METHOD( Update,            void )( ResourcesBitmap _this )
EW_END_OF_METHODS( ResourcesExternVideo )

/* 'C' function for method : 'Resources::ExternVideo.Done()' */
void ResourcesExternVideo_Done( ResourcesExternVideo _this );

/* 'C' function for method : 'Resources::ExternVideo.Init()' */
void ResourcesExternVideo_Init( ResourcesExternVideo _this, XHandle aArg );

/* 'C' function for method : 'Resources::ExternVideo.onUpdate()' */
void ResourcesExternVideo_onUpdate( ResourcesExternVideo _this, XObject sender );

/* 'C' function for method : 'Resources::ExternVideo.load()' */
void ResourcesExternVideo_load( ResourcesExternVideo _this, XObject sender );

/* 'C' function for method : 'Resources::ExternVideo.OnGetNoOfVideoFrames()' */
XInt32 ResourcesExternVideo_OnGetNoOfVideoFrames( ResourcesExternVideo _this );

/* 'C' function for method : 'Resources::ExternVideo.OnSetNoOfVideoFrames()' */
void ResourcesExternVideo_OnSetNoOfVideoFrames( ResourcesExternVideo _this, XInt32 
  value );

/* 'C' function for method : 'Resources::ExternVideo.OnGetCurrentVideoFrame()' */
XInt32 ResourcesExternVideo_OnGetCurrentVideoFrame( ResourcesExternVideo _this );

/* 'C' function for method : 'Resources::ExternVideo.OnSetCurrentVideoFrame()' */
void ResourcesExternVideo_OnSetCurrentVideoFrame( ResourcesExternVideo _this, XInt32 
  value );

/* 'C' function for method : 'Resources::ExternVideo.OnSetSpeed()' */
void ResourcesExternVideo_OnSetSpeed( ResourcesExternVideo _this, XInt32 value );

/* 'C' function for method : 'Resources::ExternVideo.OnSetPaused()' */
void ResourcesExternVideo_OnSetPaused( ResourcesExternVideo _this, XBool value );

/* 'C' function for method : 'Resources::ExternVideo.OnSetName()' */
void ResourcesExternVideo_OnSetName( ResourcesExternVideo _this, XString value );

/* The method GetState() returns the latest known state of the video decoder. For 
   more details see the enumeration Resources::ExternVideoState. */
XEnum ResourcesExternVideo_GetState( ResourcesExternVideo _this );

#ifdef __cplusplus
  }
#endif

#endif /* _ResourcesExternVideo_H */

/* Embedded Wizard */
