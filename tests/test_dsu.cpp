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

//TEST(DSUTest, TestMakeSet) {
//	DSU dsu(3);
//
//	dsu.make_set(4);
//	EXPECT_EQ(dsu.find(4), 4);
//}

TEST(DSUTest, TestUnion) {
	DSU dsu(5);

	dsu.Union(1, 4);
	dsu.Union(3, 5);
	dsu.Union(5, 2);

	EXPECT_EQ(dsu.print(0), 0);
	EXPECT_EQ(dsu.print(1), 2);
	EXPECT_EQ(dsu.print(2), 2);
	EXPECT_EQ(dsu.print(3), 0);
	EXPECT_EQ(dsu.print(4), 2);
}

TEST(DSUTest, TestCompressedFind) {
	DSU dsu(4);

	EXPECT_EQ(dsu.compressedFind(4), 4);
}

TEST(DSUTest, TestCompressedFindCanThrow) {
	DSU dsu(3);

	EXPECT_THROW(dsu.compressedFind(4), std::logic_error);
}

TEST(DSUTest, TestCompressedUnion) {
	DSU dsu(5);

	dsu.compressedUnion(1, 4);
	dsu.compressedUnion(3, 5);
	dsu.compressedUnion(5, 2);

	EXPECT_EQ(dsu.print(0), 0);
	EXPECT_EQ(dsu.print(1), 2);
	EXPECT_EQ(dsu.print(2), 2);
	EXPECT_EQ(dsu.print(3), 0);
	EXPECT_EQ(dsu.print(4), 2);
}

TEST(DSUTest, ClearTest) {
	DSU dsu(5);

	dsu.clear();
	EXPECT_EQ(dsu.print(0), 0);
	EXPECT_EQ(dsu.print(1), 0);
	EXPECT_EQ(dsu.print(2), 0);
	EXPECT_EQ(dsu.print(3), 0);
	EXPECT_EQ(dsu.print(4), 0);
}
