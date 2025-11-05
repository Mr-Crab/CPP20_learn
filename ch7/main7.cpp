#include <array>
#include <iostream>
#include <memory>
#include <format>
#include "Simple.hpp"

int* my_alloc(int value) {
    std::cout << "Calling self defined constructor" << std::endl;
    return new int(value);
}

void my_free(int* p) {
    delete p;
    std::cout << "Calling self defined destructor" << std::endl;
}

int main() {
    std::cout << "Before First initialization of Simple with unique_ptr" << std::endl;
    auto mySimplePtr1 = std::make_unique<Simple>();
    std::cout << "After First initialization of Simple with unique_ptr\n" << std::endl;

    std::cout << "Before Second initialization of Simple with make_unique_for_overwrite" << std::endl;
    // introduced in C++20
    auto mySimplePtr2 = std::make_unique<Simple>();
    std::cout << "After Second initialization of Simple with make_unique_for_overwrite\n" << std::endl;
    // other unique_ptr APIs
    // (1) reset
    std::cout << "\nBefore reset mySimplePtr1" << std::endl;
    mySimplePtr1.reset();   // Free resource and set to nullptr
    std::cout << "After reset mySimplePtr1, before reset mySimplePtr2" << std::endl;
    mySimplePtr2.reset(new Simple());   // Free resource and set to a new Simple instance
    std::cout << "After reset mySimplePtr2" << std::endl;

    // (2) release
    std::cout << "\nBefore release mySimplePtr2" << std::endl;
    Simple* simpleRawPtr { mySimplePtr2.release() };    // Release ownership
    std::cout << "After release mySimplePtr2" << std::endl;
    // Use the raw pointer
    delete simpleRawPtr;
    simpleRawPtr = nullptr;

    // (3) self defined deleter
    std::cout << "\nBefore constructing self-defined constructor and deleter of unique_ptr" << std::endl;
    std::unique_ptr<int, decltype(&my_free)> myIntSmartPtr {my_alloc(42), my_free};
    std::cout << "After constructing self-defined constructor and deleter of unique_ptr" << std::endl;

    return 0;
}