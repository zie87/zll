/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/meta/is_object.hpp"

#include <utest.h>

struct test_struct {
    int val;
};

enum test_enum {};

UTEST(meta_is_object, is_object) {
    ASSERT_TRUE(zll::meta::is_object<int>::value);
    ASSERT_TRUE(zll::meta::is_object<int*>::value);
    ASSERT_TRUE(zll::meta::is_object<test_struct>::value);
    ASSERT_TRUE(zll::meta::is_object<test_struct*>::value);
    ASSERT_TRUE(zll::meta::is_object<int (*)()>::value);
}

UTEST(meta_is_object, is_not_object) {
    ASSERT_FALSE(zll::meta::is_object<void>::value);
    ASSERT_FALSE(zll::meta::is_object<int&>::value);
    ASSERT_FALSE(zll::meta::is_object<char*&>::value);
    ASSERT_FALSE(zll::meta::is_object<test_struct&>::value);
    ASSERT_FALSE(zll::meta::is_object<int()>::value);
    ASSERT_FALSE(zll::meta::is_object<void(&)()>::value);
}
