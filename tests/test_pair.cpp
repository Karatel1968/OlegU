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

// ��� first():START
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
// ��� first():END

// ��� second():START

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
// ��� second():END