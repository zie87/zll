/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_DETAIL_CONSTRAINTSTYPE_HPP
#define ZLL_META_DETAIL_CONSTRAINTSTYPE_HPP

namespace zll {
namespace meta {
namespace detail {

template <typename T>
struct larger_than {
    T body[2];
};

typedef char no_type;
typedef larger_than<no_type> yes_type;

}  // namespace detail
}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_DETAIL_CONSTRAINTSTYPE_HPP
