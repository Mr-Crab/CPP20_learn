#include <iostream>
#include "Simple.hpp"
int main() {
    const std::size_t size{4};
    Simple** mySimplePtrArray { new Simple*[size] };
    // Allocate an object for each pointer
    for (std::size_t i {0}; i < size; ++i) {
        mySimplePtrArray[i] = new Simple();
    }

    // !!MUST!! Delete each allocated object
    for (std::size_t i {0}; i < size; ++i) {
        delete mySimplePtrArray[i];
        mySimplePtrArray[i] = nullptr;
    }

    // Delete the array itself
    delete[] mySimplePtrArray;
    mySimplePtrArray = nullptr;
    return 0;
}