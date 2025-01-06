namespace lm
{
    template <typename T>
    constexpr mat<4, 4, T>::mat(T scalar)
    {
        rows[0] = vec<4, T>(scalar);
        rows[1] = vec<4, T>(scalar);
        rows[2] = vec<4, T>(scalar);
        rows[3] = vec<4, T>(scalar);
    };
}