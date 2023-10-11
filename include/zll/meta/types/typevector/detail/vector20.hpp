/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_META_TYPES_TYPEVECTOR_DETAIL_VECTOR20_HPP
#define ZLL_META_TYPES_TYPEVECTOR_DETAIL_VECTOR20_HPP

#include "zll/meta/types/typevector/typevector_fwd.hpp"
#include "zll/meta/types/typevector/empty_type.hpp"

#include "zll/cstdint.hpp"

namespace zll {
namespace meta {
namespace detail {

template <typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T, typename ITEM04_T,
          typename ITEM05_T, typename ITEM06_T, typename ITEM07_T, typename ITEM08_T, typename ITEM09_T,
          typename ITEM10_T, typename ITEM11_T, typename ITEM12_T, typename ITEM13_T, typename ITEM14_T,
          typename ITEM15_T, typename ITEM16_T, typename ITEM17_T, typename ITEM18_T, typename ITEM19_T>
struct typevector20 {
    typedef typevector20 type;
    static const zll::uint_fast32_t size = 20;

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
    typedef ITEM16_T item16;
    typedef ITEM17_T item17;
    typedef ITEM18_T item18;
    typedef ITEM19_T item19;
};

}  // namespace detail

// clang-format off
template <typename ITEM00_T, typename ITEM01_T, typename ITEM02_T, typename ITEM03_T, typename ITEM04_T,
          typename ITEM05_T, typename ITEM06_T, typename ITEM07_T, typename ITEM08_T, typename ITEM09_T,
          typename ITEM10_T, typename ITEM11_T, typename ITEM12_T, typename ITEM13_T, typename ITEM14_T,
          typename ITEM15_T, typename ITEM16_T, typename ITEM17_T, typename ITEM18_T, typename ITEM19_T>
struct typevector : detail::typevector20<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T, ITEM07_T,
                                         ITEM08_T, ITEM09_T, ITEM10_T, ITEM11_T, ITEM12_T, ITEM13_T, ITEM14_T, ITEM15_T,
                                         ITEM16_T, ITEM17_T, ITEM18_T, ITEM19_T> {
    typedef typename detail::typevector20<ITEM00_T, ITEM01_T, ITEM02_T, ITEM03_T, ITEM04_T, ITEM05_T, ITEM06_T,
                                          ITEM07_T, ITEM08_T, ITEM09_T, ITEM10_T, ITEM11_T, ITEM12_T, ITEM13_T,
                                          ITEM14_T, ITEM15_T, ITEM16_T, ITEM17_T, ITEM18_T, ITEM19_T>::type type;
};
// clang-format on

}  // namespace meta
}  // namespace zll

#endif  // ZLL_META_TYPES_TYPEVECTOR_DETAIL_VECTOR20_HPP
