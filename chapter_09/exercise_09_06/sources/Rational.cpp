#include "headers/Rational.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cassert>

Rational::Rational(const int numerator, const int denominator)
{
   const int divisor = gcd(numerator, denominator);
   setNumeratorNumber(numerator / divisor);
   setDenominatorNumber(denominator / divisor);
}

Rational::Rational(const Rational& other)
{
   setNumeratorNumber(other.getNumeratorNumber());
   setDenominatorNumber(other.getDenominatorNumber());
}

Rational
Rational::addRationalNumbers(const Rational& other) const
{
   const int denominatorValue1 = getDenominatorNumber();
   const int denominatorValue2 = other.getDenominatorNumber();
   const int numerator1 = getNumeratorNumber() * denominatorValue2 + other.getNumeratorNumber() * denominatorValue1;
   const int denominator1 = denominatorValue1 * denominatorValue2;
   return Rational(numerator1, denominator1);
}

Rational
Rational::subtractRationalNumbers(const Rational& other) const
{
   const int denominatorValue1 = getDenominatorNumber();
   const int denominatorValue2 = other.getDenominatorNumber();
   const int numerator1 = getNumeratorNumber() * denominatorValue2 - other.getNumeratorNumber() * denominatorValue1;
   const int denominator1 = denominatorValue1 * denominatorValue2;
   return Rational(numerator1, denominator1);
}

Rational
Rational::multiplyRationalNumbers(const Rational& other) const
{
   const int numerator1 = getNumeratorNumber() * other.getNumeratorNumber();
   const int denominator1 = getDenominatorNumber() * other.getDenominatorNumber();
   return Rational(numerator1, denominator1);
}

Rational
Rational::divideRationalNumbers(const Rational& other) const
{
   assert(other.getNumeratorNumber() != 0);
   const int numerator1 = getNumeratorNumber() * other.getDenominatorNumber();
   const int denominator1 = getDenominatorNumber() * other.getNumeratorNumber();
   return Rational(numerator1, denominator1);
}

void
Rational::printRationalNumber() const
{
   std::cout << getNumeratorNumber() << '/' << getDenominatorNumber(); 
}

void
Rational::printFloatRationalNumber() const
{
   std::cout << static_cast<double>(getNumeratorNumber()) / getDenominatorNumber();
}

int
Rational::gcd(const int number1, const int number2) const
{
   if (0 == number2) return number1;
   return gcd(number2, number1 % number2);
}

int
Rational::getNumeratorNumber() const
{
   return numerator_;
}

int
Rational::getDenominatorNumber() const
{
   return denominator_;
}

void
Rational::setNumeratorNumber(const int numerator)
{
   numerator_ = numerator;
}

void
Rational::setDenominatorNumber(const int denominator)
{
   assert(denominator != 0);
   denominator_ = denominator;
}

