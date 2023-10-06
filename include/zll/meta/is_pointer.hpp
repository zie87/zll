#ifndef ZLL_META_ISPOINTER_HPP
#define ZLL_META_ISPOINTER_HPP

#include "zll/meta/integral_constant.hpp"

namespace zll {
namespace meta {

// clang-format off
template<typename T> struct is_pointer : false_type {};
template<typename T> struct is_pointer<T*>                : true_type {};
template<typename T> struct is_pointer<T* const>          : true_type {};
template<typename T> struct is_pointer<T* volatile>       : true_type {};
template<typename T> struct is_pointer<T* const volatile> : true_type {};
// clang-format on

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_ISPOINTER_HPP
