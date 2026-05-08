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
*   This file contains general configuration settings for the target system,
*   like memory ranges and display parameter and configuration settings for
*   the Embedded Wizard Graphics Engine and Runtime Environment.
*
*******************************************************************************/

#include "ewdef.h"

#ifndef EWCONFIG_H
#define EWCONFIG_H


/* ******************************************************************************
   The following macros identify the target platform and the version of the
   used Build Environment.

   EW_PLATFORM_STRING - This macro contains the name of the development platform.

   EW_BUILD_ENV_VERSION - Version string of the Embedded Wizard Build Environment.
   **************************************************************************** */
#define EW_PLATFORM_STRING    "ESP32-S3-Knob-Touch-LCD-1.8-EN"

#define EW_BUILD_ENV_VERSION  "V15.00.00.00"


/* ******************************************************************************
   The following macros configure the application.

   EW_USE_TERMINAL_INPUT - Flag to switch on/off the support of keyboard events
   received from a connected serial terminal.
   EW_USE_EXTERNAL_FLASH - Flag to enable/disable the usage of the external
   FLASH device.

   EW_BITMAP_PIXEL_SECTION_NAME - Macro to define the section name for the
   bitmap pixel data of bitmap resources. The section name is used in the linker
   file to locate the data to a dedicated read-only memory area.

   EW_FONT_PIXEL_SECTION_NAME, EW_FONT_DATA_SECTION_NAME - Macros to define the
   section name for font pixel data and font metrics of font resources. The
   section names are used in the linker file to locate the data to a dedicated
   read-only memory area.

   EW_CONST_STRING_SECTION_NAME - Macro to define the section name for all
   string constants. The section name is used in the linker file to locate the
   data to a dedicated read-only memory area.
   **************************************************************************** */
#define EW_USE_TERMINAL_INPUT 1

#define EW_USE_EXTERNAL_FLASH 0

#if EW_USE_EXTERNAL_FLASH == 1

  #define EW_BITMAP_PIXEL_SECTION_NAME .SectionEwResource
  #define EW_FONT_PIXEL_SECTION_NAME   .SectionEwResource
  #define EW_FONT_DATA_SECTION_NAME    .SectionEwResource
  #define EW_CONST_STRING_SECTION_NAME .SectionEwResource

#endif


/* ******************************************************************************
   The following macros configure the display integration, the framebuffer access
   and the usage of the graphics accelerator.
   For details about different framebuffer concepts please have a look at
   https://doc.embedded-wizard.de/framebuffer-concepts

   EW_USE_SCRATCHPAD_BUFFER - Flag to switch on/off the usage of a small
   scratch-pad buffer used for the graphics composition instead of a framebuffer.
   As a result the screen of the display is updated in partial mode.
   This mode is used to reduce the memory footprint to a minimum, but it may cause
   some tearing or flickering effects. This mode is useful in combination with
   displays containing its own graphics memory (GRAM).
   Please note that this option is not supported by all display integrations.

   EW_USE_DOUBLE_BUFFER - Flag to switch on/off the usage of an additional
   framebuffer, so that the screen is operated in double-buffering mode.
   If double-buffering is activated, the exchange between front-buffer and
   back-buffer has to be done at V-sync. This has to be implemented in the
   function EwBspDisplayCommitBuffer().
   In case of a single buffered configuration, the graphics composition is done
   directly into the framebuffer. This makes only sense, if you are using an LCD
   with its own pixelbuffer (e.g. some MIPI-DSI displays). Otherwise, the
   composition of the framebuffer content has to be synchronized with the
   LCD update in order to avoid flickering.
   Please note that this option is not supported by all display integrations.

   EW_USE_OFFSCREEN_BUFFER - Flag to switch on/off the usage of an additional
   off-screen buffer. This is an internal buffer, allocated by the Graphics Engine
   and used to prepare the graphical content (composition buffer).
   The usage of a separate off-screen buffer might be advantageous on systems
   where the read access from the physical framebuffer is very slow. In this
   case, the off-screen buffer is used for composition (read and write access)
   and the final graphics is then copied into the framebuffer (write access).
   Please note that this option is not supported by all display integrations.

   EW_DISPLAY_WIDTH and EW_DISPLAY_HEIGHT - These macros define the physical
   dimension of the display in pixel. Typically this corresponds to the attribute
   ScreenSize defined within the profile of the Embedded Wizard GUI project.

   EW_SCRATCHPAD_WIDTH and EW_SCRATCHPAD_HEIGHT - These macros define the size
   of the scratch-pad buffer in pixel. Depending on the available memory, the
   size of the scratch-pad should be 1/10 to 1/2 of the display size.
   **************************************************************************** */
#define EW_USE_SCRATCHPAD_BUFFER        1
#define EW_USE_DOUBLE_BUFFER            0

#define EW_DISPLAY_WIDTH                360
#define EW_DISPLAY_HEIGHT               360

#define EW_SCRATCHPAD_WIDTH             360
#define EW_SCRATCHPAD_HEIGHT            360


/* ******************************************************************************
   The following macros configure the touch device integration.

   EW_TOUCH_AREA_MIN_X - This macro defines the raw touch value of the leftmost
   position on the touch screen. This value represents the x value reported by
   the touch driver when touching on the top left corner of the display.

   EW_TOUCH_AREA_MIN_Y - This macro defines the raw touch value of the topmost
   position on the touch screen. This value represents the y value reported by
   the touch driver when touching on the top left corner of the display.

   EW_TOUCH_AREA_MAX_X - This macro defines the raw touch value of the rightmost
   position on the touch screen. This value represents the x value reported by
   the touch driver when touching on the bottom right corner of the display.

   EW_TOUCH_AREA_MAX_Y - This macro defines the raw touch value of the bottommost
   position on the touch screen. This value represents the y value reported by
   the touch driver when touching on the bottom right corner of the display.

   EW_TOUCH_SWAP_XY - This macro can be used to exchange the x and y values
   provided by the touch driver.

   EW_PRINT_TOUCH_DATA - This macro prints all touch data reported by the touch
   driver on the console. This is helpful to test and calibrate the touch device.

   EW_PRINT_TOUCH_EVENTS - This macro prints all touch events that are provided
   to the GUI application.
   **************************************************************************** */
#define EW_TOUCH_AREA_MIN_X                    0
#define EW_TOUCH_AREA_MIN_Y                    0
#define EW_TOUCH_AREA_MAX_X                    360
#define EW_TOUCH_AREA_MAX_Y                    360
#define EW_TOUCH_SWAP_XY                       0

// #define EW_PRINT_TOUCH_DATA
// #define EW_PRINT_TOUCH_EVENTS


/* ******************************************************************************
   The following macros configure the memory area used for the Embedded Wizard
   heap manager. Optionally, an additional extra memory pool can be defined.

   EW_MEMORY_POOL_SECTION - This macro has to be defined if the memory pool shall
   be declared as an array. Optionally a linker section name can be assigned to
   this macro to define where this array shall be located by the linker.
   Alternatively, a fixed memory address can be defined by setting the macro
   EW_MEMORY_POOL_ADDR.

   EW_MEMORY_POOL_ADDR - This macro defines the start address of the memory pool
   to a fixed address. Take care that the memory area is not used by the linker.
   Do not use this define in combination with EW_MEMORY_POOL_SECTION.

   EW_MEMORY_POOL_SIZE - This macro defines the size of the memory pool in bytes
   used for the Embedded Wizard heap manager.

   EW_EXTRA_POOL_SECTION, EW_EXTRA_POOL_ADDR and EW_EXTRA_POOL_SIZE - These
   macros are used to define a second (additional) memory pool.

   EW_GUI_THREAD_STACK_SIZE - This macro defines the stack size (in bytes) of the
   main GUI thread/task:
   In case that an operating system is used and the stack is allocated in the
   moment when the GUI thread/task is created, the macro defines the exact
   size of memory allocated for the stack.
   In case the stack size is predefined by linker settings, this macro defines
   only the stack size that will be considered and checked as stack of the GUI
   application - even if the real stack size is larger.
   In case of a bare metal environment the setting has no meaning.
   **************************************************************************** */

#define EW_USE_PSRAM 0x180000

#if ( EW_USE_PSRAM > 0 )

  #define EW_MEMORY_POOL_SIZE    EW_USE_PSRAM

#else

  #define EW_MEMORY_POOL_SECTION
  #define EW_MEMORY_POOL_SIZE    ( 80 * 1024 )

#endif

#define EW_EXTRA_POOL_ADDR       0
#define EW_EXTRA_POOL_SIZE       0

#define EW_GUI_THREAD_STACK_SIZE 8192


/* ******************************************************************************
   The following macros configure advance aspects of an Embedded Wizard
   application used for profiling, tracing or optimization purpose. In order to
   enable the functionality uncomment the respective macro definition below.

   EW_PRINT_MEMORY_USAGE - If this macro is defined, a statistic information is
   printed reporting the amount of memory allocated by Chora objects, strings and
   resources. Additionally, the current total memory allocation and the maximum
   peak value is printed.

   EW_DUMP_HEAP - If this macro is defined, the contents of all memory pools are
   evaluated and the associated information as well as the existing blocks are
   reported.

   IMPORTANT: Activating the following macros requires access to the complete
   Graphics Engine source code and recompilation. Changing these macros will have
   no effect when using pre-compiled libraries.

   EW_SUPPORT_GFX_TASK_TRACING - If this macro is defined, the functions of the
   Graphics Engine are enhanced by code to track and protocol all drawing tasks
   executed at the runtime. Once the functionality is available, you control the
   outputs of the traced drawing operations by using the EwEnableGfxTaskTracing()
   function.

   EW_PRINT_GFX_TASKS - Defining this macro activates the above described tracing
   of drawing tasks as if the macro EW_SUPPORT_GFX_TASK_TRACING were defined and
   the function EwEnableGfxTaskTracing() to enable the trace outputs were called.
   This is a convenience macro to simply activate the tracing without needing to
   modify your application code by additional function calls.

   EW_PRINT_PERF_COUNTERS - If this macro is defined, all essential functions of
   the Graphics Engine and Runtime Environment are enhanced by additional code to
   to track and measure their runtime. To display this collected information you
   use the function EwPrintPerfCounters(). In order to use this feature, it is
   necessary to provide an exact time in microseconds via EwGetPerfCounter().

   EW_USE_IMMEDIATE_GARBAGE_COLLECTION - If this macro is defined, the process of
   detection and disposal of unused Chora objects is allowed to run at any time,
   even when this would interfere with the actually executed Chora code. If this
   macro is not defined, the Garbage Collection is limited to run when no Chora
   code is executed only. Using this feature expects, that your application uses
   the function EwSetStackAddressArea() to inform the Garbage Collector about the
   memory area occupied by the CPU stack.
   **************************************************************************** */
// #define EW_PRINT_MEMORY_USAGE
// #define EW_DUMP_HEAP

// #define EW_SUPPORT_GFX_TASK_TRACING
// #define EW_PRINT_GFX_TASKS
// #define EW_PRINT_PERF_COUNTERS
// #define EW_USE_IMMEDIATE_GARBAGE_COLLECTION


/* ******************************************************************************
   The following macros configure the size of diverse caches and buffers.
   Generally, the larger a cache or buffer, the better the performance of the
   application. On the other hand, large caches and buffers will occupy more
   RAM. Configure the macros prudently according to the available RAM and
   expected performance.

   EW_MAX_STRING_CACHE_SIZE - This macro specifies the threshold value for the
   capacity of the string cache. The string cache stores frequently used string
   constants preventing them from being reloaded repeatedly. Embedded Wizard
   tracks the amount of memory occupied by all string constants and as soon as
   this size exceeds the value specified in the macro, discards oldest unused
   strings from the cache automatically. The value for this macro is expressed
   in bytes as an integer number lying between 0 and 0x800000.

   EW_MAX_SURFACE_CACHE_SIZE - This macro specifies the threshold value for the
   capacity of the surface cache. This cache stores often used bitmap resources
   and off-screen image buffers preventing them from being reloaded or recreated
   repeatedly. Embedded Wizard tracks the amount of memory occupied by all cached
   surfaces and as soon as this size exceeds the value specified in the macro,
   discards oldest unused surfaces from the cache automatically. The value for
   this macro is expressed in bytes as an integer number lying between 0 and
   0x20000000.

   EW_MAX_GLYPH_SURFACE_WIDTH, EW_MAX_GLYPH_SURFACE_HEIGHT - These macros specify
   the dimension of the glyph cache surface. This surface stores all glyphs used
   during text drawing operations. The larger the surface the more glyphs can be
   reused without needing to decompress or rasterize them again. The values for
   the macros are expressed in pixel as integer numbers lying between 64 and the
   maximum surface size supported on the graphics hardware. You should ensure,
   that the glyph surface is at least as large as the biggest glyph you want to
   display at the runtime. The following quotation can be used to calculate the
   approximated RAM usage resulting from the configuration of the macros:
   ( EW_MAX_GLYPH_SURFACE_WIDTH * EW_MAX_GLYPH_SURFACE_HEIGHT ) * 1 Byte.

   EW_MAX_NO_OF_GLYPHS - This macro determines the number of glyphs the Graphics
   Engine is allowed to store simultanously. The more glyphs are possible the
   more efficient are all text rasterization and calculation operations. One
   glyph occupies 48 bytes. The value 0 indicates that the maximum number of
   glyphs will be estimated based on the size of the glyph surface cache.

   EW_MAX_ISSUE_TASKS - This macro specifies the capacity of instruction buffers
   used to store drawing operations. Larger buffers improve the optimization and
   elimination of superfluous drawing operations. In turn, small buffers cause
   the drawing process to be often interrupted to flush the prepared operations.
   The value for this macro is expressed in 'tasks' as an integer number lying
   between 1 and 8192. You should ensure that the issue buffer is at least as
   large as the most complex drawing operation performed in your application.
   The following quotation can be used to calculate the approximated RAM usage
   resulting from the configuration of the macro:
   (( EW_MAX_ISSUE_TASKS * 64 ) + 512 ) * 1 Byte.

   EW_INVOCATION_QUEUE_SIZE - This macro defines the size of the invocation queue
   in bytes. The invocation queue is used to record function invocations in the
   context of foreign threads or interrupt service routines and to execute them
   afterwards in the regular context of the Embedded Wizard GUI application.
   **************************************************************************** */
#define EW_MAX_STRING_CACHE_SIZE           4000
#define EW_MAX_SURFACE_CACHE_SIZE          200000
#define EW_MAX_GLYPH_SURFACE_WIDTH       128
#define EW_MAX_GLYPH_SURFACE_HEIGHT      128
#define EW_MAX_NO_OF_GLYPHS                0
#define EW_MAX_ISSUE_TASKS                100
#define EW_INVOCATION_QUEUE_SIZE          64


/* ******************************************************************************
   The following macros configure the behavior of the surface cache and
   treatment of bitmap resources when these are generated in the 'compressed'
   mode. Depending on the configuration, the application will require more or
   less RAM, which affects accordingly the resulting performance.

   EW_LAZY_LOAD_BITMAPS - This macro controls the loading behavior of compressed
   bitmap resources. If this macro is defined with the value 0, the resources are
   loaded immediately and completely into RAM as soon as the application accesses
   them. Thereupon the bitmaps remain in the surface cache (see above). If this
   macro is defined with the value 1, the loading of bitmaps is delayed until the
   application is about to display one frame of the bitmap. In such case this and
   only this frame is loaded into RAM.

   EW_LAZY_LOAD_BITMAPS_IF_ANIMATED_ONLY - This macro, if defined with the value
   1, does limit the effect of the above described macro EW_LAZY_LOAD_BITMAPS to
   resources containing animated bitmaps only. All other bitmaps (single or multi
   frame but not animated) are loaded immediately regardless of the actual value
   for the EW_LAZY_LOAD_BITMAPS macro. If this macro is 0, EW_LAZY_LOAD_BITMAPS
   affects all kinds of bitmap resources.

   EW_DISCARD_BITMAPS - This macro controls the lifetime of bitmaps stored in the
   surface cache (see above). If this macro is configured with the value 1, the
   system is allowed to discard bitmap resources even if these are still in use.
   As soon as the surface cache has exceeded the threshold value specified in the
   macro EW_MAX_SURFACE_CACHE_SIZE and there is no other unused surfaces ready to
   discard from the cache, the system discards the lazy loaded bitmap resources.
   Due to this 'swapping' the application can work with significantly less RAM.
   If this macro is 0, the discarding affects only such surfaces which are really
   not in use anymore.

   EW_DISCARD_BITMAPS_IF_ANIMATED_ONLY - This macro, if defined with the value 1,
   limits the effect of the above described macro EW_DISCARD_BITMAPS to surfaces
   containing animated bitmap resources only. All other bitmaps (single or multi
   frame but not animated) are treated as if the macro EW_DISCARD_BITMAPS were 0.
   If EW_DISCARD_BITMAPS_IF_ANIMATED_ONLY is 0, EW_DISCARD_BITMAPS affects all
   kinds of bitmap in similar manner.

   EW_DISCARD_BITMAPS_IF_NOT_USED_IN_CURRENT_UPDATE - This macro, if defined with
   the value 1, limits the effect of the above described macro EW_DISCARD_BITMAPS
   to surfaces, which have not been used in actual screen update. This prevents
   the system from reloading the same bitmap resource multiple times during
   the running screen update. If this macro is 0, EW_DISCARD_BITMAPS affects all
   bitmap resources in similar manner.

   EW_DISCARD_BITMAPS_IF_NOT_USED_IN_RECENT_UPDATES - This macro, if defined with
   the value 1, limits the effect of the above described macro EW_DISCARD_BITMAPS
   to surfaces, which have not been used in actual and the immediately preceding
   screen updates. This prevents the system from reloading the same bitmap
   resource multiple times during running animations. If this macro is 0, the
   macro EW_DISCARD_BITMAPS affects all bitmap resources in similar manner.

   EW_CACHE_OFFSCREEN_SURFACES - This macro controls how to manage surfaces used
   to buffer off-screen contents (e.g. used by a buffered GUI component). If this
   macro is defined with the value 1, the off-screen surfaces are retained in the
   surface cache (see above). Accordingly, frequently used off-screen surfaces
   can be reused faster without needing to create them again. Defining the macro
   with the value 0 disables this function causing the off-screen surfaces to be
   released immediately if not needed anymore.
   **************************************************************************** */
#define EW_LAZY_LOAD_BITMAPS                              1
#define EW_LAZY_LOAD_BITMAPS_IF_ANIMATED_ONLY             1
#define EW_DISCARD_BITMAPS                                1
#define EW_DISCARD_BITMAPS_IF_ANIMATED_ONLY               1
#define EW_DISCARD_BITMAPS_IF_NOT_USED_IN_CURRENT_UPDATE  0
#define EW_DISCARD_BITMAPS_IF_NOT_USED_IN_RECENT_UPDATES  0
#define EW_CACHE_OFFSCREEN_SURFACES                       1


/* ******************************************************************************
   The following macros remove functionality dedicated to verify the correct
   function of the application. Removing such functionality makes sense only if
   you have finalized the development and ensured that your application works
   correctly. In order to remove the functionality uncomment the respective
   macro definition below.

   EW_DONT_CHECK_INDEX - If this macro is defined, the code generated by Embedded
   Wizard (your application code) does not perform any bounds checking when array
   items are addressed. If this macro is not defined, addressing items outside of
   an array will result in an adequate error message. Performing bounds checking
   may affect the performance if the applications uses arrays extensively.

   EW_DONT_CHECK_THREAD_CONTEXT - All relevant top-level Runtime Environment and
   Graphics Engine functions check if a function is called in the context of
   the main GUI thread/task. To do this, the test compares the current CPU
   stack address with the stack area of the GUI thread/task.
   This helps to detect errors in applications running multiple threads/tasks.
   If this macro is defined, the context thread check is disabled.
   **************************************************************************** */
#define EW_DONT_CHECK_INDEX
// #define EW_DONT_CHECK_THREAD_CONTEXT


/* ******************************************************************************
   The following macros remove function blocks from the Graphics Engine,
   reducing the code size of the resulting binary. Removing functionality makes
   sense only if you are sure that it is not needed by your application. If the
   application nevertheless uses the functionality, a runtime error is reported.
   In order to remove a function block just uncomment the respective macro
   definition below.

   IMPORTANT: Activating the following macros requires access to the complete
   Graphics Engine source code and recompilation. Changing these macros will have
   no effect when using pre-compiled libraries.

   EW_DONT_USE_WARP_FUNCTIONS - If this macro is defined, all functions needed to
   calculate and display transformed image contents are removed from the binary.
   In particular, it disables the possibility to scale and rotate images as well
   as their perspective projection resulting in 3D visual effects.

   EW_DONT_USE_PATH_FUNCTIONS - If this macro is defined, all functions needed
   to calculate and render vector graphics (to display polygons and paths) are
   removed from the binary.

   EW_DONT_USE_BIDI_FUNCTIONS - If this macro is defined, all functions needed to
   process bidirectional text, as it is usually required to display right-to-left
   Arabic or Hebrew scripts, are removed.

   EW_DONT_USE_BLUR_FUNCTIONS - If this macro is defined, all filter functions
   with blur filtering are removed from the binary.

   EW_DONT_USE_MASK_FUNCTIONS - If this macro is defined, all filter functions
   with mask filtering are removed from the binary.

   EW_DONT_USE_TINT_FUNCTIONS - If this macro is defined, all filter functions
   with tint filtering are removed from the binary.

   EW_DONT_USE_GRADIENTS - If this macro is defined, all drawing functions for
   gradients are removed from the binary.

   EW_DONT_USE_SVG_FUNCTIONS - If this macro is defined, all SVG functions are
   removed from the binary.

   EW_DONT_USE_SVG_READER - If this macro is defined, the possibility to
   process dynamically provided SVG contents at the runtime of the application
   is removed from the binary. Only immutable SVG resources known at the code
   generation time are supported.

   EW_DONT_USE_COMPRESSION - This macro can be defined only if neither
   compressed bitmaps nor compressed strings are used in the project. Doing this
   eliminates the compression relevant code from the binary.

   EW_DONT_USE_INDEX8_SURFACES - If this macro is defined, the support for INDEX8
   bitmap format is removed. Thereupon creation, loading and displaying of images
   stored in INDEX8 format is not possible anymore.

   EW_DONT_USE_RGB565_SURFACES - If this macro is defined, the support for RGB565
   bitmap format is removed. Thereupon creation, loading and displaying of images
   stored in RGB565 format is not possible anymore.

   EW_DONT_USE_NATIVE_SURFACES - If this macro is defined, the support for Native
   bitmap format is removed. Thereupon creation, loading and displaying of images
   stored in Native format is not possible anymore.

   EW_DONT_USE_NATIVE_SURFACES_AS_DESTINATION - If this macro is defined all
   graphical operations using a Native surface as destination are eliminated.
   This makes sense only when the alternative destination surface format Screen
   is defined. Otherwise no graphics outputs are possible.
   **************************************************************************** */
// #define EW_DONT_USE_WARP_FUNCTIONS
// #define EW_DONT_USE_PATH_FUNCTIONS
// #define EW_DONT_USE_BIDI_FUNCTIONS
// #define EW_DONT_USE_BLUR_FUNCTIONS
// #define EW_DONT_USE_MASK_FUNCTIONS
// #define EW_DONT_USE_TINT_FUNCTIONS
// #define EW_DONT_USE_GRADIENTS
// #define EW_DONT_USE_SVG_FUNCTIONS
// #define EW_DONT_USE_SVG_READER
// #define EW_DONT_USE_COMPRESSION
// #define EW_DONT_USE_INDEX8_SURFACES
// #define EW_DONT_USE_RGB565_SURFACES
// #define EW_DONT_USE_NATIVE_SURFACES
// #define EW_DONT_USE_NATIVE_SURFACES_AS_DESTINATION


/* ******************************************************************************
   The following macros configure the ExternVideo player and JPEG decoder.

   EW_USED_JPEG_DEC - Selects the JPEG decoder implementation.
   EW_JPEG_IMAGE_PIXEL_FORMAT - Pixel format for decoded JPEG frames.
   EW_JPEG_DEC_MULTI_THREADING - Enable/disable multi-threaded JPEG decoding.
   EW_EXTERN_VIDEO_DROP_FRAMES_TO_KEEP_FPS - Drop frames to maintain target FPS.
   **************************************************************************** */
#define EW_USED_JPEG_DEC                        EW_JPEG_DEC_LIBJPEG
#define EW_JPEG_IMAGE_PIXEL_FORMAT              EW_PIXEL_FORMAT_RGB565
#define EW_JPEG_DEC_MULTI_THREADING             0
#define EW_EXTERN_VIDEO_DROP_FRAMES_TO_KEEP_FPS 1


#endif /* EWCONFIG_H */

/* pba, mli, msy */

