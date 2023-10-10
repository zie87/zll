/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/meta/traits/is_scalar.hpp"

#include <utest.h>

struct test_struct {
    int val;
};

enum test_enum {};

UTEST(meta_traits_is_scalar, is_scalar) {
    ASSERT_TRUE(zll::meta::is_scalar<int>::value);
    ASSERT_TRUE(zll::meta::is_scalar<double>::value);
    ASSERT_TRUE(zll::meta::is_scalar<test_enum>::value);
    ASSERT_TRUE(zll::meta::is_scalar<const char*>::value);
    ASSERT_TRUE(zll::meta::is_scalar<int test_struct::*>::value);
}

UTEST(meta_traits_is_scalar, is_not_scalar) {
    ASSERT_FALSE(zll::meta::is_scalar<test_struct>::value);
}
