#include "geometry/funcs.h"

#include <numbers>

#include "gtest/gtest.h"

namespace testing
{
    TEST(GeometryTest, DegreesToRadians)
    {
        EXPECT_EQ(1.57079, lm::radians(90));
        EXPECT_EQ(std::numbers::pi, lm::radians(180));
    }

}