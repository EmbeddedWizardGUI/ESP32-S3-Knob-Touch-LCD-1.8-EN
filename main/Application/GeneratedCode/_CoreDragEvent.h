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

#ifndef _CoreDragEvent_H
#define _CoreDragEvent_H

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

/* Forward declaration of the class Core::DragEvent */
#ifndef _CoreDragEvent_
  EW_DECLARE_CLASS( CoreDragEvent )
#define _CoreDragEvent_
#endif


/* The class Core::DragEvent provides a specialized event object able to deliver 
   drag events. These events are sent when the user has touched the screen and then 
   moved the finger. See the method DriveCursorMovement() of the class Core::Root.
   The event contains information about the position where the user has tapped (@HittingPos), 
   the current position after the drag operation (@CurrentPos), the displacement 
   since the last drag event (@Offset), etc.
   The drag events are sent together with the cursor events Core::CursorEvent. */
EW_DEFINE_FIELDS( CoreDragEvent, CoreEvent )
  EW_VARIABLE( GlobalHittingPos, XPoint )
  EW_VARIABLE( GlobalCurrentPos, XPoint )
  EW_VARIABLE( StrikeCount,     XInt32 )
  EW_VARIABLE( HoldPeriod,      XInt32 )
  EW_VARIABLE( Offset,          XPoint )
  EW_VARIABLE( HittingPos,      XPoint )
  EW_VARIABLE( CurrentPos,      XPoint )
  EW_VARIABLE( Finger,          XInt32 )
EW_END_OF_FIELDS( CoreDragEvent )

/* Virtual Method Table (VMT) for the class : 'Core::DragEvent' */
EW_DEFINE_METHODS( CoreDragEvent, CoreEvent )
EW_END_OF_METHODS( CoreDragEvent )

/* The method Initialize() simplifies the initialization of this Core::DragEvent 
   object. This method stores the given parameters in the variables of this event 
   object and returns this event object to the caller. */
CoreDragEvent CoreDragEvent_Initialize( CoreDragEvent _this, XInt32 aFinger, XPoint 
  aCurrentPos, XPoint aHittingPos, XPoint aOffset, XInt32 aHoldPeriod, XInt32 aSequelCount, 
  XPoint aHitOffset, XPoint aGlobalCurrentPos, XPoint aGlobalHittingPos );

/* Wrapper function for the non virtual method : 'Core::DragEvent.Initialize()' */
CoreDragEvent CoreDragEvent__Initialize( void* _this, XInt32 aFinger, XPoint aCurrentPos, 
  XPoint aHittingPos, XPoint aOffset, XInt32 aHoldPeriod, XInt32 aSequelCount, XPoint 
  aHitOffset, XPoint aGlobalCurrentPos, XPoint aGlobalHittingPos );

/* The following define announces the presence of the method Core::DragEvent.Initialize(). */
#define _CoreDragEvent__Initialize_

#ifdef __cplusplus
  }
#endif

#endif /* _CoreDragEvent_H */

/* Embedded Wizard */
