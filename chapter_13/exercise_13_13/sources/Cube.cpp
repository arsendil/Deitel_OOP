#include "../headers/Cube.hpp"

Cube::Cube(const double side)
{
    setSide(side);
}

Cube::~Cube()
{}

void
Cube::setSide(const double side)
{
    assert(side > 0);
    side_ = side;
}

double
Cube::getSide() const
{
    return side_;
}

double
Cube::getArea() const
{
    return 6 * getSide() * getSide();
}

double
Cube::getVolume() const
{
    return std::pow(getSide(), 3);
}

void
Cube::print() const
{
    std::cout << "Cube (a = " << getSide()   << ")\n"
              << "Area is "   << getArea()   << '\n'
              << "Volume is " << getVolume();
}

