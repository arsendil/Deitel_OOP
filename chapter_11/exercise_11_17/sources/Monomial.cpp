#include "../headers/Monomial.hpp"

Monomial::Monomial(const int coefficient, const int power)
{
    setCoefficient(coefficient);
    setPower(power);
}

Monomial::Monomial(const Monomial& rhv)
    : coefficient_(rhv.getCoefficient())
    , power_(rhv.getPower())
{
}

Monomial
Monomial::operator+(const Monomial& rhv) const
{
    assert(getPower() == rhv.getPower() || 0 == rhv.getCoefficient() || 0 == getCoefficient());
    return Monomial(getCoefficient() + rhv.getCoefficient(), 0 == getCoefficient() ? rhv.getPower() : getPower());
}

Monomial
Monomial::operator-(const Monomial& rhv) const
{
    assert(getPower() == rhv.getPower() || 0 == rhv.getCoefficient() || 0 == getCoefficient());
    return Monomial(getCoefficient() - rhv.getCoefficient(), 0 == getCoefficient() ? rhv.getPower() : getPower());
}

Monomial
Monomial::operator*(const Monomial& rhv) const
{
    return Monomial(getCoefficient() * rhv.getCoefficient(), getPower() + rhv.getPower());
}

Monomial&
Monomial::operator+=(const Monomial& rhv)
{    
    assert(getPower() == rhv.getPower() || 0 == rhv.getCoefficient() || 0 == getCoefficient());
    if (0 == getCoefficient()) {
        setPower(rhv.getPower());
    }
    setCoefficient(getCoefficient() + rhv.getCoefficient());

    return *this;
}

Monomial&
Monomial::operator-=(const Monomial& rhv)
{
    assert(getPower() == rhv.getPower() || 0 == rhv.getCoefficient() || 0 == getCoefficient());
    if (0 == getCoefficient()) {
        setPower(rhv.getPower());
    }
    setCoefficient(getCoefficient() - rhv.getCoefficient());
    return *this;
}

Monomial&
Monomial::operator*=(const Monomial& rhv)
{
    setCoefficient(getCoefficient() * rhv.getCoefficient());
    setPower(getPower() + rhv.getPower());
    return *this;
}

int
Monomial::getCoefficient() const
{
    return coefficient_;
}

int
Monomial::getPower() const
{
    return power_;
}

void
Monomial::setCoefficient(const int coefficient)
{
    coefficient_ = coefficient;
}

void
Monomial::setPower(const int power)
{
    assert(power >= 0);
    power_ = power;
}

std::ostream&
operator<<(std::ostream& output, const Monomial& monomial)
{
    output << monomial.coefficient_ << "x^" << monomial.power_;
    return output;
}

std::istream&
operator>>(std::istream& input, Monomial& monomial)
{
    input >> monomial.coefficient_;
    input >> monomial.power_;
    return input;
}

