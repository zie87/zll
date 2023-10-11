/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPEVECTOR_REPLACE_HPP
#define ZLL_META_TYPES_TYPEVECTOR_REPLACE_HPP

#include "zll/meta/types/replace.hpp"
#include "zll/meta/types/typevector/typevector.hpp"
#include "zll/meta/types/typevector/append.hpp"
#include "zll/meta/types/typevector/contains.hpp"
#include "zll/meta/types/typevector/index_of.hpp"
#include "zll/meta/types/typevector/push.hpp"
#include "zll/meta/types/typevector/size.hpp"

namespace zll {
namespace meta {

namespace detail {

template <bool, typename OUT_T, typename IN_T>
struct typevector_replace_selector {
    typedef IN_T type;
};

template <typename OUT_T, typename IN_T>
struct typevector_replace_selector<false, OUT_T, IN_T> {
    typedef OUT_T type;
};

template <typename VEC_T, typename OUT_T, typename IN_T, typename TARGET_VEC_T, zll::uint_fast32_t INDEX_V,
          zll::uint_fast32_t SIZE_V>
struct typevector_replace_helper_impl {
    typedef typename at<VEC_T, INDEX_V>::type current_type;
    static const bool same = zll::meta::is_same<current_type, OUT_T>::value;

    typedef typename typevector_replace_selector<same, current_type, IN_T>::type append_type;
    typedef typename push_back<TARGET_VEC_T, append_type>::type target_type;

    typedef typename typevector_replace_helper_impl<VEC_T, OUT_T, IN_T, target_type, (INDEX_V + 1), SIZE_V>::type type;
};

template <typename VEC_T, typename OUT_T, typename IN_T, typename TARGET_VEC_T, zll::uint_fast32_t INDEX_V>
struct typevector_replace_helper_impl<VEC_T, OUT_T, IN_T, TARGET_VEC_T, INDEX_V, INDEX_V> {
    typedef TARGET_VEC_T type;
};

template <typename VEC_T, typename OUT_T, typename IN_T, bool = contains<VEC_T, OUT_T>::value>
struct typevector_replace_helper {
    typedef typename typevector_replace_helper_impl<VEC_T, OUT_T, IN_T, typevector<>, 0, size<VEC_T>::value>::type type;
};

template <typename VEC_T, typename OUT_T, typename IN_T>
struct typevector_replace_helper<VEC_T, OUT_T, IN_T, false> {
    typedef VEC_T type;
};

template <typename VEC_T, typename IN_T, zll::uint_fast32_t INDEX_V>
struct typevector_replace_first_helper_impl {
    typedef typename zll::meta::detail::typevector_append_helper_impl<typevector<>, VEC_T, 0U, INDEX_V>::type head_type;
    typedef typename zll::meta::push_back<head_type, IN_T>::type temp_type;
    typedef typename zll::meta::detail::typevector_append_helper_impl<temp_type, VEC_T, (INDEX_V + 1),
                                                                      zll::meta::size<VEC_T>::value>::type type;
};

template <typename VEC_T, typename OUT_T, typename IN_T, bool = contains<VEC_T, OUT_T>::value>
struct typevector_replace_first_helper {
    static const zll::uint_fast32_t index = zll::meta::index_of<VEC_T, OUT_T>::value;
    typedef typename typevector_replace_first_helper_impl<VEC_T, IN_T, index>::type type;
};

template <typename VEC_T, typename OUT_T, typename IN_T>
struct typevector_replace_first_helper<VEC_T, OUT_T, IN_T, false> {
    typedef VEC_T type;
};

}  // namespace detail

template <typename T01, typename T02, typename T03, typename T04, typename T05, typename T06, typename T07,
          typename T08, typename T09, typename T10, typename T11, typename T12, typename T13, typename T14,
          typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename OUT_T,
          typename IN_T>
struct replace<
    typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20>,
    OUT_T, IN_T> {
    typedef typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19,
                       T20>
        vector_type;

    typedef typename detail::typevector_replace_helper<vector_type, OUT_T, IN_T>::type type;
};

template <typename T01, typename T02, typename T03, typename T04, typename T05, typename T06, typename T07,
          typename T08, typename T09, typename T10, typename T11, typename T12, typename T13, typename T14,
          typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename OUT_T,
          typename IN_T>
struct replace_first<
    typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20>,
    OUT_T, IN_T> {
    typedef typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19,
                       T20>
        vector_type;

    typedef typename detail::typevector_replace_first_helper<vector_type, OUT_T, IN_T>::type type;
};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPEVECTOR_REPLACE_HPP
