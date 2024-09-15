// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "../lib_pair/pair.h"

#define EPSILON 0.000001
/*TEST(TPairTest, DefaultConstructor) {
    TPair<int, int> pair;
    EXPECT_EQ(pair.first(), 0);  
    EXPECT_EQ(pair.second(), 0);
}*/

TEST(TPairTest, DefaultConstructor) {
    TPair<int, int> pair1(1, 1);
    TPair<double, int> pair2(1.5, 1);
    TPair<double, char> pair3(1.5, 'ads');
    TPair<char, double> pair4('ads', 2.4);
    TPair<double, double> pair5(1.5, 1.4);
    TPair<char, char> pair6('rty', 'ads');

    ASSERT_NO_THROW(pair1, pair2, pair3, pair4, pair5, pair6);
}

// Äëÿ first():START
TEST(TPairTest, First_Returns_CorrectValue) {

TPair<int, std::string> pair(100, "wertyy");

EXPECT_EQ(pair.first(), 100);
}

TEST(TPairTest, First_and_DConstructor) {
    
TPair<int, std::string> pair;

EXPECT_EQ(pair.first(), 0);
}

TEST(TPairTest, First_and_Second) {
    
TPair<int, std::string> pair(100, "wertyy");

pair.set_first(345);

EXPECT_EQ(pair.first(), 345);
}
// Äëÿ first():END

// Äëÿ second():START

TEST(TPairTest, Second_Returns_CorrectValue) {

TPair<int, std::string> pair(100, "wertyy");

EXPECT_TRUE(pair.second() == "wertyy");
}

/*TEST(TPairTest, Second_and_DConstructor) {

    TPair<int, std::string> pair;

    EXPECT_TRUE(pair.second() == '');
}*/

TEST(TPairTest, Second_and_Second) {

TPair<int, std::string> pair(100, "wertyy");

pair.set_second("w");

EXPECT_TRUE(pair.second() == "w");
}
// Äëÿ second():END

// Äëÿ Assigment Operator:START
TEST(TPairTest, Assigment_Operator_works) {
TPair<int, std::string> pair1(100, "H");
TPair<int, std::string> pair2;

pair2 = pair1;

EXPECT_EQ(pair1.first(), 100);
EXPECT_EQ(pair1.second(), "H");

EXPECT_EQ(pair2.first(), 100);
EXPECT_EQ(pair2.second(), "H");
}

/*TEST(TPairTest, Assigment_Operator_works) {
    TPair<int, char> pair1(100, "H");
    TPair<int, char> pair2;

    pair2 = pair1;

    //EXPECT_EQ(pair1.first(), 10);
    //EXPECT_EQ(pair1.second(), "H");

    EXPECT_EQ(pair2.first(), 100);
    EXPECT_EQ(pair2.second(), "H");
}*/
// Äëÿ Assigment Operator:END

// Äëÿ Coppy Constructor Operator:START
TEST(TPairTest, CopyConstructor) {
TPair<int, std::string> pair1(42, "Hello");

TPair<int, std::string> pair2(pair1);

EXPECT_EQ(pair1.first(), 42);
EXPECT_EQ(pair1.second(), "Hello");

EXPECT_EQ(pair2.first(), 42);
EXPECT_EQ(pair2.second(), "Hello");

EXPECT_NE(&pair1, &pair2);
}

TEST(TPairTest, CopyConstructor_another_test) {
TPair<double, std::string> pair1(2.2, "try");

TPair<double, std::string> pair2(pair1);

EXPECT_EQ(pair1.first(), 2.2);
EXPECT_EQ(pair1.second(), "try");

EXPECT_EQ(pair2.first(), 2.2);
EXPECT_EQ(pair2.second(), "try");

EXPECT_NE(&pair1, &pair2);
}
// Äëÿ Coppy Constructor Operator:END

// Äëÿ Equality operator:START
TEST(TPairTest, Equality_Operator_works) {
TPair<int, std::string> pair1(100, "H");
TPair<int, std::string> pair2(100, "H");

EXPECT_TRUE(pair2 == pair1);
}

TEST(TPairTest, Equality_Operator_works_second_test) {
TPair<int, std::string> pair1(100, "H");
TPair<int, std::string> pair2(100, "Hiuy");

EXPECT_FALSE(pair2 == pair1);
}
// Äëÿ Equality operator:END

// Äëÿ NO_Equality operator:START
TEST(TPairTest, NOEquality_Operator_works) {
TPair<int, std::string> pair1(100, "H");
TPair<int, std::string> pair2(100, "Hiuy");

EXPECT_TRUE(pair2 != pair1);
}

TEST(TPairTest, NOEquality_Operator_works_Enother_test) {
TPair<int, std::string> pair1(100, "H");
TPair<int, std::string> pair2(100, "Hiuy");

EXPECT_FALSE(pair2 == pair1);
}
// Äëÿ NO_Equality operator:END

// Äëÿ Substruction operator:START
TEST(TPairTest, SubtractionAssignmentOperatorInt) {
TPair<int, int> pair1(10, 20);
TPair<int, int> pair2(3, 7);

pair1 -= pair2;

EXPECT_EQ(pair1.first(), 7);
EXPECT_EQ(pair1.second(), 13);
}

TEST(TPairTest, SubtractionAssignmentOperatorDouble) {
TPair<double, double> pair1(10.5, 20.3);
TPair<double, double> pair2(3.2, 7.1);

pair1 -= pair2;

EXPECT_DOUBLE_EQ(pair1.first(), 7.3);
EXPECT_DOUBLE_EQ(pair1.second(), 13.2);
}

TEST(TPairTest, SubtractionAssignmentOperatorChar) {
TPair<int, char> pair1(100, 'C');
TPair<int, char> pair2(40, 'A');

pair1 -= pair2;

EXPECT_EQ(pair1.first(), 60);
EXPECT_EQ(pair1.second(), 2);
}

TEST(TPairTest, SubtractionAssignmentOperatorStringThrows) {
TPair<int, std::string> pair1(10, "Hello");
TPair<int, std::string> pair2(5, "World");

EXPECT_THROW(pair1 -= pair2, std::logic_error);
}

TEST(TPairTest, SubtractionAssignmentOperatorBothStringThrows) {
TPair<std::string, std::string> pair1("yureg", "Hello");
TPair<std::string, std::string> pair2("uy", "World");

EXPECT_THROW(pair1 -= pair2, std::logic_error);
}
// Äëÿ Substruction operator:END






