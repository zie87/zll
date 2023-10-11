/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPEVECTOR_INDEXOF_HPP
#define ZLL_META_TYPES_TYPEVECTOR_INDEXOF_HPP

#include "zll/debug/static_assert.hpp"

#include "zll/meta/types/index_of.hpp"
#include "zll/meta/types/typevector/contains.hpp"
#include "zll/meta/types/typevector/typevector.hpp"

#include "zll/cstdint.hpp"

namespace zll {
namespace meta {

namespace detail {

template <typename VEC_T, typename T, zll::uint_fast32_t INDEX_V, zll::uint_fast32_t SIZE_V,
          bool = zll::meta::is_same<typename at<VEC_T, INDEX_V>::type, T>::value>
struct typevector_index_of_helper_impl {
    static const zll::uint_fast32_t value = typevector_index_of_helper_impl<VEC_T, T, (INDEX_V + 1), SIZE_V>::value;
};

template <typename VEC_T, typename T, zll::uint_fast32_t INDEX_V, zll::uint_fast32_t SIZE_V>
struct typevector_index_of_helper_impl<VEC_T, T, INDEX_V, SIZE_V, true> {
    static const zll::uint_fast32_t value = INDEX_V;
};

template <typename VEC_T, typename T>
struct typevector_index_of_helper {
    // check if type is in list
    ZLL_STATIC_ASSERT((zll::meta::contains<VEC_T, T>::value));
    static const zll::uint_fast32_t value = typevector_index_of_helper_impl<VEC_T, T, 0, size<VEC_T>::value>::value;
};

}  // namespace detail

template <typename T01, typename T02, typename T03, typename T04, typename T05, typename T06, typename T07,
          typename T08, typename T09, typename T10, typename T11, typename T12, typename T13, typename T14,
          typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename SEARCH_T>
struct index_of<
    typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20>,
    SEARCH_T>
    : zll::meta::integral_constant<zll::uint_fast32_t, detail::typevector_index_of_helper<
                                                           typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10,
                                                                      T11, T12, T13, T14, T15, T16, T17, T18, T19, T20>,
                                                           SEARCH_T>::value> {};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPEVECTOR_INDEXOF_HPP
