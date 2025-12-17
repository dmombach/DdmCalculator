#pragma once
#include <cmath>
#include <string>
#include <stack>
#include <sstream>

class Calculator
{
public:
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    int modulus(int a, int b);
    double power(double base, double exponent);
    double evaluateRPN(const std::string& expression);
};
