#include <zll/meta/traits/is_function.hpp>
#include <zll/utils/typeof_macro.hpp>

#include <utest.h>

struct test_struct {
    int fun() const;
};

int test_function();

template <typename T>
struct test_trait {};
template <typename T, typename U>
struct test_trait<U T::*> {
    typedef U member_type;
};

UTEST(meta_traits_is_function, is_function) {
    ASSERT_TRUE((zll::meta::is_function<int(int)>::value));
    ASSERT_TRUE((zll::meta::is_function<ZLL_TYPE_OF(test_function)>::value));

    typedef test_trait<ZLL_TYPE_OF(&test_struct::fun)>::member_type fun_type;
    ASSERT_TRUE((zll::meta::is_function<fun_type>::value));
}

UTEST(meta_traits_is_function, is_not_function) {
    ASSERT_FALSE((zll::meta::is_function<int>::value));
    ASSERT_FALSE((zll::meta::is_function<test_struct>::value));
}

