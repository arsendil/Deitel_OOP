#include "../headers/Polinomial.hpp"

Polinomial::Polinomial(const Monomial monomial[], const int size)
{
    assert(SIZE >= size && size > 0);
    init();
    for (int i = 0; i < size; ++i) {
        setMonomial(monomial[i]);
    }
}

Polinomial::Polinomial(const Polinomial& rhv)
{
    for (int i = 0; i < SIZE; ++i) {
         monomial_[i] = rhv.getMonomial(i);
    }
}

Monomial
Polinomial::getMonomial(const int index) const
{
    return monomial_[index];
}

void
Polinomial::setMonomial(const Monomial& rhv)
{
    monomial_[rhv.getPower()] = rhv;
}

void
Polinomial::init()
{
    for (int i = 0; i < SIZE; ++i) {
        monomial_[i] = 0;
    }
}

Polinomial
Polinomial::operator+(const Polinomial& rhv) const
{
    Polinomial temp = *this;
    temp += rhv;
    return temp;
}

Polinomial
Polinomial::operator-(const Polinomial& rhv) const
{
    Polinomial temp = *this;
    temp -= rhv;
    return temp;
}

Polinomial
Polinomial::operator*(const Polinomial& rhv) const
{
    Polinomial temp = *this;
    temp *= rhv;
    return temp;
}

Polinomial&
Polinomial::operator=(const Polinomial& rhv)
{
    for (int i = 0; i < SIZE; ++i) {
         monomial_[i] = rhv.getMonomial(i);
    } 
    return *this;
}

Polinomial&
Polinomial::operator+=(const Polinomial& rhv)
{
    for (int i = 0; i < SIZE; ++i) {
        monomial_[i] += rhv.monomial_[i];
    }
    return *this;
}

Polinomial&
Polinomial::operator-=(const Polinomial& rhv)
{
    for (int i = 0; i < SIZE; ++i) {
        monomial_[i] -= rhv.monomial_[i];
    }
    return *this;
}

Polinomial&
Polinomial::operator*=(const Polinomial& rhv)
{
    Monomial result[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            Monomial monomial1 = monomial_[i] * rhv.monomial_[j];
            const int power = monomial1.getPower();
            if (power < SIZE) {
                if (0 == result[power].getCoefficient() && 0 == result[power].getPower()) {
                    result[power] = monomial1;
                } else {
                    result[power] += monomial1;
                }
            }
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        monomial_[i] = result[i];
    }
    return *this;
}

std::ostream&
operator<<(std::ostream& output, const Polinomial& monomial)
{
    for (int i = 0; i < SIZE; ++i) {
        if (0 == monomial.monomial_[i].getCoefficient()) {
            continue;
        }
        output << monomial.monomial_[i] << ' ';
    }
    return output;
}

std::istream&
operator>>(std::istream& input, Polinomial& monomial)
{
    for (int i = 0; i < SIZE; ++i) {
        input >> monomial.monomial_[i];
    }
    return input;
}
