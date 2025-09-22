#include "../headers/HugeInteger.hpp"
#include <cassert>
#include <cmath>
#include <cstring>
#include <string>

HugeInteger::HugeInteger(const long number1)
{
    setNumber(number1);
}

HugeInteger::HugeInteger(const char* number1)
{
    setNumber(number1);
}

HugeInteger::HugeInteger(const HugeInteger& rhv)
{
    for (int i = 0; i < SIZE; ++i) {
        digits_[i] = rhv.digits_[i];
    }
}

void
HugeInteger::setNumber(long number1)
{
    init();
    int count = SIZE - 1;
    while (0 != number1) {
       digits_[count] = number1 % POWER;
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
        digits_[start + i] = number1[i] - '0';
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
HugeInteger::init()
{
    for (int i = 0; i < SIZE; ++i) {
        digits_[i] = 0;
    }
}

HugeInteger
HugeInteger::operator+(const HugeInteger& rhv) const
{
    HugeInteger result;
    int carry = 0;
    for (int i = SIZE - 1; i >= 0; --i) {
        const int sum = digits_[i] + rhv.digits_[i] + carry;
        result.digits_[i] = sum % POWER;
        carry = sum / POWER;
    }
    return result;
}

HugeInteger
HugeInteger::operator+(long number1) const
{
    HugeInteger result;
    int carry = 0;
    for (int i = SIZE - 1; i > 0; --i) {
        const int digit = number1 % POWER;
        const int sum = digits_[i] + digit + carry;
        result.digits_[i] = sum % POWER;
        carry = sum / POWER;
        number1 /= POWER;
    }
    return result;
}

HugeInteger
HugeInteger::operator+(const char* number1) const
{   
    assert(isDigit(number1) && std::strlen(number1) < SIZE);

    const int len = std::strlen(number1);
    HugeInteger result;
    int carry = 0;
    const int start = SIZE - len;
    int index = len - 1;
    for (int i = SIZE - 1; i >= start; --i) {
        const int sum = digits_[i] + (number1[index--] - '0') + carry;
        result.digits_[i] = sum % POWER;
        carry = sum / POWER;
    }
    return result;
}

HugeInteger
HugeInteger::operator-(const HugeInteger& rhv) const
{
    HugeInteger temp = *this;
    temp -= rhv;
    return temp;
}

HugeInteger
HugeInteger::operator-(long number1) const
{
    HugeInteger result;
    int borrow = 0;
    for (int i = SIZE - 1; i >= 0; --i) {
        const int digit = number1 % POWER;
        int difference = digits_[i] - digit - borrow;
        if (difference < 0) {
            difference += POWER;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.digits_[i] = difference;
        number1 /= POWER;
    }
    return result;
}

HugeInteger
HugeInteger::operator-(const char* number1) const
{
    assert(isDigit(number1) && std::strlen(number1) < SIZE);

    HugeInteger result;
    int borrow = 0;
    const int len = std::strlen(number1);
    const int start = SIZE - len;
    int index = len - 1;

    for (int i = SIZE - 1; i >= start; --i) {
        int difference = digits_[i] - (number1[index--] - '0') - borrow;
        if (difference < 0) {
            difference += POWER;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.digits_[i] = difference;
    }
    return result;
}

HugeInteger
HugeInteger::operator*(const HugeInteger& rhv) const
{
    HugeInteger result;
    for (int i = SIZE - 1; i >= 0; --i) {
        int carry = 0;
        for (int j = SIZE - 1; j >= 0; --j) {
            const int k = i + j - (SIZE - 1);
            if (k < 0 || k >= SIZE) continue;

            const int product = digits_[i] * rhv.digits_[j] + result.digits_[k] + carry;
            result.digits_[k] = product % POWER;
            carry = product / POWER;
        }
    }
    return result;
}

HugeInteger
HugeInteger::operator*(long number1) const
{
    HugeInteger result;
    for (int i = SIZE - 1; i >= 0; --i) {
        int carry = 0;
        long number2 = number1;
        for (int j = SIZE - 1; j >= 0; --j) {
            const int k = i + j - (SIZE - 1);
            const int digit = number2 % 10;
            if (k < 0 || k >= SIZE) continue;

            const int product = digits_[i] * digit + result.digits_[k] + carry;
            result.digits_[k] = product % POWER;
            carry = product / POWER;
            number2 /= 10;
        }
    }
    return result;

}

HugeInteger
HugeInteger::operator*(char* number1) const
{
    HugeInteger result;
    const int len = std::strlen(number1);

    for (int i = len - 1; i >= 0; --i) {
        int carry = 0;
        char* number2 = number1;
        for (int j = SIZE - 1; j >= 0; --j) {
            const int k = i + j - (SIZE - 1);
            const int digit = (number2[i] - '0');
            if (k < 0 || k >= SIZE) continue;

            const int product = digits_[i] * digit + result.digits_[k] + carry;
            result.digits_[k] = product % POWER;
            carry = product / POWER;
        }
    }
    return result;
}

HugeInteger
HugeInteger::operator/(const HugeInteger& divisor) const
{
    if (*this < divisor) return HugeInteger("0");
    HugeInteger result;
    HugeInteger temp;
    for (int i = 0; i < SIZE; ++i) {
        temp = temp * POWER;
        temp.digits_[SIZE - 1] = digits_[i];
        result = result * POWER;
        result.digits_[SIZE - 1] = getCount(temp, divisor);
    }
    return result;
}

HugeInteger
HugeInteger::operator/(const long number1) const
{
    assert(number1 > 0);
    HugeInteger result;
    long remainder = 0;
    for (int i = 0; i < SIZE; ++i) {
        const long current = remainder * POWER + digits_[i];
        result.digits_[i] = current / number1;
        remainder = current % number1;
    }
    return result;
}

HugeInteger
HugeInteger::operator/(char* number1) const
{
    HugeInteger result;
    long remainder = 0;
    for (int i = 0; i < SIZE; ++i) {
        long current = remainder * POWER + digits_[i];
        result.digits_[i] = current / (number1[i] - '0');
        remainder = current % (number1[i] - '0');
    }
    return result;

}

HugeInteger
HugeInteger::operator-=(const HugeInteger& rhv)
{
    int borrow = 0;
    for (int i = SIZE - 1; i >= 0; --i) {
        int difference = digits_[i] - rhv.digits_[i] - borrow;
        if (difference < 0) {
            difference += POWER;
            borrow = 1;
        } else {
            borrow = 0;
        }
        digits_[i] = difference;
    }
    return *this;
}

int
HugeInteger::getCount(HugeInteger& temp, const HugeInteger& divisor)
{
    int count = 0; 
    while (temp >= divisor) {
        temp -= divisor;
        ++count;
    }
    return count;
}

bool
HugeInteger::operator==(const HugeInteger& rhv) const
{
    for (int i = 0; i < SIZE; ++i) {
        if (digits_[i] != rhv.digits_[i]) {
            return false;
        }
    }
    return true;
}

bool
HugeInteger::operator!=(const HugeInteger& rhv) const
{
    return !(*this == rhv); 
}

bool
HugeInteger::operator>(const HugeInteger& rhv) const
{
    return !(*this < rhv || *this == rhv);
}

bool
HugeInteger::operator<(const HugeInteger& rhv) const
{
    for (int i = 0; i < SIZE; ++i) {
        if (digits_[i] < rhv.digits_[i]) {
            return true;
        } else if (digits_[i] > rhv.digits_[i]) {
            return false;
        }
    }
    return false;
}

bool
HugeInteger::operator>=(const HugeInteger& rhv) const
{
    return !(*this < rhv);
}

bool
HugeInteger::operator<=(const HugeInteger& rhv) const
{
    return !(*this > rhv);
}

bool
HugeInteger::isZero() const
{
    for (int i = 0; i < SIZE; ++i) {
        if (digits_[i] != 0) {
            return false;
        }
    }
    return true;
}

std::ostream&
operator<<(std::ostream& output, const HugeInteger& number1)
{
    bool isZero = true;
    for (int i = 0; i < SIZE; ++i) {
        if (isZero && 0 == number1.digits_[i]) continue;
        isZero = false;
        output << number1.digits_[i];
    }
    if (isZero) {
        output << "0";
    }
    return output;
}

std::istream&
operator>>(std::istream& input, HugeInteger& number1)
{   
    char number2[SIZE];
    input >> number2;
    number1 = number2;
    return input; 
}

