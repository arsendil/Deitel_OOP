#include "../headers/TwoDayPackage.hpp"

TwoDayPackage::TwoDayPackage(Person& senderPerson, Person& recipientPerson,
                             const double weight, const double costPerOunce, const double twoDayDeliveryFee)
    : Package(senderPerson, recipientPerson, weight, costPerOunce)
{
    setTwoDayDeliveryFee(twoDayDeliveryFee);
}

TwoDayPackage::TwoDayPackage(TwoDayPackage& rhv)
    : Package(rhv)
    , twoDayDeliveryFee_(rhv.getTwoDayDeliveryFee())
{}

TwoDayPackage&
TwoDayPackage::operator=(const TwoDayPackage& rhv)
{
    if (this != &rhv) {
        Package::operator=(rhv);
        setTwoDayDeliveryFee(rhv.getTwoDayDeliveryFee());
    }
    return *this;
}

void
TwoDayPackage::setTwoDayDeliveryFee(const double twoDayDeliveryFee)
{
    assert(twoDayDeliveryFee >= 0);
    twoDayDeliveryFee_ = twoDayDeliveryFee;
}

double
TwoDayPackage::getTwoDayDeliveryFee() const
{
    return twoDayDeliveryFee_;
}

double
TwoDayPackage::calculateCost() const
{
    return Package::calculateCost() + getTwoDayDeliveryFee();
}

std::ostream&
operator<<(std::ostream& output, const TwoDayPackage& rhv)
{
    output << static_cast<const Package&>(rhv);
    output << "Flat fee for 2-day delivery: "    << rhv.getTwoDayDeliveryFee() << '\n';
    output << "Total cost with 2-day delivery: " << rhv.calculateCost()        << '\n';
    return output;
}

std::istream&
operator>>(std::istream& input, TwoDayPackage& rhv)
{
    input >> static_cast<Package&>(rhv);

    double fee;
    input >> fee;
    rhv.setTwoDayDeliveryFee(fee);

    input.ignore();
    return input;
}
