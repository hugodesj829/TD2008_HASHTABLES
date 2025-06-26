cmake_minimum_required(VERSION 3.31)
project(HashtablesTD2008)

set(CMAKE_CXX_STANDARD 11)

add_executable(HashtablesTD2008 main.cpp
        hashmap.h
        tests/tests_hashmap.cpp)
