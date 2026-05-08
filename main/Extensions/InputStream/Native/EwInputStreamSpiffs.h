/*******************************************************************************
*
* Embedded Wizard - GUI Solutions by TARA Systems
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* DESCRIPTION:
*   This file declares the SPIFFS InputStream interface for ESP32.
*
*******************************************************************************/

#ifndef EWINPUTSTREAMSPIFFS_H
#define EWINPUTSTREAMSPIFFS_H

#include "EwInputStream.h"

XInputStream EwInputStreamSpiffsCreate( char* aFilePath );

#endif
