/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/meta/traits/is_const.hpp"

#include <utest.h>

struct test_dummy {};

UTEST(meta_traits_is_const, is_const) {
    ASSERT_TRUE(zll::meta::is_const<const int>::value);
    ASSERT_TRUE(zll::meta::is_const<int* const>::value);

    ASSERT_FALSE(zll::meta::is_const<int>::value);
    ASSERT_FALSE(zll::meta::is_const<const int*>::value);
    ASSERT_FALSE(zll::meta::is_const<const int&>::value);
}
