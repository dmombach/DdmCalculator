// FractionLib.cpp : Defines the functions for the static library.

#include "pch.h"
#include "framework.h"
#include "Fraction.h"
#include <numeric>
#include <iostream>

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
