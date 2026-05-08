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

#ifndef _CoreTaskQueue_H
#define _CoreTaskQueue_H

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

/* Forward declaration of the class Core::Task */
#ifndef _CoreTask_
  EW_DECLARE_CLASS( CoreTask )
#define _CoreTask_
#endif

/* Forward declaration of the class Core::TaskQueue */
#ifndef _CoreTaskQueue_
  EW_DECLARE_CLASS( CoreTaskQueue )
#define _CoreTaskQueue_
#endif


/* The class Core::TaskQueue provides a simple task scheduler component. The component 
   implements functionality to register, manage and perform tasks. A task can be 
   e.g. an animated transition between two GUI components. With the task queue, 
   several independent transitions (and another operations) can be executed strictly 
   one after another.
   Usually the tasks are executed in the order in which they were previously added 
   to the queue (the order in which they are scheduled). The queue takes care that 
   at the same time only one task is executed. This task is called the 'current' 
   task. As soon as the current task is completed, the queue activates the next 
   available task.
   A single task is represented by an instance of a class derived from Core::Task. 
   To schedule a task, create an instance of the task class and call the method 
   @ScheduleTask() with the task as parameter.
   With the method @CancelTask() you can remove a previously scheduled task from 
   the queue again or if the task is already running, stop it and let the queue 
   continue with the next task.
   The method @GetCurrentTask() is useful to determine which task is currently in 
   progress by the affected queue.
   It is essential to understand, that the entire 'task' functionality has nothing 
   to do with multi-threading or multi-tasking features known from operating systems. 
   Applications developed with Chora are limited to a single-thread environment. 
   There is no real background thread activity. Accordingly your implementation 
   of a task should behave cooperatively. A well designed task should perform its 
   job quickly, use timers or effects to delay execution and when the job is done 
   inform the queue about its completion. */
EW_DEFINE_FIELDS( CoreTaskQueue, XObject )
  EW_VARIABLE( current,         CoreTask )
  EW_VARIABLE( last,            CoreTask )
  EW_VARIABLE( first,           CoreTask )
  EW_VARIABLE( isInOnStart,     XBool )
EW_END_OF_FIELDS( CoreTaskQueue )

/* Virtual Method Table (VMT) for the class : 'Core::TaskQueue' */
EW_DEFINE_METHODS( CoreTaskQueue, XObject )
EW_END_OF_METHODS( CoreTaskQueue )

/* 'C' function for method : 'Core::TaskQueue.completeTask()' */
void CoreTaskQueue_completeTask( CoreTaskQueue _this );

/* 'C' function for method : 'Core::TaskQueue.onDispatchNext()' */
void CoreTaskQueue_onDispatchNext( CoreTaskQueue _this, XObject sender );

/* 'C' function for method : 'Core::TaskQueue.onPreDispatchNext3()' */
void CoreTaskQueue_onPreDispatchNext3( CoreTaskQueue _this, XObject sender );

/* 'C' function for method : 'Core::TaskQueue.onPreDispatchNext2()' */
void CoreTaskQueue_onPreDispatchNext2( CoreTaskQueue _this, XObject sender );

/* 'C' function for method : 'Core::TaskQueue.onPreDispatchNext1()' */
void CoreTaskQueue_onPreDispatchNext1( CoreTaskQueue _this, XObject sender );

/* The method CancelTask() allows the application to remove a previously registered 
   task from the task queue. The affected task is determined by the parameter aTask.
   If the affected task is currently executed, the task is notified to immediately 
   finalize its work. Afterwards the queue starts the next available task. The method 
   will throw an error if you try to cancel a task not belonging to this queue. */
void CoreTaskQueue_CancelTask( CoreTaskQueue _this, CoreTask aTask );

/* The method ScheduleTask() registers the task passed in the parameter aTask for 
   later execution.
   The tasks are executed in the order in which they have been previously scheduled. 
   If the parameter aWithPriority is false, the new task will be arranged at the 
   end of the list with waiting tasks. If the parameter is true, the task is enqueued 
   in front of all waiting tasks.
   The method will throw an error if you try to schedule the same task twice. */
void CoreTaskQueue_ScheduleTask( CoreTaskQueue _this, CoreTask aTask, XBool aWithPriority );

#ifdef __cplusplus
  }
#endif

#endif /* _CoreTaskQueue_H */

/* Embedded Wizard */
