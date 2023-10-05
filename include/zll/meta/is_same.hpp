#ifndef ZLL_META_ISSAME_HPP
#define ZLL_META_ISSAME_HPP

#include "zll/meta/integral_constant.hpp"

namespace zll {
namespace meta {

template <typename T, typename U>
struct is_same : false_type {};

template <typename T>
struct is_same<T, T> : true_type {};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_ISSAME_HPP
