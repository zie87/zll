/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/memory/address_of.hpp"

#include <utest.h>

// clang-format off
void test_fn0() {}
void test_fn1(int) {}
void test_fn2(int, int) {}
void test_fn3(int, int, int) {}
// clang-format on

UTEST(memory_address_of, scalar) {
    float* ptr = new float();
    float& ref = *ptr;

    ASSERT_TRUE(zll::addressof(ref) == ptr);
    delete ptr;
}

UTEST(memory_address_of, function) {
    ASSERT_TRUE(zll::addressof(test_fn0) == &test_fn0);
    ASSERT_TRUE(zll::addressof(test_fn1) == &test_fn1);
    ASSERT_TRUE(zll::addressof(test_fn2) == &test_fn2);
    ASSERT_TRUE(zll::addressof(test_fn3) == &test_fn3);
}

UTEST(memory_address_of, array) {
    {
        int arr[3]   = {17, 12, 32};
        int(*ptr)[3] = &arr;
        ASSERT_TRUE(zll::addressof(arr) == ptr);
    }
    {
        const char arr[3]   = {17, 12, 32};
        const char(*ptr)[3] = &arr;
        ASSERT_TRUE(zll::addressof(arr) == ptr);
    }
}
