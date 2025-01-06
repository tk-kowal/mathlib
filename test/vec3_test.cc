#include "vectors/vec3.h"

#include <iostream>

#include <gtest/gtest.h>

#include "helpers.h"

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

    TEST(VectorTest, AddScalar)
    {
        auto a = lm::vec3(1.7, 2.8, 3.33);
        auto b = 2.25f;
        auto c = lm::vec3(3.95, 5.05, 5.58);
        EXPECT_TRUE((a + b) == c);
    }

    TEST(VectorTest, SubtractScalar)
    {
        auto a = lm::vec3(1.7, 2.8, 3.33);
        auto b = 1.0f;
        auto c = lm::vec3(0.7, 1.8, 2.33);
        EXPECT_TRUE((a - b) == c);
    }

    TEST(VectorTest, MultiplyScalar)
    {
        auto a = lm::vec3(1.7, 2.8, 3.33);
        auto b = 2.0f;
        auto c = lm::vec3(3.4, 5.6, 6.66);
        EXPECT_TRUE((a * b) == c);
    }

    TEST(VectorTest, DivideScalar)
    {
        auto a = lm::vec3(2.5, 5.0, -10);
        auto b = 2.0f;
        auto c = lm::vec3(1.25, 2.5, -5);
        EXPECT_TRUE((a / b) == c);
    }

    TEST(VectorTest, AddVector)
    {
        auto a = lm::vec3(1.7, 2.8, 3.33);
        auto b = lm::vec3(4.2, -5, 6.0);
        auto c = lm::vec3(5.9, -2.2, 9.33);
        EXPECT_TRUE((a + b) == c);
    }

    TEST(VectorTest, SubtractVector)
    {
        auto a = lm::vec3(1.07, 5, -4.5);
        auto b = lm::vec3(1);
        auto c = lm::vec3(0.07, 4, -5.5);
        EXPECT_TRUE((a - b) == c);
    }

    TEST(VectorTest, MultiplyVector)
    {
        auto a = lm::vec3(1.07, 5, -4.5);
        auto b = lm::vec3(-2);
        auto c = lm::vec3(-2.14, -10, 9);
        EXPECT_TRUE((a * b) == c);
    }

    TEST(VectorTest, DivideVector)
    {
        auto a = lm::vec3(10, 5, -8);
        auto b = lm::vec3(2);
        auto c = lm::vec3(5, 2.5, -4);
        EXPECT_TRUE((a / b) == c);
    }

    TEST(VectorTest, DotProduct)
    {
        auto a = lm::vec3(1, 2, 3);
        auto b = lm::vec3(4, 5, 6);
        EXPECT_TRUE(AreEq(32, lm::dot(a, b)));
    }

    TEST(VectorTest, MagnitudeDefault)
    {
        auto a = lm::vec3(0, 0, 0);
        EXPECT_EQ(0, lm::mag(a));
    }

    TEST(VectorTest, MagnitudeUnit)
    {
        auto a = lm::vec3(1, 1, 0);
        EXPECT_TRUE(AreEq(std::sqrt(2), lm::mag(a)));
    }
}
