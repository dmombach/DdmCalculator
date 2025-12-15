#include "Calculator.h"
#include <iostream>

double Calculator::add(double a, double b)
{
    return a + b;
}

double Calculator::subtract(double a, double b)
{
    return a - b;
}

double Calculator::multiply(double a, double b)
{
    return a * b;
}

double Calculator::divide(double a, double b)
{
    if (b == 0)
    {
        std::cout << "Error: Division by zero!" << std::endl;

        return 0;
    }

    return a / b;
}

int Calculator::modulus(int a, int b)
{
    if (b == 0)
    {
        std::cout << "Error: Modulus by zero!" << std::endl;

        return 0;
    }

    return a % b;
}

double Calculator::power(double base, double exponent)
{
    return std::pow(base, exponent);
}
