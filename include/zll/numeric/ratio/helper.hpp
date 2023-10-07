/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_NUMERIC_RATIO_HELPER_HPP
#define ZLL_NUMERIC_RATIO_HELPER_HPP

#include "zll/meta/integral_constant.hpp"

#include "zll/cstdint.hpp"

namespace zll {
namespace detail {

template <zll::intmax_t LHS_V, zll::intmax_t RHS_V>
struct ratio_gcd_helper_impl {
    static const zll::intmax_t value = ratio_gcd_helper_impl<RHS_V, LHS_V % RHS_V>::value;
};

template <zll::intmax_t V>
struct ratio_gcd_helper_impl<V, 0> {
    static const zll::intmax_t value = V;
};

template <>
struct ratio_gcd_helper_impl<0, 0> {
    static const zll::intmax_t value = 1;
};

template <zll::intmax_t V>
struct ratio_sign_helper_impl {
    static const zll::intmax_t value = (V == 0) ? 0 : ((V < 0) ? -1 : 1);
};

template <zll::intmax_t LHS_V, zll::intmax_t RHS_V>
struct ratio_gcd_helper : meta::integral_constant<zll::intmax_t, ratio_gcd_helper_impl<LHS_V, RHS_V>::value> {};

template <zll::intmax_t V>
struct ratio_abs_helper : meta::integral_constant<zll::intmax_t, ((V < 0) ? -V : V)> {};

template <zll::intmax_t V>
struct ratio_sign_helper : meta::integral_constant<zll::intmax_t, ratio_sign_helper_impl<V>::value> {};

}  // namespace detail
}  // namespace zll

#endif  // ZLL_NUMERIC_RATIO_HELPER_HPP
