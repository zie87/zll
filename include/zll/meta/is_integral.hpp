/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_ISINTEGRAL_HPP
#define ZLL_META_ISINTEGRAL_HPP

#include "zll/meta/integral_constant.hpp"

namespace zll {
namespace meta {

// clang-format off
template <typename T> struct is_integral : false_type {};
template <typename T> struct is_integral<const T>          : is_integral<T> {};
template <typename T> struct is_integral<volatile T>       : is_integral<T> {};
template <typename T> struct is_integral<const volatile T> : is_integral<T> {};
// clang-format on

// clang-format off
template <> struct is_integral<signed char> : true_type {};
template <> struct is_integral<short>       : true_type {};
template <> struct is_integral<int>         : true_type {};
template <> struct is_integral<long>        : true_type {};
// clang-format on

// clang-format off
template <> struct is_integral<unsigned char>  : true_type {};
template <> struct is_integral<unsigned short> : true_type {};
template <> struct is_integral<unsigned int>   : true_type {};
template <> struct is_integral<unsigned long>  : true_type {};
// clang-format on

// clang-format off
template <> struct is_integral<char> : true_type {};
template <> struct is_integral<bool> : true_type {};
// clang-format on

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_ISINTEGRAL_HPP
