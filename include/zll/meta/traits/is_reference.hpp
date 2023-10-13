#ifndef ZLL_META_TRAITS_ISREFERENCE_HPP
#define ZLL_META_TRAITS_ISREFERENCE_HPP

#include "zll/meta/integral_constant.hpp"

namespace zll {
namespace meta {

// clang-format off
template <typename T> struct is_reference     : zll::meta::false_type {};
template <typename T> struct is_reference<T&> : zll::meta::true_type {};
// clang-format on

}  // namespace meta
}  // namespace zll

#endif  //  ZLL_META_TRAITS_ISREFERENCE_HPP
