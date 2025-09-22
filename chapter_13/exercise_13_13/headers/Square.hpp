#ifndef __SQUARE_HPP__
#define __SQUARE_HPP__

#include "TwoDimensionalShape.hpp"

class Square : public TwoDimensionalShape
{
public:
    Square(const double side);
    virtual ~Square();

    void setSide(const double side);
    double getSide() const;

    virtual double getArea() const;
    virtual void print()     const;

private:
    double side_;
};

#endif /// __SQUARE_HPP__

