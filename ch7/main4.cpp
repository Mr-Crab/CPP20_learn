#include <iostream>

void doubleInts(int theArray[], std::size_t size) {
    std::cout << "func " << __func__ << " Original input: ";
    for (std::size_t i = 0; i < size; i++) {
         std::cout << theArray[i] << ", ";
    }
    std::cout << std::endl;
    for (std::size_t i = 0; i < size; i++) {
        theArray[i] = theArray[i] * 2;
    }
    std::cout << "func " << __func__ << " After modification input: ";
    for (std::size_t i = 0; i < size; i++) {
         std::cout << theArray[i] << ", ";
    }
    std::cout << std::endl;
}


int main() {
    int stackArray[] {5,7,9,11};
    std::size_t arrSize = std::size(stackArray);
    doubleInts(stackArray, arrSize);
    std::cout << "func " << __func__ << " After modification input: ";
    for (std::size_t i = 0; i < arrSize; i++) {
        std::cout << stackArray[i] << ", ";
    }
    std::cout << std::endl;
    return 0;
}