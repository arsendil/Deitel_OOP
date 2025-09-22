#ifndef __SPHERE_HPP__
#define __SPHERE_HPP__

#include "ThreeDimensionalShape.hpp"

class Sphere : public ThreeDimensionalShape
{
public:
    Sphere(const double radius);
    virtual ~Sphere();

    void setRadius(const double radius);
    double getRadius() const;

    virtual double getArea()   const;
    virtual double getVolume() const;
    virtual void print()       const;

private:
    double radius_;
}; 

#endif /// __SPHERE_HPP__

