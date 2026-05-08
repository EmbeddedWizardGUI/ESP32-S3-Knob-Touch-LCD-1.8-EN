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
*   This template provides a system event mechanism, that can be used in
*   combination with an operating system to sleep and to continue (resume) the
*   operation of the UI main loop.
*
*******************************************************************************/

#include "ewconfig.h"
#include "ew_bsp_os.h"
#include "ew_bsp_clock.h"
#include "ew_bsp_event.h"

#if EW_USE_OPERATING_SYSTEM == 1

  #define OS_SIGNAL_WAKEUP_UI  0x00000001

  static XThreadHandle ThreadHandle = 0;

#endif


/*******************************************************************************
* FUNCTION:
*   EwBspEventWait
*
* DESCRIPTION:
*   The function EwBspEventWait should be called from the Embedded
*   Wizard main loop in case there are no pending events, signals or timers that
*   have to be processed by the UI application.
*   The function EwBspEventWait is used to sleep the given time span or
*   to suspend the UI task. The function returns as soon as a new system event
*   occurs or when the given timeout value is expired.
*   Typically, a system event is a touch event or a key event or any event
*   from your device driver.
*
* ARGUMENTS:
*   aTimeout - timeout value in milliseconds.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspEventWait( int aTimeout )
{
  if ( aTimeout > 0 )
  {
    CPU_LOAD_SET_IDLE();

    #if EW_USE_OPERATING_SYSTEM == 1

      /* save the thread ID for signaling */
      if ( ThreadHandle == 0 )
        ThreadHandle = EwBspOsThreadGetHandle();

      /* Important note: Within this template, the timeout value is limited to
         10 ms in order to ensure that the UI application is continuously working,
         e.g. to get new touch values or to receive data from a device driver.
         This makes the usage of this template very simple.
         If you want to implement a completely event driven system, you can use
         the given timeout without limiting it. In this case you have to ensure
         that the touch driver or your device drivers are resuming the UI task
         by calling TriggerSystemEvent().
      */
      if ( aTimeout > 10 )
        aTimeout = 10;

      EwBspOsSignalWait( OS_SIGNAL_WAKEUP_UI, aTimeout );

    #else

      /* in bare metal maximum wait time is 10 ms to keep main loop running */
      if ( aTimeout > 10 )
        aTimeout = 10;

      EwBspOsDelay( aTimeout );

    #endif

    CPU_LOAD_SET_ACTIVE();
  }
}


/*******************************************************************************
* FUNCTION:
*   EwBspEventTrigger
*
* DESCRIPTION:
*   The function EwBspEventTrigger is used in combination with an
*   operating system to continue (resume) the operation of the UI main loop.
*   Typically, a system event is a touch event or a key event or any event
*   from your device driver.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspEventTrigger( void )
{
  #if EW_USE_OPERATING_SYSTEM == 1

    EwBspOsSignalSet( ThreadHandle, OS_SIGNAL_WAKEUP_UI );

  #endif
}


/* msy */
