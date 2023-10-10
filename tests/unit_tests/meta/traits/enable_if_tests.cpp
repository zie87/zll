/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/meta/traits/enable_if.hpp"
#include "zll/meta/traits/is_same.hpp"
#include "zll/meta/traits/is_pointer.hpp"

#include <utest.h>

namespace test_types {
enum test_values { f = 0, i, p };
}

template <typename T>
typename zll::meta::enable_if<zll::meta::is_same<T, int>::value, test_types::test_values>::type test_function() {
    return test_types::i;
}

template <typename T>
typename zll::meta::enable_if<zll::meta::is_same<T, float>::value, test_types::test_values>::type test_function() {
    return test_types::f;
}

template <typename T>
typename zll::meta::enable_if<zll::meta::is_pointer<T>::value, test_types::test_values>::type test_function() {
    return test_types::p;
}

UTEST(meta_traits_enable_if, sfinae) {
    ASSERT_EQ(test_function<int>(), test_types::i);
    ASSERT_EQ(test_function<float>(), test_types::f);
    ASSERT_EQ(test_function<int*>(), test_types::p);
}
