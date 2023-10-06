/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/meta/is_member_pointer.hpp"

#include <utest.h>

struct test_struct {};

UTEST(meta_is_member_pointer, is_member_pointer) {
    ASSERT_TRUE(zll::meta::is_member_pointer<int(test_struct::*)>::value);
    ASSERT_FALSE(zll::meta::is_member_pointer<int>::value);
}
