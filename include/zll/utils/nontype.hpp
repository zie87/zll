#ifndef ZLL_UTILS_NONTYPE_HPP
#define ZLL_UTILS_NONTYPE_HPP

#include "zll/meta/integral_constant.hpp"

namespace zll {

template <typename T, T VALUE>
struct nontype_t {};

template <typename T>
struct is_nontype : zll::meta::false_type {};

template <typename T, T VALUE>
struct is_nontype<nontype_t<T, VALUE> > : zll::meta::true_type {};
}  // namespace zll

#endif  //  ZLL_UTILS_NONTYPE_HPP
