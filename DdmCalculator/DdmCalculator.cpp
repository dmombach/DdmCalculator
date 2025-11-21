
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

double calculate(double a, double b, char op)
{
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw std::runtime_error("Division by zero.");
            return a / b;
        default:
            throw std::runtime_error("Unknown operator.");
    }
}

void printSpacing()
{
    std::cout << "\n\n";
}

int main()
{
    std::string line;
    double x, y;
    char op;

    while (true)
    {
        std::cout << "Enter a math expression (e.g., 3 + 4), or 'q' to quit: \n";
        std::getline(std::cin, line);

        if (line.size() == 1 && 
            std::tolower(line[0]) == 'q')
        {
            std::cout << "Goodbye! \n";
            break;
        }

        std::istringstream iss(line);
        if (iss >> x >> op >> y)
        {
            try
            {
                std::cout << "Result: " << calculate(x, y, op);
            }
            catch (const std::exception& e)
            {
                std::cerr << "Error: " << e.what();
            }
        }
        else
        {
            std::cerr << "Invalid input format.";
        }

        printSpacing();
    }
}

