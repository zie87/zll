/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPELIST_CONTAINS_HPP
#define ZLL_META_TYPES_TYPELIST_CONTAINS_HPP

#include "zll/meta/integral_constant.hpp"

#include "zll/meta/types/contains.hpp"
#include "zll/meta/types/typelist/nil_type.hpp"
#include "zll/meta/types/typelist/typelist.hpp"

namespace zll {
namespace meta {

namespace detail {

template <typename, typename>
struct typelist_contains_helper;

template <typename T>
struct typelist_contains_helper<nil_type, T> {
    static const bool value = false;
};

template <typename TAIL_T, typename T>
struct typelist_contains_helper<typelist<T, TAIL_T>, T> {
    static const bool value = true;
};

template <typename HEAD_T, typename TAIL_T, typename T>
struct typelist_contains_helper<typelist<HEAD_T, TAIL_T>, T> {
    static const bool value = typelist_contains_helper<TAIL_T, T>::value;
};

}  // namespace detail

template <typename T>
struct contains<nil_type, T> : zll::meta::bool_constant<false> {};

template <typename HEAD_T, typename TAIL_T, typename T>
struct contains<typelist<HEAD_T, TAIL_T>, T>
    : zll::meta::bool_constant<detail::typelist_contains_helper<typelist<HEAD_T, TAIL_T>, T>::value> {};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPELIST_CONTAINS_HPP
