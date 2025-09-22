#include <gtest/gtest.h>
#include "headers/Monomial.hpp"
#include "headers/Polinomial.hpp"

TEST(MonomialTest, ConstructorAndGetters)
{
    Monomial m(5, 3);
    EXPECT_EQ(m.getCoefficient(), 5);
    EXPECT_EQ(m.getPower(), 3);
}

TEST(MonomialTest, AdditionSamePower)
{
    Monomial m1(0, 4);
    Monomial m2(2, 2);
    Monomial sum = m1 + m2;
    EXPECT_EQ(sum.getCoefficient(), 2);
    EXPECT_EQ(sum.getPower(), 2);
}

TEST(MonomialTest, Multiplication)
{
    Monomial m1(2, 2);
    Monomial m2(3, 3);
    Monomial prod = m1 * m2;
    EXPECT_EQ(prod.getCoefficient(), 6);
    EXPECT_EQ(prod.getPower(), 5);
}

TEST(MonomialTest, OperatorsAssignment)
{
    Monomial m1(4, 2);
    Monomial m2(0, 3);
    m2 += m1;
    EXPECT_EQ(m2.getCoefficient(), 4);
    EXPECT_EQ(m2.getPower(), 2);
    m2 -= Monomial(2, 2);
    EXPECT_EQ(m2.getCoefficient(), 2);
    EXPECT_EQ(m2.getPower(), 2);
    m2 *= Monomial(2, 1);
    EXPECT_EQ(m2.getCoefficient(), 4);
    EXPECT_EQ(m2.getPower(), 3);
}

TEST(PolinomialTest, ConstructorAndGet)
{
    Monomial monoms[] = { Monomial(1,0), Monomial(2,1), Monomial(3,2) };
    Polinomial p(monoms, 3);
    EXPECT_EQ(p.getMonomial(0).getCoefficient(), 1);
    EXPECT_EQ(p.getMonomial(1).getCoefficient(), 2);
    EXPECT_EQ(p.getMonomial(2).getCoefficient(), 3);
}

TEST(PolinomialTest, AdditionOperator)
{
    Monomial monoms1[] = { Monomial(2,0), Monomial(1,1) };
    Monomial monoms2[] = { Monomial(3,0), Monomial(4,1) };
    Polinomial p1(monoms1, 2);
    Polinomial p2(monoms2, 2);

    Polinomial sum = p1 + p2;
    EXPECT_EQ(sum.getMonomial(0).getCoefficient(), 5);
    EXPECT_EQ(sum.getMonomial(1).getCoefficient(), 5);
}

TEST(PolinomialTest, SubtractionOperator)
{
    Monomial monoms1[] = { Monomial(5,0), Monomial(6,1) };
    Monomial monoms2[] = { Monomial(3,0), Monomial(4,1) };
    Polinomial p1(monoms1, 2);
    Polinomial p2(monoms2, 2);

    Polinomial diff = p1 - p2;
    EXPECT_EQ(diff.getMonomial(0).getCoefficient(), 2);
    EXPECT_EQ(diff.getMonomial(1).getCoefficient(), 2);
}

TEST(PolinomialTest, MultiplicationOperator)
{
    Monomial monoms1[] = { Monomial(1,0), Monomial(1,1) };
    Monomial monoms2[] = { Monomial(1,0), Monomial(-1,1) };
    Polinomial p1(monoms1, 2);
    Polinomial p2(monoms2, 2);

    Polinomial prod = p1 * p2;
    EXPECT_EQ(prod.getMonomial(0).getCoefficient(), 1);  
    EXPECT_EQ(prod.getMonomial(1).getCoefficient(), 0); 
    EXPECT_EQ(prod.getMonomial(2).getCoefficient(), -1);
}

TEST(PolinomialTest, MultiplySimplePolinomials)
{
    Monomial m1[] = { Monomial(2, 1), Monomial(1, 0) }; 
    Monomial m2[] = { Monomial(3, 1), Monomial(4, 0) };  

    Polinomial p1(m1, 2);
    Polinomial p2(m2, 2);

    p1 *= p2;

    EXPECT_EQ(p1.getMonomial(2).getCoefficient(), 6);
    EXPECT_EQ(p1.getMonomial(2).getPower(), 2);

    EXPECT_EQ(p1.getMonomial(1).getCoefficient(), 11);
    EXPECT_EQ(p1.getMonomial(1).getPower(), 1);

    EXPECT_EQ(p1.getMonomial(0).getCoefficient(), 4);
    EXPECT_EQ(p1.getMonomial(0).getPower(), 0);
}

TEST(PolinomialTest, MultiplySamePowersCombine)
{
    Monomial m1[] = { Monomial(1, 1), Monomial(1, 0) }; 
    Polinomial p(m1, 2);

    p *= p; 

    EXPECT_EQ(p.getMonomial(2).getCoefficient(), 1);
    EXPECT_EQ(p.getMonomial(1).getCoefficient(), 2);
    EXPECT_EQ(p.getMonomial(0).getCoefficient(), 1);
}

TEST(PolinomialTest, AssignmentOperator)
{
    Monomial monoms1[] = { Monomial(3,0), Monomial(2,1) };
    Polinomial p1(monoms1, 2);
    Polinomial p2 = p1;
    EXPECT_EQ(p2.getMonomial(0).getCoefficient(), 3);
    EXPECT_EQ(p2.getMonomial(1).getCoefficient(), 2);
}

TEST(PolinomialTest, CompoundOperators)
{
    Monomial m1[] = { Monomial(1, 0), Monomial(2, 1) };
    Monomial m2[] = { Monomial(3, 0), Monomial(4, 1) };
    Polinomial p1(m1, 2);
    Polinomial p2(m2, 2);

    p1 += p2;
    EXPECT_EQ(p1.getMonomial(0).getCoefficient(), 4);
    EXPECT_EQ(p1.getMonomial(1).getCoefficient(), 6);

    p1 -= p2;
    EXPECT_EQ(p1.getMonomial(0).getCoefficient(), 1);
    EXPECT_EQ(p1.getMonomial(1).getCoefficient(), 2);

    p1 *= p2;
    EXPECT_EQ(p1.getMonomial(0).getCoefficient(), 3);  
    EXPECT_EQ(p1.getMonomial(1).getCoefficient(), 10);
    EXPECT_EQ(p1.getMonomial(2).getCoefficient(), 8);  
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
