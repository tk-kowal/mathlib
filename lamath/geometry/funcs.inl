#include <numbers>
namespace lm
{
    constexpr float radians(const float degrees)
    {
        return degrees * (std::numbers::pi / 180.f);
    }

}