module Employee;

namespace Records {
    Employee::Employee(const std::string& firstName, const std::string& lastName)
        : mFirstName(firstName), mLastName(lastName) {}

    void Employee::promote(int raiseAmount) {
        setSalary(getSalary() + raiseAmount);
    }

    void Employee::demote(int demeritAmount) {
        setSalary(getSalary() - demeritAmount);
    }

    void Employee::hire() { mHired = true; }
    void Employee::fire() { mHired = false; }

    void Employee::display() const {
        std::cout << std::format("Employee: {}, {}", getLastName(), getFirstName()) << "\n";
        std::cout << "-------------------------------------" << std::endl;
        std::cout << (isHired() ? "Current Employee" : "Former Employee") << "\n";
        std::cout << std::format("Employee Number: {}", getEmployeeNumber()) << "\n";
        std::cout << std::format("Salary: ${}", getSalary()) << "\n";
        std::cout << std::endl;
    }

    void Employee::setFirstName(const std::string& firstName) { mFirstName = firstName; }
    const std::string& Employee::getFirstName() const { return mFirstName; }
    void Employee::setLastName(const std::string& lastName){mLastName = lastName;};
    const std::string& Employee::getLastName() const { return mLastName; }

    void Employee::setEmployeeNumber(int employeeNumber) {mEmployeeNumber = employeeNumber;};
    int Employee::getEmployeeNumber() const { return mEmployeeNumber; }

    void Employee::setSalary(int salary) { mSalary = salary; };
    int Employee::getSalary() const {return mSalary;};

    bool Employee::isHired() const { return mHired; };
}
