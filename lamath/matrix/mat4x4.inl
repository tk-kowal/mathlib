namespace lm
{
    // Constructors

    template <typename T>
    constexpr mat<4, 4, T>::mat(T scalar)
    {
        rows[0] = vec<4, T>(scalar);
        rows[1] = vec<4, T>(scalar);
        rows[2] = vec<4, T>(scalar);
        rows[3] = vec<4, T>(scalar);
    };

    template <typename T>
    constexpr mat<4, 4, T>::mat(std::initializer_list<mat<4, 4, T>::row_type> r)
    {
        if (r.size() != 4)
        {
            throw std::invalid_argument("Attempted to construct mat4 with incompatible initializer list size.");
        }
        std::copy(r.begin(), r.end(), rows);
    };

    template <typename T>
    constexpr mat<4, 4, T> mat<4, 4, T>::identity()
    {
        return mat4{
            lm::vec4{1.0, 0, 0, 0},
            lm::vec4{0, 1.0, 0, 0},
            lm::vec4{0, 0, 1.0, 0},
            lm::vec4{0, 0, 0, 1.0},
        };
    }

    // Component Access
    template <typename T>
    constexpr mat<4, 4, T>::row_type &mat<4, 4, T>::operator[](const int i)
    {
        return rows[i];
    }

    template <typename T>
    constexpr const mat<4, 4, T>::row_type &mat<4, 4, T>::operator[](const int i) const
    {
        return rows[i];
    }

    // Binary Ops
    template <typename T>
    constexpr bool operator==(const mat<4, 4, T> &a, const mat<4, 4, T> &b)
    {
        return a[0] == b[0] &&
               a[1] == b[1] &&
               a[2] == b[2] &&
               a[3] == b[3];
    }
}