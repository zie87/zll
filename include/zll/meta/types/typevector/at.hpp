/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPEVECTOR_AT_HPP
#define ZLL_META_TYPES_TYPEVECTOR_AT_HPP

#include "zll/debug/static_assert.hpp"

#include "zll/meta/types/at.hpp"
#include "zll/meta/types/typevector/size.hpp"
#include "zll/meta/types/typevector/typevector.hpp"
#include "zll/meta/types/typevector/is_typevector.hpp"

#include "zll/cstdint.hpp"

namespace zll {
namespace meta {

namespace detail {

template <typename T, zll::uint_fast32_t INDEX_V>
struct typevector_at_helper_impl;

template <typename T>
struct typevector_at_helper_impl<T, 0U> {
    typedef typename T::item00 type;
};

template <typename T>
struct typevector_at_helper_impl<T, 1U> {
    typedef typename T::item01 type;
};

template <typename T>
struct typevector_at_helper_impl<T, 2U> {
    typedef typename T::item02 type;
};

template <typename T>
struct typevector_at_helper_impl<T, 3U> {
    typedef typename T::item03 type;
};

template <typename T>
struct typevector_at_helper_impl<T, 4U> {
    typedef typename T::item04 type;
};

template <typename T>
struct typevector_at_helper_impl<T, 5U> {
    typedef typename T::item05 type;
};

template <typename T>
struct typevector_at_helper_impl<T, 6U> {
    typedef typename T::item06 type;
};

template <typename T>
struct typevector_at_helper_impl<T, 7U> {
    typedef typename T::item07 type;
};

template <typename T>
struct typevector_at_helper_impl<T, 8U> {
    typedef typename T::item08 type;
};

template <typename T>
struct typevector_at_helper_impl<T, 9U> {
    typedef typename T::item09 type;
};

template <typename T>
struct typevector_at_helper_impl<T, 10U> {
    typedef typename T::item10 type;
};

template <typename T>
struct typevector_at_helper_impl<T, 11U> {
    typedef typename T::item11 type;
};

template <typename T>
struct typevector_at_helper_impl<T, 12U> {
    typedef typename T::item12 type;
};

template <typename T>
struct typevector_at_helper_impl<T, 13U> {
    typedef typename T::item13 type;
};

template <typename T>
struct typevector_at_helper_impl<T, 14U> {
    typedef typename T::item14 type;
};

template <typename T>
struct typevector_at_helper_impl<T, 15U> {
    typedef typename T::item15 type;
};

template <typename T>
struct typevector_at_helper_impl<T, 16U> {
    typedef typename T::item16 type;
};

template <typename T>
struct typevector_at_helper_impl<T, 17U> {
    typedef typename T::item17 type;
};

template <typename T>
struct typevector_at_helper_impl<T, 18U> {
    typedef typename T::item18 type;
};

template <typename T>
struct typevector_at_helper_impl<T, 19U> {
    typedef typename T::item19 type;
};

template <typename T, zll::uint_fast32_t INDEX_V, bool = is_typevector<T>::value>
struct typevector_at_helper;

template <typename T, zll::uint_fast32_t INDEX_V>
struct typevector_at_helper<T, INDEX_V, true> {
    typedef typename typevector_at_helper_impl<T, INDEX_V>::type type;
};

}  // namespace detail

template <typename T01, typename T02, typename T03, typename T04, typename T05, typename T06, typename T07,
          typename T08, typename T09, typename T10, typename T11, typename T12, typename T13, typename T14,
          typename T15, typename T16, typename T17, typename T18, typename T19, typename T20,
          zll::uint_fast32_t INDEX_V>
struct at<
    typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20>,
    INDEX_V> {
    typedef typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19,
                       T20>
        vector_type;

    // check if index is out of range
    ZLL_STATIC_ASSERT((INDEX_V < zll::meta::size<vector_type>::value));

    typedef typename detail::typevector_at_helper<vector_type, INDEX_V>::type type;
};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPEVECTOR_AT_HPP
