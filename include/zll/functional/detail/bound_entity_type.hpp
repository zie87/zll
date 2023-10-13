#ifndef ZLL_FUNCTIONAL_DETAIL_BOUNDENTITYTPE_HPP
#define ZLL_FUNCTIONAL_DETAIL_BOUNDENTITYTPE_HPP

#include "zll/meta/traits/enable_if.hpp"
#include "zll/meta/traits/is_const.hpp"
#include "zll/meta/traits/is_function.hpp"
#include "zll/meta/traits/is_object.hpp"

namespace zll {
namespace detail {

struct bound_entity_object {};
struct bound_entity_function {};

union bound_entity_type {
    void* object_ptr;
    const void* const_object_ptr;
    void (*fn_ptr)();

    bound_entity_type() : object_ptr(NULL) {}

    template <typename T>
    explicit bound_entity_type(T* ptr, bound_entity_object) : object_ptr(ptr) {}

    template <typename T>
    explicit bound_entity_type(const T* ptr, bound_entity_object) : const_object_ptr(ptr) {}

    template <typename T>
    explicit bound_entity_type(T* ptr, bound_entity_function) : fn_ptr(reinterpret_cast<void (*)()>(ptr)) {}
};

template <typename T>
static typename zll::meta::enable_if<zll::meta::is_object<T>::value && zll::meta::is_const<T>::value, T*>::type get(
    bound_entity_type entity) {
    return static_cast<T*>(entity.const_object_ptr);
}

template <typename T>
static typename zll::meta::enable_if<zll::meta::is_object<T>::value && !(zll::meta::is_const<T>::value), T*>::type get(
    bound_entity_type entity) {
    return static_cast<T*>(entity.object_ptr);
}

template <typename T>
static typename zll::meta::enable_if<!zll::meta::is_object<T>::value && (zll::meta::is_function<T>::value), T*>::type
get(bound_entity_type entity) {
    return reinterpret_cast<T*>(entity.fn_ptr);
}

}  // namespace detail
}  // namespace zll

#endif  // ZLL_FUNCTIONAL_DETAIL_BOUNDENTITYTPE_HPP
