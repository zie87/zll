/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_ISARITHMETIC_HPP
#define ZLL_META_ISARITHMETIC_HPP

#include "zll/meta/integral_constant.hpp"
#include "zll/meta/is_floating_point.hpp"
#include "zll/meta/is_integral.hpp"

namespace zll {
namespace meta {

template <typename T>
struct is_arithmetic : bool_constant<is_integral<T>::value || is_floating_point<T>::value> {};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_ISARITHMETIC_HPP
