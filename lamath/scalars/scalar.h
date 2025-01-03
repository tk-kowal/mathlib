#pragma once
#include <cmath>

namespace lm
{

    static const float kEpsilon = 0.0001;

    bool AreEq(float a, float b, float epsilon = kEpsilon)
    {
        return std::fabs(a - b) < epsilon;
    }
}