/*******************************************************************************
*
* Embedded Wizard - GUI Solutions by TARA Systems
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This software and related documentation (the "Library") are intellectual
* property of TARA Systems GmbH.
*
* Use of this file and the Library is governed as follows:
*
*   (1) To the extent your use is covered by the Embedded Wizard License
*       Agreement (EWLA) and the Embedded Wizard Terms and Conditions (EWTC),
*       or by another written commercial license agreement with TARA Systems
*       GmbH that expressly covers this Library, that agreement governs;
*       otherwise
*
*   (2) Your use is governed by the Embedded Wizard Community License (EWCL).
*
* Absent such a commercial license as in (1), distribution of products including
* this Library may require you to provide the complete corresponding Application
* Source Code, as described in the Embedded Wizard Community License (EWCL).
*
* Any use, modification, copying, reproduction, or redistribution of this file
* not in accordance with the applicable license is expressly prohibited. The
* removal of this preamble is expressly prohibited.
*
* License information:
*   EWTC: https://www.embedded-wizard.de/legal/ewtc
*   EWLA: https://www.embedded-wizard.de/legal/ewla
*   EWCL: https://www.embedded-wizard.de/legal/ewcl
*
********************************************************************************
*
* DESCRIPTION:
*   This header file belongs to the external platform adaptation layer of the
*   Embedded Wizard Runtime Environment. It abstracts the interface between the
*   platform independent core of Runtime Environment and the underlying, target
*   specific operating system and the used 'C' compiler version.
*
*   This header provides the interface by using the GCC compiler environment.
*
*******************************************************************************/


/* Provide access to variable-argument lists (va_list, va_arg, ...) */
#include <stdarg.h>
#include <stdatomic.h>

/******************************************************************************
* TYPE:
*   XAtomic
*
* DESCRIPTION:
*   The type definition XAtomic represents a compiler or OS specific version
*   of an ordinary signed integer type (at least 32-bit large) suitable for
*   atomic add, sub and load operations.
*
******************************************************************************/
typedef atomic_long XAtomic;


/* pba */
