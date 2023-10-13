/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPEIDENTITY_HPP
#define ZLL_META_TYPEIDENTITY_HPP

namespace zll {
namespace meta {

template <typename T>
struct type_identity {
    typedef T type;
};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPEIDENTITY_HPP
