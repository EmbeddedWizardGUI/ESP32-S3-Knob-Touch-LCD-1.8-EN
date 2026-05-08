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

#ifndef _WidgetSetToggleButtonConfig_H
#define _WidgetSetToggleButtonConfig_H

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

#include "_WidgetSetWidgetConfig.h"

/* Forward declaration of the class Resources::Bitmap */
#ifndef _ResourcesBitmap_
  EW_DECLARE_CLASS( ResourcesBitmap )
#define _ResourcesBitmap_
#endif

/* Forward declaration of the class Resources::Font */
#ifndef _ResourcesFont_
  EW_DECLARE_CLASS( ResourcesFont )
#define _ResourcesFont_
#endif

/* Forward declaration of the class WidgetSet::ToggleButtonConfig */
#ifndef _WidgetSetToggleButtonConfig_
  EW_DECLARE_CLASS( WidgetSetToggleButtonConfig )
#define _WidgetSetToggleButtonConfig_
#endif


/* This class implements the functionality permitting you to simply customize the 
   look and feel of a bistable 'toggle button' widget (WidgetSet::ToggleButton). 
   In the practice, you will create an instance of this class, configure its properties 
   with bitmaps, colors and other relevant attributes according to your design expectations 
   and assign such prepared configuration object to the property 'Appearance' of 
   every affected toggle button widget. Thereupon the widgets will use the configuration 
   information provided in the object.
   During its lifetime the button remains always in one of the four states: 'disabled', 
   'default', 'focused' and 'active'. The state 'disabled' is true for every not 
   available button (the property 'Enabled' of the button is 'false'). Such buttons 
   will ignore all user inputs. The state 'default' determines a button, which is 
   ready to be touched by the user or ready to become focused. As soon as the button 
   becomes focused, it switches in the state 'focused'. In this state the user can 
   activate the button by pressing a key on the keyboard. Finally, the state 'active' 
   is true, if the user actually interacts with the button (the button is pressed). 
   At the same time, the toggle button distinguishes between two further states: 
   'on' (checked) and 'off' (unchecked). With the configuration object you can specify 
   the appearance of the button for every state combination individually. For this 
   purpose you should know from which views the button is composed of:
   - 'FaceImage' is a bitmap frame view (Views::Frame) filling per default the entire 
   background of the button unless the area is reduced by using the properties @FaceMarginBottom, 
   @FaceMarginLeft, @FaceMarginRight, @FaceMarginTop. The position can additionally 
   be adjusted for each state individually (@CommonOffOffsetActive, @CommonOffOffsetDefault, 
   @CommonOffOffsetDisabled, @CommonOffOffsetFocused, @CommonOnOffsetActive, @CommonOnOffsetDefault, 
   @CommonOnOffsetDisabled, @CommonOnOffsetFocused). In the configuration object 
   you can individually specify for every button state combination the desired bitmap 
   (@FaceOffBitmapActive, @FaceOffBitmapDefault, @FaceOffBitmapDisabled, @FaceOffBitmapFocused, 
   @FaceOnBitmapActive, @FaceOnBitmapDefault, @FaceOnBitmapDisabled, @FaceOnBitmapFocused), 
   the frame number within the bitmap (@FaceOffFrameActive, @FaceOffFrameDefault, 
   @FaceOffFrameDisabled, @FaceOffFrameFocused, @FaceOnFrameActive, @FaceOnFrameDefault, 
   @FaceOnFrameDisabled, @FaceOnFrameFocused) and opacity or color to tint the bitmap 
   (@FaceOffTintActive, @FaceOffTintDefault, @FaceOffTintDisabled, @FaceOffTintFocused, 
   @FaceOnTintActive, @FaceOnTintDefault, @FaceOnTintDisabled, @FaceOnTintFocused). 
   The button can automatically play animated bitmaps if the corresponding frame 
   number is -1. If desired, with the property @FaceLayout you can also configure 
   the bitmap to be arranged horizontally and vertically instead of filling the 
   entire widget area.
   - 'ThumbRectangle' is a rectangle view (Views::Rectangle) filling per default 
   the entire area of the button unless other constraints (@ThumbLayout), a size 
   alternation (@ThumbOffSizeActive, @ThumbOffSizeDefault, @ThumbOffSizeDisabled, 
   @ThumbOffSizeFocused, @ThumbOnSizeActive, @ThumbOnSizeDefault, @ThumbOnSizeDisabled, 
   @ThumbOnSizeFocused) or a displacement (@ThumbOffOffsetActive, @ThumbOffOffsetDefault, 
   @ThumbOffOffsetDisabled, @ThumbOffOffsetFocused, @ThumbOnOffsetActive, @ThumbOnOffsetDefault, 
   @ThumbOnOffsetDisabled, @ThumbOnOffsetFocused) have been specified. Normally, 
   the thumb has rectangular shape with sharp corners. If desired the corners can 
   be rounded (@ThumbOffCornerRadiusActive, @ThumbOffCornerRadiusDefault, @ThumbOffCornerRadiusDisabled, 
   @ThumbOffCornerRadiusFocused, @ThumbOnCornerRadiusActive, @ThumbOnCornerRadiusDefault, 
   @ThumbOnCornerRadiusDisabled, @ThumbOnCornerRadiusFocused). The thumb can be 
   filled with a solid color (@ThumbOffColorActive, @ThumbOffColorDefault, @ThumbOffColorDisabled, 
   @ThumbOffColorFocused, @ThumbOnColorActive, @ThumbOnColorDefault, @ThumbOnColorDisabled, 
   @ThumbOnColorFocused).
   - 'ThumbBorder' is a border view (Views::Border) surrounding the above described 
   'ThumbRectangle' and lying in front of it. Its size, position and corner radius 
   correspond thus to the of the 'ThumbRectangle'. The thickness of the border (@ThumbOffBorderWidthActive, 
   @ThumbOffBorderWidthDefault, @ThumbOffBorderWidthDisabled, @ThumbOffBorderWidthFocused, 
   @ThumbOnBorderWidthActive, @ThumbOnBorderWidthDefault, @ThumbOnBorderWidthDisabled, 
   @ThumbOnBorderWidthFocused) and its color (@ThumbOffBorderColorActive, @ThumbOffBorderColorDefault, 
   @ThumbOffBorderColorDisabled, @ThumbOffBorderColorFocused, @ThumbOnBorderColorActive, 
   @ThumbOnBorderColorDefault, @ThumbOnBorderColorDisabled, @ThumbOnBorderColorFocused) 
   can be specified.
   - 'ThumbShadow' is a shadow view (Views::Shadow) lying always behind the above 
   described 'ThumbRectangle' view. Its size, position and corner radius correspond 
   thus to the of the 'ThumbRectangle'. However, an additional displacement for 
   the shadow can be specified (@ThumbOffShadowOffsetActive, @ThumbOffShadowOffsetDefault, 
   @ThumbOffShadowOffsetDisabled, @ThumbOffShadowOffsetFocused, @ThumbOnShadowOffsetActive, 
   @ThumbOnShadowOffsetDefault, @ThumbOnShadowOffsetDisabled, @ThumbOnShadowOffsetFocused). 
   The color of the shadow (@ThumbOffShadowColorActive, @ThumbOffShadowColorDefault, 
   @ThumbOffShadowColorDisabled, @ThumbOffShadowColorFocused, @ThumbOnShadowColorActive, 
   @ThumbOnShadowColorDefault, @ThumbOnShadowColorDisabled, @ThumbOnShadowColorFocused) 
   as well as its blur radius (@ThumbOffShadowBlurRadiusActive, @ThumbOffShadowBlurRadiusDefault, 
   @ThumbOffShadowBlurRadiusDisabled, @ThumbOffShadowBlurRadiusFocused, @ThumbOnShadowBlurRadiusActive, 
   @ThumbOnShadowBlurRadiusDefault, @ThumbOnShadowBlurRadiusDisabled, @ThumbOnShadowBlurRadiusFocused) 
   can be specified.
   - 'TrackRectangle' is a rectangle view (Views::Rectangle) filling per default 
   the entire area of the button unless other constraints (@TrackLayout), a size 
   alternation (@TrackSize) or a displacement (@TrackOffset) have been specified. 
   Normally, the track has rectangular shape with sharp corners. If desired the 
   corners can be rounded (@TrackCornerRadius). The track can be filled with a solid 
   color (@TrackOffColorActive, @TrackOffColorDefault, @TrackOffColorDisabled, @TrackOffColorFocused, 
   @TrackOnColorActive, @TrackOnColorDefault, @TrackOnColorDisabled, @TrackOnColorFocused). 
   Track usually serves to visualize the area where thumb is moved and it is usually 
   arranged behind the thumb.
   - 'TrackBorder' is a border view (Views::Border) surrounding the above described 
   'TrackRectangle' and lying in front of it. Its size, position and corner radius 
   correspond thus to the of the 'TrackRectangle'. The thickness of the border (@TrackOffBorderWidthActive, 
   @TrackOffBorderWidthDefault, @TrackOffBorderWidthDisabled, @TrackOffBorderWidthFocused, 
   @TrackOnBorderWidthActive, @TrackOnBorderWidthDefault, @TrackOnBorderWidthDisabled, 
   @TrackOnBorderWidthFocused) and its color (@TrackOffBorderColorActive, @TrackOffBorderColorDefault, 
   @TrackOffBorderColorDisabled, @TrackOffBorderColorFocused, @TrackOnBorderColorActive, 
   @TrackOnBorderColorDefault, @TrackOnBorderColorDisabled, @TrackOnBorderColorFocused) 
   can be specified. Track usually serves to visualize the area where thumb is moved 
   and it is usually arranged behind the thumb.
   - 'AccentRectangle' is a rectangle view (Views::Rectangle) filling per default 
   the entire area of the button unless other constraints (@AccentLayout), a size 
   alternation (@AccentOffSizeActive, @AccentOffSizeDefault, @AccentOffSizeDisabled, 
   @AccentOffSizeFocused, @AccentOnSizeActive, @AccentOnSizeDefault, @AccentOnSizeDisabled, 
   @AccentOnSizeFocused) or a displacement (@AccentOffOffsetActive, @AccentOffOffsetDefault, 
   @AccentOffOffsetDisabled, @AccentOffOffsetFocused, @AccentOnOffsetActive, @AccentOnOffsetDefault, 
   @AccentOnOffsetDisabled, @AccentOnOffsetFocused) have been specified. Normally, 
   the accent area has rectangular shape with sharp corners. If desired the corners 
   can be rounded (@AccentOffCornerRadiusActive, @AccentOffCornerRadiusDefault, 
   @AccentOffCornerRadiusDisabled, @AccentOffCornerRadiusFocused, @AccentOnCornerRadiusActive, 
   @AccentOnCornerRadiusDefault, @AccentOnCornerRadiusDisabled, @AccentOnCornerRadiusFocused). 
   The accent area can be filled with a solid color (@AccentOffColorActive, @AccentOffColorDefault, 
   @AccentOffColorDisabled, @AccentOffColorFocused, @AccentOnColorActive, @AccentOnColorDefault, 
   @AccentOnColorDisabled, @AccentOnColorFocused). Accent usually serves to highlight 
   the widget when the user interacts with it actively or when the widget is focused.
   - 'AccentBorder' is a border view (Views::Border) surrounding the above described 
   'AccentRectangle' and lying in front of it. Its size, position and corner radius 
   correspond thus to the of the 'AccentRectangle'. The thickness of the border 
   (@AccentOffBorderWidthActive, @AccentOffBorderWidthDefault, @AccentOffBorderWidthDisabled, 
   @AccentOffBorderWidthFocused, @AccentOnBorderWidthActive, @AccentOnBorderWidthDefault, 
   @AccentOnBorderWidthDisabled, @AccentOnBorderWidthFocused) and its color (@AccentOffBorderColorActive, 
   @AccentOffBorderColorDefault, @AccentOffBorderColorDisabled, @AccentOffBorderColorFocused, 
   @AccentOnBorderColorActive, @AccentOnBorderColorDefault, @AccentOnBorderColorDisabled, 
   @AccentOnBorderColorFocused) can be specified. Accent usually serves to highlight 
   the widget when the user interacts with it actively or when the widget is focused.
   - 'Icon' is an image view (Views::Image) displayed per default in the center 
   of the button. The corresponding bitmap is determined in the property 'Icon' 
   in the toggle button widget. In the configuration object you can specify the 
   alignment (@IconAlignment) and margins (@IconMarginBottom, @IconMarginLeft, @IconMarginRight, 
   @IconMarginTop) how to arrange the 'Icon' bitmap within the button area. The 
   position can additionally be adjusted for each state individually (@CommonOffOffsetActive, 
   @CommonOffOffsetDefault, @CommonOffOffsetDisabled, @CommonOffOffsetFocused, @CommonOnOffsetActive, 
   @CommonOnOffsetDefault, @CommonOnOffsetDisabled, @CommonOnOffsetFocused). Furthermore, 
   for every button state combination the opacity or color to tint the bitmap can 
   be determined (@IconOffTintActive, @IconOffTintDefault, @IconOffTintDisabled, 
   @IconOffTintFocused, @IconOnTintActive, @IconOnTintDefault, @IconOnTintDisabled, 
   @IconOnTintFocused).
   - 'Label' is a text view (Views::Text) displayed per default in the center of 
   the button. The corresponding text is determined in the property 'LabelOff' or 
   'LabelOn' in the toggle button widget. In the configuration object you can specify 
   the font (@LabelOffFont, @LabelOnFont), alignment (@LabelAlignment) and margins 
   (@LabelMarginBottom, @LabelMarginLeft, @LabelMarginRight, @LabelMarginTop) to 
   use for the text view. The position can additionally be adjusted for each state 
   individually (@CommonOffOffsetActive, @CommonOffOffsetDefault, @CommonOffOffsetDisabled, 
   @CommonOffOffsetFocused, @CommonOnOffsetActive, @CommonOnOffsetDefault, @CommonOnOffsetDisabled, 
   @CommonOnOffsetFocused). For every button state combination you can specify individual 
   text color values (@LabelOffColorActive, @LabelOffColorDefault, @LabelOffColorDisabled, 
   @LabelOffColorFocused, @LabelOnColorActive, @LabelOnColorDefault, @LabelOnColorDisabled, 
   @LabelOnColorFocused).
   All above mentioned views are arranged one above the other whereby the resulting 
   stacking order can be configured by using the properties @FaceStackingPriority, 
   @IconStackingPriority, @LabelStackingPriority, @ThumbStackingPriority, @TrackStackingPriority 
   and @AccentStackingPriority. The view with higher priority will appear in front 
   of other views with lower priority.
   Normally, when a state alternation occurs, the affected views are updated immediatelly 
   to reflect the new state. By using the property @StateTransitionDuration it is 
   possible to configure the toggle button to perform state alternations with animations 
   (e.g. the displacement of the shadow can be animated). This affects all attributes 
   of the views 'ThumbRectangle', 'ThumbBorder', 'ThumbShadow', 'TrackRectangle' 
   and 'TrackBorder'. In case of the views 'FaceImage', 'Label' and 'Icon' the animation 
   has an effect only on the colors and offsets used to configure the views. Consequently, 
   during animations these views can fade-out/in their colors and move only.
   If the button is actually focused, it can also be activated by pressing the keyboard 
   key specified in the property @KeyCode. To prevent the button from being able 
   to be focused, initialize this property with the value Core::KeyCode.NoKey. The 
   property @PressedFeedbackDuration configures the duration how long the button 
   should appear active (pressed) even if it has been taped for a very short time.
   To further enhance the widgets, a slot method can be assigned to the property 
   @OnUpdate. Within the slot method new decoration views can be added to the widgets 
   and updated according to the current state of the widget. 
   With the properties @WidgetMinSize and @WidgetMaxSize you can configure size 
   constraints for the widget itself. You can, for example, limit the button to 
   not shrink below a specified width or height. */
EW_DEFINE_FIELDS( WidgetSetToggleButtonConfig, WidgetSetWidgetConfig )
  EW_PROPERTY( LabelOnFont,     ResourcesFont )
  EW_PROPERTY( LabelOffFont,    ResourcesFont )
  EW_PROPERTY( FaceOnBitmapActive, ResourcesBitmap )
  EW_PROPERTY( FaceOnBitmapFocused, ResourcesBitmap )
  EW_PROPERTY( FaceOnBitmapDisabled, ResourcesBitmap )
  EW_PROPERTY( FaceOnBitmapDefault, ResourcesBitmap )
  EW_PROPERTY( FaceOffBitmapActive, ResourcesBitmap )
  EW_PROPERTY( FaceOffBitmapFocused, ResourcesBitmap )
  EW_PROPERTY( FaceOffBitmapDisabled, ResourcesBitmap )
  EW_PROPERTY( FaceOffBitmapDefault, ResourcesBitmap )
  EW_PROPERTY( LabelOnColorActive, XColor )
  EW_PROPERTY( LabelOnColorFocused, XColor )
  EW_PROPERTY( LabelOnColorDisabled, XColor )
  EW_PROPERTY( LabelOnColorDefault, XColor )
  EW_PROPERTY( LabelOffColorActive, XColor )
  EW_PROPERTY( LabelOffColorFocused, XColor )
  EW_PROPERTY( LabelOffColorDisabled, XColor )
  EW_PROPERTY( LabelOffColorDefault, XColor )
  EW_PROPERTY( LabelMarginRight, XInt32 )
  EW_PROPERTY( IconOnTintActive, XColor )
  EW_PROPERTY( IconOnTintFocused, XColor )
  EW_PROPERTY( IconOnTintDisabled, XColor )
  EW_PROPERTY( IconOnTintDefault, XColor )
  EW_PROPERTY( IconOffTintActive, XColor )
  EW_PROPERTY( IconOffTintFocused, XColor )
  EW_PROPERTY( IconOffTintDisabled, XColor )
  EW_PROPERTY( IconOffTintDefault, XColor )
  EW_PROPERTY( IconMarginRight, XInt32 )
  EW_PROPERTY( LabelAlignment,  XSet )
  EW_PROPERTY( IconAlignment,   XSet )
  EW_PROPERTY( FaceLayout,      XSet )
  EW_PROPERTY( FaceOnFrameActive, XInt32 )
  EW_PROPERTY( FaceOnFrameFocused, XInt32 )
  EW_PROPERTY( FaceOnFrameDisabled, XInt32 )
  EW_PROPERTY( FaceOnFrameDefault, XInt32 )
  EW_PROPERTY( FaceOffFrameActive, XInt32 )
  EW_PROPERTY( FaceOffFrameFocused, XInt32 )
  EW_PROPERTY( FaceOffFrameDisabled, XInt32 )
  EW_PROPERTY( FaceOffFrameDefault, XInt32 )
  EW_PROPERTY( WidgetMinSize,   XPoint )
EW_END_OF_FIELDS( WidgetSetToggleButtonConfig )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::ToggleButtonConfig' */
EW_DEFINE_METHODS( WidgetSetToggleButtonConfig, WidgetSetWidgetConfig )
EW_END_OF_METHODS( WidgetSetToggleButtonConfig )

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOnColorActive()' */
void WidgetSetToggleButtonConfig_OnSetLabelOnColorActive( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOnColorFocused()' */
void WidgetSetToggleButtonConfig_OnSetLabelOnColorFocused( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOnColorDisabled()' */
void WidgetSetToggleButtonConfig_OnSetLabelOnColorDisabled( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOnColorDefault()' */
void WidgetSetToggleButtonConfig_OnSetLabelOnColorDefault( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOffColorActive()' */
void WidgetSetToggleButtonConfig_OnSetLabelOffColorActive( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOffColorFocused()' */
void WidgetSetToggleButtonConfig_OnSetLabelOffColorFocused( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOffColorDisabled()' */
void WidgetSetToggleButtonConfig_OnSetLabelOffColorDisabled( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOffColorDefault()' */
void WidgetSetToggleButtonConfig_OnSetLabelOffColorDefault( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelMarginRight()' */
void WidgetSetToggleButtonConfig_OnSetLabelMarginRight( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOnTintActive()' */
void WidgetSetToggleButtonConfig_OnSetIconOnTintActive( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOnTintFocused()' */
void WidgetSetToggleButtonConfig_OnSetIconOnTintFocused( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOnTintDisabled()' */
void WidgetSetToggleButtonConfig_OnSetIconOnTintDisabled( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOnTintDefault()' */
void WidgetSetToggleButtonConfig_OnSetIconOnTintDefault( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOffTintActive()' */
void WidgetSetToggleButtonConfig_OnSetIconOffTintActive( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOffTintFocused()' */
void WidgetSetToggleButtonConfig_OnSetIconOffTintFocused( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOffTintDisabled()' */
void WidgetSetToggleButtonConfig_OnSetIconOffTintDisabled( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOffTintDefault()' */
void WidgetSetToggleButtonConfig_OnSetIconOffTintDefault( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconMarginRight()' */
void WidgetSetToggleButtonConfig_OnSetIconMarginRight( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelAlignment()' */
void WidgetSetToggleButtonConfig_OnSetLabelAlignment( WidgetSetToggleButtonConfig _this, 
  XSet value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOnFont()' */
void WidgetSetToggleButtonConfig_OnSetLabelOnFont( WidgetSetToggleButtonConfig _this, 
  ResourcesFont value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOffFont()' */
void WidgetSetToggleButtonConfig_OnSetLabelOffFont( WidgetSetToggleButtonConfig _this, 
  ResourcesFont value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconAlignment()' */
void WidgetSetToggleButtonConfig_OnSetIconAlignment( WidgetSetToggleButtonConfig _this, 
  XSet value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceLayout()' */
void WidgetSetToggleButtonConfig_OnSetFaceLayout( WidgetSetToggleButtonConfig _this, 
  XSet value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnFrameActive()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnFrameActive( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnFrameFocused()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnFrameFocused( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnFrameDisabled()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnFrameDisabled( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnFrameDefault()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnFrameDefault( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnBitmapActive()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnBitmapActive( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnBitmapFocused()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnBitmapFocused( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnBitmapDisabled()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnBitmapDisabled( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnBitmapDefault()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnBitmapDefault( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffFrameActive()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffFrameActive( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffFrameFocused()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffFrameFocused( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffFrameDisabled()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffFrameDisabled( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffFrameDefault()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffFrameDefault( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffBitmapActive()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffBitmapActive( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffBitmapFocused()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffBitmapFocused( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffBitmapDisabled()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffBitmapDisabled( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffBitmapDefault()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffBitmapDefault( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetWidgetMinSize()' */
void WidgetSetToggleButtonConfig_OnSetWidgetMinSize( WidgetSetToggleButtonConfig _this, 
  XPoint value );

#ifdef __cplusplus
  }
#endif

#endif /* _WidgetSetToggleButtonConfig_H */

/* Embedded Wizard */
