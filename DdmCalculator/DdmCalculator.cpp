#include <iostream>
#include "Calculator.h"
#include "StringUtil.h"

int standardCalculator();
int rpnCalculator();

int main()
{
    //return standardCalculator();

    return rpnCalculator();
}

static int rpnCalculator()
{
    Calculator calc;
    std::string expr;

    do
    {
        std::cout << "Enter RPN expression (e.g., '5 3 + 2 *') or type 'quit' to exit: ";
        std::getline(std::cin, expr);

        if (StringUtil::toLower(StringUtil::trim(expr)) == "quit")
        {
            std::cout << "Exiting calculator..." << std::endl;
            break;
        }

        try
        {
            double result = calc.evaluateRPN(expr);
            std::cout << "Result : " << result << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
            return 1;
        }
    } while (true);

    return 0;
}

static int standardCalculator()
{
    Calculator calc;
    double x, y;
    char op;

    std::cout << "Enter expression (e.g., 5 + 3): ";
    std::cin >> x >> op >> y;

    double result = 0;
    switch (op)
    {
    case '+':
        result = calc.add(x, y);
        break;
    case '-':
        result = calc.subtract(x, y);
        break;
    case '*':
        result = calc.multiply(x, y);
        break;
    case '/':
        result = calc.divide(x, y);
        break;
    case '%':
        result = calc.modulus((int)x, (int)y);
        break;
    case '^':
        result = calc.power(x, y);
        break;
    default:
        std::cout << "Unknown operator!" << std::endl;
        return 1;
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}
