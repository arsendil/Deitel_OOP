#include "../headers/Point.hpp"
#include <cassert>

Point::Point(const double x, const double y)
{
    setPoint(x, y);
}

Point::Point(const Point& other)
{
    setPoint(other.x_, other.y_);
}

void
Point::setPoint(const double x, const double y)
{
    assert(x >= MIN_VALUE_COORDINATE && x <= MAX_VALUE_COORDINATE &&
           y >= MIN_VALUE_COORDINATE && y <= MAX_VALUE_COORDINATE);
    x_ = x;
    y_ = y; 
}

