#include <cmath>
#include <gtest/gtest.h>
#include "scalars/scalar.h"

namespace testing
{
    AssertionResult AreEq(float a, float b, float epsilon = 0.0001)
    {
        if (std::abs(a - b) < epsilon)
        {
            return testing::AssertionSuccess();
        }
        else
        {
            return testing::AssertionFailure() << a << " and " << b << " are not equal.";
        }
    }
}