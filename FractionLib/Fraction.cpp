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

