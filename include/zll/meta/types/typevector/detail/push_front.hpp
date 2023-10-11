/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPEVECTOR_DETAIL_PUSHFRONT_HPP
#define ZLL_META_TYPES_TYPEVECTOR_DETAIL_PUSHFRONT_HPP

#include "zll/debug/static_assert.hpp"

#include "zll/meta/types/push.hpp"
#include "zll/meta/types/typevector/empty_type.hpp"
#include "zll/meta/types/typevector/typevector.hpp"
#include "zll/meta/types/typevector/size.hpp"

namespace zll {
namespace meta {

namespace detail {

template <typename VEC_T, typename PUSH_T>
struct typevector_push_front_helper;

template <typename PUSH_T>
struct typevector_push_front_helper<typevector<>, PUSH_T> {
    typedef typevector<PUSH_T> type;
};

template <typename PUSH_T, typename ITEM00_T>
struct typevector_push_front_helper<typevector<ITEM00_T>, PUSH_T> {
    typedef typevector<PUSH_T, ITEM00_T> type;
};

template <typename PUSH_T, typename ITEM00_T, typename ITEM01_T>
struct typevector_push_front_helper<typevector<ITEM00_T, ITEM01_T>, PUSH_T> {
    typedef typevector<PUSH_T, ITEM00_T, ITEM01_T> type;
};

template <typename PUSH_T, typename ITEM00_T, typename ITEM01_T, typename ITEM02_T>
struct typevector_push_front_helper<typevector<ITEM00_T, ITEM01_T, ITEM02_T>, PUSH_T> {
    typedef typevector<PUSH_T, ITEM00_T, ITEM01_T, ITEM02_T> type;
};

template <typename PUSH_T, typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T>
struct typevector_push_front_helper<typevector<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T>, PUSH_T> {
    typedef typevector<PUSH_T, ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T> type;
};

template <typename PUSH_T, typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T,
          typename ITEM04_T>
struct typevector_push_front_helper<typevector<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T>, PUSH_T> {
    typedef typevector<PUSH_T, ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T> type;
};

template <typename PUSH_T, typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T,
          typename ITEM04_T, typename ITEM05_T>
struct typevector_push_front_helper<typevector<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T>, PUSH_T> {
    typedef typevector<PUSH_T, ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T> type;
};

template <typename PUSH_T, typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T,
          typename ITEM04_T, typename ITEM05_T, typename ITEM06_T>
struct typevector_push_front_helper<typevector<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T>,
                                    PUSH_T> {
    typedef typevector<PUSH_T, ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T> type;
};

template <typename PUSH_T, typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T,
          typename ITEM04_T, typename ITEM05_T, typename ITEM06_T, typename ITEM07_T>
struct typevector_push_front_helper<
    typevector<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T>, PUSH_T> {
    typedef typevector<PUSH_T, ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T> type;
};

template <typename PUSH_T, typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T,
          typename ITEM04_T, typename ITEM05_T, typename ITEM06_T, typename ITEM07_T, typename ITEM08_T>
struct typevector_push_front_helper<
    typevector<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T>, PUSH_T> {
    typedef typevector<PUSH_T, ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T>
        type;
};

template <typename PUSH_T, typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T,
          typename ITEM04_T, typename ITEM05_T, typename ITEM06_T, typename ITEM07_T, typename ITEM08_T,
          typename ITEM09_T>
struct typevector_push_front_helper<
    typevector<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T, ITEM09_T>,
    PUSH_T> {
    typedef typevector<PUSH_T, ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T,
                       ITEM09_T>
        type;
};

template <typename PUSH_T, typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T,
          typename ITEM04_T, typename ITEM05_T, typename ITEM06_T, typename ITEM07_T, typename ITEM08_T,
          typename ITEM09_T, typename ITEM10_T>
struct typevector_push_front_helper<typevector<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T,
                                               ITEM07_T, ITEM08_T, ITEM09_T, ITEM10_T>,
                                    PUSH_T> {
    typedef typevector<PUSH_T, ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T,
                       ITEM09_T, ITEM10_T>
        type;
};

template <typename PUSH_T, typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T,
          typename ITEM04_T, typename ITEM05_T, typename ITEM06_T, typename ITEM07_T, typename ITEM08_T,
          typename ITEM09_T, typename ITEM10_T, typename ITEM11_T>
struct typevector_push_front_helper<typevector<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T,
                                               ITEM07_T, ITEM08_T, ITEM09_T, ITEM10_T, ITEM11_T>,
                                    PUSH_T> {
    typedef typevector<PUSH_T, ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T,
                       ITEM09_T, ITEM10_T, ITEM11_T>
        type;
};

template <typename PUSH_T, typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T,
          typename ITEM04_T, typename ITEM05_T, typename ITEM06_T, typename ITEM07_T, typename ITEM08_T,
          typename ITEM09_T, typename ITEM10_T, typename ITEM11_T, typename ITEM12_T>
struct typevector_push_front_helper<typevector<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T,
                                               ITEM07_T, ITEM08_T, ITEM09_T, ITEM10_T, ITEM11_T, ITEM12_T>,
                                    PUSH_T> {
    typedef typevector<PUSH_T, ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T,
                       ITEM09_T, ITEM10_T, ITEM11_T, ITEM12_T>
        type;
};

template <typename PUSH_T, typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T,
          typename ITEM04_T, typename ITEM05_T, typename ITEM06_T, typename ITEM07_T, typename ITEM08_T,
          typename ITEM09_T, typename ITEM10_T, typename ITEM11_T, typename ITEM12_T, typename ITEM13_T>
struct typevector_push_front_helper<typevector<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T,
                                               ITEM07_T, ITEM08_T, ITEM09_T, ITEM10_T, ITEM11_T, ITEM12_T, ITEM13_T>,
                                    PUSH_T> {
    typedef typevector<PUSH_T, ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T,
                       ITEM09_T, ITEM10_T, ITEM11_T, ITEM12_T, ITEM13_T>
        type;
};

template <typename PUSH_T, typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T,
          typename ITEM04_T, typename ITEM05_T, typename ITEM06_T, typename ITEM07_T, typename ITEM08_T,
          typename ITEM09_T, typename ITEM10_T, typename ITEM11_T, typename ITEM12_T, typename ITEM13_T,
          typename ITEM14_T>
struct typevector_push_front_helper<
    typevector<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T, ITEM09_T,
               ITEM10_T, ITEM11_T, ITEM12_T, ITEM13_T, ITEM14_T>,
    PUSH_T> {
    typedef typevector<PUSH_T, ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T,
                       ITEM09_T, ITEM10_T, ITEM11_T, ITEM12_T, ITEM13_T, ITEM14_T>
        type;
};

template <typename PUSH_T, typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T,
          typename ITEM04_T, typename ITEM05_T, typename ITEM06_T, typename ITEM07_T, typename ITEM08_T,
          typename ITEM09_T, typename ITEM10_T, typename ITEM11_T, typename ITEM12_T, typename ITEM13_T,
          typename ITEM14_T, typename ITEM15_T>
struct typevector_push_front_helper<
    typevector<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T, ITEM09_T,
               ITEM10_T, ITEM11_T, ITEM12_T, ITEM13_T, ITEM14_T, ITEM15_T>,
    PUSH_T> {
    typedef typevector<PUSH_T, ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T,
                       ITEM09_T, ITEM10_T, ITEM11_T, ITEM12_T, ITEM13_T, ITEM14_T, ITEM15_T>
        type;
};

template <typename PUSH_T, typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T,
          typename ITEM04_T, typename ITEM05_T, typename ITEM06_T, typename ITEM07_T, typename ITEM08_T,
          typename ITEM09_T, typename ITEM10_T, typename ITEM11_T, typename ITEM12_T, typename ITEM13_T,
          typename ITEM14_T, typename ITEM15_T, typename ITEM16_T>
struct typevector_push_front_helper<
    typevector<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T, ITEM09_T,
               ITEM10_T, ITEM11_T, ITEM12_T, ITEM13_T, ITEM14_T, ITEM15_T, ITEM16_T>,
    PUSH_T> {
    typedef typevector<PUSH_T, ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T,
                       ITEM09_T, ITEM10_T, ITEM11_T, ITEM12_T, ITEM13_T, ITEM14_T, ITEM15_T, ITEM16_T>
        type;
};

template <typename PUSH_T, typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T,
          typename ITEM04_T, typename ITEM05_T, typename ITEM06_T, typename ITEM07_T, typename ITEM08_T,
          typename ITEM09_T, typename ITEM10_T, typename ITEM11_T, typename ITEM12_T, typename ITEM13_T,
          typename ITEM14_T, typename ITEM15_T, typename ITEM16_T, typename ITEM17_T>
struct typevector_push_front_helper<
    typevector<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T, ITEM09_T,
               ITEM10_T, ITEM11_T, ITEM12_T, ITEM13_T, ITEM14_T, ITEM15_T, ITEM16_T, ITEM17_T>,
    PUSH_T> {
    typedef typevector<PUSH_T, ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T,
                       ITEM09_T, ITEM10_T, ITEM11_T, ITEM12_T, ITEM13_T, ITEM14_T, ITEM15_T, ITEM16_T, ITEM17_T>
        type;
};

template <typename PUSH_T, typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T,
          typename ITEM04_T, typename ITEM05_T, typename ITEM06_T, typename ITEM07_T, typename ITEM08_T,
          typename ITEM09_T, typename ITEM10_T, typename ITEM11_T, typename ITEM12_T, typename ITEM13_T,
          typename ITEM14_T, typename ITEM15_T, typename ITEM16_T, typename ITEM17_T, typename ITEM18_T>
struct typevector_push_front_helper<
    typevector<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T, ITEM09_T,
               ITEM10_T, ITEM11_T, ITEM12_T, ITEM13_T, ITEM14_T, ITEM15_T, ITEM16_T, ITEM17_T, ITEM18_T>,
    PUSH_T> {
    typedef typevector<PUSH_T, ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T,
                       ITEM09_T, ITEM10_T, ITEM11_T, ITEM12_T, ITEM13_T, ITEM14_T, ITEM15_T, ITEM16_T, ITEM17_T,
                       ITEM18_T>
        type;
};

}  // namespace detail

template <typename T01, typename T02, typename T03, typename T04, typename T05, typename T06, typename T07,
          typename T08, typename T09, typename T10, typename T11, typename T12, typename T13, typename T14,
          typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename PUSH_T>
struct push_front<
    typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20>,
    PUSH_T> {
    typedef typevector<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19,
                       T20>
        vector_type;

    ZLL_STATIC_ASSERT((zll::meta::size<vector_type>::value < 20));  // only 20 elements are supported for now
    typedef typename detail::typevector_push_front_helper<vector_type, PUSH_T>::type type;
};

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPEVECTOR_PUSH_HPP
