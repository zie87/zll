/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/meta/type_identity.hpp"
#include "zll/meta/traits/is_same.hpp"

#include <utest.h>

template <typename T>
struct identity_check {
    static const bool value = zll::meta::is_same<typename zll::meta::type_identity<T>::type, T>::value;
};

UTEST(meta_type_identity, identity) {
    ASSERT_TRUE((identity_check<int>::value));
    ASSERT_TRUE((identity_check<const char*>::value));
    ASSERT_TRUE((identity_check<float*>::value));
}

template <typename T>
bool test_fn1(T a, T b) {
    return true;
}

template <typename T>
bool test_fn2(T a, typename zll::meta::type_identity<T>::type b) {
    return true;
}

UTEST(meta_type_identity, establish_non_deduced_context) {
    // ASSERT_TRUE( test_fn1(4.1, 1) ); // can not be deduced
    ASSERT_TRUE(test_fn2(4.1, 1));  // enforce to deduce
}
