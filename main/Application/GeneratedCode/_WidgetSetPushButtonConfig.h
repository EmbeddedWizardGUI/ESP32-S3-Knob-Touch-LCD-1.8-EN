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

#ifndef _WidgetSetPushButtonConfig_H
#define _WidgetSetPushButtonConfig_H

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

/* Forward declaration of the class WidgetSet::PushButtonConfig */
#ifndef _WidgetSetPushButtonConfig_
  EW_DECLARE_CLASS( WidgetSetPushButtonConfig )
#define _WidgetSetPushButtonConfig_
#endif


/* This class implements the functionality permitting you to simply customize the 
   look and feel of a monostable 'push button' widget (WidgetSet::PushButton). In 
   the practice, you will create an instance of this class, configure its properties 
   with bitmaps, colors and other relevant attributes according to your design expectations 
   and assign such prepared configuration object to the property 'Appearance' of 
   every affected push button widget. Thereupon the widgets will use the configuration 
   information provided in the object.
   During its lifetime the button remains always in one of the four states: 'disabled', 
   'default', 'focused' and 'active'. The state 'disabled' is true for every not 
   available button (the property 'Enabled' of the button is 'false'). Such buttons 
   will ignore all user inputs. The state 'default' determines a button, which is 
   ready to be touched by the user or ready to become focused. As soon as the button 
   becomes focused, it switches in the state 'focused'. In this state the user can 
   activate the button by pressing a key on the keyboard. Finally, the state 'active' 
   is true, if the user actually interacts with the button (the button is pressed). 
   With the configuration object you can specify the appearance of the button for 
   every state individually. For this purpose you should know from which views the 
   button is composed of:
   - 'FaceImage' is a bitmap frame view (Views::Frame) filling per default the entire 
   background of the button unless the area is reduced by using the properties @FaceMarginBottom, 
   @FaceMarginLeft, @FaceMarginRight, @FaceMarginTop. The position can additionally 
   be adjusted for each state individually (@CommonOffsetActive, @CommonOffsetDefault, 
   @CommonOffsetDisabled, @CommonOffsetFocused). In the configuration object you 
   can individually specify for every button state the desired bitmap (@FaceBitmapActive, 
   @FaceBitmapDefault, @FaceBitmapDisabled, @FaceBitmapFocused), the frame number 
   within the bitmap (@FaceFrameActive, @FaceFrameDefault, @FaceFrameDisabled, @FaceFrameFocused) 
   and opacity or color to tint the bitmap (@FaceTintActive, @FaceTintDefault, @FaceTintDisabled, 
   @FaceTintFocused). The button can automatically play animated bitmaps if the 
   corresponding frame number is -1. If desired, with the property @FaceLayout you 
   can also configure the bitmap to be arranged horizontally and vertically instead 
   of filling the entire widget area.
   - 'ThumbRectangle' is a rectangle view (Views::Rectangle) filling per default 
   the entire area of the button unless other constraints (@ThumbLayout), a size 
   alternation (@ThumbSizeActive, @ThumbSizeDefault, @ThumbSizeDisabled, @ThumbSizeFocused) 
   or a displacement (@ThumbOffsetActive, @ThumbOffsetDefault, @ThumbOffsetDisabled, 
   @ThumbOffsetFocused) have been specified. Normally, the thumb has rectangular 
   shape with sharp corners. If desired the corners can be rounded (@ThumbCornerRadiusActive, 
   @ThumbCornerRadiusDefault, @ThumbCornerRadiusDisabled, @ThumbCornerRadiusFocused). 
   The thumb can be filled with a solid color (@ThumbColorActive, @ThumbColorDefault, 
   @ThumbColorDisabled, @ThumbColorFocused).
   - 'ThumbBorder' is a border view (Views::Border) surrounding the above described 
   'ThumbRectangle' and lying in front of it. Its size, position and corner radius 
   correspond thus to the of the 'ThumbRectangle'. The thickness of the border (@ThumbBorderWidthActive, 
   @ThumbBorderWidthDefault, @ThumbBorderWidthDisabled, @ThumbBorderWidthFocused) 
   and its color (@ThumbBorderColorActive, @ThumbBorderColorDefault, @ThumbBorderColorDisabled, 
   @ThumbBorderColorFocused) can be specified.
   - 'ThumbShadow' is a shadow view (Views::Shadow) lying always behind the above 
   described 'ThumbRectangle' view. Its size, position and corner radius correspond 
   thus to the of the 'ThumbRectangle'. However, an additional displacement for 
   the shadow can be specified (@ThumbShadowOffsetActive, @ThumbShadowOffsetDefault, 
   @ThumbShadowOffsetDisabled, @ThumbShadowOffsetFocused). The color of the shadow 
   (@ThumbShadowColorActive, @ThumbShadowColorDefault, @ThumbShadowColorDisabled, 
   @ThumbShadowColorFocused) as well as its blur radius (@ThumbShadowBlurRadiusActive, 
   @ThumbShadowBlurRadiusDefault, @ThumbShadowBlurRadiusDisabled, @ThumbShadowBlurRadiusFocused) 
   can be specified.
   - 'AccentRectangle' is a rectangle view (Views::Rectangle) filling per default 
   the entire area of the button unless other constraints (@AccentLayout), a size 
   alternation (@AccentSizeActive, @AccentSizeDefault, @AccentSizeDisabled, @AccentSizeFocused) 
   or a displacement (@AccentOffsetActive, @AccentOffsetDefault, @AccentOffsetDisabled, 
   @AccentOffsetFocused) have been specified. Normally, the accent area has rectangular 
   shape with sharp corners. If desired the corners can be rounded (@AccentCornerRadiusActive, 
   @AccentCornerRadiusDefault, @AccentCornerRadiusDisabled, @AccentCornerRadiusFocused). 
   The accent area can be filled with a solid color (@AccentColorActive, @AccentColorDefault, 
   @AccentColorDisabled, @AccentColorFocused). Accent usually serves to highlight 
   the widget when the user interacts with it actively or when the widget is focused.
   - 'AccentBorder' is a border view (Views::Border) surrounding the above described 
   'AccentRectangle' and lying in front of it. Its size, position and corner radius 
   correspond thus to the of the 'AccentRectangle'. The thickness of the border 
   (@AccentBorderWidthActive, @AccentBorderWidthDefault, @AccentBorderWidthDisabled, 
   @AccentBorderWidthFocused) and its color (@AccentBorderColorActive, @AccentBorderColorDefault, 
   @AccentBorderColorDisabled, @AccentBorderColorFocused) can be specified. Accent 
   usually serves to highlight the widget when the user interacts with it actively 
   or when the widget is focused.
   - 'Icon' is an image view (Views::Image) displayed per default in the center 
   of the button. The corresponding bitmap is determined in the property 'Icon' 
   in the push button widget. In the configuration object you can specify the alignment 
   (@IconAlignment) and margins (@IconMarginBottom, @IconMarginLeft, @IconMarginRight, 
   @IconMarginTop) how to arrange the 'Icon' bitmap within the button area. The 
   position can additionally be adjusted for each state individually (@CommonOffsetActive, 
   @CommonOffsetDefault, @CommonOffsetDisabled, @CommonOffsetFocused). Furthermore, 
   for every button state the opacity or color to tint the bitmap can be determined 
   (@IconTintActive, @IconTintDefault, @IconTintDisabled, @IconTintFocused).
   - 'Label' is a text view (Views::Text) displayed per default in the center of 
   the button. The corresponding text is determined in the property 'Label' in the 
   push button widget. In the configuration object you can specify the font (@LabelFont), 
   alignment (@LabelAlignment) and margins (@LabelMarginBottom, @LabelMarginLeft, 
   @LabelMarginRight, @LabelMarginTop) to use for the text view. The position can 
   additionally be adjusted for each state individually (@CommonOffsetActive, @CommonOffsetDefault, 
   @CommonOffsetDisabled, @CommonOffsetFocused). For every button state you can 
   specify individual text color values (@LabelColorActive, @LabelColorDefault, 
   @LabelColorDisabled, @LabelColorFocused).
   All above mentioned views are arranged one above the other whereby the resulting 
   stacking order can be configured by using the properties @FaceStackingPriority, 
   @IconStackingPriority, @LabelStackingPriority, @ThumbStackingPriority and @AccentStackingPriority. 
   The view with higher priority will appear in front of other views with lower 
   priority.
   Normally, when a state alternation occurs, the affected views are updated immediatelly 
   to reflect the new state. By using the property @StateTransitionDuration it is 
   possible to configure the push button to perform state alternations with animations 
   (e.g. the displacement of the shadow can be animated). This affects all attributes 
   of the views 'ThumbRectangle', 'ThumbBorder', 'ThumbShadow', 'AccentRectangle' 
   and 'AccentBorder'. In case of the views 'FaceImage', 'Label' and 'Icon' the 
   animation has an effect only on the colors and offsets used to configure the 
   views. Consequently, during animations these views can fade-out/in their colors 
   and move only.
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
EW_DEFINE_FIELDS( WidgetSetPushButtonConfig, WidgetSetWidgetConfig )
  EW_PROPERTY( LabelFont,       ResourcesFont )
  EW_PROPERTY( FaceBitmapActive, ResourcesBitmap )
  EW_PROPERTY( FaceBitmapFocused, ResourcesBitmap )
  EW_PROPERTY( FaceBitmapDisabled, ResourcesBitmap )
  EW_PROPERTY( FaceBitmapDefault, ResourcesBitmap )
  EW_PROPERTY( LabelColorActive, XColor )
  EW_PROPERTY( LabelColorFocused, XColor )
  EW_PROPERTY( LabelColorDisabled, XColor )
  EW_PROPERTY( LabelColorDefault, XColor )
  EW_PROPERTY( LabelMarginBottom, XInt32 )
  EW_PROPERTY( LabelMarginTop,  XInt32 )
  EW_PROPERTY( LabelMarginRight, XInt32 )
  EW_PROPERTY( LabelMarginLeft, XInt32 )
  EW_PROPERTY( IconTintDisabled, XColor )
  EW_PROPERTY( IconTintDefault, XColor )
  EW_PROPERTY( IconMarginBottom, XInt32 )
  EW_PROPERTY( IconMarginTop,   XInt32 )
  EW_PROPERTY( IconMarginRight, XInt32 )
  EW_PROPERTY( IconMarginLeft,  XInt32 )
  EW_PROPERTY( FaceFrameActive, XInt32 )
  EW_PROPERTY( FaceFrameFocused, XInt32 )
  EW_PROPERTY( FaceFrameDisabled, XInt32 )
  EW_PROPERTY( FaceFrameDefault, XInt32 )
  EW_PROPERTY( WidgetMinSize,   XPoint )
EW_END_OF_FIELDS( WidgetSetPushButtonConfig )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::PushButtonConfig' */
EW_DEFINE_METHODS( WidgetSetPushButtonConfig, WidgetSetWidgetConfig )
EW_END_OF_METHODS( WidgetSetPushButtonConfig )

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelColorActive()' */
void WidgetSetPushButtonConfig_OnSetLabelColorActive( WidgetSetPushButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelColorFocused()' */
void WidgetSetPushButtonConfig_OnSetLabelColorFocused( WidgetSetPushButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelColorDisabled()' */
void WidgetSetPushButtonConfig_OnSetLabelColorDisabled( WidgetSetPushButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelColorDefault()' */
void WidgetSetPushButtonConfig_OnSetLabelColorDefault( WidgetSetPushButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelMarginBottom()' */
void WidgetSetPushButtonConfig_OnSetLabelMarginBottom( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelMarginTop()' */
void WidgetSetPushButtonConfig_OnSetLabelMarginTop( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelMarginRight()' */
void WidgetSetPushButtonConfig_OnSetLabelMarginRight( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelMarginLeft()' */
void WidgetSetPushButtonConfig_OnSetLabelMarginLeft( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetIconTintDisabled()' */
void WidgetSetPushButtonConfig_OnSetIconTintDisabled( WidgetSetPushButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetIconTintDefault()' */
void WidgetSetPushButtonConfig_OnSetIconTintDefault( WidgetSetPushButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetIconMarginBottom()' */
void WidgetSetPushButtonConfig_OnSetIconMarginBottom( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetIconMarginTop()' */
void WidgetSetPushButtonConfig_OnSetIconMarginTop( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetIconMarginRight()' */
void WidgetSetPushButtonConfig_OnSetIconMarginRight( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetIconMarginLeft()' */
void WidgetSetPushButtonConfig_OnSetIconMarginLeft( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelFont()' */
void WidgetSetPushButtonConfig_OnSetLabelFont( WidgetSetPushButtonConfig _this, 
  ResourcesFont value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceFrameActive()' */
void WidgetSetPushButtonConfig_OnSetFaceFrameActive( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceFrameFocused()' */
void WidgetSetPushButtonConfig_OnSetFaceFrameFocused( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceFrameDisabled()' */
void WidgetSetPushButtonConfig_OnSetFaceFrameDisabled( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceFrameDefault()' */
void WidgetSetPushButtonConfig_OnSetFaceFrameDefault( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceBitmapActive()' */
void WidgetSetPushButtonConfig_OnSetFaceBitmapActive( WidgetSetPushButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceBitmapFocused()' */
void WidgetSetPushButtonConfig_OnSetFaceBitmapFocused( WidgetSetPushButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceBitmapDisabled()' */
void WidgetSetPushButtonConfig_OnSetFaceBitmapDisabled( WidgetSetPushButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceBitmapDefault()' */
void WidgetSetPushButtonConfig_OnSetFaceBitmapDefault( WidgetSetPushButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetWidgetMinSize()' */
void WidgetSetPushButtonConfig_OnSetWidgetMinSize( WidgetSetPushButtonConfig _this, 
  XPoint value );

#ifdef __cplusplus
  }
#endif

#endif /* _WidgetSetPushButtonConfig_H */

/* Embedded Wizard */
