#ifndef CPP20_SIMPLE_HPP
#define CPP20_SIMPLE_HPP
#include <iostream>

class Simple {
public:
    Simple() {
        std::cout << "Simple Constructor: Simple" << std::endl;
    }
    ~Simple() {
        std::cout << "Simple Destructor: ~Simple" << std::endl;
    }
};

#endif //CPP20_SIMPLE_HPP