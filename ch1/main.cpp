#include <iostream>
#include <format>
import employee;

int main() {
    std::cout << "Hello, World!" << std::endl;
    Employee anEmployee{};
    anEmployee.firstInitial = 'J';
    anEmployee.lastInitial = 'D';
    anEmployee.employeeNumber = 12345;
    anEmployee.salary = 55000;
    std::cout << std::format("Employee number is {}\n", anEmployee.employeeNumber);

    return 0;
}