#include "../headers/Sphere.hpp"
#include <cmath>

Sphere::Sphere(const double radius)
{
    setRadius(radius);
}

Sphere::~Sphere()
{}

void
Sphere::setRadius(const double radius)
{
    assert(radius > 0);
    radius_ = radius;
}

double
Sphere::getRadius() const
{
    return radius_;
}

double
Sphere::getArea() const
{
    return 4.0 * M_PI * getRadius() * getRadius();
}

double
Sphere::getVolume() const
{
    return (4.0 / 3.0) * M_PI * std::pow(getRadius(), 3);
}

void
Sphere::print() const
{
    std::cout << "Sphere (r = " << getRadius() << ")\n"
              << "Area is "     << getArea()   << '\n'
              << "Volume is "   << getVolume();
}

