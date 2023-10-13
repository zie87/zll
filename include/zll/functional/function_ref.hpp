/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef ZLL_FUNCTIONAL_FUNCTIONREF_HPP
#define ZLL_FUNCTIONAL_FUNCTIONREF_HPP

#include "zll/functional/detail/bound_entity_type.hpp"
#include "zll/functional/detail/fn_types.hpp"

#include "zll/memory/address_of.hpp"

#include "zll/meta/traits/enable_if.hpp"
#include "zll/meta/traits/is_object.hpp"
#include "zll/meta/traits/is_function.hpp"
#include "zll/meta/traits/remove_reference.hpp"

#include "zll/utils/nontype.hpp"

namespace zll {
namespace detail {

template <typename T, typename U>
struct fn_enable_if_object {
    typedef typename zll::meta::enable_if<zll::meta::is_object<T>::value, U>::type type;
};

template <typename T, typename U>
struct fn_enable_if_function {
    typedef typename zll::meta::enable_if<zll::meta::is_function<T>::value, U>::type type;
};

}  // namespace detail

template <typename SIG_T, typename = typename detail::fn_types<SIG_T>::type>
class function_ref;

template <typename SIG_T, typename R>
class function_ref<SIG_T, R()> {
    typedef detail::bound_entity_type entity_type;
    typedef R (*thunk_ptr_type)(entity_type);

public:
    typedef R (*signature_type)();

    template <typename F>
    explicit function_ref(
        const F& f, typename zll::meta::enable_if<!(zll::meta::is_member_pointer<F>::value ||
                                                    zll::is_nontype<typename zll::meta::remove_cvref<F>::type>::value),
                                                  void*>::type = NULL)
        : m_bound_entity(zll::addressof(f), detail::bound_entity_object()),
          m_thunk_ptr(function_ref::thunk_call<typename zll::meta::remove_reference<F>::type>) {}

    template <typename F>
    explicit function_ref(F* f, typename detail::fn_enable_if_function<F, void*>::type = NULL)
        : m_bound_entity(f, detail::bound_entity_function()), m_thunk_ptr(function_ref::thunk_fn_call<F>) {}

    template <signature_type VALUE>
    function_ref(zll::nontype_t<signature_type, VALUE>)
        : m_bound_entity(), m_thunk_ptr(function_ref::thunk_nontype_call<VALUE>) {}

    template <typename T, T VALUE, typename U>
    function_ref(zll::nontype_t<T, VALUE>, U& obj)
        : m_bound_entity(zll::addressof(obj), detail::bound_entity_object()),
          m_thunk_ptr(function_ref::thunk_member_call<T, VALUE, U>) {}

    R operator()() const { return m_thunk_ptr(m_bound_entity); }

private:
    template <typename T>
    static typename zll::meta::enable_if<!(zll::is_nontype<T>::value), R>::type thunk_call(entity_type entity) {
        T& obj = *detail::get<T>(entity);
        return obj();
    }

    template <typename F>
    static R thunk_fn_call(entity_type entity) {
        return detail::get<F>(entity)();
    }

    template <signature_type VALUE>
    static R thunk_nontype_call(entity_type) {
        return VALUE();
    }

    template <typename T, T VALUE, typename U>
    static R thunk_member_call(entity_type entity) {
        U& obj = *detail::get<U>(entity);
        return (obj.*VALUE)();
    }

    entity_type m_bound_entity;
    thunk_ptr_type m_thunk_ptr;
};

template <typename SIG_T, typename R, typename ARG1_T>
class function_ref<SIG_T, R(ARG1_T)> {
    typedef detail::bound_entity_type entity_type;
    typedef R (*thunk_ptr_type)(entity_type, ARG1_T);

public:
    typedef R (*signature_type)(ARG1_T);

    template <typename F>
    explicit function_ref(
        const F& f, typename zll::meta::enable_if<!(zll::meta::is_member_pointer<F>::value ||
                                                    zll::is_nontype<typename zll::meta::remove_cvref<F>::type>::value),
                                                  void*>::type = NULL)
        : m_bound_entity(zll::addressof(f), detail::bound_entity_object()),
          m_thunk_ptr(function_ref::thunk_call<typename zll::meta::remove_reference<F>::type>) {}

    template <typename F>
    explicit function_ref(F* f, typename detail::fn_enable_if_function<F, void*>::type = NULL)
        : m_bound_entity(f, detail::bound_entity_function()), m_thunk_ptr(function_ref::thunk_fn_call<F>) {}

    template <signature_type VALUE>
    function_ref(zll::nontype_t<signature_type, VALUE>)
        : m_bound_entity(), m_thunk_ptr(function_ref::thunk_nontype_call<VALUE>) {}

    template <typename T, T VALUE, typename U>
    function_ref(zll::nontype_t<T, VALUE>, U& obj)
        : m_bound_entity(zll::addressof(obj), detail::bound_entity_object()),
          m_thunk_ptr(function_ref::thunk_member_call<T, VALUE, U>) {}

    R operator()(ARG1_T arg) const { return m_thunk_ptr(m_bound_entity, arg); }

private:
    template <typename T>
    static typename zll::meta::enable_if<!(zll::is_nontype<T>::value), R>::type thunk_call(entity_type entity,
                                                                                           ARG1_T arg) {
        T& obj = *detail::get<T>(entity);
        return obj(arg);
    }

    template <typename F>
    static R thunk_fn_call(entity_type entity, ARG1_T arg) {
        return detail::get<F>(entity)(arg);
    }

    template <signature_type VALUE>
    static R thunk_nontype_call(entity_type, ARG1_T arg) {
        return VALUE(arg);
    }

    template <typename T, T VALUE, typename U>
    static R thunk_member_call(entity_type entity, ARG1_T arg) {
        U& obj = *detail::get<U>(entity);
        return (obj.*VALUE)(arg);
    }

    entity_type m_bound_entity;
    thunk_ptr_type m_thunk_ptr;
};

}  // namespace zll

#endif  // ZLL_FUNCTIONAL_FUNCTIONREF_HPP
