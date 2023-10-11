/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPEVECTOR_DETAIL_VECTOR0_HPP
#define ZLL_META_TYPES_TYPEVECTOR_DETAIL_VECTOR0_HPP

#include "zll/meta/types/typevector/typevector_fwd.hpp"
#include "zll/meta/types/typevector/empty_type.hpp"

#include "zll/cstdint.hpp"

namespace zll {
namespace meta {
namespace detail {

template <typename = zll::meta::empty_type>
struct typevector0;

template <>
struct typevector0<zll::meta::empty_type> {
    typedef typevector0 type;
    static const zll::uint_fast32_t size = 0;
};

}  // namespace detail

// clang-format off
template <>
struct typevector<empty_type, empty_type, empty_type, empty_type, empty_type, empty_type, empty_type, empty_type,
                  empty_type, empty_type, empty_type, empty_type, empty_type, empty_type, empty_type, empty_type,
                  empty_type, empty_type, empty_type, empty_type>
        : detail::typevector0<> {
    typedef detail::typevector0<>::type type;
};
// clang-format on

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPEVECTOR_DETAIL_VECTOR0_HPP
