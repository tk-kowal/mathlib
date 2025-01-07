#include "helpers.h"

#include <cmath>

#include <gtest/gtest.h>

#include "scalars/scalar.h"

namespace testing
{
    AssertionResult AreEq(float a, float b, float epsilon)
    {
        if (std::abs(a - b) < epsilon)
        {
            return AssertionSuccess();
        }
        else
        {
            return AssertionFailure() << a << " and " << b << " are not equal.";
        }
    }
}