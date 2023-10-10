/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPELIST_AT_HPP
#define ZLL_META_TYPES_TYPELIST_AT_HPP

#include "zll/debug/static_assert.hpp"

#include "zll/meta/types/at.hpp"
#include "zll/meta/types/typelist/nil_type.hpp"
#include "zll/meta/types/typelist/size.hpp"
#include "zll/meta/types/typelist/typelist.hpp"

#include "zll/cstdint.hpp"

namespace zll {
namespace meta {

namespace detail {

template <typename, zll::uint_fast32_t>
struct typelist_at_helper;

template <typename HEAD_T, typename TAIL_T>
struct typelist_at_helper<typelist<HEAD_T, TAIL_T>, 0> {
    typedef HEAD_T type;
};

template <typename HEAD_T, typename TAIL_T, zll::uint_fast32_t INDEX_V>
struct typelist_at_helper<typelist<HEAD_T, TAIL_T>, INDEX_V> {
    typedef typename typelist_at_helper<TAIL_T, (INDEX_V - 1)>::type type;
};

}  // namespace detail

template <>
struct at<nil_type, 0> {
    typedef nil_type type;
};

template <typename HEAD_T, typename TAIL_T, zll::uint_fast32_t INDEX_V>
struct at<typelist<HEAD_T, TAIL_T>, INDEX_V> {
    // check if index is out of range
    ZLL_STATIC_ASSERT((INDEX_V < zll::meta::size<typelist<HEAD_T, TAIL_T> >::value));

    typedef typename detail::typelist_at_helper<typelist<HEAD_T, TAIL_T>, INDEX_V>::type type;
};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPELIST_AT_HPP
