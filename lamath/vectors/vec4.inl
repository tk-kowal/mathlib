namespace lm
{
    // Component Access
    template <typename T>
    constexpr T vec<4, T>::operator[](const int i)
    {
        // How should I handle range checking here? throw an exception?
        switch (i)
        {
        default:
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        case 3:
            return w;
        }
    }

    // Scalar Ops
    template <typename T>
    constexpr vec<4, T> operator+(const vec<4, T> &a, const T scalar)
    {
        return vec<4, T>{a.x + scalar, a.y + scalar, a.z + scalar, a.w + scalar};
    }

    template <typename T>
    constexpr vec<4, T> operator-(const vec<4, T> &a, const T scalar)
    {
        return vec<4, T>{a.x - scalar, a.y - scalar, a.z - scalar, a.w - scalar};
    }

    template <typename T>
    constexpr vec<4, T> operator*(const vec<4, T> &a, const T scalar)
    {
        return vec<4, T>{a.x * scalar, a.y * scalar, a.z * scalar, a.w * scalar};
    }

    template <typename T>
    constexpr vec<4, T> operator/(const vec<4, T> &a, const T scalar)
    {
        return vec<4, T>{a.x / scalar, a.y / scalar, a.z / scalar, a.w / scalar};
    }

    // Vector Ops

    template <typename T>
    constexpr vec<4, T> operator+(const vec<4, T> &a, const vec<4, T> &b)
    {
        return vec<4, T>{
            a.x + b.x,
            a.y + b.y,
            a.z + b.z,
            a.w + b.w};
    }

    template <typename T>
    constexpr vec<4, T> operator-(const vec<4, T> &a, const vec<4, T> &b)
    {
        return vec<4, T>{
            a.x - b.x,
            a.y - b.y,
            a.z - b.z,
            a.w - b.w};
    }

    template <typename T>
    constexpr vec<4, T> operator*(const vec<4, T> &a, const vec<4, T> &b)
    {
        return vec<4, T>{
            a.x * b.x,
            a.y * b.y,
            a.z * b.z,
            a.w * b.w};
    }

    template <typename T>
    constexpr vec<4, T> operator/(const vec<4, T> &a, const vec<4, T> &b)
    {
        return vec<4, T>{
            a.x / b.x,
            a.y / b.y,
            a.z / b.z,
            a.w / b.w};
    }

    template <typename T>
    constexpr T dot(const vec<4, T> &a, const vec<4, T> &b)
    {
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
    }

    template <typename T>
    constexpr bool operator==(const vec<4, T> &a, const vec<4, T> &b)
    {
        return AreEq(a.x, b.x) && AreEq(a.y, b.y) && AreEq(a.z, b.z) && AreEq(a.w, b.w);
    }

    // Unary Ops
    template <typename T>
    constexpr T mag(const vec<4, T> &a)
    {
        return std::sqrt(dot(a, a));
    }

}