// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "../lib_parser/parser.h"

TEST(IsValid, WorkRight) {

	//const std::string str = "({[])";

	EXPECT_TRUE(is_valid("([{}])"));
	EXPECT_TRUE(is_valid("([])"));
	EXPECT_TRUE(is_valid("()"));
	EXPECT_TRUE(is_valid("((()))"));
}

TEST(IsValid, CanThrow) {
	EXPECT_FALSE(is_valid("([{])"));
}
