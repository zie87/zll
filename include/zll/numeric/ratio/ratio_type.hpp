/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_NUMERIC_RATIO_RATIOTYPE_HPP
#define ZLL_NUMERIC_RATIO_RATIOTYPE_HPP

#include "zll/numeric/ratio/helper.hpp"

#include "zll/debug/static_assert.hpp"
#include "zll/meta/integral_constant.hpp"

#include "zll/cstdint.hpp"

namespace zll {

template <zll::intmax_t NUM_V, zll::intmax_t DENOM_V = 1>
class ratio {
    ZLL_STATIC_ASSERT((DENOM_V != 0));

    static const zll::intmax_t sign    = detail::ratio_sign_helper<NUM_V>::value * detail::ratio_sign_helper<DENOM_V>::value;
    static const zll::intmax_t num_abs = detail::ratio_abs_helper<NUM_V>::value;
    static const zll::intmax_t den_abs = detail::ratio_abs_helper<DENOM_V>::value;
    static const zll::intmax_t gcd     = detail::ratio_gcd_helper<num_abs, den_abs>::value;

public:
    static const zll::intmax_t num = sign * num_abs / gcd;
    static const zll::intmax_t den = den_abs / gcd;

    typedef ratio<num, den> type;
};

template <typename>
struct is_ratio : meta::false_type {};

template <zll::intmax_t NUM_V, zll::intmax_t DENOM_V>
struct is_ratio<ratio<NUM_V, DENOM_V> > : meta::true_type {};
}  // namespace zll

#endif  // ZLL_NUMERIC_RATIO_RATIOTYPE_HPP
