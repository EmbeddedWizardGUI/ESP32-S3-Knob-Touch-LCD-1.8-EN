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
*   This template is responsible to configurate the entire system (CPU clock,
*   memory, qspi, etc).
*
*******************************************************************************/

#include "ewconfig.h"
#include "ew_bsp_system.h"

/*******************************************************************************
* FUNCTION:
*   EwBspSystemInit
*
* DESCRIPTION:
*   The function EwBspSystemInit initializes the system components.
*   (CPU clock, memory, qspi, ...)
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspSystemInit( void )
{
}


/*******************************************************************************
* FUNCTION:
*   EwBspSystemDone
*
* DESCRIPTION:
*   The function EwBspSystemDone terminates the system components.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspSystemDone( void )
{
}


/*******************************************************************************
* FUNCTION:
*   EwBspSystemInvalidateCache
*
* DESCRIPTION:
*   The function EwBspSystemInvalidateCache is called from the Graphics Engine
*   to invalidate the data cache for a certain memory area defined by the
*   parameters aAddress and aSize.
*   The function is called after the GPU has modified a memory area and before
*   the CPU is accessing this memory area. In this case, cache invalidation
*   ensures that the cache does not contain old content.
*
* ARGUMENTS:
*   aAddress       - Startaddress of the memory area to invalidate in data cache.
*   aSize t        - Size of the memory area in bytes.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspSystemInvalidateCache( void* aAddress, unsigned int aSize )
{
}


/*******************************************************************************
* FUNCTION:
*   EwBspSystemCleanCache
*
* DESCRIPTION:
*   The function EwBspSystemCleanCache is called from the Graphics Engine
*   to clean (flush) the data cache for a certain memory area defined by the
*   parameters aAddress and aSize.
*   The function is called after the CPU has modified a memory area and before
*   the GPU or the display controller is reading this memory area. In this case,
*   cache cleaning ensures that the cache does not keep prepared data.
*
* ARGUMENTS:
*   aAddress       - Startaddress of the memory area to invalidate in data cache.
*   aSize t        - Size of the memory area in bytes.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspSystemCleanCache( void* aAddress, unsigned int aSize )
{
}


/* msy */
