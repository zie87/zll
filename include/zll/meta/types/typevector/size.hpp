/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPEVECTOR_SIZE_HPP
#define ZLL_META_TYPES_TYPEVECTOR_SIZE_HPP

#include "zll/meta/integral_constant.hpp"
#include "zll/meta/traits/enable_if.hpp"

#include "zll/meta/types/size.hpp"
#include "zll/meta/types/typevector/typevector.hpp"
#include "zll/meta/types/typevector/is_typevector.hpp"

#include "zll/cstdint.hpp"

namespace zll {
namespace meta {

namespace detail {

template <typename T, bool = is_typevector<T>::value>
struct typevector_size_helper;

template <typename T>
struct typevector_size_helper<T, true> {
    static const zll::uint_fast32_t value = T::size;
};

template <typename T, bool = is_typevector<T>::value>
struct typevector_empty_helper;

template <typename T>
struct typevector_empty_helper<T, true> {
    static const bool value = (typevector_size_helper<T, true>::value == 0U);
};

}  // namespace detail

template <typename T01, typename T02, typename T03, typename T04, typename T05, typename T06, typename T07,
          typename T08, typename T09, typename T10, typename T11, typename T12, typename T13, typename T14,
          typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>
struct size<
    typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20> >
    : zll::meta::integral_constant<
          zll::uint_fast32_t,
          detail::typevector_size_helper<typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13,
                                                    T14, T15, T16, T17, T18, T19, T20> >::value> {};

template <typename T01, typename T02, typename T03, typename T04, typename T05, typename T06, typename T07,
          typename T08, typename T09, typename T10, typename T11, typename T12, typename T13, typename T14,
          typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>
struct empty<
    typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20> >
    : zll::meta::bool_constant<
          detail::typevector_empty_helper<typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13,
                                                     T14, T15, T16, T17, T18, T19, T20> >::value> {};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPEVECTOR_HPP
