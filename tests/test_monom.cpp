// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "../lib_polynom/Monom.h"

#define EPSILON 0.000001

//Base Constructor trst:START
TEST(MONOM, MonomBaseConstructor) {
	CMonom m(3.0, 2, 1, 0);
	EXPECT_FLOAT_EQ(m.getCoeff(), 3.0);
	EXPECT_EQ(m.getPow(0), 2);
	EXPECT_EQ(m.getPow(1), 1);
	EXPECT_EQ(m.getPow(2), 0);
}
//Base Constructor trst:END

//Multyply test:START
TEST(MONOM, Multyply) {
	CMonom m(3.0, 2, 1, 0);
	CMonom m1(3.0, 2, 1, 0);
	CMonom m2(3.0, 2, 1, 0);

	m = m1 * m2;

	EXPECT_FLOAT_EQ(m.getCoeff(), 9.0);
	EXPECT_EQ(m.getPow(0), 4);
	EXPECT_EQ(m.getPow(1), 2);
	EXPECT_EQ(m.getPow(2), 0);
}
//Multyply test:START

//Multyply test:START
//Multyply test:START