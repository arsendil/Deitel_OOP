#ifndef __INTEGER_SET__
#define __INTEGER_SET__

const int SIZE = 101;

class IntegerSet
{
public:
    IntegerSet();
    IntegerSet(const int array[], const int size);
    IntegerSet(const IntegerSet& other);
    void insertElement(const int index);
    void deleteElement(const int index);
    bool getElement(const int index) const;

    IntegerSet unionOfSets(const IntegerSet& other) const;
    IntegerSet intersectionOfSets(const IntegerSet& other) const;

    void printSet() const;
    bool isEqualTo(const IntegerSet& other) const;

private:
    void init();

private:
    bool set_[SIZE];

};

#endif /// __INTEGER_SET__

