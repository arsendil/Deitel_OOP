#ifndef __CIRCLE_HPP__
#define __CIRCLE_HPP__

#include "TwoDimensionalShape.hpp"

class Circle : public TwoDimensionalShape
{
public:
    Circle(const double radius = 1);
    virtual ~Circle();

    void setRadius(const double radius);
    double getRadius() const;

    virtual void print()     const;
    virtual double getArea() const;

private:
    double radius_;

};

#endif /// __CIRCLE_HPP__

