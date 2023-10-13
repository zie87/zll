/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TRAITS_REMOVEREFERENCE_HPP
#define ZLL_META_TRAITS_REMOVEREFERENCE_HPP

#include "zll/meta/traits/remove_cv.hpp"

namespace zll {
namespace meta {
// clang-format off
template <typename T> struct remove_reference     { typedef T type; };
template <typename T> struct remove_reference<T&> { typedef T type; };
// clang-format on
template <typename T>
struct remove_cvref {
    typedef typename zll::meta::remove_cv<typename zll::meta::remove_reference<T>::type>::type type;
};
}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TRAITS_REMOVEREFERENCE_HPP
