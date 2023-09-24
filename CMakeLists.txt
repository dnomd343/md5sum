cmake_minimum_required(VERSION 3.5)
project(md5sum LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

add_library(md5sum STATIC md5.cc md5_impl.cc)
