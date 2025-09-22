#ifndef __THREE_DIMENSIONAL_SHAPE_HPP__
#define __THREE_DIMENSIONAL_SHAPE_HPP__

#include "Shape.hpp"
#include <cmath>
#include <iostream>
#include <cassert>

class ThreeDimensionalShape : public Shape
{
public:
    virtual ~ThreeDimensionalShape() {}
    virtual double getArea()   const = 0;
    virtual double getVolume() const = 0;
    virtual void print()       const = 0;
};

#endif /// __THREE_DIMENSIONAL_SHAPE_HPP__

