#=======================================================================================================================
# Preamble
#=======================================================================================================================
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(ProjectTemplate VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)

#=======================================================================================================================
# Set project metadata
#=======================================================================================================================
set(PROJECT_VENDOR "Kenneth Troldal Balslev")
set(PROJECT_CONTACT "kenneth.balslev@gmail.com")
set(PROJECT_URL "Add GitHub address here")
set(PROJECT_DESCRIPTION "Add description here")

#=======================================================================================================================
# Set C/C++ compiler version
#=======================================================================================================================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(IGNORE_ME ${CMAKE_C_COMPILER})

#=======================================================================================================================
# Output Directories.
#=======================================================================================================================
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

#=======================================================================================================================
# Add build options
#=======================================================================================================================
option(CREATE_DOCS "Build library documentation (requires Doxygen and Graphviz/Dot to be installed)" ON)
option(BUILD_SAMPLES "Build sample programs" ON)
option(BUILD_TESTS "Build and run library tests" ON)
option(BUILD_BENCHMARKS "Build and run library benchmarks" ON)
option(ENABLE_COVERAGE "Enable GCC/Clang code coverage in Debug build (tests, benchmarks and samples will NOT build
when this is enabled!)" OFF)

#=======================================================================================================================
# Add project subdirectories
#=======================================================================================================================
add_subdirectory(source)

if(${CREATE_DOCS})
    add_subdirectory(doxy)
endif()

if(${BUILD_SAMPLES})
    add_subdirectory(examples)
endif()

if(${BUILD_TESTS})
    add_subdirectory(tests)
endif()

if(${BUILD_BENCHMARKS})
    add_subdirectory(benchmark)
endif()

