#ifndef __POLINOMIAL_HPP__
#define __POLINOMIAL_HPP__

#include "Monomial.hpp"

const int SIZE = 10;

class Polinomial
{
    friend std::ostream& operator<<(std::ostream& output, const Polinomial& monomial);
    friend std::istream& operator>>(std::istream& input, Polinomial& monomial);

public:
    Polinomial(const Monomial monomial[], const int size);
    Polinomial(const Polinomial& rhv);

    Polinomial operator+(const Polinomial& rhv) const;
    Polinomial operator-(const Polinomial& rhv) const;
    Polinomial operator*(const Polinomial& rhv) const;
    Polinomial& operator=(const Polinomial& rhv);
    Polinomial& operator+=(const Polinomial& rhv);
    Polinomial& operator-=(const Polinomial& rhv);
    Polinomial& operator*=(const Polinomial& rhv);
    
    Monomial getMonomial(const int index) const;

private:
    void setMonomial(const Monomial& rhv);
    void init();

private:
    Monomial monomial_[SIZE];
};

#endif /// __POLINOMIAL_HPP__
