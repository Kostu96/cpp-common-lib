#
# Copyright (C) 2022-2023 Konstanty Misiak
#
# SPDX-License-Identifier: MIT
#

if (${CCL_BUILD_TESTS})
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
endif()
