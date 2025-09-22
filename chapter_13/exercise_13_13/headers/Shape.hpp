#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

#include <cmath>
#include <iostream>
#include <cassert>

class Shape
{
public:
    virtual ~Shape() {}
    virtual void print() const = 0;
    virtual double getArea() const = 0;
};

#endif /// __SHAPE_HPP__

