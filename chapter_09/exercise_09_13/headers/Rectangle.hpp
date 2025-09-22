#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "Point.hpp"

const double POWER = 2;
const double EPSILION = 1e-6;
const int GRID_SIZE = 25;
const int COUNT_WIDTH = 4;

class Rectangle
{
public:
    Rectangle(const Point& coordinateA, const Point& coordinateB, const Point& coordinateC, const Point& coordinateD, const char fillChar = ' ', const char perimeter = '$');
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

    void setFillCharacter(const char fill);
    void setPerimeterCharacter(const char perimeter);
    char getFillCharacter() const; 
    char getPerimetrCharacter() const;
    void draw();

private:
    bool inFirstQuadrant(const Point& point) const;
    bool isRightAngle(const Point& coordinateA, const Point& coordinateB, const Point& coordinateC) const;
    double distance(const Point&  coordinateA, const Point& coordinateB) const;

private:
    Point coordinateA_;
    Point coordinateB_;
    Point coordinateC_;
    Point coordinateD_;

    char fillChar_;
    char perimeterChar_;
};

#endif /// __RECTANGLE_HPP__

