/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPELIST_REMOVE_HPP
#define ZLL_META_TYPES_TYPELIST_REMOVE_HPP

#include "zll/meta/types/remove.hpp"
#include "zll/meta/types/typelist/nil_type.hpp"
#include "zll/meta/types/typelist/typelist.hpp"

namespace zll {
namespace meta {

namespace detail {

template <typename, typename>
struct typelist_remove_helper;

template <typename T>
struct typelist_remove_helper<nil_type, T> {
    typedef nil_type type;
};

template <typename T, typename TAIL_T>
struct typelist_remove_helper<typelist<T, TAIL_T>, T> {
    typedef typename detail::typelist_remove_helper<TAIL_T, T>::type type;
};

template <typename HEAD_T, typename TAIL_T, typename T>
struct typelist_remove_helper<typelist<HEAD_T, TAIL_T>, T> {
    typedef typelist<HEAD_T, typename detail::typelist_remove_helper<TAIL_T, T>::type> type;
};

template <typename, typename>
struct typelist_remove_first_helper;

template <typename T>
struct typelist_remove_first_helper<nil_type, T> {
    typedef nil_type type;
};

template <typename T, typename TAIL_T>
struct typelist_remove_first_helper<typelist<T, TAIL_T>, T> {
    typedef TAIL_T type;
};

template <typename HEAD_T, typename TAIL_T, typename T>
struct typelist_remove_first_helper<typelist<HEAD_T, TAIL_T>, T> {
    typedef typelist<HEAD_T, typename detail::typelist_remove_first_helper<TAIL_T, T>::type> type;
};

}  // namespace detail

template <typename T>
struct remove<nil_type, T> {
    typedef typename detail::typelist_remove_helper<nil_type, T>::type type;
};

template <typename HEAD_T, typename TAIL_T, typename T>
struct remove<typelist<HEAD_T, TAIL_T>, T> {
    typedef typename detail::typelist_remove_helper<typelist<HEAD_T, TAIL_T>, T>::type type;
};

template <typename T>
struct remove_first<nil_type, T> {
    typedef typename detail::typelist_remove_first_helper<nil_type, T>::type type;
};

template <typename HEAD_T, typename TAIL_T, typename T>
struct remove_first<typelist<HEAD_T, TAIL_T>, T> {
    typedef typename detail::typelist_remove_first_helper<typelist<HEAD_T, TAIL_T>, T>::type type;
};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPELIST_REMOVE_HPP
