cmake_minimum_required(VERSION 3.12)

project(test VERSION 1.0)

add_subdirectory(math)

add_executable(test test.cpp)

target_link_libraries(test PRIVATE math)