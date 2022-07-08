#
# Copyright (C) 2022 Konstanty Misiak
#
# SPDX-License-Identifier: MIT
#

set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
add_subdirectory(googletest)

set_target_properties(
    gtest
    gtest_main
    PROPERTIES
    FOLDER third_party
    EXCLUDE_FROM_ALL true
)
