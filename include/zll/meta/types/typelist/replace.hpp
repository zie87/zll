/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPELIST_REPLACE_HPP
#define ZLL_META_TYPES_TYPELIST_REPLACE_HPP

#include "zll/meta/types/replace.hpp"
#include "zll/meta/types/typelist/nil_type.hpp"
#include "zll/meta/types/typelist/typelist.hpp"

namespace zll {
namespace meta {

namespace detail {

template <typename, typename, typename>
struct typelist_replace_helper;

template <typename OUT_T, typename IN_T>
struct typelist_replace_helper<nil_type, OUT_T, IN_T> {
    typedef nil_type type;
};

template <typename T, typename TAIL_T, typename IN_T>
struct typelist_replace_helper<typelist<T, TAIL_T>, T, IN_T> {
    typedef typelist<IN_T, typename detail::typelist_replace_helper<TAIL_T, T, IN_T>::type> type;
};

template <typename HEAD_T, typename TAIL_T, typename OUT_T, typename IN_T>
struct typelist_replace_helper<typelist<HEAD_T, TAIL_T>, OUT_T, IN_T> {
    typedef typelist<HEAD_T, typename detail::typelist_replace_helper<TAIL_T, OUT_T, IN_T>::type> type;
};

template <typename, typename, typename>
struct typelist_replace_first_helper;

template <typename OUT_T, typename IN_T>
struct typelist_replace_first_helper<nil_type, OUT_T, IN_T> {
    typedef nil_type type;
};

template <typename T, typename TAIL_T, typename IN_T>
struct typelist_replace_first_helper<typelist<T, TAIL_T>, T, IN_T> {
    typedef typelist<IN_T, TAIL_T> type;
};

template <typename HEAD_T, typename TAIL_T, typename OUT_T, typename IN_T>
struct typelist_replace_first_helper<typelist<HEAD_T, TAIL_T>, OUT_T, IN_T> {
    typedef typelist<HEAD_T, typename detail::typelist_replace_first_helper<TAIL_T, OUT_T, IN_T>::type> type;
};

}  // namespace detail

template <typename OUT_T, typename IN_T>
struct replace<nil_type, OUT_T, IN_T> {
    typedef typename detail::typelist_replace_helper<nil_type, OUT_T, IN_T>::type type;
};

template <typename HEAD_T, typename TAIL_T, typename OUT_T, typename IN_T>
struct replace<typelist<HEAD_T, TAIL_T>, OUT_T, IN_T> {
    typedef typename detail::typelist_replace_helper<typelist<HEAD_T, TAIL_T>, OUT_T, IN_T>::type type;
};

template <typename OUT_T, typename IN_T>
struct replace_first<nil_type, OUT_T, IN_T> {
    typedef typename detail::typelist_replace_first_helper<nil_type, OUT_T, IN_T>::type type;
};

template <typename HEAD_T, typename TAIL_T, typename OUT_T, typename IN_T>
struct replace_first<typelist<HEAD_T, TAIL_T>, OUT_T, IN_T> {
    typedef typename detail::typelist_replace_first_helper<typelist<HEAD_T, TAIL_T>, OUT_T, IN_T>::type type;
};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPELIST_REPLACE_HPP
