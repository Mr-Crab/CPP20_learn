#include <iostream>
#include "Simple.hpp"

Simple** allocateCharacterBoard(std::size_t xDimension, std::size_t yDimension) {
    Simple** myArray { new Simple*[xDimension] };   // Allocate first dimension
    for (std::size_t i {0}; i < xDimension; ++i) {
        myArray[i] = new Simple[yDimension];      // Allocate ith subarray
    }
    return myArray;
}

void releaseCharacterBoard(Simple** myArray, std::size_t xDimension) {
    for (std::size_t i {0}; i < xDimension; ++i) {
        delete[] myArray[i];
        myArray[i] = nullptr;
    }
    delete[] myArray;
    myArray = nullptr;
}

int main() {
    auto myArray = allocateCharacterBoard(3, 3);
    releaseCharacterBoard(myArray, 3);
    return 0;
}