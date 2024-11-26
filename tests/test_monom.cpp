// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "../lib_polynom/Monom.h"

#define EPSILON 0.000001

TEST(MONOM, MonomBaseConstructor) {
	CMonom m(3.0, 2, 1, 0);
	EXPECT_FLOAT_EQ(m.getCoeff(), 3.0);
	EXPECT_EQ(m.getPow(0), 2);
	EXPECT_EQ(m.getPow(1), 1);
	EXPECT_EQ(m.getPow(2), 0);
}
