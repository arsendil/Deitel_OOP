#include "../headers/Complex.hpp"
#include <iostream>

Complex::Complex(const double realPart, const double imaginaryPart)
    : real_(realPart)
    , imaginary_(imaginaryPart)
{
}

Complex::Complex(const Complex& rhv)
    : real_(rhv.getReal())
    , imaginary_(rhv.getImaginary())
{
}

Complex
Complex::operator+(const Complex& rhv) const
{
    return Complex(getReal() + rhv.getReal(),
                   getImaginary() + rhv.getImaginary());
}

Complex
Complex::operator-(const Complex& rhv) const
{
    return Complex(getReal() - rhv.getReal(),
                   getImaginary() - rhv.getImaginary());
}

Complex
Complex::operator*(const Complex &rhv) const
{
    return Complex((getReal() * rhv.getReal()) - (getImaginary() * rhv.getImaginary()),
                   (getReal() * rhv.getImaginary() + getImaginary() * rhv.getReal()));
}

bool
Complex::operator==(const Complex &rhv) const
{
    return (getReal() == rhv.getReal()) && (getImaginary() == rhv.getImaginary());
}

bool
Complex::operator!=(const Complex &rhv) const
{
    return !(*this == rhv);
}

double
Complex::getReal() const
{
    return real_;
}

double
Complex::getImaginary() const
{
    return imaginary_;
}

void
Complex::setReal(const double realPart)
{
    real_ = realPart;
}

void
Complex::setImaginary(const double imaginaryPart)
{
    imaginary_ = imaginaryPart;
}

std::ostream&
operator<<(std::ostream& output, const Complex& number1)
{
    output << '(' << number1.getReal() << ", " << number1.getImaginary() << ')';
    return output;
}

std::istream&
operator>>(std::istream& input, Complex& number1)
{
    input >> number1.real_ >> number1.imaginary_;
    return input;
}

