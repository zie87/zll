/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/meta/traits/is_arithmetic.hpp"

#include <utest.h>

class test_class {};

UTEST(meta_traits_is_arithmetic, is_arithmetic) {
    ASSERT_TRUE(zll::meta::is_arithmetic<bool>::value);
    ASSERT_TRUE(zll::meta::is_arithmetic<char>::value);
    ASSERT_TRUE(zll::meta::is_arithmetic<const int>::value);
    ASSERT_TRUE(zll::meta::is_arithmetic<float>::value);
    ASSERT_TRUE(zll::meta::is_arithmetic<volatile float>::value);
    ASSERT_TRUE(zll::meta::is_arithmetic<const volatile double>::value);
}

UTEST(meta_traits_is_arithmetic, is_not_arithmetic) {
    ASSERT_FALSE(zll::meta::is_arithmetic<test_class>::value);
    ASSERT_FALSE(zll::meta::is_arithmetic<float&>::value);
    ASSERT_FALSE(zll::meta::is_arithmetic<double*>::value);
    ASSERT_FALSE(zll::meta::is_arithmetic<const char*>::value);
    ASSERT_FALSE(zll::meta::is_arithmetic<volatile short&>::value);
}
