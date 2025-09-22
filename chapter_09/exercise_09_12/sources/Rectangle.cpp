#include "../headers/Rectangle.hpp"
#include <cassert>
#include <cmath>

Rectangle:: Rectangle(const Point& coordinateA, const Point& coordinateB, const Point& coordinateC, const Point& coordinateD)
{
    setCoordinates(coordinateA, coordinateB, coordinateC, coordinateD);
}

Rectangle::Rectangle(const Rectangle& other)
{
    setCoordinates(other.getCoordinateA(), other.getCoordinateB(), other.getCoordinateC(), other.getCoordinateD());
}

void
Rectangle::setCoordinates(const Point& coordinateA, const Point& coordinateB, const Point& coordinateC, const Point& coordinateD)
{
    assert(inFirstQuadrant(coordinateA) && inFirstQuadrant(coordinateB) && inFirstQuadrant(coordinateC) && inFirstQuadrant(coordinateD));
    assert(isRightAngle(coordinateA, coordinateB, coordinateC) && isRightAngle(coordinateB, coordinateC, coordinateD) && 
           isRightAngle(coordinateC, coordinateD, coordinateA) && isRightAngle(coordinateD, coordinateA, coordinateB));
    coordinateA_ = coordinateA;
    coordinateB_ = coordinateB;
    coordinateC_ = coordinateC;
    coordinateD_ = coordinateD;
}

Point
Rectangle::getCoordinateA() const
{
    return coordinateA_;
}

Point
Rectangle::getCoordinateB() const
{
    return coordinateB_;
}

Point
Rectangle::getCoordinateC() const
{
    return coordinateC_;
}

Point
Rectangle::getCoordinateD() const
{
    return coordinateD_;
}

double
Rectangle::length() const
{
    return std::max(distance(coordinateA_, coordinateB_), distance(coordinateB_, coordinateC_));
}

double
Rectangle::width() const
{
    return std::min(distance(coordinateA_, coordinateB_), distance(coordinateB_, coordinateC_));
}

double
Rectangle::perimeter() const
{
    return POWER * (length() + width());
}

double
Rectangle::area() const
{
    return length() * width();
}

bool
Rectangle::square() const
{
    return std::fabs(length() - width()) < EPSILION; 
}

bool
Rectangle::inFirstQuadrant(const Point& point) const
{
    return (point.x_ >= MIN_VALUE_COORDINATE && point.x_ <= MAX_VALUE_COORDINATE &&
            point.y_ >= MIN_VALUE_COORDINATE && point.y_ <= MAX_VALUE_COORDINATE);
}

bool
Rectangle::isRightAngle(const Point& coordinateA, const Point& coordinateB, const Point& coordinateC) 
{
    const double abVectorX = coordinateB.x_ - coordinateA.x_;
    const double abVectorY = coordinateB.y_ - coordinateA.y_;
    const double bcVectorX = coordinateC.x_ - coordinateB.x_;
    const double bcVectorY = coordinateC.y_ - coordinateB.y_;
    return std::fabs(abVectorX * bcVectorX + abVectorY * bcVectorY) < EPSILION;
}

double
Rectangle::distance(const Point& coordinateA, const Point& coordinateB) const
{
    return std::sqrt(std::pow(coordinateA.x_ - coordinateB.x_, POWER) + std::pow(coordinateA.y_ - coordinateB.y_, POWER));
}

