/*
 * Copyright (C) 2022 Konstanty Misiak
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once
#include <stddef.h>

namespace ccl {

	bool readFile(const char* filename, char* data, size_t& size, bool binary = false);
	bool writeFile(const char* filename, const char* data, size_t size, bool binary = false);

} // namespace ccl
