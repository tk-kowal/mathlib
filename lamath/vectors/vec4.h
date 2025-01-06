#pragma once
#include <cassert>

#include "detail/base_types.h"
#include "scalars/scalar.h"

namespace lm
{
    typedef vec<4, float> vec4;

    template <typename T>
    struct vec<4, T>
    {
        typedef float value_type;
        typedef vec<4, T> type;

        union
        {
            T x, r;
        };
        union
        {
            T y, g;
        };
        union
        {
            T z, b;
        };
        union
        {
            T w, a;
        };

        constexpr vec() = default;
        constexpr vec(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w) {}
        constexpr vec(T scalar) : x(scalar), y(scalar), z(scalar), w(scalar) {}
        constexpr vec(const vec<4, T> &other) : x(other.x), y(other.y), z(other.z), w(other.w) {}

        // Component Access
        constexpr T operator[](const int i);
    };

    // Scalar Ops
    template <typename T>
    constexpr vec<4, T> operator+(const vec<4, T> &a, const T scalar);

    template <typename T>
    constexpr vec<4, T> operator-(const vec<4, T> &a, const T scalar);

    template <typename T>
    constexpr vec<4, T> operator*(const vec<4, T> &a, const T scalar);

    template <typename T>
    constexpr vec<4, T> operator/(const vec<4, T> &a, const T scalar);

    // Vector Ops

    template <typename T>
    constexpr vec<4, T> operator+(const vec<4, T> &a, const vec<4, T> &b);

    template <typename T>
    constexpr vec<4, T> operator-(const vec<4, T> &a, const vec<4, T> &b);

    template <typename T>
    constexpr T dot(const vec<4, T> &a, const vec<4, T> &b);

    // Unary Ops

    template <typename T>
    constexpr T mag(const vec<4, T> &a);

    template <typename T>
    constexpr bool operator==(const vec<4, T> &a, const vec<4, T> &b);

    template <typename T>
    constexpr vec<4, T> operator-(const vec<4, T> &a);
}

#include "vec4.inl"