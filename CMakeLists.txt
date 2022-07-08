#
# Copyright (C) 2022 Konstanty Misiak
#
# SPDX-License-Identifier: MIT
#

cmake_minimum_required(VERSION 3.20)

### options: ###
option(CCL_BUILD_TESTS "Build tests" OFF)
################

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/output/debug/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/output/debug/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/output/debug/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/output/release/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/output/release/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/output/release/lib)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

function(assure_out_of_source_builds)
    # make sure the user doesn't play dirty with symlinks
    get_filename_component(srcdir "${CMAKE_SOURCE_DIR}" REALPATH)
    get_filename_component(bindir "${CMAKE_BINARY_DIR}" REALPATH)
    
    if("${srcdir}" STREQUAL "${bindir}")
        message("Warning: in-source builds are disabled")
        message("Please create a separate build directory and run cmake from there")
        message(FATAL_ERROR "Quitting configuration")
    endif()
endfunction()

assure_out_of_source_builds()

project(cpp-common-lib-proj LANGUAGES CXX)
set(LIB_TARGET_NAME cpp-common-lib)

set(SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ccl/helper_functions.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ccl/md5.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ccl/non_copyable.h
    ${CMAKE_CURRENT_SOURCE_DIR}/source/helper_functions.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/md5.cpp
)

add_library(${LIB_TARGET_NAME} STATIC
	${SOURCE_FILES}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

target_include_directories(${LIB_TARGET_NAME} SYSTEM PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_subdirectory(third_party)

if (${CCL_BUILD_TESTS})
    add_subdirectory(tests)
endif()
