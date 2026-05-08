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

#ifndef _AcceleratorAccelerator_H
#define _AcceleratorAccelerator_H

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

#include "_AcceleratorGraphicsFactory.h"
#include "_CoreGroup.h"
#include "_CoreTimer.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "_WidgetSetPushButton.h"
#include "_WidgetSetToggleButton.h"

/* Forward declaration of the class Accelerator::Accelerator */
#ifndef _AcceleratorAccelerator_
  EW_DECLARE_CLASS( AcceleratorAccelerator )
#define _AcceleratorAccelerator_
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

/* Forward declaration of the class GraphicsSystem::DeviceClass */
#ifndef _GraphicsSystemDeviceClass_
  EW_DECLARE_CLASS( GraphicsSystemDeviceClass )
#define _GraphicsSystemDeviceClass_
#endif


/* This is the root component of the entire GUI application. */
EW_DEFINE_FIELDS( AcceleratorAccelerator, CoreGroup )
  EW_OBJECT  ( Rectangle,       ViewsRectangle )
  EW_OBJECT  ( GraphicsFactory, AcceleratorGraphicsFactory )
  EW_OBJECT  ( PerformanceTimer, CoreTimer )
  EW_OBJECT  ( FpsDescr,        ViewsText )
  EW_OBJECT  ( FpsText,         ViewsText )
  EW_OBJECT  ( CpuDescr,        ViewsText )
  EW_OBJECT  ( CpuText,         ViewsText )
  EW_OBJECT  ( ScenDescr,       ViewsText )
  EW_OBJECT  ( AccelDescr,      ViewsText )
  EW_OBJECT  ( ScenarioText,    ViewsText )
  EW_OBJECT  ( PushButton,      WidgetSetPushButton )
  EW_OBJECT  ( AutoDemoTimer,   CoreTimer )
  EW_OBJECT  ( ToggleButton,    WidgetSetToggleButton )
  EW_VARIABLE( GraphicsSystem,  GraphicsSystemDeviceClass )
  EW_PROPERTY( NoOfRectBlend,   XInt32 )
  EW_PROPERTY( NoOfRGB565Bmp,   XInt32 )
  EW_PROPERTY( NoOfNativeBmp,   XInt32 )
  EW_PROPERTY( NoOfRGB565BmpOpacity, XInt32 )
  EW_PROPERTY( NoOfNativeBmpOpacity, XInt32 )
  EW_PROPERTY( NoOfAlpha8Bmp,   XInt32 )
  EW_VARIABLE( currentScene,    XInt32 )
EW_END_OF_FIELDS( AcceleratorAccelerator )

/* Virtual Method Table (VMT) for the class : 'Accelerator::Accelerator' */
EW_DEFINE_METHODS( AcceleratorAccelerator, CoreGroup )
  EW_METHOD( initLayoutContext, void )( CoreRectView _this, XRect aBounds, CoreOutline 
    aOutline )
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
  EW_METHOD( UpdateLayout,      void )( AcceleratorAccelerator _this, XPoint aSize )
  EW_METHOD( UpdateViewState,   void )( CoreGroup _this, XSet aState )
  EW_METHOD( InvalidateArea,    void )( CoreGroup _this, XRect aArea )
EW_END_OF_METHODS( AcceleratorAccelerator )

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void AcceleratorAccelerator_Init( AcceleratorAccelerator _this, XHandle aArg );

/* The method UpdateLayout() is invoked automatically after the size of the component 
   has been changed. This method can be overridden and filled with logic to perform 
   a sophisticated arrangement calculation for one or more enclosed views. In this 
   case the parameter aSize can be used. It contains the current size of the component. 
   Usually, all enclosed views are arranged automatically accordingly to their @Layout 
   property. UpdateLayout() gives the derived components a chance to extend this 
   automatism by a user defined algorithm. */
void AcceleratorAccelerator_UpdateLayout( AcceleratorAccelerator _this, XPoint aSize );

/* 'C' function for method : 'Accelerator::Accelerator.PerformanceSlot()' */
void AcceleratorAccelerator_PerformanceSlot( AcceleratorAccelerator _this, XObject 
  sender );

/* 'C' function for method : 'Accelerator::Accelerator.NextScene()' */
void AcceleratorAccelerator_NextScene( AcceleratorAccelerator _this, XObject sender );

/* Method to select given test case. It the test case is not supported, the method 
   returns false - otherwise true. */
XBool AcceleratorAccelerator_ChangeScene( AcceleratorAccelerator _this, XInt32 aIndex );

#ifdef __cplusplus
  }
#endif

#endif /* _AcceleratorAccelerator_H */

/* Embedded Wizard */
