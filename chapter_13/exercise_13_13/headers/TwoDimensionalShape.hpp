#ifndef __TWO_DIMENSIONAL_SHAPE_HPP__
#define __TWO_DIMENSIONAL_SHAPE_HPP__

#include "Shape.hpp"

class TwoDimensionalShape : public Shape
{
public:
    virtual ~TwoDimensionalShape() {}
    virtual double getArea() const = 0;
    virtual void print()     const = 0;
};

#endif /// __TWO_DIMENSIONAL_SHAPE_HPP__

