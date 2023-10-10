/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPELIST_INDEXOF_HPP
#define ZLL_META_TYPES_TYPELIST_INDEXOF_HPP

#include "zll/debug/static_assert.hpp"

#include "zll/meta/types/index_of.hpp"
#include "zll/meta/types/typelist/nil_type.hpp"
#include "zll/meta/types/typelist/contains.hpp"
#include "zll/meta/types/typelist/typelist.hpp"

#include "zll/cstdint.hpp"

namespace zll {
namespace meta {

namespace detail {

template <typename, typename>
struct typelist_index_of_helper_impl;

template <typename T, typename TAIL_T>
struct typelist_index_of_helper_impl<typelist<T, TAIL_T>, T> {
    static const zll::uint_fast32_t value = 0;
};

template <typename HEAD_T, typename TAIL_T, typename T>
struct typelist_index_of_helper_impl<typelist<HEAD_T, TAIL_T>, T> {
    static const zll::uint_fast32_t value = 1 + typelist_index_of_helper_impl<TAIL_T, T>::value;
};

template <typename LIST_T, typename T>
struct typelist_index_of_helper {
    // check if type is in list
    ZLL_STATIC_ASSERT((zll::meta::contains<LIST_T, T>::value));
    static const zll::uint_fast32_t value = typelist_index_of_helper_impl<LIST_T, T>::value;
};

}  // namespace detail

template <typename HEAD_T, typename TAIL_T, typename T>
struct index_of<typelist<HEAD_T, TAIL_T>, T>
    : zll::meta::integral_constant<zll::uint_fast32_t,
                                   detail::typelist_index_of_helper<typelist<HEAD_T, TAIL_T>, T>::value> {};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPELIST_INDEXOF_HPP
