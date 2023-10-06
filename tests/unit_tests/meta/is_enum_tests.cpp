/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/meta/is_enum.hpp"

#include <utest.h>

struct test_struct {
    enum test_enum {};
};

enum test_enum {};

UTEST(meta_is_enum, is_enum) {
    ASSERT_TRUE(zll::meta::is_enum<test_enum>::value);
    ASSERT_TRUE(zll::meta::is_enum<test_struct::test_enum>::value);

    ASSERT_FALSE(zll::meta::is_enum<int>::value);
    ASSERT_FALSE(zll::meta::is_enum<test_struct>::value);
}
