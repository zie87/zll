/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_UTILS_MACROS_HPP
#define ZLL_UTILS_MACROS_HPP

#define ZLL_STRING_CONCAT(str1, str2) ZLL_STRING_CONCAT_SUB(str1, str2)
#define ZLL_STRING_CONCAT_SUB(str1, str2) str1##str2

#endif  // ZLL_UTILS_MACROS_HPP
