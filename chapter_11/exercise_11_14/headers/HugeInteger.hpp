#ifndef __HUGE_INTEGER_HPP__
#define __HUGE_INTEGER_HPP__

#include <iostream>
#include <string>

const int SIZE = 60;
const int POWER = 10;

class HugeInteger 
{
    friend std::ostream& operator<<(std::ostream& output, const HugeInteger& number1);
    friend std::istream& operator>>(std::istream& input, HugeInteger& number1);
public:
    static int getCount(HugeInteger& temp, const HugeInteger& divisor);

public:
    HugeInteger(const long number1 = 0);
    HugeInteger(const HugeInteger& rhv);
    HugeInteger(const char* number1);
    HugeInteger operator+(const HugeInteger& rhv) const;
    HugeInteger operator+(long number1)           const;
    HugeInteger operator+(const char* number1)    const;
    HugeInteger operator-(const HugeInteger& rhv) const;
    HugeInteger operator-(long number1)           const;
    HugeInteger operator-(const char* number)     const;
    HugeInteger operator*(const HugeInteger& rhv) const;
    HugeInteger operator*(long number1)           const;
    HugeInteger operator*(char* number)           const;
    HugeInteger operator/(const HugeInteger& divisor) const;
    HugeInteger operator/(const long number1)         const;
    HugeInteger operator/(char* number1)              const;
    HugeInteger operator-=(const HugeInteger& rhv);
    bool operator==(const HugeInteger& rhv) const;
    bool operator!=(const HugeInteger& rhv) const;
    bool operator>(const HugeInteger& rhv)  const;
    bool operator<(const HugeInteger& rhv)  const;
    bool operator>=(const HugeInteger& rhv) const;
    bool operator<=(const HugeInteger& rhv) const;
    bool isZero() const;

private:
    void setNumber(const char* number1);
    void setNumber(long number1);
    bool isDigit(const char* number1) const;
    void init();

private:
    int digits_[SIZE];

};

#endif /// __HUGE_INTEGER_HPP__

