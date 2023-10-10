/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_NUMERIC_RATIO_ARITHMETIC_HPP
#define ZLL_NUMERIC_RATIO_ARITHMETIC_HPP

#include "zll/numeric/ratio/ratio_type.hpp"
#include "zll/numeric/ratio/helper.hpp"
#include "zll/numeric/ratio/overflow_helper.hpp"

#include "zll/meta/integral_constant.hpp"
#include "zll/meta/traits/enable_if.hpp"

#include "zll/cstdint.hpp"

namespace zll {
namespace detail {
template <typename LHS_T, typename RHS_T>
struct ratio_add_helper {
    static const zll::intmax_t gcd = ratio_gcd_helper<LHS_T::den, RHS_T::den>::value;

    static const zll::intmax_t num = safe_addition<safe_multiply<LHS_T::num, (RHS_T::den / gcd)>::value,
                                                   safe_multiply<RHS_T::num, (LHS_T::den / gcd)>::value>::value;
    static const zll::intmax_t den = safe_multiply<LHS_T::den, (RHS_T::den / gcd)>::value;

    typedef ratio<num, den> ratio_type;
    typedef typename ratio_type::type type;
};

}  // namespace detail

// clang-format off
template <typename LHS_T, typename RHS_T, 
          typename meta::enable_if<is_ratio<LHS_T>::value, bool>::type = true,
          typename meta::enable_if<is_ratio<RHS_T>::value, bool>::type = true>
struct ratio_add {
    typedef typename detail::ratio_add_helper<LHS_T, RHS_T>::type type;
};
// clang-format on

// clang-format off
template <typename LHS_T, typename RHS_T, 
          typename meta::enable_if<is_ratio<LHS_T>::value, bool>::type = true,
          typename meta::enable_if<is_ratio<RHS_T>::value, bool>::type = true>
struct ratio_subtract {
    typedef typename detail::ratio_add_helper< LHS_T, ratio<-RHS_T::num, RHS_T::den> >::type type;
};
// clang-format on

namespace detail {

template <typename LHS_T, typename RHS_T>
struct ratio_multiply_helper {
    static const zll::intmax_t gcd_x = ratio_gcd_helper<LHS_T::num, RHS_T::den>::value;
    static const zll::intmax_t gcd_y = ratio_gcd_helper<RHS_T::num, LHS_T::den>::value;

    static const zll::intmax_t num = safe_multiply<LHS_T::num / gcd_x, RHS_T::num / gcd_y>::value;
    static const zll::intmax_t den = safe_multiply<LHS_T::den / gcd_y, RHS_T::den / gcd_x>::value;

    typedef ratio<num, den> ratio_type;
    typedef typename ratio_type::type type;
};

}  // namespace detail

// clang-format off
template <typename LHS_T, typename RHS_T, 
          typename meta::enable_if<is_ratio<LHS_T>::value, bool>::type = true,
          typename meta::enable_if<is_ratio<RHS_T>::value, bool>::type = true>
struct ratio_multiply {
    typedef typename detail::ratio_multiply_helper<LHS_T, RHS_T>::type type;
};
// clang-format on
namespace detail {

template <typename LHS_T, typename RHS_T>
struct ratio_divide_helper {
    static const zll::intmax_t gcd_num = ratio_gcd_helper<LHS_T::num, RHS_T::num>::value;
    static const zll::intmax_t gcd_den = ratio_gcd_helper<RHS_T::den, LHS_T::den>::value;

    static const zll::intmax_t num = safe_multiply<LHS_T::num / gcd_num, RHS_T::den / gcd_den>::value;
    static const zll::intmax_t den = safe_multiply<RHS_T::num / gcd_num, LHS_T::den / gcd_den>::value;

    typedef ratio<num, den> ratio_type;
    typedef typename ratio_type::type type;
};

}  // namespace detail

// clang-format off
template <typename LHS_T, typename RHS_T, 
          typename meta::enable_if<is_ratio<LHS_T>::value, bool>::type = true,
          typename meta::enable_if<is_ratio<RHS_T>::value, bool>::type = true>
struct ratio_divide {
    typedef typename detail::ratio_divide_helper<LHS_T, RHS_T>::type type;
};
// clang-format on


}  // namespace zll

#endif  // ZLL_NUMERIC_RATIO_ARITHMETIC_HPP
