/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_CONVERSION_HPP
#define ZLL_META_TYPES_CONVERSION_HPP

#include "zll/debug/static_assert.hpp"

#include "zll/meta/types/typelist.hpp"
#include "zll/meta/types/typevector.hpp"

#include "zll/cstdint.hpp"

namespace zll {
namespace meta {

namespace detail {

template <typename VEC_T, zll::uint_fast32_t INDEX_V, zll::uint_fast32_t SIZE_V>
struct to_typelist_helper {
    typedef typename at<VEC_T, INDEX_V>::type current_type;
    typedef typelist<current_type, typename to_typelist_helper<VEC_T, (INDEX_V + 1), SIZE_V>::type> type;
};

template <typename VEC_T, zll::uint_fast32_t INDEX_V>
struct to_typelist_helper<VEC_T, INDEX_V, INDEX_V> {
    typedef zll::meta::nil_type type;
};
}  // namespace detail

template <typename>
struct to_typelist;

template <typename T01, typename T02, typename T03, typename T04, typename T05, typename T06, typename T07,
          typename T08, typename T09, typename T10, typename T11, typename T12, typename T13, typename T14,
          typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>
struct to_typelist<
    typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20> > {
    typedef typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19,
                       T20>
        vector_type;
    typedef typename detail::to_typelist_helper<vector_type, 0, zll::meta::size<vector_type>::value>::type type;
};

}  // namespace meta
}  // namespace zll

namespace zll {
namespace meta {

namespace detail {

template <typename>
struct to_typevector_helper;

template <typename HEAD_T, typename TAIL_T>
struct to_typevector_helper<typelist<HEAD_T, TAIL_T> > {
    typedef typevector<HEAD_T> vector_type;
    typedef typename append<vector_type, typename to_typevector_helper<TAIL_T>::type>::type type;
};

template <>
struct to_typevector_helper<zll::meta::nil_type> {
    typedef zll::meta::empty_type type;
};
}  // namespace detail

template <typename>
struct to_typevector;

template <typename HEAD_T, typename TAIL_T>
struct to_typevector<typelist<HEAD_T, TAIL_T> > {
    typedef typelist<HEAD_T, TAIL_T> list_type;
    static const zll::uint_fast32_t size = zll::meta::size<list_type>::value;
    ZLL_STATIC_ASSERT( size <= 20 );

    typedef typename detail::to_typevector_helper<list_type>::type type;
};

template <>
struct to_typevector<zll::meta::nil_type> {
    typedef typevector<> type;
};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_CONVERSION_HPP
