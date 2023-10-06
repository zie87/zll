/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/meta/is_union.hpp"

#include <utest.h>

union test_union {
    char a;
    int b;
};

struct test_struct {
    test_union u;
};

UTEST(meta_is_union, is_union) {
    ASSERT_TRUE(zll::meta::is_union<test_union>::value);
    ASSERT_FALSE(zll::meta::is_union<test_struct>::value);
    ASSERT_FALSE(zll::meta::is_union<int>::value);
}
