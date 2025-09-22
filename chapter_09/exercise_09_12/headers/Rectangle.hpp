#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "Point.hpp"

const int POWER = 2;
const double EPSILION = 1e-6;

class Rectangle
{
public:
    Rectangle(const Point& coordinateA, const Point& coordinateB, const Point& coordinateC, const Point& coordinateD);
    Rectangle(const Rectangle& other);
    void setCoordinates(const Point& coordinateA, const Point& coordinateB, const Point& coordinateC, const Point& coordinateD);
    Point getCoordinateA() const;
    Point getCoordinateB() const;
    Point getCoordinateC() const;
    Point getCoordinateD() const;
    double length() const;
    double width() const;
    double perimeter() const;
    double area() const;
    bool square() const;

private:
    bool inFirstQuadrant(const Point& point) const;
    bool isRightAngle(const Point& coordinateA, const Point& coordinateB, const Point& coordinateC);
    double distance(const Point& coordinateA, const Point& coordinateB) const;

private:
    Point coordinateA_;
    Point coordinateB_;
    Point coordinateC_;
    Point coordinateD_;
};

#endif /// __RECTANGLE_HPP__

