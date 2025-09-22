#include "../headers/HugeInteger.hpp"
#include <cassert>
#include <cmath>
#include <cstring>

HugeInteger::HugeInteger(const long number1)
{
    setNumber(number1);
}

HugeInteger::HugeInteger(const char* number1)
{
    setNumber(number1);
}

HugeInteger::HugeInteger(const HugeInteger& other)
{
    for (int i = 0; i < SIZE; ++i) {
        digits[i] = other.digits[i];
    }
}

void
HugeInteger::setNumber(int number1)
{
    init();
    int count = SIZE - 1;
    while (0 != number1) {
       digits[count] = number1 % POWER;
       number1 /= POWER;
       --count;
    } 
}

void
HugeInteger::setNumber(const char* number1)
{
    assert(isDigit(number1) && std::strlen(number1) < SIZE);
    init();
    const int len = std::strlen(number1);
    const int start = SIZE - len;
    for (int i = 0; i < len; ++i) {
        digits[start + i] = number1[i] - '0';
    }
}

bool
HugeInteger::isDigit(const char* number1) const
{
    const int size = std::strlen(number1);
    for (int i = 0; i < size; ++i) {
        if (!std::isdigit(number1[i])) {
            return false;
        }
    }
    return true;
}

void
HugeInteger::output() const
{
    bool isZero = true;
    for (int i = 0; i < SIZE; ++i) {
        if (isZero && 0 == digits[i]) continue;
        isZero = false;
        std::cout << digits[i];
    }
    if (isZero) {
        std::cout << "0";
    }
    std::cout << std::endl;
}

void
HugeInteger::init()
{
    for (int i = 0; i < SIZE; ++i) {
        digits[i] = 0;
    }
}

HugeInteger
HugeInteger::add(const HugeInteger& other) const
{
    HugeInteger result;
    int carry = 0;
    for (int i = SIZE - 1; i >= 0; --i) {
        const int sum = digits[i] + other.digits[i] + carry;
        result.digits[i] = sum % POWER;
        carry = sum / POWER;
    }
    return result;
}

HugeInteger
HugeInteger::subtract(const HugeInteger& other) const
{
    HugeInteger result;
    int borrow = 0;
    for (int i = SIZE - 1; i >= 0; --i) {
        int difference = digits[i] - other.digits[i] - borrow;
        if (difference < 0) {
            difference += POWER;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.digits[i] = difference;
    }
    return result;
}

HugeInteger
HugeInteger::multiply(const HugeInteger& other) const
{
    HugeInteger result;

    for (int i = SIZE - 1; i >= 0; --i) {
        int carry = 0;
        for (int j = SIZE - 1; j >= 0; --j) {
            const int k = i + j - (SIZE - 1);
            if (k < 0 || k >= SIZE) continue;

            const int product = digits[i] * other.digits[j] + result.digits[k] + carry;
            result.digits[k] = product % POWER;
            carry = product / POWER;
        }
    }

    return result;
}

bool
HugeInteger::isEqualTo(const HugeInteger& other) const
{
    for (int i = 0; i < SIZE; ++i) {
        if (digits[i] != other.digits[i]) {
            return false;
        }
    }
    return true;
}

bool
HugeInteger::isNotEqualTo(const HugeInteger& other) const
{
    return !isEqualTo(other);
}

bool
HugeInteger::isGreaterThan(const HugeInteger& other) const
{
    return other.isLessThan(*this);
}

bool
HugeInteger::isLessThan(const HugeInteger& other) const
{
    for (int i = 0; i < SIZE; ++i) {
        if (digits[i] < other.digits[i]) {
            return true;
        } else if (digits[i] > other.digits[i]) {
            return false;
        }
    }
    return false;
}

bool
HugeInteger::isGreaterThanOrEqualTo(const HugeInteger& other) const
{
    return !isLessThan(other);
}

bool
HugeInteger::isLessThanOrEqualTo(const HugeInteger& other) const
{
    return !isGreaterThan(other);
}

bool
HugeInteger::isZero() const
{
    for (int i = 0; i < SIZE; ++i) {
        if (digits[i] != 0) {
            return false;
        }
    }
    return true;
}

