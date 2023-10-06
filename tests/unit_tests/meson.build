
unit_tests_srcs = [
    'meta/enable_if_tests.cpp',
    'meta/integral_constant_tests.cpp',
    'meta/is_class_tests.cpp',
    'meta/is_pointer_tests.cpp',
    'meta/is_same_tests.cpp',
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
