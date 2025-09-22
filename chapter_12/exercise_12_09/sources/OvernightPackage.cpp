#include "../headers/OvernightPackage.hpp"

OvernightPackage::OvernightPackage(Person& senderPerson, Person& recipientPerson,
                                   const double weight, const double costPerOunce, const double extraFeePerOunce)
    : Package(senderPerson, recipientPerson, weight, costPerOunce)
{
    setExtraFeePerOunce(extraFeePerOunce);
}

OvernightPackage::OvernightPackage(OvernightPackage& rhv)
    : Package(rhv)
    , extraFeePerOunce_(rhv.getExtraFeePerOunce())
{}

OvernightPackage&
OvernightPackage::operator=(const OvernightPackage& rhv)
{
    if (this != &rhv) {
        Package::operator=(rhv);
        setExtraFeePerOunce(rhv.getExtraFeePerOunce());
    }
    return *this;
}

void
OvernightPackage::setExtraFeePerOunce(const double extraFeePerOunce)
{
    assert(extraFeePerOunce >= 0);
    extraFeePerOunce_ = extraFeePerOunce;
}

double
OvernightPackage::getExtraFeePerOunce() const
{
    return extraFeePerOunce_;
}

double
OvernightPackage::calculateCost() const
{
    return getWeight() * (getCostPerOunce() + getExtraFeePerOunce());
}

std::ostream&
operator<<(std::ostream& output, const OvernightPackage& rhv)
{
    output << static_cast<const Package&>(rhv);
    output << "Extra fee per ounce for overnight delivery: " << rhv.getExtraFeePerOunce() << '\n';
    output << "Total cost with overnight delivery: " << rhv.calculateCost() << '\n';
    return output;
}

std::istream&
operator>>(std::istream& input, OvernightPackage& rhv)
{
    input >> static_cast<Package&>(rhv);
    double fee;
    input >> fee;
    rhv.setExtraFeePerOunce(fee);

    input.ignore();
    return input;
}

