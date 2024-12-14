// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "Polynom.h"


#define EPSILON 0.000001

TEST(POLYNOM, StringConstructor) {
    CPolynom p("3x^2y^1z^0 + 2x^1y^0z^1");
    EXPECT_DOUBLE_EQ(p.evaluate(2, 1, 3), 24.0);
}

