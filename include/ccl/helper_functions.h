/*
 * Copyright (C) 2022 Konstanty Misiak
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once
#include <stddef.h>
#include <string>

namespace ccl {

	bool readFile(const char* filename, char* data, size_t& size, bool binary = false);
	bool writeFile(const char* filename, const char* data, size_t size, bool binary = false);

	//std::string wstringToString(const std::wstring& wideString);
	//std::wstring stringToWstring(const std::string& wideString);

} // namespace ccl
