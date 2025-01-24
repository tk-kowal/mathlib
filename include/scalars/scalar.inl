#include <cmath>

namespace tml
{
    constexpr bool AreEq(float a, float b, float epsilon)
    {
        return std::fabs(a - b) < epsilon;
    }
}