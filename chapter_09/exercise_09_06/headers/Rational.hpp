#ifndef __RATIONAL_HPP__
#define __RATIONAL_HPP__

class Rational
{
public:
    Rational(const int numerator = 0, const int denominator = 1);
    Rational(const Rational& other);
    Rational addRationalNumbers(const Rational& other) const;
    Rational subtractRationalNumbers(const Rational& other) const;
    Rational multiplyRationalNumbers(const Rational& other) const;
    Rational divideRationalNumbers(const Rational& other) const;
    void printRationalNumber() const;
    void printFloatRationalNumber() const;
    int getNumeratorNumber() const;
    int getDenominatorNumber() const;
    void setNumeratorNumber(const int numerator);
    void setDenominatorNumber(const int denominator);

private:
    int gcd(const int number1, const int number2) const;

private:
    int numerator_;
    int denominator_;
};

#endif /// __RATIONAL_HPP__

