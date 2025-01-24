#pragma once

namespace tml
{
    static const float kEpsilon = 0.0001;

    constexpr bool AreEq(float a, float b, float epsilon = kEpsilon);
}

#include "scalar.inl"