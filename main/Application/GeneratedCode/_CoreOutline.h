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

#ifndef _CoreOutline_H
#define _CoreOutline_H

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

#include "_CoreRectView.h"

/* Forward declaration of the class Core::Group */
#ifndef _CoreGroup_
  EW_DECLARE_CLASS( CoreGroup )
#define _CoreGroup_
#endif

/* Forward declaration of the class Core::LayoutContext */
#ifndef _CoreLayoutContext_
  EW_DECLARE_CLASS( CoreLayoutContext )
#define _CoreLayoutContext_
#endif

/* Forward declaration of the class Core::Outline */
#ifndef _CoreOutline_
  EW_DECLARE_CLASS( CoreOutline )
#define _CoreOutline_
#endif

/* Forward declaration of the class Core::View */
#ifndef _CoreView_
  EW_DECLARE_CLASS( CoreView )
#define _CoreView_
#endif

/* Forward declaration of the class Graphics::Canvas */
#ifndef _GraphicsCanvas_
  EW_DECLARE_CLASS( GraphicsCanvas )
#define _GraphicsCanvas_
#endif


/* The class Core::Outline provides a special kind of a view able to unite and control 
   its sibling views. It acts like a lightweight container for the views without 
   being the owner of them:
   - Outline can control only views lying in front of it (views with higher Z-order). 
   Furthermore the affected views have to be signed explicitly with the state 'Embedded'. 
   Views lying behind the outline or views not signed as embedded are ignored by 
   the outline - they are controlled by their @Owner.
   - Outline limits the visibility of the embedded views to its own boundary area. 
   In this manner the views are clipped at the outlines edges.
   - Moving the outline causes the embedded views to be moved accordingly. Together 
   with the outline the views behave like a single union.
   - The embedded views can be scrolled within the outline boundary area. The property 
   @ScrollOffset determines the desired displacement.
   - A Core::SlideTouchHandler can be attached to the outline so the user can scroll 
   the outline content interactively by touching the screen. The property @SlideHandler 
   allows it. 
   - If the size of the outline changes, all embedded views are automatically arranged 
   within the outline boundary accordingly to their @Layout properties.
   - The property @Formation allows more sophisticated arrangement of embedded views 
   in columns and rows. Even table-like grid is possible. It is useful to create 
   scrollable menus or lists. With the properties @SpaceHorz, @SpaceVert and @Space 
   additional gaps between the automatically arranged views can be added. The property 
   @WrapSize determines the maximim width of the resulting row or maximum height 
   of the resulting column (depending on the configured fomration). It can be used 
   to control the wrap (break) position in long sequences of views.
   - When @Formation is configured to arrange views in rows and/or columns, the 
   property @Alignment can be used to control the position of the arranged views 
   within the outline boundary area. For example, the views can be centered horizontally 
   and/or vertically.
   - The properties @Padding, @PaddingLeft, @PaddingRight, @PaddingTop and @PaddingBottom 
   permit to reserve additional space around the content controlled by the Outline. 
   This space is taken in account when scrolling the Outline content or when the 
   Outline is configured with its @Formation property to arrange the views in rows 
   and/or columns.
   - The property @ClipViews controls how views lying outside the boundary area 
   of the outline should appear. Disabling the clipping is useful especially in 
   application cases of the outline containing some shadows or blur effects.
   - To find and enumerate the embedded views, the methods like @FindNextView(), 
   @FindPrevView(), @FindViewAtPosition, @FindViewInDirection(), @FindViewWithStackingPriority() 
   or @GetViewAtIndex() are available. 
   - The method @EnsureVisible() has the job to scroll the outline contents until 
   the given view is visible. The method @AdjustContent() in contrast tries to scroll 
   the outline so the entire outline area is filled with views. Usually this is 
   used after the outline size changes.
   The outline itself is invisible except the Embedded Wizard Composer, where all 
   outlines appear as semitransparent rectangles. This allows you to interact with 
   the outlines during the design time. */
EW_DEFINE_FIELDS( CoreOutline, CoreRectView )
EW_END_OF_FIELDS( CoreOutline )

/* Virtual Method Table (VMT) for the class : 'Core::Outline' */
EW_DEFINE_METHODS( CoreOutline, CoreRectView )
  EW_METHOD( initLayoutContext, void )( CoreRectView _this, XRect aBounds, CoreOutline 
    aOutline )
  EW_METHOD( GetRoot,           CoreRoot )( CoreView _this )
  EW_METHOD( Draw,              void )( CoreOutline _this, GraphicsCanvas aCanvas, 
    XRect aClip, XPoint aOffset, XInt32 aOpacity, XBool aBlend )
  EW_METHOD( GetClipping,       XRect )( CoreOutline _this )
  EW_METHOD( HandleEvent,       XObject )( CoreView _this, CoreEvent aEvent )
  EW_METHOD( CursorHitTest,     CoreCursorHit )( CoreView _this, XRect aArea, XInt32 
    aFinger, XInt32 aStrikeCount, CoreView aDedicatedView, CoreView aStartView, 
    XSet aRetargetReason )
  EW_METHOD( AdjustDrawingArea, XRect )( CoreView _this, XRect aArea )
  EW_METHOD( ArrangeView,       XPoint )( CoreRectView _this, XRect aBounds, XEnum 
    aFormation )
  EW_METHOD( MoveView,          void )( CoreRectView _this, XPoint aOffset, XBool 
    aFastMove )
  EW_METHOD( GetExtent,         XRect )( CoreRectView _this )
  EW_METHOD( ChangeViewState,   void )( CoreOutline _this, XSet aSetState, XSet 
    aClearState )
  EW_METHOD( OnSetBounds,       void )( CoreOutline _this, XRect value )
EW_END_OF_METHODS( CoreOutline )

/* The method Draw() is invoked automatically if parts of the view should be redrawn 
   on the screen. This can occur when e.g. the view has been moved or the appearance 
   of the view has changed before.
   Draw() is invoked automatically by the framework, you will never need to invoke 
   this method directly. However you can request an invocation of this method by 
   calling the method InvalidateArea() of the views @Owner. Usually this is also 
   unnecessary unless you are developing your own view.
   The passed parameters determine the drawing destination aCanvas and the area 
   to redraw aClip in the coordinate space of the canvas. The parameter aOffset 
   contains the displacement between the origin of the views owner and the origin 
   of the canvas. You will need it to convert views coordinates into these of the 
   canvas.
   The parameter aOpacity contains the opacity descended from this view's @Owner. 
   It lies in range 0 .. 255. If the view implements its own 'Opacity', 'Color', 
   etc. properties, the Draw() method should calculate the resulting real opacity 
   by mixing the values of these properties with the one passed in aOpacity parameter.
   The parameter aBlend contains the blending mode descended from this view's @Owner. 
   It determines, whether the view should be drawn with alpha-blending active or 
   not. If aBlend is false, the outputs of the view should overwrite the corresponding 
   pixel in the drawing destination aCanvas. If aBlend is true, the outputs should 
   be mixed with the pixel already stored in aCanvas. For this purpose all Graphics 
   Engine functions provide a parameter to specify the mode for the respective drawing 
   operation. If the view implements its own 'Blend' property, the Draw() method 
   should calculate the resulting real blend mode by using logical AND operation 
   of the value of the property and the one passed in aBlend parameter. */
void CoreOutline_Draw( CoreOutline _this, GraphicsCanvas aCanvas, XRect aClip, XPoint 
  aOffset, XInt32 aOpacity, XBool aBlend );

/* The method GetClipping() returns the clipping area of the view as rectangle relative 
   to the origin of the view's @Owner. With the returned clipping area the view 
   limits its own visibility. Contents belonging to the view and lying outside this 
   area will not be displayed - they are clipped during the screen update process.
   Per default the clipping area corresponds to the boundary area of the view (see 
   also @GetExtent()). Derived views can override GetClipping() and enlarge the 
   area so the view can display additional contents (e.g. shadows or decoration) 
   outside of its original boundary area. */
XRect CoreOutline_GetClipping( CoreOutline _this );

/* The method ChangeViewState() modifies the current state of the view. The state 
   is a set of switches determining whether a view is visible, whether it can react 
   to user inputs or whether it is just performing some update operations, etc.
   The modification is controlled by the both parameters. The first aSetState contains 
   the switches to activate within the view state. The second aClearState determines 
   all switches to disable.
   Depending on the state alteration the method will perform different operations, 
   e.g. in response to the clearing of the visible state, the method will request 
   a screen redraw to make disappear the view from the screen.
   ChangeViewState() is invoked automatically by the framework, so you never should 
   need to invoke it directly. All relevant states are available as properties e.g. 
   the property Visible in derived classes reflects the visible state of the view. */
void CoreOutline_ChangeViewState( CoreOutline _this, XSet aSetState, XSet aClearState );

/* 'C' function for method : 'Core::Outline.OnSetBounds()' */
void CoreOutline_OnSetBounds( CoreOutline _this, XRect value );

#ifdef __cplusplus
  }
#endif

#endif /* _CoreOutline_H */

/* Embedded Wizard */
