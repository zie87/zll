
unit_tests_srcs = [
    'functional/function_ref_tests.cpp',
    
    'memory/address_of_tests.cpp',
    
    'meta/integral_constant_tests.cpp',
    'meta/type_identity_tests.cpp',

    'meta/traits/enable_if_tests.cpp',
    'meta/traits/is_arithmetic_tests.cpp',
    'meta/traits/is_array_tests.cpp',
    'meta/traits/is_class_tests.cpp',
    'meta/traits/is_const_tests.cpp',
    'meta/traits/is_enum_tests.cpp',
    'meta/traits/is_floating_point_tests.cpp',
    'meta/traits/is_function_tests.cpp',
    'meta/traits/is_integral_tests.cpp',
    'meta/traits/is_member_pointer_tests.cpp',
    'meta/traits/is_object_tests.cpp',
    'meta/traits/is_pointer_tests.cpp',
    'meta/traits/is_same_tests.cpp',
    'meta/traits/is_scalar_tests.cpp',
    'meta/traits/is_union_tests.cpp',
    'meta/traits/remove_cv_tests.cpp',
    
    'meta/types/conversion_tests.cpp',
    'meta/types/typelist_tests.cpp',
    'meta/types/typevector_tests.cpp',
    
    'numeric/ratio_tests.cpp',
    
    'main.cpp',
]

unit_tests_inc_dir = include_directories('.')
unit_tests_exec = executable(
    'zll_unit_tests',
    unit_tests_srcs,
    include_directories: unit_tests_inc_dir,
    dependencies: [utest_dep, dis_dep],
)

test('zll-unit-tests', unit_tests_exec, suite: 'zll')
