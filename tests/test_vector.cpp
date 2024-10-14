// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "../lib_vector/TVector.h"

#define EPSILON 0.000001

// tests for operator+:START
TEST(TVectorTest, Operator_add_Test) {

	TVector<int> vector(3, 1);

	TVector<int> vector2(3, 2);

	TVector<int> res = vector + vector2;

	EXPECT_EQ(res[0], 3);
	EXPECT_EQ(res[1], 3);
	EXPECT_EQ(res[2], 3);

}

TEST(TVectorTest, Operator_add_CanThrowTest) {

	TVector<int> vector(2, 1);

	TVector<int> vector2(3, 2);

	EXPECT_THROW(vector + vector2, std::logic_error);

}
// tests for operator+:END

// tests for operator-:START
TEST(TVectorTest, Operator_sub_Test) {

	TVector<int> vector(3, 1);

	TVector<int> vector2(3, 2);

	TVector<int> res = vector - vector2;

	EXPECT_EQ(res[0], -1);
	EXPECT_EQ(res[1], -1);
	EXPECT_EQ(res[2], -1);

}

TEST(TVectorTest, Operator_sub_CanThrowTest) {

	TVector<int> vector(2, 1);

	TVector<int> vector2(3, 2);

	EXPECT_THROW(vector - vector2, std::logic_error);

}
// tests for operator-:END

// tests for operator*:START
TEST(TVectorTest, Operator_mult_Test) {

	TVector<int> vector(3, 1);

	TVector<int> vector2(3, 2);

	int res = vector * vector2;

	EXPECT_EQ(res, 6);

}
// tests for operator*:END

// tests for operator+=:START
TEST(TVectorTest, Operator_AddEq_Test) {

	TVector<int> vector(3, 1);

	TVector<int> vector2(3, 2);

	vector += vector2;

	EXPECT_EQ(vector[0], 3);
	EXPECT_EQ(vector[1], 3);
	EXPECT_EQ(vector[2], 3);

}
// tests for operator+=:END

TEST(TVectorTest, CopyConstr) {
	TVector<int> vector(3, 1);

	TVector<int> vector2(vector);

	EXPECT_EQ(vector2[0], 1);
	EXPECT_EQ(vector2[1], 1);
	EXPECT_EQ(vector2[2], 1);
}



