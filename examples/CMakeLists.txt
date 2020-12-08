#=======================================================================================================================
# Define Demo1 target
#=======================================================================================================================
add_executable(Demo1 Demo1.cpp)
target_link_libraries(Demo1 PRIVATE library-static)
target_compile_definitions(Demo1 PRIVATE OPENXLSX_STATIC_DEFINE)


