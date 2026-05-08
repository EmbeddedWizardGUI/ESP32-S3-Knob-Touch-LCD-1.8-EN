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

#ifndef _ViewsStrokePath_H
#define _ViewsStrokePath_H

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

/* Forward declaration of the class Graphics::Path */
#ifndef _GraphicsPath_
  EW_DECLARE_CLASS( GraphicsPath )
#define _GraphicsPath_
#endif

/* Forward declaration of the class Views::StrokePath */
#ifndef _ViewsStrokePath_
  EW_DECLARE_CLASS( ViewsStrokePath )
#define _ViewsStrokePath_
#endif


/* The class Views::StrokePath provides a kind of view specialized to stroke a path. 
   The coordinates of the path line segments are provided in a Graphics::Path object 
   assigned to the property @Path. The position and the size of the area to display 
   the path are determined by the property @Bounds. The color to use when stroking 
   the path is defined by the property @Color. Alternatively, the path can be stroked 
   with a color gradient specified by the properties @ColorTL, @ColorTR, @ColorBL 
   and @ColorBR. For each view's corner different color can be set. 
   The thickness of the stroked path is controlled by the property @Width. With 
   the properties @StartCap and @EndCap the appearance of the path ends, if the 
   path is opened, can be determined. The properties @JoinPoints and @MiterLimit 
   control the appearance of path corners, the join points between path line segments.
   With the property @FlipY and @Offset you can control the orientation and the 
   origin position of the path coordinate system. Finally, the property @Quality 
   determines whether the paths is rasterized with or without antialiasing.
   The visibility of the stroked path is controlled by the properties @Visible and 
   @Embedded. In particular the property @Embedded can determine whether the corresponding 
   view is limited (== embedded) to the boundary of a sibling Core::Outline view 
   or not. The embedding of views within a Core::Outline allows a kind of sub-groups 
   within the GUI component itself. Very useful for any kind of scrollable lists, 
   menus, etc.
   Finally, the property @Buffered controls whether the view should store its aspect 
   in an off-screen bitmap. This feature is useful to optimize screen update avoiding 
   the rasterization of the path. */
EW_DEFINE_FIELDS( ViewsStrokePath, CoreRectView )
  EW_PROPERTY( Path,            GraphicsPath )
  EW_PROPERTY( Color,           XColor )
  EW_PROPERTY( Offset,          XPoint )
  EW_PROPERTY( EndCap,          XEnum )
  EW_PROPERTY( StartCap,        XEnum )
  EW_PROPERTY( Width,           XFloat )
EW_END_OF_FIELDS( ViewsStrokePath )

/* Virtual Method Table (VMT) for the class : 'Views::StrokePath' */
EW_DEFINE_METHODS( ViewsStrokePath, CoreRectView )
  EW_METHOD( GetRoot,           CoreRoot )( CoreView _this )
  EW_METHOD( Draw,              void )( ViewsStrokePath _this, GraphicsCanvas aCanvas, 
    XRect aClip, XPoint aOffset, XInt32 aOpacity, XBool aBlend )
  EW_METHOD( GetClipping,       XRect )( CoreView _this )
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
  EW_METHOD( ChangeViewState,   void )( CoreView _this, XSet aSetState, XSet aClearState )
  EW_METHOD( OnSetBounds,       void )( CoreRectView _this, XRect value )
EW_END_OF_METHODS( ViewsStrokePath )

/* 'C' function for method : 'Views::StrokePath.Done()' */
void ViewsStrokePath_Done( ViewsStrokePath _this );

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
void ViewsStrokePath_Draw( ViewsStrokePath _this, GraphicsCanvas aCanvas, XRect 
  aClip, XPoint aOffset, XInt32 aOpacity, XBool aBlend );

/* 'C' function for method : 'Views::StrokePath.destroyBuffer()' */
void ViewsStrokePath_destroyBuffer( ViewsStrokePath _this );

/* 'C' function for method : 'Views::StrokePath.updatePath()' */
void ViewsStrokePath_updatePath( ViewsStrokePath _this, XObject sender );

/* 'C' function for method : 'Views::StrokePath.OnSetColor()' */
void ViewsStrokePath_OnSetColor( ViewsStrokePath _this, XColor value );

/* 'C' function for method : 'Views::StrokePath.OnSetOffset()' */
void ViewsStrokePath_OnSetOffset( ViewsStrokePath _this, XPoint value );

/* 'C' function for method : 'Views::StrokePath.OnSetEndCap()' */
void ViewsStrokePath_OnSetEndCap( ViewsStrokePath _this, XEnum value );

/* 'C' function for method : 'Views::StrokePath.OnSetStartCap()' */
void ViewsStrokePath_OnSetStartCap( ViewsStrokePath _this, XEnum value );

/* 'C' function for method : 'Views::StrokePath.OnSetWidth()' */
void ViewsStrokePath_OnSetWidth( ViewsStrokePath _this, XFloat value );

/* 'C' function for method : 'Views::StrokePath.OnSetPath()' */
void ViewsStrokePath_OnSetPath( ViewsStrokePath _this, GraphicsPath value );

/* 'C' function for method : 'Views::StrokePath.OnSetVisible()' */
void ViewsStrokePath_OnSetVisible( ViewsStrokePath _this, XBool value );

#ifdef __cplusplus
  }
#endif

#endif /* _ViewsStrokePath_H */

/* Embedded Wizard */
