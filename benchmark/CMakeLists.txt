#=======================================================================================================================
# Download Google Benchmark
#=======================================================================================================================
include(FetchContent)
FetchContent_Declare(gbench
                     GIT_REPOSITORY https://github.com/google/benchmark.git
                     GIT_TAG master
                     )

FetchContent_GetProperties(gbench)
if (NOT gbench_POPULATED)
    FetchContent_Populate(gbench)
    set(BENCHMARK_ENABLE_TESTING OFF)
    add_subdirectory(${gbench_SOURCE_DIR} ${gbench_BINARY_DIR} EXCLUDE_FROM_ALL)
endif ()


#=======================================================================================================================
# Define Benchmark targets
#=======================================================================================================================

# ===== Target using static library ===== #
add_executable(${PROJECT_NAME}-benchmark-static EXCLUDE_FROM_ALL Benchmark.cpp)
target_link_libraries(${PROJECT_NAME}-benchmark-static PRIVATE benchmark benchmark_main ${PROJECT_NAME}-library-static)
target_compile_definitions(${PROJECT_NAME}-benchmark-static PRIVATE OPENXLSX_STATIC_DEFINE)

# ===== Target using shared library ===== #
add_executable(${PROJECT_NAME}-benchmark-shared EXCLUDE_FROM_ALL Benchmark.cpp)
target_link_libraries(${PROJECT_NAME}-benchmark-shared PRIVATE benchmark benchmark_main ${PROJECT_NAME}-library-shared)

