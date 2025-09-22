#ifndef __HUGE_INTEGER_HPP__
#define __HUGE_INTEGER_HPP__

#include <iostream>
#include <string>

const int SIZE = 40;
const int POWER = 10;

class HugeInteger 
{
public:
    HugeInteger(const long number1 = 0);
    HugeInteger(const HugeInteger& other);
    HugeInteger(const char* number1);
    void output() const;
    HugeInteger add(const HugeInteger& other) const;
    HugeInteger subtract(const HugeInteger& other) const;
    HugeInteger multiply(const HugeInteger& other) const;
    bool isEqualTo(const HugeInteger& other) const;
    bool isNotEqualTo(const HugeInteger& other) const;
    bool isGreaterThan(const HugeInteger& other) const;
    bool isLessThan(const HugeInteger& other) const;
    bool isGreaterThanOrEqualTo(const HugeInteger& other) const;
    bool isLessThanOrEqualTo(const HugeInteger& other) const;
    bool isZero() const;

private:
    void setNumber(const char* number1);
    void setNumber(int number1);
    bool isDigit(const char* number1) const;
    void init();

private:
    int digits[SIZE];

};

#endif /// __HUGE_INTEGER_HPP__

