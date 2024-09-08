#include <gtest.h>
#include "../lib_pair/pair.h"

// Test the default constructor
TEST(TPairTest, DefaultConstructor) {
    TPair<int, int> pair;
    EXPECT_EQ(pair.first(), 0);  // Expect default initialization to be 0 for integers
    EXPECT_EQ(pair.second(), 0);
}