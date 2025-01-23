#pragma once
#include <cmath>

namespace tml
{

    static const float kEpsilon = 0.0001;

    constexpr bool AreEq(float a, float b, float epsilon = kEpsilon)
    {
        return std::fabs(a - b) < epsilon;
    }
}