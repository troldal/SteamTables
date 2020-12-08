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
add_executable(benchmark-static EXCLUDE_FROM_ALL Benchmark.cpp)
target_link_libraries(benchmark-static PRIVATE benchmark benchmark_main library-static)
target_compile_definitions(benchmark-static PRIVATE OPENXLSX_STATIC_DEFINE)

# ===== Target using shared library ===== #
add_executable(benchmark-shared EXCLUDE_FROM_ALL Benchmark.cpp)
target_link_libraries(benchmark-shared PRIVATE benchmark benchmark_main library-shared)

