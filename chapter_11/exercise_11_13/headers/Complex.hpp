#ifndef __COMPLEX_HPP__
#define __COMPLEX_HPP__

#include <iostream>

class Complex
{
   friend std::istream& operator>>(std::istream& input, Complex& number1);
   friend std::ostream& operator<<(std::ostream& input, const Complex& number1);

public:
    Complex(const double realPart = 0.0, const double imaginaryPart = 0.0);
    Complex(const Complex& rhv);

    Complex operator+(const Complex& rhv) const;
    Complex operator-(const Complex& rhv) const;
    Complex operator*(const Complex& rhv) const;
    bool operator==(const Complex& rhv) const;
    bool operator!=(const Complex& rhv) const;

    double getReal() const;
    double getImaginary() const;

private:
    void setReal(const double realPart);
    void setImaginary(const double imaginaryPart);

private:
    double real_;
    double imaginary_; 
};

 #endif /// __COMPLEX_HPP__

