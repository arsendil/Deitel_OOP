#include "../headers/RightTriangle.hpp"

RightTriangle::RightTriangle(const double sideA, const double sideB, const double sideC, const char fill)
{
    setRightTriangle(sideA, sideB, sideC);
    setFill(fill);
}

RightTriangle::~RightTriangle()
{}

void
RightTriangle::setRightTriangle(const double sideA, const double sideB, const double sideC)
{
    assert(sideA > 0 && sideB > 0 && sideC > 0);
    assert(isRightTriangle(sideA, sideB, sideC));
    setSideA(sideA);
    setSideB(sideB);
    setSideC(sideC);
}

void
RightTriangle::setSideA(const double side)
{
    sideA_ = side;
}

void
RightTriangle::setSideB(const double side)
{
    sideB_ = side;
}

void
RightTriangle::setSideC(const double side)
{
    sideC_ = side;
}

void
RightTriangle::setFill(const char fill)
{
    assert(std::isprint(fill));
    fill_ = fill;
}

double
RightTriangle::getSideA() const
{
    return sideA_;
}

double
RightTriangle::getSideB() const
{
    return sideB_;
}

double
RightTriangle::getSideC() const
{
    return sideC_;
}

char
RightTriangle::getFill() const
{
    return fill_;
}

double
RightTriangle::getArea() const
{
    const double halfPerimetr = (getSideA() + getSideB() + getSideC()) / 2.0;
    return std::sqrt(halfPerimetr *
                    (halfPerimetr - getSideA()) *
                    (halfPerimetr - getSideB()) *
                    (halfPerimetr - getSideC()));
}

void
RightTriangle::print() const
{
    std::cout << "RightTriangle (a = " << getSideA() 
              << ", b = "         << getSideB() 
              << ", c = "         << getSideC() << ")\n"
              << "Area is "       << getArea();
}

void
RightTriangle::draw() const
{
    const int base = static_cast<int>(getSideA());
    const int height = static_cast<int>(getSideB());
    for (int i = 0; i < base; ++i) {
        for (int j = 0; j < height; ++j) {
            std::cout << ((0 == j || base - 1 == i || i == j) ? getFill() : ' ');
        }
        std::cout << std::endl;
    }
}

bool
RightTriangle::isRightTriangle(const double sideA, const double sideB, const double sideC)
{
    return ((sideC * sideC == sideA * sideA + sideB * sideB)  ||
            (sideB * sideB == sideA * sideA + sideC * sideC)) || 
            (sideA * sideA == sideB * sideB + sideC * sideC);
}
