#pragma once
#include <stdexcept>
#include <string>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

    void reduce();

public:
    Fraction(int numerator = 0, int denominator = 1);

    int numerator() const { return m_numerator; }
    int denominator() const { return m_denominator; }

    std::string toString() const;
    double toDouble() const;
};