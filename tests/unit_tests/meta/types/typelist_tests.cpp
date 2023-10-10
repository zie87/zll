/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/meta/types/typelist.hpp"
#include "zll/meta/traits/is_same.hpp"

#include <utest.h>

UTEST(meta_types_typelist, make_typelist) {
    {
        typedef zll::meta::make_typelist<>::type list_type;
        typedef zll::meta::nil_type expected_type;

        ASSERT_TRUE((zll::meta::is_typelist<list_type>::value));
        ASSERT_TRUE((zll::meta::is_same<list_type, expected_type>::value));
        ASSERT_EQ((zll::meta::size<list_type>::value), 0U);
        ASSERT_TRUE((zll::meta::empty<list_type>::value));
    }
    {
        typedef zll::meta::make_typelist<short>::type list_type;
        typedef zll::meta::typelist<short, zll::meta::nil_type> expected_type;

        ASSERT_TRUE((zll::meta::is_typelist<list_type>::value));
        ASSERT_TRUE((zll::meta::is_same<list_type, expected_type>::value));
        ASSERT_EQ((zll::meta::size<list_type>::value), 1U);
        ASSERT_FALSE((zll::meta::empty<list_type>::value));
    }
    {
        typedef zll::meta::make_typelist<int, char, float>::type list_type;
        typedef zll::meta::typelist<int, zll::meta::typelist<char, zll::meta::typelist<float, zll::meta::nil_type> > >
            expected_type;

        ASSERT_TRUE((zll::meta::is_typelist<list_type>::value));
        ASSERT_TRUE((zll::meta::is_same<list_type, expected_type>::value));
        ASSERT_EQ((zll::meta::size<list_type>::value), 3U);
        ASSERT_FALSE((zll::meta::empty<list_type>::value));
    }
}

UTEST(meta_types_typelist, type_at) {
    {
        typedef zll::meta::make_typelist<>::type list_type;
        typedef zll::meta::nil_type expected_type;
        typedef zll::meta::at<list_type, 0>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<char, short>::type list_type;

        {
            typedef zll::meta::at<list_type, 0>::type result_type;
            ASSERT_TRUE((zll::meta::is_same<result_type, char>::value));
        }
        {
            typedef zll::meta::at<list_type, 1>::type result_type;
            ASSERT_TRUE((zll::meta::is_same<result_type, short>::value));
        }
    }
    {
        typedef zll::meta::make_typelist<int, long, char, short>::type list_type;

        {
            typedef zll::meta::at<list_type, 3>::type result_type;
            ASSERT_TRUE((zll::meta::is_same<result_type, short>::value));
        }
        {
            typedef zll::meta::at<list_type, 1>::type result_type;
            ASSERT_TRUE((zll::meta::is_same<result_type, long>::value));
        }
    }
}

UTEST(meta_types_typelist, contains) {
    {
        typedef zll::meta::make_typelist<>::type list_type;

        ASSERT_FALSE((zll::meta::contains<list_type, char>::value));
    }
    {
        typedef zll::meta::make_typelist<char, short>::type list_type;

        ASSERT_TRUE((zll::meta::contains<list_type, char>::value));
        ASSERT_TRUE((zll::meta::contains<list_type, short>::value));
        ASSERT_FALSE((zll::meta::contains<list_type, double>::value));
    }
    {
        typedef zll::meta::make_typelist<int, char, short, double>::type list_type;

        ASSERT_TRUE((zll::meta::contains<list_type, int>::value));
        ASSERT_TRUE((zll::meta::contains<list_type, char>::value));
        ASSERT_TRUE((zll::meta::contains<list_type, short>::value));
        ASSERT_TRUE((zll::meta::contains<list_type, double>::value));
        ASSERT_FALSE((zll::meta::contains<list_type, long>::value));
    }
}

UTEST(meta_types_typelist, index_of) {
    {
        typedef zll::meta::make_typelist<char, short>::type list_type;

        ASSERT_EQ((zll::meta::index_of<list_type, char>::value), 0U);
        ASSERT_EQ((zll::meta::index_of<list_type, short>::value), 1U);
    }
    {
        typedef zll::meta::make_typelist<int, char, short, double>::type list_type;

        ASSERT_EQ((zll::meta::index_of<list_type, int>::value), 0U);
        ASSERT_EQ((zll::meta::index_of<list_type, char>::value), 1U);
        ASSERT_EQ((zll::meta::index_of<list_type, short>::value), 2U);
        ASSERT_EQ((zll::meta::index_of<list_type, double>::value), 3U);
    }
}

UTEST(meta_types_typelist, push_front) {
    {
        typedef zll::meta::make_typelist<>::type list_type;
        typedef zll::meta::nil_type expected_type;

        typedef zll::meta::push_front<list_type, zll::meta::nil_type>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<>::type list_type;
        typedef zll::meta::make_typelist<short>::type expected_type;

        typedef zll::meta::push_front<list_type, short>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<char, short>::type list_type;
        typedef zll::meta::make_typelist<int, char, short>::type expected_type;

        typedef zll::meta::push_front<list_type, int>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<int, char, short, long>::type list_type;
        typedef zll::meta::make_typelist<int, int, char, short, long>::type expected_type;

        typedef zll::meta::push_front<list_type, int>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        // push_front of a list will add the list as a node and not append the entries!
        typedef zll::meta::make_typelist<int>::type list_type;
        typedef zll::meta::make_typelist<list_type, int>::type expected_type;

        typedef zll::meta::push_front<list_type, list_type>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
}

UTEST(meta_types_typelist, push_back) {
    {
        typedef zll::meta::make_typelist<>::type list_type;
        typedef zll::meta::nil_type expected_type;

        typedef zll::meta::push_back<list_type, zll::meta::nil_type>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<>::type list_type;
        typedef zll::meta::make_typelist<char>::type expected_type;

        typedef zll::meta::push_back<list_type, char>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<char, short>::type list_type;
        typedef zll::meta::make_typelist<char, short, int>::type expected_type;

        typedef zll::meta::push_back<list_type, int>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<int, char, short, long>::type list_type;
        typedef zll::meta::make_typelist<int, char, short, long, int>::type expected_type;

        typedef zll::meta::push_back<list_type, int>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        // push_back of a list will add the list as a node and not append the entries!
        typedef zll::meta::make_typelist<int>::type list_type;
        typedef zll::meta::make_typelist<int, list_type>::type expected_type;

        typedef zll::meta::push_back<list_type, list_type>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
}

UTEST(meta_types_typelist, append) {
    {
        typedef zll::meta::make_typelist<>::type list_type;
        typedef zll::meta::nil_type expected_type;

        typedef zll::meta::append<list_type, zll::meta::nil_type>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<>::type list_type;
        typedef zll::meta::make_typelist<char>::type expected_type;

        typedef zll::meta::append<list_type, char>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<char, short>::type list_type;
        typedef zll::meta::make_typelist<char, short, int>::type expected_type;

        typedef zll::meta::append<list_type, int>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<int, char, short, long>::type list_type;
        typedef zll::meta::make_typelist<int, char, short, long, int>::type expected_type;

        typedef zll::meta::append<list_type, int>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<int, short>::type list_type;
        typedef zll::meta::make_typelist<int, short, int, short>::type expected_type;

        typedef zll::meta::append<list_type, list_type>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
}

UTEST(meta_types_typelist, remove) {
    {
        typedef zll::meta::make_typelist<>::type list_type;
        typedef zll::meta::nil_type expected_type;

        typedef zll::meta::remove<list_type, zll::meta::nil_type>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<>::type list_type;
        typedef zll::meta::make_typelist<>::type expected_type;

        typedef zll::meta::remove<list_type, char>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<short>::type list_type;
        typedef zll::meta::make_typelist<>::type expected_type;

        typedef zll::meta::remove<list_type, short>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<char, short>::type list_type;
        typedef zll::meta::make_typelist<short>::type expected_type;

        typedef zll::meta::remove<list_type, char>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<int, char, short, long, int>::type list_type;
        typedef zll::meta::make_typelist<char, short, long>::type expected_type;

        typedef zll::meta::remove<list_type, int>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
}

UTEST(meta_types_typelist, remove_first) {
    {
        typedef zll::meta::make_typelist<>::type list_type;
        typedef zll::meta::nil_type expected_type;

        typedef zll::meta::remove_first<list_type, zll::meta::nil_type>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<>::type list_type;
        typedef zll::meta::make_typelist<>::type expected_type;

        typedef zll::meta::remove_first<list_type, char>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<short>::type list_type;
        typedef zll::meta::make_typelist<>::type expected_type;

        typedef zll::meta::remove_first<list_type, short>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<char, short, char>::type list_type;
        typedef zll::meta::make_typelist<char, char>::type expected_type;

        typedef zll::meta::remove_first<list_type, short>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<int, char, short, long, int>::type list_type;
        typedef zll::meta::make_typelist<char, short, long, int>::type expected_type;

        typedef zll::meta::remove_first<list_type, int>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
}

UTEST(meta_types_typelist, replace) {
    {
        typedef zll::meta::make_typelist<>::type list_type;
        typedef zll::meta::nil_type expected_type;

        typedef zll::meta::replace<list_type, zll::meta::nil_type, char>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<short>::type list_type;
        typedef zll::meta::make_typelist<int>::type expected_type;

        typedef zll::meta::replace<list_type, short, int>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<char, short>::type list_type;
        typedef zll::meta::make_typelist<short, short>::type expected_type;

        typedef zll::meta::replace<list_type, char, short>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<int, char, short, long, int>::type list_type;
        typedef zll::meta::make_typelist<bool, char, short, long, bool>::type expected_type;

        typedef zll::meta::replace<list_type, int, bool>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
}

UTEST(meta_types_typelist, replace_first) {
    {
        typedef zll::meta::make_typelist<>::type list_type;
        typedef zll::meta::nil_type expected_type;

        typedef zll::meta::replace_first<list_type, zll::meta::nil_type, char>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<short>::type list_type;
        typedef zll::meta::make_typelist<int>::type expected_type;

        typedef zll::meta::replace_first<list_type, short, int>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<char, char, short>::type list_type;
        typedef zll::meta::make_typelist<short, char, short>::type expected_type;

        typedef zll::meta::replace_first<list_type, char, short>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::make_typelist<int, char, short, long, int>::type list_type;
        typedef zll::meta::make_typelist<bool, char, short, long, int>::type expected_type;

        typedef zll::meta::replace_first<list_type, int, bool>::type result_type;
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
}
