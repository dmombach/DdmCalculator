#include "gtest/gtest.h"
#include "Fraction.h"

TEST(FractionTests, DefaultConstructorCreatesZero)
{
    Fraction f;
    EXPECT_EQ(f.numerator(), 0);
    EXPECT_EQ(f.denominator(), 1);
}