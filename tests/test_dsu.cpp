// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "../lib_dsu/dsu.cpp"

#define EPSILON 0.000001

TEST(DSUTest, ConstructorTest) {
	DSU dsu(3);

	for (int i = 0; i < 3; i++) {
		EXPECT_EQ(dsu.print(i), i);
	}
}

TEST(DSUTest, TestFind) {
	DSU dsu(4);

	EXPECT_EQ(dsu.find(4), 4);
}

TEST(DSUTest, TestFindCanThrow) {
	DSU dsu(3);

	EXPECT_THROW(dsu.find(4), std::logic_error);
}