#include <iostream>
#include <array>
#include <utility>
#include <format>
#include <string>

int main() {
    // std::array is a container that encapsulates fixed size arrays
    std::array arr = {1, 2, 3, 4, 5};

    // Accessing elements using at() method
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << "Element at index " << i << " is " << arr.at(i) << std::endl;
    }

    // Accessing elements using range-based for loop
    for (const auto& element : arr) {
        std::cout << "Element: " << element << std::endl;
    }

    // the construct bind must use "auto" keyword
    // and the number of variables must match the number of elements in the array
    auto [x, y, z, a, b] {arr};
    std::cout << "Structured bindings: x=" << x << ", y=" << y << ", z=" << z << std::endl;

    std::pair myPair {"hello", 20.5};
    auto [theString, theInt] {myPair};
    std::cout << std::format("theString: {}, theInt: {}\n", theString, theInt);

    return 0;
}