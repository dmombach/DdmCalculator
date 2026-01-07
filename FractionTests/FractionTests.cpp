#include "gtest/gtest.h"
#include "Fraction.h"

TEST(FractionTests, DefaultConstructorCreatesZero)
{
    Fraction f;
    EXPECT_EQ(f.numerator(), 0);
    EXPECT_EQ(f.denominator(), 1);
}

TEST(FractionTests, ConstructorReducesFraction)
{
    Fraction f(6, 8);
    EXPECT_EQ(f.numerator(), 3);
    EXPECT_EQ(f.denominator(), 4);
}

TEST(FractionTests, NegativeDenominatorMovesSignToNumerator)
{
    Fraction f(1, -2);
    EXPECT_EQ(f.numerator(), -1);
    EXPECT_EQ(f.denominator(), 2);
}

TEST(FractionTests, ZeroNumeratorAlwaysReducesToZeroOverOne)
{
    Fraction f(0, 5);
    EXPECT_EQ(f.numerator(), 0);
    EXPECT_EQ(f.denominator(), 1);
}

TEST(FractionTests, ReducesNegativeFractionsCorrectly)
{
    Fraction f(-6, 8);
    EXPECT_EQ(f.numerator(), -3);
    EXPECT_EQ(f.denominator(), 4);
}

TEST(FractionTests, DoubleNegativeBecomesPositive)
{
    Fraction f(-6, -8);
    EXPECT_EQ(f.numerator(), 3);
    EXPECT_EQ(f.denominator(), 4);
}

TEST(FractionTests, EqualityOperatorWorksForEquivalentFractions)
{
    Fraction a(1, 2);
    Fraction b(2, 4);
    EXPECT_TRUE(a == b);
}

TEST(FractionTests, EqualityOperatorWorksForDifferentFractions)
{
    Fraction a(1, 2);
    Fraction b(3, 4);
    EXPECT_FALSE(a == b);
}

TEST(FractionTests, InequalityOperatorWorks)
{
    Fraction a(1, 2);
    Fraction b(3, 4);
    EXPECT_TRUE(a != b);
    EXPECT_FALSE(a != Fraction(2, 4)); // equal fractions
}
