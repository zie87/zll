#ifndef ZLL_FUNCTIONAL_DETAIL_FNTYPES_HPP
#define ZLL_FUNCTIONAL_DETAIL_FNTYPES_HPP

namespace zll {
namespace detail {
// clang-format off
template <typename> struct fn_types;

template <typename R> struct fn_types<R()> { typedef R type(); };
template <typename R> struct fn_types<R() const> { typedef R type(); };

template <typename R, typename T> struct fn_types<R(T)> { typedef R type(T); };
template <typename R, typename T> struct fn_types<R(T) const> { typedef R type(T); };
// clang-format on
}  // namespace detail
}  // namespace zll

#endif  // ZLL_FUNCTIONAL_DETAIL_FNTYPES_HPP
