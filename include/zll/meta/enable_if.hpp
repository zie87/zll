/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_ENABLEIF_HPP
#define ZLL_META_ENABLEIF_HPP

namespace zll {
namespace meta {

template <bool, typename = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T> {
    typedef T type;
};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_ENABLEIF_HPP
