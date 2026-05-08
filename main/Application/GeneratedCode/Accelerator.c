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
#include "_AcceleratorAccelerator.h"
#include "_AcceleratorGraphicsFactory.h"
#include "_CoreRoot.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_GraphicsCanvas.h"
#include "_GraphicsSystemDeviceClass.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "_WidgetSetPushButton.h"
#include "_WidgetSetPushButtonConfig.h"
#include "_WidgetSetToggleButton.h"
#include "_WidgetSetToggleButtonConfig.h"
#include "Accelerator.h"
#include "GraphicsSystem.h"
#include "Views.h"
#include "WidgetSet.h"

/* Strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned short _StringsDefault0[] =
{
  0xFFFF, 0xFFFF, 0xC557, 0x0046, 0x0072, 0x0061, 0x006D, 0x0065, 0x0072, 0x0061,
  0x0074, 0x0065, 0x0000, 0xC557, 0x0030, 0x0020, 0x0066, 0x0070, 0x0073, 0x0000,
  0xC557, 0x0043, 0x0050, 0x0055, 0x0020, 0x004C, 0x006F, 0x0061, 0x0064, 0x0000,
  0xC557, 0x0030, 0x0020, 0x0025, 0x0025, 0x0000, 0xC557, 0x0053, 0x0063, 0x0065,
  0x006E, 0x0061, 0x0072, 0x0069, 0x006F, 0x0000, 0xC557, 0x0041, 0x0063, 0x0063,
  0x0065, 0x006C, 0x0065, 0x0072, 0x0061, 0x0074, 0x006F, 0x0072, 0x0000, 0xC557,
  0x0041, 0x006C, 0x0070, 0x0068, 0x0061, 0x0038, 0x0020, 0x0042, 0x006C, 0x0065,
  0x006E, 0x0064, 0x0000, 0xC557, 0x004E, 0x0065, 0x0078, 0x0074, 0x0000, 0xC557,
  0x0020, 0x0066, 0x0070, 0x0073, 0x0000, 0xC557, 0x0020, 0x0025, 0x0025, 0x0000,
  0xC557, 0x002D, 0x0000, 0xC557, 0x0052, 0x0065, 0x0063, 0x0074, 0x0061, 0x006E,
  0x0067, 0x006C, 0x0065, 0x0020, 0x0046, 0x0069, 0x006C, 0x006C, 0x0000, 0xC557,
  0x0052, 0x0065, 0x0063, 0x0074, 0x0061, 0x006E, 0x0067, 0x006C, 0x0065, 0x0020,
  0x0042, 0x006C, 0x0065, 0x006E, 0x0064, 0x0000, 0xC557, 0x0052, 0x0047, 0x0042,
  0x0035, 0x0036, 0x0035, 0x0020, 0x0042, 0x0069, 0x0074, 0x006D, 0x0061, 0x0070,
  0x0000, 0xC557, 0x004E, 0x0061, 0x0074, 0x0069, 0x0076, 0x0065, 0x0020, 0x0042,
  0x0069, 0x0074, 0x006D, 0x0061, 0x0070, 0x0000, 0xC557, 0x0052, 0x0047, 0x0042,
  0x0035, 0x0036, 0x0035, 0x0020, 0x0042, 0x0069, 0x0074, 0x006D, 0x0061, 0x0070,
  0x0020, 0x002B, 0x0020, 0x004F, 0x0070, 0x0061, 0x0063, 0x0069, 0x0074, 0x0079,
  0x0000, 0xC557, 0x004E, 0x0061, 0x0074, 0x0069, 0x0076, 0x0065, 0x0020, 0x0042,
  0x0069, 0x0074, 0x006D, 0x0061, 0x0070, 0x0020, 0x002B, 0x0020, 0x004F, 0x0070,
  0x0061, 0x0063, 0x0069, 0x0074, 0x0079, 0x0000, 0xC557, 0x0041, 0x006C, 0x0070,
  0x0068, 0x0061, 0x0038, 0x0020, 0x0042, 0x0069, 0x0074, 0x006D, 0x0061, 0x0070,
  0x0000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 360, 360 }};
static const XColor _Const0001 = { 0x08, 0x08, 0x20, 0xFF };
static const XRect _Const0002 = {{ 0, 79 }, { 360, 293 }};
static const XRect _Const0003 = {{ 72, 34 }, { 182, 54 }};
static const XStringRes _Const0004 = { _StringsDefault0, 0x0003 };
static const XRect _Const0005 = {{ 187, 29 }, { 243, 59 }};
static const XStringRes _Const0006 = { _StringsDefault0, 0x000E };
static const XRect _Const0007 = {{ 67, 328 }, { 167, 348 }};
static const XStringRes _Const0008 = { _StringsDefault0, 0x0015 };
static const XRect _Const0009 = {{ 172, 323 }, { 272, 353 }};
static const XStringRes _Const000A = { _StringsDefault0, 0x001F };
static const XColor _Const000B = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XRect _Const000C = {{ 77, 301 }, { 167, 321 }};
static const XStringRes _Const000D = { _StringsDefault0, 0x0025 };
static const XRect _Const000E = {{ 82, 10 }, { 182, 30 }};
static const XStringRes _Const000F = { _StringsDefault0, 0x002F };
static const XRect _Const0010 = {{ 32, 49 }, { 332, 79 }};
static const XStringRes _Const0011 = { _StringsDefault0, 0x003C };
static const XRect _Const0012 = {{ 172, 296 }, { 272, 326 }};
static const XStringRes _Const0013 = { _StringsDefault0, 0x004A };
static const XRect _Const0014 = {{ 191, 0 }, { 239, 40 }};
static const XStringRes _Const0015 = { _StringsDefault0, 0x0050 };
static const XStringRes _Const0016 = { _StringsDefault0, 0x0056 };
static const XStringRes _Const0017 = { _StringsDefault0, 0x005B };
static const XStringRes _Const0018 = { _StringsDefault0, 0x005E };
static const XStringRes _Const0019 = { _StringsDefault0, 0x006E };
static const XStringRes _Const001A = { _StringsDefault0, 0x007F };
static const XStringRes _Const001B = { _StringsDefault0, 0x008E };
static const XStringRes _Const001C = { _StringsDefault0, 0x009D };
static const XStringRes _Const001D = { _StringsDefault0, 0x00B6 };
static const XStringRes _Const001E = { _StringsDefault0, 0x00CF };
static const XRect _Const001F = {{ 0, 0 }, { 400, 240 }};
static const XPoint _Const0020 = { 0, 0 };

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

/* Initializer for the class 'Accelerator::Accelerator' */
void AcceleratorAccelerator__Init( AcceleratorAccelerator _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( AcceleratorAccelerator );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Rectangle, &_this->_.XObject, 0 );
  AcceleratorGraphicsFactory__Init( &_this->GraphicsFactory, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->PerformanceTimer, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->FpsDescr, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->FpsText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->CpuDescr, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->CpuText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->ScenDescr, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->AccelDescr, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->ScenarioText, &_this->_.XObject, 0 );
  WidgetSetPushButton__Init( &_this->PushButton, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->AutoDemoTimer, &_this->_.XObject, 0 );
  WidgetSetToggleButton__Init( &_this->ToggleButton, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( AcceleratorAccelerator );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0001 );
  CoreRectView__OnSetBounds( &_this->GraphicsFactory, _Const0002 );
  CoreTimer_OnSetEnabled( &_this->PerformanceTimer, 1 );
  CoreRectView__OnSetBounds( &_this->FpsDescr, _Const0003 );
  ViewsText_OnSetAlignment( &_this->FpsDescr, ViewsTextAlignmentAlignHorzRight | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->FpsDescr, EwLoadString( &_Const0004 ));
  CoreRectView__OnSetBounds( &_this->FpsText, _Const0005 );
  ViewsText_OnSetAlignment( &_this->FpsText, ViewsTextAlignmentAlignHorzCenter | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->FpsText, EwLoadString( &_Const0006 ));
  CoreRectView__OnSetBounds( &_this->CpuDescr, _Const0007 );
  ViewsText_OnSetAlignment( &_this->CpuDescr, ViewsTextAlignmentAlignHorzRight | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->CpuDescr, EwLoadString( &_Const0008 ));
  CoreRectView__OnSetBounds( &_this->CpuText, _Const0009 );
  ViewsText_OnSetAlignment( &_this->CpuText, ViewsTextAlignmentAlignHorzCenter | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->CpuText, EwLoadString( &_Const000A ));
  ViewsText_OnSetColor( &_this->CpuText, _Const000B );
  CoreRectView__OnSetBounds( &_this->ScenDescr, _Const000C );
  ViewsText_OnSetAlignment( &_this->ScenDescr, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ScenDescr, EwLoadString( &_Const000D ));
  CoreRectView__OnSetBounds( &_this->AccelDescr, _Const000E );
  ViewsText_OnSetWrapText( &_this->AccelDescr, 1 );
  ViewsText_OnSetAlignment( &_this->AccelDescr, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->AccelDescr, EwLoadString( &_Const000F ));
  CoreRectView__OnSetBounds( &_this->ScenarioText, _Const0010 );
  ViewsText_OnSetAlignment( &_this->ScenarioText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ScenarioText, EwLoadString( &_Const0011 ));
  CoreRectView__OnSetBounds( &_this->PushButton, _Const0012 );
  WidgetSetPushButton_OnSetLabel( &_this->PushButton, EwLoadString( &_Const0013 ));
  CoreTimer_OnSetPeriod( &_this->AutoDemoTimer, 5000 );
  CoreTimer_OnSetBegin( &_this->AutoDemoTimer, 0 );
  _this->NoOfRectBlend = 8;
  _this->NoOfRGB565Bmp = 8;
  _this->NoOfNativeBmp = 8;
  _this->NoOfRGB565BmpOpacity = 8;
  _this->NoOfNativeBmpOpacity = 8;
  _this->NoOfAlpha8Bmp = 8;
  CoreRectView__OnSetBounds( &_this->ToggleButton, _Const0014 );
  WidgetSetToggleButton_OnSetLabel( &_this->ToggleButton, 0 );
  _this->currentScene = 5;
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Rectangle ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->GraphicsFactory ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->FpsDescr ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->FpsText ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->CpuDescr ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->CpuText ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->ScenDescr ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->AccelDescr ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->ScenarioText ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->PushButton ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->ToggleButton ), 0 );
  _this->PerformanceTimer.OnTrigger = EwNewSlot( _this, AcceleratorAccelerator_PerformanceSlot );
  ViewsText_OnSetFont( &_this->FpsDescr, EwLoadResource( &AcceleratorFontSmall, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->FpsText, EwLoadResource( &AcceleratorFontMedium, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->CpuDescr, EwLoadResource( &AcceleratorFontSmall, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->CpuText, EwLoadResource( &AcceleratorFontMedium, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->ScenDescr, EwLoadResource( &AcceleratorFontSmall, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->AccelDescr, EwLoadResource( &AcceleratorFontSmall, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->ScenarioText, EwLoadResource( &AcceleratorFontMedium, 
  ResourcesFont ));
  _this->PushButton.OnActivate = EwNewSlot( _this, AcceleratorAccelerator_NextScene );
  WidgetSetPushButton_OnSetAppearance( &_this->PushButton, EwGetAutoObject( &WidgetSetPushButton_Lime_Small, 
  WidgetSetPushButtonConfig ));
  _this->AutoDemoTimer.OnTrigger = EwNewSlot( _this, AcceleratorAccelerator_NextScene );
  _this->GraphicsSystem = EwGetAutoObject( &GraphicsSystemDevice, GraphicsSystemDeviceClass );
  WidgetSetToggleButton_OnSetOutlet( &_this->ToggleButton, EwNewRef( EwGetAutoObject( 
  &GraphicsSystemDevice, GraphicsSystemDeviceClass ), GraphicsSystemDeviceClass_OnGetAcceleratorActive, 
  GraphicsSystemDeviceClass_OnSetAcceleratorActive ));
  WidgetSetToggleButton_OnSetAppearance( &_this->ToggleButton, EwGetAutoObject( 
  &WidgetSetSwitch_Lime_Small, WidgetSetToggleButtonConfig ));

  /* Call the user defined constructor */
  AcceleratorAccelerator_Init( _this, aArg );
}

/* Re-Initializer for the class 'Accelerator::Accelerator' */
void AcceleratorAccelerator__ReInit( AcceleratorAccelerator _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Rectangle );
  AcceleratorGraphicsFactory__ReInit( &_this->GraphicsFactory );
  CoreTimer__ReInit( &_this->PerformanceTimer );
  ViewsText__ReInit( &_this->FpsDescr );
  ViewsText__ReInit( &_this->FpsText );
  ViewsText__ReInit( &_this->CpuDescr );
  ViewsText__ReInit( &_this->CpuText );
  ViewsText__ReInit( &_this->ScenDescr );
  ViewsText__ReInit( &_this->AccelDescr );
  ViewsText__ReInit( &_this->ScenarioText );
  WidgetSetPushButton__ReInit( &_this->PushButton );
  CoreTimer__ReInit( &_this->AutoDemoTimer );
  WidgetSetToggleButton__ReInit( &_this->ToggleButton );
}

/* Finalizer method for the class 'Accelerator::Accelerator' */
void AcceleratorAccelerator__Done( AcceleratorAccelerator _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Rectangle );
  AcceleratorGraphicsFactory__Done( &_this->GraphicsFactory );
  CoreTimer__Done( &_this->PerformanceTimer );
  ViewsText__Done( &_this->FpsDescr );
  ViewsText__Done( &_this->FpsText );
  ViewsText__Done( &_this->CpuDescr );
  ViewsText__Done( &_this->CpuText );
  ViewsText__Done( &_this->ScenDescr );
  ViewsText__Done( &_this->AccelDescr );
  ViewsText__Done( &_this->ScenarioText );
  WidgetSetPushButton__Done( &_this->PushButton );
  CoreTimer__Done( &_this->AutoDemoTimer );
  WidgetSetToggleButton__Done( &_this->ToggleButton );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void AcceleratorAccelerator_Init( AcceleratorAccelerator _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  ViewsText_OnSetVisible( &_this->AccelDescr, 0 );
  CoreGroup_OnSetVisible((CoreGroup)&_this->ToggleButton, 0 );
  ViewsText_OnSetVisible( &_this->CpuDescr, 0 );
  ViewsText_OnSetVisible( &_this->CpuText, 0 );
  CoreGroup__OnSetFocus( _this, ((CoreView)&_this->PushButton ));
}

/* The method UpdateLayout() is invoked automatically after the size of the component 
   has been changed. This method can be overridden and filled with logic to perform 
   a sophisticated arrangement calculation for one or more enclosed views. In this 
   case the parameter aSize can be used. It contains the current size of the component. 
   Usually, all enclosed views are arranged automatically accordingly to their @Layout 
   property. UpdateLayout() gives the derived components a chance to extend this 
   automatism by a user defined algorithm. */
void AcceleratorAccelerator_UpdateLayout( AcceleratorAccelerator _this, XPoint aSize )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aSize );

  EwSignal( EwNewSlot( _this, AcceleratorAccelerator_NextScene ), ((XObject)_this ));
}

/* 'C' function for method : 'Accelerator::Accelerator.PerformanceSlot()' */
void AcceleratorAccelerator_PerformanceSlot( AcceleratorAccelerator _this, XObject 
  sender )
{
  XInt32 cpu;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  cpu = GraphicsSystemDeviceClass_GetCpuLoad( _this->GraphicsSystem );

  if ( CoreView__GetRoot( _this ) != 0 )
    ViewsText_OnSetString( &_this->FpsText, EwConcatString( EwNewStringInt( CoreRoot_GetFPS( 
    CoreView__GetRoot( _this )), 0, 10 ), EwLoadString( &_Const0015 )));

  if (( cpu >= 0 ) && ( cpu <= 100 ))
  {
    XColor c;
    ViewsText_OnSetString( &_this->CpuText, EwConcatString( EwNewStringInt( cpu, 
    0, 10 ), EwLoadString( &_Const0016 )));
    c = EwNewColor((XUInt8)(( cpu * 255 ) / 100 ), (XUInt8)((( 100 - cpu ) * 255 ) 
    / 100 ), 0, 255 );
    ViewsText_OnSetColor( &_this->CpuText, c );
  }
  else
  {
    ViewsText_OnSetString( &_this->CpuText, EwLoadString( &_Const0017 ));
    ViewsText_OnSetColor( &_this->CpuText, _Const000B );
  }
}

/* 'C' function for method : 'Accelerator::Accelerator.NextScene()' */
void AcceleratorAccelerator_NextScene( AcceleratorAccelerator _this, XObject sender )
{
  XInt32 scene;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  scene = _this->currentScene + 1;

  while ( scene != _this->currentScene )
  {
    if ( AcceleratorAccelerator_ChangeScene( _this, scene ))
      _this->currentScene = scene;
    else
      scene = scene + 1;

    if ( scene > 6 )
      scene = 0;
  }
}

/* Method to select given test case. It the test case is not supported, the method 
   returns false - otherwise true. */
XBool AcceleratorAccelerator_ChangeScene( AcceleratorAccelerator _this, XInt32 aIndex )
{
  XEnum type;
  XInt32 count = 0;

  if (( aIndex < 0 ) || ( aIndex > 6 ))
    return 0;

  switch ( aIndex )
  {
    case 0 :
    {
      count = 16;
      type = AcceleratorGraphicsTypeRectFill;
      ViewsText_OnSetString( &_this->ScenarioText, EwLoadString( &_Const0018 ));
    }
    break;

    case 1 :
    {
      count = _this->NoOfRectBlend;

      if ( count <= 0 )
        return 0;

      type = AcceleratorGraphicsTypeRectBlend;
      ViewsText_OnSetString( &_this->ScenarioText, EwLoadString( &_Const0019 ));
    }
    break;

    case 2 :
    {
      count = _this->NoOfRGB565Bmp;

      if ( count <= 0 )
        return 0;

      type = AcceleratorGraphicsTypeRGB565Bmp;
      ViewsText_OnSetString( &_this->ScenarioText, EwLoadString( &_Const001A ));
    }
    break;

    case 3 :
    {
      count = _this->NoOfNativeBmp;

      if ( count <= 0 )
        return 0;

      type = AcceleratorGraphicsTypeNativeBmp;
      ViewsText_OnSetString( &_this->ScenarioText, EwLoadString( &_Const001B ));
    }
    break;

    case 4 :
    {
      count = _this->NoOfRGB565BmpOpacity;

      if ( count <= 0 )
        return 0;

      type = AcceleratorGraphicsTypeRGB565BmpOpacity;
      ViewsText_OnSetString( &_this->ScenarioText, EwLoadString( &_Const001C ));
    }
    break;

    case 5 :
    {
      count = _this->NoOfNativeBmpOpacity;

      if ( count <= 0 )
        return 0;

      type = AcceleratorGraphicsTypeNativeBmpOpacity;
      ViewsText_OnSetString( &_this->ScenarioText, EwLoadString( &_Const001D ));
    }
    break;

    default : 
    {
      count = _this->NoOfAlpha8Bmp;

      if ( count <= 0 )
        return 0;

      type = AcceleratorGraphicsTypeAlpha8Bmp;
      ViewsText_OnSetString( &_this->ScenarioText, EwLoadString( &_Const001E ));
    }
  }

  _this->GraphicsFactory.TypeOfItems = type;
  AcceleratorGraphicsFactory_OnSetNoOfItems( &_this->GraphicsFactory, count );
  return 1;
}

/* Variants derived from the class : 'Accelerator::Accelerator' */
EW_DEFINE_CLASS_VARIANTS( AcceleratorAccelerator )
EW_END_OF_CLASS_VARIANTS( AcceleratorAccelerator )

/* Virtual Method Table (VMT) for the class : 'Accelerator::Accelerator' */
EW_DEFINE_CLASS( AcceleratorAccelerator, CoreGroup, Rectangle, GraphicsSystem, NoOfRectBlend, 
                 NoOfRectBlend, NoOfRectBlend, NoOfRectBlend, "Accelerator::Accelerator" )
  CoreRectView_initLayoutContext,
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
  AcceleratorAccelerator_UpdateLayout,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( AcceleratorAccelerator )

/* Include a file containing the bitmap resource : 'Accelerator::Logo' */
#include "_AcceleratorLogo.h"

/* Table with links to derived variants of the bitmap resource : 'Accelerator::Logo' */
EW_RES_WITHOUT_VARIANTS( AcceleratorLogo )

/* Include a file containing the font resource : 'Accelerator::FontSmall' */
#include "_AcceleratorFontSmall.h"

/* Table with links to derived variants of the font resource : 'Accelerator::FontSmall' */
EW_RES_WITHOUT_VARIANTS( AcceleratorFontSmall )

/* Initializer for the class 'Accelerator::GraphicsFactory' */
void AcceleratorGraphicsFactory__Init( AcceleratorGraphicsFactory _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( AcceleratorGraphicsFactory );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( AcceleratorGraphicsFactory );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const001F );
  _this->NoOfItems = 1;
  _this->TypeOfItems = AcceleratorGraphicsTypeAlpha8Bmp;
  _this->NativeImages[ 0 ] = EwLoadResource( &AcceleratorImgBlend1, ResourcesBitmap );
  _this->NativeImages[ 1 ] = EwLoadResource( &AcceleratorImgBlend2, ResourcesBitmap );
  _this->NativeImages[ 2 ] = EwLoadResource( &AcceleratorImgBlend3, ResourcesBitmap );
  _this->NativeImages[ 3 ] = EwLoadResource( &AcceleratorImgBlend4, ResourcesBitmap );
  _this->NativeImages[ 4 ] = EwLoadResource( &AcceleratorImgBlend5, ResourcesBitmap );
  _this->NativeImages[ 5 ] = EwLoadResource( &AcceleratorImgBlend6, ResourcesBitmap );
  _this->NativeImages[ 6 ] = EwLoadResource( &AcceleratorImgBlend7, ResourcesBitmap );
  _this->RGB565Images[ 0 ] = EwLoadResource( &AcceleratorImgCopy1, ResourcesBitmap );
  _this->RGB565Images[ 1 ] = EwLoadResource( &AcceleratorImgCopy2, ResourcesBitmap );
  _this->RGB565Images[ 2 ] = EwLoadResource( &AcceleratorImgCopy3, ResourcesBitmap );
  _this->RGB565Images[ 3 ] = EwLoadResource( &AcceleratorImgCopy4, ResourcesBitmap );
  _this->RGB565Images[ 4 ] = EwLoadResource( &AcceleratorImgCopy5, ResourcesBitmap );
  _this->EmWiLogo = EwLoadResource( &AcceleratorLogo, ResourcesBitmap );
}

/* Re-Initializer for the class 'Accelerator::GraphicsFactory' */
void AcceleratorGraphicsFactory__ReInit( AcceleratorGraphicsFactory _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Accelerator::GraphicsFactory' */
void AcceleratorGraphicsFactory__Done( AcceleratorGraphicsFactory _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Accelerator::GraphicsFactory.Draw()' */
void AcceleratorGraphicsFactory_Draw( AcceleratorGraphicsFactory _this, GraphicsCanvas 
  aCanvas, XRect aClip, XPoint aOffset, XInt32 aOpacity, XBool aBlend )
{
  XInt32 inx = 0;

  CoreGroup_Draw((CoreGroup)_this, aCanvas, aClip, aOffset, aOpacity, aBlend );
  aOffset = EwMovePointPos( aOffset, _this->Super2.Bounds.Point1 );

  while ( inx < 64 )
  {
    ResourcesBitmap bmp;
    XPoint pos = EwMovePointPos( _this->Position[ EwCheckIndex( inx, 64 )], aOffset );
    XPoint size = _this->Size[ EwCheckIndex( inx, 64 )];
    XColor col = _this->Color[ EwCheckIndex( inx, 64 )];

    if ( _this->Position[ EwCheckIndex( inx, 64 )].Y <= EwGetRectH( _this->Super2.Bounds ))
      switch ( _this->Type[ EwCheckIndex( inx, 64 )])
      {
        case AcceleratorGraphicsTypeRectFill :
        case AcceleratorGraphicsTypeRectBlend :
          GraphicsCanvas_FillRectangle( aCanvas, aClip, EwNewRect2Point( pos, EwMovePointPos( 
          pos, size )), col, col, col, col, aBlend );
        break;

        case AcceleratorGraphicsTypeRGB565Bmp :
        case AcceleratorGraphicsTypeRGB565BmpOpacity :
        {
          bmp = _this->RGB565Images[ EwCheckIndex( inx % 5, 5 )];
          GraphicsCanvas_CopyBitmap( aCanvas, aClip, bmp, 0, EwNewRect2Point( pos, 
          EwMovePointPos( pos, size )), _Const0020, col, col, col, col, aBlend );
        }
        break;

        case AcceleratorGraphicsTypeNativeBmp :
        case AcceleratorGraphicsTypeNativeBmpOpacity :
        {
          bmp = _this->NativeImages[ EwCheckIndex( inx % 7, 7 )];
          GraphicsCanvas_CopyBitmap( aCanvas, aClip, bmp, 0, EwNewRect2Point( pos, 
          EwMovePointPos( pos, size )), _Const0020, col, col, col, col, aBlend );
        }
        break;

        case AcceleratorGraphicsTypeAlpha8Bmp :
        {
          bmp = _this->EmWiLogo;
          GraphicsCanvas_CopyBitmap( aCanvas, aClip, bmp, 0, EwNewRect2Point( pos, 
          EwMovePointPos( pos, size )), _Const0020, col, col, col, col, aBlend );
        }
        break;

        default :; 
      }

    inx = inx + 1;
  }

  EwIdleSignal( EwNewSlot( _this, AcceleratorGraphicsFactory_TriggerNextRedraw ), 
    ((XObject)_this ));
}

/* The method UpdateLayout() is invoked automatically after the size of the component 
   has been changed. This method can be overridden and filled with logic to perform 
   a sophisticated arrangement calculation for one or more enclosed views. In this 
   case the parameter aSize can be used. It contains the current size of the component. 
   Usually, all enclosed views are arranged automatically accordingly to their @Layout 
   property. UpdateLayout() gives the derived components a chance to extend this 
   automatism by a user defined algorithm. */
void AcceleratorGraphicsFactory_UpdateLayout( AcceleratorGraphicsFactory _this, 
  XPoint aSize )
{
  XInt32 inx;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aSize );

  for ( inx = 0; inx < _this->NoOfItems; inx = inx + 1 )
  {
    AcceleratorGraphicsFactory_RandomizeItem( _this, inx );
    _this->Position[ EwCheckIndex( inx, 64 )].Y = EwMathRandInt32( 0, EwGetRectH( 
    _this->Super2.Bounds ) - _this->Size[ EwCheckIndex( inx, 64 )].Y );
  }

  EwIdleSignal( EwNewSlot( _this, AcceleratorGraphicsFactory_TriggerNextRedraw ), 
    ((XObject)_this ));
}

/* 'C' function for method : 'Accelerator::GraphicsFactory.OnSetNoOfItems()' */
void AcceleratorGraphicsFactory_OnSetNoOfItems( AcceleratorGraphicsFactory _this, 
  XInt32 value )
{
  XInt32 inx;

  if ( value < 0 )
    value = 0;

  if ( value > 64 )
    value = 64;

  if ( _this->NoOfItems == value )
    return;

  for ( inx = _this->NoOfItems; inx < value; inx = inx + 1 )
    AcceleratorGraphicsFactory_RandomizeItem( _this, inx );

  _this->NoOfItems = value;
}

/* Slot method to invalidate the entire component. This slot method should be triggered 
   only by using 'idelsignal' in order to ensure that the invalidation happens after 
   the next screen update. */
void AcceleratorGraphicsFactory_TriggerNextRedraw( AcceleratorGraphicsFactory _this, 
  XObject sender )
{
  XInt32 inx;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup__InvalidateArea( _this, EwGetRectORect( _this->Super2.Bounds ));
  inx = 0;

  while ( inx < 64 )
  {
    XPoint size = _this->Size[ EwCheckIndex( inx, 64 )];

    if ( _this->Position[ EwCheckIndex( inx, 64 )].Y <= EwGetRectH( _this->Super2.Bounds ))
    {
      _this->Position[ EwCheckIndex( inx, 64 )] = EwMovePointPos( _this->Position[ 
      EwCheckIndex( inx, 64 )], _this->DeltaPos[ EwCheckIndex( inx, 64 )]);

      if ((( _this->Position[ EwCheckIndex( inx, 64 )].X + size.X ) < 0 ) || ( _this->Position[ 
          EwCheckIndex( inx, 64 )].X > EwGetRectW( _this->Super2.Bounds )))
        _this->Position[ EwCheckIndex( inx, 64 )].Y = ( EwGetRectH( _this->Super2.Bounds ) 
        + 1 );
    }

    if (( _this->Position[ EwCheckIndex( inx, 64 )].Y > EwGetRectH( _this->Super2.Bounds )) 
        && ( inx < _this->NoOfItems ))
      AcceleratorGraphicsFactory_RandomizeItem( _this, inx );

    if (( _this->TypeOfItems == AcceleratorGraphicsTypeRGB565BmpOpacity ) || ( _this->TypeOfItems 
        == AcceleratorGraphicsTypeNativeBmpOpacity ))
    {
      XInt32 alpha = _this->Color[ EwCheckIndex( inx, 64 )].Alpha + _this->DeltaAlpha[ 
        EwCheckIndex( inx, 64 )];

      if ( alpha > 255 )
      {
        alpha = 255;
        _this->DeltaAlpha[ EwCheckIndex( inx, 64 )] = -_this->DeltaAlpha[ EwCheckIndex( 
        inx, 64 )];
      }

      if ( alpha < 0 )
      {
        alpha = 0;
        _this->DeltaAlpha[ EwCheckIndex( inx, 64 )] = -_this->DeltaAlpha[ EwCheckIndex( 
        inx, 64 )];
      }

      _this->Color[ EwCheckIndex( inx, 64 )].Alpha = (XUInt8)alpha;
    }

    inx = inx + 1;
  }
}

/* The method 'RandomizeItem' calculates random values for the graphics object with 
   the given index. */
void AcceleratorGraphicsFactory_RandomizeItem( AcceleratorGraphicsFactory _this, 
  XInt32 aIndex )
{
  XPoint size;

  switch ( _this->TypeOfItems )
  {
    case AcceleratorGraphicsTypeRectFill :
    {
      size = EwNewPoint( EwMathRandInt32( EwGetRectW( _this->Super2.Bounds ) / 3, 
      ( 2 * EwGetRectW( _this->Super2.Bounds )) / 3 ), EwMathRandInt32( EwGetRectH( 
      _this->Super2.Bounds ) / 3, ( 2 * EwGetRectH( _this->Super2.Bounds )) / 3 ));
      _this->Position[ EwCheckIndex( aIndex, 64 )] = EwNewPoint( EwMathRandInt32( 
      0, EwGetRectW( _this->Super2.Bounds ) - size.X ), -size.Y );
      _this->Size[ EwCheckIndex( aIndex, 64 )] = size;
      _this->Color[ EwCheckIndex( aIndex, 64 )] = EwNewColor((XUInt8)EwMathRandInt32( 
      0, 255 ), (XUInt8)EwMathRandInt32( 0, 255 ), (XUInt8)EwMathRandInt32( 0, 255 ), 
      255 );
    }
    break;

    case AcceleratorGraphicsTypeRectBlend :
    {
      size = EwNewPoint( EwMathRandInt32( EwGetRectW( _this->Super2.Bounds ) / 3, 
      ( 2 * EwGetRectW( _this->Super2.Bounds )) / 3 ), EwMathRandInt32( EwGetRectH( 
      _this->Super2.Bounds ) / 3, ( 2 * EwGetRectH( _this->Super2.Bounds )) / 3 ));
      _this->Position[ EwCheckIndex( aIndex, 64 )] = EwNewPoint( EwMathRandInt32( 
      0, EwGetRectW( _this->Super2.Bounds ) - size.X ), -size.Y );
      _this->Size[ EwCheckIndex( aIndex, 64 )] = size;
      _this->Color[ EwCheckIndex( aIndex, 64 )] = EwNewColor((XUInt8)EwMathRandInt32( 
      0, 255 ), (XUInt8)EwMathRandInt32( 0, 255 ), (XUInt8)EwMathRandInt32( 0, 255 ), 
      170 );
    }
    break;

    case AcceleratorGraphicsTypeRGB565Bmp :
    {
      size = _this->RGB565Images[ 0 ]->FrameSize;
      _this->Position[ EwCheckIndex( aIndex, 64 )] = EwNewPoint( EwMathRandInt32( 
      0, EwGetRectW( _this->Super2.Bounds ) - size.X ), -size.Y );
      _this->Size[ EwCheckIndex( aIndex, 64 )] = size;
      _this->Color[ EwCheckIndex( aIndex, 64 )] = _Const000B;
    }
    break;

    case AcceleratorGraphicsTypeNativeBmp :
    {
      size = _this->NativeImages[ 0 ]->FrameSize;
      _this->Position[ EwCheckIndex( aIndex, 64 )] = EwNewPoint( EwMathRandInt32( 
      0, EwGetRectW( _this->Super2.Bounds ) - size.X ), -size.Y );
      _this->Size[ EwCheckIndex( aIndex, 64 )] = size;
      _this->Color[ EwCheckIndex( aIndex, 64 )] = _Const000B;
    }
    break;

    case AcceleratorGraphicsTypeRGB565BmpOpacity :
    {
      size = _this->RGB565Images[ 0 ]->FrameSize;
      _this->Position[ EwCheckIndex( aIndex, 64 )] = EwNewPoint( EwMathRandInt32( 
      0, EwGetRectW( _this->Super2.Bounds ) - size.X ), -size.Y );
      _this->Size[ EwCheckIndex( aIndex, 64 )] = size;
      _this->Color[ EwCheckIndex( aIndex, 64 )] = EwNewColor( 255, 255, 255, (XUInt8)EwMathRandInt32( 
      0, 255 ));
      _this->DeltaAlpha[ EwCheckIndex( aIndex, 64 )] = (XInt8)EwMathRandInt32( -5, 
      5 );
    }
    break;

    case AcceleratorGraphicsTypeNativeBmpOpacity :
    {
      size = _this->NativeImages[ 0 ]->FrameSize;
      _this->Position[ EwCheckIndex( aIndex, 64 )] = EwNewPoint( EwMathRandInt32( 
      0, EwGetRectW( _this->Super2.Bounds ) - size.X ), -size.Y );
      _this->Size[ EwCheckIndex( aIndex, 64 )] = size;
      _this->Color[ EwCheckIndex( aIndex, 64 )] = EwNewColor( 255, 255, 255, (XUInt8)EwMathRandInt32( 
      0, 255 ));
      _this->DeltaAlpha[ EwCheckIndex( aIndex, 64 )] = (XInt8)EwMathRandInt32( -5, 
      5 );
    }
    break;

    case AcceleratorGraphicsTypeAlpha8Bmp :
    {
      size = _this->EmWiLogo->FrameSize;
      _this->Position[ EwCheckIndex( aIndex, 64 )] = EwNewPoint( EwMathRandInt32( 
      0, EwGetRectW( _this->Super2.Bounds ) - size.X ), -size.Y );
      _this->Size[ EwCheckIndex( aIndex, 64 )] = size;
      _this->Color[ EwCheckIndex( aIndex, 64 )] = EwNewColor((XUInt8)EwMathRandInt32( 
      0, 255 ), (XUInt8)EwMathRandInt32( 0, 255 ), (XUInt8)EwMathRandInt32( 0, 255 ), 
      170 );
    }
    break;

    default :; 
  }

  _this->DeltaPos[ EwCheckIndex( aIndex, 64 )] = EwNewPoint( EwMathRandInt32( -2, 
  2 ), EwMathRandInt32( 1, EwGetRectH( _this->Super2.Bounds ) / 40 ));
  _this->Type[ EwCheckIndex( aIndex, 64 )] = _this->TypeOfItems;
}

/* Variants derived from the class : 'Accelerator::GraphicsFactory' */
EW_DEFINE_CLASS_VARIANTS( AcceleratorGraphicsFactory )
EW_END_OF_CLASS_VARIANTS( AcceleratorGraphicsFactory )

/* Virtual Method Table (VMT) for the class : 'Accelerator::GraphicsFactory' */
EW_DEFINE_CLASS( AcceleratorGraphicsFactory, CoreGroup, NativeImages, NativeImages, 
                 Position, Position, Position, Position, "Accelerator::GraphicsFactory" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  AcceleratorGraphicsFactory_Draw,
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
  AcceleratorGraphicsFactory_UpdateLayout,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( AcceleratorGraphicsFactory )

/* Include a file containing the bitmap resource : 'Accelerator::ImgBlend1' */
#include "_AcceleratorImgBlend1.h"

/* Table with links to derived variants of the bitmap resource : 'Accelerator::ImgBlend1' */
EW_RES_WITHOUT_VARIANTS( AcceleratorImgBlend1 )

/* Include a file containing the bitmap resource : 'Accelerator::ImgBlend2' */
#include "_AcceleratorImgBlend2.h"

/* Table with links to derived variants of the bitmap resource : 'Accelerator::ImgBlend2' */
EW_RES_WITHOUT_VARIANTS( AcceleratorImgBlend2 )

/* Include a file containing the bitmap resource : 'Accelerator::ImgBlend3' */
#include "_AcceleratorImgBlend3.h"

/* Table with links to derived variants of the bitmap resource : 'Accelerator::ImgBlend3' */
EW_RES_WITHOUT_VARIANTS( AcceleratorImgBlend3 )

/* Include a file containing the bitmap resource : 'Accelerator::ImgBlend4' */
#include "_AcceleratorImgBlend4.h"

/* Table with links to derived variants of the bitmap resource : 'Accelerator::ImgBlend4' */
EW_RES_WITHOUT_VARIANTS( AcceleratorImgBlend4 )

/* Include a file containing the bitmap resource : 'Accelerator::ImgBlend5' */
#include "_AcceleratorImgBlend5.h"

/* Table with links to derived variants of the bitmap resource : 'Accelerator::ImgBlend5' */
EW_RES_WITHOUT_VARIANTS( AcceleratorImgBlend5 )

/* Include a file containing the bitmap resource : 'Accelerator::ImgBlend6' */
#include "_AcceleratorImgBlend6.h"

/* Table with links to derived variants of the bitmap resource : 'Accelerator::ImgBlend6' */
EW_RES_WITHOUT_VARIANTS( AcceleratorImgBlend6 )

/* Include a file containing the bitmap resource : 'Accelerator::ImgBlend7' */
#include "_AcceleratorImgBlend7.h"

/* Table with links to derived variants of the bitmap resource : 'Accelerator::ImgBlend7' */
EW_RES_WITHOUT_VARIANTS( AcceleratorImgBlend7 )

/* Include a file containing the bitmap resource : 'Accelerator::ImgCopy1' */
#include "_AcceleratorImgCopy1.h"

/* Table with links to derived variants of the bitmap resource : 'Accelerator::ImgCopy1' */
EW_RES_WITHOUT_VARIANTS( AcceleratorImgCopy1 )

/* Include a file containing the bitmap resource : 'Accelerator::ImgCopy2' */
#include "_AcceleratorImgCopy2.h"

/* Table with links to derived variants of the bitmap resource : 'Accelerator::ImgCopy2' */
EW_RES_WITHOUT_VARIANTS( AcceleratorImgCopy2 )

/* Include a file containing the bitmap resource : 'Accelerator::ImgCopy3' */
#include "_AcceleratorImgCopy3.h"

/* Table with links to derived variants of the bitmap resource : 'Accelerator::ImgCopy3' */
EW_RES_WITHOUT_VARIANTS( AcceleratorImgCopy3 )

/* Include a file containing the bitmap resource : 'Accelerator::ImgCopy4' */
#include "_AcceleratorImgCopy4.h"

/* Table with links to derived variants of the bitmap resource : 'Accelerator::ImgCopy4' */
EW_RES_WITHOUT_VARIANTS( AcceleratorImgCopy4 )

/* Include a file containing the bitmap resource : 'Accelerator::ImgCopy5' */
#include "_AcceleratorImgCopy5.h"

/* Table with links to derived variants of the bitmap resource : 'Accelerator::ImgCopy5' */
EW_RES_WITHOUT_VARIANTS( AcceleratorImgCopy5 )

/* Include a file containing the font resource : 'Accelerator::FontMedium' */
#include "_AcceleratorFontMedium.h"

/* Table with links to derived variants of the font resource : 'Accelerator::FontMedium' */
EW_RES_WITHOUT_VARIANTS( AcceleratorFontMedium )

/* Embedded Wizard */
