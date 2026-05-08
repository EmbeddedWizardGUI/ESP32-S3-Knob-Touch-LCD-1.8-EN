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

#ifndef _ApplicationApplication_H
#define _ApplicationApplication_H

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

#include "_CoreKeyPressHandler.h"
#include "_CorePropertyObserver.h"
#include "_CoreRoot.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_EffectsInt32Effect.h"
#include "_ResourcesExternVideo.h"
#include "_ViewsImage.h"

/* Forward declaration of the class Application::Application */
#ifndef _ApplicationApplication_
  EW_DECLARE_CLASS( ApplicationApplication )
#define _ApplicationApplication_
#endif

/* Forward declaration of the class Application::ControlBar */
#ifndef _ApplicationControlBar_
  EW_DECLARE_CLASS( ApplicationControlBar )
#define _ApplicationControlBar_
#endif

/* Forward declaration of the class Application::DeviceClass */
#ifndef _ApplicationDeviceClass_
  EW_DECLARE_CLASS( ApplicationDeviceClass )
#define _ApplicationDeviceClass_
#endif

/* Forward declaration of the class Application::DoneMessage */
#ifndef _ApplicationDoneMessage_
  EW_DECLARE_CLASS( ApplicationDoneMessage )
#define _ApplicationDoneMessage_
#endif

/* Forward declaration of the class Application::ProgressIndicator */
#ifndef _ApplicationProgressIndicator_
  EW_DECLARE_CLASS( ApplicationProgressIndicator )
#define _ApplicationProgressIndicator_
#endif

/* Forward declaration of the class Application::TimerConfigure */
#ifndef _ApplicationTimerConfigure_
  EW_DECLARE_CLASS( ApplicationTimerConfigure )
#define _ApplicationTimerConfigure_
#endif

/* Forward declaration of the class Core::Group */
#ifndef _CoreGroup_
  EW_DECLARE_CLASS( CoreGroup )
#define _CoreGroup_
#endif

/* Forward declaration of the class Core::LayoutContext */
#ifndef _CoreLayoutContext_
  EW_DECLARE_CLASS( CoreLayoutContext )
#define _CoreLayoutContext_
#endif

/* Forward declaration of the class Core::View */
#ifndef _CoreView_
  EW_DECLARE_CLASS( CoreView )
#define _CoreView_
#endif

/* Forward declaration of the class Graphics::Canvas */
#ifndef _GraphicsCanvas_
  EW_DECLARE_CLASS( GraphicsCanvas )
#define _GraphicsCanvas_
#endif

/* Forward declaration of the class Resources::Bitmap */
#ifndef _ResourcesBitmap_
  EW_DECLARE_CLASS( ResourcesBitmap )
#define _ResourcesBitmap_
#endif


/* Root component of the Standmixer GUI application. For more information, please 
   visit: https://doc.embedded-wizard.de/ */
EW_DEFINE_FIELDS( ApplicationApplication, CoreRoot )
  EW_OBJECT  ( Background,      ViewsImage )
  EW_OBJECT  ( BackgroundNext,  ViewsImage )
  EW_OBJECT  ( BgFadeEffect,    EffectsInt32Effect )
  EW_OBJECT  ( VideoView,       ViewsImage )
  EW_OBJECT  ( EncoderObserver, CorePropertyObserver )
  EW_OBJECT  ( HardButtonHandler, CoreSystemEventHandler )
  EW_OBJECT  ( HardButtonTimer, CoreTimer )
  EW_OBJECT  ( KeyEnterHandler, CoreKeyPressHandler )
  EW_OBJECT  ( KeyLeftHandler,  CoreKeyPressHandler )
  EW_OBJECT  ( KeyRightHandler, CoreKeyPressHandler )
  EW_OBJECT  ( KeyHoldGateTimer, CoreTimer )
  EW_OBJECT  ( VideoSource,     ResourcesExternVideo )
  EW_ARRAY   ( Backgrounds,     ResourcesBitmap, [6])
  EW_ARRAY   ( DarkBackgrounds, ResourcesBitmap, [6])
  EW_VARIABLE( TimerCfg,        ApplicationTimerConfigure )
  EW_VARIABLE( DoneMsg,         ApplicationDoneMessage )
  EW_VARIABLE( CtrlBar,         ApplicationControlBar )
  EW_VARIABLE( ProgressInd,     ApplicationProgressIndicator )
  EW_VARIABLE( DeviceRef,       ApplicationDeviceClass )
  EW_ARRAY   ( VideoSources,    XString, [6])
  EW_VARIABLE( PreviousAdcValue, XInt32 )
  EW_VARIABLE( TimerState,      XEnum )
EW_END_OF_FIELDS( ApplicationApplication )

/* Virtual Method Table (VMT) for the class : 'Application::Application' */
EW_DEFINE_METHODS( ApplicationApplication, CoreRoot )
  EW_METHOD( GetRoot,           CoreRoot )( CoreRoot _this )
  EW_METHOD( Draw,              void )( CoreRoot _this, GraphicsCanvas aCanvas, 
    XRect aClip, XPoint aOffset, XInt32 aOpacity, XBool aBlend )
  EW_METHOD( GetClipping,       XRect )( CoreGroup _this )
  EW_METHOD( HandleEvent,       XObject )( CoreView _this, CoreEvent aEvent )
  EW_METHOD( CursorHitTest,     CoreCursorHit )( CoreGroup _this, XRect aArea, XInt32 
    aFinger, XInt32 aStrikeCount, CoreView aDedicatedView, CoreView aStartView, 
    XSet aRetargetReason )
  EW_METHOD( AdjustDrawingArea, XRect )( CoreGroup _this, XRect aArea )
  EW_METHOD( ArrangeView,       XPoint )( CoreRectView _this, XRect aBounds, XEnum 
    aFormation )
  EW_METHOD( MoveView,          void )( CoreRectView _this, XPoint aOffset, XBool 
    aFastMove )
  EW_METHOD( GetExtent,         XRect )( CoreRectView _this )
  EW_METHOD( ChangeViewState,   void )( CoreRoot _this, XSet aSetState, XSet aClearState )
  EW_METHOD( OnSetBounds,       void )( CoreGroup _this, XRect value )
  EW_METHOD( OnSetFocus,        void )( CoreRoot _this, CoreView value )
  EW_METHOD( DispatchEvent,     XObject )( CoreRoot _this, CoreEvent aEvent )
  EW_METHOD( BroadcastEvent,    XObject )( CoreRoot _this, CoreEvent aEvent, XSet 
    aFilter )
  EW_METHOD( InvalidateArea,    void )( CoreRoot _this, XRect aArea )
EW_END_OF_METHODS( ApplicationApplication )

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ApplicationApplication_Init( ApplicationApplication _this, XHandle aArg );

/* Fade complete - copy new bitmap to Background and hide the overlay */
void ApplicationApplication_OnBgFadeDone( ApplicationApplication _this, XObject 
  sender );

/* Central state machine handler: Idle -> Setting -> Running -> Idle */
void ApplicationApplication_HandleArrowAction( ApplicationApplication _this );

/* Encoder rotation handler - adjusts timer in SETTING state, rotates carousel in 
   IDLE */
void ApplicationApplication_onEncoderChange( ApplicationApplication _this, XObject 
  sender );

/* Hardware button pressed - show press animation and start 200ms auto-release timer */
void ApplicationApplication_onHardButtonEvent( ApplicationApplication _this, XObject 
  sender );

/* Auto-release timer fired - play release animation and execute arrow action */
void ApplicationApplication_OnHardButtonTimerDone( ApplicationApplication _this, 
  XObject sender );

/* Keyboard Enter key - simulates hardware button press using same auto-release 
   timer */
void ApplicationApplication_onKeyEnter( ApplicationApplication _this, XObject sender );

/* Keyboard Left arrow - decreases timer in SETTING, rotates carousel otherwise */
void ApplicationApplication_onKeyLeft( ApplicationApplication _this, XObject sender );

/* Keyboard Right arrow - increases timer in SETTING, rotates carousel otherwise */
void ApplicationApplication_onKeyRight( ApplicationApplication _this, XObject sender );

/* Key held down - repeat 1s step with gate timer */
void ApplicationApplication_onKeyLeftHold( ApplicationApplication _this, XObject 
  sender );

/* Key held down - repeat 1s step with gate timer */
void ApplicationApplication_onKeyRightHold( ApplicationApplication _this, XObject 
  sender );

/* Control bar arrow button released - delegate to the state machine */
void ApplicationApplication_OnControlBarAction( ApplicationApplication _this, XObject 
  sender );

/* Countdown reached zero - tear down RUNNING state and show done screen */
void ApplicationApplication_OnCountdownComplete( ApplicationApplication _this, XObject 
  sender );

/* Progress tick - syncs MM:SS display with remaining time once per second */
void ApplicationApplication_OnProgressTick( ApplicationApplication _this, XObject 
  sender );

/* Done message expired or dismissed - tear down done screen and restore IDLE state */
void ApplicationApplication_OnDoneExpired( ApplicationApplication _this, XObject 
  sender );

/* Carousel selection changed - cross-fade background to the newly selected mode */
void ApplicationApplication_OnSelectionChanged( ApplicationApplication _this, XObject 
  sender );

/* Carousel touched - immediately dismiss done screen if showing */
void ApplicationApplication_OnCarouselTouch( ApplicationApplication _this, XObject 
  sender );

/* Start video playback for the currently selected mode */
void ApplicationApplication_StartVideo( ApplicationApplication _this );

/* Stop video playback and free decoder memory */
void ApplicationApplication_StopVideo( ApplicationApplication _this );

/* Handle video state changes - rewind to frame 0 on end-of-stream for looping */
void ApplicationApplication_OnVideoStateChanged( ApplicationApplication _this, XObject 
  sender );

#ifdef __cplusplus
  }
#endif

#endif /* _ApplicationApplication_H */

/* Embedded Wizard */
