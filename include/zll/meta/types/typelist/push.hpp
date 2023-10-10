/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPELIST_PUSH_HPP
#define ZLL_META_TYPES_TYPELIST_PUSH_HPP

#include "zll/meta/types/push.hpp"
#include "zll/meta/types/typelist/nil_type.hpp"
#include "zll/meta/types/typelist/typelist.hpp"

namespace zll {
namespace meta {

namespace detail {
template <typename, typename>
struct typelist_push_back_helper;

template <typename T>
struct typelist_push_back_helper<nil_type, T> {
    typedef typename make_typelist<T>::type type;
};

template <typename HEAD_T, typename TAIL_T, typename T>
struct typelist_push_back_helper<typelist<HEAD_T, TAIL_T>, T> {
    typedef typelist<HEAD_T, typename typelist_push_back_helper<TAIL_T, T>::type> type;
};

template <typename, typename>
struct typelist_push_front_helper;

template <typename T>
struct typelist_push_front_helper<nil_type, T> {
    typedef typename make_typelist<T>::type type;
};

template <typename HEAD_T, typename TAIL_T, typename T>
struct typelist_push_front_helper<typelist<HEAD_T, TAIL_T>, T> {
    typedef typelist<T, typelist<HEAD_T, TAIL_T> > type;
};
}  // namespace detail

template <typename T>
struct push_back<nil_type, T> {
    typedef typename detail::typelist_push_back_helper<nil_type, T>::type type;
};

template <typename HEAD_T, typename TAIL_T, typename T>
struct push_back<typelist<HEAD_T, TAIL_T>, T> {
    typedef typename detail::typelist_push_back_helper<typelist<HEAD_T, TAIL_T>, T>::type type;
};

template <typename T>
struct push_front<nil_type, T> {
    typedef typename detail::typelist_push_front_helper<nil_type, T>::type type;
};

template <typename HEAD_T, typename TAIL_T, typename T>
struct push_front<typelist<HEAD_T, TAIL_T>, T> {
    typedef typename detail::typelist_push_front_helper<typelist<HEAD_T, TAIL_T>, T>::type type;
};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPELIST_PUSH_HPP
