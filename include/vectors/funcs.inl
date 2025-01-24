namespace tml
{
    template <int S, typename T>
    constexpr vec<S, T> normalize(const vec<S, T> &v)
    {
        return v / mag(v);
    }
}