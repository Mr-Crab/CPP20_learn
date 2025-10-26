export module Employee;

#include <string>
#include <format>
#include <iostream>

namespace Records {
    const int DefaultStrartingSalary {30'000};
    export const int DefaultRaiseAndDemeritAmount {1'000};

    export class Employee {
    public:
        Employee(const std::string& firstName, const std::string& lastName);

        void promote(int raiseAmount = DefaultRaiseAndDemeritAmount);
        void demote(int demeritAmount = DefaultRaiseAndDemeritAmount);
        void hire();    // Hires or rehires the employee
        void fire();    // Dismisses the employee
        void display() const; // Displays employee information

        // Getters and setters
        void setFirstName(const std::string& firstName);
        const std::string& getFirstName() const;

        void setLastName(const std::string& lastName);
        const std::string& getLastName() const;

        void setEmployeeNumber(int employeeNumber);
        int getEmployeeNumber() const;

        void setSalary(int salary);
        int getSalary() const;

        bool isHired() const;

    private:
        std::string mFirstName;
        std::string mLastName;
        int mEmployeeNumber{-1};
        int mSalary{DefaultStrartingSalary};
        bool mHired{false};
    };
}