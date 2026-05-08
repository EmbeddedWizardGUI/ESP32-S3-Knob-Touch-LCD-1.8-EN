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

#ifndef _CoreCursorEvent_H
#define _CoreCursorEvent_H

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

#include "_CoreEvent.h"

/* Forward declaration of the class Core::CursorEvent */
#ifndef _CoreCursorEvent_
  EW_DECLARE_CLASS( CoreCursorEvent )
#define _CoreCursorEvent_
#endif


/* The class Core::CursorEvent provides a specialized event object able to deliver 
   touch screen pressure and release events. Each time the user clicks with the 
   mouse cursor on the screen, hits it with a pen or touches it with his finger, 
   a cursor event is prepared and dispatched to the view which is willing to handle 
   it. See the method DriveCursorHitting() of the class Core::Root.
   The event contains information about the position where the user has tapped (@HittingPos 
   and @CurrentPos), whether the user has pressed or released the finger (@Down), 
   how often has the user tapped at the same position (@StrikeCount), etc.
   The dispatching of cursor events will always take place in so called 'grab cycles'. 
   A grab cycle starts when the user touches the screen and exists until the user 
   has released it. At the beginning the framework determines the view which is 
   lying at the touched position and is willing to receive cursor events. This view 
   will become the target for all following events while this grab cycle -> the 
   view 'grabs' the cursor for this time.
   Afterwards the target view will receive the first Core::CursorEvent with its 
   variable @Down == 'true'. At the end of the grab cycle, after the user has released 
   the finger, the target view will receive the last Core::CursorEvent with the 
   variable @Down == 'false'. In the meantime the framework will feed the target 
   view with more events: the hold and the drag events.
   The hold events are generated periodically in constant intervals. They store 
   the current cursor position and the time since the grab cycle began @HoldPeriod. 
   Please note, these hold events are sent with the variable @Down == 'true'. In 
   order to distinguish between the first event and the following hold events, the 
   @HoldPeriod variable should be evaluated.
   Beside the hold events, the target view will also receive drag events as soon 
   as the user strokes the screen. This is communicated by events of the class Core::DragEvent. */
EW_DEFINE_FIELDS( CoreCursorEvent, CoreEvent )
  EW_VARIABLE( GlobalHittingPos, XPoint )
  EW_VARIABLE( GlobalCurrentPos, XPoint )
  EW_VARIABLE( StrikeCount,     XInt32 )
  EW_VARIABLE( HoldPeriod,      XInt32 )
  EW_VARIABLE( HittingPos,      XPoint )
  EW_VARIABLE( CurrentPos,      XPoint )
  EW_VARIABLE( Finger,          XInt32 )
  EW_VARIABLE( AutoDeflected,   XBool )
  EW_VARIABLE( Down,            XBool )
EW_END_OF_FIELDS( CoreCursorEvent )

/* Virtual Method Table (VMT) for the class : 'Core::CursorEvent' */
EW_DEFINE_METHODS( CoreCursorEvent, CoreEvent )
EW_END_OF_METHODS( CoreCursorEvent )

/* The method InitializeHold() simplifies the initialization of this Core::CursorEvent 
   object. This method stores the given parameters in the variables of this event 
   object, sets its variable @Down 'true' and returns this event object to the caller. */
CoreCursorEvent CoreCursorEvent_InitializeHold( CoreCursorEvent _this, XInt32 aFinger, 
  XPoint aCurrentPos, XPoint aHittingPos, XInt32 aHoldPeriod, XInt32 aStrikeCount, 
  XPoint aHitOffset, XPoint aGlobalCurrentPos, XPoint aGlobalHittingPos );

/* Wrapper function for the non virtual method : 'Core::CursorEvent.InitializeHold()' */
CoreCursorEvent CoreCursorEvent__InitializeHold( void* _this, XInt32 aFinger, XPoint 
  aCurrentPos, XPoint aHittingPos, XInt32 aHoldPeriod, XInt32 aStrikeCount, XPoint 
  aHitOffset, XPoint aGlobalCurrentPos, XPoint aGlobalHittingPos );

/* The following define announces the presence of the method Core::CursorEvent.InitializeHold(). */
#define _CoreCursorEvent__InitializeHold_

/* The method InitializeUp() simplifies the initialization of this Core::CursorEvent 
   object. This method stores the given parameters in the variables of this event 
   object, sets its variable @Down 'false' and returns this event object to the 
   caller. */
CoreCursorEvent CoreCursorEvent_InitializeUp( CoreCursorEvent _this, XInt32 aFinger, 
  XPoint aCurrentPos, XPoint aHittingPos, XInt32 aHoldPeriod, XInt32 aStrikeCount, 
  XPoint aHitOffset, XBool aAutoDeflected, XPoint aGlobalCurrentPos, XPoint aGlobalHittingPos );

/* Wrapper function for the non virtual method : 'Core::CursorEvent.InitializeUp()' */
CoreCursorEvent CoreCursorEvent__InitializeUp( void* _this, XInt32 aFinger, XPoint 
  aCurrentPos, XPoint aHittingPos, XInt32 aHoldPeriod, XInt32 aStrikeCount, XPoint 
  aHitOffset, XBool aAutoDeflected, XPoint aGlobalCurrentPos, XPoint aGlobalHittingPos );

/* The following define announces the presence of the method Core::CursorEvent.InitializeUp(). */
#define _CoreCursorEvent__InitializeUp_

/* The method InitializeDown() simplifies the initialization of this Core::CursorEvent 
   object. This method stores the given parameters in the variables of this event 
   object, sets its variable @Down 'true' and returns this event object to the caller. */
CoreCursorEvent CoreCursorEvent_InitializeDown( CoreCursorEvent _this, XInt32 aFinger, 
  XPoint aCurrentPos, XInt32 aStrikeCount, XPoint aHitOffset, XBool aAutoDeflected, 
  XPoint aGlobalCurrentPos );

/* Wrapper function for the non virtual method : 'Core::CursorEvent.InitializeDown()' */
CoreCursorEvent CoreCursorEvent__InitializeDown( void* _this, XInt32 aFinger, XPoint 
  aCurrentPos, XInt32 aStrikeCount, XPoint aHitOffset, XBool aAutoDeflected, XPoint 
  aGlobalCurrentPos );

/* The following define announces the presence of the method Core::CursorEvent.InitializeDown(). */
#define _CoreCursorEvent__InitializeDown_

#ifdef __cplusplus
  }
#endif

#endif /* _CoreCursorEvent_H */

/* Embedded Wizard */
