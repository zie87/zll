/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_ISOBJECT_HPP
#define ZLL_META_ISOBJECT_HPP

#include "zll/meta/integral_constant.hpp"
#include "zll/meta/is_array.hpp"
#include "zll/meta/is_class.hpp"
#include "zll/meta/is_scalar.hpp"
#include "zll/meta/is_union.hpp"

namespace zll {
namespace meta {

template <typename T>
struct is_object
    : bool_constant<is_scalar<T>::value || is_array<T>::value || is_union<T>::value || is_class<T>::value> {};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_ISOBJECT_HPP
