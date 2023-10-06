/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/meta/is_integral.hpp"

#include <utest.h>

class test_class {};

UTEST(meta_is_integral, signed_types) {
    ASSERT_TRUE(zll::meta::is_integral<signed char>::value);
    ASSERT_TRUE(zll::meta::is_integral<const short>::value);
    ASSERT_TRUE(zll::meta::is_integral<volatile int>::value);
    ASSERT_TRUE(zll::meta::is_integral<const volatile long>::value);
}

UTEST(meta_is_integral, unsigned_types) {
    ASSERT_TRUE(zll::meta::is_integral<unsigned char>::value);
    ASSERT_TRUE(zll::meta::is_integral<const unsigned long>::value);
    ASSERT_TRUE(zll::meta::is_integral<volatile unsigned short>::value);
    ASSERT_TRUE(zll::meta::is_integral<const volatile unsigned int>::value);
}

UTEST(meta_is_integral, special_types) {
    ASSERT_TRUE(zll::meta::is_integral<bool>::value);
    ASSERT_TRUE(zll::meta::is_integral<char>::value);

    ASSERT_FALSE(zll::meta::is_integral<test_class>::value);
    ASSERT_FALSE(zll::meta::is_integral<int*>::value);
    ASSERT_FALSE(zll::meta::is_integral<float>::value);
}
