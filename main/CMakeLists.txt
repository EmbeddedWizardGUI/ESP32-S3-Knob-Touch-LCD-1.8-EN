###############################################################################
# PROJECT     : Embedded Wizard Application Demo
###############################################################################

###############################################################################
# GENERAL SETTINGS & PATHS
###############################################################################
set(EMWI_APP_PATH ${COMPONENT_PATH}/Application/GeneratedCode)

###############################################################################
# Include Embedded Wizard definition files
###############################################################################
# Check for generated code and include Embedded Wizard file list
if(EXISTS ${EMWI_APP_PATH}/ewfiles.cmake)
  include (${EMWI_APP_PATH}/ewfiles.cmake)
else()
  message(FATAL_ERROR "The file '${EMWI_APP_PATH}/ewfiles.cmake' is missing! "
  "Please open Embedded Wizard project and generate code before calling make!")
endif()

# Set path variables
set(EMWI_UI_CODE_PATH "${COMPONENT_PATH}/Application/GeneratedCode")
set(EMWI_RTE_PATH "${COMPONENT_PATH}/PlatformPackage/RTE")
set(EMWI_GFX_PATH "${COMPONENT_PATH}/PlatformPackage/${EMWI_COLOR_FORMAT}")

# Include .cmake files
include (${EMWI_RTE_PATH}/ewrte.cmake)
include (${EMWI_GFX_PATH}/ewgfx.cmake)

# Macro for replacing a value in a list
macro(LIST_REPLACE LIST INDEX NEWVALUE)
    list(INSERT ${LIST} ${INDEX} ${NEWVALUE})
    MATH(EXPR __INDEX "${INDEX} + 1")
    list (REMOVE_AT ${LIST} ${__INDEX})
endmacro(LIST_REPLACE)

# Adding paths for generated code c files
set(INDEX 0)
foreach(C_FILE IN LISTS EMWIFILES)
	LIST_REPLACE(EMWIFILES ${INDEX} "${EMWI_UI_CODE_PATH}/${C_FILE}")
	MATH(EXPR __INDEX "${INDEX} + 1")
	set(INDEX ${__INDEX})
endforeach()

# Adding paths for RTE c files
set(INDEX 0)
foreach(C_FILE IN LISTS EMWI_RTE_FILES)
	LIST_REPLACE(EMWI_RTE_FILES ${INDEX} "${EMWI_RTE_PATH}/${C_FILE}")
	MATH(EXPR __INDEX "${INDEX} + 1")
	set(INDEX ${__INDEX})
endforeach()

# Adding paths for GFX c files
set(INDEX 0)
foreach(C_FILE IN LISTS EMWI_GFX_FILES)
	LIST_REPLACE(EMWI_GFX_FILES ${INDEX} "${EMWI_GFX_PATH}/${C_FILE}")
	MATH(EXPR __INDEX "${INDEX} + 1")
	set(INDEX ${__INDEX})
endforeach()

###############################################################################
# Collect libjpeg-turbo decoder source files
###############################################################################
set(LIBJPEG_TURBO_PATH "${COMPONENT_PATH}/ThirdParty/libjpeg-turbo")
set(LIBJPEG_TURBO_SRCS
  "${LIBJPEG_TURBO_PATH}/jaricom.c"
  "${LIBJPEG_TURBO_PATH}/jcomapi.c"
  "${LIBJPEG_TURBO_PATH}/jdapimin.c"
  "${LIBJPEG_TURBO_PATH}/jdapistd.c"
  "${LIBJPEG_TURBO_PATH}/jdarith.c"
  "${LIBJPEG_TURBO_PATH}/jdatasrc.c"
  "${LIBJPEG_TURBO_PATH}/jdcoefct.c"
  "${LIBJPEG_TURBO_PATH}/jdcolor.c"
  "${LIBJPEG_TURBO_PATH}/jddctmgr.c"
  "${LIBJPEG_TURBO_PATH}/jdhuff.c"
  "${LIBJPEG_TURBO_PATH}/jdicc.c"
  "${LIBJPEG_TURBO_PATH}/jdinput.c"
  "${LIBJPEG_TURBO_PATH}/jdmainct.c"
  "${LIBJPEG_TURBO_PATH}/jdmarker.c"
  "${LIBJPEG_TURBO_PATH}/jdmaster.c"
  "${LIBJPEG_TURBO_PATH}/jdmerge.c"
  "${LIBJPEG_TURBO_PATH}/jdphuff.c"
  "${LIBJPEG_TURBO_PATH}/jdpostct.c"
  "${LIBJPEG_TURBO_PATH}/jdsample.c"
  "${LIBJPEG_TURBO_PATH}/jdtrans.c"
  "${LIBJPEG_TURBO_PATH}/jerror.c"
  "${LIBJPEG_TURBO_PATH}/jidctflt.c"
  "${LIBJPEG_TURBO_PATH}/jidctfst.c"
  "${LIBJPEG_TURBO_PATH}/jidctint.c"
  "${LIBJPEG_TURBO_PATH}/jidctred.c"
  "${LIBJPEG_TURBO_PATH}/jmemmgr.c"
  "${LIBJPEG_TURBO_PATH}/jmemnobs.c"
  "${LIBJPEG_TURBO_PATH}/jquant1.c"
  "${LIBJPEG_TURBO_PATH}/jquant2.c"
  "${LIBJPEG_TURBO_PATH}/jsimd_none.c"
  "${LIBJPEG_TURBO_PATH}/jutils.c"
)

###############################################################################
# Register Embedded Wizard as component
###############################################################################
idf_component_register(SRCS
"Application/Source/main.c"
"Application/Source/ewmain.c"
"Application/Source/DeviceDriver.c"
${EMWIFILES}
${EMWI_RTE_FILES}
${EMWI_GFX_FILES}
"TargetSpecific/ew_bsp_clock.c"
"TargetSpecific/ew_bsp_display.c"
"TargetSpecific/ew_bsp_event.c"
"TargetSpecific/ew_bsp_os.c"
"TargetSpecific/ew_bsp_inout.c"
"TargetSpecific/ew_bsp_system.c"
"TargetSpecific/ew_bsp_touch.c"
"Extensions/ExternVideo/Native/EwExternVideoMJpeg.c"
"Extensions/ExternVideo/Native/EwAviParser.c"
"Extensions/InputStream/Native/EwInputStream.c"
"Extensions/InputStream/Native/EwInputStreamSpiffs.c"
"Extensions/JpegDecoding/Native/EwJpegDecLibJpeg.c"
${LIBJPEG_TURBO_SRCS}

INCLUDE_DIRS
"Application/Source"
"Application/GeneratedCode"
"PlatformPackage/RTE"
"PlatformPackage/${EMWI_COLOR_FORMAT}"
"TargetSpecific"
"Extensions/ExternVideo/Native"
"Extensions/InputStream/Native"
"Extensions/JpegDecoding/Native"
"ThirdParty/libjpeg-turbo"
)

###############################################################################
# Defines
###############################################################################
target_compile_options(${COMPONENT_LIB} PRIVATE
-Wno-error=format= -Wno-format
-Wno-address
-Wno-shift-negative-value
-Wno-empty-body
-Wno-missing-field-initializers
-Wno-implicit-fallthrough
-DEW_USE_OPERATING_SYSTEM=1
-DEW_FRAME_BUFFER_COLOR_FORMAT=EW_FRAME_BUFFER_COLOR_FORMAT_${EMWI_COLOR_FORMAT}
-DEW_SURFACE_ROTATION=${EMWI_SURFACE_ROTATION}
)

###############################################################################
# Linking libraries
###############################################################################
if(DEFINED EMWI_RTE_LIB AND EMWI_GFX_LIB)

	# Linking of RTE and GFX libraries into component library
	target_link_libraries(${COMPONENT_LIB} PUBLIC ${COMPONENT_PATH}/PlatformPackage/RTE/${EMWI_RTE_LIB} ${COMPONENT_PATH}/PlatformPackage/${EMWI_COLOR_FORMAT}/${EMWI_GFX_LIB})

	# Recursive linking of GFX library
	add_library(GFX STATIC IMPORTED)
	set_property(TARGET GFX PROPERTY IMPORTED_LOCATION ${COMPONENT_PATH}/PlatformPackage/${EMWI_COLOR_FORMAT}/${EMWI_GFX_LIB})
	target_link_libraries(${COMPONENT_LIB} PUBLIC GFX)
	set_property(TARGET GFX APPEND PROPERTY INTERFACE_LINK_LIBRARIES ${COMPONENT_LIB})

	# Recursive linking of RTE library
	add_library(RTE STATIC IMPORTED)
	set_property(TARGET RTE PROPERTY IMPORTED_LOCATION ${COMPONENT_PATH}/PlatformPackage/RTE/${EMWI_RTE_LIB})
	target_link_libraries(${COMPONENT_LIB} PUBLIC RTE)
	set_property(TARGET RTE APPEND PROPERTY INTERFACE_LINK_LIBRARIES ${COMPONENT_LIB})

else()

	# Verifying whether RTE professional files were unzipped correctly
	if(DEFINED EMWI_RTE_LIB)
		if(NOT DEFINED EMWI_GFX_LIB)
			message(FATAL_ERROR "The Embedded Wizard RTE professional files are missing! "
			"In case that you would like to use the Professional AddOn, "
			"please ensure that the ESP32-Professional-AddOn.zip was unzipped correctly!")
		endif()
	endif()

	# Verifying whether GFX professional files were unzipped correctly
	if(DEFINED EMWI_GFX_LIB)
		if(NOT DEFINED EMWI_RTE_LIB)
			message(FATAL_ERROR "The Embedded Wizard GFX professional files are missing! "
			"In case that you would like to use the Professional AddOn, "
			"please ensure that the ESP32-Professional-AddOn.zip was unzipped correctly!")
		endif()
	endif()

endif()