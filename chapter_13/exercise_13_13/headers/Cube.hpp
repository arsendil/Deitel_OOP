#ifndef __CUBE_HPP__
#define __CUBE_HPP__

#include "ThreeDimensionalShape.hpp"

class Cube : public ThreeDimensionalShape
{
public:
    Cube(const double side);
    virtual ~Cube();

    void setSide(const double side);
    double getSide() const;

    virtual double getArea()   const;
    virtual double getVolume() const;
    virtual void print()       const;

private:
    double side_;
};

#endif /// __CUBE_HPP__

