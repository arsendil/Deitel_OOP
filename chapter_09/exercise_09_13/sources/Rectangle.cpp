#include "../headers/Rectangle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>

Rectangle:: Rectangle(const Point& coordinateA, const Point& coordinateB, const Point& coordinateC, const Point& coordinateD, const char fillChar, const char perimeter)
{
    setCoordinates(coordinateA, coordinateB, coordinateC, coordinateD);
    setFillCharacter(fillChar);
    setPerimeterCharacter(perimeter);
}

Rectangle::Rectangle(const Rectangle& other)
{
    setCoordinates(other.getCoordinateA(), other.getCoordinateB(), other.getCoordinateC(), other.getCoordinateD());
    setFillCharacter(other.fillChar_);
    setPerimeterCharacter(other.perimeterChar_);
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
Rectangle::isRightAngle(const Point& coordinateA, const Point& coordinateB, const Point& coordinateC) const 
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

void
Rectangle::setFillCharacter(const char fill)
{
    fillChar_ = fill;
}

void
Rectangle::setPerimeterCharacter(const char perimeter)
{
    perimeterChar_ = perimeter;
}

char
Rectangle::getFillCharacter() const
{
    return fillChar_;
}

char
Rectangle::getPerimetrCharacter() const
{
    return perimeterChar_;
}

void
Rectangle::draw()
{
    const double k = std::fabs((0 == (coordinateB_.x_ - coordinateA_.x_)) ? 0 : ((coordinateB_.y_ - coordinateA_.y_) / (coordinateB_.x_ - coordinateA_.x_)));
    Point* coordinates[] = {&coordinateA_, &coordinateB_, &coordinateC_, &coordinateD_};
    
    Point* maxX = coordinates[0];
    Point* minX = coordinates[0];
    Point* maxY = coordinates[0];
    Point* minY = coordinates[0];

    for (int i = 1; i < COUNT_WIDTH; ++i) {
        if (maxX->x_ <= coordinates[i]->x_) {
            maxX = coordinates[i];
        }
        if (minX->x_ >= coordinates[i]->x_) {
            minX = coordinates[i];
        }
        if (maxY->y_ <= coordinates[i]->y_) {
            maxY = coordinates[i];
        }
        if (minY->y_ >= coordinates[i]->y_) {
            minY = coordinates[i];
        }
    }

    for (int y = GRID_SIZE; y >= 0; --y) {
        for (int x = 0; x <= GRID_SIZE; ++x) {
            const double firstStraight  =  -k * (x - minX->x_) + minX->y_;
            const double secondStraight  =  k * (x - minY->x_) + minY->y_;
            const double thirdStraight  =  -k * (x - maxX->x_) + maxX->y_;
            const double fourthStraight =   k * (x - maxY->x_) + maxY->y_;
            if (y > secondStraight && y > firstStraight && y < thirdStraight && y < fourthStraight) {
                std::cout << getFillCharacter();
            } else if (y <= static_cast<int>(maxY->y_) &&
                       y >= static_cast<int>(minY->y_) &&
                       x >= static_cast<int>(minX->x_) &&
                       x <= static_cast<int>(maxX->x_) && (
                       y == static_cast<int>(secondStraight) ||
                       y == static_cast<int>(firstStraight)  ||
                       y == static_cast<int>(thirdStraight)  ||
                       y == static_cast<int>(fourthStraight))) {
                std::cout << getPerimetrCharacter();
            } else {
                std::cout << ' ';
            }  
        }
        std::cout << std::endl;
    }
}

