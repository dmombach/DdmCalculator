#pragma once
#include "Fraction.h" 

class DdmCalculator
{
public:
    Fraction ComputeGordonGrowth(
        const Fraction& dividend,
        const Fraction& growth,
        const Fraction& discount) const;
};
