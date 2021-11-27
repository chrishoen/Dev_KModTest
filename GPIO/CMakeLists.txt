cmake_minimum_required (VERSION 3.8)

project (GPIO CXX)
my_find_src_files (src_files GPIO)
add_executable (GPIO ${src_files})
my_add_compile_options (GPIO)
my_add_pch (GPIO)

my_inc_import_RisLib(GPIO)
my_inc_import_CommonLib(GPIO)
my_inc_import_GPIO(GPIO)

my_lib_import_CommonLib(GPIO)
my_lib_import_GPIO(GPIO)
my_lib_import_RisLib(GPIO)

