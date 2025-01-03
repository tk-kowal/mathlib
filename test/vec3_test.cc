#include <iostream>

#include <lamath.h>
#include "helpers.h"
#include <gtest/gtest.h>

namespace testing
{

    TEST(VectorTest, DefaultValues)
    {
        auto vec = lm::vec3();
        EXPECT_TRUE(AreEq(0.0, vec.x));
        EXPECT_TRUE(AreEq(0.0, vec.y));
        EXPECT_TRUE(AreEq(0.0, vec.z));
    }

    TEST(VectorTest, Initialization)
    {
        auto vec = lm::vec3{1.5, 2, -3.7};
        EXPECT_TRUE(AreEq(1.5, vec.x));
        EXPECT_TRUE(AreEq(2.0, vec.y));
        EXPECT_TRUE(AreEq(-3.7, vec.z));
    }

    TEST(VectorTest, InitializeWithScalar)
    {
        auto vec = lm::vec3(3.7f);
        EXPECT_TRUE(AreEq(3.7, vec.x));
        EXPECT_TRUE(AreEq(3.7, vec.y));
        EXPECT_TRUE(AreEq(3.7, vec.z));
    }

    TEST(VectorTest, InitializeWithOther)
    {
        auto other = lm::vec3{0.07, -1.29, 3.99};
        auto vec = lm::vec3(other);
        EXPECT_TRUE(AreEq(other.x, vec.x));
        EXPECT_TRUE(AreEq(other.y, vec.y));
        EXPECT_TRUE(AreEq(other.z, vec.z));
    }

    TEST(VectorTest, Addition)
    {
        auto a = lm::vec3(1.7, 2.8, 3.33);
        auto b = lm::vec3(4.2, -5, 6.0);
        auto c = lm::vec3(5.9, -2.2, 9.33);
        std::cout << (a + b) << std::endl;
        std::cout << c << std::endl;
        EXPECT_TRUE((a + b) == c);
    }
}
