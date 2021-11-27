cmake_minimum_required (VERSION 3.8)

project (GPIO CXX)
my_find_src_files (src_files GPIO)
add_executable (GPIO ${src_files})
my_add_compile_options (GPIO)
my_add_pch (GPIO)

my_inc_import_RisLib(GPIO)
my_inc_import_CommonLib(GPIO)

my_lib_import_RisLib(GPIO)
my_lib_import_CommonLib(GPIO)
my_lib_import_GPIO(GPIO)

if(NOT CMAKE_SYSTEM_VERSION EQUAL 101)
   install(TARGETS GPIO DESTINATION "/opt/prime/bin")
else()
   my_post_build_bin(GPIO)
endif()
