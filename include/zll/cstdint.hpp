/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_CSTDINT_HPP
#define ZLL_CSTDINT_HPP

#include <stdint.h>

namespace zll {
using ::int8_t;
using ::int_fast8_t;
using ::int_least8_t;
using ::uint8_t;
using ::uint_fast8_t;
using ::uint_least8_t;

using ::int16_t;
using ::int_fast16_t;
using ::int_least16_t;
using ::uint16_t;
using ::uint_fast16_t;
using ::uint_least16_t;

using ::int32_t;
using ::int_fast32_t;
using ::int_least32_t;
using ::uint32_t;
using ::uint_fast32_t;
using ::uint_least32_t;

using ::int64_t;
using ::int_fast64_t;
using ::int_least64_t;
using ::uint64_t;
using ::uint_fast64_t;
using ::uint_least64_t;

using ::intmax_t;
using ::uintmax_t;
}  // namespace zll

namespace zll {
// this is specific for gcc and clang
typedef __INTPTR_TYPE__ intptr_t;
typedef __UINTPTR_TYPE__ uintptr_t;
}  // namespace zll

#endif  // ZLL_CSTDINT_HPP
