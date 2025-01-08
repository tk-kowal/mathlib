#include "geometry/funcs.h"

#include <numbers>

#include "gtest/gtest.h"

#include "helpers/helpers.h"

namespace testing
{
    TEST(GeometryTest, DegreesToRadians)
    {
        EXPECT_TRUE(AreEq(1.57079, lm::radians(90)));
        EXPECT_TRUE(AreEq(std::numbers::pi, lm::radians(180)));
    }

}