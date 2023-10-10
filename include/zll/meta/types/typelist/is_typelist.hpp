/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPELIST_ISTYPELIST_HPP
#define ZLL_META_TYPES_TYPELIST_ISTYPELIST_HPP

#include "zll/meta/integral_constant.hpp"
#include "zll/meta/types/typelist/nil_type.hpp"
#include "zll/meta/types/typelist/typelist.hpp"

namespace zll {
namespace meta {

template <typename>
struct is_typelist : zll::meta::false_type {};

template <typename HEAD_T, typename TAIL_T>
struct is_typelist<typelist<HEAD_T, TAIL_T> > : zll::meta::true_type {};

template <>
struct is_typelist<nil_type> : zll::meta::true_type {};
}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPELIST_ISTYPELIST_HPP
