cmake_minimum_required(VERSION 3.12)
project(md5sum LANGUAGES CXX)

option(MD5_ENABLE_TESTING "Enable testing of the md5sum library." ON)
option(MD5_ENABLE_BENCHMARK "Enable benchmark of the md5sum library." ON)

set(CXX_STANDARDS)
foreach (CXX_FEATURE ${CMAKE_CXX_COMPILE_FEATURES})
    if (CXX_FEATURE MATCHES "^cxx_std_[0-9]+$")
        string(REGEX MATCH "[0-9]+$" CXX_STANDARD ${CXX_FEATURE})
        list(APPEND CXX_STANDARDS ${CXX_STANDARD})  # Get supported c++ standards
    endif()
endforeach()

if (NOT 17 IN_LIST CXX_STANDARDS)
    message(FATAL_ERROR "MD5 projects require at least C++17 support.")
endif()

list(GET CXX_STANDARDS -1 MD5_CXX_STANDARD)  # Select the latest C++ standard
message("MD5 CXX STANDARD: ${MD5_CXX_STANDARD}")
set(CMAKE_CXX_STANDARD ${MD5_CXX_STANDARD})
add_compile_options(-Wall -Wextra)

add_library(md5sum STATIC src/impl/core.cc src/impl/wrapper.cc)
target_compile_options(md5sum PRIVATE -fno-rtti -fno-exceptions)
target_include_directories(md5sum PUBLIC src/)

include(third_party/ThirdParty.cmake)
add_library(md5sum::md5sum ALIAS md5sum)

if (MD5_ENABLE_TESTING)
    enable_testing()
    add_executable(md5_test test/constexpr.cc test/md5_update.cc)
    target_link_libraries(md5_test PRIVATE md5sum::md5sum GTest::gtest_main)
endif()

if (MD5_ENABLE_BENCHMARK)
    add_executable(md5_benchmark benchmark.cc)
    target_link_libraries(md5_benchmark PRIVATE md5sum::md5sum benchmark::benchmark_main)
    target_compile_options(md5_benchmark PRIVATE -fno-rtti -fno-exceptions)
endif()
