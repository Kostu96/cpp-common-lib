/*
 * Copyright (C) 2022 Konstanty Misiak
 *
 * SPDX-License-Identifier: MIT
 */

#include <ccl/md5.h>

#include <gtest/gtest.h>

struct TestParam
{
	std::string_view message;
	std::array<uint8_t, 16> digest;
};

struct MD5Test : public testing::TestWithParam<TestParam> {};

TEST_P(MD5Test, qwerty)
{
	const auto& testParam = GetParam();

	auto result = ccl::md5(reinterpret_cast<const uint8_t*>(testParam.message.data()), testParam.message.size());

	ASSERT_EQ(result.size(), 4u);
	ASSERT_EQ(testParam.digest.size(), 16u);

	const uint8_t* resultBytes = reinterpret_cast<const uint8_t*>(result.data());
	for (size_t i = 0; i < 16; ++i)
		EXPECT_EQ(resultBytes[i], testParam.digest[i]);
}

INSTANTIATE_TEST_SUITE_P(Parametrized, MD5Test,
	testing::Values(
		TestParam{ "",
					 { 0xd4, 0x1d, 0x8c, 0xd9, 0x8f, 0x00, 0xb2, 0x04, 0xe9, 0x80, 0x09, 0x98, 0xec, 0xf8, 0x42, 0x7e }
		},
		TestParam{ "The quick brown fox jumps over the lazy dog",
		           { 0x9e, 0x10, 0x7d, 0x9d, 0x37, 0x2b, 0xb6, 0x82, 0x6b, 0xd8, 0x1d, 0x35, 0x42, 0xa4, 0x19, 0xd6 }
		},
		TestParam{ "a",
		             { 0x0c, 0xc1, 0x75, 0xb9, 0xc0, 0xf1, 0xb6, 0xa8, 0x31, 0xc3, 0x99, 0xe2, 0x69, 0x77, 0x26, 0x61 }
		},
		TestParam{ "12345678901234567890123456789012345678901234567890123456789012345678901234567890",
		             { 0x57, 0xed, 0xf4, 0xa2, 0x2b, 0xe3, 0xc9, 0x55, 0xac, 0x49, 0xda, 0x2e, 0x21, 0x07, 0xb6, 0x7a }
		},
		TestParam{ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",
		           { 0xd1, 0x74, 0xab, 0x98, 0xd2, 0x77, 0xd9, 0xf5, 0xa5, 0x61, 0x1c, 0x2c, 0x9f, 0x41, 0x9d, 0x9f }
		},
		TestParam{ "abcdefghijklmnopqrstuvwxyz",
		           { 0xc3, 0xfc, 0xd3, 0xd7, 0x61, 0x92, 0xe4, 0x00, 0x7d, 0xfb, 0x49, 0x6c, 0xca, 0x67, 0xe1, 0x3b }
		}
	)
);
