#ifndef __POINT_HPP__
#define __POINT_HPP__

const double MIN_VALUE_COORDINATE = 0.0;
const double MAX_VALUE_COORDINATE = 20.0;

class Point
{
public:
   Point(const double x = MIN_VALUE_COORDINATE, const double y = MIN_VALUE_COORDINATE);
   Point(const Point& other);
   void setPoint(const double x, const double y);

   double x_;
   double y_;
};

#endif /// __POINT_HPP__

