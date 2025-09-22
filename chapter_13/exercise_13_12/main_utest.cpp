#include <gtest/gtest.h>
#include "headers/Salaried.hpp"
#include "headers/HourlyEmployee.hpp"
#include "headers/ComissionEmployee.hpp"
#include "headers/BasePlusComissionEmployee.hpp"

TEST(SalariedEmployeeTest, EarningsWithoutBonus)
{
    Date birthDate("02/02/2011");
    SalariedEmployee emp("John", "Doe", "123-45-6789", birthDate, 1000);
    EXPECT_DOUBLE_EQ(emp.earnings(), 1000);
}

TEST(HourlyEmployeeTest, BasicEarningsWithoutOvertime)
{
    Date birthDate("02/02/2011");
    HourlyEmployee emp("Anna", "Smith", "987-65-4321", birthDate, 20.0, 30.0);
    EXPECT_DOUBLE_EQ(emp.earnings(), 600.0);
}

TEST(HourlyEmployeeTest, EarningsWithOvertime)
{
    Date birthDate("01/01/2000");
    HourlyEmployee emp("Anna", "Smith", "987-65-4321", birthDate, 20.0, 45.0);
    double base = 45.0 * 20.0;
    double overtimePay = (45.0 - 40.0) * 20.0 * 0.5;
    EXPECT_DOUBLE_EQ(emp.earnings(), base + overtimePay);
}

TEST(CommissionEmployeeTest, CommissionOnly) 
{
    Date birthDate("01/01/2000");
    CommissionEmployee emp("Mark", "Brown", "555-55-5555", birthDate, 10000.0, 0.1);
    EXPECT_DOUBLE_EQ(emp.earnings(), 10000.0 * 0.1);
}

TEST(BasePlusCommissionEmployeeTest, EarningsWithBase)
{
    Date birthDate("01/01/2000");
    BasePlusCommissionEmployee emp("Lucy", "Jones", "111-22-3333", birthDate, 5000.0, 0.1, 300.0);
    double expected = 500.0 + 300.0; // 500 from 10% of 5000
    EXPECT_DOUBLE_EQ(emp.earnings(), expected);
}


int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

