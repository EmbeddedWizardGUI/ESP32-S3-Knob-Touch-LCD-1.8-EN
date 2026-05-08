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

#ifndef _CoreGroup_H
#define _CoreGroup_H

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

/* Forward declaration of the class Core::CursorHit */
#ifndef _CoreCursorHit_
  EW_DECLARE_CLASS( CoreCursorHit )
#define _CoreCursorHit_
#endif

/* Forward declaration of the class Core::Event */
#ifndef _CoreEvent_
  EW_DECLARE_CLASS( CoreEvent )
#define _CoreEvent_
#endif

/* Forward declaration of the class Core::Group */
#ifndef _CoreGroup_
  EW_DECLARE_CLASS( CoreGroup )
#define _CoreGroup_
#endif

/* Forward declaration of the class Core::KeyPressHandler */
#ifndef _CoreKeyPressHandler_
  EW_DECLARE_CLASS( CoreKeyPressHandler )
#define _CoreKeyPressHandler_
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


/* The class Core::Group provides the base functionality for all kinds of complex 
   GUI components, like the push button, the slider or the entire menu panel. All 
   user defined GUI components do descend from this class.
   Groups serve as containers for other views. They are able to manage any number 
   of enclosed views, to arrange these views, to redraw them automatically and to 
   deliver user input events to the views. They act as the unique @Owner of the 
   enclosed views. At the same time the groups borderline determines the area where 
   its views can appear. Parts of views lying outside this @Bounds area are per 
   default clipped and not visible.
   Each group defines its own coordinate system starting with the origin <0,0> at 
   the top-left corner of the group. All views enclosed within the group are placed 
   relatively to this origin. Moving a group automatically moves the corresponding 
   coordinate system and thus the enclosed views. You don't need to take care about 
   it.
   Since the Core::Group class descends from the very basic ordinary Core::View 
   class, groups can be enclosed within other groups, by what nesting of GUI components 
   is possible. For example, several push button components can be enclosed within 
   a superior menu component in order to design a more complex component. It's up 
   to you to compose these view hierarchies.
   The interface of the Core::Group class provides a wide range of methods and some 
   properties to control the group and the enclosed views. For example:
   - The list of enclosed views is controlled by the methods @Add(), @Remove() and 
   @Restack(). These methods allow you to insert new views to the group, to remove 
   existing views from the group or to change the so-called Z-order of views - the 
   order determining which view lies in the front and which in the background of 
   the group.
   - More sophisticated: with the method @FadeGroup() animated transitions to add 
   and fade-in or to fade-out and remove a GUI component within 'this' component 
   can be scheduled.
   - To find and enumerate the enclosed views, the methods like @FindNextView(), 
   @FindPrevView(), @FindViewAtPosition, @FindViewInDirection(), @FindViewWithStackingPriority() 
   or @GetViewAtIndex() are available. 
   - Although the screen redraw is performed automatically by the framework, the 
   method InvalidateArea() can be used to request an explicit screen update for 
   the given area of the group. Furthermore, by overriding the methods @DrawBackground() 
   and @DrawForeground() the descending class can implement additional code to draw 
   the areas behind and in front of the enclosed views programmatically.
   - If the size of the group changes, all enclosed views are arranged automatically 
   accordingly to their @Layout properties. If more sophisticated arrangement is 
   desired the method @UpdateLayout() can be overridden and filled with the appropriate 
   logic to calculate the position and size of views. If your application case it 
   requires, you can trigger the layout update explicitly by invoking the method 
   @InvalidateLayout().
   - Although the delivery of user input events to the views is performed automatically 
   by the framework, the both methods @DispatchEvent() and @BroadcastEvent() can 
   be used to feed the group and its views with any additional user defined events.
   - The visibility of the group and thus the visibility of all enclosed views is 
   controlled by the properties @Visible, @AlphaBlended, @Opacity and @Embedded. 
   In particular the property @Embedded can determine whether the corresponding 
   GUI component is limited (== embedded) to the boundary of a sibling Core::Outline 
   view or not. The embedding of views within a Core::Outline allows a kind of sub-groups 
   within the group itself. Very useful for any kind of scrollable lists, menus, 
   etc.
   - The property @Buffered controls whether the group should store its aspect in 
   an off-screen bitmap. This feature is useful when e.g. the entire group should 
   be animated - it can avoid superfluous redrawing of the groups content. Other 
   advantage of this feature is the possibility to replicate the aspect of a group 
   within a Views::Group or Views::WarpGroup view. With other words, several copies 
   of the group aspect can be shown on the screen. Useful for many fade-in, 2D/3D 
   warp or mirror visual effects.
   - The property @ClipViews and the method @ExtendClipping() control how views 
   lying outside the boundary area of the component should appear. Extending or 
   disabling the clipping is useful especially in application cases of the component 
   containing some shadows or blur effects.
   - Other useful feature is the centralized and uniform update of the GUI state. 
   Usually every GUI component does store its current state, like the states 'on' 
   or 'off' in case of a toggle switch component. This state can change at the runtime 
   e.g. in response to the user interaction. To handle this state alteration the 
   method @UpdateViewState() can be overridden and filled with the desired logic 
   to reflect the current state in the appearance of the GUI component. In this 
   manner the entire state update is located in a single method. This method will 
   be invoked automatically by the framework. Optionally you can request its invocation 
   by using the method @InvalidateViewState().
   - The class Core::Group implements a powerful infrastructure permitting simple 
   presentation and dismissing of GUI components in context of 'this' component 
   similarly to the concepts of 'alert panels', 'message boxes' or 'dialogs' known 
   from other GUI frameworks. Internally, every instance of Core::Group manages 
   a stack with all dialog components belonging actually to it. The dialog component 
   on top of the stack is considered as the active dialog - the dialog, the user 
   may interact with. Other dialogs lying in the background are automatically deactivated 
   and they are suppressed from being able to receive and process user inputs. New 
   dialogs are presented by using the method @PresentDialog(). With the method @SwitchToDialog() 
   you can replace the actually active dialog by another one. Finally, with the 
   method @DismissDialog() one of the actually presented dialogs can be dismissed 
   again. Every of these operations can be performed with animation transitions, 
   you specify in the parameters when invoking the respective method.
   - If using the above described infrastructure to manage dialogs, you can use 
   the methods @IsDialog(), @IsActiveDialog() and @IsCurrentDialog() to verify whether 
   the affected GUI component is actually, just in this moment a dialog presented 
   within another GUI component, whether it is an active dialog or even the current 
   dialog. Knowing this is essential to estimate the actual state of the GUI application, 
   even if the dialogs appear or disappear with animations. With the methods @CountDialogs(), 
   @GetDialogAtIndex(), @GetIndexOfDialog() you can simply evaluate and traverse 
   the stack of dialog components existing actually in context of 'this' GUI component. 
   With the method @FindCurrentDialog() you can search in 'this' component and all 
   subordinated dialog components for the dialog which is the current one. The both 
   methods @FindDialogByClass() and @FindActiveDialogByClass() are convenient to 
   search in 'this' component and all subordinated dialog components for the dialog, 
   which is an instance of a specified component class. */
EW_DEFINE_FIELDS( CoreGroup, CoreRectView )
  EW_VARIABLE( first,           CoreView )
  EW_VARIABLE( last,            CoreView )
  EW_VARIABLE( keyHandlers,     CoreKeyPressHandler )
  EW_PROPERTY( Focus,           CoreView )
  EW_VARIABLE( extClipLeft,     XUInt8 )
  EW_VARIABLE( extClipRight,    XUInt8 )
  EW_VARIABLE( extClipTop,      XUInt8 )
  EW_VARIABLE( extClipBottom,   XUInt8 )
EW_END_OF_FIELDS( CoreGroup )

/* Virtual Method Table (VMT) for the class : 'Core::Group' */
EW_DEFINE_METHODS( CoreGroup, CoreRectView )
  EW_METHOD( GetRoot,           CoreRoot )( CoreView _this )
  EW_METHOD( Draw,              void )( CoreGroup _this, GraphicsCanvas aCanvas, 
    XRect aClip, XPoint aOffset, XInt32 aOpacity, XBool aBlend )
  EW_METHOD( GetClipping,       XRect )( CoreGroup _this )
  EW_METHOD( HandleEvent,       XObject )( CoreView _this, CoreEvent aEvent )
  EW_METHOD( CursorHitTest,     CoreCursorHit )( CoreGroup _this, XRect aArea, XInt32 
    aFinger, XInt32 aStrikeCount, CoreView aDedicatedView, CoreView aStartView, 
    XSet aRetargetReason )
  EW_METHOD( AdjustDrawingArea, XRect )( CoreGroup _this, XRect aArea )
  EW_METHOD( ArrangeView,       XPoint )( CoreRectView _this, XRect aBounds, XEnum 
    aFormation )
  EW_METHOD( MoveView,          void )( CoreRectView _this, XPoint aOffset, XBool 
    aFastMove )
  EW_METHOD( GetExtent,         XRect )( CoreRectView _this )
  EW_METHOD( ChangeViewState,   void )( CoreGroup _this, XSet aSetState, XSet aClearState )
  EW_METHOD( OnSetBounds,       void )( CoreGroup _this, XRect value )
  EW_METHOD( OnSetFocus,        void )( CoreGroup _this, CoreView value )
  EW_METHOD( DispatchEvent,     XObject )( CoreGroup _this, CoreEvent aEvent )
  EW_METHOD( BroadcastEvent,    XObject )( CoreGroup _this, CoreEvent aEvent, XSet 
    aFilter )
  EW_METHOD( InvalidateArea,    void )( CoreGroup _this, XRect aArea )
EW_END_OF_METHODS( CoreGroup )

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void CoreGroup_Init( CoreGroup _this, XHandle aArg );

/* 'C' function for method : 'Core::Group.Draw()' */
void CoreGroup_Draw( CoreGroup _this, GraphicsCanvas aCanvas, XRect aClip, XPoint 
  aOffset, XInt32 aOpacity, XBool aBlend );

/* The method GetClipping() returns the clipping area of the view as rectangle relative 
   to the origin of the view's @Owner. With the returned clipping area the view 
   limits its own visibility. Contents belonging to the view and lying outside this 
   area will not be displayed - they are clipped during the screen update process.
   Per default the clipping area corresponds to the boundary area of the view (see 
   also @GetExtent()). Derived views can override GetClipping() and enlarge the 
   area so the view can display additional contents (e.g. shadows or decoration) 
   outside of its original boundary area. */
XRect CoreGroup_GetClipping( CoreGroup _this );

/* The method CursorHitTest() is invoked automatically in order to determine whether 
   the view is interested in the receipt of cursor events or not. This method will 
   be invoked immediately after the user has tapped the visible area of the view. 
   If the view is not interested in the cursor event, the framework repeats this 
   procedure for the next behind view until a willing view has been found or all 
   views are evaluated.
   In the implementation of the method the view can evaluate the passed aArea parameter. 
   It determines the place where the user has tapped the view with his fingertip 
   expressed in the coordinates of the views @Owner. The method can test e.g. whether 
   the tapped area does intersect any touchable areas within the view, etc. The 
   affected finger is identified in the parameter aFinger. The first finger (or 
   the first mouse device button) has the number 0.
   The parameter aStrikeCount determines how many times the same area has been tapped 
   in series. This is useful to detect series of multiple touches, e.g. in case 
   of the double click, aStrikeCount == 2.
   The parameter aDedicatedView, if it is not 'null', restricts the event to be 
   handled by this view only. If aDedicatedView == null, no special restriction 
   exists.
   The parameter aStartView, if it is not 'null', restricts the event to be handled 
   by the specified view or another view lying behind it. In other words, views 
   found in front of aStartView are not taken in account during the hit-test operation.
   This method is also invoked if during an existing grab cycle the current target 
   view has decided to resign and deflect the cursor events to another view. This 
   is usually the case after the user has performed a gesture the current target 
   view is not interested to process. Thereupon, the system looks for another view 
   willing to take over the cursor event processing after the performed gesture. 
   Which gesture has caused the operation, is specified in the parameter aRetargetReason.
   If the view is willing to process the event, the method should create, initialize 
   and return a new Core::CursorHit object. This object identify the willing view. 
   Otherwise the method should return 'null'.
   CursorHitTest() is invoked automatically by the framework, so you never should 
   need to invoke it directly. This method is predetermined for the hit-test only. 
   The proper processing of events should take place in the @HandleEvent() method 
   by reacting to Core::CursorEvent and Core::DragEvent events. */
CoreCursorHit CoreGroup_CursorHitTest( CoreGroup _this, XRect aArea, XInt32 aFinger, 
  XInt32 aStrikeCount, CoreView aDedicatedView, CoreView aStartView, XSet aRetargetReason );

/* 'C' function for method : 'Core::Group.AdjustDrawingArea()' */
XRect CoreGroup_AdjustDrawingArea( CoreGroup _this, XRect aArea );

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
void CoreGroup_ChangeViewState( CoreGroup _this, XSet aSetState, XSet aClearState );

/* 'C' function for method : 'Core::Group.OnSetBounds()' */
void CoreGroup_OnSetBounds( CoreGroup _this, XRect value );

/* 'C' function for method : 'Core::Group.processKeyHandlers()' */
XObject CoreGroup_processKeyHandlers( CoreGroup _this, CoreEvent aEvent );

/* 'C' function for method : 'Core::Group.drawContent()' */
void CoreGroup_drawContent( CoreGroup _this, GraphicsCanvas aCanvas, XRect aClip, 
  XPoint aOffset, XInt32 aOpacity, XBool aBlend );

/* 'C' function for method : 'Core::Group.recalculateLayout()' */
void CoreGroup_recalculateLayout( CoreGroup _this );

/* 'C' function for method : 'Core::Group.updateComponentWithDelay()' */
void CoreGroup_updateComponentWithDelay( CoreGroup _this, XObject sender );

/* 'C' function for method : 'Core::Group.updateComponent()' */
void CoreGroup_updateComponent( CoreGroup _this, XObject sender );

/* 'C' function for method : 'Core::Group.OnSetFocus()' */
void CoreGroup_OnSetFocus( CoreGroup _this, CoreView value );

/* Wrapper function for the virtual method : 'Core::Group.OnSetFocus()' */
void CoreGroup__OnSetFocus( void* _this, CoreView value );

/* 'C' function for method : 'Core::Group.OnSetVisible()' */
void CoreGroup_OnSetVisible( CoreGroup _this, XBool value );

/* The method ExtendClipping() enhances the clipping area of the affected group 
   so that all contents lying outside its original @Bounds area can be displayed 
   on the screen. Enhancement of the clipping area is typically necessary when the 
   group is intended to display shadows or blur effects which cross the borders 
   of the group.
   With the four parameters aExtClipLeft, aExtClipRight aExtClipTop and aExtClipBottom 
   the clipping at the corresponding edges can be enhanced individually. Please 
   note that the parameters are limited to the range 0 .. 255. This means the clipping 
   for an edge can be enhanced maximally by 255 pixel. Exaggerated enhancement of 
   clipping aea can impact the screen update performance of your application.
   Furthermore, if the component is configured as @Buffered, extending the clipping 
   area has no effect. Setting 'Buffered' = 'true' imposes the component to clip 
   at its edges determined by the property @Bounds. */
void CoreGroup_ExtendClipping( CoreGroup _this, XInt32 aExtClipLeft, XInt32 aExtClipRight, 
  XInt32 aExtClipTop, XInt32 aExtClipBottom );

/* Wrapper function for the non virtual method : 'Core::Group.ExtendClipping()' */
void CoreGroup__ExtendClipping( void* _this, XInt32 aExtClipLeft, XInt32 aExtClipRight, 
  XInt32 aExtClipTop, XInt32 aExtClipBottom );

/* The following define announces the presence of the method Core::Group.ExtendClipping(). */
#define _CoreGroup__ExtendClipping_

/* The method DrawForeground() is invoked automatically if parts of the GUI component 
   should be redrawn on the screen. This can occur when e.g. the component has been 
   moved or the appearance of the enclosed views has changed before.
   DrawForeground() is invoked after all other views existing inside the component 
   are drawn. Thus it can be used to implement sophisticated foreground drawing 
   operations. By overriding this method in a descending class the desired drawing 
   operations can be implemented individually.
   This method is invoked by the framework, so you will never need to invoke this 
   method directly. However you can request an invocation of this method by calling 
   the method @InvalidateArea().
   The passed parameters determine the drawing destination aCanvas and the area 
   to redraw aClip in the coordinate space of the canvas. The parameter aOffset 
   contains the displacement between the origin of the GUI component and the origin 
   of the canvas. You will need it to convert the drawing coordinates into these 
   of the canvas.
   The parameter aOpacity contains the resulting @Opacity value to apply on the 
   drawn contents. It lies in range 0 .. 255. The parameter aBlend contains the 
   resulting @AlphaBlended mode to apply. It determines, whether the drawing operations 
   should be performed with alpha-blending active or not. If aBlend is false, the 
   drawn contents should overwrite the corresponding pixel in the drawing destination 
   aCanvas. If aBlend is true, the outputs should be mixed with the pixel already 
   stored in aCanvas. For this purpose all Graphics Engine functions provide a parameter 
   to specify the mode for the respective drawing operation.
   Please note also the method @DrawBackground(), which is invoked before the views 
   belonging to the component have begun their drawing operations. */
void CoreGroup_DrawForeground( CoreGroup _this, GraphicsCanvas aCanvas, XRect aClip, 
  XPoint aOffset, XInt32 aOpacity, XBool aBlend );

/* The method DrawBackground() is invoked automatically if parts of the GUI component 
   should be redrawn on the screen. This can occur when e.g. the component has been 
   moved or the appearance of the enclosed views has changed before.
   DrawBackground() is invoked before all other views existing inside the component 
   are drawn. Thus it can be used to implement sophisticated background filling 
   operations. By overriding this method in a descending class the desired drawing 
   operations can be implemented individually.
   This method is invoked by the framework, so you will never need to invoke this 
   method directly. However you can request an invocation of this method by calling 
   the method @InvalidateArea().
   The passed parameters determine the drawing destination aCanvas and the area 
   to redraw aClip in the coordinate space of the canvas. The parameter aOffset 
   contains the displacement between the origin of the GUI component and the origin 
   of the canvas. You will need it to convert the drawing coordinates into these 
   of the canvas.
   The parameter aOpacity contains the resulting @Opacity value to apply on the 
   drawn contents. It lies in range 0 .. 255. The parameter aBlend contains the 
   resulting @AlphaBlended mode to apply. It determines, whether the drawing operations 
   should be performed with alpha-blending active or not. If aBlend is false, the 
   drawn contents should overwrite the corresponding pixel in the drawing destination 
   aCanvas. If aBlend is true, the outputs should be mixed with the pixel already 
   stored in aCanvas. For this purpose all Graphics Engine functions provide a parameter 
   to specify the mode for the respective drawing operation.
   Please note also the method @DrawForeground(), which is invoked after all views 
   belonging to the component have finalized their drawing operations. */
void CoreGroup_DrawBackground( CoreGroup _this, GraphicsCanvas aCanvas, XRect aClip, 
  XPoint aOffset, XInt32 aOpacity, XBool aBlend );

/* The method GetMaximalSize() provides a common interface to ask the component 
   for the maximum possible size it can assume by still correctly displaying the 
   contents enclosed inside it. This information can thereupon be used in complex 
   layout application cases to equally adjust multiple components, etc. Please note 
   also the method @GetMinimalSize().

   The default implementation of this method does nothing and returns $ScreenSize 
   value. If necessary, you can override the method and implement an algorithm to 
   calculate from the actual content of the GUI component its maximum size. For 
   example, if the component displays some text, the calculation can take in account 
   the space needed for this text if it is not broken in multiple rows. The maximum 
   size corresponds then to the maximum width of the text. */
XPoint CoreGroup_GetMaximalSize( CoreGroup _this );

/* Wrapper function for the non virtual method : 'Core::Group.GetMaximalSize()' */
XPoint CoreGroup__GetMaximalSize( void* _this );

/* The following define announces the presence of the method Core::Group.GetMaximalSize(). */
#define _CoreGroup__GetMaximalSize_

/* The method GetMinimalSize() provides a common interface to ask the component 
   for the minimum possible size it can assume by still correctly displaying the 
   contents enclosed inside it. This information can thereupon be used in complex 
   layout application cases to equally adjust multiple components, etc. Please note 
   also the method @GetMaximalSize().

   The default implementation of this method does nothing and returns <0,0> value. 
   If necessary, you can override the method and implement an algorithm to calculate 
   from the actual content of the GUI component its minimum size. For example, if 
   the component displays some text, the calculation can take in account the space 
   needed for this text. */
XPoint CoreGroup_GetMinimalSize( CoreGroup _this );

/* Wrapper function for the non virtual method : 'Core::Group.GetMinimalSize()' */
XPoint CoreGroup__GetMinimalSize( void* _this );

/* The following define announces the presence of the method Core::Group.GetMinimalSize(). */
#define _CoreGroup__GetMinimalSize_

/* The method LocalPosition() converts the given position aPoint from the screen 
   coordinate space to the coordinate space of this component and returns the calculated 
   position. In the case the component isn't visible within the application, the 
   method can fail and return a wrong position. */
XPoint CoreGroup_LocalPosition( CoreGroup _this, XPoint aPoint );

/* The method DispatchEvent() feeds the component with the event passed in the parameter 
   aEvent and propagates it along the so-called focus path. This focus path leads 
   to the currently selected keyboard event receiver view. If the event is rejected 
   by the view, the same operation is repeated for the next superior view. This 
   permits the hierarchical event dispatching until a willing view has handled the 
   event or all views in the focus path have been evaluated. If the event remains 
   still unhandled, it will be passed to the component itself.
   The focus path is established by the property @Focus. 
   DispatchEvent() returns the value returned by the @HandleEvent() method of the 
   view which has handled the event. In the case, the event was not handled, the 
   method returns 'null'. */
XObject CoreGroup_DispatchEvent( CoreGroup _this, CoreEvent aEvent );

/* Wrapper function for the virtual method : 'Core::Group.DispatchEvent()' */
XObject CoreGroup__DispatchEvent( void* _this, CoreEvent aEvent );

/* The following define announces the presence of the method Core::Group.DispatchEvent(). */
#define _CoreGroup__DispatchEvent_

/* The method BroadcastEventAtPosition() feeds the component with the event passed 
   in the parameter aEvent and propagates it to all views, which do exist within 
   the component and do enclose the given position aPosition until the event has 
   been handled or all affected views are evaluated. If the event remains still 
   unhandled, it will be passed to the component itself.
   Beside the position, the additional parameter aFilter can be used to limit the 
   operation to special views only, e.g. to visible and touchable views.
   BroadcastEventAtPosition() is very useful to provide views with one and the same 
   event in order e.g. to inform the views about an important global state alteration. 
   The parameters aPosition and aFilter limit the operation to particular views. 
   To send events to all views regardless of their position use the method @BroadcastEvent().
   BroadcastEventAtPosition() returns the value returned by the @HandleEvent() method 
   of the view which has handled the event. In the case, the event was not handled, 
   the method returns 'null'. */
XObject CoreGroup_BroadcastEventAtPosition( CoreGroup _this, CoreEvent aEvent, XPoint 
  aPosition, XSet aFilter );

/* Wrapper function for the non virtual method : 'Core::Group.BroadcastEventAtPosition()' */
XObject CoreGroup__BroadcastEventAtPosition( void* _this, CoreEvent aEvent, XPoint 
  aPosition, XSet aFilter );

/* The following define announces the presence of the method Core::Group.BroadcastEventAtPosition(). */
#define _CoreGroup__BroadcastEventAtPosition_

/* The method BroadcastEvent() feeds the component with the event passed in the 
   parameter aEvent and propagates it to all views enclosed within the component 
   until the event has been handled or all views are evaluated. If the event remains 
   still unhandled, it will be passed to the component itself.
   The additional parameter aFilter can be used to limit the operation to special 
   views only, e.g. to visible and touchable views. To broadcast the event to all 
   views pass in the parameter aFilter the value 'Core::ViewState[]'.
   BroadcastEvent() is very useful to provide all views with one and the same event 
   in order e.g. to inform all views about an important global state alteration. 
   To send events to views enclosing a given position use the method @BroadcastEventAtPosition().
   BroadcastEvent() returns the value returned by the @HandleEvent() method of the 
   view which has handled the event. In the case, the event was not handled, the 
   method returns 'null'. */
XObject CoreGroup_BroadcastEvent( CoreGroup _this, CoreEvent aEvent, XSet aFilter );

/* Wrapper function for the virtual method : 'Core::Group.BroadcastEvent()' */
XObject CoreGroup__BroadcastEvent( void* _this, CoreEvent aEvent, XSet aFilter );

/* The following define announces the presence of the method Core::Group.BroadcastEvent(). */
#define _CoreGroup__BroadcastEvent_

/* The method UpdateLayout() is invoked automatically after the size of the component 
   has been changed. This method can be overridden and filled with logic to perform 
   a sophisticated arrangement calculation for one or more enclosed views. In this 
   case the parameter aSize can be used. It contains the current size of the component. 
   Usually, all enclosed views are arranged automatically accordingly to their @Layout 
   property. UpdateLayout() gives the derived components a chance to extend this 
   automatism by a user defined algorithm. */
void CoreGroup_UpdateLayout( CoreGroup _this, XPoint aSize );

/* The method UpdateViewState() is invoked automatically after the state of the 
   component has been changed. This method can be overridden and filled with logic 
   to ensure the visual aspect of the component does reflect its current state. 
   For example, the 'enabled' state of the component can affect its colors (disabled 
   components may appear pale). In this case the logic of the method should modify 
   the respective color properties accordingly to the current 'enabled' state. 
   The current state of the component is passed as a set in the parameter aState. 
   It reflects the very basic component state like its visibility or the ability 
   to react to user inputs. Beside this common state, the method can also involve 
   any other variables used in the component as long as they reflect its current 
   state. For example, the toggle switch component can take in account its toggle 
   state 'on' or 'off' and change accordingly the location of the slider, etc.
   Usually, this method will be invoked automatically by the framework. Optionally 
   you can request its invocation by using the method @InvalidateViewState(). */
void CoreGroup_UpdateViewState( CoreGroup _this, XSet aState );

/* The method InvalidateViewState() declares the state of this component as changed, 
   so its visual aspect possibly doesn't reflect its current state anymore. To update 
   the visual aspect, the framework will invoke the @UpdateViewState() method. */
void CoreGroup_InvalidateViewState( CoreGroup _this );

/* The method InvalidateArea() declares the given area of the component as invalid, 
   this means this area should be redrawn at the next screen update. */
void CoreGroup_InvalidateArea( CoreGroup _this, XRect aArea );

/* Wrapper function for the virtual method : 'Core::Group.InvalidateArea()' */
void CoreGroup__InvalidateArea( void* _this, XRect aArea );

/* The method FindSiblingView() searches for a sibling view of the view specified 
   in the parameter aView - aView itself will be excluded from the search operation.
   The method combines the functionality of @FindNextView() and @FindPrevView() 
   and tries to find any neighbor view (regarding the Z-order not the position).
   The additional parameter aFilter can be used to limit the search operation to 
   special views only, e.g. to visible and touchable views.
   If there are no other views complying the filter condition, the method returns 
   'null'. In contrast to other find methods, FindSiblingView() will fail, if it 
   has been invoked with aView == 'null'. */
CoreView CoreGroup_FindSiblingView( CoreGroup _this, CoreView aView, XSet aFilter );

/* The method Remove() removes the given view aView from the component. After this 
   operation the view doesn't belong anymore to the component - the view is not 
   visible and it can't receive any events.
   Please note, removing of views from a component containing a Core::Outline view 
   can cause this outline to update its automatic row or column formation.
   Please note, it the removed view is currently selected by the @Focus property, 
   the framework will automatically select other sibling view, which will be able 
   to react to keyboard events. */
void CoreGroup_Remove( CoreGroup _this, CoreView aView );

/* The method Add() inserts the given view aView into this component and places 
   it at a Z-order position resulting primarily from the parameter aOrder. The parameter 
   determines the number of sibling views the view has to skip over starting with 
   the top most view. If aOrder == 0, the newly added view will obtain the top most 
   position. If the value is negative, the view will be lowered to the background 
   accordingly to the absolute value of aOrder. After this operation the view belongs 
   to the component - the view can appear on the screen and it can receive events.
   The effective stacking position of the view can additionally be affected by the 
   value of the view's property @StackingPriority. Concrete, the view is prevented 
   from being arranged in front of any sibling view configured with a higher @StackingPriority 
   value. Similarly the view can't be arranged behind any sibling view having lower 
   @StackingPriority value.
   Please note, adding of views to a component containing a Core::Outline view can 
   cause this outline to update its automatic row or column formation. */
void CoreGroup_Add( CoreGroup _this, CoreView aView, XInt32 aOrder );

#ifdef __cplusplus
  }
#endif

#endif /* _CoreGroup_H */

/* Embedded Wizard */
