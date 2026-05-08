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
*   This template is responsible to initialize the display hardware of the board
*   and to provide the necessary access to update the display content.
*   The color format of the framebuffer has to correspond to the color format
*   of the Graphics Engine.
*
*   Important: This file is intended to be used as a template. Please adapt the
*   implementation according your particular hardware.
*
*******************************************************************************/

#include "esp_system.h"
#include "esp_heap_caps.h"

/* flags to choose one of the provided display drivers */

#include <string.h>

#include "ewconfig.h"
#include "ewrte.h"
#include "ewgfx.h"
#include "ewextgfx.h"
#include "ewgfxdefs.h"

#include "ew_bsp_display.h"

#include <stdio.h>
#include "esp_log.h"
#include "esp_heap_caps.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_sh8601.h"
#include "i2c_bsp.h"
#include "lcd_bl_pwm_bsp.h"
#include "user_config.h"

static esp_lcd_panel_handle_t panelHandle = NULL;

#if ((EW_FRAME_BUFFER_COLOR_FORMAT == EW_FRAME_BUFFER_COLOR_FORMAT_Index8) || (EW_FRAME_BUFFER_COLOR_FORMAT == EW_FRAME_BUFFER_COLOR_FORMAT_LumA44))
static unsigned short Clut[256];
#endif

static uint8_t *ScratchPad = 0;
static uint8_t *TransferBuffer = 0;

// SH8601 LCD initialization commands (from reference implementation)
static const sh8601_lcd_init_cmd_t lcd_init_cmds[] = {
    {0xF0, (uint8_t[]){0x28}, 1, 0},
    {0xF2, (uint8_t[]){0x28}, 1, 0},
    {0x73, (uint8_t[]){0xF0}, 1, 0},
    {0x7C, (uint8_t[]){0xD1}, 1, 0},
    {0x83, (uint8_t[]){0xE0}, 1, 0},
    {0x84, (uint8_t[]){0x61}, 1, 0},
    {0xF2, (uint8_t[]){0x82}, 1, 0},
    {0xF0, (uint8_t[]){0x00}, 1, 0},
    {0xF0, (uint8_t[]){0x01}, 1, 0},
    {0xF1, (uint8_t[]){0x01}, 1, 0},
    {0xB0, (uint8_t[]){0x56}, 1, 0},
    {0xB1, (uint8_t[]){0x4D}, 1, 0},
    {0xB2, (uint8_t[]){0x24}, 1, 0},
    {0xB4, (uint8_t[]){0x87}, 1, 0},
    {0xB5, (uint8_t[]){0x44}, 1, 0},
    {0xB6, (uint8_t[]){0x8B}, 1, 0},
    {0xB7, (uint8_t[]){0x40}, 1, 0},
    {0xB8, (uint8_t[]){0x86}, 1, 0},
    {0xBA, (uint8_t[]){0x00}, 1, 0},
    {0xBB, (uint8_t[]){0x08}, 1, 0},
    {0xBC, (uint8_t[]){0x08}, 1, 0},
    {0xBD, (uint8_t[]){0x00}, 1, 0},
    {0xC0, (uint8_t[]){0x80}, 1, 0},
    {0xC1, (uint8_t[]){0x10}, 1, 0},
    {0xC2, (uint8_t[]){0x37}, 1, 0},
    {0xC3, (uint8_t[]){0x80}, 1, 0},
    {0xC4, (uint8_t[]){0x10}, 1, 0},
    {0xC5, (uint8_t[]){0x37}, 1, 0},
    {0xC6, (uint8_t[]){0xA9}, 1, 0},
    {0xC7, (uint8_t[]){0x41}, 1, 0},
    {0xC8, (uint8_t[]){0x01}, 1, 0},
    {0xC9, (uint8_t[]){0xA9}, 1, 0},
    {0xCA, (uint8_t[]){0x41}, 1, 0},
    {0xCB, (uint8_t[]){0x01}, 1, 0},
    {0xD0, (uint8_t[]){0x91}, 1, 0},
    {0xD1, (uint8_t[]){0x68}, 1, 0},
    {0xD2, (uint8_t[]){0x68}, 1, 0},
    {0xF5, (uint8_t[]){0x00, 0xA5}, 2, 0},
    {0xDD, (uint8_t[]){0x4F}, 1, 0},
    {0xDE, (uint8_t[]){0x4F}, 1, 0},
    {0xF1, (uint8_t[]){0x10}, 1, 0},
    {0xF0, (uint8_t[]){0x00}, 1, 0},
    {0xF0, (uint8_t[]){0x02}, 1, 0},
    {0xE0, (uint8_t[]){0xF0, 0x0A, 0x10, 0x09, 0x09, 0x36, 0x35, 0x33, 0x4A, 0x29, 0x15, 0x15, 0x2E, 0x34}, 14, 0},
    {0xE1, (uint8_t[]){0xF0, 0x0A, 0x0F, 0x08, 0x08, 0x05, 0x34, 0x33, 0x4A, 0x39, 0x15, 0x15, 0x2D, 0x33}, 14, 0},
    {0xF0, (uint8_t[]){0x10}, 1, 0},
    {0xF3, (uint8_t[]){0x10}, 1, 0},
    {0xE0, (uint8_t[]){0x07}, 1, 0},
    {0xE1, (uint8_t[]){0x00}, 1, 0},
    {0xE2, (uint8_t[]){0x00}, 1, 0},
    {0xE3, (uint8_t[]){0x00}, 1, 0},
    {0xE4, (uint8_t[]){0xE0}, 1, 0},
    {0xE5, (uint8_t[]){0x06}, 1, 0},
    {0xE6, (uint8_t[]){0x21}, 1, 0},
    {0xE7, (uint8_t[]){0x01}, 1, 0},
    {0xE8, (uint8_t[]){0x05}, 1, 0},
    {0xE9, (uint8_t[]){0x02}, 1, 0},
    {0xEA, (uint8_t[]){0xDA}, 1, 0},
    {0xEB, (uint8_t[]){0x00}, 1, 0},
    {0xEC, (uint8_t[]){0x00}, 1, 0},
    {0xED, (uint8_t[]){0x0F}, 1, 0},
    {0xEE, (uint8_t[]){0x00}, 1, 0},
    {0xEF, (uint8_t[]){0x00}, 1, 0},
    {0xF8, (uint8_t[]){0x00}, 1, 0},
    {0xF9, (uint8_t[]){0x00}, 1, 0},
    {0xFA, (uint8_t[]){0x00}, 1, 0},
    {0xFB, (uint8_t[]){0x00}, 1, 0},
    {0xFC, (uint8_t[]){0x00}, 1, 0},
    {0xFD, (uint8_t[]){0x00}, 1, 0},
    {0xFE, (uint8_t[]){0x00}, 1, 0},
    {0xFF, (uint8_t[]){0x00}, 1, 0},
    {0x60, (uint8_t[]){0x40}, 1, 0},
    {0x61, (uint8_t[]){0x04}, 1, 0},
    {0x62, (uint8_t[]){0x00}, 1, 0},
    {0x63, (uint8_t[]){0x42}, 1, 0},
    {0x64, (uint8_t[]){0xD9}, 1, 0},
    {0x65, (uint8_t[]){0x00}, 1, 0},
    {0x66, (uint8_t[]){0x00}, 1, 0},
    {0x67, (uint8_t[]){0x00}, 1, 0},
    {0x68, (uint8_t[]){0x00}, 1, 0},
    {0x69, (uint8_t[]){0x00}, 1, 0},
    {0x6A, (uint8_t[]){0x00}, 1, 0},
    {0x6B, (uint8_t[]){0x00}, 1, 0},
    {0x70, (uint8_t[]){0x40}, 1, 0},
    {0x71, (uint8_t[]){0x03}, 1, 0},
    {0x72, (uint8_t[]){0x00}, 1, 0},
    {0x73, (uint8_t[]){0x42}, 1, 0},
    {0x74, (uint8_t[]){0xD8}, 1, 0},
    {0x75, (uint8_t[]){0x00}, 1, 0},
    {0x76, (uint8_t[]){0x00}, 1, 0},
    {0x77, (uint8_t[]){0x00}, 1, 0},
    {0x78, (uint8_t[]){0x00}, 1, 0},
    {0x79, (uint8_t[]){0x00}, 1, 0},
    {0x7A, (uint8_t[]){0x00}, 1, 0},
    {0x7B, (uint8_t[]){0x00}, 1, 0},
    {0x80, (uint8_t[]){0x48}, 1, 0},
    {0x81, (uint8_t[]){0x00}, 1, 0},
    {0x82, (uint8_t[]){0x06}, 1, 0},
    {0x83, (uint8_t[]){0x02}, 1, 0},
    {0x84, (uint8_t[]){0xD6}, 1, 0},
    {0x85, (uint8_t[]){0x04}, 1, 0},
    {0x86, (uint8_t[]){0x00}, 1, 0},
    {0x87, (uint8_t[]){0x00}, 1, 0},
    {0x88, (uint8_t[]){0x48}, 1, 0},
    {0x89, (uint8_t[]){0x00}, 1, 0},
    {0x8A, (uint8_t[]){0x08}, 1, 0},
    {0x8B, (uint8_t[]){0x02}, 1, 0},
    {0x8C, (uint8_t[]){0xD8}, 1, 0},
    {0x8D, (uint8_t[]){0x04}, 1, 0},
    {0x8E, (uint8_t[]){0x00}, 1, 0},
    {0x8F, (uint8_t[]){0x00}, 1, 0},
    {0x90, (uint8_t[]){0x48}, 1, 0},
    {0x91, (uint8_t[]){0x00}, 1, 0},
    {0x92, (uint8_t[]){0x0A}, 1, 0},
    {0x93, (uint8_t[]){0x02}, 1, 0},
    {0x94, (uint8_t[]){0xDA}, 1, 0},
    {0x95, (uint8_t[]){0x04}, 1, 0},
    {0x96, (uint8_t[]){0x00}, 1, 0},
    {0x97, (uint8_t[]){0x00}, 1, 0},
    {0x98, (uint8_t[]){0x48}, 1, 0},
    {0x99, (uint8_t[]){0x00}, 1, 0},
    {0x9A, (uint8_t[]){0x0C}, 1, 0},
    {0x9B, (uint8_t[]){0x02}, 1, 0},
    {0x9C, (uint8_t[]){0xDC}, 1, 0},
    {0x9D, (uint8_t[]){0x04}, 1, 0},
    {0x9E, (uint8_t[]){0x00}, 1, 0},
    {0x9F, (uint8_t[]){0x00}, 1, 0},
    {0xA0, (uint8_t[]){0x48}, 1, 0},
    {0xA1, (uint8_t[]){0x00}, 1, 0},
    {0xA2, (uint8_t[]){0x05}, 1, 0},
    {0xA3, (uint8_t[]){0x02}, 1, 0},
    {0xA4, (uint8_t[]){0xD5}, 1, 0},
    {0xA5, (uint8_t[]){0x04}, 1, 0},
    {0xA6, (uint8_t[]){0x00}, 1, 0},
    {0xA7, (uint8_t[]){0x00}, 1, 0},
    {0xA8, (uint8_t[]){0x48}, 1, 0},
    {0xA9, (uint8_t[]){0x00}, 1, 0},
    {0xAA, (uint8_t[]){0x07}, 1, 0},
    {0xAB, (uint8_t[]){0x02}, 1, 0},
    {0xAC, (uint8_t[]){0xD7}, 1, 0},
    {0xAD, (uint8_t[]){0x04}, 1, 0},
    {0xAE, (uint8_t[]){0x00}, 1, 0},
    {0xAF, (uint8_t[]){0x00}, 1, 0},
    {0xB0, (uint8_t[]){0x48}, 1, 0},
    {0xB1, (uint8_t[]){0x00}, 1, 0},
    {0xB2, (uint8_t[]){0x09}, 1, 0},
    {0xB3, (uint8_t[]){0x02}, 1, 0},
    {0xB4, (uint8_t[]){0xD9}, 1, 0},
    {0xB5, (uint8_t[]){0x04}, 1, 0},
    {0xB6, (uint8_t[]){0x00}, 1, 0},
    {0xB7, (uint8_t[]){0x00}, 1, 0},
    {0xB8, (uint8_t[]){0x48}, 1, 0},
    {0xB9, (uint8_t[]){0x00}, 1, 0},
    {0xBA, (uint8_t[]){0x0B}, 1, 0},
    {0xBB, (uint8_t[]){0x02}, 1, 0},
    {0xBC, (uint8_t[]){0xDB}, 1, 0},
    {0xBD, (uint8_t[]){0x04}, 1, 0},
    {0xBE, (uint8_t[]){0x00}, 1, 0},
    {0xBF, (uint8_t[]){0x00}, 1, 0},
    {0xC0, (uint8_t[]){0x10}, 1, 0},
    {0xC1, (uint8_t[]){0x47}, 1, 0},
    {0xC2, (uint8_t[]){0x56}, 1, 0},
    {0xC3, (uint8_t[]){0x65}, 1, 0},
    {0xC4, (uint8_t[]){0x74}, 1, 0},
    {0xC5, (uint8_t[]){0x88}, 1, 0},
    {0xC6, (uint8_t[]){0x99}, 1, 0},
    {0xC7, (uint8_t[]){0x01}, 1, 0},
    {0xC8, (uint8_t[]){0xBB}, 1, 0},
    {0xC9, (uint8_t[]){0xAA}, 1, 0},
    {0xD0, (uint8_t[]){0x10}, 1, 0},
    {0xD1, (uint8_t[]){0x47}, 1, 0},
    {0xD2, (uint8_t[]){0x56}, 1, 0},
    {0xD3, (uint8_t[]){0x65}, 1, 0},
    {0xD4, (uint8_t[]){0x74}, 1, 0},
    {0xD5, (uint8_t[]){0x88}, 1, 0},
    {0xD6, (uint8_t[]){0x99}, 1, 0},
    {0xD7, (uint8_t[]){0x01}, 1, 0},
    {0xD8, (uint8_t[]){0xBB}, 1, 0},
    {0xD9, (uint8_t[]){0xAA}, 1, 0},
    {0xF3, (uint8_t[]){0x01}, 1, 0},
    {0xF0, (uint8_t[]){0x00}, 1, 0},
    {0x21, (uint8_t[]){0x00}, 1, 0},
    {0x11, (uint8_t[]){0x00}, 1, 120},
    {0x29, (uint8_t[]){0x00}, 1, 0},
#ifdef EXAMPLE_Rotate_90
    {0x36, (uint8_t[]){0x60}, 1, 0},
#else
    {0x36, (uint8_t[]){0x00}, 1, 0},
#endif
};

/*******************************************************************************
 * FUNCTION:
 *   EwBspDisplayInit
 *
 * DESCRIPTION:
 *   The function EwBspDisplayInit initializes the display hardware and returns
 *   the display parameter.
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
int EwBspDisplayInit(int aGuiWidth, int aGuiHeight, XDisplayInfo *aDisplayInfo)
{
  EW_UNUSED_ARG(aGuiWidth);
  EW_UNUSED_ARG(aGuiHeight);

  /* check and clean display info structure */
  if (!aDisplayInfo)
    return 0;
  memset(aDisplayInfo, 0, sizeof(XDisplayInfo));

  /* ensure that transfer buffer is not lost */
  if (TransferBuffer)
    heap_caps_free(TransferBuffer);

  /* allocate a transfer buffer that can be accessed by DMA */
  TransferBuffer = (uint8_t *)heap_caps_malloc(EW_SCRATCHPAD_WIDTH * EW_SCRATCHPAD_HEIGHT * 2, MALLOC_CAP_8BIT | MALLOC_CAP_DMA);
  if (!TransferBuffer)
    EwPrint("EwBspDisplayInit: Failed to allocated transfer buffer!\n");

  ScratchPad = (uint8_t *)heap_caps_malloc(EW_SCRATCHPAD_WIDTH * EW_SCRATCHPAD_HEIGHT * 2, MALLOC_CAP_8BIT);
  if (!ScratchPad)
    EwPrint("EwBspDisplayInit: Failed to allocated scratch pad buffer!\n");

  /* Initialize backlight PWM */
  lcd_bl_pwm_bsp_init(LCD_PWM_MODE_255);

  /* Initialize I2C bus (needed for touch controller) */
  i2c_master_Init();

  /* Initialize SPI bus for display */
  EwPrint("EwBspDisplayInit: Initialize SPI bus\n");
  const spi_bus_config_t buscfg = {
      .data0_io_num = EXAMPLE_PIN_NUM_LCD_DATA0,
      .data1_io_num = EXAMPLE_PIN_NUM_LCD_DATA1,
      .sclk_io_num = EXAMPLE_PIN_NUM_LCD_PCLK,
      .data2_io_num = EXAMPLE_PIN_NUM_LCD_DATA2,
      .data3_io_num = EXAMPLE_PIN_NUM_LCD_DATA3,
      .max_transfer_sz = EXAMPLE_LCD_H_RES * EXAMPLE_LCD_V_RES * sizeof(uint16_t),
  };
  if (spi_bus_initialize(LCD_HOST, &buscfg, SPI_DMA_CH_AUTO) != ESP_OK)
  {
    EwPrint("EwBspDisplayInit: Failed to initialize SPI bus!\n");
    return 0;
  }

  /* Install panel IO */
  EwPrint("EwBspDisplayInit: Install panel IO\n");
  esp_lcd_panel_io_handle_t io_handle = NULL;
  const esp_lcd_panel_io_spi_config_t io_config = SH8601_PANEL_IO_QSPI_CONFIG(
      EXAMPLE_PIN_NUM_LCD_CS,
      NULL,
      NULL);
  if (esp_lcd_new_panel_io_spi((esp_lcd_spi_bus_handle_t)LCD_HOST, &io_config, &io_handle) != ESP_OK)
  {
    EwPrint("EwBspDisplayInit: Failed to create panel IO!\n");
    return 0;
  }

  /* Install SH8601 panel driver */
  EwPrint("EwBspDisplayInit: Install SH8601 panel driver\n");
  sh8601_vendor_config_t vendor_config = {
      .init_cmds = lcd_init_cmds,
      .init_cmds_size = sizeof(lcd_init_cmds) / sizeof(lcd_init_cmds[0]),
      .flags = {
          .use_qspi_interface = 1,
      },
  };
  const esp_lcd_panel_dev_config_t panel_config = {
      .reset_gpio_num = EXAMPLE_PIN_NUM_LCD_RST,
      .rgb_ele_order = LCD_RGB_ELEMENT_ORDER_RGB,
      .bits_per_pixel = 16,
      .vendor_config = &vendor_config,
  };
  if (esp_lcd_new_panel_sh8601(io_handle, &panel_config, &panelHandle) != ESP_OK)
  {
    EwPrint("EwBspDisplayInit: Failed to create SH8601 panel!\n");
    return 0;
  }

  /* Reset and initialize panel */
  if (esp_lcd_panel_reset(panelHandle) != ESP_OK)
  {
    EwPrint("EwBspDisplayInit: Failed to reset panel!\n");
    return 0;
  }
  if (esp_lcd_panel_init(panelHandle) != ESP_OK)
  {
    EwPrint("EwBspDisplayInit: Failed to initialize panel!\n");
    return 0;
  }

  /* Return the current display configuration */
  aDisplayInfo->FrameBuffer = (void *)ScratchPad;
  aDisplayInfo->DoubleBuffer = (void *)0;
  aDisplayInfo->BufferWidth = EW_SCRATCHPAD_WIDTH;
  aDisplayInfo->BufferHeight = EW_SCRATCHPAD_HEIGHT;
  aDisplayInfo->DisplayWidth = EW_DISPLAY_WIDTH;
  aDisplayInfo->DisplayHeight = EW_DISPLAY_HEIGHT;
  aDisplayInfo->UpdateMode = EW_BSP_DISPLAY_UPDATE_SCRATCHPAD;

  EwPrint("EwBspDisplayInit: Display initialized successfully\n");
  return 1;
}

/*******************************************************************************
 * FUNCTION:
 *   EwBspDisplayDone
 *
 * DESCRIPTION:
 *   The function EwBspDisplayDone deinitializes the display hardware.
 *
 * ARGUMENTS:
 *   aDisplayInfo - Display info data structure.
 *
 * RETURN VALUE:
 *   None
 *
 *******************************************************************************/
void EwBspDisplayDone(XDisplayInfo *aDisplayInfo)
{
  EW_UNUSED_ARG(aDisplayInfo);

  /* free memory of transfer buffer */
  if (TransferBuffer)
    heap_caps_free(TransferBuffer);
  TransferBuffer = 0;

  /* free memory of scratch pad buffer */
  if (ScratchPad)
    heap_caps_free(ScratchPad);
  ScratchPad = 0;
}

/*******************************************************************************
 * FUNCTION:
 *   EwBspDisplayGetUpdateArea
 *
 * DESCRIPTION:
 *   The function EwBspDisplayGetUpdateArea returns the next update area
 *   depending on the selected display mode:
 *   In case of a synchroneous single-buffer, the function has to return the
 *   the rectangular areas that correspond to the horizontal stripes (fields)
 *   of the framebuffer.
 *   In case of a scratch-pad buffer, the function has to return the subareas
 *   that fit into the provided update rectangle.
 *   During each display update, this function is called until it returns 0.
 *
 * ARGUMENTS:
 *   aUpdateRect - Rectangular area which should be updated (redrawn).
 *
 * RETURN VALUE:
 *   Returns 1 if a further update area can be provided, 0 otherwise.
 *
 *******************************************************************************/
int EwBspDisplayGetUpdateArea(XRect *aUpdateRect)
{
  static int h = 0;
  static int dh = 0;
  int width = aUpdateRect->Point2.X - aUpdateRect->Point1.X;

  if (width <= 0)
    return 0;

  if (dh == 0)
  {
    h = aUpdateRect->Point2.Y - aUpdateRect->Point1.Y;

    /* determine the number of lines that fit into the scratch-pad */
    dh = EW_SCRATCHPAD_WIDTH * EW_SCRATCHPAD_HEIGHT /
         (aUpdateRect->Point2.X - aUpdateRect->Point1.X);
  }
  else
    aUpdateRect->Point1.Y += dh;

  if (dh > h)
    dh = h;

  aUpdateRect->Point2.Y = aUpdateRect->Point1.Y + dh;
  h -= dh;

  if (dh > 0)
    return 1;

  dh = 0;
  return 0;
}

/*******************************************************************************
 * FUNCTION:
 *   EwBspDisplayWaitForCompletion
 *
 * DESCRIPTION:
 *   The function EwBspDisplayWaitForCompletion is called from the Graphics Engine
 *   to ensure that all pending activities of the display system are completed, so
 *   that the rendering of the next frame can start.
 *   In case of a double-buffering system, the function has to wait until the
 *   V-sync has occured and the pending buffer is used by the display controller.
 *   In case of an external display controller, the function has to wait until
 *   the transfer (update) of the graphics data has been completed and there are
 *   no pending buffers.
 *
 * ARGUMENTS:
 *   None
 *
 * RETURN VALUE:
 *   None
 *
 *******************************************************************************/
void EwBspDisplayWaitForCompletion(void)
{
}

/*******************************************************************************
 * FUNCTION:
 *   EwBspDisplayCommitBuffer
 *
 * DESCRIPTION:
 *   The function EwBspDisplayCommitBuffer is called from the Graphics Engine
 *   when the rendering of a certain buffer has been completed.
 *   The type of buffer depends on the selected framebuffer concept.
 *   If the display is running in a double-buffering mode, the function is called
 *   after each buffer update in order to change the currently active framebuffer
 *   address. Changing the framebuffer address should be synchronized with V-sync.
 *   If the system is using an external graphics controller, this function is
 *   responsible to start the transfer of the framebuffer content.
 *
 * ARGUMENTS:
 *   aAddress - Address of the framebuffer to be shown on the display.
 *   aX,
 *   aY       - Origin of the area which has been updated by the Graphics Engine.
 *   aWidth,
 *   aHeight  - Size of the area which has been updated by the Graphics Engine.
 *
 * RETURN VALUE:
 *   None
 *
 *******************************************************************************/
void EwBspDisplayCommitBuffer(void *aAddress, int aX, int aY, int aWidth, int aHeight)
{
  // if ( pdPASS != xSemaphoreTake( ewDisplaySemaphore, pdMS_TO_TICKS( 1000 )))
  //   return;

  if (!TransferBuffer)
    return;

/* update display content depending on source color format */
#if ((EW_FRAME_BUFFER_COLOR_FORMAT == EW_FRAME_BUFFER_COLOR_FORMAT_Index8) || (EW_FRAME_BUFFER_COLOR_FORMAT == EW_FRAME_BUFFER_COLOR_FORMAT_LumA44))
  {
    register int i;
    register uint16_t *dst = (uint16_t *)TransferBuffer;
    register uint8_t *src = (uint8_t *)aAddress;

    /* take index from scratch-pad and convert it via clut into color -
       colors are already stored byte swapped and suitable for the transfer buffer */
    for (i = aWidth * aHeight; i > 0; i--, dst++, src++)
      *dst = Clut[*src];
  }
#else
  {
    register int pixelCount = aWidth * aHeight;
    register uint32_t *dst32 = (uint32_t *)TransferBuffer;
    register uint32_t *src32 = (uint32_t *)aAddress;
    register int i;

    /* process two RGB565 pixels at a time using 32-bit operations */
    for (i = pixelCount >> 1; i > 0; i--, dst32++, src32++)
    {
      register uint32_t v = *src32;
      *dst32 = ((v >> 8) & 0x00FF00FF) | ((v << 8) & 0xFF00FF00);
    }

    /* handle odd trailing pixel */
    if (pixelCount & 1)
    {
      register uint16_t *dst = (uint16_t *)dst32;
      register uint16_t *src = (uint16_t *)src32;
      *dst = (*src >> 8) | (*src << 8);
    }
  }
#endif

  if (esp_lcd_panel_draw_bitmap(panelHandle, aX, aY, aX + aWidth, aY + aHeight, TransferBuffer) != ESP_OK)
    EwPrint("UpdateDisplay: Failed to draw transfer buffer!\n");
}

/*******************************************************************************
 * FUNCTION:
 *   EwBspDisplaySetClut
 *
 * DESCRIPTION:
 *   The function EwBspDisplaySetClut is called from the Graphics Engine
 *   in order to update the hardware CLUT of the current framebuffer.
 *   The function is only called when the color format of the framebuffer is
 *   Index8 or LumA44.
 *
 * ARGUMENTS:
 *   aClut - Pointer to a color lookup table with 256 entries.
 *
 * RETURN VALUE:
 *   None
 *
 *******************************************************************************/
void EwBspDisplaySetClut(unsigned long *aClut)
{
#if (EW_FRAME_BUFFER_COLOR_FORMAT == EW_FRAME_BUFFER_COLOR_FORMAT_Index8)

  /* create a color lookup table to update display with RGB565 color format */
  register int i;
  for (i = 0; i < 256; i++)
  {
    /* clut content is stored with byte swapped order */
    register unsigned long c = *aClut++;
    Clut[ i ] = (( c & 0x00F80000 ) >> 8 ) | (( c & 0x0000FC00 ) >> 5 ) | (( c & 0x000000F8 ) >> 3 );
  }

#elif (EW_FRAME_BUFFER_COLOR_FORMAT == EW_FRAME_BUFFER_COLOR_FORMAT_LumA44)

  /* create a color lookup table to update display with RGB565 color format */
  register int i;
  for (i = 0; i < 256; i++)
  {
    /* clut content is stored with byte swapped order */
    register unsigned long l = (i & 0x0F) | ((i & 0x0F) << 4);
    Clut[ i ] = (( l & 0xF8 ) << 8 ) | (( l & 0xFC ) << 3 ) | (( l & 0xF8 ) >> 3 );
  }

#else

  EwPrint("EwBspDisplaySetClut: Could not load CLUT!\n");

#endif
}

/* msy, psh */
