#ifndef ZLL_META_TRAITS_ISFUNCTION_HPP
#define ZLL_META_TRAITS_ISFUNCTION_HPP

#include "zll/meta/integral_constant.hpp"
#include "zll/meta/traits/is_const.hpp"
#include "zll/meta/traits/is_reference.hpp"

namespace zll {
namespace meta {

namespace detail {

template <typename T>
struct is_function_helper {
    static const bool value = !(zll::meta::is_const<const T>::value) && !(zll::meta::is_reference<T>::value);
};

}  // namespace detail

template <typename T>
struct is_function : zll::meta::bool_constant<detail::is_function_helper<T>::value> {};

}  // namespace meta
}  // namespace zll

#endif  //  ZLL_META_TRAITS_ISFUNCTION_HPP
