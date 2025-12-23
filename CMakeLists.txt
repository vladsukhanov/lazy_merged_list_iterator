cmake_minimum_required(VERSION 3.10)

project(task_siber_systems)

set(CMAKE_CXX_STANDARD 17)

add_executable(task_siber_systems source/main.cpp)

target_include_directories(task_siber_systems PRIVATE include)
