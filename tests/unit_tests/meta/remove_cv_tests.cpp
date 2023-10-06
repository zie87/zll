#include "zll/meta/remove_cv.hpp"
#include "zll/meta/is_same.hpp"

#include <utest.h>

struct test_dummy {};
struct test_child : test_dummy {};

UTEST(meta_remove_cv, remove_const) {
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_const<int>::type, int>::value));
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_const<const int>::type, int>::value));
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_const<volatile int>::type, volatile int>::value));
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_const<const volatile int>::type, volatile int>::value));
}

UTEST(meta_remove_cv, remove_volatile) {
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_volatile<int>::type, int>::value));
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_volatile<const int>::type, const int>::value));
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_volatile<volatile int>::type, int>::value));
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_volatile<const volatile int>::type, const int>::value));
}

UTEST(meta_remove_cv, remove_cv) {
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_cv<int>::type, int>::value));
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_cv<const int>::type, int>::value));
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_cv<volatile int>::type, int>::value));
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_cv<const volatile int>::type, int>::value));
}
UTEST(meta_remove_cv, remove_cv_pointer) {
    ASSERT_TRUE((zll::meta::is_same<zll::meta::remove_cv<int*>::type, int*>::value));
    
    // remove_cv does not work on pointers
    ASSERT_FALSE((zll::meta::is_same<zll::meta::remove_cv<const int*>::type, int*>::value));
    ASSERT_FALSE((zll::meta::is_same<zll::meta::remove_cv<volatile int*>::type, int*>::value));
    ASSERT_FALSE((zll::meta::is_same<zll::meta::remove_cv<const volatile int*>::type, int*>::value));
}
