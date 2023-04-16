#*******************************************************************************
#*******************************************************************************
#*******************************************************************************

function(my_lib_import_RisLib _target)

   set (MyRisLibImportPath  "/opt/prime/lib/rpi/libRisLib.a")
   add_library(RisLib STATIC IMPORTED)
   set_target_properties(RisLib PROPERTIES IMPORTED_LOCATION ${MyRisLibImportPath})
   target_link_libraries(${_target} RisLib)
   target_link_libraries(${_target} pthread)
   target_link_libraries(${_target} rt)
   target_link_libraries(${_target} readline)

endfunction()

function(my_inc_import_RisLib _target)

   set (MyRisLibIncludePath "/opt/prime/include/RisLib")
   target_include_directories(${_target} PUBLIC ${MyRisLibIncludePath})

endfunction()

#*******************************************************************************
#*******************************************************************************
#*******************************************************************************

function(my_lib_import_Hardware _target)

   target_link_libraries(${_target} gpiod)

endfunction()


#*******************************************************************************
#*******************************************************************************
#*******************************************************************************

