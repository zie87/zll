/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/meta/is_class.hpp"

#include <utest.h>

struct test_struct {};
class test_class {};

union test_union {
    class clazz {};
};

UTEST(meta_is_class, is_class) {
    ASSERT_TRUE(zll::meta::is_class<test_class>::value);
    ASSERT_TRUE(zll::meta::is_class<const test_class>::value);
    ASSERT_TRUE(zll::meta::is_class<test_struct>::value);
    ASSERT_TRUE(zll::meta::is_class<const test_struct>::value);
    
    ASSERT_FALSE(zll::meta::is_class<test_struct*>::value);
    ASSERT_FALSE(zll::meta::is_class<test_struct&>::value);
    ASSERT_FALSE(zll::meta::is_class<test_union>::value);
    
    ASSERT_TRUE(zll::meta::is_class<test_union::clazz>::value);
}
