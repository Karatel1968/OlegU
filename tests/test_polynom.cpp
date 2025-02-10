// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "Polynom.h"


#define EPSILON 0.000001

TEST(POLYNOM, StringConstructor) {
    CPolynom p("3x^2y^1z^0 + 2x^1y^0z^1");
    EXPECT_DOUBLE_EQ(p.evaluate(2, 1, 3), 24.0);
}

TEST(POLYNOM, CopyConstructor) {
    CPolynom p1("3x^2y^1z^0 + -2x^1y^0z^1");
    CPolynom p2(p1);
    EXPECT_DOUBLE_EQ(p2.evaluate(2, 1, 3), 0.0);
}

TEST(POLYNOM, SUB) {
    CPolynom p;
    p.addMonom(CMonom(3.0, 2, 1, 0));
    p.addMonom(CMonom(-2.0, 1, 0, 1));
    EXPECT_DOUBLE_EQ(p.evaluate(2, 1, 3), 0.0);
}

TEST(CPolynomTest, AddPolynomials) {
    CPolynom p1("3x^2y^1z^0 + 2x^1y^0z^1");
    CPolynom p2("1x^2y^1z^0 + 1x^1y^0z^1");
    CPolynom p3 = p1 + p2;
    EXPECT_DOUBLE_EQ(p3.evaluate(2, 1, 3), 34.0);
}

TEST(CPolynomTest, MultiplyPolynomials) {
    CPolynom p1("3x^2y^1z^0 + 2x^1y^0z^1");
    CPolynom p2("1x^2y^1z^0 + 1x^1y^0z^1");
    CPolynom p3 = p1 * p2;
    EXPECT_DOUBLE_EQ(p3.evaluate(2, 1, 3), 240.0);
}

TEST(CPolynomTest, DividePolynomials) {
    CPolynom p1("3x^2y^1z^0 + 2x^1y^0z^1");
    CPolynom p2("1x^2y^1z^0 + 1x^1y^0z^1");
    CPolynom p3 = p1 / p2;
    EXPECT_DOUBLE_EQ(p3.evaluate(2, 1, 3), 2.4);
}

//TEST(CPolynomTest, OrderedMonomials) {
//    CPolynom p("y^2z^3 + 2y^2 + xy + 6");
//    std::ostringstream oss;
//    p.print2(oss);
//    std::string expectedOutput = "1xy^1z^0 + 1x^0y^2z^3 + 2x^0y^2z^0 + 6x^0y^0z^0";
//    EXPECT_EQ(oss.str(), expectedOutput);
//}

TEST(CPolynomTest, OrderedMonomials) {
    CPolynom p("y^2z^3+2y^2+xy+6");
    std::string expectedOutput = "1xy^1z^0 + 1x^0y^2z^3 + 2x^0y^2z^0 + 6x^0y^0z^0 + 0";
    EXPECT_EQ(p.toString(), expectedOutput);
}