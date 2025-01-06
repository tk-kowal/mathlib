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

    // Component Access
    template <typename T>
    constexpr mat<4, 4, T>::row_type &mat<4, 4, T>::operator[](const int i)
    {
        return rows[i];
    }
}