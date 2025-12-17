#include "pch.h"
#include "Calculator.h"
#include <iostream>
#include <stdexcept>

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

double Calculator::evaluateRPN(const std::string& expression)
{
    std::stack<double> st;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isdigit(token[0]))
        {
            // Token is a number

            st.push(std::stod(token));
        }
        else
        {
            // Token is an operator

            if (st.size() < 2) throw std::runtime_error("Invalid RPN expression!");

            double b = st.top(); st.pop();
            double a = st.top(); st.pop();

            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/")
            {
                if (b == 0) throw std::runtime_error("Division by zero!");
                st.push(a / b);
            }
            else if (token == "%")
            {
                if (static_cast<int>(b) == 0) throw std::runtime_error("Modulus by zero!");
                st.push(static_cast<int>(a) % static_cast<int>(b));
            }
            else if (token == "^")
            {
                st.push(std::pow(a, b));
            }
            else
            {
                throw std::runtime_error("Unknown operator: " + token);
            }
        }
    }

    if (st.size() != 1) throw std::runtime_error("Invalid RPN expression!");

    return st.top();
}
