/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_ISFLOATINGPOINT_HPP
#define ZLL_META_ISFLOATINGPOINT_HPP

#include "zll/meta/integral_constant.hpp"

namespace zll {
namespace meta {

// clang-format off
template <typename T> struct is_floating_point : false_type {};
template <typename T> struct is_floating_point<const T>          : is_floating_point<T> {};
template <typename T> struct is_floating_point<volatile T>       : is_floating_point<T> {};
template <typename T> struct is_floating_point<const volatile T> : is_floating_point<T> {};
// clang-format on

// clang-format off
template <> struct is_floating_point<float>  : true_type {};
template <> struct is_floating_point<double> : true_type {};
// clang-format on

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_ISFLOATINGPOINT_HPP
