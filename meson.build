project(
    'zll',
    'cpp',
    version: '0.1',
    license: 'MPL-2.0',
    default_options: ['cpp_std=c++03', 'warning_level=3'],
)

inc_dir = include_directories('include')
dis_dep = declare_dependency(include_directories: inc_dir)

subdir('tests')
