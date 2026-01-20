#include "pch.h"
#include "gtest/gtest.h"
#include "DdmCalculator.h"
#include "Fraction.h" 

TEST(DdmCalculatorTests, GordonGrowthBasic)
{
    DdmCalculator calc;

    Fraction dividend{ 5, 1 };      // D1 = 5
    Fraction growth{ 1, 100 };      // g = 1%
    Fraction discount{ 5, 100 };    // r = 5%

    auto result = calc.ComputeGordonGrowth(dividend, growth, discount);

    // Expected: 5 / (0.05 - 0.01) = 5 / 0.04 = 125 
    EXPECT_EQ(result, Fraction(125, 1));
}