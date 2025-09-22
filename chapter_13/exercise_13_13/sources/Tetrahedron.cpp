#include "../headers/Tetrahedron.hpp"

Tetrahedron::Tetrahedron(const double edge)
{
    setEdge(edge);
}

Tetrahedron::~Tetrahedron()
{}

void
Tetrahedron::setEdge(const double edge)
{
    assert(edge > 0);
    edge_ = edge;
}

double
Tetrahedron::getEdge() const
{
    return edge_;
}

double
Tetrahedron::getArea() const
{
    return std::sqrt(3.0) * std::pow(getEdge(), 2); 
}

double
Tetrahedron::getVolume() const
{
     return (std::pow(getEdge(), 3)) / (6.0 * std::sqrt(2.0));
}

void
Tetrahedron::print() const
{
    std::cout << "Tetrahedron (a = " << getEdge() << ")\n"
              << "Area is "   << getArea()   << '\n'
              << "Volume is " << getVolume();
}

