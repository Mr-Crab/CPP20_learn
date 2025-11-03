#include <iostream>
#include <new>

int main() {
    int* ptrStandard = new int(0);
    std::cout << *ptrStandard << std::endl;
    if (ptrStandard) {
        delete ptrStandard;
        ptrStandard = nullptr;
    }
    int* ptrNonThrow = new(std::nothrow) int(2);
    std::cout << *ptrNonThrow << std::endl;
    if (ptrNonThrow) {
        delete ptrNonThrow;
        ptrNonThrow = nullptr;
    }
    return 0;
}