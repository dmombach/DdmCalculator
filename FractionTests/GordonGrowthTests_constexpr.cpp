#include "GordonGrowth.h"
#include "Fraction.h"

/*
* Gordon Growth Model (Dividend Discount Model): 
* D_1 / (r - g)
* D_1: expected dividend
* r  : return rate
* g  : growth rate
*/

static_assert(
    GordonGrowth(
        Fraction(2, 1),     // D1 = 2
        Fraction(10, 100),  // r = 0.10
        Fraction(2, 100)    // g = 0.02
    ) == Fraction(25, 1),
    "Gordon Growth Model test failed."
);