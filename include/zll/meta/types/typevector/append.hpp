/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPEVECTOR_APPEND_HPP
#define ZLL_META_TYPES_TYPEVECTOR_APPEND_HPP

#include "zll/meta/types/append.hpp"
#include "zll/meta/types/typevector/typevector.hpp"
#include "zll/meta/types/typevector/is_typevector.hpp"
#include "zll/meta/types/typevector/at.hpp"
#include "zll/meta/types/typevector/push.hpp"
#include "zll/meta/types/typevector/size.hpp"

namespace zll {
namespace meta {

namespace detail {

template <typename VEC_T, typename APPEND_T, zll::uint_fast32_t INDEX_V, zll::uint_fast32_t SIZE_V>
struct typevector_append_helper_impl {
    typedef typename push_back<VEC_T, typename at<APPEND_T, INDEX_V>::type>::type temp_type;
    typedef typename typevector_append_helper_impl<temp_type, APPEND_T, (INDEX_V + 1), SIZE_V>::type type;
};

template <typename VEC_T, typename APPEND_T, zll::uint_fast32_t INDEX_V>
struct typevector_append_helper_impl<VEC_T, APPEND_T, INDEX_V, INDEX_V> {
    typedef VEC_T type;
};

template <typename VEC_T, typename APPEND_T, bool = is_typevector<APPEND_T>::value>
struct typevector_append_helper {
    typedef typename push_back<VEC_T, APPEND_T>::type type;
};

template <typename VEC_T, typename APPEND_T>
struct typevector_append_helper<VEC_T, APPEND_T, true> {
    static const zll::uint_fast32_t new_size = zll::meta::size<VEC_T>::value + zll::meta::size<APPEND_T>::value;
    ZLL_STATIC_ASSERT((new_size <= 20));  // only 20 elements are support
    typedef typename typevector_append_helper_impl<VEC_T, APPEND_T, 0, size<APPEND_T>::value>::type type;
};

}  // namespace detail

template <typename HEAD_T, typename TAIL_T, typename T>
struct append<typevector<HEAD_T, TAIL_T>, T> {
    typedef typename detail::typevector_append_helper<typevector<HEAD_T, TAIL_T>, T>::type type;
};

template <typename T01, typename T02, typename T03, typename T04, typename T05, typename T06, typename T07,
          typename T08, typename T09, typename T10, typename T11, typename T12, typename T13, typename T14,
          typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename APPEND_T>
struct append<
    typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20>,
    APPEND_T> {
    typedef typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19,
                       T20>
        vector_type;

    typedef typename detail::typevector_append_helper<vector_type, APPEND_T>::type type;
};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPEVECTOR_APPEND_HPP
