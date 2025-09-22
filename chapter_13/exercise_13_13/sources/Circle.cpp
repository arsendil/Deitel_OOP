#include "../headers/Circle.hpp"

Circle::Circle(const double radius)
{
    setRadius(radius);
}

Circle::~Circle()
{}

void
Circle::setRadius(const double radius)
{
    assert(radius > 0);
    radius_ = radius;
}

double
Circle::getRadius() const
{
    return radius_;
}

double
Circle::getArea() const
{
     return M_PI * getRadius() * getRadius();
}

void
Circle::print() const
{
    std::cout << "Circle (r = " << getRadius() << ")\n"
              << "Area is "     << getArea();
}

