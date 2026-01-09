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

TEST(FractionTests, LessThanOperatorWorks)
{
    Fraction a(1, 2);
    Fraction b(3, 4);
    
    EXPECT_TRUE(a < b);
    EXPECT_FALSE(b < a);
    EXPECT_FALSE(a < Fraction(2, 4)); // equal fractions
}

TEST(FractionTests, LessThanOrEqualOperatorWorks)
{
    Fraction a(1, 2);
    Fraction b(3, 4);

    EXPECT_TRUE(a <= b);
    EXPECT_TRUE(a <= Fraction(2, 4)); // equal
    EXPECT_FALSE(b <= a);
}

TEST(FractionTests, GreaterThanOperatorWorks)
{
    Fraction a(1, 2);
    Fraction b(3, 4);

    EXPECT_TRUE(b > a);
    EXPECT_FALSE(a > b);
    EXPECT_FALSE(a > Fraction(2, 4)); // equal
}

TEST(FractionTests, GreaterThanOrEqualOperatorWorks)
{
    Fraction a(1, 2);
    Fraction b(3, 4);

    EXPECT_TRUE(b >= a);
    EXPECT_TRUE(a >= Fraction(2, 4)); // equal
    EXPECT_FALSE(a >= b);
}

TEST(FractionTests, AdditionOperatorWorks)
{
    Fraction a(1, 2);
    Fraction b(1, 3);

    Fraction result = a + b;

    EXPECT_EQ(result, Fraction(5, 6));
}

TEST(FractionTests, SubtractionOperatorWorks)
{
    Fraction a(1, 2);
    Fraction b(1, 3);

    Fraction result = a - b;

    EXPECT_EQ(result, Fraction(1, 6));
}

TEST(FractionTests, MultiplicationOperatorWorks)
{
    Fraction a(2, 3);
    Fraction b(3, 4);

    Fraction result = a * b;

    EXPECT_EQ(result, Fraction(1, 2)); // 6/12 reduces to 1/2
}

TEST(FractionTests, DivisionOperatorWorks)
{
    Fraction a(2, 3);
    Fraction b(3, 4);

    Fraction result = a / b;

    EXPECT_EQ(result, Fraction(8, 9)); // (2/3) / (3/4) = (2/3)*(4/3) = 8/9
}

TEST(FractionTests, UnaryPlusOperatorWorks)
{
    Fraction a(3, 4);
    Fraction result = +a;

    EXPECT_EQ(result, a);
}

TEST(FractionTests, UnaryMinusOperatorWorks)
{
    Fraction a(3, 4);
    Fraction result = -a;

    EXPECT_EQ(result, Fraction(-3, 4));
}

TEST(FractionTests, PlusEqualsOperatorWorks)
{
    Fraction a(1, 2);
    a += Fraction(1, 3);

    EXPECT_EQ(a, Fraction(5, 6));
}

TEST(FractionTests, MinusEqualsOperatorWorks)
{
    Fraction a(1, 2);
    a -= Fraction(1, 3);

    EXPECT_EQ(a, Fraction(1, 6));
}

TEST(FractionTests, MultiplyEqualsOperatorWorks)
{
    Fraction a(2, 3);
    a *= Fraction(3, 4);

    EXPECT_EQ(a, Fraction(1, 2));
}

TEST(FractionTests, DivideEqualsOperatorWorks)
{
    Fraction a(2, 3);
    a /= Fraction(3, 4);

    EXPECT_EQ(a, Fraction(8, 9));
}

TEST(FractionTests, StreamOutputOperatorWorks)
{
    Fraction a(3, 4);
    std::ostringstream oss;
    oss << a;

    EXPECT_EQ(oss.str(), "3/4");
}
