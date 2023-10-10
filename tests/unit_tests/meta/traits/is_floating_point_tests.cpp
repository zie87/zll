/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/meta/traits/is_floating_point.hpp"

#include <utest.h>

class test_class {};

UTEST(meta_traits_is_floating_point, is_floating_point) {
    ASSERT_TRUE(zll::meta::is_floating_point<float>::value);
    ASSERT_TRUE(zll::meta::is_floating_point<const double>::value);
    ASSERT_TRUE(zll::meta::is_floating_point<volatile float>::value);
    ASSERT_TRUE(zll::meta::is_floating_point<const volatile double>::value);
    
    ASSERT_FALSE(zll::meta::is_floating_point<test_class>::value);
    ASSERT_FALSE(zll::meta::is_floating_point<float&>::value);
    ASSERT_FALSE(zll::meta::is_floating_point<double*>::value);
}


