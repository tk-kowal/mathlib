namespace lm
{

    template <typename T>
    constexpr vec<3, T> operator+(const vec<3, T> &a, const T scalar)
    {
        return vec<3, T>{a.x + scalar, a.y + scalar, a.z + scalar};
    }

    template <typename T>
    constexpr vec<3, T> operator+(const vec<3, T> &a, const vec<3, T> &b)
    {
        return vec<3, T>{a.x + b.x, a.y + b.y, a.z + b.z};
    }

    template <typename T>
    constexpr vec<3, T> operator-(const vec<3, T> &a, const T scalar)
    {
        return vec<3, T>{a.x - scalar, a.y - scalar, a.z - scalar};
    }

    template <typename T>
    constexpr vec<3, T> operator-(const vec<3, T> &a, const vec<3, T> &b)
    {
        return vec<3, T>{a.x - b.x, a.y - b.y, a.z - b.z};
    }

    template <typename T>
    constexpr vec<3, T> operator-(const vec<3, T> &a)
    {
        return vec<3, T>{-a.x, -a.y, -a.z};
    }

    template <typename T>
    constexpr vec<3, T> operator*(const vec<3, T> &a, const T scalar)
    {
        return vec<3, T>{a.x * scalar, a.y * scalar, a.z * scalar};
    }

    template <typename T>
    constexpr vec<3, T> operator*(const vec<3, T> &a, const vec<3, T> &b)
    {
        return vec<3, T>{a.x * b.x, a.y * b.y, a.z * b.z};
    }

    template <typename T>
    constexpr vec<3, T> operator/(const vec<3, T> &a, const T scalar)
    {
        return vec<3, T>{a.x / scalar, a.y / scalar, a.z / scalar};
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
    constexpr T vec<3, T>::operator[](const int i)
    {
        if (i < 0 || i > 2)
        {
            throw std::out_of_range("Atttempted to access vec3 at index: " + std::to_string(i));
        }

        switch (i)
        {
        default:
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        }
    }

    // Presentation
    template <typename T>
    constexpr std::ostream &operator<<(std::ostream &stream, const vec<3, T> &v)
    {
        return stream << "< " << v.x << ", " << v.y << ", " << v.z << " >";
    }

    template <typename T>
    constexpr T dot(const vec<3, T> &a, const vec<3, T> &b)
    {
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
    }

    template <typename T>
    constexpr T mag(const vec<3, T> &a)
    {
        return std::sqrt(dot(a, a));
    }
}