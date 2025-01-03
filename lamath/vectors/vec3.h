#pragma once
#include <iostream>
#include "scalars/scalar.h"

namespace lm
{
    template <int S, typename T>
    struct vec;

    template <typename T>
    struct vec<3, T>
    {
        typedef float value_type;
        typedef vec<3, T> type;

        union
        {
            T x, r, s;
        };
        union
        {
            T y, g, t;
        };
        union
        {
            T z, b, p;
        };

        vec() : x(0), y(0), z(0) {}
        vec(T scalar) : x(scalar), y(scalar), z(scalar) {}
        vec(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
        vec(const vec<3, T> &other) : x(other.x), y(other.y), z(other.z) {}
    };

    typedef vec<3, float> vec3;

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

}