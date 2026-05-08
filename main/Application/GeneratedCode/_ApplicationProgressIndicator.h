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

#ifndef _ApplicationProgressIndicator_H
#define _ApplicationProgressIndicator_H

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

#include "_CoreGroup.h"
#include "_CoreRotateTouchHandler.h"
#include "_CoreTimer.h"
#include "_EffectsInt32Effect.h"
#include "_GraphicsArcPath.h"
#include "_ViewsStrokePath.h"

/* Forward declaration of the class Application::ProgressIndicator */
#ifndef _ApplicationProgressIndicator_
  EW_DECLARE_CLASS( ApplicationProgressIndicator )
#define _ApplicationProgressIndicator_
#endif

/* Forward declaration of the class Core::KeyPressHandler */
#ifndef _CoreKeyPressHandler_
  EW_DECLARE_CLASS( CoreKeyPressHandler )
#define _CoreKeyPressHandler_
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


/* Countdown progress arc indicator - shows animated arc during timer countdown */
EW_DEFINE_FIELDS( ApplicationProgressIndicator, CoreGroup )
  EW_OBJECT  ( TimerArcPath,    GraphicsArcPath )
  EW_OBJECT  ( TimerArcStroke,  ViewsStrokePath )
  EW_OBJECT  ( CountdownTimer,  CoreTimer )
  EW_OBJECT  ( ArcEffect,       EffectsInt32Effect )
  EW_OBJECT  ( ArcTouchHandler, CoreRotateTouchHandler )
  EW_PROPERTY( OnCountdownDone, XSlot )
  EW_PROPERTY( OnTick,          XSlot )
  EW_PROPERTY( TotalSeconds,    XInt32 )
  EW_PROPERTY( RemainingSeconds, XInt32 )
  EW_VARIABLE( TouchStartSeconds, XInt32 )
EW_END_OF_FIELDS( ApplicationProgressIndicator )

/* Virtual Method Table (VMT) for the class : 'Application::ProgressIndicator' */
EW_DEFINE_METHODS( ApplicationProgressIndicator, CoreGroup )
  EW_METHOD( GetRoot,           CoreRoot )( CoreView _this )
  EW_METHOD( Draw,              void )( CoreGroup _this, GraphicsCanvas aCanvas, 
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
  EW_METHOD( ChangeViewState,   void )( CoreGroup _this, XSet aSetState, XSet aClearState )
  EW_METHOD( OnSetBounds,       void )( CoreGroup _this, XRect value )
  EW_METHOD( OnSetFocus,        void )( CoreGroup _this, CoreView value )
  EW_METHOD( DispatchEvent,     XObject )( CoreGroup _this, CoreEvent aEvent )
  EW_METHOD( BroadcastEvent,    XObject )( CoreGroup _this, CoreEvent aEvent, XSet 
    aFilter )
  EW_METHOD( InvalidateArea,    void )( CoreGroup _this, XRect aArea )
EW_END_OF_METHODS( ApplicationProgressIndicator )

/* Set static arc fill proportional to aSeconds / MaxSeconds (no countdown)
   Uses preview angles that avoid the visible button bar. */
void ApplicationProgressIndicator_SetPreview( ApplicationProgressIndicator _this, 
  XInt32 aSeconds );

/* Start the countdown. */
void ApplicationProgressIndicator_StartCountdown( ApplicationProgressIndicator _this, 
  XInt32 aSeconds );

/* Add or remove seconds during a running countdown. Restarts the arc effect
   from the current visual position so the sweep continues smoothly. */
void ApplicationProgressIndicator_AdjustTime( ApplicationProgressIndicator _this, 
  XInt32 aDelta );

/* Called every animation frame to smoothly shrink the arc. The arc spans 280 degrees 
   Maps the remaining milliseconds to an arc EndAngle using current ArcStart/ArcSpan. */
void ApplicationProgressIndicator_OnArcAnimate( ApplicationProgressIndicator _this, 
  XObject sender );

/* Fires once per second. Decrements the remaining time, notifies the parent (to 
   update the MM:SS display), and when zero is reached stops everything and fires 
   OnCountdownDone. */
void ApplicationProgressIndicator_OnCountdownTick( ApplicationProgressIndicator _this, 
  XObject sender );

/* Touch started - save current seconds as baseline */
void ApplicationProgressIndicator_OnArcTouchStart( ApplicationProgressIndicator _this, 
  XObject sender );

/* Dragging on the arc - map rotation to seconds */
void ApplicationProgressIndicator_OnArcRotate( ApplicationProgressIndicator _this, 
  XObject sender );

#ifdef __cplusplus
  }
#endif

#endif /* _ApplicationProgressIndicator_H */

/* Embedded Wizard */
