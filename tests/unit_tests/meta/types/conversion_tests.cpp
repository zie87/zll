/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "zll/meta/types/conversion.hpp"
#include "zll/meta/types/typelist.hpp"
#include "zll/meta/types/typevector.hpp"
#include "zll/meta/traits/is_same.hpp"

#include <utest.h>

UTEST(meta_types_conversion, to_typelist) {
    {
        typedef zll::meta::typevector<> vector_type;
        typedef zll::meta::nil_type expected_type;

        typedef zll::meta::to_typelist<vector_type>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<int, short> vector_type;
        typedef zll::meta::make_typelist<int, short>::type expected_type;

        typedef zll::meta::to_typelist<vector_type>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
    {
        typedef zll::meta::typevector<int, short, bool, float, short, int, char> vector_type;
        typedef zll::meta::make_typelist<int, short, bool, float, short, int, char>::type expected_type;

        typedef zll::meta::to_typelist<vector_type>::type result_type;

        ASSERT_TRUE((zll::meta::is_same<result_type, expected_type>::value));
    }
}
