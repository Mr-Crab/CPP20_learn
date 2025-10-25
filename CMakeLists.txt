cmake_minimum_required(VERSION 4.1)
project(CPP20)

set(CMAKE_CXX_STANDARD 20)
# this bool forcely requires C++ standard, if not, the Cmake fails
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# this bool disables compiler-specific extensions like gnu++20
set(CMAKE_CXX_EXTENSIONS OFF)

# Add source files to the executable target
add_executable(CPP20 main.cpp
        employee.cppm)

target_sources(CPP20
    PRIVATE
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
        employee.cppm
)

target_include_directories(CPP20 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(CPP20_2 main2.cpp)