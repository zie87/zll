
unit_tests_srcs = [
    'main.cpp',
]

unit_tests_inc_dir = include_directories('.')
unit_tests_exec = executable(
    'zll_unit_tests',
    unit_tests_srcs,
    include_directories: unit_tests_inc_dir,
    dependencies: [utest_dep, dis_dep],
    override_options: ['cpp_std=c++20', 'warning_level=3'],
)

test('zll-unit-tests', unit_tests_exec, suite: 'dis')
