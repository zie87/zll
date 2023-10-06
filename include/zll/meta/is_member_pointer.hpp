/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_ISMEMBERPOINTER_HPP
#define ZLL_META_ISMEMBERPOINTER_HPP

#include "zll/meta/integral_constant.hpp"
#include "zll/meta/remove_cv.hpp"

namespace zll {
namespace meta {

namespace detail {

template <typename>
struct is_member_pointer_helper : false_type {};

template <typename T, typename U>
struct is_member_pointer_helper<T U::*> : true_type {};

}  // namespace detail

template <typename T>
struct is_member_pointer : detail::is_member_pointer_helper<typename remove_cv<T>::type> {};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_ISMEMBERPOINTER_HPP
