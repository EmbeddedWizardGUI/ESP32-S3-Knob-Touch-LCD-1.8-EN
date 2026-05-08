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
*   This file implements an interface between an Embedded Wizard generated UI
*   application and a certain device. Please consider this file only as template
*   that is intended to show the binding between an UI application and the
*   underlying system (e.g. middleware, BSP, hardware driver, protocol, ...).
*
*   This device driver is the counterpart to a device class implemented within
*   your Embedded Wizard project.
*
*   Feel free to adapt this file according your needs!
*
*   The following code demonstrates the access to the board LED, a simulated
*   ADC value and the hardware button. Furthemore, the console interface is used
*   to print a string.
*
*   The Embedded Wizard GUI example 'DeviceIntegration' shows the usage of this
*   device driver.
*
*   This file assumes to be the counterpart of the device class 'DeviceClass'
*   within the unit 'Application'.
*
*******************************************************************************/

/*
   Include all necessary files to access the real device and/or to get access
   to the required operating system calls.
*/
#include "ewrte.h"
#include "ew_bsp_inout.h"
#include "ew_bsp_os.h"
#include "esp_attr.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"

/*
   Include the generated header file to access the device class, for example to
   access the class 'DeviceClass' from the unit 'Application' include the
   generated file 'Application.h'.
*/
#include "Application.h"
#include "i2c_bsp.h"
#include "user_encoder_bsp.h"

/* DRV2605 Vibration Motor Driver Registers */
#define DRV2605_REG_STATUS    0x00
#define DRV2605_REG_MODE      0x01
#define DRV2605_REG_RTPIN     0x02
#define DRV2605_REG_LIBRARY   0x03
#define DRV2605_REG_WAVEFORM1 0x04
#define DRV2605_REG_WAVEFORM2 0x05
#define DRV2605_REG_GO        0x0C
#define DRV2605_REG_FEEDBACK  0x1A
#define DRV2605_REG_CONTROL3  0x1D
#define DRV2605_REG_CONTROL4  0x1E
#define DRV2605_REG_VBAT      0x21
#define DRV2605_REG_LRARESON  0x22

#define DRV2605_MODE_INTTRIG  0x00  /* Internal trigger mode */
#define DRV2605_MODE_REALTIME 0x05  /* Real-time playback (RTP) mode - continuous */
#define DRV2605_LIBRARY_5     0x05  /* LRA library */

#if EW_USE_OPERATING_SYSTEM == 1

  static volatile XThreadHandle WorkerThread = 0;

  static volatile XThreadHandle EncoderWorkerThread = 0;
  static void EncoderWorkerThread_Task( const void* arg );
#endif

static volatile int DeviceInitialized = 0;

/*
   In order to ensure that the example code of this module is only compiled
   and linked to the example 'DeviceIntegration', we check for generated defines.
*/
#if ( defined _ApplicationDeviceClass__TriggerHardButtonEvent_ && defined _ApplicationDeviceClass__UpdateAdcValue_ )
  #define DEVICE_INTEGRATION_EXAMPLE
#endif

#ifdef DEVICE_INTEGRATION_EXAMPLE

/*******************************************************************************
* FUNCTION:
*   UpdateAdcValueProc
*
* DESCRIPTION:
*   This function is used to inform the GUI application about a new ADC value by
*   calling the method UpdateAdcValue of the device class.
*   Please note, that this function has to be called in the context of the main
*   GUI thread/task. Use EwInvoke() to ensure the invocation of this function
*   in the right context.
*
*******************************************************************************/
static void UpdateAdcValueProc( const void* aData )
{
  int adcValue = *((int*)aData);

  /* only in case that the device driver is still initialized and the worker
     thread is still running, the data should be provided to the device class
     - otherwise, a new autoobject will be created and a new worker thread
     started... */
  if ( DeviceInitialized )
  {
    ApplicationDeviceClass device = EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass );
    ApplicationDeviceClass__UpdateAdcValue( device, adcValue );
  }
}

/*******************************************************************************
* FUNCTION:
*   TriggerHardButtonEventProc
*
* DESCRIPTION:
*   This function is used to trigger a system event in the GUI application by
*   calling the method TriggerHardButtonEvent of the device class.
*   Please note, that this function has to be called in the context of the main
*   GUI thread/task. Use EwInvoke() to ensure the invocation of this function
*   in the right context.
*
*******************************************************************************/
static void TriggerHardButtonEventProc( const void* aData )
{
  ApplicationDeviceClass device = EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass );
  ApplicationDeviceClass__TriggerHardButtonEvent( device );
}


/*******************************************************************************
* FUNCTION:
*   HardButtonIsrCallback
*
* DESCRIPTION:
*   Callback function for the hardware button. This function is called every time
*   the hardware button is pressed or released.
*   Please note, that this function is called from the interrupt service routine!
*
*******************************************************************************/
void IRAM_ATTR HardButtonIsrCallback( int aButtonPressed )
{
  /*
     Important note: This function is called from an interrupt handler and not
     in the context of the main GUI thread/task. NEVER make a direct function
     call to a method of the driver class or any other generated code
     from an interrupt handler or any other thread/task.
     EwInvoke() or EwInvokeCopy() have to be used to schedule the invocation of
     the desired method in the context of the GUI thread/task.
  */
  if ( aButtonPressed )
    EwInvoke( TriggerHardButtonEventProc, 0 );
}


/*******************************************************************************
* FUNCTION:
*   DeviceIntegrationExample_Init
*
* DESCRIPTION:
*   This is the initialization function used for the example 'DeviceIntegration'.
*   It initializes the hardware that should be accessed from the GUI. If the
*   GUI application is running in an operating system, a separate worker-thread
*   will be created to showcase the data processing as separate thread.
*
*******************************************************************************/
void DeviceIntegrationExample_Init( void )
{
  /* check for initialization */
  if ( DeviceInitialized )
    return;

  /* Initialize DRV2605 vibration motor */
  uint8_t data;

  /* Set mode to internal trigger */
  data = DRV2605_MODE_INTTRIG;
  i2c_write_buff(drv2605_dev_handle, DRV2605_REG_MODE, &data, 1);

  /* Select library 5 (LRA library) */
  data = DRV2605_LIBRARY_5;
  i2c_write_buff(drv2605_dev_handle, DRV2605_REG_LIBRARY, &data, 1);

  /* Initialize encoder */
  user_encoder_init();

  DeviceInitialized = 1;

#if EW_USE_OPERATING_SYSTEM == 1
  /* create and start the worker thread to process encoder events */
  EncoderWorkerThread = EwBspOsThreadCreate( EncoderWorkerThread_Task, EW_BSP_OS_THREAD_PRIORITY_NORMAL, 4096, 0 );
#endif
}


/*******************************************************************************
* FUNCTION:
*   DeviceIntegrationExample_Done
*
* DESCRIPTION:
*   This is the de-initialization function of the example 'DeviceIntegration'.
*   It de-initializes the hardware that was accessed from the GUI. If the
*   GUI application is running in an operating system, the separate worker-thread
*   will be terminated.
*
*******************************************************************************/
void DeviceIntegrationExample_Done( void )
{
  DeviceInitialized = 0;

#if EW_USE_OPERATING_SYSTEM == 1
  /* wait until the worker thread is really terminated */
  while ( EncoderWorkerThread )
    EwBspOsDelay( 1 );
#endif

  /* Stop any ongoing vibration */
  uint8_t data = 0;
  i2c_write_buff(drv2605_dev_handle, DRV2605_REG_WAVEFORM1, &data, 1);
}


/*******************************************************************************
* FUNCTION:
*   DeviceIntegrationExample_SetLedStatus
*
* DESCRIPTION:
*   This is a sample for a function called from the device class, when a
*   property has changed. As a result, the corresponding value of the real
*   device should be changed.
*   In this implementation the LED is switched on or off.
*
*******************************************************************************/
void DeviceIntegrationExample_SetLedStatus( XInt32 aValue )
{
  /* Control vibration motor instead of LED - toggle mode (continuous on/off) */
  uint8_t data;

  if (aValue)
  {
    /* Turn ON continuous vibration using Real-Time Playback (RTP) mode */

    /* Set mode to RTP (Real-time playback) for continuous vibration */
    data = DRV2605_MODE_REALTIME;
    i2c_write_buff(drv2605_dev_handle, DRV2605_REG_MODE, &data, 1);

    /* Set RTP input value to 0x7F (50% strength, continuous) */
    /* Valid range: 0x00 (off) to 0xFF (max strength) */
    data = 0x7F;  /* Medium strength continuous vibration */
    i2c_write_buff(drv2605_dev_handle, DRV2605_REG_RTPIN, &data, 1);
  }
  else
  {
    /* Turn OFF vibration by setting RTP input to 0 */
    data = 0x00;
    i2c_write_buff(drv2605_dev_handle, DRV2605_REG_RTPIN, &data, 1);

    /* Return to standby/internal trigger mode */
    data = DRV2605_MODE_INTTRIG;
    i2c_write_buff(drv2605_dev_handle, DRV2605_REG_MODE, &data, 1);
  }
}


/*******************************************************************************
* FUNCTION:
*   DeviceIntegrationExample_PrintMessage
*
* DESCRIPTION:
*   This is a sample for a function that is called directly from a 'Command'
*   method of the device class. As a result, the corresponding action should
*   happen.
*   In this implementation the given message is printed via the console interface.
*
*******************************************************************************/
void DeviceIntegrationExample_PrintMessage( XString aText )
{
  /* Print the message */
  EwPrint( "Message: %S\n", aText );
}


#if EW_USE_OPERATING_SYSTEM == 1

/*******************************************************************************
* FUNCTION:
*   EncoderWorkerThread_Task
*
* DESCRIPTION:
*   Worker thread that monitors the encoder event group and forwards encoder
*   rotation events to the GUI application as ADC value updates.
*
*******************************************************************************/
static void EncoderWorkerThread_Task( const void* arg )
{
  EventBits_t bits;
  int adcValue = 0;  /* Start at midpoint */

  while ( DeviceInitialized )
  {
    /* Wait for encoder events (bit 0 = LEFT, bit 1 = RIGHT) */
    bits = xEventGroupWaitBits(knob_even_, 0x03, pdTRUE, pdFALSE, 50 / portTICK_PERIOD_MS);

    if (bits & 0x01)
    {
      /* LEFT rotation - decrease ADC value (no clamping for infinite rotation) */
      adcValue = adcValue - 10;
      EwInvokeCopy( UpdateAdcValueProc, &adcValue, sizeof( int ));
    }

    if (bits & 0x02)
    {
      /* RIGHT rotation - increase ADC value (no clamping for infinite rotation) */
      adcValue = adcValue + 10;
      EwInvokeCopy( UpdateAdcValueProc, &adcValue, sizeof( int ));
    }
  }

  /* terminate the worker thread */
  EncoderWorkerThread = 0;
  EwBspOsThreadDestroy( EwBspOsThreadGetHandle());
}
#endif
#endif /* DEVICE_INTEGRATION_EXAMPLE */

/*******************************************************************************
* FUNCTION:
*   DeviceDriver_Initialize
*
* DESCRIPTION:
*   The function DeviceDriver_Initialize() initializes the module and prepares all
*   necessary things to access or communicate with the real device.
*   The function has to be called from your main module, before the initialization
*   of your GUI application.
*
*   IMPORTANT NOTE: This global initialization function exists for compatibility
*   reasons. The initialization of dedicated hardware drivers or middleware APIs
*   should be done in separate functions called by the Init constructor of the
*   device class.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void DeviceDriver_Initialize( void )
{
  /*
     You can implement here the necessary code to initialize your particular
     hardware, to open needed devices, to open communication channels, etc.
  */
}


/*******************************************************************************
* FUNCTION:
*   DeviceDriver_Deinitialize
*
* DESCRIPTION:
*   The function DeviceDriver_Deinitialize() deinitializes the module and
*   finalizes the access or communication with the real device.
*   The function has to be called from your main module, after the GUI
*   application will be deinitialized.
*
*   IMPORTANT NOTE: This global de-initialization function exists for
*   compatibility reasons. It is recommend to use the Done destructor of the
*   device class.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void DeviceDriver_Deinitialize( void )
{
  /*
     You can implement here the necessary code to deinitialize your particular
     hardware, to close used devices, to close communication channels, etc.
  */
}


/*******************************************************************************
* FUNCTION:
*   DeviceDriver_ProcessData
*
* DESCRIPTION:
*   The function DeviceDriver_ProcessData() is called from the main UI loop, in
*   order to process data and events from your particular device.
*   This function is responsible to update properties within the device class
*   if the corresponding state or value of the real device has changed.
*   This function is also responsible to trigger system events if necessary.
*
*   IMPORTANT NOTE: This data processing function can be used to process data
*   periodically in the context of the main GUI thread/task or in case there
*   is no operating system at all (bare metal).
*   In case you want to feed the GUI application with data and events from a
*   foreign thread/task or an interrupt service routine it will be much easier
*   to use the functions EwInvoke() and EwInvokeCopy().
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   The function returns a non-zero value if a property has changed or if a
*   system event was triggered. If nothing happens, the function returns 0.
*
*******************************************************************************/
int DeviceDriver_ProcessData( void )
{
  int needUpdate = 0;

  /*
     Get the data you want to provide to the GUI application.
     Please note, that this function is called within the context of the main
     GUI thread/task.
  */

  #ifdef DEVICE_INTEGRATION_EXAMPLE

    /* the following code is used only in case of bare metal when there is no
       separate thread/task running */
    #if EW_USE_OPERATING_SYSTEM == 0

      static int simulatedAdcValue = 0;

      /* in order to simplify the example, the ADC value is just simulated - it
         could be read from a real ADC by using corresponding BSP functions... */
      simulatedAdcValue = ( simulatedAdcValue + 1 ) % 1024;

      /* due to the fact that this code is executed only in case there is no
        operating system used (bare metal), there is no need to use EwInvoke()
        here - so the update function can be called directly */
      UpdateAdcValueProc( &simulatedAdcValue );

      needUpdate = 1;

    #endif

  #endif /* DEVICE_INTEGRATION_EXAMPLE */

  /*
     Return a value != 0 if there is at least one property changed or if a
     system event was triggered. The return value is used by the main loop, to
     decide whether the GUI application has changed or not.
  */
  return needUpdate;
}


/* msy */
