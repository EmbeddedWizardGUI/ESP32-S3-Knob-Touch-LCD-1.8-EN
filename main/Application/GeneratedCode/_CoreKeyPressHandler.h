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

#ifndef _CoreKeyPressHandler_H
#define _CoreKeyPressHandler_H

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

/* Forward declaration of the class Core::KeyEvent */
#ifndef _CoreKeyEvent_
  EW_DECLARE_CLASS( CoreKeyEvent )
#define _CoreKeyEvent_
#endif

/* Forward declaration of the class Core::KeyPressHandler */
#ifndef _CoreKeyPressHandler_
  EW_DECLARE_CLASS( CoreKeyPressHandler )
#define _CoreKeyPressHandler_
#endif


/* The class Core::KeyPressHandler provides a universal keyboard event handler able 
   to process key press and release events. It compares the received key codes with 
   the value of the property @Filter and if the codes do match the filter condition, 
   sends signals to the slot methods stored in the @OnPress, @OnHold and @OnRelease 
   properties.
   Keyboard handlers can be created at the design time only. You can simply drag-and-drop 
   them from the Embedded Wizard Gallery into the Composer window where you are 
   editing the GUI component. If necessary several keyboard handlers can be added 
   to the component. For example, one handler can react to the 'Enter' key and the 
   other to the 'Exit' key. The order in which the handlers will process the events 
   corresponds to their Z-order. You can verify and modify this Z-order in the Embedded 
   Wizard Inspector. Please note, keyboard handlers created at the runtime with 
   the Chora 'new' operator will not work!
   The handler provides several variables with details of the received keyboard 
   event, like the key code (@Code or @CharCode), whether the user has pressed or 
   released the key (@Down), etc. These variables can be evaluated in the implementation 
   of the slot method.
   The property @Enabled can be used to activate/deactivate the keyboard handler. 
   Disabled handler will not react to the events. */
EW_DEFINE_FIELDS( CoreKeyPressHandler, XObject )
  EW_VARIABLE( next,            CoreKeyPressHandler )
  EW_PROPERTY( OnPress,         XSlot )
  EW_PROPERTY( OnHold,          XSlot )
  EW_VARIABLE( pressCounter,    XInt32 )
  EW_VARIABLE( Time,            XUInt32 )
  EW_VARIABLE( Code,            XEnum )
  EW_VARIABLE( RepetitionCount, XInt32 )
  EW_PROPERTY( Filter,          XEnum )
  EW_VARIABLE( CharCode,        XChar )
  EW_VARIABLE( Repetition,      XBool )
  EW_VARIABLE( Down,            XBool )
EW_END_OF_FIELDS( CoreKeyPressHandler )

/* Virtual Method Table (VMT) for the class : 'Core::KeyPressHandler' */
EW_DEFINE_METHODS( CoreKeyPressHandler, XObject )
EW_END_OF_METHODS( CoreKeyPressHandler )

/* 'C' function for method : 'Core::KeyPressHandler.Init()' */
void CoreKeyPressHandler_Init( CoreKeyPressHandler _this, XHandle aArg );

/* 'C' function for method : 'Core::KeyPressHandler.HandleEvent()' */
XBool CoreKeyPressHandler_HandleEvent( CoreKeyPressHandler _this, CoreKeyEvent aEvent );

#ifdef __cplusplus
  }
#endif

#endif /* _CoreKeyPressHandler_H */

/* Embedded Wizard */
