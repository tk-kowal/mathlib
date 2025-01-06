#include "vectors/vec.h"

#include <gtest/gtest.h>

#include "helpers.h"

namespace testing
{
    TEST(Vec4Test, DefaultsXYZW)
    {
        auto a = lm::vec4();
        EXPECT_TRUE(AreEq(0, a.x));
        EXPECT_TRUE(AreEq(0, a.y));
        EXPECT_TRUE(AreEq(0, a.z));
        EXPECT_TRUE(AreEq(0, a.w));
    }

    TEST(Vec4Test, DefaultsRGBA)
    {
        auto a = lm::vec4();
        EXPECT_TRUE(AreEq(0, a.r));
        EXPECT_TRUE(AreEq(0, a.g));
        EXPECT_TRUE(AreEq(0, a.b));
        EXPECT_TRUE(AreEq(0, a.a));
    }

    TEST(Vec4Test, Initialization)
    {
        auto vec = lm::vec4{1.5, 2, -3.7, 9};
        EXPECT_TRUE(AreEq(1.5, vec.x));
        EXPECT_TRUE(AreEq(2.0, vec.y));
        EXPECT_TRUE(AreEq(-3.7, vec.z));
        EXPECT_TRUE(AreEq(9, vec.w));
    }

    TEST(Vec4Test, InitializeWithScalar)
    {
        auto vec = lm::vec4(3.7f);
        EXPECT_TRUE(AreEq(3.7, vec.x));
        EXPECT_TRUE(AreEq(3.7, vec.y));
        EXPECT_TRUE(AreEq(3.7, vec.z));
        EXPECT_TRUE(AreEq(3.7, vec.w));
    }

    TEST(Vec4Test, InitializeWithOther)
    {
        auto other = lm::vec4{0.07, -1.29, 3.99, -20};
        auto vec = lm::vec4(other);
        EXPECT_TRUE(AreEq(other.x, vec.x));
        EXPECT_TRUE(AreEq(other.y, vec.y));
        EXPECT_TRUE(AreEq(other.z, vec.z));
        EXPECT_TRUE(AreEq(other.w, vec.w));
    }

    TEST(Vec4Test, AddScalar)
    {
        auto a = lm::vec4(1.7, 2.8, 3.33, -20);
        auto b = 2.25f;
        auto c = lm::vec4(3.95, 5.05, 5.58, -17.75);
        EXPECT_TRUE((a + b) == c);
    }

    TEST(Vec4Test, SubtractScalar)
    {
        auto a = lm::vec4(1.7, 2.8, 3.33, -19);
        auto b = 1.0f;
        auto c = lm::vec4(0.7, 1.8, 2.33, -20);
        EXPECT_TRUE((a - b) == c);
    }

    TEST(Vec4Test, MultiplyScalar)
    {
        auto a = lm::vec4(1.7, 2.8, 3.33, -4);
        auto b = 2.0f;
        auto c = lm::vec4(3.4, 5.6, 6.66, -8);
        EXPECT_TRUE((a * b) == c);
    }

    TEST(Vec4Test, DivideScalar)
    {
        auto a = lm::vec4(2.5, 5.0, -10, -15);
        auto b = 2.0f;
        auto c = lm::vec4(1.25, 2.5, -5, -7.5);
        EXPECT_TRUE((a / b) == c);
    }

    TEST(Vec4Test, AddVector)
    {
        auto a = lm::vec4(1.7, 2.8, 3.33, 123);
        auto b = lm::vec4(4.2, -5, 6.0, 1.5);
        auto c = lm::vec4(5.9, -2.2, 9.33, 124.5);
        EXPECT_TRUE((a + b) == c);
    }

    TEST(Vec4Test, SubtractVector)
    {
        auto a = lm::vec4(1.07, 5, -4.5, 100);
        auto b = lm::vec4(1);
        auto c = lm::vec4(0.07, 4, -5.5, 99);
        EXPECT_TRUE((a - b) == c);
    }

    TEST(Vec4Test, MultiplyVector)
    {
        auto a = lm::vec4(1.07, 5, -4.5, 17);
        auto b = lm::vec4(-2);
        auto c = lm::vec4(-2.14, -10, 9, -34);
        EXPECT_TRUE((a * b) == c);
    }

    TEST(Vec4Test, DivideVector)
    {
        auto a = lm::vec4(10, 5, -8, 22);
        auto b = lm::vec4(2);
        auto c = lm::vec4(5, 2.5, -4, 11);
        EXPECT_TRUE((a / b) == c);
    }

    TEST(Vec4Test, DotProduct)
    {
        auto a = lm::vec4(1, 2, 3, 4);
        auto b = lm::vec4(5, 6, 7, 8);
        EXPECT_TRUE(AreEq(70, lm::dot(a, b)));
    }

    TEST(Vec4Test, MagnitudeDefault)
    {
        auto a = lm::vec4(0, 0, 0, 0);
        EXPECT_EQ(0, lm::mag(a));
    }

    TEST(Vec4Test, MagnitudeUnit)
    {
        auto a = lm::vec4(1, 1, 1, 1);
        EXPECT_TRUE(AreEq(std::sqrt(4), lm::mag(a)));
    }

    TEST(Vec4Test, ComponentAccess)
    {
        auto a = lm::vec4(1, 2, 3, 4);
        EXPECT_EQ(1, a[0]);
        EXPECT_EQ(2, a[1]);
        EXPECT_EQ(3, a[2]);
        EXPECT_EQ(4, a[3]);
    }

    TEST(Vec4Test, Equality)
    {
        auto a = lm::vec4(1, 2, 3, 4);
        auto b = lm::vec4(1, 2, 3, 4);
        EXPECT_EQ(a, b);
    }

    TEST(Vec4Test, Inequality)
    {
        auto a = lm::vec4(1, 2, 3, 4);
        auto b = lm::vec4(4, 3, 2, 1);
        EXPECT_NE(a, b);
    }

    TEST(Vec4Test, Negation)
    {
        auto a = lm::vec4(1, 2, 3, 4);
        auto b = lm::vec4(-1, -2, -3, -4);
        EXPECT_EQ(b, -a);
    }

    TEST(Vec4Test, Normalize)
    {
        auto a = lm::vec4(1, 2, 3, 4);
        auto e = lm::vec4(0.18257, 0.36515, 0.54772, 0.73030);
        EXPECT_EQ(e, normalize(a));
    }
}