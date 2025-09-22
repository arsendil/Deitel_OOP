#include "../headers/IntegerSet.hpp"

#include <iostream>
#include <cassert>

IntegerSet::IntegerSet()
{
    init();
}

IntegerSet::IntegerSet(const int array[], const int size) 
{
    assert(size < SIZE && size >= 0);
    init();
    for (int i = 0; i < size; ++i) {
        assert(array[i] < SIZE);
        insertElement(array[i]);
    }
}

IntegerSet::IntegerSet(const IntegerSet& other)
{
    for (int i = 0; i < SIZE; ++i) {
        set_[i] = other.set_[i];
    }
}

void
IntegerSet::insertElement(const int index)
{
    assert(index < SIZE && index >= 0);
    set_[index] = true;
}

void
IntegerSet::deleteElement(const int index)
{
    assert(index < SIZE && index >= 0);
    set_[index] = false;
}

bool
IntegerSet::getElement(const int index) const
{
    assert(index < SIZE && index >= 0);
    return set_[index];
}

void
IntegerSet::printSet() const
{
    bool empty = true;
    for (int i = 0; i < SIZE; ++i) {
        if (set_[i]) {
            std::cout << i << ' ';
            empty = false;
        }
    }
    if (empty) {
        std::cout << "---";
    }
    std::cout << std::endl;
}

bool
IntegerSet::isEqualTo(const IntegerSet& other) const
{
    for (int i = 0; i < SIZE; ++i) {
        if (getElement(i) != other.getElement(i)) {
            return false;
        }
    }
    return true;
}

void
IntegerSet::init()
{
    for (int i = 0; i < SIZE; ++i) {
        set_[i] = false;
    }
}

IntegerSet
IntegerSet::unionOfSets(const IntegerSet& other) const
{
    IntegerSet set;
    for (int i = 0; i < SIZE; ++i) {
        set.set_[i] = getElement(i) || other.getElement(i);
    }
    return set;
}

IntegerSet
IntegerSet::intersectionOfSets(const IntegerSet& other) const
{
    IntegerSet set;
    for (int i = 0; i < SIZE; ++i) {
        set.set_[i] = getElement(i) && other.getElement(i);
    }
    return set;
}

