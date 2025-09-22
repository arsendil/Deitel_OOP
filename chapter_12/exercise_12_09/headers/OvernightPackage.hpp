#ifndef __OVER_NIGHT_PACKAGE_HPP__
#define __OVER_NIGHT_PACKAGE_HPP__

#include "Package.hpp"

class OvernightPackage : public Package
{
    friend std::ostream& operator<<(std::ostream& output, const OvernightPackage& rhv);
    friend std::istream& operator>>(std::istream& input, OvernightPackage& rhv);

public:
    OvernightPackage(Person& senderPerson, Person& recipientPerson,
                     const double weight = 1, const double costPerOunce = 1, const double extraFeePerOunce = 0);
    OvernightPackage(OvernightPackage& rhv);

    OvernightPackage& operator=(const OvernightPackage& rhv);

    void setExtraFeePerOunce(const double extraFeePerOunce);
    double getExtraFeePerOunce() const;
    double calculateCost()       const;

private:
    double extraFeePerOunce_;
};

#endif /// __OVER_NIGHT_PACKAGE_HPP__

