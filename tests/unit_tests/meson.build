
unit_tests_srcs = [
    'memory/address_of_tests.cpp',
    
    'meta/enable_if_tests.cpp',
    'meta/integral_constant_tests.cpp',
    'meta/is_arithmetic_tests.cpp',
    'meta/is_array_tests.cpp',
    'meta/is_class_tests.cpp',
    'meta/is_enum_tests.cpp',
    'meta/is_floating_point_tests.cpp',
    'meta/is_integral_tests.cpp',
    'meta/is_member_pointer_tests.cpp',
    'meta/is_object_tests.cpp',
    'meta/is_pointer_tests.cpp',
    'meta/is_same_tests.cpp',
    'meta/is_scalar_tests.cpp',
    'meta/is_union_tests.cpp',
    'meta/remove_cv_tests.cpp',
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
