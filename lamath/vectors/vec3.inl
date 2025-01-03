#include <cmath>

namespace lm
{

    // Scalar Ops
    template <typename T>
    constexpr vec<3, T> operator+(const vec<3, T> &a, const T scalar)
    {
        return vec<3, T>{a.x + scalar, a.y + scalar, a.z + scalar};
    }

    template <typename T>
    constexpr vec<3, T> operator-(const vec<3, T> &a, const T scalar)
    {
        return vec<3, T>{a.x - scalar, a.y - scalar, a.z - scalar};
    }

    template <typename T>
    constexpr vec<3, T> operator*(const vec<3, T> &a, const T scalar)
    {
        return vec<3, T>{a.x * scalar, a.y * scalar, a.z * scalar};
    }

    template <typename T>
    constexpr vec<3, T> operator/(const vec<3, T> &a, const T scalar)
    {
        return vec<3, T>{a.x / scalar, a.y / scalar, a.z / scalar};
    }

    // Vector Ops
    template <typename T>
    constexpr vec<3, T> operator+(const vec<3, T> &a, const vec<3, T> &b)
    {
        return vec<3, T>{a.x + b.x, a.y + b.y, a.z + b.z};
    }

    template <typename T>
    constexpr vec<3, T> operator-(const vec<3, T> &a, const vec<3, T> &b)
    {
        return vec<3, T>{a.x - b.x, a.y - b.y, a.z - b.z};
    }

    template <typename T>
    constexpr vec<3, T> operator*(const vec<3, T> &a, const vec<3, T> &b)
    {
        return vec<3, T>{a.x * b.x, a.y * b.y, a.z * b.z};
    }

    template <typename T>
    constexpr vec<3, T> operator/(const vec<3, T> &a, const vec<3, T> &b)
    {
        return vec<3, T>{a.x / b.x, a.y / b.y, a.z / b.z};
    }

    template <typename T>
    constexpr bool operator==(const vec<3, T> &a, const vec<3, T> &b)
    {
        return AreEq(a.x, b.x) && AreEq(a.y, b.y) && AreEq(a.z, b.z);
    }

    template <typename T>
    constexpr std::ostream &operator<<(std::ostream &stream, const vec<3, T> &v)
    {
        return stream << "< " << v.x << ", " << v.y << ", " << v.z << " >";
    }

    template <typename T>
    constexpr float dot(const vec<3, T> &a, const vec<3, T> &b)
    {
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
    }

    template <typename T>
    constexpr float mag(const vec<3, T> &a)
    {
        return std::sqrt(dot(a, a));
    }
}