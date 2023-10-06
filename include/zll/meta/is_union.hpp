/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_ISUNION_HPP
#define ZLL_META_ISUNION_HPP

#include "zll/utils/intrinsics_macros.hpp"
#include "zll/meta/integral_constant.hpp"

namespace zll {
namespace meta {

template <typename T>
struct is_union : bool_constant<ZLL_INTRINSICS_IS_UNION(T)> {};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_ISUNION_HPP
