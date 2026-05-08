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

#ifndef Application_H
#define Application_H

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

#include "_ApplicationApplication.h"
#include "_ApplicationControlBar.h"
#include "_ApplicationDeviceClass.h"
#include "_ApplicationDoneMessage.h"
#include "_ApplicationProgressIndicator.h"
#include "_ApplicationTimerConfigure.h"

/* Bitmap resource : 'Application::BackgroundChop' */
EW_DECLARE_BITMAP_RES( ApplicationBackgroundChop )

/* Bitmap resource : 'Application::BackgroundCrush' */
EW_DECLARE_BITMAP_RES( ApplicationBackgroundCrush )

/* Bitmap resource : 'Application::BackgroundWhip' */
EW_DECLARE_BITMAP_RES( ApplicationBackgroundWhip )

/* Bitmap resource : 'Application::BackgroundShake' */
EW_DECLARE_BITMAP_RES( ApplicationBackgroundShake )

/* Bitmap resource : 'Application::BackgroundStir' */
EW_DECLARE_BITMAP_RES( ApplicationBackgroundStir )

/* Bitmap resource : 'Application::BackgroundStrain' */
EW_DECLARE_BITMAP_RES( ApplicationBackgroundStrain )

/* Bitmap resource : 'Application::IconChop' */
EW_DECLARE_BITMAP_RES( ApplicationIconChop )

/* Bitmap resource : 'Application::IconCrush' */
EW_DECLARE_BITMAP_RES( ApplicationIconCrush )

/* Bitmap resource : 'Application::IconFroth' */
EW_DECLARE_BITMAP_RES( ApplicationIconFroth )

/* Bitmap resource : 'Application::IconShake' */
EW_DECLARE_BITMAP_RES( ApplicationIconShake )

/* Bitmap resource : 'Application::IconStir' */
EW_DECLARE_BITMAP_RES( ApplicationIconStir )

/* Bitmap resource : 'Application::IconStrain' */
EW_DECLARE_BITMAP_RES( ApplicationIconStrain )

/* Bitmap resource : 'Application::CircleOuterFill' */
EW_DECLARE_BITMAP_RES( ApplicationCircleOuterFill )

/* Bitmap resource : 'Application::SelectedFill' */
EW_DECLARE_BITMAP_RES( ApplicationSelectedFill )

/* Bitmap resource : 'Application::CircleInnerFill' */
EW_DECLARE_BITMAP_RES( ApplicationCircleInnerFill )

/* Bitmap resource : 'Application::IconArrow' */
EW_DECLARE_BITMAP_RES( ApplicationIconArrow )

/* Bitmap resource : 'Application::IconPlayPause' */
EW_DECLARE_BITMAP_RES( ApplicationIconPlayPause )

/* Large font for timer display (108px = 2x FontExtraLarge) */
EW_DECLARE_FONT_RES( ApplicationFontTimer )

/* Font for done message title */
EW_DECLARE_FONT_RES( ApplicationFontDoneTitle )

/* Bold font for done message subtitle */
EW_DECLARE_FONT_RES( ApplicationFontDoneBold )

/* Bitmap resource : 'Application::BackgroundChopDark' */
EW_DECLARE_BITMAP_RES( ApplicationBackgroundChopDark )

/* Bitmap resource : 'Application::BackgroundCrushDark' */
EW_DECLARE_BITMAP_RES( ApplicationBackgroundCrushDark )

/* Bitmap resource : 'Application::BackgroundWhipDark' */
EW_DECLARE_BITMAP_RES( ApplicationBackgroundWhipDark )

/* Bitmap resource : 'Application::BackgroundShakeDark' */
EW_DECLARE_BITMAP_RES( ApplicationBackgroundShakeDark )

/* Bitmap resource : 'Application::BackgroundStirDark' */
EW_DECLARE_BITMAP_RES( ApplicationBackgroundStirDark )

/* Bitmap resource : 'Application::BackgroundStrainDark' */
EW_DECLARE_BITMAP_RES( ApplicationBackgroundStrainDark )

/* State machine phases for the timer workflow */
typedef XEnum ApplicationTimerStateEnum;

#define ApplicationTimerStateEnumIdle                       0
#define ApplicationTimerStateEnumSetting                    1
#define ApplicationTimerStateEnumRunning                    2
#define ApplicationTimerStateEnumDone                       3

/* Global instance of the device interface */
EW_DECLARE_AUTOOBJECT( ApplicationDevice, ApplicationDeviceClass )

#ifdef __cplusplus
  }
#endif

#endif /* Application_H */

/* Embedded Wizard */
