#pragma once

#include "Fraction.h"

constexpr Fraction GordonGrowth(const Fraction& dividend,
    const Fraction& rate,
    const Fraction& growth)
{
    const Fraction denominator = rate - growth;

    return dividend / denominator;
}