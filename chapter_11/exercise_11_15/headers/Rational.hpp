#ifndef __RATIONAL_HPP__
#define __RATIONAL_HPP__

#include <iostream>

class Rational
{
    friend std::ostream& operator<<(std::ostream& output, const Rational& number1); 
    friend std::istream& operator>>(std::istream& input, Rational& number1); 
public:
    Rational(const int numerator = 0, const int denominator = 1);
    Rational(const Rational& rhv);
    Rational operator+(const Rational& rhv) const;
    Rational operator-(const Rational& rhv) const;
    Rational operator*(const Rational& rhv) const;
    Rational operator/(const Rational& rhv) const;
    bool operator==(const Rational& rhv)    const;
    bool operator!=(const Rational& rhv)    const;
    bool operator<(const Rational& rhv)     const;
    bool operator>(const Rational& rhv)     const;
    bool operator<=(const Rational& rhv)    const;
    bool operator>=(const Rational& rhv)    const;

    void printFloatRationalNumber() const;
    int getNumeratorNumber()        const;
    int getDenominatorNumber()      const;

private:
    void setDenominatorNumber(const int denominator);
    void setNumeratorNumber(const int numerator);
    int gcd(const int number1, const int number2) const;

private:
    int numerator_;
    int denominator_;
};

#endif /// __RATIONAL_HPP__
