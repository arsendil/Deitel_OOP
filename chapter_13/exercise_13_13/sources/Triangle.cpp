#include "../headers/Triangle.hpp"

Triangle::Triangle(const double sideA, const double sideB, const double sideC)
{
    setTriangle(sideA, sideB, sideC);
}

Triangle::~Triangle()
{}

void
Triangle::setTriangle(const double sideA, const double sideB, const double sideC)
{
    assert(sideA > 0 && sideB > 0 && sideC > 0);
    assert(validateTriangle(sideA, sideB, sideC));
    setSideA(sideA);
    setSideB(sideB);
    setSideC(sideC);
}

void
Triangle::setSideA(const double side)
{
    sideA_ = side;
}

void
Triangle::setSideB(const double side)
{
    sideB_ = side;
}

void
Triangle::setSideC(const double side)
{
    sideC_ = side;
}

double
Triangle::getSideA() const
{
    return sideA_;
}

double
Triangle::getSideB() const
{
    return sideB_;
}

double
Triangle::getSideC() const
{
    return sideC_;
}

double
Triangle::getArea() const
{
    const double halfPerimetr = (getSideA() + getSideB() + getSideC()) / 2.0;
    return std::sqrt(halfPerimetr *
                    (halfPerimetr - getSideA()) *
                    (halfPerimetr - getSideB()) *
                    (halfPerimetr - getSideC()));
}

void
Triangle::print() const
{
    std::cout << "Triangle (a = " << getSideA() 
              << ", b = "         << getSideB() 
              << ", c = "         << getSideC() << ")\n"
              << "Area is "       << getArea();
}

bool
Triangle::validateTriangle(const double sideA, const double sideB, const double sideC)
{
    return (sideA + sideB > sideC && 
            sideA + sideC > sideB && 
            sideB + sideC > sideA);
}

