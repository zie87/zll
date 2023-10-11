/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPEVECTOR_DETAIL_VECTOR2_HPP
#define ZLL_META_TYPES_TYPEVECTOR_DETAIL_VECTOR2_HPP

#include "zll/meta/types/typevector/typevector_fwd.hpp"
#include "zll/meta/types/typevector/empty_type.hpp"

#include "zll/cstdint.hpp"

namespace zll {
namespace meta {
namespace detail {

template <typename ITEM00_T, typename ITEM01_T>
struct typevector2 {
    typedef typevector2 type;
    static const zll::uint_fast32_t size = 2;

    typedef ITEM00_T item00;
    typedef ITEM01_T item01;
};

}  // namespace detail

// clang-format off
template <typename ITEM00_T, typename ITEM01_T>
struct typevector<ITEM00_T, ITEM01_T, empty_type, empty_type, empty_type, empty_type, empty_type, empty_type,
                  empty_type, empty_type, empty_type, empty_type, empty_type, empty_type, empty_type, empty_type,
                  empty_type, empty_type, empty_type, empty_type> 
        : detail::typevector2<ITEM00_T, ITEM01_T> {
    typedef typename detail::typevector2<ITEM00_T, ITEM01_T>::type type;
};
// clang-format on

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPEVECTOR_DETAIL_VECTOR2_HPP
