cmake_minimum_required(VERSION 3.10)
project(list_tests_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(list_tests
    tests/test_main.cpp
)
