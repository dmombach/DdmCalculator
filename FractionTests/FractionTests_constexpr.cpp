#include "Fraction.h"

// Basic construction

static_assert(Fraction(1, 2).numerator() == 1);
static_assert(Fraction(1, 2).denominator() == 2);

static_assert(Fraction(2, 4).numerator() == 1);
static_assert(Fraction(2, 4).denominator() == 2);

// Arithmetic

constexpr Fraction a(1, 2);
constexpr Fraction b(1, 4);

constexpr Fraction sum = a + b;
static_assert(sum.numerator() == 3);
static_assert(sum.denominator() == 4);

constexpr Fraction diff = a - b;
static_assert(diff.numerator() == 1);
static_assert(diff.denominator() == 4);

constexpr Fraction prod = a * b;
static_assert(prod.numerator() == 1);
static_assert(prod.denominator() == 8);

constexpr Fraction quot = a / b;
static_assert(quot.numerator() == 2);
static_assert(quot.denominator() == 1);

// Unary operators

constexpr Fraction pos = +a;
static_assert(pos.numerator() == 1);
static_assert(pos.denominator() == 2);

constexpr Fraction neg = -a;
static_assert(neg.numerator() == -1);
static_assert(neg.denominator() == 2);

// Comparisons

static_assert(Fraction(1, 2) == Fraction(2, 4));
static_assert(Fraction(1, 3) < Fraction(1, 2));
static_assert(Fraction(3, 4) > Fraction(2, 3));
static_assert(Fraction(1, 2) <= Fraction(1, 2));
static_assert(Fraction(3, 5) >= Fraction(1, 3));

// Sign normalization

static_assert(Fraction(-1, -2).numerator() == 1);
static_assert(Fraction(-1, -2).denominator() == 2);

static_assert(Fraction(1, -2).numerator() == -1);
static_assert(Fraction(1, -2).denominator() == 2);

// Reduction edge cases

static_assert(Fraction(0, 5).numerator() == 0);
static_assert(Fraction(0, 5).denominator() == 1);
