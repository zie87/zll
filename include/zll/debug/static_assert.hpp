/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_DEBUG_STATICASSERT_HPP
#define ZLL_DEBUG_STATICASSERT_HPP

#include "zll/utils/macros.hpp"

namespace zll {
namespace debug {

template <bool CONDITION_V>
struct static_assertion;

template <>
struct static_assertion<true> {
    static_assertion() {}

    template <typename T>
    static_assertion(T) {}
};

}  // namespace debug
}  // namespace zll

#define ZLL_STATIC_ASSERT(expr) \
    enum { ZLL_STRING_CONCAT(boost_static_assert_enum_, __LINE__) = sizeof(zll::debug::static_assertion<expr != 0>) }

#endif  // ZLL_DEBUG_STATICASSERT_HPP
