#include <iostream>
#include <compare>
#include <string>

int main() {
    // strong ordering only applies to integrater types
    int i{11};
    std::strong_ordering result { i <=> 0 };
    if (result == std::strong_ordering::less) { std::cout << "less" << std::endl; }
    if (result == std::strong_ordering::greater) { std::cout << "greater" << std::endl; }
    if (result == std::strong_ordering::equal) { std::cout << "equal" << std::endl; }

    // if the type is float, the result is partial ordering
    float f{11.0f};
    std::partial_ordering presult { f <=> 30.0f };
    if (presult == std::partial_ordering::less) { std::cout << "less" << std::endl; }
    if (presult == std::partial_ordering::greater) { std::cout << "greater" << std::endl; }
    if (presult == std::partial_ordering::equivalent) { std::cout << "equivalent" << std::endl; }
    // if one compare variable is non-number or both of them are non-numbers, the result is unordered
    if (presult == std::partial_ordering::unordered) { std::cout << "unordered" << std::endl; }

    if (std::is_eq(result)) {
        std::cout << "i " << i << " is equal to 0" << std::endl;
    } else if (std::is_neq(result)) {
        std::cout << "i " << i << " is not equal to 0" << std::endl;
    }
    // same: std::is_lt, std::is_gt, std::is_lteq, std::is_gteq
    return 0;
}