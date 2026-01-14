#pragma once
#include <stdexcept>
#include <string>
#include <ostream>
#include <istream>
#include <cstdlib>

class Fraction
{
public:
    
    // Constructors
    
    constexpr Fraction(int numerator = 0, int denominator = 1)
        : m_numerator(numerator), m_denominator(denominator)
    {
        if (denominator == 0)
        {
            throw std::invalid_argument("Denominator cannot be zero.");
        }

        reduce();
    }

    // Accessors 

    constexpr int numerator() const { return m_numerator; }
    constexpr int denominator() const { return m_denominator; }

    double toDouble() const
    {
        return static_cast<double>(m_numerator) / m_denominator;
    }

    std::string toString() const;
    
    // Comparison operators 

    constexpr bool operator==(const Fraction& other) const
    {
        return m_numerator == other.m_numerator &&
            m_denominator == other.m_denominator;
    }

    constexpr bool operator!=(const Fraction& other) const
    {
        return !(*this == other);
    }

    constexpr bool operator<(const Fraction& other) const
    {
        return static_cast<long long>(m_numerator) * other.m_denominator <
            static_cast<long long>(other.m_numerator) * m_denominator;
    }
    
    constexpr bool operator<=(const Fraction& other) const
    {
        return *this < other || *this == other;
    }

    constexpr bool operator>(const Fraction& other) const
    {
        return other < *this;
    }

    constexpr bool operator>=(const Fraction& other) const
    {
        return other <= *this;
    }

    // Arithmetic operators 

    constexpr Fraction operator+(const Fraction& other) const
    {
        long long newNumerator =
            static_cast<long long>(m_numerator) * other.m_denominator +
            static_cast<long long>(other.m_numerator) * m_denominator;

        long long newDenominator =
            static_cast<long long>(m_denominator) * other.m_denominator;

        return Fraction(static_cast<int>(newNumerator),
                        static_cast<int>(newDenominator));
    }

    constexpr Fraction operator-(const Fraction& other) const
    {
        long long newNumerator =
            static_cast<long long>(m_numerator) * other.m_denominator -
            static_cast<long long>(other.m_numerator) * m_denominator;

        long long newDenominator =
            static_cast<long long>(m_denominator) * other.m_denominator;

        return Fraction(static_cast<int>(newNumerator),
                        static_cast<int>(newDenominator));
    }

    constexpr Fraction operator*(const Fraction& other) const
    {
        long long newNumerator =
            static_cast<long long>(m_numerator) * other.m_numerator;

        long long newDenominator =
            static_cast<long long>(m_denominator) * other.m_denominator;

        return Fraction(static_cast<int>(newNumerator),
                        static_cast<int>(newDenominator));
    }

    constexpr Fraction operator/(const Fraction& other) const
    {
        // Divisiton by zero check
        if (other.m_numerator == 0)
        {
            throw std::runtime_error("Division by zero fraction.");
        }

        long long newNumerator =
            static_cast<long long>(m_numerator) * other.m_denominator;

        long long newDenominator =
            static_cast<long long>(m_denominator) * other.m_numerator;

        return Fraction(static_cast<int>(newNumerator),
                        static_cast<int>(newDenominator));
    }

    // Unary operators 

    constexpr Fraction operator+() const
    {
        return *this;
    }

    constexpr Fraction operator-() const
    {
        return Fraction(-m_numerator, m_denominator);
    }

    // Compound assignment 

    Fraction& operator+=(const Fraction& other)
    {
        *this = *this + other;

        return *this;
    }

    Fraction& operator-=(const Fraction& other)
    {
        *this = *this - other;

        return *this;
    }

    Fraction& operator*=(const Fraction& other)
    {
        *this = *this * other;

        return *this;
    }

    Fraction& operator/=(const Fraction& other)
    {
        *this = *this / other;

        return *this;
    }

    // Stream operators 

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);

    friend std::istream& operator>>(std::istream& is, Fraction& f);

    // Conversion 

    explicit operator double() const
    {
        return static_cast<double>(m_numerator) / m_denominator;
    }

private:
    int m_numerator;
    int m_denominator;

    // Helpers 

    static constexpr int gcd(int a, int b)
    {
        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;

        return (b == 0) ? a : gcd(b, a % b);
    }

    constexpr void reduce()
    {
        // Normalize sign: denominator should always be positive 
        if (m_denominator < 0)
        {
            m_denominator = -m_denominator;
            m_numerator = -m_numerator;
        }

        int divisor = gcd(m_numerator, m_denominator);

        if (divisor != 0)
        {
            m_numerator /= divisor;
            m_denominator /= divisor;
        }
    }
};
