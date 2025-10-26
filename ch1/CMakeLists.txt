cmake_minimum_required(VERSION 4.1)
project(CPP20)

set(CMAKE_CXX_STANDARD 20)
# this bool forcely requires C++ standard, if not, the Cmake fails
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# this bool disables compiler-specific extensions like gnu++20
set(CMAKE_CXX_EXTENSIONS OFF)

# Add source files to the executable target
add_executable(CH1_CPP20_1 main.cpp
        employee.cppm)

target_sources(CH1_CPP20_1
    PRIVATE
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
        employee.cppm
)

target_include_directories(CH1_CPP20_1 PRIVATE ..)

add_executable(CH1_CPP20_2 main2.cpp)
add_executable(CH1_CPP20_3 main3.cpp)
if (MSVC)
    target_compile_options(CH1_CPP20_3 PRIVATE /W4 /permissive- /wd4100)
else ()
    # 常用的 GCC/Clang 警告组合
    target_compile_options(CH1_CPP20_3 PRIVATE -Wall -Wextra -Wpedantic)
    # 如果想保持高警告等级但不把未使用参数/变量当作警告：
    target_compile_options(CH1_CPP20_3 PRIVATE -Wno-unused-parameter -Wno-unused-variable)
endif ()

add_executable(CH1_CPP20_4 main4.cpp)
add_executable(CH1_CPP20_5 main5.cpp)
add_executable(CH1_CPP20_6 main6.cpp airline_ticket.cpp)
target_sources(CH1_CPP20_6
        PRIVATE
        FILE_SET cxx_modules2 TYPE CXX_MODULES FILES
        airline_ticket.cppm
)

add_executable(CH1_CPP20_7 main7.cpp Rect.cpp)
target_sources(CH1_CPP20_7
    PRIVATE
        FILE_SET cxx_modules3 TYPE CXX_MODULES FILES
        Rect.cppm
)

add_executable(CH1_CPP20_8 main8.cpp)
add_executable(CH1_CPP20_9 main9.cpp)