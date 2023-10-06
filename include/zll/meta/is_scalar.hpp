/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_ISSCALAR_HPP
#define ZLL_META_ISSCALAR_HPP

#include "zll/meta/integral_constant.hpp"
#include "zll/meta/is_arithmetic.hpp"
#include "zll/meta/is_enum.hpp"
#include "zll/meta/is_member_pointer.hpp"
#include "zll/meta/is_pointer.hpp"

namespace zll {
namespace meta {

template <typename T>
struct is_scalar : bool_constant<is_arithmetic<T>::value || is_enum<T>::value || is_pointer<T>::value ||
                                 is_member_pointer<T>::value> {};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_ISSCALAR_HPP
