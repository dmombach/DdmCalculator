// FractionLib.cpp : Defines the functions for the static library.

#include "pch.h"
#include "framework.h"
#include "Fraction.h"
#include <numeric>
#include <iostream>

static int gcd(int a, int b)
{
    a = std::abs(a);
    b = std::abs(b);

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
    os << f.m_numerator << '/' << f.m_denominator;

    return os;
}

std::istream& operator>>(std::istream& is, Fraction& f)
{
    int num = 0;
    int den = 0;
    char slash = 0;

    // Expected format: a/b 
    if (is >> num >> slash >> den)
    {
        if (slash == '/')
        {
            if (den == 0)
            {
                is.setstate(std::ios::failbit);
            }
            else
            {
                f = Fraction(num, den);
            }
        }
        else
        {
            is.setstate(std::ios::failbit);
        }
    }

    return is;
}

Fraction::Fraction(int numerator, int denominator)
    : m_numerator(numerator), m_denominator(denominator)
{
    if (denominator == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero.");
    }

    reduce();
}

void Fraction::reduce()
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

