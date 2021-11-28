cmake_minimum_required (VERSION 3.8)

project (gpiotest CXX)
my_find_src_files (src_files gpiotest)
add_executable (gpiotest ${src_files})
my_add_compile_options (gpiotest)
my_add_pch (gpiotest)

my_inc_import_RisLib(gpiotest)
my_inc_import_CommonLib(gpiotest)

my_lib_import_RisLib(gpiotest)
my_lib_import_CommonLib(gpiotest)
my_lib_import_GPIO(gpiotest)

if(NOT CMAKE_SYSTEM_VERSION EQUAL 101)
   install(TARGETS gpiotest DESTINATION "/opt/prime/bin")
else()
   my_post_build_bin(gpiotest)
endif()
