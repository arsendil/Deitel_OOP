#ifndef __TWO_DAY_PACKAGE_HPP
#define __TWO_DAY_PACKAGE_HPP

#include "Package.hpp"

class TwoDayPackage : public Package
{
    friend std::ostream& operator<<(std::ostream& output, const TwoDayPackage& rhv);
    friend std::istream& operator>>(std::istream& input, TwoDayPackage& rhv);

public:
    TwoDayPackage(Person& senderPerson, Person& recipientPerson,
                  const double weight = 1, const double costPerOunce = 1, const double twoDayDeliveryFee = 0);
    TwoDayPackage(TwoDayPackage& rhv);

    TwoDayPackage& operator=(const TwoDayPackage& rhv);

    void setTwoDayDeliveryFee(const double twoDayDeliveryFee);
    double getTwoDayDeliveryFee() const;
    double calculateCost() const;

private:
    double twoDayDeliveryFee_;
};

#endif /// __TWO_DAY_PACKAGE_HPP__

