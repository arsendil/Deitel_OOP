#include "headers/Complex.hpp"
#include <iostream>

Complex::Complex(const double realNumber, const double imaginaryNumber)
{
    setRealNumber(realNumber);
    setImaginaryNumber(imaginaryNumber);
}

Complex::Complex(const Complex& other)
{
    setRealNumber(other.getRealNumber());
    setImaginaryNumber(other.getImaginaryNumber());
}

Complex
Complex::sumComplexNumbers(const Complex& other) const
{
    return Complex(getRealNumber() + other.getRealNumber(), getImaginaryNumber() + other.getImaginaryNumber());
}

Complex
Complex::diffComplexNumbers(const Complex& other) const
{
    return Complex(getRealNumber() - other.getRealNumber(), getImaginaryNumber() - other.getImaginaryNumber());
}

void
Complex::setRealNumber(const double realNumber)
{
    real_ = realNumber;
}

void
Complex::setImaginaryNumber(const double imaginaryNumber)
{
    imaginary_ = imaginaryNumber; 
}

double
Complex::getRealNumber() const
{
    return real_;
}

double
Complex::getImaginaryNumber() const
{
    return imaginary_;
}

void
Complex::printComplexNumber() const
{
    std::cout << '(' << real_ << ',' << imaginary_ << ')' << std::endl;
}

