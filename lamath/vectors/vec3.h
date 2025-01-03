#pragma once
#include <iostream>
#include "scalars/scalar.h"

namespace lm
{
    template <int S, typename T>
    struct vec;

    typedef vec<3, float> vec3;

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

    // Scalar Ops
    template <typename T>
    constexpr vec<3, T> operator+(const vec<3, T> &a, const T scalar);

    template <typename T>
    constexpr vec<3, T> operator-(const vec<3, T> &a, const T scalar);

    template <typename T>
    constexpr vec<3, T> operator*(const vec<3, T> &a, const T scalar);

    template <typename T>
    constexpr vec<3, T> operator/(const vec<3, T> &a, const T scalar);

    // Vector Ops
    template <typename T>
    constexpr vec<3, T> operator+(const vec<3, T> &a, const vec<3, T> &b);

    template <typename T>
    constexpr vec<3, T> operator-(const vec<3, T> &a, const vec<3, T> &b);

    template <typename T>
    constexpr vec<3, T> operator*(const vec<3, T> &a, const vec<3, T> &b);

    template <typename T>
    constexpr vec<3, T> operator/(const vec<3, T> &a, const vec<3, T> &b);

    template <typename T>
    constexpr bool operator==(const vec<3, T> &a, const vec<3, T> &b);

    template <typename T>
    constexpr std::ostream &operator<<(std::ostream &stream, const vec<3, T> &v);

    template <typename T>
    constexpr float dot(const vec<3, T> &a, const vec<3, T> &b);

    template <typename T>
    constexpr float mag(const vec<3, T> &a);

}

#ifndef LM_TEST
#include "vec3.inl"
#endif // LM_TEST