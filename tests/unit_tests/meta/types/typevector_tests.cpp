/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/meta/types/typevector.hpp"
#include "zll/meta/traits/is_same.hpp"

#include <utest.h>

UTEST(meta_types_typevector, make_typevector) {
    {
        typedef zll::meta::typevector<> vector_type;

        ASSERT_TRUE((zll::meta::is_typevector<vector_type>::value));
        ASSERT_EQ((zll::meta::size<vector_type>::value), 0U);
        ASSERT_TRUE((zll::meta::empty<vector_type>::value));
    }
    {
        typedef zll::meta::typevector<int> vector_type;

        ASSERT_TRUE((zll::meta::is_typevector<vector_type>::value));
        ASSERT_EQ((zll::meta::size<vector_type>::value), 1U);
        ASSERT_FALSE((zll::meta::empty<vector_type>::value));
    }
    {
        typedef zll::meta::typevector<int, short> vector_type;

        ASSERT_TRUE((zll::meta::is_typevector<vector_type>::value));
        ASSERT_EQ((zll::meta::size<vector_type>::value), 2U);
        ASSERT_FALSE((zll::meta::empty<vector_type>::value));
    }
    {
        typedef zll::meta::typevector<char, int, int, short> vector_type;

        ASSERT_TRUE((zll::meta::is_typevector<vector_type>::value));
        ASSERT_EQ((zll::meta::size<vector_type>::value), 4U);
        ASSERT_FALSE((zll::meta::empty<vector_type>::value));
    }
    {
        // clang-format off
        typedef zll::meta::typevector<char, int, int, short, long, 
                                      char, int, int, short, long, 
                                      char, int, int, short, long, 
                                      char, int, int, short, long>
            vector_type;
        // clang-format on

        ASSERT_TRUE((zll::meta::is_typevector<vector_type>::value));
        ASSERT_EQ((zll::meta::size<vector_type>::value), 20U);
        ASSERT_FALSE((zll::meta::empty<vector_type>::value));
    }
}

UTEST(meta_types_typevector, type_at) {
    {
        typedef zll::meta::typevector<char> vector_type;
        typedef char expected_type;
        typedef zll::meta::at<vector_type, 0>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<char, short> vector_type;
        typedef short expected_type;
        typedef zll::meta::at<vector_type, 1>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        // clang-format off
        typedef zll::meta::typevector<char, short, int, float, double, long, 
                                      char, short, int, float, double, long,
                                      char, short, int, float, double, long>
            vector_type;
        // clang-format on
        {
            typedef long expected_type;
            typedef zll::meta::at<vector_type, 5>::type result_type;

            ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
        }
        {
            typedef char expected_type;
            typedef zll::meta::at<vector_type, 12>::type result_type;

            ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
        }
        {
            typedef long expected_type;
            typedef zll::meta::at<vector_type, 17>::type result_type;

            ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
        }
    }
}

UTEST(meta_types_typevector, contains) {
    {
        typedef zll::meta::typevector<char> vector_type;

        ASSERT_TRUE((zll::meta::contains<vector_type, char>::value));
        ASSERT_FALSE((zll::meta::contains<vector_type, short>::value));
    }
    {
        typedef zll::meta::typevector<char, short, long, int> vector_type;

        ASSERT_TRUE((zll::meta::contains<vector_type, char>::value));
        ASSERT_TRUE((zll::meta::contains<vector_type, short>::value));
        ASSERT_TRUE((zll::meta::contains<vector_type, long>::value));
        ASSERT_TRUE((zll::meta::contains<vector_type, int>::value));
        ASSERT_FALSE((zll::meta::contains<vector_type, bool>::value));
    }
}

UTEST(meta_types_typevector, index_of) {
    {
        typedef zll::meta::typevector<char> vector_type;

        ASSERT_EQ((zll::meta::index_of<vector_type, char>::value), 0U);
    }
    {
        typedef zll::meta::typevector<char, float, float, int, long, bool, int, short> vector_type;

        ASSERT_EQ((zll::meta::index_of<vector_type, char>::value), 0U);
        ASSERT_EQ((zll::meta::index_of<vector_type, float>::value), 1U);
        ASSERT_EQ((zll::meta::index_of<vector_type, int>::value), 3U);
        ASSERT_EQ((zll::meta::index_of<vector_type, long>::value), 4U);
        ASSERT_EQ((zll::meta::index_of<vector_type, bool>::value), 5U);
        ASSERT_EQ((zll::meta::index_of<vector_type, short>::value), 7U);
    }
}

UTEST(meta_types_typevector, push_back) {
    {
        typedef zll::meta::typevector<> vector_type;
        typedef zll::meta::typevector<short> expected_type;
        typedef zll::meta::push_back<vector_type, short>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short> vector_type;
        typedef zll::meta::typevector<short, int> expected_type;
        typedef zll::meta::push_back<vector_type, int>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short, int> vector_type;
        typedef zll::meta::typevector<short, int, long> expected_type;
        typedef zll::meta::push_back<vector_type, long>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short, int, long> vector_type;
        typedef zll::meta::typevector<short, int, long, bool> expected_type;
        typedef zll::meta::push_back<vector_type, bool>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short, int, long, bool> vector_type;
        typedef zll::meta::typevector<short, int, long, bool, char> expected_type;
        typedef zll::meta::push_back<vector_type, char>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short, int, long, bool, char, short, int, long, bool, char, short, int, long,
                                      bool, char, short, int, long, bool>
            vector_type;
        typedef zll::meta::typevector<short, int, long, bool, char, short, int, long, bool, char, short, int, long,
                                      bool, char, short, int, long, bool, char>
            expected_type;
        typedef zll::meta::push_back<vector_type, char>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
}

UTEST(meta_types_typevector, push_front) {
    {
        typedef zll::meta::typevector<> vector_type;
        typedef zll::meta::typevector<short> expected_type;
        typedef zll::meta::push_front<vector_type, short>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short> vector_type;
        typedef zll::meta::typevector<int, short> expected_type;
        typedef zll::meta::push_front<vector_type, int>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short, int> vector_type;
        typedef zll::meta::typevector<long, short, int> expected_type;
        typedef zll::meta::push_front<vector_type, long>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short, int, long> vector_type;
        typedef zll::meta::typevector<bool, short, int, long> expected_type;
        typedef zll::meta::push_front<vector_type, bool>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short, int, long, bool> vector_type;
        typedef zll::meta::typevector<char, short, int, long, bool> expected_type;
        typedef zll::meta::push_front<vector_type, char>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short, int, long, bool, char, short, int, long, bool, char, short, int, long,
                                      bool, char, short, int, long, bool>
            vector_type;
        typedef zll::meta::typevector<char, short, int, long, bool, char, short, int, long, bool, char, short, int,
                                      long, bool, char, short, int, long, bool>
            expected_type;
        typedef zll::meta::push_front<vector_type, char>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
}

UTEST(meta_types_typevector, append) {
    {
        typedef zll::meta::typevector<> vector_type;
        typedef zll::meta::typevector<short> expected_type;
        typedef zll::meta::append<vector_type, short>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short> vector_type;
        typedef zll::meta::typevector<short, int> expected_type;
        typedef zll::meta::append<vector_type, int>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short, int> vector_type;
        typedef zll::meta::typevector<short, int, double, float, char> expected_type;
        typedef zll::meta::append<vector_type, zll::meta::typevector<double, float, char> >::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short, int, long, bool, char, short, int, long, bool, char, short, int, long,
                                      bool, char, short, int, long, bool>
            vector_type;
        typedef zll::meta::typevector<short, int, long, bool, char, short, int, long, bool, char, short, int, long,
                                      bool, char, short, int, long, bool, char>
            expected_type;
        typedef zll::meta::append<vector_type, char>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short, int, long, bool, char, short, int, long, bool, char, short, int, long,
                                      bool, char, short, int>
            vector_type;
        typedef zll::meta::typevector<short, int, long, bool, char, short, int, long, bool, char, short, int, long,
                                      bool, char, short, int, double, float, char>
            expected_type;
        typedef zll::meta::append<vector_type, zll::meta::typevector<double, float, char> >::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
}

UTEST(meta_types_typevector, remove) {
    {
        typedef zll::meta::typevector<> vector_type;
        typedef zll::meta::typevector<> expected_type;
        typedef zll::meta::remove<vector_type, short>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short> vector_type;
        typedef zll::meta::typevector<short> expected_type;
        typedef zll::meta::remove<vector_type, int>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short, int, short, int, char> vector_type;
        typedef zll::meta::typevector<short, short, char> expected_type;
        typedef zll::meta::remove<vector_type, int>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
}

UTEST(meta_types_typevector, remove_first) {
    {
        typedef zll::meta::typevector<> vector_type;
        typedef zll::meta::typevector<> expected_type;
        typedef zll::meta::remove_first<vector_type, short>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short> vector_type;
        typedef zll::meta::typevector<short> expected_type;
        typedef zll::meta::remove_first<vector_type, int>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short, int, short, int, char> vector_type;
        typedef zll::meta::typevector<short, short, int, char> expected_type;
        typedef zll::meta::remove_first<vector_type, int>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
}

UTEST(meta_types_typevector, replace) {
    {
        typedef zll::meta::typevector<> vector_type;
        typedef zll::meta::typevector<> expected_type;
        typedef zll::meta::replace<vector_type, short, int>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short> vector_type;
        typedef zll::meta::typevector<short> expected_type;
        typedef zll::meta::replace<vector_type, int, short>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short, int, short, int, char> vector_type;
        typedef zll::meta::typevector<short, bool, short, bool, char> expected_type;
        typedef zll::meta::replace<vector_type, int, bool>::type result_type;
        
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<int, int, int, int, int, int, int> vector_type;
        typedef zll::meta::typevector<bool, bool, bool, bool, bool, bool, bool> expected_type;
        typedef zll::meta::replace<vector_type, int, bool>::type result_type;
        
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
}

UTEST(meta_types_typevector, replace_first) {
    {
        typedef zll::meta::typevector<> vector_type;
        typedef zll::meta::typevector<> expected_type;
        typedef zll::meta::replace_first<vector_type, short, int>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short> vector_type;
        typedef zll::meta::typevector<short> expected_type;
        typedef zll::meta::replace_first<vector_type, int, short>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<short, int, short, int, char> vector_type;
        typedef zll::meta::typevector<short, bool, short, int, char> expected_type;
        typedef zll::meta::replace_first<vector_type, int, bool>::type result_type;
        
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<int, int, int, int, int, int, int> vector_type;
        typedef zll::meta::typevector<bool, int, int, int, int, int, int> expected_type;
        typedef zll::meta::replace_first<vector_type, int, bool>::type result_type;
        
        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
}
