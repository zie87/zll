#include "zll/meta/integral_constant.hpp"
#include "zll/debug/static_assert.hpp"

#include <utest.h>

UTEST(meta_integral_constant, int_constant) {
    typedef zll::meta::integral_constant<int, 2> two_t;

    const two_t two = two_t();
    ASSERT_EQ(two_t::value, 2);
    ASSERT_EQ(two(), 2);
    const int val = two;

    ASSERT_EQ(val, 2);
    ZLL_STATIC_ASSERT((two_t::value == 2));
}

UTEST(meta_integral_constant, bool_constant) {
    {
        const zll::meta::true_type true_v;
        ASSERT_TRUE((zll::meta::true_type::value));
        ASSERT_TRUE(true_v);
        ASSERT_TRUE(true_v());
        ZLL_STATIC_ASSERT((zll::meta::true_type::value));
    }
    {
        const zll::meta::false_type false_v;
        ASSERT_FALSE((zll::meta::false_type::value));
        ASSERT_FALSE(false_v);
        ASSERT_FALSE(false_v());
        ZLL_STATIC_ASSERT(!(zll::meta::false_type::value));
    }
}
