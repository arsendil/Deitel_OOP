#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include "TwoDimensionalShape.hpp"

class Triangle : public TwoDimensionalShape
{
public:
    Triangle(const double sideA = 1, const double sideB = 1, const double sideC = 1);
    virtual ~Triangle();

    void setTriangle(const double sideA, const double sideB, const double sideC);
        
    double getSideA() const;
    double getSideB() const;
    double getSideC() const; 

    virtual double getArea() const;
    virtual void print()     const;

private:
    bool validateTriangle(const double sideA, const double sideB, const double sideC);
    void setSideA(const double side);
    void setSideB(const double side);
    void setSideC(const double side);

private:
    double sideA_;
    double sideB_;
    double sideC_;
};

#endif /// __TRIANGLE_HPP__

