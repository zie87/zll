#include "zll/meta/is_pointer.hpp"
#include "zll/meta/is_same.hpp"

#include <utest.h>

struct test_dummy {};

UTEST(meta_is_pointer, is_pointer) {
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
