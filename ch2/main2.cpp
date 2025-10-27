#include <iostream>
#include <string>
#include <format>

int main() {
    const std::string toParse("  123USD");
    std::size_t index{0};
    int value {std::stoi(toParse, &index)};
    std::cout << std::format("The transferred value is {} and index is {}", value, index) << std::endl;
    std::cout << std::format("The first non-parsed charactoer is '{}'", toParse[index]) << std::endl;
    return 0;
}