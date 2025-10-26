#include <iostream>
#include <utility>
#include <string>

int main() {
    std::string str{"C++"};
    // std::as_const returns a const reference to its argument, equals to const_cast<const T&>(obj)
    const std::string& constStr {std::as_const(str)};
    std::cout << "Original string: " << str << "\n";
    std::cout << "Const string: " << constStr << "\n";
    return 0;
}