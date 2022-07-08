/*
 * Copyright (C) 2022 Konstanty Misiak
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

namespace ccl {

	class NonCopyable
	{
	protected:
		NonCopyable() = default;
		~NonCopyable() = default;
	private:
		NonCopyable(const NonCopyable&) = delete;
		NonCopyable& operator=(const NonCopyable&) = delete;
	};

} // namespace ccl
