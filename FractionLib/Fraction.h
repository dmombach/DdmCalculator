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

    bool operator<(const Fraction& other) const
    {
        return static_cast<long long>(m_numerator) * other.m_denominator <
            static_cast<long long>(other.m_numerator) * m_denominator;
    }
    
    bool operator<=(const Fraction& other) const
    {
        return *this < other || *this == other;
    }

    bool operator>(const Fraction& other) const
    {
        return other < *this;
    }

    bool operator>=(const Fraction& other) const
    {
        return other <= *this;
    }

    Fraction operator+(const Fraction& other) const
    {
        long long newNumerator =
            static_cast<long long>(m_numerator) * other.m_denominator +
            static_cast<long long>(other.m_numerator) * m_denominator;

        long long newDenominator =
            static_cast<long long>(m_denominator) * other.m_denominator;

        return Fraction(static_cast<int>(newNumerator),
                        static_cast<int>(newDenominator));
    }

    Fraction operator-(const Fraction& other) const
    {
        long long newNumerator =
            static_cast<long long>(m_numerator) * other.m_denominator -
            static_cast<long long>(other.m_numerator) * m_denominator;

        long long newDenominator =
            static_cast<long long>(m_denominator) * other.m_denominator;

        return Fraction(static_cast<int>(newNumerator),
                        static_cast<int>(newDenominator));
    }

    Fraction operator*(const Fraction& other) const
    {
        long long newNumerator =
            static_cast<long long>(m_numerator) * other.m_numerator;

        long long newDenominator =
            static_cast<long long>(m_denominator) * other.m_denominator;

        return Fraction(static_cast<int>(newNumerator),
                        static_cast<int>(newDenominator));
    }

    Fraction operator/(const Fraction& other) const
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

    Fraction operator+() const
    {
        return *this;
    }

    Fraction operator-() const
    {
        return Fraction(-m_numerator, m_denominator);
    }

    Fraction& operator+=(const Fraction other)
    {
        *this = *this + other;

        return *this;
    }

    Fraction& operator-=(const Fraction other)
    {
        *this = *this - other;

        return *this;
    }

    Fraction& operator*=(const Fraction other)
    {
        *this = *this * other;

        return *this;
    }

    Fraction& operator/=(const Fraction other)
    {
        *this = *this / other;

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);

    friend std::istream& operator>>(std::istream& is, Fraction& f);

    explicit operator double() const
    {
        return static_cast<double>(m_numerator) / m_denominator;
    }

private:
    int m_numerator;
    int m_denominator;

    void reduce();
};
