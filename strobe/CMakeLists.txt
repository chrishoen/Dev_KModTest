cmake_minimum_required (VERSION 3.8)

project (strobe CXX)

my_find_src_files (src_files strobe)
add_executable (strobe ${src_files})
my_add_compile_options (strobe)
my_add_pch (strobe)

my_inc_import_RisLib(strobe)
my_inc_import_CommonLib(strobe)

my_lib_import_CommonLib(strobe)
my_lib_import_RisLib(strobe)

if(MSVC)
   install(TARGETS strobe DESTINATION "C:/aaa_prime/RisLib")
elseif(NOT CMAKE_SYSTEM_VERSION EQUAL 101)
   install(TARGETS strobe DESTINATION "/opt/prime/bin")
else()
   my_post_build_bin(strobe)
endif()
