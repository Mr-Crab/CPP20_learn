#include <iostream>
#include <format>

double divideNumbers(double numerator, double denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("denominator cannot be zero");
    }
    return numerator / denominator;
}

int main() {
    try {
        std::cout << "Result1: " << divideNumbers(10.0, 20.0) << std::endl;
        std::cout << "Result2: " << divideNumbers(10.0, 0.0) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << std::format("Exception caught: {}", e.what()) << std::endl;
    }
    return 0;
}