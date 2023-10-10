/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_REMOVECV_HPP
#define ZLL_META_REMOVECV_HPP

namespace zll {
namespace meta {

// clang-format off
template <typename T> struct remove_const          { typedef T type; };
template <typename T> struct remove_const<const T> { typedef T type; };
// clang-format on

// clang-format off
template <typename T> struct remove_volatile             { typedef T type; };
template <typename T> struct remove_volatile<volatile T> { typedef T type; };
// clang-format on

// clang-format off
template<typename T> struct remove_cv                   { typedef T type; };
template<typename T> struct remove_cv<const T>          { typedef T type; };
template<typename T> struct remove_cv<volatile T>       { typedef T type; };
template<typename T> struct remove_cv<const volatile T> { typedef T type; };
// clang-format on

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TRAITS_ISSAME_HPP
