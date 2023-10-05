#ifndef ZLL_META_INTEGRALCONSTANT_HPP
#define ZLL_META_INTEGRALCONSTANT_HPP

namespace zll {
namespace meta {

template <typename T, T VALUE_V>
struct integral_constant {
    typedef T value_type;
    typedef integral_constant<T, VALUE_V> type;

    static const value_type value = VALUE_V;

    operator value_type() const { return VALUE_V; }
    value_type operator()() const { return VALUE_V; }
};

template <bool BOOL_V>
struct bool_constant : integral_constant<bool, BOOL_V> {};

typedef bool_constant<true> true_type;
typedef bool_constant<false> false_type;

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_INTEGRALCONSTANT_HPP
