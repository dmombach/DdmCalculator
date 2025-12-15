#include <iostream>
#include "Calculator.h"

int main()
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
