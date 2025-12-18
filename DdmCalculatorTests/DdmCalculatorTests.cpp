#include "pch.h"
#include "StringUtil.h"
#include "Calculator.h"
#include <gtest/gtest.h>

// --- StringUtil tests ---
TEST(StringUtilTests, ToLower)
{
    EXPECT_EQ(StringUtil::toLower("HELLO"), "hello");
    EXPECT_EQ(StringUtil::toLower("HeLLo"), "hello");
    EXPECT_EQ(StringUtil::toLower("hello"), "hello");
}

TEST(StringUtilTests, Trim)
{
    EXPECT_EQ(StringUtil::trim("    hello    "), "hello");
    EXPECT_EQ(StringUtil::trim("world"), "world");
    EXPECT_EQ(StringUtil::trim("    spaced out"), "spaced out");
    EXPECT_EQ(StringUtil::trim("no-space"), "no-space");
}

// --- Calculator tests ---
TEST(CalculatorTests, BasicOps)
{
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.evaluateRPN("2 3 +"), 5.0);
    EXPECT_DOUBLE_EQ(calc.evaluateRPN("10 2 -"), 8.0);
    EXPECT_DOUBLE_EQ(calc.evaluateRPN("4 5 *"), 20.0);
    EXPECT_DOUBLE_EQ(calc.evaluateRPN("20 4 /"), 5.0);
}

TEST(CalculatorTests, ExtendedOps)
{
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.evaluateRPN("5 3 %"), 2.0);
    EXPECT_DOUBLE_EQ(calc.evaluateRPN("2 3 ^"), 8.0);
}
