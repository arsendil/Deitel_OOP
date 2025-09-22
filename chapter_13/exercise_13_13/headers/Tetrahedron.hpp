#ifndef __TETRAHEDRON_HPP__
#define __TETRAHEDRON_HPP__

#include "ThreeDimensionalShape.hpp"

class Tetrahedron : public ThreeDimensionalShape
{
public:
    Tetrahedron(const double edge);
    virtual ~Tetrahedron();

    void setEdge(const double edge);
    double getEdge() const;

    virtual double getArea()   const;
    virtual double getVolume() const;
    virtual void print()       const;

private:
    double edge_;
};

#endif /// __TETRAHEDRON_HPP__

