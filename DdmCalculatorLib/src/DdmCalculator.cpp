#include "pch.h"
#include "DdmCalculator.h" 

Fraction DdmCalculator::ComputeGordonGrowth(
    const Fraction& dividend,
    const Fraction& growth,
    const Fraction& discount) const
{
    return dividend / (discount - growth);
}