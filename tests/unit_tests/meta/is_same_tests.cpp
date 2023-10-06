/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/meta/is_same.hpp"

#include <utest.h>

struct test_dummy {};
struct test_child : test_dummy {};

UTEST(meta_is_same, compare_same) {
    ASSERT_TRUE((zll::meta::is_same<int, int>::value));
    ASSERT_TRUE((zll::meta::is_same<char, char>::value));
    ASSERT_TRUE((zll::meta::is_same<test_dummy, test_dummy>::value));
    ASSERT_TRUE((zll::meta::is_same<test_child, test_child>::value));
    ASSERT_TRUE((zll::meta::is_same<test_dummy&, test_dummy&>::value));
    ASSERT_TRUE((zll::meta::is_same<test_child&, test_child&>::value));
}

UTEST(meta_is_same, compare_not_same) {
    ASSERT_FALSE((zll::meta::is_same<int, char>::value));
    ASSERT_FALSE((zll::meta::is_same<char, short>::value));
    ASSERT_FALSE((zll::meta::is_same<test_dummy, test_child>::value));
    ASSERT_FALSE((zll::meta::is_same<test_child, int>::value));
    ASSERT_FALSE((zll::meta::is_same<test_dummy, test_dummy&>::value));
    ASSERT_FALSE((zll::meta::is_same<test_dummy*, test_child*>::value));
}
