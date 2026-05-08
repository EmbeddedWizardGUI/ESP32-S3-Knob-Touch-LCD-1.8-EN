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
*   This file provides some operating system wrapper macros.
*
*******************************************************************************/

#include "ewconfig.h"
#include "ew_bsp_os.h"

#if EW_USE_OPERATING_SYSTEM == 1

  #include "freertos/FreeRTOS.h"
  #include "freertos/task.h"
  #include "freertos/semphr.h"

  void xPortSysTickHandler( void );

  #define OPERATING_SYSTEM_STRING "FreeRTOS"

  typedef void ( *XThreadFunct_ )( void* aContext );

#else

  #define OPERATING_SYSTEM_STRING "bare-metal"

  #error "Bare-metal not supported on ESP32 targets - set EW_USE_OPERATING_SYSTEM=1 in your makefile/project"

#endif


/*******************************************************************************
* FUNCTION:
*   EwBspOsGetName
*
* DESCRIPTION:
*   The function EwBspOsGetName returns the name of the operating system.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   The name of the operating system.
*
*******************************************************************************/
const char* EwBspOsGetName( void )
{
  return OPERATING_SYSTEM_STRING;
}


/*******************************************************************************
* FUNCTION:
*   EwBspOsSystickHandler
*
* DESCRIPTION:
*   The function EwBspOsSystickHandler handles the tick increment of the operating
*   system. It has to be called on every millisecond. It can be called directly
*   from interrupt service routine (ISR).
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspOsSystickHandler( void )
{
  #if EW_USE_OPERATING_SYSTEM == 1

    if ( xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED )
      xPortSysTickHandler();

  #else

  #endif
}


/*******************************************************************************
* FUNCTION:
*   EwBspOsGetTicks
*
* DESCRIPTION:
*   The function EwBspOsGetTicks returns the system ticks in milliseconds.
*   The system tick counter wraps around every 2^32's tick.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   The system Ticks.
*
*******************************************************************************/
unsigned long EwBspOsGetTicks( void )
{
  #if EW_USE_OPERATING_SYSTEM == 1

    return xTaskGetTickCount() * portTICK_PERIOD_MS;

  #else

  #endif
}


/*******************************************************************************
* FUNCTION:
*   EwBspOsDelay
*
* DESCRIPTION:
*   The function EwBspOsDelay delays the own thread by the given milliseconds
*   and allows the OS scheduler to process other threads.
*
* ARGUMENTS:
*   aDelayTime - The delay time in milliseconds.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspOsDelay( unsigned int aDelayTime )
{
  #if EW_USE_OPERATING_SYSTEM == 1

    vTaskDelay( aDelayTime / portTICK_PERIOD_MS );

  #else

  #endif
}


#if EW_USE_OPERATING_SYSTEM == 1

/*******************************************************************************
* FUNCTION:
*   EwBspOsThreadCreate
*
* DESCRIPTION:
*   The function EwBspOsThreadCreate creates a thread using the provided thread
*   function, priority, stack size and context.
*
* ARGUMENTS:
*   aFunct     - The thread function.
*   aPrio      - The thread priority.
*   aStackSize - The maximum stack size needed by the thread.
*   aContext   - The context that is passed to the thread function.
*
* RETURN VALUE:
*   The thread handle (XThreadHandle)
*
*******************************************************************************/
XThreadHandle EwBspOsThreadCreate( XThreadFunct aFunct, int aPrio, int aStackSize, void* aContext )
{
  TaskHandle_t threadHandle = NULL;

  if ( xTaskCreate( (XThreadFunct_)aFunct, "", aStackSize / 4, aContext, aPrio, &threadHandle ) != pdPASS )
    threadHandle = NULL;

  return (XThreadHandle)threadHandle;
}


/*******************************************************************************
* FUNCTION:
*   EwBspOsThreadDestroy
*
* DESCRIPTION:
*   The function EwBspOsThreadDestroy destroys a thread and frees all related
*   resources.
*
* ARGUMENTS:
*   aHandle - The handle of the thread (XThreadHandle).
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspOsThreadDestroy( XThreadHandle aHandle )
{
  vTaskDelete( aHandle );
}


/*******************************************************************************
* FUNCTION:
*   EwBspOsThreadGetHandle
*
* DESCRIPTION:
*   The function EwBspOsThreadGetHandle returns the own thread handle.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   The thread handle (XThreadHandle).
*
*******************************************************************************/
XThreadHandle EwBspOsThreadGetHandle( void )
{
  return xTaskGetCurrentTaskHandle();
}


/*******************************************************************************
* FUNCTION:
*   EwBspOsSignalWait
*
* DESCRIPTION:
*   The function EwBspOsSignalWait waits until all specified signal flags are set
*   or until any single flag is set, if no flag is specified.
*   EwBspOsSignalWait returns at the latest after the provided timeout value
*   (aTimeout=0 means no timeout).
*
* ARGUMENTS:
*   aSignalFlags  - The bit field of signal flags EwBspOsSignalWait has to wait
*                   for.
*   aTimeout      - The latest time in milliseconds EwBspOsSignalWait returns.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspOsSignalWait( unsigned int aSignalFlags, unsigned int aTimeout )
{
  /* not allowed in ISR */
  if ( xPortInIsrContext() != 0 )
    return;

  xTaskNotifyWait( 0, aSignalFlags, NULL, aTimeout / portTICK_PERIOD_MS );
}


/*******************************************************************************
* FUNCTION:
*   EwBspOsSignalSet
*
* DESCRIPTION:
*   The function EwBspOsSignalSet sets one or more signal flags. It can be called
*   from threads and interrupt service routines (ISR).
*
* ARGUMENTS:
*   aThreadHandle - The thread handle (XThreadHandle) were the given signal
*                   flags has to be set.
*   aSignalFlags  - The bit field of signal flags to be set.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspOsSignalSet( XThreadHandle aThreadHandle, unsigned int aSignalFlags )
{
  portBASE_TYPE taskWoken = pdFALSE;

  xTaskNotify( aThreadHandle, aSignalFlags, eSetBits );

  if ( xPortInIsrContext() != 0 )
  {
    xTaskNotifyFromISR( aThreadHandle, aSignalFlags, eSetBits, &taskWoken );
    portYIELD_FROM_ISR( taskWoken );
  }
  else
    xTaskNotify( aThreadHandle, aSignalFlags, eSetBits );
}


/*******************************************************************************
* FUNCTION:
*   EwBspOsSemaphoreCreate
*
* DESCRIPTION:
*   The function EwBspOsSemaphoreCreate creates a semaphore using the provided
*   semaphore definition and initial value.
*
* ARGUMENTS:
*   aMaxCount     - The maximum count for the semaphore object.
*   aInitialValue - The initial value of the semaphore.
*
* RETURN VALUE:
*   The semaphore handle (XSemaphoreHandle).
*
*******************************************************************************/
XSemaphoreHandle EwBspOsSemaphoreCreate( int aMaxCount, int aInitialValue )
{
  return xSemaphoreCreateCounting( aMaxCount, aInitialValue );
}


/*******************************************************************************
* FUNCTION:
*   EwBspOsSemaphoreWait
*
* DESCRIPTION:
*   The function EwBspOsSemaphoreWait waits until a semaphore token becomes
*   available. It returns at the latest after the provided timeout value
*   (aTimeout=0 means no timeout).
*
* ARGUMENTS:
*   aHandle  - The semaphore handle (XSemaphoreHandle).
*   aTimeout - The latest time in milliseconds EwBspOsSemaphoreWait returns.
*
* RETURN VALUE:
*   Returns 1, if a token is available, otherwise 0.
*
*******************************************************************************/
int EwBspOsSemaphoreWait( XSemaphoreHandle aHandle, int aTimeout )
{
  TickType_t    ticks = 0;

  if ( aHandle  == NULL)
    return -1;

  if ( aTimeout == 0 )
    ticks = portMAX_DELAY;
  else
  {
    ticks = aTimeout / portTICK_PERIOD_MS;
    if ( ticks == 0 )
      ticks = 1;
  }

  if ( xPortInIsrContext() != 0 )
  {
    portBASE_TYPE taskWoken = pdFALSE;
    if ( xSemaphoreTakeFromISR( aHandle, &taskWoken ) != pdTRUE )
      return 0;

    portYIELD_FROM_ISR( taskWoken );
  }
  else
    if ( xSemaphoreTake( aHandle, ticks ) != pdTRUE )
      return 0;

  return 1;
}


/*******************************************************************************
* FUNCTION:
*   EwBspOsSemaphoreRelease
*
* DESCRIPTION:
*   The function EwBspOsSemaphoreRelease releases a semaphore token.
*
* ARGUMENTS:
*   aHandle  - The semaphore handle (XSemaphoreHandle).
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspOsSemaphoreRelease( XSemaphoreHandle aHandle )
{
  if ( xPortInIsrContext() != 0 )
  {
    portBASE_TYPE taskWoken = pdFALSE;
    xSemaphoreGiveFromISR( aHandle, &taskWoken);
    portYIELD_FROM_ISR( taskWoken );
  }
  else
    xSemaphoreGive( aHandle );
}


/*******************************************************************************
* FUNCTION:
*   EwBspOsSemaphoreDestroy
*
* DESCRIPTION:
*   The function EwBspOsSemaphoreDestroy destroys a semaphore and frees all related
*   resources.
*
* ARGUMENTS:
*   aHandle - The handle of the semaphore to destroy (XSemaphoreHandle).
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspOsSemaphoreDestroy( XSemaphoreHandle aHandle )
{
  vSemaphoreDelete( aHandle );
}


/*******************************************************************************
* FUNCTION:
*   EwBspOsStartScheduler
*
* DESCRIPTION:
*   The function EwBspOsStartScheduler starts the scheduler of the operating system.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspOsStartScheduler( void )
{
  vTaskStartScheduler();
}

#endif /* EW_USE_OPERATING_SYSTEM */


/* mli */
