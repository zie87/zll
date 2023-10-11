/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPEVECTOR_DETAIL_VECTOR06_HPP
#define ZLL_META_TYPES_TYPEVECTOR_DETAIL_VECTOR06_HPP

#include "zll/meta/types/typevector/typevector_fwd.hpp"
#include "zll/meta/types/typevector/empty_type.hpp"

#include "zll/cstdint.hpp"

namespace zll {
namespace meta {
namespace detail {

template <typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T, typename ITEM04_T,
          typename ITEM05_T>
struct typevector6 {
    typedef typevector6 type;
    static const zll::uint_fast32_t size = 6;

    typedef ITEM00_T item00;
    typedef ITEM01_T item01;
    typedef ITEM02_T item02;
    typedef ITEM03_T item03;
    typedef ITEM04_T item04;
    typedef ITEM05_T item05;
};

}  // namespace detail

// clang-format off
template <typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T, typename ITEM04_T,
          typename ITEM05_T>
struct typevector<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T>
    : detail::typevector6<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T> {
    typedef typename detail::typevector6<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T>::type type;
};
// clang-format on

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPEVECTOR_DETAIL_VECTOR06_HPP
