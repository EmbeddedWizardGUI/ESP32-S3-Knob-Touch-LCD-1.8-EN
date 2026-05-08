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

#include "ewlocale.h"
#include "_ApplicationApplication.h"
#include "_ApplicationControlBar.h"
#include "_ApplicationDeviceClass.h"
#include "_ApplicationDoneMessage.h"
#include "_ApplicationProgressIndicator.h"
#include "_ApplicationTimerConfigure.h"
#include "_CoreGroup.h"
#include "_CoreKeyPressHandler.h"
#include "_CorePropertyObserver.h"
#include "_CoreRotateTouchHandler.h"
#include "_CoreSimpleTouchHandler.h"
#include "_CoreSystemEvent.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_EffectsFloatEffect.h"
#include "_EffectsInt32Effect.h"
#include "_GraphicsArcPath.h"
#include "_GraphicsPath.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesExternVideo.h"
#include "_ResourcesFont.h"
#include "_ViewsImage.h"
#include "_ViewsStrokePath.h"
#include "_ViewsText.h"
#include "Application.h"
#include "Core.h"
#include "Effects.h"
#include "Graphics.h"
#include "Resources.h"
#include "Views.h"

/* Strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned short _StringsDefault0[] =
{
  0xFFFF, 0xFFFF, 0xC557, 0x0066, 0x006C, 0x0061, 0x0073, 0x0068, 0x003A, 0x002F,
  0x002F, 0x0063, 0x0068, 0x006F, 0x0070, 0x002E, 0x0061, 0x0076, 0x0069, 0x0000,
  0xC557, 0x0066, 0x006C, 0x0061, 0x0073, 0x0068, 0x003A, 0x002F, 0x002F, 0x0063,
  0x0072, 0x0075, 0x0073, 0x0068, 0x002E, 0x0061, 0x0076, 0x0069, 0x0000, 0xC557,
  0x0066, 0x006C, 0x0061, 0x0073, 0x0068, 0x003A, 0x002F, 0x002F, 0x0077, 0x0068,
  0x0069, 0x0070, 0x002E, 0x0061, 0x0076, 0x0069, 0x0000, 0xC557, 0x0066, 0x006C,
  0x0061, 0x0073, 0x0068, 0x003A, 0x002F, 0x002F, 0x0073, 0x0068, 0x0061, 0x006B,
  0x0065, 0x002E, 0x0061, 0x0076, 0x0069, 0x0000, 0xC557, 0x0066, 0x006C, 0x0061,
  0x0073, 0x0068, 0x003A, 0x002F, 0x002F, 0x0073, 0x0074, 0x0069, 0x0072, 0x002E,
  0x0061, 0x0076, 0x0069, 0x0000, 0xC557, 0x0066, 0x006C, 0x0061, 0x0073, 0x0068,
  0x003A, 0x002F, 0x002F, 0x0073, 0x0074, 0x0072, 0x0061, 0x0069, 0x006E, 0x002E,
  0x0061, 0x0076, 0x0069, 0x0000, 0xC557, 0x0030, 0x0030, 0x003A, 0x0030, 0x0030,
  0x0000, 0xC557, 0x003A, 0x0000, 0xC557, 0x0052, 0x0065, 0x0061, 0x0064, 0x0079,
  0x0000, 0xC557, 0x0045, 0x006E, 0x006A, 0x006F, 0x0079, 0x0020, 0x0079, 0x006F,
  0x0075, 0x0072, 0x000A, 0x0073, 0x0068, 0x0061, 0x006B, 0x0065, 0x0021, 0x0000,
  0xC557, 0x0045, 0x006E, 0x006A, 0x006F, 0x0079, 0x0020, 0x0079, 0x006F, 0x0075,
  0x0072, 0x000A, 0x006D, 0x0065, 0x0061, 0x006C, 0x0021, 0x0000, 0xC557, 0x0045,
  0x006E, 0x006A, 0x006F, 0x0079, 0x0020, 0x0079, 0x006F, 0x0075, 0x0072, 0x000A,
  0x0063, 0x0072, 0x0075, 0x0073, 0x0068, 0x0021, 0x0000, 0xC557, 0x0045, 0x006E,
  0x006A, 0x006F, 0x0079, 0x0020, 0x0079, 0x006F, 0x0075, 0x0072, 0x000A, 0x0066,
  0x0072, 0x006F, 0x0074, 0x0068, 0x0021, 0x0000, 0xC557, 0x0045, 0x006E, 0x006A,
  0x006F, 0x0079, 0x0020, 0x0079, 0x006F, 0x0075, 0x0072, 0x000A, 0x006D, 0x0069,
  0x0078, 0x0021, 0x0000, 0xC557, 0x0045, 0x006E, 0x006A, 0x006F, 0x0079, 0x0020,
  0x0079, 0x006F, 0x0075, 0x0072, 0x000A, 0x006A, 0x0075, 0x0069, 0x0063, 0x0065,
  0x0021, 0x0000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 360, 360 }};
static const XColor _Const0001 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XStringRes _Const0002 = { _StringsDefault0, 0x0003 };
static const XStringRes _Const0003 = { _StringsDefault0, 0x0015 };
static const XStringRes _Const0004 = { _StringsDefault0, 0x0028 };
static const XStringRes _Const0005 = { _StringsDefault0, 0x003A };
static const XStringRes _Const0006 = { _StringsDefault0, 0x004D };
static const XStringRes _Const0007 = { _StringsDefault0, 0x005F };
static const XColor _Const0008 = { 0xC0, 0xC0, 0xC0, 0xFF };
static const XRect _Const0009 = {{ 0, 174 }, { 360, 394 }};
static const XRect _Const000A = {{ 33, 35 }, { 327, 182 }};
static const XColor _Const000B = { 0xD2, 0xD2, 0xD2, 0x5D };
static const XRect _Const000C = {{ 137, 36 }, { 221, 106 }};
static const XColor _Const000D = { 0xFF, 0xFF, 0xFF, 0xA2 };
static const XRect _Const000E = {{ 146, 92 }, { 214, 160 }};
static const XRect _Const000F = {{ 95, 102 }, { 266, 188 }};
static const XColor _Const0010 = { 0xFF, 0xFF, 0xFF, 0xBB };
static const XRect _Const0011 = {{ 155, 121 }, { 205, 166 }};
static const XColor _Const0012 = { 0xFF, 0xFF, 0xF3, 0xFF };
static const XRect _Const0013 = {{ 0, 0 }, { 360, 220 }};
static const XRect _Const0014 = {{ 0, 6 }, { 360, 186 }};
static const XPoint _Const0015 = { 0, 180 };
static const XPoint _Const0016 = { 85, 182 };
static const XPoint _Const0017 = { 281, 182 };
static const XPoint _Const0018 = { 223, 103 };
static const XPoint _Const0019 = { 132, 103 };
static const XRect _Const001A = {{ 0, 0 }, { 360, 320 }};
static const XPoint _Const001B = { 180, 180 };
static const XPoint _Const001C = { 0, 0 };
static const XRect _Const001D = {{ 0, 91 }, { 360, 181 }};
static const XRect _Const001E = {{ -1, 0 }, { 359, 90 }};
static const XStringRes _Const001F = { _StringsDefault0, 0x0073 };
static const XStringRes _Const0020 = { _StringsDefault0, 0x007A };
static const XRect _Const0021 = {{ 0, 86 }, { 360, 270 }};
static const XRect _Const0022 = {{ 0, 0 }, { 360, 61 }};
static const XStringRes _Const0023 = { _StringsDefault0, 0x007D };
static const XRect _Const0024 = {{ 0, 74 }, { 360, 184 }};
static const XStringRes _Const0025 = { _StringsDefault0, 0x0084 };
static const XPoint _Const0026 = { 0, 184 };
static const XPoint _Const0027 = { 360, 184 };
static const XPoint _Const0028 = { 360, 0 };
static const XStringRes _Const0029 = { _StringsDefault0, 0x0097 };
static const XStringRes _Const002A = { _StringsDefault0, 0x00A9 };
static const XStringRes _Const002B = { _StringsDefault0, 0x00BC };
static const XStringRes _Const002C = { _StringsDefault0, 0x00CF };
static const XStringRes _Const002D = { _StringsDefault0, 0x00E0 };

#ifndef EW_DONT_CHECK_INDEX
  /* This function is used to check the indices when accessing an array.
     If you don't want this verification add the define EW_DONT_CHECK_INDEX
     to your Makefile or project settings. */
  static int EwCheckIndex( int aIndex, int aRange, const char* aFile, int aLine )
  {
    if (( aIndex < 0 ) || ( aIndex >= aRange ))
    {
      EwPrint( "[FATAL ERROR in %s:%d] Array index %d out of bounds %d",
                aFile, aLine, aIndex, aRange );
      EwPanic();
      return 0;
    }
    return aIndex;
  }

  #define EwCheckIndex( aIndex, aRange ) \
    EwCheckIndex( aIndex, aRange, __FILE__, __LINE__ )
#else
  #define EwCheckIndex( aIndex, aRange ) aIndex
#endif

/* Include the device driver header file to access the device class */
#include "DeviceDriver.h"

/* Initializer for the class 'Application::Application' */
void ApplicationApplication__Init( ApplicationApplication _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreRoot__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationApplication );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->Background, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->BackgroundNext, &_this->_.XObject, 0 );
  EffectsInt32Effect__Init( &_this->BgFadeEffect, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->VideoView, &_this->_.XObject, 0 );
  CorePropertyObserver__Init( &_this->EncoderObserver, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->HardButtonHandler, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->HardButtonTimer, &_this->_.XObject, 0 );
  CoreKeyPressHandler__Init( &_this->KeyEnterHandler, &_this->_.XObject, 0 );
  CoreKeyPressHandler__Init( &_this->KeyLeftHandler, &_this->_.XObject, 0 );
  CoreKeyPressHandler__Init( &_this->KeyRightHandler, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->KeyHoldGateTimer, &_this->_.XObject, 0 );
  ResourcesExternVideo__Init( &_this->VideoSource, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationApplication );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Background, _Const0000 );
  CoreRectView__OnSetBounds( &_this->BackgroundNext, _Const0000 );
  ViewsImage_OnSetVisible( &_this->BackgroundNext, 0 );
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->BgFadeEffect, EffectsTimingFastIn_EaseOut );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->BgFadeEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->BgFadeEffect, 300 );
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->BgFadeEffect, 0 );
  CoreRectView__OnSetBounds( &_this->VideoView, _Const0000 );
  ViewsImage_OnSetColor( &_this->VideoView, _Const0001 );
  ViewsImage_OnSetAlignment( &_this->VideoView, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter | ViewsImageAlignmentScaleToFit );
  ViewsImage_OnSetAlphaBlended( &_this->VideoView, 0 );
  ViewsImage_OnSetVisible( &_this->VideoView, 0 );
  CoreTimer_OnSetPeriod( &_this->HardButtonTimer, 0 );
  CoreTimer_OnSetBegin( &_this->HardButtonTimer, 200 );
  CoreTimer_OnSetEnabled( &_this->HardButtonTimer, 0 );
  _this->KeyEnterHandler.Filter = CoreKeyCodeEnter;
  _this->KeyLeftHandler.Filter = CoreKeyCodeLeft;
  _this->KeyRightHandler.Filter = CoreKeyCodeRight;
  CoreTimer_OnSetPeriod( &_this->KeyHoldGateTimer, 0 );
  CoreTimer_OnSetBegin( &_this->KeyHoldGateTimer, 200 );
  CoreTimer_OnSetEnabled( &_this->KeyHoldGateTimer, 0 );
  _this->TimerState = ApplicationTimerStateEnumIdle;
  ResourcesExternVideo_OnSetSpeed( &_this->VideoSource, 100 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Background ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->BackgroundNext ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->VideoView ), 0 );
  ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &ApplicationBackgroundChop, 
  ResourcesBitmap ));
  _this->BgFadeEffect.Super1.OnFinished = EwNewSlot( _this, ApplicationApplication_OnBgFadeDone );
  _this->BgFadeEffect.Outlet = EwNewRef( &_this->BackgroundNext, ViewsImage_OnGetOpacity, 
  ViewsImage_OnSetOpacity );
  ViewsImage_OnSetBitmap( &_this->VideoView, ((ResourcesBitmap)&_this->VideoSource ));
  _this->Backgrounds[ 0 ] = EwLoadResource( &ApplicationBackgroundChop, ResourcesBitmap );
  _this->Backgrounds[ 1 ] = EwLoadResource( &ApplicationBackgroundCrush, ResourcesBitmap );
  _this->Backgrounds[ 2 ] = EwLoadResource( &ApplicationBackgroundWhip, ResourcesBitmap );
  _this->Backgrounds[ 3 ] = EwLoadResource( &ApplicationBackgroundShake, ResourcesBitmap );
  _this->Backgrounds[ 4 ] = EwLoadResource( &ApplicationBackgroundStir, ResourcesBitmap );
  _this->Backgrounds[ 5 ] = EwLoadResource( &ApplicationBackgroundStrain, ResourcesBitmap );
  _this->DarkBackgrounds[ 0 ] = EwLoadResource( &ApplicationBackgroundChopDark, 
  ResourcesBitmap );
  _this->DarkBackgrounds[ 1 ] = EwLoadResource( &ApplicationBackgroundCrushDark, 
  ResourcesBitmap );
  _this->DarkBackgrounds[ 2 ] = EwLoadResource( &ApplicationBackgroundWhipDark, 
  ResourcesBitmap );
  _this->DarkBackgrounds[ 3 ] = EwLoadResource( &ApplicationBackgroundShakeDark, 
  ResourcesBitmap );
  _this->DarkBackgrounds[ 4 ] = EwLoadResource( &ApplicationBackgroundStirDark, 
  ResourcesBitmap );
  _this->DarkBackgrounds[ 5 ] = EwLoadResource( &ApplicationBackgroundStrainDark, 
  ResourcesBitmap );
  _this->DeviceRef = EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass );
  _this->EncoderObserver.OnEvent = EwNewSlot( _this, ApplicationApplication_onEncoderChange );
  CorePropertyObserver_OnSetOutlet( &_this->EncoderObserver, EwNewRef( EwGetAutoObject( 
  &ApplicationDevice, ApplicationDeviceClass ), ApplicationDeviceClass_OnGetAdcValue, 
  ApplicationDeviceClass_OnSetAdcValue ));
  _this->HardButtonHandler.OnEvent = EwNewSlot( _this, ApplicationApplication_onHardButtonEvent );
  CoreSystemEventHandler_OnSetEvent( &_this->HardButtonHandler, &EwGetAutoObject( 
  &ApplicationDevice, ApplicationDeviceClass )->HardButtonEvent );
  _this->HardButtonTimer.OnTrigger = EwNewSlot( _this, ApplicationApplication_OnHardButtonTimerDone );
  _this->KeyEnterHandler.OnPress = EwNewSlot( _this, ApplicationApplication_onKeyEnter );
  _this->KeyLeftHandler.OnPress = EwNewSlot( _this, ApplicationApplication_onKeyLeft );
  _this->KeyLeftHandler.OnHold = EwNewSlot( _this, ApplicationApplication_onKeyLeftHold );
  _this->KeyRightHandler.OnPress = EwNewSlot( _this, ApplicationApplication_onKeyRight );
  _this->KeyRightHandler.OnHold = EwNewSlot( _this, ApplicationApplication_onKeyRightHold );
  _this->VideoSource.OnChangeState = EwNewSlot( _this, ApplicationApplication_OnVideoStateChanged );

  /* Call the user defined constructor */
  ApplicationApplication_Init( _this, aArg );
}

/* Re-Initializer for the class 'Application::Application' */
void ApplicationApplication__ReInit( ApplicationApplication _this )
{
  /* At first re-initialize the super class ... */
  CoreRoot__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->Background );
  ViewsImage__ReInit( &_this->BackgroundNext );
  EffectsInt32Effect__ReInit( &_this->BgFadeEffect );
  ViewsImage__ReInit( &_this->VideoView );
  CorePropertyObserver__ReInit( &_this->EncoderObserver );
  CoreSystemEventHandler__ReInit( &_this->HardButtonHandler );
  CoreTimer__ReInit( &_this->HardButtonTimer );
  CoreKeyPressHandler__ReInit( &_this->KeyEnterHandler );
  CoreKeyPressHandler__ReInit( &_this->KeyLeftHandler );
  CoreKeyPressHandler__ReInit( &_this->KeyRightHandler );
  CoreTimer__ReInit( &_this->KeyHoldGateTimer );
  ResourcesExternVideo__ReInit( &_this->VideoSource );
}

/* Finalizer method for the class 'Application::Application' */
void ApplicationApplication__Done( ApplicationApplication _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreRoot );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->Background );
  ViewsImage__Done( &_this->BackgroundNext );
  EffectsInt32Effect__Done( &_this->BgFadeEffect );
  ViewsImage__Done( &_this->VideoView );
  CorePropertyObserver__Done( &_this->EncoderObserver );
  CoreSystemEventHandler__Done( &_this->HardButtonHandler );
  CoreTimer__Done( &_this->HardButtonTimer );
  CoreKeyPressHandler__Done( &_this->KeyEnterHandler );
  CoreKeyPressHandler__Done( &_this->KeyLeftHandler );
  CoreKeyPressHandler__Done( &_this->KeyRightHandler );
  CoreTimer__Done( &_this->KeyHoldGateTimer );
  ResourcesExternVideo__Done( &_this->VideoSource );

  /* Don't forget to deinitialize the super class ... */
  CoreRoot__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ApplicationApplication_Init( ApplicationApplication _this, XHandle aArg )
{
  XString videoPath;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  _this->VideoSources[ 0 ] = EwShareString( EwLoadString( &_Const0002 ));
  _this->VideoSources[ 1 ] = EwShareString( EwLoadString( &_Const0003 ));
  _this->VideoSources[ 2 ] = EwShareString( EwLoadString( &_Const0004 ));
  _this->VideoSources[ 3 ] = EwShareString( EwLoadString( &_Const0005 ));
  _this->VideoSources[ 4 ] = EwShareString( EwLoadString( &_Const0006 ));
  _this->VideoSources[ 5 ] = EwShareString( EwLoadString( &_Const0007 ));
  ViewsImage_OnSetBitmap( &_this->Background, _this->Backgrounds[ 0 ]);
  _this->PreviousAdcValue = 0;
  _this->CtrlBar = EwNewObject( ApplicationControlBar, 0 );
  _this->CtrlBar->OnAction = EwNewSlot( _this, ApplicationApplication_OnControlBarAction );
  _this->CtrlBar->OnSelectionChanged = EwNewSlot( _this, ApplicationApplication_OnSelectionChanged );
  _this->CtrlBar->OnTouch = EwNewSlot( _this, ApplicationApplication_OnCarouselTouch );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)_this->CtrlBar ), 0 );
  videoPath = _this->VideoSources[ 0 ];
  ResourcesExternVideo_OnSetName( &_this->VideoSource, videoPath );
  ResourcesExternVideo_OnSetPaused( &_this->VideoSource, 1 );
}

/* Fade complete - copy new bitmap to Background and hide the overlay */
void ApplicationApplication_OnBgFadeDone( ApplicationApplication _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsImage_OnSetBitmap( &_this->Background, _this->BackgroundNext.Bitmap );
  ViewsImage_OnSetVisible( &_this->BackgroundNext, 0 );
}

/* Central state machine handler: Idle -> Setting -> Running -> Idle */
void ApplicationApplication_HandleArrowAction( ApplicationApplication _this )
{
  if ( _this->TimerState == ApplicationTimerStateEnumIdle )
  {
    _this->TimerState = ApplicationTimerStateEnumSetting;
    _this->CtrlBar->Locked = 1;
    CoreRotateTouchHandler_OnSetEnabled( &_this->CtrlBar->RotateHandler, 0 );
    ApplicationControlBar_OnSetArrowBitmap( _this->CtrlBar, EwLoadResource( &ApplicationIconPlayPause, 
    ResourcesBitmap ));
    ViewsImage_OnSetFrameNumber( &_this->CtrlBar->ArrowButton, 0 );
    CoreGroup_OnSetVisible( &_this->CtrlBar->OuterGroup, 0 );
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->BgFadeEffect, 0 );
    ViewsImage_OnSetVisible( &_this->BackgroundNext, 0 );
    ViewsImage_OnSetBitmap( &_this->Background, _this->DarkBackgrounds[ EwCheckIndex( 
    _this->CtrlBar->SelectedIndex, 6 )]);
    _this->ProgressInd = EwNewObject( ApplicationProgressIndicator, 0 );
    _this->ProgressInd->OnCountdownDone = EwNewSlot( _this, ApplicationApplication_OnCountdownComplete );
    _this->ProgressInd->OnTick = EwNewSlot( _this, ApplicationApplication_OnProgressTick );
    CoreGroup_Add((CoreGroup)_this, ((CoreView)_this->ProgressInd ), 0 );
    _this->TimerCfg = EwNewObject( ApplicationTimerConfigure, 0 );
    ApplicationTimerConfigure_OnSetTimerSeconds( _this->TimerCfg, 5 );
    CoreGroup_Add((CoreGroup)_this, ((CoreView)_this->TimerCfg ), 0 );
    ApplicationProgressIndicator_SetPreview( _this->ProgressInd, 5 );
    CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->CtrlBar ));
    CoreGroup_Add((CoreGroup)_this, ((CoreView)_this->CtrlBar ), 0 );
  }
  else
    if ( _this->TimerState == ApplicationTimerStateEnumSetting )
    {
      if ( _this->TimerCfg->TimerSeconds > 0 )
      {
        _this->TimerState = ApplicationTimerStateEnumRunning;
        ViewsImage_OnSetFrameNumber( &_this->CtrlBar->ArrowButton, 1 );
        CoreGroup_OnSetVisible( &_this->CtrlBar->OuterGroup, 0 );
        ViewsImage_OnSetVisible( &_this->CtrlBar->Selected, 0 );
        ViewsImage_OnSetVisible( &_this->CtrlBar->IconSlot2, 0 );
        ApplicationApplication_StartVideo( _this );
        ApplicationProgressIndicator_StartCountdown( _this->ProgressInd, _this->TimerCfg->TimerSeconds );
      }
      else
      {
        _this->TimerState = ApplicationTimerStateEnumIdle;
        _this->CtrlBar->Locked = 0;
        CoreRotateTouchHandler_OnSetEnabled( &_this->CtrlBar->RotateHandler, 1 );
        ApplicationControlBar_OnSetArrowBitmap( _this->CtrlBar, EwLoadResource( 
        &ApplicationIconArrow, ResourcesBitmap ));
        ViewsImage_OnSetFrameNumber( &_this->CtrlBar->ArrowButton, 0 );
        CoreGroup_OnSetVisible( &_this->CtrlBar->OuterGroup, 1 );
        EffectsEffect_OnSetEnabled((EffectsEffect)&_this->BgFadeEffect, 0 );
        ViewsImage_OnSetVisible( &_this->BackgroundNext, 0 );
        ViewsImage_OnSetBitmap( &_this->Background, _this->Backgrounds[ EwCheckIndex( 
        _this->CtrlBar->SelectedIndex, 6 )]);

        if ( _this->ProgressInd != 0 )
        {
          CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->ProgressInd ));
          _this->ProgressInd = 0;
        }

        if ( _this->TimerCfg != 0 )
        {
          CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->TimerCfg ));
          _this->TimerCfg = 0;
        }
      }
    }
    else
      if ( _this->TimerState == ApplicationTimerStateEnumRunning )
      {
        ApplicationApplication_StopVideo( _this );
        _this->TimerState = ApplicationTimerStateEnumIdle;
        _this->CtrlBar->Locked = 0;
        CoreRotateTouchHandler_OnSetEnabled( &_this->CtrlBar->RotateHandler, 1 );
        ApplicationControlBar_OnSetArrowBitmap( _this->CtrlBar, EwLoadResource( 
        &ApplicationIconArrow, ResourcesBitmap ));
        ViewsImage_OnSetFrameNumber( &_this->CtrlBar->ArrowButton, 0 );
        EffectsEffect_OnSetEnabled((EffectsEffect)&_this->BgFadeEffect, 0 );
        ViewsImage_OnSetVisible( &_this->BackgroundNext, 0 );
        ViewsImage_OnSetBitmap( &_this->Background, _this->Backgrounds[ EwCheckIndex( 
        _this->CtrlBar->SelectedIndex, 6 )]);
        CoreGroup_OnSetVisible( &_this->CtrlBar->OuterGroup, 1 );
        ViewsImage_OnSetVisible( &_this->CtrlBar->Selected, 1 );
        ViewsImage_OnSetVisible( &_this->CtrlBar->IconSlot2, 1 );

        if ( _this->ProgressInd != 0 )
        {
          CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->ProgressInd ));
          _this->ProgressInd = 0;
        }

        if ( _this->TimerCfg != 0 )
        {
          CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->TimerCfg ));
          _this->TimerCfg = 0;
        }
      }
}

/* Encoder rotation handler - adjusts timer in SETTING state, rotates carousel in 
   IDLE */
void ApplicationApplication_onEncoderChange( ApplicationApplication _this, XObject 
  sender )
{
  XInt32 currentAdc;
  XInt32 delta;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  currentAdc = EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->AdcValue;
  delta = currentAdc - _this->PreviousAdcValue;
  _this->PreviousAdcValue = currentAdc;

  if ( _this->TimerState == ApplicationTimerStateEnumSetting )
  {
    if ( delta > 0 )
      ApplicationTimerConfigure_OnSetTimerSeconds( _this->TimerCfg, _this->TimerCfg->TimerSeconds 
      + 1 );
    else
      if ( delta < 0 )
        ApplicationTimerConfigure_OnSetTimerSeconds( _this->TimerCfg, _this->TimerCfg->TimerSeconds 
        - 1 );

    if ( _this->TimerCfg->TimerSeconds < 0 )
      ApplicationTimerConfigure_OnSetTimerSeconds( _this->TimerCfg, 0 );

    if ( _this->TimerCfg->TimerSeconds > 60 )
      ApplicationTimerConfigure_OnSetTimerSeconds( _this->TimerCfg, 60 );

    ApplicationProgressIndicator_SetPreview( _this->ProgressInd, _this->TimerCfg->TimerSeconds );
    return;
  }

  if ( _this->TimerState == ApplicationTimerStateEnumRunning )
  {
    if ( delta > 0 )
      ApplicationProgressIndicator_AdjustTime( _this->ProgressInd, 1 );
    else
      if ( delta < 0 )
        ApplicationProgressIndicator_AdjustTime( _this->ProgressInd, -1 );

    return;
  }

  if ( delta > 0 )
    ApplicationControlBar_RotateStep( _this->CtrlBar, -1 );
  else
    if ( delta < 0 )
      ApplicationControlBar_RotateStep( _this->CtrlBar, 1 );
}

/* Hardware button pressed - show press animation and start 200ms auto-release timer */
void ApplicationApplication_onHardButtonEvent( ApplicationApplication _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ApplicationControlBar_AnimateButton( _this->CtrlBar, _Const0008 );
  CoreTimer_OnSetEnabled( &_this->HardButtonTimer, 0 );
  CoreTimer_OnSetEnabled( &_this->HardButtonTimer, 1 );
}

/* Auto-release timer fired - play release animation and execute arrow action */
void ApplicationApplication_OnHardButtonTimerDone( ApplicationApplication _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->HardButtonTimer, 0 );
  ApplicationControlBar_AnimateButton( _this->CtrlBar, _Const0001 );
  ApplicationApplication_HandleArrowAction( _this );
}

/* Keyboard Enter key - simulates hardware button press using same auto-release 
   timer */
void ApplicationApplication_onKeyEnter( ApplicationApplication _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ApplicationControlBar_AnimateButton( _this->CtrlBar, _Const0008 );
  CoreTimer_OnSetEnabled( &_this->HardButtonTimer, 0 );
  CoreTimer_OnSetEnabled( &_this->HardButtonTimer, 1 );
}

/* Keyboard Left arrow - decreases timer in SETTING, rotates carousel otherwise */
void ApplicationApplication_onKeyLeft( ApplicationApplication _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->TimerState == ApplicationTimerStateEnumSetting )
  {
    ApplicationTimerConfigure_OnSetTimerSeconds( _this->TimerCfg, _this->TimerCfg->TimerSeconds 
    - 1 );

    if ( _this->TimerCfg->TimerSeconds < 0 )
      ApplicationTimerConfigure_OnSetTimerSeconds( _this->TimerCfg, 0 );

    ApplicationProgressIndicator_SetPreview( _this->ProgressInd, _this->TimerCfg->TimerSeconds );
    return;
  }

  if ( _this->TimerState == ApplicationTimerStateEnumRunning )
  {
    ApplicationProgressIndicator_AdjustTime( _this->ProgressInd, -1 );
    return;
  }

  ApplicationControlBar_RotateStep( _this->CtrlBar, -1 );
}

/* Keyboard Right arrow - increases timer in SETTING, rotates carousel otherwise */
void ApplicationApplication_onKeyRight( ApplicationApplication _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->TimerState == ApplicationTimerStateEnumSetting )
  {
    ApplicationTimerConfigure_OnSetTimerSeconds( _this->TimerCfg, _this->TimerCfg->TimerSeconds 
    + 1 );

    if ( _this->TimerCfg->TimerSeconds > 60 )
      ApplicationTimerConfigure_OnSetTimerSeconds( _this->TimerCfg, 60 );

    ApplicationProgressIndicator_SetPreview( _this->ProgressInd, _this->TimerCfg->TimerSeconds );
    return;
  }

  if ( _this->TimerState == ApplicationTimerStateEnumRunning )
  {
    ApplicationProgressIndicator_AdjustTime( _this->ProgressInd, 1 );
    return;
  }

  ApplicationControlBar_RotateStep( _this->CtrlBar, 1 );
}

/* Key held down - repeat 1s step with gate timer */
void ApplicationApplication_onKeyLeftHold( ApplicationApplication _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->TimerState == ApplicationTimerStateEnumRunning )
  {
    ApplicationProgressIndicator_AdjustTime( _this->ProgressInd, -1 );
    return;
  }

  if ( _this->TimerState != ApplicationTimerStateEnumSetting )
  {
    ApplicationControlBar_RotateStep( _this->CtrlBar, -1 );
    return;
  }

  if ( _this->KeyHoldGateTimer.Enabled )
    return;

  CoreTimer_OnSetEnabled( &_this->KeyHoldGateTimer, 1 );
  ApplicationTimerConfigure_OnSetTimerSeconds( _this->TimerCfg, _this->TimerCfg->TimerSeconds 
  - 1 );

  if ( _this->TimerCfg->TimerSeconds < 0 )
    ApplicationTimerConfigure_OnSetTimerSeconds( _this->TimerCfg, 0 );

  ApplicationProgressIndicator_SetPreview( _this->ProgressInd, _this->TimerCfg->TimerSeconds );
}

/* Key held down - repeat 1s step with gate timer */
void ApplicationApplication_onKeyRightHold( ApplicationApplication _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->TimerState == ApplicationTimerStateEnumRunning )
  {
    ApplicationProgressIndicator_AdjustTime( _this->ProgressInd, 1 );
    return;
  }

  if ( _this->TimerState != ApplicationTimerStateEnumSetting )
  {
    ApplicationControlBar_RotateStep( _this->CtrlBar, 1 );
    return;
  }

  if ( _this->KeyHoldGateTimer.Enabled )
    return;

  CoreTimer_OnSetEnabled( &_this->KeyHoldGateTimer, 1 );
  ApplicationTimerConfigure_OnSetTimerSeconds( _this->TimerCfg, _this->TimerCfg->TimerSeconds 
  + 1 );

  if ( _this->TimerCfg->TimerSeconds > 60 )
    ApplicationTimerConfigure_OnSetTimerSeconds( _this->TimerCfg, 60 );

  ApplicationProgressIndicator_SetPreview( _this->ProgressInd, _this->TimerCfg->TimerSeconds );
}

/* Control bar arrow button released - delegate to the state machine */
void ApplicationApplication_OnControlBarAction( ApplicationApplication _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ApplicationApplication_HandleArrowAction( _this );
}

/* Countdown reached zero - tear down RUNNING state and show done screen */
void ApplicationApplication_OnCountdownComplete( ApplicationApplication _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ApplicationApplication_StopVideo( _this );
  _this->TimerState = ApplicationTimerStateEnumDone;

  if ( _this->ProgressInd != 0 )
  {
    CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->ProgressInd ));
    _this->ProgressInd = 0;
  }

  if ( _this->TimerCfg != 0 )
  {
    CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->TimerCfg ));
    _this->TimerCfg = 0;
  }

  CoreGroup_OnSetVisible( &_this->CtrlBar->OuterGroup, 0 );
  CoreGroup_OnSetVisible( &_this->CtrlBar->InnerGroup, 0 );
  _this->DoneMsg = EwNewObject( ApplicationDoneMessage, 0 );
  _this->DoneMsg->OnExpired = EwNewSlot( _this, ApplicationApplication_OnDoneExpired );
  ApplicationDoneMessage_OnSetModeIndex( _this->DoneMsg, _this->CtrlBar->SelectedIndex );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)_this->DoneMsg ), 0 );
}

/* Progress tick - syncs MM:SS display with remaining time once per second */
void ApplicationApplication_OnProgressTick( ApplicationApplication _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->ProgressInd == 0 )
    return;

  ApplicationTimerConfigure_OnSetTimerSeconds( _this->TimerCfg, _this->ProgressInd->RemainingSeconds );
}

/* Done message expired or dismissed - tear down done screen and restore IDLE state */
void ApplicationApplication_OnDoneExpired( ApplicationApplication _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->DoneMsg != 0 )
  {
    CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->DoneMsg ));
    _this->DoneMsg = 0;
  }

  _this->TimerState = ApplicationTimerStateEnumIdle;
  _this->CtrlBar->Locked = 0;
  CoreRotateTouchHandler_OnSetEnabled( &_this->CtrlBar->RotateHandler, 1 );
  ApplicationControlBar_OnSetArrowBitmap( _this->CtrlBar, EwLoadResource( &ApplicationIconArrow, 
  ResourcesBitmap ));
  ViewsImage_OnSetFrameNumber( &_this->CtrlBar->ArrowButton, 0 );
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->BgFadeEffect, 0 );
  ViewsImage_OnSetVisible( &_this->BackgroundNext, 0 );
  ViewsImage_OnSetBitmap( &_this->Background, _this->Backgrounds[ EwCheckIndex( 
  _this->CtrlBar->SelectedIndex, 6 )]);
  CoreGroup_OnSetVisible( &_this->CtrlBar->OuterGroup, 1 );
  ViewsImage_OnSetVisible( &_this->CtrlBar->Selected, 1 );
  ViewsImage_OnSetVisible( &_this->CtrlBar->IconSlot2, 1 );
  CoreGroup_OnSetVisible( &_this->CtrlBar->InnerGroup, 1 );
}

/* Carousel selection changed - cross-fade background to the newly selected mode */
void ApplicationApplication_OnSelectionChanged( ApplicationApplication _this, XObject 
  sender )
{
  ResourcesBitmap newBmp;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->TimerState == ApplicationTimerStateEnumSetting )
    newBmp = _this->DarkBackgrounds[ EwCheckIndex( _this->CtrlBar->SelectedIndex, 
    6 )];
  else
    newBmp = _this->Backgrounds[ EwCheckIndex( _this->CtrlBar->SelectedIndex, 6 )];

  if ( newBmp == _this->Background.Bitmap )
    return;

  ViewsImage_OnSetBitmap( &_this->BackgroundNext, newBmp );
  ViewsImage_OnSetOpacity( &_this->BackgroundNext, 0 );
  ViewsImage_OnSetVisible( &_this->BackgroundNext, 1 );
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->BgFadeEffect, 0 );
  _this->BgFadeEffect.Value1 = 0;
  _this->BgFadeEffect.Value2 = 255;
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->BgFadeEffect, 1 );
}

/* Carousel touched - immediately dismiss done screen if showing */
void ApplicationApplication_OnCarouselTouch( ApplicationApplication _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->TimerState == ApplicationTimerStateEnumDone )
    EwPostSignal( EwNewSlot( _this, ApplicationApplication_OnDoneExpired ), ((XObject)_this ));
}

/* Start video playback for the currently selected mode */
void ApplicationApplication_StartVideo( ApplicationApplication _this )
{
  XString source = _this->VideoSources[ EwCheckIndex( _this->CtrlBar->SelectedIndex, 
    6 )];

  ResourcesExternVideo_OnSetName( &_this->VideoSource, source );
  ResourcesExternVideo_OnSetPaused( &_this->VideoSource, 0 );
  ViewsImage_OnSetVisible( &_this->VideoView, 1 );
}

/* Stop video playback and free decoder memory */
void ApplicationApplication_StopVideo( ApplicationApplication _this )
{
  ViewsImage_OnSetVisible( &_this->VideoView, 0 );
  ResourcesExternVideo_OnSetName( &_this->VideoSource, 0 );
}

/* Handle video state changes - rewind to frame 0 on end-of-stream for looping */
void ApplicationApplication_OnVideoStateChanged( ApplicationApplication _this, XObject 
  sender )
{
  ResourcesExternVideo externVideo = EwCastObject( sender, ResourcesExternVideo );
  XEnum state = ResourcesExternVideo_GetState( externVideo );

  switch ( state )
  {
    case ResourcesExternVideoStateEndOfStreamReached :
      if ( _this->TimerState == ApplicationTimerStateEnumRunning )
        {
          extern void EwExternVideoRewind( XHandle aInstance, int aFrameNumber );
          XHandle inst = ((ResourcesExternVideo)externVideo)->instance;
          if ( inst )
          {
            EwExternVideoRewind( inst, 0 );

            /* Re-enable the 5ms update timer that was disabled on EOS */
            CoreTimer_OnSetEnabled( &((ResourcesExternVideo)externVideo)->updateTimer, 1 );

            /* Reset stored state so next onUpdate doesn't re-trigger EOS */
            ((ResourcesExternVideo)externVideo)->state = ResourcesExternVideoStatePlaying;
          }
        }
    break;

    default :; 
  }
}

/* Variants derived from the class : 'Application::Application' */
EW_DEFINE_CLASS_VARIANTS( ApplicationApplication )
EW_END_OF_CLASS_VARIANTS( ApplicationApplication )

/* Virtual Method Table (VMT) for the class : 'Application::Application' */
EW_DEFINE_CLASS( ApplicationApplication, CoreRoot, Background, Backgrounds, VideoSources, 
                 VideoSources, VideoSources, PreviousAdcValue, "Application::Application" )
  CoreRoot_GetRoot,
  CoreRoot_Draw,
  CoreGroup_GetClipping,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreGroup_AdjustDrawingArea,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreRoot_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreRoot_OnSetFocus,
  CoreRoot_DispatchEvent,
  CoreRoot_BroadcastEvent,
  CoreRoot_InvalidateArea,
EW_END_OF_CLASS( ApplicationApplication )

/* Initializer for the class 'Application::DeviceClass' */
void ApplicationDeviceClass__Init( ApplicationDeviceClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationDeviceClass );

  /* ... then construct all embedded objects */
  CoreSystemEvent__Init( &_this->HardButtonEvent, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationDeviceClass );

  /* Call the user defined constructor */
  ApplicationDeviceClass_Init( _this, aArg );
}

/* Re-Initializer for the class 'Application::DeviceClass' */
void ApplicationDeviceClass__ReInit( ApplicationDeviceClass _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEvent__ReInit( &_this->HardButtonEvent );
}

/* Finalizer method for the class 'Application::DeviceClass' */
void ApplicationDeviceClass__Done( ApplicationDeviceClass _this )
{
  /* Call the user defined destructor of the class */
  ApplicationDeviceClass_Done( _this );

  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Finalize all embedded objects */
  CoreSystemEvent__Done( &_this->HardButtonEvent );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* 'C' function for method : 'Application::DeviceClass.Done()' */
void ApplicationDeviceClass_Done( ApplicationDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  DeviceIntegrationExample_Done();
}

/* 'C' function for method : 'Application::DeviceClass.Init()' */
void ApplicationDeviceClass_Init( ApplicationDeviceClass _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  DeviceIntegrationExample_Init();
}

/* Called by device driver to update the ADC value from encoder rotation */
void ApplicationDeviceClass_UpdateAdcValue( ApplicationDeviceClass _this, XInt32 
  aNewValue )
{
  if ( aNewValue != _this->AdcValue )
  {
    _this->AdcValue = aNewValue;
    EwNotifyRefObservers( EwNewRef( _this, ApplicationDeviceClass_OnGetAdcValue, 
      ApplicationDeviceClass_OnSetAdcValue ), 0 );
  }
}

/* Wrapper function for the non virtual method : 'Application::DeviceClass.UpdateAdcValue()' */
void ApplicationDeviceClass__UpdateAdcValue( void* _this, XInt32 aNewValue )
{
  ApplicationDeviceClass_UpdateAdcValue((ApplicationDeviceClass)_this, aNewValue );
}

/* Called by device driver when hardware button is pressed */
void ApplicationDeviceClass_TriggerHardButtonEvent( ApplicationDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->HardButtonEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'Application::DeviceClass.TriggerHardButtonEvent()' */
void ApplicationDeviceClass__TriggerHardButtonEvent( void* _this )
{
  ApplicationDeviceClass_TriggerHardButtonEvent((ApplicationDeviceClass)_this );
}

/* Default onget method for the property 'AdcValue' */
XInt32 ApplicationDeviceClass_OnGetAdcValue( ApplicationDeviceClass _this )
{
  return _this->AdcValue;
}

/* Default onset method for the property 'AdcValue' */
void ApplicationDeviceClass_OnSetAdcValue( ApplicationDeviceClass _this, XInt32 
  value )
{
  _this->AdcValue = value;
}

/* Variants derived from the class : 'Application::DeviceClass' */
EW_DEFINE_CLASS_VARIANTS( ApplicationDeviceClass )
EW_END_OF_CLASS_VARIANTS( ApplicationDeviceClass )

/* Virtual Method Table (VMT) for the class : 'Application::DeviceClass' */
EW_DEFINE_CLASS( ApplicationDeviceClass, XObject, HardButtonEvent, AdcValue, AdcValue, 
                 AdcValue, AdcValue, AdcValue, "Application::DeviceClass" )
EW_END_OF_CLASS( ApplicationDeviceClass )

/* Global instance of the device interface */
EW_DEFINE_AUTOOBJECT( ApplicationDevice, ApplicationDeviceClass )

/* Initializer for the auto object 'Application::Device' */
void ApplicationDevice__Init( ApplicationDeviceClass _this )
{
  EW_UNUSED_ARG( _this );
}

/* Re-Initializer for the auto object 'Application::Device' */
void ApplicationDevice__ReInit( ApplicationDeviceClass _this )
{
  EW_UNUSED_ARG( _this );
}

/* Table with links to derived variants of the auto object : 'Application::Device' */
EW_DEFINE_AUTOOBJECT_VARIANTS( ApplicationDevice )
EW_END_OF_AUTOOBJECT_VARIANTS( ApplicationDevice )

/* Include a file containing the bitmap resource : 'Application::BackgroundChop' */
#include "_ApplicationBackgroundChop.h"

/* Table with links to derived variants of the bitmap resource : 'Application::BackgroundChop' */
EW_RES_WITHOUT_VARIANTS( ApplicationBackgroundChop )

/* Include a file containing the bitmap resource : 'Application::BackgroundCrush' */
#include "_ApplicationBackgroundCrush.h"

/* Table with links to derived variants of the bitmap resource : 'Application::BackgroundCrush' */
EW_RES_WITHOUT_VARIANTS( ApplicationBackgroundCrush )

/* Include a file containing the bitmap resource : 'Application::BackgroundWhip' */
#include "_ApplicationBackgroundWhip.h"

/* Table with links to derived variants of the bitmap resource : 'Application::BackgroundWhip' */
EW_RES_WITHOUT_VARIANTS( ApplicationBackgroundWhip )

/* Include a file containing the bitmap resource : 'Application::BackgroundShake' */
#include "_ApplicationBackgroundShake.h"

/* Table with links to derived variants of the bitmap resource : 'Application::BackgroundShake' */
EW_RES_WITHOUT_VARIANTS( ApplicationBackgroundShake )

/* Include a file containing the bitmap resource : 'Application::BackgroundStir' */
#include "_ApplicationBackgroundStir.h"

/* Table with links to derived variants of the bitmap resource : 'Application::BackgroundStir' */
EW_RES_WITHOUT_VARIANTS( ApplicationBackgroundStir )

/* Include a file containing the bitmap resource : 'Application::BackgroundStrain' */
#include "_ApplicationBackgroundStrain.h"

/* Table with links to derived variants of the bitmap resource : 'Application::BackgroundStrain' */
EW_RES_WITHOUT_VARIANTS( ApplicationBackgroundStrain )

/* Include a file containing the bitmap resource : 'Application::IconChop' */
#include "_ApplicationIconChop.h"

/* Table with links to derived variants of the bitmap resource : 'Application::IconChop' */
EW_RES_WITHOUT_VARIANTS( ApplicationIconChop )

/* Include a file containing the bitmap resource : 'Application::IconCrush' */
#include "_ApplicationIconCrush.h"

/* Table with links to derived variants of the bitmap resource : 'Application::IconCrush' */
EW_RES_WITHOUT_VARIANTS( ApplicationIconCrush )

/* Include a file containing the bitmap resource : 'Application::IconFroth' */
#include "_ApplicationIconFroth.h"

/* Table with links to derived variants of the bitmap resource : 'Application::IconFroth' */
EW_RES_WITHOUT_VARIANTS( ApplicationIconFroth )

/* Include a file containing the bitmap resource : 'Application::IconShake' */
#include "_ApplicationIconShake.h"

/* Table with links to derived variants of the bitmap resource : 'Application::IconShake' */
EW_RES_WITHOUT_VARIANTS( ApplicationIconShake )

/* Include a file containing the bitmap resource : 'Application::IconStir' */
#include "_ApplicationIconStir.h"

/* Table with links to derived variants of the bitmap resource : 'Application::IconStir' */
EW_RES_WITHOUT_VARIANTS( ApplicationIconStir )

/* Include a file containing the bitmap resource : 'Application::IconStrain' */
#include "_ApplicationIconStrain.h"

/* Table with links to derived variants of the bitmap resource : 'Application::IconStrain' */
EW_RES_WITHOUT_VARIANTS( ApplicationIconStrain )

/* Include a file containing the bitmap resource : 'Application::CircleOuterFill' */
#include "_ApplicationCircleOuterFill.h"

/* Table with links to derived variants of the bitmap resource : 'Application::CircleOuterFill' */
EW_RES_WITHOUT_VARIANTS( ApplicationCircleOuterFill )

/* Include a file containing the bitmap resource : 'Application::SelectedFill' */
#include "_ApplicationSelectedFill.h"

/* Table with links to derived variants of the bitmap resource : 'Application::SelectedFill' */
EW_RES_WITHOUT_VARIANTS( ApplicationSelectedFill )

/* Include a file containing the bitmap resource : 'Application::CircleInnerFill' */
#include "_ApplicationCircleInnerFill.h"

/* Table with links to derived variants of the bitmap resource : 'Application::CircleInnerFill' */
EW_RES_WITHOUT_VARIANTS( ApplicationCircleInnerFill )

/* Include a file containing the bitmap resource : 'Application::IconArrow' */
#include "_ApplicationIconArrow.h"

/* Table with links to derived variants of the bitmap resource : 'Application::IconArrow' */
EW_RES_WITHOUT_VARIANTS( ApplicationIconArrow )

/* Include a file containing the bitmap resource : 'Application::IconPlayPause' */
#include "_ApplicationIconPlayPause.h"

/* Table with links to derived variants of the bitmap resource : 'Application::IconPlayPause' */
EW_RES_WITHOUT_VARIANTS( ApplicationIconPlayPause )

/* Include a file containing the font resource : 'Application::FontTimer' */
#include "_ApplicationFontTimer.h"

/* Table with links to derived variants of the font resource : 'Application::FontTimer' */
EW_RES_WITHOUT_VARIANTS( ApplicationFontTimer )

/* Include a file containing the font resource : 'Application::FontDoneTitle' */
#include "_ApplicationFontDoneTitle.h"

/* Table with links to derived variants of the font resource : 'Application::FontDoneTitle' */
EW_RES_WITHOUT_VARIANTS( ApplicationFontDoneTitle )

/* Include a file containing the font resource : 'Application::FontDoneBold' */
#include "_ApplicationFontDoneBold.h"

/* Table with links to derived variants of the font resource : 'Application::FontDoneBold' */
EW_RES_WITHOUT_VARIANTS( ApplicationFontDoneBold )

/* Include a file containing the bitmap resource : 'Application::BackgroundChopDark' */
#include "_ApplicationBackgroundChopDark.h"

/* Table with links to derived variants of the bitmap resource : 'Application::BackgroundChopDark' */
EW_RES_WITHOUT_VARIANTS( ApplicationBackgroundChopDark )

/* Include a file containing the bitmap resource : 'Application::BackgroundCrushDark' */
#include "_ApplicationBackgroundCrushDark.h"

/* Table with links to derived variants of the bitmap resource : 'Application::BackgroundCrushDark' */
EW_RES_WITHOUT_VARIANTS( ApplicationBackgroundCrushDark )

/* Include a file containing the bitmap resource : 'Application::BackgroundWhipDark' */
#include "_ApplicationBackgroundWhipDark.h"

/* Table with links to derived variants of the bitmap resource : 'Application::BackgroundWhipDark' */
EW_RES_WITHOUT_VARIANTS( ApplicationBackgroundWhipDark )

/* Include a file containing the bitmap resource : 'Application::BackgroundShakeDark' */
#include "_ApplicationBackgroundShakeDark.h"

/* Table with links to derived variants of the bitmap resource : 'Application::BackgroundShakeDark' */
EW_RES_WITHOUT_VARIANTS( ApplicationBackgroundShakeDark )

/* Include a file containing the bitmap resource : 'Application::BackgroundStirDark' */
#include "_ApplicationBackgroundStirDark.h"

/* Table with links to derived variants of the bitmap resource : 'Application::BackgroundStirDark' */
EW_RES_WITHOUT_VARIANTS( ApplicationBackgroundStirDark )

/* Include a file containing the bitmap resource : 'Application::BackgroundStrainDark' */
#include "_ApplicationBackgroundStrainDark.h"

/* Table with links to derived variants of the bitmap resource : 'Application::BackgroundStrainDark' */
EW_RES_WITHOUT_VARIANTS( ApplicationBackgroundStrainDark )

/* Initializer for the class 'Application::ControlBar' */
void ApplicationControlBar__Init( ApplicationControlBar _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationControlBar );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->CircleOuter, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Selected, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->IconSlot0, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->IconSlot1, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->IconSlot2, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->IconSlot3, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->IconSlot4, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->CircleInner, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->ArrowButton, &_this->_.XObject, 0 );
  CoreGroup__Init( &_this->OuterGroup, &_this->_.XObject, 0 );
  CoreGroup__Init( &_this->InnerGroup, &_this->_.XObject, 0 );
  CoreRotateTouchHandler__Init( &_this->RotateHandler, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->ArrowTouchHandler, &_this->_.XObject, 0 );
  EffectsFloatEffect__Init( &_this->IconMoveEffect, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationControlBar );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0009 );
  CoreRectView__OnSetBounds( &_this->CircleOuter, _Const000A );
  ViewsImage_OnSetAutoSize( &_this->CircleOuter, 1 );
  ViewsImage_OnSetColor( &_this->CircleOuter, _Const000B );
  ViewsImage_OnSetVisible( &_this->CircleOuter, 1 );
  CoreRectView__OnSetBounds( &_this->Selected, _Const000C );
  ViewsImage_OnSetAutoSize( &_this->Selected, 1 );
  ViewsImage_OnSetColor( &_this->Selected, _Const000D );
  ViewsImage_OnSetVisible( &_this->Selected, 1 );
  CoreRectView__OnSetBounds( &_this->IconSlot0, _Const000E );
  ViewsImage_OnSetColor( &_this->IconSlot0, _Const0001 );
  CoreRectView__OnSetBounds( &_this->IconSlot1, _Const000E );
  ViewsImage_OnSetColor( &_this->IconSlot1, _Const0001 );
  CoreRectView__OnSetBounds( &_this->IconSlot2, _Const000E );
  ViewsImage_OnSetColor( &_this->IconSlot2, _Const0001 );
  CoreRectView__OnSetBounds( &_this->IconSlot3, _Const000E );
  ViewsImage_OnSetColor( &_this->IconSlot3, _Const0001 );
  CoreRectView__OnSetBounds( &_this->IconSlot4, _Const000E );
  ViewsImage_OnSetColor( &_this->IconSlot4, _Const0001 );
  CoreRectView__OnSetBounds( &_this->CircleInner, _Const000F );
  ViewsImage_OnSetAutoSize( &_this->CircleInner, 1 );
  ViewsImage_OnSetColor( &_this->CircleInner, _Const0010 );
  ViewsImage_OnSetVisible( &_this->CircleInner, 1 );
  CoreRectView__OnSetBounds( &_this->ArrowButton, _Const0011 );
  ViewsImage_OnSetAutoSize( &_this->ArrowButton, 1 );
  ViewsImage_OnSetColor( &_this->ArrowButton, _Const0012 );
  CoreRectView__OnSetBounds( &_this->OuterGroup, _Const0013 );
  CoreRectView__OnSetBounds( &_this->InnerGroup, _Const0013 );
  CoreRectView__OnSetBounds( &_this->RotateHandler, _Const0014 );
  CoreRotateTouchHandler_OnSetCenterOffset( &_this->RotateHandler, _Const0015 );
  CoreQuadView_OnSetPoint4((CoreQuadView)&_this->ArrowTouchHandler, _Const0016 );
  CoreQuadView_OnSetPoint3((CoreQuadView)&_this->ArrowTouchHandler, _Const0017 );
  CoreQuadView_OnSetPoint2((CoreQuadView)&_this->ArrowTouchHandler, _Const0018 );
  CoreQuadView_OnSetPoint1((CoreQuadView)&_this->ArrowTouchHandler, _Const0019 );
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->IconMoveEffect, EffectsTimingFastIn_EaseOut );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->IconMoveEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->IconMoveEffect, 200 );
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->IconMoveEffect, 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->CircleOuter ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Selected ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->IconSlot0 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->IconSlot1 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->IconSlot2 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->IconSlot3 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->IconSlot4 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->CircleInner ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->ArrowButton ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->OuterGroup ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->InnerGroup ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->RotateHandler ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->ArrowTouchHandler ), 0 );
  ViewsImage_OnSetBitmap( &_this->CircleOuter, EwLoadResource( &ApplicationCircleOuterFill, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Selected, EwLoadResource( &ApplicationSelectedFill, 
  ResourcesBitmap ));
  _this->IconBitmaps[ 0 ] = EwLoadResource( &ApplicationIconChop, ResourcesBitmap );
  _this->IconBitmaps[ 1 ] = EwLoadResource( &ApplicationIconCrush, ResourcesBitmap );
  _this->IconBitmaps[ 2 ] = EwLoadResource( &ApplicationIconFroth, ResourcesBitmap );
  _this->IconBitmaps[ 3 ] = EwLoadResource( &ApplicationIconShake, ResourcesBitmap );
  _this->IconBitmaps[ 4 ] = EwLoadResource( &ApplicationIconStir, ResourcesBitmap );
  _this->IconBitmaps[ 5 ] = EwLoadResource( &ApplicationIconStrain, ResourcesBitmap );
  _this->IconSlots[ 0 ] = &_this->IconSlot0;
  _this->IconSlots[ 1 ] = &_this->IconSlot1;
  _this->IconSlots[ 2 ] = &_this->IconSlot2;
  _this->IconSlots[ 3 ] = &_this->IconSlot3;
  _this->IconSlots[ 4 ] = &_this->IconSlot4;
  ViewsImage_OnSetBitmap( &_this->CircleInner, EwLoadResource( &ApplicationCircleInnerFill, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ArrowButton, EwLoadResource( &ApplicationIconArrow, 
  ResourcesBitmap ));
  _this->RotateHandler.OnRotate = EwNewSlot( _this, ApplicationControlBar_HandleRotation );
  _this->RotateHandler.OnEnd = EwNewSlot( _this, ApplicationControlBar_OnRelease );
  _this->RotateHandler.OnStart = EwNewSlot( _this, ApplicationControlBar_OnTouchStart );
  _this->ArrowTouchHandler.OnRelease = EwNewSlot( _this, ApplicationControlBar_OnArrowRelease );
  _this->ArrowTouchHandler.OnPress = EwNewSlot( _this, ApplicationControlBar_OnArrowPress );
  _this->IconMoveEffect.Super1.OnFinished = EwNewSlot( _this, ApplicationControlBar_OnIconMoveDone );
  _this->IconMoveEffect.Super1.OnAnimate = EwNewSlot( _this, ApplicationControlBar_OnIconAnimate );

  /* Call the user defined constructor */
  ApplicationControlBar_Init( _this, aArg );
}

/* Re-Initializer for the class 'Application::ControlBar' */
void ApplicationControlBar__ReInit( ApplicationControlBar _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->CircleOuter );
  ViewsImage__ReInit( &_this->Selected );
  ViewsImage__ReInit( &_this->IconSlot0 );
  ViewsImage__ReInit( &_this->IconSlot1 );
  ViewsImage__ReInit( &_this->IconSlot2 );
  ViewsImage__ReInit( &_this->IconSlot3 );
  ViewsImage__ReInit( &_this->IconSlot4 );
  ViewsImage__ReInit( &_this->CircleInner );
  ViewsImage__ReInit( &_this->ArrowButton );
  CoreGroup__ReInit( &_this->OuterGroup );
  CoreGroup__ReInit( &_this->InnerGroup );
  CoreRotateTouchHandler__ReInit( &_this->RotateHandler );
  CoreSimpleTouchHandler__ReInit( &_this->ArrowTouchHandler );
  EffectsFloatEffect__ReInit( &_this->IconMoveEffect );
}

/* Finalizer method for the class 'Application::ControlBar' */
void ApplicationControlBar__Done( ApplicationControlBar _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->CircleOuter );
  ViewsImage__Done( &_this->Selected );
  ViewsImage__Done( &_this->IconSlot0 );
  ViewsImage__Done( &_this->IconSlot1 );
  ViewsImage__Done( &_this->IconSlot2 );
  ViewsImage__Done( &_this->IconSlot3 );
  ViewsImage__Done( &_this->IconSlot4 );
  ViewsImage__Done( &_this->CircleInner );
  ViewsImage__Done( &_this->ArrowButton );
  CoreGroup__Done( &_this->OuterGroup );
  CoreGroup__Done( &_this->InnerGroup );
  CoreRotateTouchHandler__Done( &_this->RotateHandler );
  CoreSimpleTouchHandler__Done( &_this->ArrowTouchHandler );
  EffectsFloatEffect__Done( &_this->IconMoveEffect );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ApplicationControlBar_Init( ApplicationControlBar _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  CoreGroup_Remove((CoreGroup)_this, ((CoreView)&_this->CircleOuter ));
  CoreGroup_Remove((CoreGroup)_this, ((CoreView)&_this->Selected ));
  CoreGroup_Remove((CoreGroup)_this, ((CoreView)&_this->IconSlot0 ));
  CoreGroup_Remove((CoreGroup)_this, ((CoreView)&_this->IconSlot1 ));
  CoreGroup_Remove((CoreGroup)_this, ((CoreView)&_this->IconSlot2 ));
  CoreGroup_Remove((CoreGroup)_this, ((CoreView)&_this->IconSlot3 ));
  CoreGroup_Remove((CoreGroup)_this, ((CoreView)&_this->IconSlot4 ));
  CoreGroup_Add( &_this->OuterGroup, ((CoreView)&_this->CircleOuter ), 0 );
  CoreGroup_Add( &_this->OuterGroup, ((CoreView)&_this->IconSlot0 ), 0 );
  CoreGroup_Add( &_this->OuterGroup, ((CoreView)&_this->IconSlot1 ), 0 );
  CoreGroup_Add( &_this->OuterGroup, ((CoreView)&_this->IconSlot3 ), 0 );
  CoreGroup_Add( &_this->OuterGroup, ((CoreView)&_this->IconSlot4 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Selected ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->IconSlot2 ), 0 );
  CoreGroup_Remove((CoreGroup)_this, ((CoreView)&_this->CircleInner ));
  CoreGroup_Remove((CoreGroup)_this, ((CoreView)&_this->ArrowButton ));
  CoreGroup_Add( &_this->InnerGroup, ((CoreView)&_this->CircleInner ), 0 );
  CoreGroup_Add( &_this->InnerGroup, ((CoreView)&_this->ArrowButton ), 0 );
  CoreGroup_Remove((CoreGroup)_this, ((CoreView)&_this->ArrowTouchHandler ));
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->ArrowTouchHandler ), 0 );
  ApplicationControlBar_UpdateIconPositions( _this, 0.0f );
}

/* 'C' function for method : 'Application::ControlBar.OnSetArrowBitmap()' */
void ApplicationControlBar_OnSetArrowBitmap( ApplicationControlBar _this, ResourcesBitmap 
  value )
{
  _this->ArrowBitmap = value;
  ViewsImage_OnSetBitmap( &_this->ArrowButton, value );
}

/* Touch press on the arrow area - dim to pressed gray */
void ApplicationControlBar_OnArrowPress( ApplicationControlBar _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ApplicationControlBar_AnimateButton( _this, _Const0008 );
}

/* Touch released on the arrow area - restore to white and notify parent */
void ApplicationControlBar_OnArrowRelease( ApplicationControlBar _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ApplicationControlBar_AnimateButton( _this, _Const0001 );
  EwSignal( _this->OnAction, ((XObject)_this ));
}

/* Set button color on arrow, inner circle and selection highlight */
void ApplicationControlBar_AnimateButton( ApplicationControlBar _this, XColor aTarget )
{
  ViewsImage_OnSetColor( &_this->ArrowButton, aTarget );
  ViewsImage_OnSetColor( &_this->CircleInner, aTarget );
  ViewsImage_OnSetColor( &_this->Selected, aTarget );
}

/* Recalculate icon positions and opacity for the circular carousel. Uses 5 virtualized 
   image slots to display the 6 mode icons on a semicircular arc. Icons near the 
   top (90 degrees) are fully opaque; icons toward the edges fade out proportionally. */
void ApplicationControlBar_UpdateIconPositions( ApplicationControlBar _this, XFloat 
  aAngle )
{
  XFloat phase = aAngle / 60.0f;
  XInt32 centerPhase = (XInt32)EwMathRound( phase );
  XInt32 s;

  for ( s = 0; s < 5; s = s + 1 )
  {
    XInt32 modePhase = ( centerPhase + s ) - 2;
    XInt32 modeIndex = modePhase % 6;
    XFloat visualAngle;
    XInt32 x;
    XInt32 y;
    XFloat angleDiff;
    XInt32 opacity;
    ResourcesBitmap newBmp;
    XRect newRect;
    XColor oldClr;
    XColor newClr;

    if ( modeIndex < 0 )
      modeIndex = modeIndex + 6;

    visualAngle = 90.0f - (((XFloat)modePhase - phase ) * 45.0f );
    x = 180 + (XInt32)( 118.0f * EwMathCos( visualAngle ));
    y = 186 - (XInt32)( 118.0f * EwMathSin( visualAngle ));
    angleDiff = visualAngle - 90.0f;

    if ( angleDiff < 0.0f )
      angleDiff = -angleDiff;

    opacity = 255 - (XInt32)(( angleDiff / 90.0f ) * 200.0f );

    if ( opacity < 55 )
      opacity = 55;

    newBmp = _this->IconBitmaps[ EwCheckIndex( modeIndex, 6 )];

    if ( _this->IconSlots[ EwCheckIndex( s, 5 )]->Bitmap != newBmp )
      ViewsImage_OnSetBitmap( _this->IconSlots[ EwCheckIndex( s, 5 )], newBmp );

    newRect = EwNewRect( x - 34, y - 34, x + 34, y + 34 );

    if ( EwCompRect( _this->IconSlots[ EwCheckIndex( s, 5 )]->Super1.Bounds, newRect ))
      CoreRectView__OnSetBounds( _this->IconSlots[ EwCheckIndex( s, 5 )], newRect );

    oldClr = _this->IconSlots[ EwCheckIndex( s, 5 )]->Color;
    newClr = EwNewColor( oldClr.Red, oldClr.Green, oldClr.Blue, (XUInt8)opacity );

    if ( EwCompColor( oldClr, newClr ))
      ViewsImage_OnSetColor( _this->IconSlots[ EwCheckIndex( s, 5 )], newClr );
  }
}

/* Wrap an arbitrary angle into the 0..360 range using modular arithmetic */
XFloat ApplicationControlBar_NormalizeAngle( ApplicationControlBar _this, XFloat 
  aAngle )
{
  XFloat result;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  result = aAngle;

  while ( result < 0.0f )
    result = result + 360.0f;

  while ( result >= 360.0f )
    result = result - 360.0f;

  return result;
}

/* Called each rendered frame - interpolates the angle and repositions icons */
void ApplicationControlBar_OnIconAnimate( ApplicationControlBar _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ApplicationControlBar_UpdateIconPositions( _this, _this->IconMoveEffect.Value );
}

/* Animation finished - store final angle and notify parent of new selection */
void ApplicationControlBar_OnIconMoveDone( ApplicationControlBar _this, XObject 
  sender )
{
  XFloat norm;
  XInt32 newIndex;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  _this->CurrentAngle = _this->IconMoveTargetAngle;
  norm = ApplicationControlBar_NormalizeAngle( _this, _this->IconMoveTargetAngle );
  newIndex = (XInt32)(( norm + 30.0f ) / 60.0f ) % 6;

  if ( newIndex != _this->SelectedIndex )
  {
    _this->SelectedIndex = newIndex;
    EwSignal( _this->OnSelectionChanged, ((XObject)_this ));
  }
}

/* Animate icons from the current angle to the target angle */
void ApplicationControlBar_StartIconEffects( ApplicationControlBar _this, XFloat 
  aTargetAngle )
{
  XFloat startAngle;

  if ( _this->IconMoveEffect.Super1.Enabled )
  {
    startAngle = _this->IconMoveEffect.Value;
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->IconMoveEffect, 0 );
  }
  else
    startAngle = _this->CurrentAngle;

  _this->CurrentAngle = startAngle;
  _this->IconMoveTargetAngle = aTargetAngle;
  _this->IconMoveEffect.Value1 = startAngle;
  _this->IconMoveEffect.Value2 = aTargetAngle;
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->IconMoveEffect, 1 );
}

/* Update visuals whenever the carousel angle changes. Repositions all icons on 
   the arc and computes which mode is nearest to the top center. If the nearest 
   mode changed, fires OnSelectionChanged to the parent. */
void ApplicationControlBar_OnSetCurrentAngle( ApplicationControlBar _this, XFloat 
  value )
{
  XFloat normalized;
  XInt32 nearestIndex;

  if ( value == _this->CurrentAngle )
    return;

  _this->CurrentAngle = value;
  ApplicationControlBar_UpdateIconPositions( _this, _this->CurrentAngle );
  normalized = ApplicationControlBar_NormalizeAngle( _this, value );
  nearestIndex = (XInt32)(( normalized + 30.0f ) / 60.0f ) % 6;
  _this->SelectedIndex = nearestIndex;
}

/* Touch started - notifies parent, then snaps any running animation to its target 
   and saves the current angle as baseline for threshold detection */
void ApplicationControlBar_OnTouchStart( ApplicationControlBar _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwSignal( _this->OnTouch, ((XObject)_this ));

  if ( _this->Locked )
    return;

  if ( _this->IconMoveEffect.Super1.Enabled )
  {
    XFloat norm;
    XInt32 newIndex;
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->IconMoveEffect, 0 );
    ApplicationControlBar_OnSetCurrentAngle( _this, _this->IconMoveTargetAngle );
    norm = ApplicationControlBar_NormalizeAngle( _this, _this->IconMoveTargetAngle );
    newIndex = (XInt32)(( norm + 30.0f ) / 60.0f ) % 6;

    if ( newIndex != _this->SelectedIndex )
    {
      _this->SelectedIndex = newIndex;
      EwSignal( _this->OnSelectionChanged, ((XObject)_this ));
    }
  }

  _this->StartAngle = _this->CurrentAngle;
}

/* Rotation gesture in progress - icons follow the finger directly */
void ApplicationControlBar_HandleRotation( ApplicationControlBar _this, XObject 
  sender )
{
  XFloat totalAngle;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Locked )
    return;

  if ( _this->IconMoveEffect.Super1.Enabled )
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->IconMoveEffect, 0 );

  totalAngle = _this->StartAngle + ((XFloat)_this->RotateHandler.Relative * 2.3f );
  ApplicationControlBar_OnSetCurrentAngle( _this, totalAngle );
}

/* Touch released - snap to the nearest detent and notify parent of selection */
void ApplicationControlBar_OnRelease( ApplicationControlBar _this, XObject sender )
{
  XFloat angle;
  XFloat snapped;
  XFloat norm;
  XInt32 newIndex;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Locked )
    return;

  angle = _this->CurrentAngle;
  snapped = EwMathRound( angle / 60.0f ) * 60.0f;
  ApplicationControlBar_StartIconEffects( _this, snapped );
  norm = ApplicationControlBar_NormalizeAngle( _this, snapped );
  newIndex = (XInt32)(( norm + 30.0f ) / 60.0f ) % 6;

  if ( newIndex != _this->SelectedIndex )
    _this->SelectedIndex = newIndex;

  EwSignal( _this->OnSelectionChanged, ((XObject)_this ));
}

/* Rotate the carousel by exactly one mode slot (60 degrees). aDirection: +1 = clockwise, 
   -1 = counter-clockwise. Called by parent for encoder clicks and keyboard arrow 
   presses. Ignores the call if the carousel is locked or already animating. */
void ApplicationControlBar_RotateStep( ApplicationControlBar _this, XInt32 aDirection )
{
  XFloat baseAngle;

  if ( _this->Locked )
    return;

  if ( _this->IconMoveEffect.Super1.Enabled )
    baseAngle = _this->IconMoveTargetAngle;
  else
    baseAngle = _this->CurrentAngle;

  ApplicationControlBar_StartIconEffects( _this, baseAngle + ((XFloat)aDirection 
  * 60.0f ));
}

/* Variants derived from the class : 'Application::ControlBar' */
EW_DEFINE_CLASS_VARIANTS( ApplicationControlBar )
EW_END_OF_CLASS_VARIANTS( ApplicationControlBar )

/* Virtual Method Table (VMT) for the class : 'Application::ControlBar' */
EW_DEFINE_CLASS( ApplicationControlBar, CoreGroup, CircleOuter, IconBitmaps, OnAction, 
                 IconMoveTargetAngle, IconMoveTargetAngle, IconMoveTargetAngle, 
                 "Application::ControlBar" )
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreGroup_GetClipping,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreGroup_AdjustDrawingArea,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( ApplicationControlBar )

/* Initializer for the class 'Application::ProgressIndicator' */
void ApplicationProgressIndicator__Init( ApplicationProgressIndicator _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationProgressIndicator );

  /* ... then construct all embedded objects */
  GraphicsArcPath__Init( &_this->TimerArcPath, &_this->_.XObject, 0 );
  ViewsStrokePath__Init( &_this->TimerArcStroke, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->CountdownTimer, &_this->_.XObject, 0 );
  EffectsInt32Effect__Init( &_this->ArcEffect, &_this->_.XObject, 0 );
  CoreRotateTouchHandler__Init( &_this->ArcTouchHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationProgressIndicator );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const001A );
  GraphicsArcPath_OnSetEndAngle( &_this->TimerArcPath, 410.0f );
  GraphicsArcPath_OnSetStartAngle( &_this->TimerArcPath, 130.0f );
  GraphicsArcPath_OnSetRadius( &_this->TimerArcPath, 155.0f );
  GraphicsArcPath_OnSetStyle( &_this->TimerArcPath, GraphicsArcStyleArc );
  CoreRectView__OnSetBounds( &_this->TimerArcStroke, _Const001A );
  ViewsStrokePath_OnSetColor( &_this->TimerArcStroke, _Const0001 );
  ViewsStrokePath_OnSetOffset( &_this->TimerArcStroke, _Const001B );
  ViewsStrokePath_OnSetEndCap( &_this->TimerArcStroke, GraphicsPathCapRound );
  ViewsStrokePath_OnSetStartCap( &_this->TimerArcStroke, GraphicsPathCapRound );
  ViewsStrokePath_OnSetWidth( &_this->TimerArcStroke, 8.0f );
  ViewsStrokePath_OnSetVisible( &_this->TimerArcStroke, 1 );
  CoreTimer_OnSetPeriod( &_this->CountdownTimer, 1000 );
  CoreTimer_OnSetEnabled( &_this->CountdownTimer, 0 );
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->ArcEffect, EffectsTimingLinear );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->ArcEffect, 1 );
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->ArcEffect, 0 );
  CoreRectView__OnSetBounds( &_this->ArcTouchHandler, _Const001A );
  CoreRotateTouchHandler_OnSetCenterOffset( &_this->ArcTouchHandler, _Const001C );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->TimerArcStroke ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->ArcTouchHandler ), 0 );
  ViewsStrokePath_OnSetPath( &_this->TimerArcStroke, ((GraphicsPath)&_this->TimerArcPath ));
  _this->CountdownTimer.OnTrigger = EwNewSlot( _this, ApplicationProgressIndicator_OnCountdownTick );
  _this->ArcEffect.Super1.OnAnimate = EwNewSlot( _this, ApplicationProgressIndicator_OnArcAnimate );
  _this->ArcTouchHandler.OnRotate = EwNewSlot( _this, ApplicationProgressIndicator_OnArcRotate );
  _this->ArcTouchHandler.OnStart = EwNewSlot( _this, ApplicationProgressIndicator_OnArcTouchStart );
}

/* Re-Initializer for the class 'Application::ProgressIndicator' */
void ApplicationProgressIndicator__ReInit( ApplicationProgressIndicator _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  GraphicsArcPath__ReInit( &_this->TimerArcPath );
  ViewsStrokePath__ReInit( &_this->TimerArcStroke );
  CoreTimer__ReInit( &_this->CountdownTimer );
  EffectsInt32Effect__ReInit( &_this->ArcEffect );
  CoreRotateTouchHandler__ReInit( &_this->ArcTouchHandler );
}

/* Finalizer method for the class 'Application::ProgressIndicator' */
void ApplicationProgressIndicator__Done( ApplicationProgressIndicator _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  GraphicsArcPath__Done( &_this->TimerArcPath );
  ViewsStrokePath__Done( &_this->TimerArcStroke );
  CoreTimer__Done( &_this->CountdownTimer );
  EffectsInt32Effect__Done( &_this->ArcEffect );
  CoreRotateTouchHandler__Done( &_this->ArcTouchHandler );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* Set static arc fill proportional to aSeconds / MaxSeconds (no countdown)
   Uses preview angles that avoid the visible button bar. */
void ApplicationProgressIndicator_SetPreview( ApplicationProgressIndicator _this, 
  XInt32 aSeconds )
{
  CoreTimer_OnSetEnabled( &_this->CountdownTimer, 0 );
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->ArcEffect, 0 );
  GraphicsArcPath_OnSetEndAngle( &_this->TimerArcPath, 130.0f + (( 280.0f * (XFloat)aSeconds ) 
  / 60.0f ));
}

/* Start the countdown. */
void ApplicationProgressIndicator_StartCountdown( ApplicationProgressIndicator _this, 
  XInt32 aSeconds )
{
  _this->TotalSeconds = aSeconds;

  if ( aSeconds <= 0 )
    return;

  _this->RemainingSeconds = aSeconds;
  GraphicsArcPath_OnSetEndAngle( &_this->TimerArcPath, 130.0f + (( 280.0f * (XFloat)aSeconds ) 
  / 60.0f ));
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->ArcEffect, 0 );
  _this->ArcEffect.Value1 = aSeconds * 1000;
  _this->ArcEffect.Value2 = 0;
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->ArcEffect, aSeconds * 
  1000 );
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->ArcEffect, 1 );
  CoreTimer_OnSetEnabled( &_this->CountdownTimer, 0 );
  CoreTimer_OnSetEnabled( &_this->CountdownTimer, 1 );
}

/* Add or remove seconds during a running countdown. Restarts the arc effect
   from the current visual position so the sweep continues smoothly. */
void ApplicationProgressIndicator_AdjustTime( ApplicationProgressIndicator _this, 
  XInt32 aDelta )
{
  XInt32 newRemaining = _this->RemainingSeconds + aDelta;
  XInt32 currentMs;

  if ( newRemaining < 1 )
    newRemaining = 1;

  if ( newRemaining > 60 )
    newRemaining = 60;

  _this->RemainingSeconds = newRemaining;
  EwSignal( _this->OnTick, ((XObject)_this ));
  currentMs = newRemaining * 1000;
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->ArcEffect, 0 );
  _this->ArcEffect.Value1 = currentMs;
  _this->ArcEffect.Value2 = 0;
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->ArcEffect, currentMs );
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->ArcEffect, 1 );
}

/* Called every animation frame to smoothly shrink the arc. The arc spans 280 degrees 
   Maps the remaining milliseconds to an arc EndAngle using current ArcStart/ArcSpan. */
void ApplicationProgressIndicator_OnArcAnimate( ApplicationProgressIndicator _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  GraphicsArcPath_OnSetEndAngle( &_this->TimerArcPath, 130.0f + (( 280.0f * (XFloat)_this->ArcEffect.Value ) 
  / 60000.0f ));
}

/* Fires once per second. Decrements the remaining time, notifies the parent (to 
   update the MM:SS display), and when zero is reached stops everything and fires 
   OnCountdownDone. */
void ApplicationProgressIndicator_OnCountdownTick( ApplicationProgressIndicator _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  _this->RemainingSeconds = _this->RemainingSeconds - 1;
  EwSignal( _this->OnTick, ((XObject)_this ));

  if ( _this->RemainingSeconds <= 0 )
  {
    _this->RemainingSeconds = 0;
    CoreTimer_OnSetEnabled( &_this->CountdownTimer, 0 );
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->ArcEffect, 0 );
    EwSignal( _this->OnCountdownDone, ((XObject)_this ));
  }
}

/* Touch started - save current seconds as baseline */
void ApplicationProgressIndicator_OnArcTouchStart( ApplicationProgressIndicator _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  _this->TouchStartSeconds = (XInt32)((( _this->TimerArcPath.EndAngle - 130.0f ) 
  / 280.0f ) * 60.0f );
}

/* Dragging on the arc - map rotation to seconds */
void ApplicationProgressIndicator_OnArcRotate( ApplicationProgressIndicator _this, 
  XObject sender )
{
  XInt32 deltaSec;
  XInt32 newSec;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  deltaSec = -(XInt32)((XFloat)_this->ArcTouchHandler.Relative / 4.66667f );
  newSec = _this->TouchStartSeconds + deltaSec;

  if ( newSec < 0 )
    newSec = 0;

  if ( newSec > 60 )
    newSec = 60;

  if ( _this->CountdownTimer.Enabled )
  {
    XInt32 diff = newSec - _this->RemainingSeconds;

    if ( diff != 0 )
      ApplicationProgressIndicator_AdjustTime( _this, diff );
  }
  else
  {
    _this->RemainingSeconds = newSec;
    ApplicationProgressIndicator_SetPreview( _this, newSec );
    EwSignal( _this->OnTick, ((XObject)_this ));
  }
}

/* Variants derived from the class : 'Application::ProgressIndicator' */
EW_DEFINE_CLASS_VARIANTS( ApplicationProgressIndicator )
EW_END_OF_CLASS_VARIANTS( ApplicationProgressIndicator )

/* Virtual Method Table (VMT) for the class : 'Application::ProgressIndicator' */
EW_DEFINE_CLASS( ApplicationProgressIndicator, CoreGroup, TimerArcPath, OnCountdownDone, 
                 OnCountdownDone, TotalSeconds, TotalSeconds, TotalSeconds, "Application::ProgressIndicator" )
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreGroup_GetClipping,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreGroup_AdjustDrawingArea,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( ApplicationProgressIndicator )

/* Initializer for the class 'Application::TimerConfigure' */
void ApplicationTimerConfigure__Init( ApplicationTimerConfigure _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationTimerConfigure );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->TimerText, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationTimerConfigure );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const001D );
  CoreRectView__OnSetBounds( &_this->TimerText, _Const001E );
  ViewsText_OnSetAlignment( &_this->TimerText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TimerText, EwLoadString( &_Const001F ));
  ViewsText_OnSetColor( &_this->TimerText, _Const0001 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->TimerText ), 0 );
  ViewsText_OnSetFont( &_this->TimerText, EwLoadResource( &ApplicationFontTimer, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Application::TimerConfigure' */
void ApplicationTimerConfigure__ReInit( ApplicationTimerConfigure _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->TimerText );
}

/* Finalizer method for the class 'Application::TimerConfigure' */
void ApplicationTimerConfigure__Done( ApplicationTimerConfigure _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->TimerText );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* Store the new timer value and refresh the displayed M:SS text */
void ApplicationTimerConfigure_OnSetTimerSeconds( ApplicationTimerConfigure _this, 
  XInt32 value )
{
  XInt32 minutes;
  XInt32 seconds;

  _this->TimerSeconds = value;
  minutes = _this->TimerSeconds / 60;
  seconds = _this->TimerSeconds % 60;
  ViewsText_OnSetString( &_this->TimerText, EwConcatString( EwConcatString( EwNewStringInt( 
  minutes, 0, 10 ), EwLoadString( &_Const0020 )), EwNewStringInt( seconds, 2, 10 )));
}

/* Variants derived from the class : 'Application::TimerConfigure' */
EW_DEFINE_CLASS_VARIANTS( ApplicationTimerConfigure )
EW_END_OF_CLASS_VARIANTS( ApplicationTimerConfigure )

/* Virtual Method Table (VMT) for the class : 'Application::TimerConfigure' */
EW_DEFINE_CLASS( ApplicationTimerConfigure, CoreGroup, TimerText, TimerSeconds, 
                 TimerSeconds, TimerSeconds, TimerSeconds, TimerSeconds, "Application::TimerConfigure" )
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreGroup_GetClipping,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreGroup_AdjustDrawingArea,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( ApplicationTimerConfigure )

/* Initializer for the class 'Application::DoneMessage' */
void ApplicationDoneMessage__Init( ApplicationDoneMessage _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationDoneMessage );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->DoneTitle, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->DoneSubtitle, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->DismissTouchHandler, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->DismissTimer, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationDoneMessage );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0021 );
  CoreRectView__OnSetBounds( &_this->DoneTitle, _Const0022 );
  ViewsText_OnSetAlignment( &_this->DoneTitle, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DoneTitle, EwLoadString( &_Const0023 ));
  ViewsText_OnSetColor( &_this->DoneTitle, _Const0001 );
  ViewsText_OnSetVisible( &_this->DoneTitle, 1 );
  CoreRectView__OnSetBounds( &_this->DoneSubtitle, _Const0024 );
  ViewsText_OnSetWrapText( &_this->DoneSubtitle, 1 );
  ViewsText_OnSetAlignment( &_this->DoneSubtitle, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DoneSubtitle, EwLoadString( &_Const0025 ));
  ViewsText_OnSetColor( &_this->DoneSubtitle, _Const0001 );
  ViewsText_OnSetVisible( &_this->DoneSubtitle, 1 );
  CoreQuadView_OnSetPoint4((CoreQuadView)&_this->DismissTouchHandler, _Const0026 );
  CoreQuadView_OnSetPoint3((CoreQuadView)&_this->DismissTouchHandler, _Const0027 );
  CoreQuadView_OnSetPoint2((CoreQuadView)&_this->DismissTouchHandler, _Const0028 );
  CoreQuadView_OnSetPoint1((CoreQuadView)&_this->DismissTouchHandler, _Const001C );
  CoreTimer_OnSetPeriod( &_this->DismissTimer, 0 );
  CoreTimer_OnSetBegin( &_this->DismissTimer, 3000 );
  CoreTimer_OnSetEnabled( &_this->DismissTimer, 1 );
  _this->DoneEnjoyTexts[ 0 ] = EwShareString( EwLoadString( &_Const0029 ));
  _this->DoneEnjoyTexts[ 1 ] = EwShareString( EwLoadString( &_Const002A ));
  _this->DoneEnjoyTexts[ 2 ] = EwShareString( EwLoadString( &_Const002B ));
  _this->DoneEnjoyTexts[ 3 ] = EwShareString( EwLoadString( &_Const0025 ));
  _this->DoneEnjoyTexts[ 4 ] = EwShareString( EwLoadString( &_Const002C ));
  _this->DoneEnjoyTexts[ 5 ] = EwShareString( EwLoadString( &_Const002D ));
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->DoneTitle ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->DoneSubtitle ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->DismissTouchHandler ), 0 );
  ViewsText_OnSetFont( &_this->DoneTitle, EwLoadResource( &ApplicationFontDoneTitle, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DoneSubtitle, EwLoadResource( &ApplicationFontDoneBold, 
  ResourcesFont ));
  _this->DismissTouchHandler.OnRelease = EwNewSlot( _this, ApplicationDoneMessage_OnTouchDismiss );
  _this->DismissTimer.OnTrigger = EwNewSlot( _this, ApplicationDoneMessage_OnDismissTimerExpired );
}

/* Re-Initializer for the class 'Application::DoneMessage' */
void ApplicationDoneMessage__ReInit( ApplicationDoneMessage _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->DoneTitle );
  ViewsText__ReInit( &_this->DoneSubtitle );
  CoreSimpleTouchHandler__ReInit( &_this->DismissTouchHandler );
  CoreTimer__ReInit( &_this->DismissTimer );
}

/* Finalizer method for the class 'Application::DoneMessage' */
void ApplicationDoneMessage__Done( ApplicationDoneMessage _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->DoneTitle );
  ViewsText__Done( &_this->DoneSubtitle );
  CoreSimpleTouchHandler__Done( &_this->DismissTouchHandler );
  CoreTimer__Done( &_this->DismissTimer );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* User tapped directly on the done screen overlay */
void ApplicationDoneMessage_OnTouchDismiss( ApplicationDoneMessage _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwSignal( _this->OnExpired, ((XObject)_this ));
}

/* 3-second auto-dismiss timer elapsed without user interaction */
void ApplicationDoneMessage_OnDismissTimerExpired( ApplicationDoneMessage _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwSignal( _this->OnExpired, ((XObject)_this ));
}

/* Look up the mode-specific "Enjoy your ..." text and apply it to the subtitle */
void ApplicationDoneMessage_OnSetModeIndex( ApplicationDoneMessage _this, XInt32 
  value )
{
  _this->ModeIndex = value;
  ViewsText_OnSetString( &_this->DoneSubtitle, _this->DoneEnjoyTexts[ EwCheckIndex( 
  value, 6 )]);
}

/* Variants derived from the class : 'Application::DoneMessage' */
EW_DEFINE_CLASS_VARIANTS( ApplicationDoneMessage )
EW_END_OF_CLASS_VARIANTS( ApplicationDoneMessage )

/* Virtual Method Table (VMT) for the class : 'Application::DoneMessage' */
EW_DEFINE_CLASS( ApplicationDoneMessage, CoreGroup, DoneTitle, OnExpired, OnExpired, 
                 DoneEnjoyTexts, DoneEnjoyTexts, ModeIndex, "Application::DoneMessage" )
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreGroup_GetClipping,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreGroup_AdjustDrawingArea,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( ApplicationDoneMessage )

/* Embedded Wizard */
