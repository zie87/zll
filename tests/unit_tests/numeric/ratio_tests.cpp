/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/numeric/ratio.hpp"
#include "zll/meta/is_same.hpp"

#include <utest.h>

UTEST(numeric_ratio, normalization) {
    {
        typedef zll::ratio<-0, 6> test_type;

        ASSERT_EQ(test_type::num, 0);
        ASSERT_EQ(test_type::den, 1);

        typedef test_type::type ret_type;
        ASSERT_TRUE((zll::meta::is_same<ret_type, zll::ratio<0, 1> >::value));
    }
    {
        typedef zll::ratio<4, 6> test_type;

        ASSERT_EQ(test_type::num, 2);
        ASSERT_EQ(test_type::den, 3);

        typedef test_type::type ret_type;
        ASSERT_TRUE((zll::meta::is_same<ret_type, zll::ratio<2, 3> >::value));
    }
    {
        typedef zll::ratio<2, -7> test_type;

        ASSERT_EQ(test_type::num, -2);
        ASSERT_EQ(test_type::den, 7);

        typedef test_type::type ret_type;
        ASSERT_TRUE((zll::meta::is_same<ret_type, zll::ratio<-2, 7> >::value));
    }
    {
        typedef zll::ratio<-200, -10> test_type;

        ASSERT_EQ(test_type::num, 20);
        ASSERT_EQ(test_type::den, 1);

        typedef test_type::type ret_type;
        ASSERT_TRUE((zll::meta::is_same<ret_type, zll::ratio<20, 1> >::value));
    }
}

UTEST(numeric_ratio, comparsion_equal) {
    {
        typedef zll::ratio<5, 25> lhs_type;
        typedef zll::ratio<1, 5> rhs_type;

        ASSERT_TRUE((zll::ratio_equal<lhs_type, rhs_type>::value));
        ASSERT_FALSE((zll::ratio_not_equal<lhs_type, rhs_type>::value));
    }
    {
        typedef zll::ratio<3, -6> lhs_type;
        typedef zll::ratio<-1, 2> rhs_type;

        ASSERT_TRUE((zll::ratio_equal<lhs_type, rhs_type>::value));
        ASSERT_FALSE((zll::ratio_not_equal<lhs_type, rhs_type>::value));
    }
    {
        typedef zll::ratio<-3, -6> lhs_type;
        typedef zll::ratio<-1, 2> rhs_type;

        ASSERT_FALSE((zll::ratio_equal<lhs_type, rhs_type>::value));
        ASSERT_TRUE((zll::ratio_not_equal<lhs_type, rhs_type>::value));
    }
    {
        typedef zll::ratio<-2, 1> lhs_type;
        typedef zll::ratio<-1, 2> rhs_type;

        ASSERT_FALSE((zll::ratio_equal<lhs_type, rhs_type>::value));
        ASSERT_TRUE((zll::ratio_not_equal<lhs_type, rhs_type>::value));
    }
}

UTEST(numeric_ratio, comparsion_less) {
    {
        typedef zll::ratio<-1, 1> lhs_type;
        typedef zll::ratio<1, 1> rhs_type;

        ASSERT_TRUE((zll::ratio_less<lhs_type, rhs_type>::value));
        ASSERT_TRUE((zll::ratio_less_equal<lhs_type, rhs_type>::value));
    }
    {
        typedef zll::ratio<5, 25> lhs_type;
        typedef zll::ratio<1, 5> rhs_type;

        ASSERT_FALSE((zll::ratio_less<lhs_type, rhs_type>::value));
        ASSERT_TRUE((zll::ratio_less_equal<lhs_type, rhs_type>::value));
    }
    {
        typedef zll::ratio<-1, 3> lhs_type;
        typedef zll::ratio<-1, 3> rhs_type;

        ASSERT_FALSE((zll::ratio_less<lhs_type, rhs_type>::value));
        ASSERT_TRUE((zll::ratio_less_equal<lhs_type, rhs_type>::value));
    }
    {
        typedef zll::ratio<641981, 1339063L> lhs_type;
        typedef zll::ratio<1291640, 2694141L> rhs_type;

        ASSERT_FALSE((zll::ratio_less<lhs_type, rhs_type>::value));
        ASSERT_FALSE((zll::ratio_less_equal<lhs_type, rhs_type>::value));
    }
    {
        typedef zll::ratio<1291640, 2694141L> lhs_type;
        typedef zll::ratio<641981, 1339063L> rhs_type;

        ASSERT_TRUE((zll::ratio_less<lhs_type, rhs_type>::value));
        ASSERT_TRUE((zll::ratio_less_equal<lhs_type, rhs_type>::value));
    }
}

UTEST(numeric_ratio, comparsion_greater) {
    {
        typedef zll::ratio<1, 3> lhs_type;
        typedef zll::ratio<-1, 2> rhs_type;

        ASSERT_TRUE((zll::ratio_greater<lhs_type, rhs_type>::value));
        ASSERT_TRUE((zll::ratio_greater_equal<lhs_type, rhs_type>::value));
    }
    {
        typedef zll::ratio<34523, 3> lhs_type;
        typedef zll::ratio<34523, 2> rhs_type;

        ASSERT_FALSE((zll::ratio_greater<lhs_type, rhs_type>::value));
        ASSERT_FALSE((zll::ratio_greater_equal<lhs_type, rhs_type>::value));
    }
    {
        typedef zll::ratio<641981, 1339063L> lhs_type;
        typedef zll::ratio<1291640, 2694141L> rhs_type;

        ASSERT_TRUE((zll::ratio_greater<lhs_type, rhs_type>::value));
        ASSERT_TRUE((zll::ratio_greater_equal<lhs_type, rhs_type>::value));
    }
    {
        typedef zll::ratio<1291640, 2694141L> lhs_type;
        typedef zll::ratio<1291640, 2694141L> rhs_type;

        ASSERT_FALSE((zll::ratio_greater<lhs_type, rhs_type>::value));
        ASSERT_TRUE((zll::ratio_greater_equal<lhs_type, rhs_type>::value));
    }
}

UTEST(numeric_ratio, arithmetic_add) {
    {
        typedef zll::ratio<1, 3> lhs_type;
        typedef zll::ratio<1, 2> rhs_type;

        typedef zll::ratio_add<lhs_type, rhs_type>::type result_type;

        ASSERT_EQ(result_type::num, 5);
        ASSERT_EQ(result_type::den, 6);
    }
    {
        typedef zll::ratio<2, 3> lhs_type;
        typedef zll::ratio<4, 3> rhs_type;

        typedef zll::ratio_add<lhs_type, rhs_type>::type result_type;

        ASSERT_EQ(result_type::num, 2);
        ASSERT_EQ(result_type::den, 1);
    }
    {
        typedef zll::ratio<-2, 3> lhs_type;
        typedef zll::ratio<4, 3> rhs_type;

        typedef zll::ratio_add<lhs_type, rhs_type>::type result_type;

        ASSERT_EQ(result_type::num, 2);
        ASSERT_EQ(result_type::den, 3);
    }
    {
        typedef zll::ratio<1, 5> lhs_type;
        typedef zll::ratio<-4, 3> rhs_type;

        typedef zll::ratio_add<lhs_type, rhs_type>::type result_type;

        ASSERT_EQ(result_type::num, -17);
        ASSERT_EQ(result_type::den, 15);
    }
}

UTEST(numeric_ratio, arithmetic_subtract) {
    {
        typedef zll::ratio<1, 3> lhs_type;
        typedef zll::ratio<1, 2> rhs_type;

        typedef zll::ratio_subtract<lhs_type, rhs_type>::type result_type;

        ASSERT_EQ(result_type::num, -1);
        ASSERT_EQ(result_type::den, 6);
    }
    {
        typedef zll::ratio<0, 3> lhs_type;
        typedef zll::ratio<0, 2> rhs_type;

        typedef zll::ratio_subtract<lhs_type, rhs_type>::type result_type;

        ASSERT_EQ(result_type::num, 0);
        ASSERT_EQ(result_type::den, 1);
    }
    {
        typedef zll::ratio<0, 1> lhs_type;
        typedef zll::ratio<1, 1> rhs_type;

        typedef zll::ratio_subtract<lhs_type, rhs_type>::type result_type;

        ASSERT_EQ(result_type::num, -1);
        ASSERT_EQ(result_type::den, 1);
    }
    {
        typedef zll::ratio<1, 1> lhs_type;
        typedef zll::ratio<0, 1> rhs_type;

        typedef zll::ratio_subtract<lhs_type, rhs_type>::type result_type;

        ASSERT_EQ(result_type::num, 1);
        ASSERT_EQ(result_type::den, 1);
    }
}

UTEST(numeric_ratio, arithmetic_multiply) {
    {
        typedef zll::ratio<1, 3> lhs_type;
        typedef zll::ratio<1, 2> rhs_type;

        typedef zll::ratio_multiply<lhs_type, rhs_type>::type result_type;

        ASSERT_EQ(result_type::num, 1);
        ASSERT_EQ(result_type::den, 6);
    }
    {
        typedef zll::ratio<5, 3> lhs_type;
        typedef zll::ratio<3, 2> rhs_type;

        typedef zll::ratio_multiply<lhs_type, rhs_type>::type result_type;

        ASSERT_EQ(result_type::num, 5);
        ASSERT_EQ(result_type::den, 2);
    }
    {
        typedef zll::ratio<-12, 8> lhs_type;
        typedef zll::ratio<17, 9> rhs_type;

        typedef zll::ratio_multiply<lhs_type, rhs_type>::type result_type;

        ASSERT_EQ(result_type::num, -17);
        ASSERT_EQ(result_type::den, 6);
    }
    {
        typedef zll::ratio<-3, 2> lhs_type;
        typedef zll::ratio<0, 9> rhs_type;

        typedef zll::ratio_multiply<lhs_type, rhs_type>::type result_type;

        ASSERT_EQ(result_type::num, 0);
        ASSERT_EQ(result_type::den, 1);
    }
}

UTEST(numeric_ratio, arithmetic_divide) {
    {
        typedef zll::ratio<-3, 1> lhs_type;
        typedef zll::ratio<2, 1> rhs_type;

        typedef zll::ratio_divide<lhs_type, rhs_type>::type result_type;

        ASSERT_EQ(result_type::num, -3);
        ASSERT_EQ(result_type::den, 2);
    }
    {
        typedef zll::ratio<1, 6> lhs_type;
        typedef zll::ratio<-5, 8> rhs_type;

        typedef zll::ratio_divide<lhs_type, rhs_type>::type result_type;

        ASSERT_EQ(result_type::num, -4);
        ASSERT_EQ(result_type::den, 15);
    }
}
