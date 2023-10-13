/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include <zll/functional/function_ref.hpp>
#include <zll/utils/typeof_macro.hpp>

#include <utest.h>

struct functor1 {
    int operator()() const { return 17; }
};

int free_fun1() { return 42; }

struct static_fun {
    static int fun() { return 15; }
};

struct member_fun {
    int fun() const { return 3; }
};

UTEST(functional_function_ref, no_parameter) {
    {
        functor1 fun;
        zll::function_ref<int() const> fn_ref(fun);

        ASSERT_EQ(fn_ref(), 17);
    }
    {
        const functor1 fun;
        zll::function_ref<int() const> fn_ref(fun);

        ASSERT_EQ(fn_ref(), 17);
    }
    {
        zll::function_ref<int()> fn_ref(free_fun1);
        ASSERT_EQ(fn_ref(), 42);
    }
    {
        zll::function_ref<int()> fn_ref(&free_fun1);
        ASSERT_EQ(fn_ref(), 42);
    }
    {
        zll::nontype_t<int (*)(), free_fun1> nontype;
        zll::function_ref<int()> fn_ref(nontype);
        ASSERT_EQ(fn_ref(), 42);
    }
    {
        zll::nontype_t<int (*)(), static_fun::fun> nontype;
        zll::function_ref<int()> fn_ref(nontype);
        ASSERT_EQ(fn_ref(), 15);
    }
    {
        zll::nontype_t<ZLL_TYPE_OF(&member_fun::fun), &member_fun::fun> nontype;

        member_fun obj;
        zll::function_ref<int()> fn_ref(nontype, obj);
        ASSERT_EQ(fn_ref(), 3);
    }
}

struct functor2 {
    int operator()(int a) const { return a; }
};

int free_fun2(char) { return 42; }

struct static_fun2 {
    static int fun(int a) { return a; }
};

struct member_fun2 {
    int fun(int a) const { return a; }
};

UTEST(functional_function_ref, one_parameter) {
    {
        functor2 fun;
        zll::function_ref<int(int) const> fn_ref(fun);

        ASSERT_EQ(fn_ref(5), 5);
    }
    {
        const functor2 fun;
        zll::function_ref<int(int) const> fn_ref(fun);

        ASSERT_EQ(fn_ref(8), 8);
    }
    {
        zll::function_ref<int(char)> fn_ref(free_fun2);
        ASSERT_EQ(fn_ref('a'), 42);
    }
    {
        zll::function_ref<int(char)> fn_ref(&free_fun2);
        ASSERT_EQ(fn_ref('f'), 42);
    }
    {
        zll::nontype_t<int (*)(char), free_fun2> nontype;
        zll::function_ref<int(char)> fn_ref(nontype);
        ASSERT_EQ(fn_ref('g'), 42);
    }
    {
        zll::nontype_t<int (*)(int), static_fun2::fun> nontype;
        zll::function_ref<int(int)> fn_ref(nontype);
        ASSERT_EQ(fn_ref(11), 11);
    }
    {
        zll::nontype_t<ZLL_TYPE_OF(&member_fun2::fun), &member_fun2::fun> nontype;

        member_fun2 obj;
        zll::function_ref<int(int)> fn_ref(nontype, obj);
        ASSERT_EQ(fn_ref(-12), -12);
    }
}
