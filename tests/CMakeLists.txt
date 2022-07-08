#
# Copyright (C) 2022 Konstanty Misiak
#
# SPDX-License-Identifier: MIT
#

set(TEST_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/md5_tests.cpp
)

add_executable(tests
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
    ${TEST_FILES}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX tests FILES ${TEST_FILES})

target_link_libraries(tests
    ${LIB_TARGET_NAME}
    gtest
)
