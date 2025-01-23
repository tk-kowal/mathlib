#include <numbers>
namespace tml
{
    constexpr float radians(const float degrees)
    {
        return degrees * (std::numbers::pi / 180.f);
    }

}