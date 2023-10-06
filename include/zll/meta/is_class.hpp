/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_ISCLASS_HPP
#define ZLL_META_ISCLASS_HPP

#include "zll/meta/enable_if.hpp"
#include "zll/meta/integral_constant.hpp"
#include "zll/meta/is_union.hpp"

#include "zll/meta/detail/constraints_type.hpp"

#include <cstdlib>

namespace zll {
namespace meta {

namespace detail {

struct is_class_helper {
    template <typename T>
    static typename enable_if<!(is_union<T>::value), yes_type>::type test(int T::*);

    template <typename>
    static no_type test(...);
};

}  // namespace detail

template <typename T>
struct is_class : bool_constant<(sizeof(detail::is_class_helper::test<T>(NULL)) == sizeof(detail::yes_type))> {};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_ISCLASS_HPP
