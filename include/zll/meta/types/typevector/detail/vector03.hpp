/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPEVECTOR_DETAIL_VECTOR3_HPP
#define ZLL_META_TYPES_TYPEVECTOR_DETAIL_VECTOR3_HPP

#include "zll/meta/types/typevector/typevector_fwd.hpp"
#include "zll/meta/types/typevector/empty_type.hpp"

#include "zll/cstdint.hpp"

namespace zll {
namespace meta {
namespace detail {

template <typename ITEM00_T, typename ITEM01_T, typename ITEM02_T>
struct typevector3 {
    typedef typevector3 type;
    static const zll::uint_fast32_t size = 3;

    typedef ITEM00_T item00;
    typedef ITEM01_T item01;
    typedef ITEM02_T item02;
};

}  // namespace detail

// clang-format off
template <typename ITEM00_T, typename ITEM01_T, typename ITEM02_T>
struct typevector<ITEM00_T, ITEM01_T, ITEM02_T, empty_type, empty_type, empty_type, empty_type, empty_type,
                  empty_type, empty_type, empty_type, empty_type, empty_type, empty_type, empty_type, empty_type,
                  empty_type, empty_type, empty_type, empty_type> 
        : detail::typevector3<ITEM00_T, ITEM01_T, ITEM02_T> {
    typedef typename detail::typevector3<ITEM00_T, ITEM01_T, ITEM02_T>::type type;
};
// clang-format on

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPEVECTOR_DETAIL_VECTOR3_HPP
