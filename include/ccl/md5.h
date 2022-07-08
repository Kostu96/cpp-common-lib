/*
 * Copyright (C) 2022 Konstanty Misiak
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once
#include <array>

namespace ccl {

	std::array<uint32_t, 4> md5(const uint8_t* data, size_t size);

} // namespace ccl
