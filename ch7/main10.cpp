#include <iostream>
#include <memory>
#include "Simple.hpp"

std::unique_ptr<Simple> create() {
    auto ptr {std::make_unique<Simple>()};
    return ptr;
}

int main() {
    std::unique_ptr<Simple> mySmartPtr1 {create()};
    auto mySmartPtr2{create()};
    return 0;
}