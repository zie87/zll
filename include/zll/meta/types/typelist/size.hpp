/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPELIST_SIZE_HPP
#define ZLL_META_TYPES_TYPELIST_SIZE_HPP

#include "zll/meta/integral_constant.hpp"

#include "zll/meta/types/size.hpp"
#include "zll/meta/types/typelist/nil_type.hpp"
#include "zll/meta/types/typelist/typelist.hpp"

#include "zll/cstdint.hpp"

namespace zll {
namespace meta {

namespace detail {

template <typename>
struct typelist_size_helper;

template <>
struct typelist_size_helper<nil_type> {
    static const zll::uint_fast32_t value = 0;
};

template <typename HEAD_T, typename TAIL_T>
struct typelist_size_helper<typelist<HEAD_T, TAIL_T> > {
    static const zll::uint_fast32_t value = 1 + typelist_size_helper<TAIL_T>::value;
};

}  // namespace detail

template <>
struct size<nil_type> : zll::meta::integral_constant<zll::uint_fast32_t, 0> {};

template <typename HEAD_T, typename TAIL_T>
struct size<typelist<HEAD_T, TAIL_T> >
    : zll::meta::integral_constant<zll::uint_fast32_t, detail::typelist_size_helper<typelist<HEAD_T, TAIL_T> >::value> {
};

template <>
struct empty<nil_type> : zll::meta::true_type {};

template <typename HEAD_T, typename TAIL_T>
struct empty<typelist<HEAD_T, TAIL_T> > : zll::meta::false_type {};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPELIST_HPP
