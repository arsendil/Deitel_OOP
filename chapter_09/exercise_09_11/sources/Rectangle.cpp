#include "../headers/Rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const float width, const float length)
{
    setWidth(width);
    setLength(length);
}

Rectangle::Rectangle(const Rectangle& other)
{
    setWidth(other.getWidth());
    setLength(other.getLength());
}

float
Rectangle::area() const
{
    return getWidth() * getLength();
}

float
Rectangle::perimeter() const
{
    return 2 * (getWidth() + getLength());
}

float
Rectangle::getWidth() const
{
    return width_;
}

float
Rectangle::getLength() const
{
    return length_;
}

void
Rectangle::setWidth(const float width)
{
    assert(width > MIN_LENGTH && width < MAX_LENGTH);
    width_ = width;
}

void
Rectangle::setLength(const float length)
{
    assert(length > MIN_LENGTH && length < MAX_LENGTH);
    length_ = length;
}

