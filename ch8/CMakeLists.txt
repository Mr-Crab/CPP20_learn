add_executable(CH8_CPP20_1 main1.cpp SpreadsheetCell.cpp)
target_sources(CH8_CPP20_1
        PRIVATE
        FILE_SET cxx_modules_common TYPE CXX_MODULES FILES
        SpreadsheetCell.cppm
)