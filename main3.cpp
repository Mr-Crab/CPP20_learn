#include <iostream>

// [[nodiscard]] attribute indicates that the return value should not be ignored
[[nodiscard]] int func1() {
    return 42;
}

// [[nodiscard]] attribute with a custom message (from C++20 onwards)
[[nodiscard("No need to explain")]] int func2() {
    return 42;
}

// [[maybe_unused]] attribute indicates that the function or variable might not be used
[[maybe_unused]] int func3(int param1, int param2) {
    return 42;
}

int func4(int param1, [[maybe_unused]] int param2) {
    return 42;
}

// [[noreturn]] attribute indicates that the function does not return to the caller
[[noreturn]] void func5() {
    std::exit(1);   // defined in <cstdlib>
}

bool isDongleAvailable() {
    bool isAvailable = false;
    // check whether a licensing dongle is available
    return isAvailable;
}

bool isFeatureLicensed(int featureId) {
    if (!isDongleAvailable()) {
        // No licensing dongle found, abort program execution
        func5();
    } else {
        bool isLicensed {featureId == 42}; // Dummy check for illustration
        return isLicensed;
    }
}

[[deprecated]] void func6() {
    // This function is intentionally left empty
}

[[deprecated("This is deprecated, do not use")]] void func7() {
    // This function is intentionally left empty
}

// [[likely]] and [[unlikely]] attributes provide branch prediction hints to the compiler
// rarely use this, because the compiler is strong enough to optimize the branches itself
void func8() {
    int value{12};
    if (value > 11) [[unlikely]] {
        std::cout << "Value is greater than 11" << std::endl;
    } else {
        std::cout << "Value is less than 11" << std::endl;
    }
}

int main() {
    func1();
    func2();
    func3(1, 2);
    func4(1, 2);
    func6();
    func7();
    std::cout << "Hello, World! This is main3.cpp" << std::endl;
    bool isLicensed {isFeatureLicensed(42)};
    return 0;
}