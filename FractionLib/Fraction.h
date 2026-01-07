#pragma once
#include <stdexcept>
#include <string>

class Fraction
{
public:
    Fraction(int numerator = 0, int denominator = 1);

    int numerator() const { return m_numerator; }
    int denominator() const { return m_denominator; }

    std::string toString() const;
    double toDouble() const;

    bool operator==(const Fraction& other) const
    {
        return m_numerator == other.m_numerator &&
            m_denominator == other.m_denominator;
    }

    bool operator!=(const Fraction& other) const
    {
        return !(*this == other);
    }

private:
    int m_numerator;
    int m_denominator;

    void reduce();
};