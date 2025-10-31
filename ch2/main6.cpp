#include <iostream>
#include "KeyValue.hpp"

int main() {
    KeyValue keyValue{"Key1", 11};
    std::cout << std::format("{}", keyValue) << std::endl;
    std::cout << std::format("{:a}", keyValue) << std::endl;
    std::cout << std::format("{:b}", keyValue) << std::endl;
    std::cout << std::format("{:c}", keyValue) << std::endl;
    try {
        std::cout << std::format("{:c}", keyValue) << std::endl;
    } catch (const std::format_error& caught_exception) {
        std::cout << caught_exception.what() << std::endl;
    }
    return 0;
}