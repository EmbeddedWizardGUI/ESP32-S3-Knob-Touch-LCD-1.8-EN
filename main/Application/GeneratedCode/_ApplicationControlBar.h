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

#ifndef _ApplicationControlBar_H
#define _ApplicationControlBar_H

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
#include "_CoreSimpleTouchHandler.h"
#include "_EffectsFloatEffect.h"
#include "_ViewsImage.h"

/* Forward declaration of the class Application::ControlBar */
#ifndef _ApplicationControlBar_
  EW_DECLARE_CLASS( ApplicationControlBar )
#define _ApplicationControlBar_
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

/* Forward declaration of the class Resources::Bitmap */
#ifndef _ResourcesBitmap_
  EW_DECLARE_CLASS( ResourcesBitmap )
#define _ResourcesBitmap_
#endif


/* Control bar component - circles, arrow button, press animations */
EW_DEFINE_FIELDS( ApplicationControlBar, CoreGroup )
  EW_OBJECT  ( CircleOuter,     ViewsImage )
  EW_OBJECT  ( Selected,        ViewsImage )
  EW_OBJECT  ( IconSlot0,       ViewsImage )
  EW_OBJECT  ( IconSlot1,       ViewsImage )
  EW_OBJECT  ( IconSlot2,       ViewsImage )
  EW_OBJECT  ( IconSlot3,       ViewsImage )
  EW_OBJECT  ( IconSlot4,       ViewsImage )
  EW_OBJECT  ( CircleInner,     ViewsImage )
  EW_OBJECT  ( ArrowButton,     ViewsImage )
  EW_OBJECT  ( OuterGroup,      CoreGroup )
  EW_OBJECT  ( InnerGroup,      CoreGroup )
  EW_OBJECT  ( RotateHandler,   CoreRotateTouchHandler )
  EW_OBJECT  ( ArrowTouchHandler, CoreSimpleTouchHandler )
  EW_OBJECT  ( IconMoveEffect,  EffectsFloatEffect )
  EW_ARRAY   ( IconBitmaps,     ResourcesBitmap, [6])
  EW_ARRAY   ( IconSlots,       ViewsImage, [5])
  EW_PROPERTY( ArrowBitmap,     ResourcesBitmap )
  EW_PROPERTY( OnAction,        XSlot )
  EW_PROPERTY( OnTouch,         XSlot )
  EW_PROPERTY( OnSelectionChanged, XSlot )
  EW_VARIABLE( IconMoveTargetAngle, XFloat )
  EW_PROPERTY( CurrentAngle,    XFloat )
  EW_VARIABLE( StartAngle,      XFloat )
  EW_VARIABLE( SelectedIndex,   XInt32 )
  EW_PROPERTY( Locked,          XBool )
EW_END_OF_FIELDS( ApplicationControlBar )

/* Virtual Method Table (VMT) for the class : 'Application::ControlBar' */
EW_DEFINE_METHODS( ApplicationControlBar, CoreGroup )
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
EW_END_OF_METHODS( ApplicationControlBar )

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ApplicationControlBar_Init( ApplicationControlBar _this, XHandle aArg );

/* 'C' function for method : 'Application::ControlBar.OnSetArrowBitmap()' */
void ApplicationControlBar_OnSetArrowBitmap( ApplicationControlBar _this, ResourcesBitmap 
  value );

/* Touch press on the arrow area - dim to pressed gray */
void ApplicationControlBar_OnArrowPress( ApplicationControlBar _this, XObject sender );

/* Touch released on the arrow area - restore to white and notify parent */
void ApplicationControlBar_OnArrowRelease( ApplicationControlBar _this, XObject 
  sender );

/* Set button color on arrow, inner circle and selection highlight */
void ApplicationControlBar_AnimateButton( ApplicationControlBar _this, XColor aTarget );

/* Recalculate icon positions and opacity for the circular carousel. Uses 5 virtualized 
   image slots to display the 6 mode icons on a semicircular arc. Icons near the 
   top (90 degrees) are fully opaque; icons toward the edges fade out proportionally. */
void ApplicationControlBar_UpdateIconPositions( ApplicationControlBar _this, XFloat 
  aAngle );

/* Wrap an arbitrary angle into the 0..360 range using modular arithmetic */
XFloat ApplicationControlBar_NormalizeAngle( ApplicationControlBar _this, XFloat 
  aAngle );

/* Called each rendered frame - interpolates the angle and repositions icons */
void ApplicationControlBar_OnIconAnimate( ApplicationControlBar _this, XObject sender );

/* Animation finished - store final angle and notify parent of new selection */
void ApplicationControlBar_OnIconMoveDone( ApplicationControlBar _this, XObject 
  sender );

/* Animate icons from the current angle to the target angle */
void ApplicationControlBar_StartIconEffects( ApplicationControlBar _this, XFloat 
  aTargetAngle );

/* Update visuals whenever the carousel angle changes. Repositions all icons on 
   the arc and computes which mode is nearest to the top center. If the nearest 
   mode changed, fires OnSelectionChanged to the parent. */
void ApplicationControlBar_OnSetCurrentAngle( ApplicationControlBar _this, XFloat 
  value );

/* Touch started - notifies parent, then snaps any running animation to its target 
   and saves the current angle as baseline for threshold detection */
void ApplicationControlBar_OnTouchStart( ApplicationControlBar _this, XObject sender );

/* Rotation gesture in progress - icons follow the finger directly */
void ApplicationControlBar_HandleRotation( ApplicationControlBar _this, XObject 
  sender );

/* Touch released - snap to the nearest detent and notify parent of selection */
void ApplicationControlBar_OnRelease( ApplicationControlBar _this, XObject sender );

/* Rotate the carousel by exactly one mode slot (60 degrees). aDirection: +1 = clockwise, 
   -1 = counter-clockwise. Called by parent for encoder clicks and keyboard arrow 
   presses. Ignores the call if the carousel is locked or already animating. */
void ApplicationControlBar_RotateStep( ApplicationControlBar _this, XInt32 aDirection );

#ifdef __cplusplus
  }
#endif

#endif /* _ApplicationControlBar_H */

/* Embedded Wizard */
