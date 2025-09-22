#include "../headers/Square.hpp"
#include <cctype>

Square::Square(const double side, const char fill)
{
    setSide(side);
    setFill(fill);
}

Square::~Square()
{}

void
Square::setSide(const double side)
{
    assert(side > 0);
    side_ = side;
}

void
Square::setFill(const char fill)
{
    assert(std::isprint(fill));
    fill_ = fill;
}

char
Square::getFill() const
{
    return fill_;
}

double
Square::getSide() const
{
    return side_;
}

double
Square::getArea() const
{
    return getSide() * getSide();
}

void
Square::draw() const
{
    const int size = getSide() - 1;
    const char fillCharacter = getFill();
    for (int i = 0; i < getSide(); ++i) {
        for (int j = 0; j < getSide(); ++j) {
            std::cout << ((0 == i || 0 == j || size == i || size == j) ? fillCharacter : ' ');
        }
        std::cout << std::endl;
    }
}

void
Square::print() const
{
    std::cout << "Square (a = " << getSide() << ")\n"
              << "Area is "     << getArea();
}
