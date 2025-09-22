#ifndef __MONOMIAL_HPP__
#define __MONOMIAL_HPP__

#include <iostream>
#include <cassert>

class Monomial
{
    friend std::ostream& operator<<(std::ostream& output, const Monomial& monomial);
    friend std::istream& operator>>(std::istream& input, Monomial& monomial);

public:
    Monomial(const int coefficient = 0, const int power = 0);
    Monomial(const Monomial& rhv);

    Monomial operator+(const Monomial& rhv) const;
    Monomial operator-(const Monomial& rhv) const;
    Monomial operator*(const Monomial& rhv) const;
    Monomial& operator+=(const Monomial& rhv);
    Monomial& operator-=(const Monomial& rhv);
    Monomial& operator*=(const Monomial& rhv);

    int getCoefficient()  const;
    int getPower() const;
    void setCoefficient(const int coefficient);
    void setPower(const int power);

private:
    int coefficient_;
    int power_;
};

#endif /// __MONOMIAL_HPP__
