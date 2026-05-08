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

#ifndef Views_H
#define Views_H

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

#include "_ViewsFrame.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"

/* The definition Views::ImageAlignment determines the set of constraints to apply 
   on a bitmap if its size differ from the size of the view where the bitmap is 
   shown. Depending on the active constraints a bitmap can be aligned or stretched 
   within the view's area. */
typedef XSet ViewsImageAlignment;

#define ViewsImageAlignmentAlignHorzLeft                    0x00000001
#define ViewsImageAlignmentAlignHorzCenter                  0x00000002
#define ViewsImageAlignmentAlignHorzRight                   0x00000004
#define ViewsImageAlignmentAlignVertTop                     0x00000008
#define ViewsImageAlignmentAlignVertCenter                  0x00000010
#define ViewsImageAlignmentAlignVertBottom                  0x00000020
#define ViewsImageAlignmentScaleToFill                      0x00000040
#define ViewsImageAlignmentScaleToFit                       0x00000080
#define ViewsImageAlignmentStretchToFill                    0x00000100

/* The definition Views::TextAlignment determines the set of constraints to apply 
   on text rows and blocks if their size differ from the size of the view where 
   the text is shown. Depending on the active constraints the text rows can be aligned 
   horizontally and text blocks vertically. */
typedef XSet ViewsTextAlignment;

#define ViewsTextAlignmentAlignHorzLeft                     0x00000001
#define ViewsTextAlignmentAlignHorzCenter                   0x00000002
#define ViewsTextAlignmentAlignHorzRight                    0x00000004
#define ViewsTextAlignmentAlignVertTop                      0x00000008
#define ViewsTextAlignmentAlignVertCenter                   0x00000010
#define ViewsTextAlignmentAlignVertBottom                   0x00000020
#define ViewsTextAlignmentAlignHorzJustified                0x00000040
#define ViewsTextAlignmentAlignHorzAuto                     0x00000080
#define ViewsTextAlignmentAlignVertCenterBaseline           0x00000100

/* The definition Views::Orientation determines the possible options to control 
   the orientation of the content displayed in the Views::Image, Views::Group and 
   Views::Text views. Depending on the selected option the view displays the content 
   rotated. */
typedef XEnum ViewsOrientation;

#define ViewsOrientationNormal                              0
#define ViewsOrientationRotated_90                          1
#define ViewsOrientationRotated_180                         2
#define ViewsOrientationRotated_270                         3

#ifdef __cplusplus
  }
#endif

#endif /* Views_H */

/* Embedded Wizard */
