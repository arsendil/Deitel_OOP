#ifndef __COMPLEX_HPP__
#define __COMPLEX_HPP__

class Complex
{
public:
    Complex(const double realNumber = 0.0, const double imaginaryNumber = 0.0);
    Complex(const Complex& other);
    Complex sumComplexNumbers(const Complex& other) const;
    Complex diffComplexNumbers(const Complex& other) const;
    void setRealNumber(const double realNumber);
    void setImaginaryNumber(const double imaginaryNumber);
    double getRealNumber() const;
    double getImaginaryNumber() const;
    void printComplexNumber() const;

private:
    double real_;
    double imaginary_;
};

#endif /// __COMPLEX_HPP__
