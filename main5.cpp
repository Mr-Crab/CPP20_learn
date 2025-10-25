#include <iostream>
#include <initializer_list>

int makeSum(const std::initializer_list<int>& values) {
    int total = 0;
    for (int value : values)
        total += value;
    return total;
}

int main() {
    std::initializer_list<int> numbers = {10, 20, 30, 40, 50};

    std::cout << "The numbers are: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    auto value = makeSum(numbers);
    std::cout << "The sum is: " << value << std::endl;
    return 0;
}