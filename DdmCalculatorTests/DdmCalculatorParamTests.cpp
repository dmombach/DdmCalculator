#include "pch.h"
#include "Calculator.h"
#include <gtest/gtest.h>

// Define a struct for test parameters
struct CalcTestParam
{
    std::string expression;
    double expected;
};

// Test fixture using parametrized tests
class CalculatorParamTest : public ::testing::TestWithParam<CalcTestParam> {};

TEST_P(CalculatorParamTest, EvaluatesExpressionsCorrectly)
{
    auto param = GetParam();
    Calculator calc;
    double result = calc.evaluateRPN(param.expression);
    EXPECT_DOUBLE_EQ(result, param.expected);
}

// Provide the test cases
INSTANTIATE_TEST_SUITE_P(
    RpnExpressions,
    CalculatorParamTest,
    ::testing::Values(
        CalcTestParam{ "3 4 +", 7.0 },
        CalcTestParam{ "10 2 -", 8.0 },
        CalcTestParam{ "2 3 *", 6.0 },
        CalcTestParam{ "8 4 /", 2.0 },
        CalcTestParam{ "5 1 2 + 4 * + 3 -", 14.0 } // classic RPN example
    )
);