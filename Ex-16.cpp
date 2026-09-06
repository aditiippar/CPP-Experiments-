
#include <iostream>  // Gives access to input/output tools like std::cout.
#include <string>    // Gives access to the std::string data type.
#include <utility>   // Gives access to std::move.

class Employee {     // Defines an abstract base class named Employee.

protected:           // Members below can be used by this class and derived classes.
    int employeeId;  // Stores the unique ID number of an employee.
    std::string name; // Stores the employee's name.

public:              // Members below can be accessed from outside the class.

    // Constructor: initializes employeeId with id and name with employeeName.
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {}

    // Pure virtual function: every derived employee class must define salary calculation.
    virtual double calculateSalary() const = 0;

    // Displays common employee details.
    void displayBasicDetails() const {
        std::cout << "Employee ID: " << employeeId << '\n'; // Prints employee ID.
        std::cout << "Name: " << name << '\n';              // Prints employee name.
    }

    // Virtual destructor ensures derived objects are destroyed correctly.
    virtual ~Employee() = default;
};

// PermanentEmployee inherits from Employee.
class PermanentEmployee : public Employee {

private:                // Members below are accessible only inside this class.
    double basicSalary; // Stores the fixed/basic salary.
    double allowance;   // Stores additional allowance.

public:
    // Constructor for a permanent employee.
    PermanentEmployee(int id, std::string employeeName, double basic, double extra)
        : Employee(id, std::move(employeeName)), // Calls Employee constructor.
          basicSalary(basic),                     // Initializes basicSalary.
          allowance(extra) {}                     // Initializes allowance.

    // Overrides Employee's salary-calculation function.
    double calculateSalary() const override {
        return basicSalary + allowance; // Total = basic salary + allowance.
    }
};

// ContractEmployee inherits from Employee.
class ContractEmployee : public Employee {

private:
    double hourlyRate; // Stores pay received for one hour of work.
    int hoursWorked;   // Stores total hours worked.

public:
    // Constructor for a contract employee.
    ContractEmployee(int id, std::string employeeName, double rate, int hours)
        : Employee(id, std::move(employeeName)), // Calls Employee constructor.
          hourlyRate(rate),                       // Initializes hourly rate.
          hoursWorked(hours) {}                   // Initializes hours worked.

    // Overrides Employee's salary-calculation function.
    double calculateSalary() const override {
        return hourlyRate * hoursWorked; // Total = hourly rate × worked hours.
    }
};

// Accepts any Employee object using a reference to the base class.
void displayPaySlip(const Employee& employee) {
    employee.displayBasicDetails(); // Calls common employee-detail display function.
    std::cout << "Salary: "         // Prints the label.
              << employee.calculateSalary() // Calls the correct derived salary method.
              << "\n\n";            // Prints two new lines.
}

int main() {
    // Creates a permanent employee:
    // ID = 101, name = Asha, basic salary = 40000, allowance = 8000.
    PermanentEmployee permanentEmployee(101, "Aditi", 40000.0, 8000.0);

    // Creates a contract employee:
    // ID = 102, name = Vikas, hourly rate = 500, hours worked = 80.
    ContractEmployee contractEmployee(102, "Payal", 500.0, 80);

    displayPaySlip(permanentEmployee); // Displays Asha's details and salary: 48000.
    displayPaySlip(contractEmployee);  // Displays Vikas's details and salary: 40000.

    return 0; // Ends the program successfully.
}
