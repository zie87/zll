/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPEVECTOR_CONTAINS_HPP
#define ZLL_META_TYPES_TYPEVECTOR_CONTAINS_HPP

#include "zll/meta/integral_constant.hpp"

#include "zll/meta/types/contains.hpp"
#include "zll/meta/types/typevector/typevector.hpp"
#include "zll/meta/types/typevector/at.hpp"
#include "zll/meta/types/typevector/size.hpp"

#include "zll/meta/traits/is_same.hpp"

namespace zll {
namespace meta {

namespace detail {

template <typename VEC_T, typename T, zll::uint_fast32_t INDEX_V, zll::uint_fast32_t SIZE_V>
struct typevector_contains_helper_impl {
    static const bool same = zll::meta::is_same<typename at<VEC_T, INDEX_V>::type, T>::value;
    static const bool value = same ? true : typevector_contains_helper_impl<VEC_T, T, (INDEX_V + 1), SIZE_V>::value;
};

template <typename VEC_T, typename T, zll::uint_fast32_t INDEX_V>
struct typevector_contains_helper_impl<VEC_T, T, INDEX_V, INDEX_V> {
    static const bool value = false;
};

template <typename VEC_T, typename T>
struct typevector_contains_helper {
    static const bool value = typevector_contains_helper_impl<VEC_T, T, 0, size<VEC_T>::value>::value;
};

}  // namespace detail

template <typename T01, typename T02, typename T03, typename T04, typename T05, typename T06, typename T07,
          typename T08, typename T09, typename T10, typename T11, typename T12, typename T13, typename T14,
          typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename SEARCH_T>
struct contains<
    typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20>,
    SEARCH_T>
    : zll::meta::bool_constant<
          detail::typevector_contains_helper<typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13,
                                                        T14, T15, T16, T17, T18, T19, T20>,
                                             SEARCH_T>::value> {};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPEVECTOR_CONTAINS_HPP
