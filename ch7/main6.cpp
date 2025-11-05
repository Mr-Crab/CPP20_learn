#include <array>
#include <iostream>
#include <memory>
#include <format>

#ifndef __NO_CONSTRUCT__
#define __NO_CONSTRUCT__
#endif

#include "Simple.hpp"

/*
 * Tip:
 * For std::make_unique_for_overwrite
 * Only the class does not have user defined constructor, this function will now initialize the class member variables
 * to zero
 * Otherwise, the std::make_unique_for_overwrite will call the user-defined constructor, which has no difference with
 * the std::make_shared
 *
 */

int main() {
    std::cout << "Before First initialization of Simple with unique_ptr" << std::endl;
    auto mySimplePtr1 = std::make_unique<Simple>();
    auto myArray = mySimplePtr1->GetArray();
    std::cout << "The array underline mySimplePtr1 is " << std::endl;
    for (std::size_t idx = 0; idx < LENGTH; ++idx) {
        std::cout << std::format("{} ", myArray[idx]);
    }
    std::cout << "\nAfter First initialization of Simple with unique_ptr\n" << std::endl;

    std::cout << "Before Second initialization of Simple with make_unique_for_overwrite" << std::endl;
    // introduced in C++20
    auto mySimplePtr2 = std::make_unique_for_overwrite<Simple>();
    auto myArray2 = mySimplePtr2->GetArray();
    std::cout << "The array underline mySimplePtr1 is " << std::endl;
    for (std::size_t idx = 0; idx < LENGTH; ++idx) {
        std::cout << std::format("{} ", myArray2[idx]);
    }
    std::cout << "\nAfter Second initialization of Simple with make_unique_for_overwrite\n" << std::endl;

    return 0;
}