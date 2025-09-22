#include "../headers/Rational.hpp"
#include <cmath>
#include <cstdlib>
#include <cassert>

Rational::Rational(const int numerator, const int denominator)
{
    const int divisor = gcd(numerator, denominator) * ((numerator < 0) ? -1: 1);
    
    setNumeratorNumber(numerator / divisor);
    setDenominatorNumber(denominator / divisor);
}

Rational::Rational(const Rational& rhv)
{
    setNumeratorNumber(rhv.getNumeratorNumber());
    setDenominatorNumber(rhv.getDenominatorNumber());
}

Rational
Rational::operator+(const Rational& rhv) const
{
    const int denominatorValue1 = getDenominatorNumber();
    const int denominatorValue2 = rhv.getDenominatorNumber();
    const int numerator1 = getNumeratorNumber() * denominatorValue2 + rhv.getNumeratorNumber() * denominatorValue1;
    const int denominator1 = denominatorValue1 * denominatorValue2;
    return Rational(numerator1, denominator1);
}

Rational
Rational::operator-(const Rational& rhv) const
{
    const int denominatorValue1 = getDenominatorNumber();
    const int denominatorValue2 = rhv.getDenominatorNumber();
    const int numerator1 = getNumeratorNumber() * denominatorValue2 - rhv.getNumeratorNumber() * denominatorValue1;
    const int denominator1 = denominatorValue1 * denominatorValue2;
    return Rational(numerator1, denominator1);
}

Rational
Rational::operator*(const Rational& rhv) const
{
    const int numerator1 = getNumeratorNumber() * rhv.getNumeratorNumber();
    const int denominator1 = getDenominatorNumber() * rhv.getDenominatorNumber();
    return Rational(numerator1, denominator1);
}

Rational
Rational::operator/(const Rational& rhv) const
{
    assert(rhv.getNumeratorNumber() != 0);
    const int numerator1 = getNumeratorNumber() * rhv.getDenominatorNumber();
    const int denominator1 = getDenominatorNumber() * rhv.getNumeratorNumber();
    return Rational(numerator1, denominator1);
}

bool
Rational::operator==(const Rational& rhv) const
{
    return ((getNumeratorNumber() == rhv.getNumeratorNumber() &&
             getDenominatorNumber() == rhv.getDenominatorNumber()));    
}

bool
Rational::operator!=(const Rational& rhv) const
{
    return !(*this == rhv);
}

bool
Rational::operator<(const Rational& rhv) const
{
    return (getNumeratorNumber() * rhv.getDenominatorNumber()) <
           (getDenominatorNumber() * rhv.getNumeratorNumber());

}

bool
Rational::operator>(const Rational &rhv) const
{
    return !(*this == rhv || *this < rhv); 
}

bool
Rational::operator<=(const Rational &rhv) const
{
   return !(*this > rhv);
}

bool
Rational::operator>=(const Rational &rhv) const
{
   return !(*this < rhv);
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

std::ostream&
operator<<(std::ostream& output, const Rational& number1)
{
    output << number1.getNumeratorNumber() << '/' << number1.getDenominatorNumber();
    return output;
}

std::istream&
operator>>(std::istream& input, Rational& number1)
{
    input >> number1.numerator_;
    input >> number1.denominator_;
    return input;
}
