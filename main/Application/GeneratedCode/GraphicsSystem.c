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

#include "ewlocale.h"
#include "_GraphicsSystemDeviceClass.h"
#include "GraphicsSystem.h"

/* Initializer for the class 'GraphicsSystem::DeviceClass' */
void GraphicsSystemDeviceClass__Init( GraphicsSystemDeviceClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  TemplatesDeviceClass__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( GraphicsSystemDeviceClass );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( GraphicsSystemDeviceClass );

  /* ... and initialize objects, variables, properties, etc. */
  _this->AcceleratorActive = 1;

  /* Call the user defined constructor */
  GraphicsSystemDeviceClass_Init( _this, aArg );
}

/* Re-Initializer for the class 'GraphicsSystem::DeviceClass' */
void GraphicsSystemDeviceClass__ReInit( GraphicsSystemDeviceClass _this )
{
  /* At first re-initialize the super class ... */
  TemplatesDeviceClass__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'GraphicsSystem::DeviceClass' */
void GraphicsSystemDeviceClass__Done( GraphicsSystemDeviceClass _this )
{
  /* Call the user defined destructor of the class */
  GraphicsSystemDeviceClass_Done( _this );

  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( TemplatesDeviceClass );

  /* Don't forget to deinitialize the super class ... */
  TemplatesDeviceClass__Done( &_this->_.Super );
}

/* 'C' function for method : 'GraphicsSystem::DeviceClass.OnSetAcceleratorActive()' */
void GraphicsSystemDeviceClass_OnSetAcceleratorActive( GraphicsSystemDeviceClass _this, 
  XBool value )
{
  _this->AcceleratorActive = value;
  /* place here the code to change accelerator state */
  EwNotifyRefObservers( EwNewRef( _this, GraphicsSystemDeviceClass_OnGetAcceleratorActive, 
    GraphicsSystemDeviceClass_OnSetAcceleratorActive ), 0 );
}

/* The method 'GetCpuLoad' returns the current CPU usage in percent since last call 
   of this method. */
XInt32 GraphicsSystemDeviceClass_GetCpuLoad( GraphicsSystemDeviceClass _this )
{
  XInt32 result;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  result = 0;
  /* place here the code for reading CPU usage */
  return result;
}

/* 'C' function for method : 'GraphicsSystem::DeviceClass.Init()' */
void GraphicsSystemDeviceClass_Init( GraphicsSystemDeviceClass _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );
}

/* 'C' function for method : 'GraphicsSystem::DeviceClass.Done()' */
void GraphicsSystemDeviceClass_Done( GraphicsSystemDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Default onget method for the property 'AcceleratorActive' */
XBool GraphicsSystemDeviceClass_OnGetAcceleratorActive( GraphicsSystemDeviceClass _this )
{
  return _this->AcceleratorActive;
}

/* Variants derived from the class : 'GraphicsSystem::DeviceClass' */
EW_DEFINE_CLASS_VARIANTS( GraphicsSystemDeviceClass )
EW_END_OF_CLASS_VARIANTS( GraphicsSystemDeviceClass )

/* Virtual Method Table (VMT) for the class : 'GraphicsSystem::DeviceClass' */
EW_DEFINE_CLASS( GraphicsSystemDeviceClass, TemplatesDeviceClass, _.VMT, _.VMT, 
                 _.VMT, _.VMT, _.VMT, _.VMT, "GraphicsSystem::DeviceClass" )
EW_END_OF_CLASS( GraphicsSystemDeviceClass )

/* User defined auto object: 'GraphicsSystem::Device' */
EW_DEFINE_AUTOOBJECT( GraphicsSystemDevice, GraphicsSystemDeviceClass )

/* Initializer for the auto object 'GraphicsSystem::Device' */
void GraphicsSystemDevice__Init( GraphicsSystemDeviceClass _this )
{
  EW_UNUSED_ARG( _this );
}

/* Re-Initializer for the auto object 'GraphicsSystem::Device' */
void GraphicsSystemDevice__ReInit( GraphicsSystemDeviceClass _this )
{
  EW_UNUSED_ARG( _this );
}

/* Table with links to derived variants of the auto object : 'GraphicsSystem::Device' */
EW_DEFINE_AUTOOBJECT_VARIANTS( GraphicsSystemDevice )
EW_END_OF_AUTOOBJECT_VARIANTS( GraphicsSystemDevice )

/* Embedded Wizard */
