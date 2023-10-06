/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_MEMORY_ADDRESSOF_HPP
#define ZLL_MEMORY_ADDRESSOF_HPP

#include "zll/meta/enable_if.hpp"
#include "zll/meta/is_object.hpp"
#include "zll/utils/attribute_macros.hpp"

namespace zll {

template <typename T>
ZLL_FORCE_INLINE typename meta::enable_if<meta::is_object<T>::value, T*>::type addressof(T& arg) {
    return reinterpret_cast<T*>(&const_cast<char&>(reinterpret_cast<const volatile char&>(arg)));
}

template <typename T>
ZLL_FORCE_INLINE typename meta::enable_if<!meta::is_object<T>::value, T*>::type addressof(T& arg) {
    return &arg;
}

}  // namespace zll

#endif  // ZLL_MEMORY_ADDRESSOF_HPP
