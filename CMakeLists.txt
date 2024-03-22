cmake_minimum_required(VERSION 3.12)
project(md5sum LANGUAGES CXX)

option(MD5_ENABLE_TESTING "Enable testing of the md5sum library." ON)
option(MD5_ENABLE_BENCHMARK "Enable benchmark of the md5sum library." ON)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra)

add_library(md5sum STATIC src/core.cc src/wrapper.cc)
target_compile_options(md5sum PRIVATE -fno-rtti -fno-exceptions)
target_include_directories(md5sum INTERFACE src/)

include(third_party/ThirdParty.cmake)
add_library(md5sum::md5sum ALIAS md5sum)

if (MD5_ENABLE_TESTING)
    enable_testing()
    add_executable(md5_test test/md5_update.cc)
    target_link_libraries(md5_test PRIVATE md5sum::md5sum GTest::gtest_main)
endif()

if (MD5_ENABLE_BENCHMARK)
    add_executable(md5_benchmark benchmark.cc)
    target_link_libraries(md5_benchmark PRIVATE md5sum::md5sum benchmark::benchmark_main)
    target_compile_options(md5_benchmark PRIVATE -fno-rtti -fno-exceptions)
endif()
