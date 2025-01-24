namespace tml
{
    // Component Access
    template <typename T>
    constexpr T &vec<4, T>::operator[](const int i)
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

    // Component Access
    template <typename T>
    constexpr const T &vec<4, T>::operator[](const int i) const
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

    // Operators
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
    constexpr vec<4, T> operator-(const vec<4, T> &a)
    {
        return vec<4, T>{-a.x, -a.y, -a.z, -a.w};
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
    constexpr bool operator==(const vec<4, T> &a, const vec<4, T> &b)
    {
        return AreEq(a.x, b.x) && AreEq(a.y, b.y) && AreEq(a.z, b.z) && AreEq(a.w, b.w);
    }

    // Presentation
    template <typename T>
    constexpr std::ostream &operator<<(std::ostream &stream, const vec<4, T> &v)
    {
        return stream << "< " << v.x << ", " << v.y << ", " << v.z << ", " << v.w << " >";
    }

    template <typename T>
    constexpr T dot(const vec<4, T> &a, const vec<4, T> &b)
    {
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
    }

    template <typename T>
    constexpr T mag(const vec<4, T> &a)
    {
        return std::sqrt(dot(a, a));
    }
}