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
// tests for operator+:END

