#include "zll/meta/is_same.hpp"

#include <utest.h>

struct test_dummy {};
struct test_child : test_dummy {};

UTEST(meta_is_same, compare_same) {
    ASSERT_TRUE((zll::meta::is_same<int, int>::value));
    ASSERT_TRUE((zll::meta::is_same<char, char>::value));
    ASSERT_TRUE((zll::meta::is_same<test_dummy, test_dummy>::value));
    ASSERT_TRUE((zll::meta::is_same<test_child, test_child>::value));
    ASSERT_TRUE((zll::meta::is_same<test_dummy&, test_dummy&>::value));
    ASSERT_TRUE((zll::meta::is_same<test_child&, test_child&>::value));
}

UTEST(meta_is_same, compare_not_same) {
    ASSERT_FALSE((zll::meta::is_same<int, char>::value));
    ASSERT_FALSE((zll::meta::is_same<char, short>::value));
    ASSERT_FALSE((zll::meta::is_same<test_dummy, test_child>::value));
    ASSERT_FALSE((zll::meta::is_same<test_child, int>::value));
    ASSERT_FALSE((zll::meta::is_same<test_dummy, test_dummy&>::value));
    ASSERT_FALSE((zll::meta::is_same<test_dummy*, test_child*>::value));
}
