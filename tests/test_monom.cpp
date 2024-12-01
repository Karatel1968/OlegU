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

//MultyplyEQ test:START
TEST(MONOM, MultyplyEq) {
	CMonom m1(3.0, 2, 1, 0);
	CMonom m2(3.0, 2, 1, 0);

	m1 *= m2;

	EXPECT_FLOAT_EQ(m1.getCoeff(), 9.0);
	EXPECT_EQ(m1.getPow(0), 4);
	EXPECT_EQ(m1.getPow(1), 2);
	EXPECT_EQ(m1.getPow(2), 0);
}
//MultyplyEQ test:START

//Add test:START
TEST(MONOM, Add) {
	CMonom m(3.0, 2, 1, 0);
	CMonom m1(3.0, 2, 1, 0);
	CMonom m2(3.0, 2, 1, 0);

	m = m1 + m2;

	EXPECT_FLOAT_EQ(m.getCoeff(), 6.0);
	EXPECT_EQ(m.getPow(0), 2);
	EXPECT_EQ(m.getPow(1), 1);
	EXPECT_EQ(m.getPow(2), 0);
}

TEST(MONOM, AddCanThrow) {
	CMonom m(3.0, 2, 1, 0);
	CMonom m1(3.0, 3, 1, 0);
	CMonom m2(3.0, 2, 1, 0);

	EXPECT_THROW(m = m1 + m2, std::invalid_argument);
}
//Add test:START

//EQAdd test:START
TEST(MONOM, AddEq) {
	CMonom m1(3.0, 2, 1, 0);
	CMonom m2(3.0, 2, 1, 0);

	m1 += m2;

	EXPECT_FLOAT_EQ(m1.getCoeff(), 6.0);
	EXPECT_EQ(m1.getPow(0), 2);
	EXPECT_EQ(m1.getPow(1), 1);
	EXPECT_EQ(m1.getPow(2), 0);
}

TEST(MONOM, AddEqCanThrow) {
	CMonom m1(3.0, 3, 1, 0);
	CMonom m2(3.0, 2, 1, 0);

	EXPECT_THROW(m1 += m2, std::invalid_argument);
}
//EQAdd test:START

//Div test:START
TEST(MONOM, Div) {
	CMonom m(3.0, 2, 1, 0);
	CMonom m1(6.0, 1, 2, 0);
	CMonom m2(3.0, 3, 1, 0);

	m = m1 / m2;

	EXPECT_FLOAT_EQ(m.getCoeff(), 2.0);
	EXPECT_EQ(m.getPow(0), -2);
	EXPECT_EQ(m.getPow(1), 1);
	EXPECT_EQ(m.getPow(2), 0);
}
//Div test:START

//DivEQ test:START
TEST(MONOM, DivEq) {
	CMonom m1(6.0, 1, 2, 0);
	CMonom m2(3.0, 3, 1, 0);

	m1 /= m2;

	EXPECT_FLOAT_EQ(m1.getCoeff(), 2.0);
	EXPECT_EQ(m1.getPow(0), -2);
	EXPECT_EQ(m1.getPow(1), 1);
	EXPECT_EQ(m1.getPow(2), 0);
}
//DivEQ test:START

//Add test:START
TEST(MONOM, Sub) {
	CMonom m(3.0, 2, 1, 0);
	CMonom m1(3.0, 2, 1, 0);
	CMonom m2(3.0, 2, 1, 0);

	m = m1 - m2;

	EXPECT_FLOAT_EQ(m.getCoeff(), 0.0);
	EXPECT_EQ(m.getPow(0), 2);
	EXPECT_EQ(m.getPow(1), 1);
	EXPECT_EQ(m.getPow(2), 0);
}

TEST(MONOM, SubCanThrow) {
	CMonom m(3.0, 2, 1, 0);
	CMonom m1(3.0, 3, 1, 0);
	CMonom m2(3.0, 2, 1, 0);

	EXPECT_THROW(m = m1 - m2, std::invalid_argument);
}
//Add test:START

//EQsub test:START
TEST(MONOM, SubEq) {
	CMonom m1(3.0, 2, 1, 0);
	CMonom m2(3.0, 2, 1, 0);

	m1 -= m2;

	EXPECT_FLOAT_EQ(m1.getCoeff(), 0.0);
	EXPECT_EQ(m1.getPow(0), 2);
	EXPECT_EQ(m1.getPow(1), 1);
	EXPECT_EQ(m1.getPow(2), 0);
}

TEST(MONOM, SubEqCanThrow) {
	CMonom m1(3.0, 3, 1, 0);
	CMonom m2(3.0, 2, 1, 0);

	EXPECT_THROW(m1 -= m2, std::invalid_argument);
}
//EQsub test:START