#ifndef __PROXY_HPP__
#define __PROXY_HPP__

class DoubleSubscriptedArray;

class Proxy
{
public:
    Proxy(DoubleSubscriptedArray& parent, const int index);

    Proxy& operator=(const int value);

    operator int() const;

private:
    DoubleSubscriptedArray& parent_;
    int index_;
};

#endif /// __PROXY_HPP__
