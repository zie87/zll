/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TRAITS_ISCONST_HPP
#define ZLL_META_TRAITS_ISCONST_HPP

#include "zll/meta/integral_constant.hpp"

namespace zll {
namespace meta {

template <typename T>
struct is_const : zll::meta::false_type {};

template <typename T>
struct is_const<const T> : zll::meta::true_type {};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TRAITS_ISCONST_HPP
