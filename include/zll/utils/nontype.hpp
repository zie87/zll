/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

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
