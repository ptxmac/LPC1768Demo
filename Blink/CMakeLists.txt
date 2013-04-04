project(blink)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_C_FLAGS "-mthumb -fno-builtin -mcpu=cortex-m3")
set(CMAKE_EXE_LINKER_FLAGS "-mthumb -nostartfiles -lgcc")


if(NOT USE_BOOTLOADER)
	message("Linking for bare metal")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T../bare.ld")
else()
	message("Linking for bootloader")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T../bootloader.ld")
endif()

add_definitions(-D__USE_CMSIS=1)

add_executable(${PROJECT_NAME}.elf
	blink.c
	system_LPC17xx.c
	core_cm3.c
	cr_startup_lpc17.c
)

add_custom_command(OUTPUT ${PROJECT_NAME}.tmp
                   COMMAND arm-none-eabi-objcopy -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.tmp
				   COMMAND ${PROJECT_SOURCE_DIR}/../tools/cm3_checksum ${PROJECT_NAME}.tmp
                   COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_NAME}.tmp ${PROJECT_NAME}.bin
                   DEPENDS ${PROJECT_NAME}.elf
                   COMMENT "objcopying ${PROJECT_NAME}.elf to ${PROJECT_NAME}.bin")
				   
add_custom_target(${PROJECT_NAME}.bin ALL DEPENDS ${PROJECT_NAME}.tmp)

set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${PROJECT_NAME}.bin)
