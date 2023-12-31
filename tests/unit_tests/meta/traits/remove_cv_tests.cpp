/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/meta/traits/remove_cv.hpp"
#include "zll/meta/traits/is_same.hpp"

#include <utest.h>

struct test_dummy {};
struct test_child : test_dummy {};

UTEST(meta_traits_remove_cv, remove_const) {
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_const<int>::type, int>::value));
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_const<const int>::type, int>::value));
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_const<volatile int>::type, volatile int>::value));
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_const<const volatile int>::type, volatile int>::value));
}

UTEST(meta_traits_remove_cv, remove_volatile) {
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_volatile<int>::type, int>::value));
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_volatile<const int>::type, const int>::value));
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_volatile<volatile int>::type, int>::value));
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_volatile<const volatile int>::type, const int>::value));
}

UTEST(meta_traits_remove_cv, remove_cv) {
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_cv<int>::type, int>::value));
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_cv<const int>::type, int>::value));
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_cv<volatile int>::type, int>::value));
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_cv<const volatile int>::type, int>::value));
}
UTEST(meta_traits_remove_cv, remove_cv_pointer) {
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_cv<int*>::type, int*>::value));
    
    // remove_cv should not work on pointers
    ASSERT_FALSE((zll::meta::is_same<zll::meta::remove_cv<const int*>::type, int*>::value));
    ASSERT_FALSE((zll::meta::is_same<zll::meta::remove_cv<volatile int*>::type, int*>::value));
    ASSERT_FALSE((zll::meta::is_same<zll::meta::remove_cv<const volatile int*>::type, int*>::value));
}
