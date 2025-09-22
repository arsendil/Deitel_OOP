#include "../headers/Proxy.hpp"
#include "../headers/DoubleSubscriptedArray.hpp"

Proxy::Proxy(DoubleSubscriptedArray& parent, const int index)
    : parent_(parent)
    , index_(index)
{}

Proxy&
Proxy::operator=(const int value)
{
    parent_.array_[index_] = value;
    parent_.sortingArray();
    return *this;
}

Proxy::operator int() const
{
    return parent_.array_[index_];
}
