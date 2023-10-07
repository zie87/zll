/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_NUMER_RATIO_OVERFLOWHELPER_HPP
#define ZLL_NUMER_RATIO_OVERFLOWHELPER_HPP

#include "zll/debug/static_assert.hpp"
#include "zll/meta/integral_constant.hpp"
#include "zll/numeric/ratio/helper.hpp"

#include "zll/cstdint.hpp"

namespace zll {
namespace detail {

template <zll::intmax_t LHS_V, zll::intmax_t RHS_V>
struct safe_multiply_helper {
    static const zll::intmax_t lhs_abs = ratio_abs_helper<LHS_V>::value;
    static const zll::intmax_t rhs_abs = ratio_abs_helper<RHS_V>::value;

    static const bool value = lhs_abs <= (INTMAX_MAX / rhs_abs);
};

template <zll::intmax_t V>
struct safe_multiply_helper<V, 0> {
    static const bool value = true;
};

// clang-format off
template <zll::intmax_t LHS_V, zll::intmax_t RHS_V, 
          bool NO_OVERFLOW_V = safe_multiply_helper<LHS_V, RHS_V>::value>
struct safe_multiply : meta::integral_constant<zll::intmax_t, (LHS_V * RHS_V)> {};
// clang-format on

template <zll::intmax_t LHS_V, zll::intmax_t RHS_V>
struct safe_multiply<LHS_V, RHS_V, false> {
    static const bool no_overflow = safe_multiply_helper<LHS_V, RHS_V>::value;
    ZLL_STATIC_ASSERT(no_overflow);
};

// clang-format off
template <zll::intmax_t LHS_V, zll::intmax_t RHS_V, 
          zll::intmax_t LHS_SIGN_V = ratio_sign_helper<LHS_V>::value,
          zll::intmax_t RHS_SIGN_V = ratio_sign_helper<RHS_V>::value>
struct safe_addition_helper {
    static const bool value = true;
};
// clang-format on

template <zll::intmax_t LHS_V, zll::intmax_t RHS_V, zll::intmax_t SIGN_V>
struct safe_addition_helper<LHS_V, RHS_V, SIGN_V, SIGN_V> {
    static const zll::intmax_t lhs_abs = ratio_abs_helper<LHS_V>::value;
    static const zll::intmax_t rhs_abs = ratio_abs_helper<RHS_V>::value;

    static const bool value = lhs_abs <= (INTMAX_MAX - rhs_abs);
};

// clang-format off
template <zll::intmax_t LHS_V, zll::intmax_t RHS_V, 
          bool NO_OVERFLOW_V = safe_addition_helper<LHS_V, RHS_V>::value>
struct safe_addition : meta::integral_constant<zll::intmax_t, (LHS_V + RHS_V)> {};
// clang-format on

template <zll::intmax_t LHS_V, zll::intmax_t RHS_V>
struct safe_addition<LHS_V, RHS_V, false> {
    static const bool no_overflow = safe_addition_helper<LHS_V, RHS_V>::value;
    ZLL_STATIC_ASSERT(no_overflow);
};

}  // namespace detail
}  // namespace zll

#endif  // ZLL_NUMER_RATIO_OVERFLOWHELPER_HPP
