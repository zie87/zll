/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPEVECTOR_DETAIL_VECTOR16_HPP
#define ZLL_META_TYPES_TYPEVECTOR_DETAIL_VECTOR16_HPP

#include "zll/meta/types/typevector/typevector_fwd.hpp"
#include "zll/meta/types/typevector/empty_type.hpp"

#include "zll/cstdint.hpp"

namespace zll {
namespace meta {
namespace detail {

template <typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T, typename ITEM04_T,
          typename ITEM05_T, typename ITEM06_T, typename ITEM07_T, typename ITEM08_T, typename ITEM09_T,
          typename ITEM10_T, typename ITEM11_T, typename ITEM12_T, typename ITEM13_T, typename ITEM14_T,
          typename ITEM15_T>
struct typevector16 {
    typedef typevector16 type;
    static const zll::uint_fast32_t size = 16;

    typedef ITEM00_T item00;
    typedef ITEM01_T item01;
    typedef ITEM02_T item02;
    typedef ITEM03_T item03;
    typedef ITEM04_T item04;
    typedef ITEM05_T item05;
    typedef ITEM06_T item06;
    typedef ITEM07_T item07;
    typedef ITEM08_T item08;
    typedef ITEM09_T item09;
    typedef ITEM10_T item10;
    typedef ITEM11_T item11;
    typedef ITEM12_T item12;
    typedef ITEM13_T item13;
    typedef ITEM14_T item14;
    typedef ITEM15_T item15;
};

}  // namespace detail

// clang-format off
template <typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T, typename ITEM04_T,
          typename ITEM05_T, typename ITEM06_T, typename ITEM07_T, typename ITEM08_T, typename ITEM09_T,
          typename ITEM10_T, typename ITEM11_T, typename ITEM12_T, typename ITEM13_T, typename ITEM14_T,
          typename ITEM15_T>
struct typevector<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T, ITEM09_T,
                  ITEM10_T, ITEM11_T, ITEM12_T, ITEM13_T, ITEM14_T, ITEM15_T>
    : detail::typevector16<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T, ITEM08_T,
                           ITEM09_T, ITEM10_T, ITEM11_T, ITEM12_T, ITEM13_T, ITEM14_T, ITEM15_T> {
    typedef typename detail::typevector16<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T,
                                          ITEM07_T, ITEM08_T, ITEM09_T, ITEM10_T, ITEM11_T, ITEM12_T, ITEM13_T,
                                          ITEM14_T, ITEM15_T>::type type;
};
// clang-format on

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPEVECTOR_DETAIL_VECTOR16_HPP
