#ifndef CPP20_SIMPLE_HPP
#define CPP20_SIMPLE_HPP
#include <iostream>

const std::size_t LENGTH = 300;

class Simple {
public:
#ifndef __NO_CONSTRUCT__
    Simple() {
        std::cout << "Simple Constructor: Simple" << std::endl;
    }
#endif
    ~Simple() {
        std::cout << "Simple Destructor: ~Simple" << std::endl;
    }
    uint8_t* GetArray() {return array;}
private:
    uint8_t array[LENGTH];
};

#endif //CPP20_SIMPLE_HPP