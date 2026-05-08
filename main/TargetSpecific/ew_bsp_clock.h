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
*   This template is responsible to initialize the system clock of the hardware,
*   to provide a timer tick for the Embedded Wizard UI application and to get
*   access to the realtime clock (RTC). Additionally, this file contains some
*   performance measurements to analyse the CPU usage of the UI application.
*
*******************************************************************************/

#ifndef EW_BSP_CLOCK_H
#define EW_BSP_CLOCK_H


#ifdef __cplusplus
  extern "C"
  {
#endif

#if EW_CPU_LOAD_MEASURING == 1
  #define CPU_LOAD_SET_IDLE()           EwBspClockCpuLoadSetIdle()
  #define CPU_LOAD_SET_ACTIVE()         EwBspClockCpuLoadSetActive()
#else
  #define CPU_LOAD_SET_IDLE()
  #define CPU_LOAD_SET_ACTIVE()
#endif


/*******************************************************************************
* FUNCTION:
*   EwBspClockInit
*
* DESCRIPTION:
*   Initialises the system clock and the real time clock.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspClockInit
(
  void
);


/*******************************************************************************
* FUNCTION:
*   EwBspClockGetTime
*
* DESCRIPTION:
*   Returns the current time in seconds since 01.01.1970.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   The current time in seconds since 01.01.1970.
*
*******************************************************************************/
unsigned long EwBspClockGetTime
(
  void
);


/*******************************************************************************
* FUNCTION:
*   EwBspClockSetTime
*
* DESCRIPTION:
*   Sets the given time in seconds since 01.01.1970 at real time clock (RTC).
*
* ARGUMENTS:
*   aTime - the time in seconds since 01.01.1970 to set in real time clock.
*
* RETURN VALUE:
*   None.
*
*******************************************************************************/
void EwBspClockSetTime
(
  unsigned long aTime
);


/*******************************************************************************
* FUNCTION:
*   EwBspClockGetCpuLoad
*
* DESCRIPTION:
*   Returns the current CPU load as percent value.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   The current CPU load.
*
*******************************************************************************/
int EwBspClockGetCpuLoad
(
  void
);


/*******************************************************************************
* FUNCTION:
*   EwBspClockCpuLoadSetActive
*
* DESCRIPTION:
*   Starts the CPU load counting. Call this function whenever CPU processing
*   is needed.
*
* ARGUMENTS:
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspClockCpuLoadSetActive
(
  void
);


/*******************************************************************************
* FUNCTION:
*   EwBspClockCpuLoadSetIdle
*
* DESCRIPTION:
*   Stops the CPU load counting. Call this function whenever CPU processing is
*   currently not needed since the program execution is waiting for some system
*   event.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspClockCpuLoadSetIdle
(
  void
);


#ifdef __cplusplus
  }
#endif

#endif /* EW_BSP_CLOCK_H */


/* msy */
