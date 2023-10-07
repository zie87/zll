/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLl_NUMERIC_RATIO_COMPARSION_HPP
#define ZLl_NUMERIC_RATIO_COMPARSION_HPP

#include "zll/numeric/ratio/ratio_type.hpp"
#include "zll/numeric/ratio/helper.hpp"
#include "zll/numeric/ratio/overflow_helper.hpp"

#include "zll/meta/enable_if.hpp"
#include "zll/meta/integral_constant.hpp"

namespace zll {

// clang-format off
template <typename LHS_T, typename RHS_T, 
          typename meta::enable_if<is_ratio<LHS_T>::value, bool>::type = true,
          typename meta::enable_if<is_ratio<RHS_T>::value, bool>::type = true>
struct ratio_equal : meta::bool_constant<((LHS_T::num == RHS_T::num) && (LHS_T::den == RHS_T::den))> {};
// clang-format on

// clang-format off
template <typename LHS_T, typename RHS_T, 
          typename meta::enable_if<is_ratio<LHS_T>::value, bool>::type = true,
          typename meta::enable_if<is_ratio<RHS_T>::value, bool>::type = true>
struct ratio_not_equal : meta::bool_constant< !(ratio_equal<LHS_T,RHS_T>::value) > {};
// clang-format on

namespace detail {
// clang-format off
template <typename LHS_T, typename RHS_T>
struct ratio_less_helper_impl {
    static const zll::intmax_t lhs = detail::safe_multiply<LHS_T::num, RHS_T::den>::value;
    static const zll::intmax_t rhs = detail::safe_multiply<RHS_T::num, LHS_T::den>::value;
    static const bool value =  lhs < rhs;
};
// clang-format on

// clang-format off
template <typename LHS_T, typename RHS_T, 
          zll::intmax_t LHS_SIGN_V = ratio_sign_helper<LHS_T::num>::value,
          zll::intmax_t RHS_SIGN_V = ratio_sign_helper<RHS_T::num>::value>
struct ratio_less_helper : meta::bool_constant<(LHS_SIGN_V < RHS_SIGN_V)> {};
// clang-format on

// clang-format off
template <typename LHS_T, typename RHS_T>
struct ratio_less_helper<LHS_T, RHS_T, 1, 1> 
    : meta::bool_constant<ratio_less_helper_impl<LHS_T, RHS_T>::value> {};
// clang-format on

// clang-format off
template <typename LHS_T, typename RHS_T>
struct ratio_less_helper<LHS_T, RHS_T, -1, -1> 
    : meta::bool_constant<ratio_less_helper_impl< ratio<-LHS_T::num, LHS_T::den>, 
                                                  ratio<-RHS_T::num, RHS_T::den> >::value> {};
// clang-format on
}  // namespace detail

// clang-format off
template <typename LHS_T, typename RHS_T, 
          typename meta::enable_if<is_ratio<LHS_T>::value, bool>::type = true,
          typename meta::enable_if<is_ratio<RHS_T>::value, bool>::type = true>
struct ratio_less : detail::ratio_less_helper<LHS_T, RHS_T> {};
// clang-format on

// clang-format off
template <typename LHS_T, typename RHS_T, 
          typename meta::enable_if<is_ratio<LHS_T>::value, bool>::type = true,
          typename meta::enable_if<is_ratio<RHS_T>::value, bool>::type = true>
struct ratio_greater : detail::ratio_less_helper<RHS_T, LHS_T> {};
// clang-format on

// clang-format off
template <typename LHS_T, typename RHS_T, 
          typename meta::enable_if<is_ratio<LHS_T>::value, bool>::type = true,
          typename meta::enable_if<is_ratio<RHS_T>::value, bool>::type = true>
struct ratio_less_equal : meta::bool_constant<!(ratio_greater<LHS_T, RHS_T>::value)> {};
// clang-format on

// clang-format off
template <typename LHS_T, typename RHS_T, 
          typename meta::enable_if<is_ratio<LHS_T>::value, bool>::type = true,
          typename meta::enable_if<is_ratio<RHS_T>::value, bool>::type = true>
struct ratio_greater_equal : meta::bool_constant<!(ratio_less<LHS_T, RHS_T>::value)> {};
// clang-format on

}  // namespace zll

#endif  // ZLl_NUMERIC_RATIO_COMPARSION_HPP
