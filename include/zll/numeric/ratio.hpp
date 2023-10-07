/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_NUMERIC_RATIO_HPP
#define ZLL_NUMERIC_RATIO_HPP

#include "zll/numeric/ratio/ratio_type.hpp"
#include "zll/numeric/ratio/arithmetic.hpp"
#include "zll/numeric/ratio/comparsion.hpp"


namespace zll {

// clang-format off
typedef ratio<1L, 1000000000000000000L> atto;
typedef ratio<1L,    1000000000000000L> femto;
typedef ratio<1L,       1000000000000L> pico;
typedef ratio<1L,          1000000000L> nano;
typedef ratio<1L,             1000000L> micro;
typedef ratio<1L,                1000L> milli;
typedef ratio<1L,                 100L> centi;
typedef ratio<1L,                  10L> deci;
typedef ratio<                 10L, 1L> deca;
typedef ratio<                100L, 1L> hecto;
typedef ratio<               1000L, 1L> kilo;
typedef ratio<            1000000L, 1L> mega;
typedef ratio<         1000000000L, 1L> giga;
typedef ratio<      1000000000000L, 1L> tera;
typedef ratio<   1000000000000000L, 1L> peta;
typedef ratio<1000000000000000000L, 1L> exa;
// clang-format on

}  // namespace zll

#endif  // ZLL_NUMERIC_RATIO_HPP
