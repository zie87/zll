/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPELIST_TYPELIST_HPP
#define ZLL_META_TYPES_TYPELIST_TYPELIST_HPP

#include "zll/meta/types/typelist/nil_type.hpp"

namespace zll {
namespace meta {

template <typename HEAD_T, typename TAIL_T = nil_type>
struct typelist {
    typedef HEAD_T head_type;
    typedef TAIL_T tail_type;
};

template <typename T01 = nil_type, typename T02 = nil_type, typename T03 = nil_type, typename T04 = nil_type,
          typename T05 = nil_type, typename T06 = nil_type, typename T07 = nil_type, typename T08 = nil_type,
          typename T09 = nil_type, typename T10 = nil_type, typename T11 = nil_type, typename T12 = nil_type,
          typename T13 = nil_type, typename T14 = nil_type, typename T15 = nil_type, typename T16 = nil_type,
          typename T17 = nil_type, typename T18 = nil_type, typename T19 = nil_type, typename T20 = nil_type>
struct make_typelist {
private:
    typedef typename make_typelist<T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18,
                                   T19, T20>::type tail_type;

public:
    typedef typelist<T01, tail_type> type;
};

template <>
struct make_typelist<> {
    typedef nil_type type;
};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPELIST_TYPELIST_HPP
