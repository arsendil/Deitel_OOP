#include "../headers/Square.hpp"

Square::Square(const double side)
{
    setSide(side);
}

Square::~Square()
{}

void
Square::setSide(const double side)
{
    assert(side > 0);
    side_ = side;
}

double
Square::getSide() const
{
    return side_;
}

double
Square::getArea() const
{
    return getSide() * getSide();
}

void
Square::print() const
{
    std::cout << "Square (a = " << getSide() << ")\n"
              << "Area is "     << getArea();
}

