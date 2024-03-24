if (MD5_ENABLE_TESTING)
    add_subdirectory(third_party/googletest/ EXCLUDE_FROM_ALL)
endif()

if (MD5_ENABLE_BENCHMARK)
    set(BENCHMARK_ENABLE_TESTING OFF)
    set(BENCHMARK_ENABLE_EXCEPTIONS OFF)
    add_subdirectory(third_party/benchmark/ EXCLUDE_FROM_ALL)
endif()
