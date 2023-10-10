/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPELIST_APPEND_HPP
#define ZLL_META_TYPES_TYPELIST_APPEND_HPP

#include "zll/meta/types/append.hpp"
#include "zll/meta/types/typelist/nil_type.hpp"
#include "zll/meta/types/typelist/typelist.hpp"
#include "zll/meta/types/typelist/push.hpp"

namespace zll {
namespace meta {

namespace detail {
template <typename, typename>
struct typelist_append_helper;

template <typename T>
struct typelist_append_helper<nil_type, T> {
    typedef typename push_back<nil_type, T>::type type;
};

template <typename HEAD_T, typename TAIL_T>
struct typelist_append_helper<nil_type, typelist<HEAD_T, TAIL_T> > {
    typedef typelist<HEAD_T, TAIL_T> type;
};

template <typename HEAD_T, typename TAIL_T, typename T>
struct typelist_append_helper<typelist<HEAD_T, TAIL_T>, T> {
    typedef typelist<HEAD_T, typename typelist_append_helper<TAIL_T, T>::type> type;
};

}  // namespace detail

template <typename T>
struct append<nil_type, T> {
    typedef typename detail::typelist_append_helper<nil_type, T>::type type;
};

template <typename HEAD_T, typename TAIL_T, typename T>
struct append<typelist<HEAD_T, TAIL_T>, T> {
    typedef typename detail::typelist_append_helper<typelist<HEAD_T, TAIL_T>, T>::type type;
};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPELIST_APPEND_HPP
