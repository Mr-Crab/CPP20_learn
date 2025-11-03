cmake_minimum_required(VERSION 4.1)
project(CPP20)

set(CMAKE_CXX_STANDARD 20)
# this bool forcely requires C++ standard, if not, the Cmake fails
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# this bool disables compiler-specific extensions like gnu++20
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(ch1)
add_subdirectory(ch2)
add_subdirectory(ch7)