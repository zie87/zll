/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPEVECTOR_ISTYPEVECTOR_HPP
#define ZLL_META_TYPES_TYPEVECTOR_ISTYPEVECTOR_HPP

#include "zll/meta/integral_constant.hpp"

#include "zll/meta/types/typevector/typevector.hpp"

namespace zll {
namespace meta {

template <typename>
struct is_typevector : zll::meta::false_type {};

// clang-format off
template <typename T01, typename T02, typename T03, typename T04, typename T05, typename T06, typename T07,
          typename T08, typename T09, typename T10, typename T11, typename T12, typename T13, typename T14,
          typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>
struct is_typevector< typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, 
                                 T11, T12, T13, T14, T15, T16, T17, T18, T19, T20> >
    : zll::meta::true_type {};
// clang-format on

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPEVECTOR_ISTYPEVECTOR_HPP
