add_executable(CH1_CPP20_ProjectExample main10.cpp Employee.cpp)
target_sources(CH1_CPP20_ProjectExample
        PRIVATE
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
        Employee.cppm
)
target_include_directories(CH1_CPP20_ProjectExample PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})