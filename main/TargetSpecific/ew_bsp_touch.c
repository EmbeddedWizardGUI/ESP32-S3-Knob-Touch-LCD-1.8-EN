/*******************************************************************************
*
* Embedded Wizard - GUI Solutions by TARA Systems
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This software is provided as example code to demonstrate the use of Embedded
* Wizard and related software components. It may be used in production systems
* after you have reviewed, tested and adapted it to your specific requirements.
*
* Use of this example code is subject to the Embedded Wizard license terms
* (as published at https://www.embedded-wizard.de/legal), including in
* particular:
*
*   - Embedded Wizard Terms and Conditions (EWTC)
*   - Embedded Wizard License Agreement (EWLA)
*   - Embedded Wizard Community License (EWCL)
*
* The specific agreement(s) applicable to you depend on your contractual
* relationship with TARA Systems GmbH and/or your use of the Community License.
*
* Subject to your compliance with the applicable Embedded Wizard license terms
* and/or any separate written agreement with TARA Systems, you are granted a
* non-exclusive, worldwide, royalty-free license to use, copy, modify and
* integrate this example code into your own software products and projects.
* You may redistribute this code only as part of your products and not as a
* standalone library, framework or development tool.
*
* THE SOFTWARE IS PROVIDED "AS IS" AND "AS AVAILABLE", WITHOUT WARRANTY OF ANY
* KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT.
* TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, IN NO EVENT SHALL TARA
* SYSTEMS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
* ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
* WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
********************************************************************************
*
* DESCRIPTION:
*   This file is part of the interface (glue layer) between an Embedded Wizard
*   generated UI application and the board support package (BSP) of a dedicated
*   target.
*   This template is responsible to initialize the touch driver of the display
*   hardware and to receive the touch events for the UI application.
*   Important: This file is intended to be used as a template. Please adapt the
*   implementation according your particular hardware.
*
*******************************************************************************/

#include <string.h>

#include "ewconfig.h"
#include "ewrte.h"

#include "ew_bsp_clock.h"
#include "ew_bsp_display.h"
#include "ew_bsp_touch.h"

#include "esp_err.h"
#include "esp_log.h"
#include "lcd_touch_bsp.h"
#include "i2c_bsp.h"

#define NO_OF_FINGERS                   1

/* additional touch flag to indicate idle state */
#define EW_BSP_TOUCH_IDLE               0

/* additional touch flag to indicate hold state */
#define EW_BSP_TOUCH_HOLD               4 

static int           TouchAreaMinX  =  0; /* raw touch value of the leftmost position on the touch screen */
static int           TouchAreaMinY  =  0; /* raw touch value of the topmost position on the touch screen */
static int           TouchAreaMaxX  =  0; /* raw touch value of the rightmost position on the touch screen */
static int           TouchAreaMaxY  =  0; /* raw touch value of the bottommost position on the touch screen */
static int           DisplayWidth   =  0; /* width of the display */
static int           DisplayHeight  =  0; /* height of the display */
static unsigned char TouchState     =  EW_BSP_TOUCH_IDLE;
static int           IsInitalized   =  0;
static XTouchEvent   TouchEvent[ NO_OF_FINGERS ];

/////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// OBSOLETE //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

#define I2C_MASTER_SCL_IO           9         // GPIO number used for I2C master clock
#define I2C_MASTER_SDA_IO           8         // GPIO number used for I2C master data
#define I2C_MASTER_NUM              0         // I2C master i2c port number, the number of i2c peripheral interfaces available will depend on the chip
#define I2C_MASTER_FREQ_HZ          400000    // I2C master clock frequency
#define I2C_MASTER_TX_BUF_DISABLE   0         // I2C master doesn't need buffer
#define I2C_MASTER_RX_BUF_DISABLE   0         // I2C master doesn't need buffer
#define I2C_MASTER_TIMEOUT_MS       1000      // I2C Timeout

#define CH422G_Mode                 0x24      // Control the mode
#define CH422G_Mode_IO_OE           0x01      // Output enabled
#define CH422G_Mode_A_SCAN          0x02      // Dynamic display automatic scanning enabled
#define CH422G_Mode_OD_EN           0x04      // The output pins OC3 ~ OC0 open drain output enable
#define CH422G_Mode_SLEEP           0x08      // Low power sleep control

#define CH422G_OD_OUT               0x23      // Control the OC pin output
#define CH422G_OD_OUT_0             0x01      // OC0 => DO0
#define CH422G_OD_OUT_1             0x02      // OC1 => DO1
#define CH422G_OD_OUT_2             0x04      // OC2
#define CH422G_OD_OUT_3             0x08      // OC3

#define CH422G_IO_OUT               0x38      // Control the IO pin output
#define CH422G_IO_OUT_0             0x01      // IO0 => DI0 use
#define CH422G_IO_OUT_1             0x02      // IO1 => Output ...
#define CH422G_IO_OUT_2             0x04      // IO2 => Output ...
#define CH422G_IO_OUT_3             0x08      // IO3 => Output ...
#define CH422G_IO_OUT_4             0x10      // IO4 => Output ...
#define CH422G_IO_OUT_5             0x20      // IO5 => DI1 use
#define CH422G_IO_OUT_6             0x40      // IO6
#define CH422G_IO_OUT_7             0x80      // IO7

#define CH422G_IO_IN                0x26      // Read the IO pin status
#define CH422G_IO_0                 0x01      // IO0 => Input ...
#define CH422G_IO_1                 0x02      // IO1 => Touch reset
#define CH422G_IO_2                 0x04      // IO2 => Backlight control
#define CH422G_IO_3                 0x08      // IO3 => LCD liquid crystal reset
#define CH422G_IO_4                 0x10      // IO4 => SD card CS pin
#define CH422G_IO_5                 0x20      // IO5 => Input ...
#define CH422G_IO_6                 0x40      // IO6
#define CH422G_IO_7                 0x80      // IO7

/////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// OBSOLETE //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

/*******************************************************************************
* FUNCTION:
*   EwBspTouchInit
*
* DESCRIPTION:
*   Initalizes the touch driver interface. The provided display information is
*   used to configure the touch driver interface so that a proper mapping of
*   touch coordinates to GUI coordinates can be done.
*
* ARGUMENTS:
*   aGuiWidth,
*   aGuiHeight   - Size of the GUI in pixel.
*   aDisplayInfo - Display info data structure.
*
* RETURN VALUE:
*   Returns 1 if successful, 0 otherwise.
*
*******************************************************************************/
int EwBspTouchInit( int aGuiWidth, int aGuiHeight, XDisplayInfo* aDisplayInfo )
{
  EW_UNUSED_ARG( aGuiWidth );
  EW_UNUSED_ARG( aGuiHeight );

  /* clear all touch state variables */
  memset( TouchEvent, 0, sizeof( TouchEvent ));

  /* check display info structure */
  if ( !aDisplayInfo )
  {
    EwPrint( "EwBspTouchInit: Invalid DisplayInfo!\n" );
    return 0;
  }

  /* initialize touch controller (I2C already initialized in display init) */
  lcd_touch_init();
  
  /* take physical size of display from provided display info structure */
  DisplayWidth   = aDisplayInfo->DisplayWidth;
  DisplayHeight  = aDisplayInfo->DisplayHeight;

  /* take touch calibration values */
  TouchAreaMinX = EW_TOUCH_AREA_MIN_X;
  TouchAreaMinY = EW_TOUCH_AREA_MIN_Y;
  TouchAreaMaxX = EW_TOUCH_AREA_MAX_X;
  TouchAreaMaxY = EW_TOUCH_AREA_MAX_Y;

  /* check touch calibration and configuration to avoid division by zero */
  if (( TouchAreaMaxX == TouchAreaMinX ) || ( TouchAreaMaxY == TouchAreaMinY ))
  {
    EwPrint( "EwBspTouchInit: Invalid touch area!\n" );
    return 0;
  }


  #ifdef EW_PRINT_TOUCH_DATA

    EwPrint( "\n" );
    EwPrint( "EwBspTouchInit: Using TouchArea %d, %d - %d, %d\n", TouchAreaMinX, TouchAreaMinY, TouchAreaMaxX, TouchAreaMaxY );

  #endif

  IsInitalized = 1;
  return 1;
}


/*******************************************************************************
* FUNCTION:
*   EwBspTouchDone
*
* DESCRIPTION:
*   Terminates the touch driver.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspTouchDone( void )
{
  IsInitalized = 0;
}


/*******************************************************************************
* FUNCTION:
*   EwBspTouchGetEvents
*
* DESCRIPTION:
*   The function EwBspTouchGetEvents reads the current touch positions from the
*   touch driver and returns the current touch position and touch status of the
*   different fingers. The returned number of touch events indicates the number
*   of XTouchEvent that contain position and status information.
*   The orientation of the touch positions is adjusted to match GUI coordinates.
*   If the hardware supports only single touch, the finger number is always 0.
*
* ARGUMENTS:
*   aTouchEvent - Pointer to return array of XTouchEvent.
*
* RETURN VALUE:
*   Returns the number of detected touch events, otherwise 0.
*
*******************************************************************************/
int EwBspTouchGetEvents( XTouchEvent** aTouchEvent )
{
  int                    touchX;
  int                    touchY;
  int                    x, y;
  int                    noOfEvents     = 0;
  uint8_t                touchpad_pressed;
  uint16_t               touch_x;
  uint16_t               touch_y;
  unsigned long          ticks;
  static unsigned long   ticksLastDown  = 0;
  static unsigned long   ticksLastUp    = 0;

  if ( !IsInitalized )
    return 0;

  /* access touch driver to receive current touch status and position */
  CPU_LOAD_SET_IDLE();
  touchpad_pressed = tpGetCoordinates(&touch_x, &touch_y);
  CPU_LOAD_SET_ACTIVE();

  /* get current time in ms */
  ticks = EwGetTicks();

  if ( touchpad_pressed )
  {
    #ifdef EW_PRINT_TOUCH_DATA

      EwPrint( "Raw touch data: x %d, y %d\n", touch_x, touch_y );

    #endif

    /* apply swapping of raw touch coordinates if required */
    #if ( EW_TOUCH_SWAP_XY )

      touchX = touch_y;
      touchY = touch_x;

    #else

      touchX = touch_x;
      touchY = touch_y;

    #endif

    /* convert raw touch coordinates into display coordinates */
    touchX = (( touchX - TouchAreaMinX ) * DisplayWidth ) / ( TouchAreaMaxX - TouchAreaMinX );
    touchY = (( touchY - TouchAreaMinY ) * DisplayHeight ) / ( TouchAreaMaxY - TouchAreaMinY );

    if (( touchX > 0 ) && ( touchX < DisplayWidth  - 1 ) &&
        ( touchY > 0 ) && ( touchY < DisplayHeight - 1 ))
    {
      /* convert display coordinates into GUI coordinates */
      #if ( EW_SURFACE_ROTATION == 90 )

        x = touchY;
        y = DisplayWidth - touchX;

      #elif ( EW_SURFACE_ROTATION == 270 )

        x = DisplayHeight - touchY;
        y = touchX;

      #elif ( EW_SURFACE_ROTATION == 180 )

        x = DisplayWidth - touchX;
        y = DisplayHeight - touchY;

      #else

        x = touchX;
        y = touchY;

      #endif

      #ifdef EW_PRINT_TOUCH_DATA

        EwPrint( "GUI coordinates: x %d, y %d\n", x, y );

      #endif

      ticksLastDown = ticks;

      if ( ticks - ticksLastUp < 40 )
        return 0;

      if ( TouchState == EW_BSP_TOUCH_IDLE )
        TouchState = EW_BSP_TOUCH_DOWN;
      else
      {
        /* suppress move events when position unchanged */
        if (( x == TouchEvent[ 0 ].XPos ) && ( y == TouchEvent[ 0 ].YPos ))
          return 0;

        TouchState = EW_BSP_TOUCH_MOVE;
      }

      TouchEvent[ 0 ].XPos   = x;
      TouchEvent[ 0 ].YPos   = y;
      TouchEvent[ 0 ].State  = TouchState;
      noOfEvents = 1;
    }
  }
  else
  {
    /* touch driver provides permanently 'up' events while finger is pressed - in order
       to avoid that a touch sequence is interrupted by unwished 'up' events we have to
       filter over a certain time period until a real 'up' event is detected */
    if (( TouchState != EW_BSP_TOUCH_IDLE ) && ( ticks - ticksLastDown > 40 ))
    {
      TouchEvent[ 0 ].State  = EW_BSP_TOUCH_UP;
      TouchState = EW_BSP_TOUCH_IDLE;
      noOfEvents = 1;
      ticksLastUp = ticks;
    }
  }

  #ifdef EW_PRINT_TOUCH_EVENTS

    if ( noOfEvents == 1 )
      EwPrint( "Touch event for finger 0 with state %d ( %4d, %4d )\n", TouchEvent[ 0 ].State, TouchEvent[ 0 ].XPos, TouchEvent[ 0 ].YPos );

  #endif

  /* return the prepared touch events and the number of prepared touch events */
  if ( aTouchEvent )
    *aTouchEvent = TouchEvent;

  return noOfEvents;
}


/* msy */
