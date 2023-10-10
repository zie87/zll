/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/meta/traits/is_pointer.hpp"
#include "zll/meta/traits/is_same.hpp"

#include <utest.h>

struct test_dummy {};

UTEST(meta_traits_is_pointer, is_pointer) {
    ASSERT_TRUE(zll::meta::is_pointer<test_dummy*>::value);
    ASSERT_TRUE(zll::meta::is_pointer<test_dummy const* volatile>::value);
    ASSERT_TRUE(zll::meta::is_pointer<void*>::value);
    ASSERT_TRUE(zll::meta::is_pointer<int*>::value);
    ASSERT_TRUE(zll::meta::is_pointer<int**>::value);
    ASSERT_TRUE(zll::meta::is_pointer<void (*)()>::value);

    ASSERT_FALSE(zll::meta::is_pointer<test_dummy>::value);
    ASSERT_FALSE(zll::meta::is_pointer<test_dummy&>::value);
    ASSERT_FALSE(zll::meta::is_pointer<int>::value);
    ASSERT_FALSE(zll::meta::is_pointer<int[3]>::value);
}
