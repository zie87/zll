/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/meta/traits/is_array.hpp"

#include <utest.h>

struct test_struct {};

UTEST(meta_traits_is_array, is_array) {
    ASSERT_TRUE(zll::meta::is_array<int[]>::value);
    ASSERT_TRUE(zll::meta::is_array<char[4]>::value);
    ASSERT_TRUE(zll::meta::is_array<test_struct[]>::value);
    ASSERT_TRUE(zll::meta::is_array<const float[3]>::value);

    ASSERT_FALSE(zll::meta::is_array<char*>::value);
    ASSERT_FALSE(zll::meta::is_array<int>::value);
    ASSERT_FALSE(zll::meta::is_array<test_struct>::value);
    ASSERT_FALSE(zll::meta::is_array<const float>::value);
}
