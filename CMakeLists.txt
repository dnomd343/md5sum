cmake_minimum_required(VERSION 3.10)
project(md5sum LANGUAGES CXX)

if ("${CMAKE_VERSION}" VERSION_GREATER_EQUAL "3.13")
  cmake_policy(SET CMP0077 NEW)
endif()

# ------------------------------------------------------------------------------------ #

option(MD5_BUILD_DEMO "Build md5 demo binary." OFF)
option(MD5_SHARED_LIB "Build as a dynamic library." OFF)
option(MD5_ENABLE_LTO "Enable LTO optimization of the library." ON)
option(MD5_ENABLE_TESTING "Enable testing of the md5sum library." OFF)
option(MD5_ENABLE_BENCHMARK "Enable benchmark of the md5sum library." OFF)

# ------------------------------------------------------------------------------------ #

set(CXX_STANDARDS)
foreach (CXX_FEATURE ${CMAKE_CXX_COMPILE_FEATURES})
  if (CXX_FEATURE MATCHES "^cxx_std_[0-9]+$")
    string(REGEX MATCH "[0-9]+$" CXX_STANDARD ${CXX_FEATURE})
    list(APPEND CXX_STANDARDS ${CXX_STANDARD})  # supported c++ standards
  endif()
endforeach()

if (NOT 17 IN_LIST CXX_STANDARDS)
  message(FATAL_ERROR "MD5 project require at least C++17.")
endif()

list(GET CXX_STANDARDS -1 MD5_CXX_STANDARD)  # select the latest C++ standard
message(STATUS "MD5 CXX Standard: ${MD5_CXX_STANDARD}")
set(CMAKE_CXX_STANDARD ${MD5_CXX_STANDARD})

# ------------------------------------------------------------------------------------ #

if (NOT CMAKE_BUILD_TYPE OR MSVC)
  set(CMAKE_BUILD_TYPE Release)  # using release build in default
endif()

if (MSVC)
  add_compile_options(/W4)  # TODO: add `/WX` after fix MSVC warnings
  if (MD5_ENABLE_LTO)
    add_compile_options(/GL)
    add_link_options(/LTCG)
  endif()
else()
  add_compile_options(-Wall -Wextra -Werror)
  if (MD5_ENABLE_LTO)
    add_compile_options(-flto=auto)
  endif()
endif()

# ------------------------------------------------------------------------------------ #

file(GLOB MD5_SRC src/impl/*.cc)
if (NOT MD5_SHARED_LIB)
  add_library(md5sum STATIC ${MD5_SRC})
else()
  add_library(md5sum SHARED ${MD5_SRC})
  if (NOT MSVC)
    target_compile_options(md5sum PRIVATE -fvisibility=hidden)
  endif()
endif()

if (MSVC)
  set(MD5_COMPILE_OPTIONS /GR-)
else()
  set(MD5_COMPILE_OPTIONS
          -fno-rtti -fno-exceptions
          -fno-unwind-tables -fno-asynchronous-unwind-tables)
endif()

target_compile_options(md5sum PRIVATE ${MD5_COMPILE_OPTIONS})
target_include_directories(md5sum PUBLIC src/)

add_library(md5sum::md5 ALIAS md5sum)

# ------------------------------------------------------------------------------------ #

if (MD5_BUILD_DEMO)
  add_executable(md5_demo demo.cc)
  target_link_libraries(md5_demo PRIVATE md5sum)
  target_compile_options(md5_demo PRIVATE ${MD5_COMPILE_OPTIONS})
endif()

# ------------------------------------------------------------------------------------ #

include(third_party/ThirdParty.cmake)

if (MD5_ENABLE_TESTING)
  enable_testing()
  file(GLOB MD5_TEST_SRC test/*.cc)
  add_executable(md5_test ${MD5_TEST_SRC})
  target_link_libraries(md5_test PRIVATE md5sum GTest::gtest_main)
  add_test(NAME md5_test COMMAND md5_test)
endif()

if (MD5_ENABLE_BENCHMARK)
  add_executable(md5_benchmark benchmark.cc)
  target_link_libraries(md5_benchmark PRIVATE md5sum benchmark::benchmark_main)
  target_compile_options(md5_benchmark PRIVATE ${MD5_COMPILE_OPTIONS})
endif()

# ------------------------------------------------------------------------------------ #
