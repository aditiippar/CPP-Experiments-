#include <iostream>  // For std::cout
#include <string>    // For std::string
#include <utility>   // For std::move

class Vehicle {      // Base class for all vehicles
protected:           // Accessible in derived classes
    std::string registrationNumber; // Vehicle registration number
    double ratePerDay;              // Daily rental rate

public:
    // Constructor: initializes registration number and daily rate
    Vehicle(std::string registration, double rate)
        : registrationNumber(std::move(registration)), ratePerDay(rate) {}

    // Virtual function: calculates normal rent
    virtual double calculateRent(int days) const {
        return ratePerDay * days; // Rate multiplied by number of days
    }

    // Virtual function: displays common vehicle information
    virtual void display() const {
        std::cout << "Registration: " << registrationNumber << '\n';
        std::cout << "Rate per day: " << ratePerDay << '\n';
    }

    virtual ~Vehicle() = default; // Virtual destructor for safe inheritance
};

class Car : public Vehicle { // Car inherits from Vehicle
private:
    int numberOfDoors; // Number of doors in the car

public:
    // Car constructor
    Car(std::string registration, double rate, int doors)
        : Vehicle(std::move(registration), rate), numberOfDoors(doors) {}

    // Overrides Vehicle display function
    void display() const override {
        Vehicle::display(); // Show registration number and rate
        std::cout << "Doors: " << numberOfDoors << '\n';
    }
};

class Bike : public Vehicle { // Bike inherits from Vehicle
private:
    int engineCapacity; // Engine capacity in cc

public:
    // Bike constructor
    Bike(std::string registration, double rate, int capacity)
        : Vehicle(std::move(registration), rate), engineCapacity(capacity) {}

    // Overrides rent calculation to give a 10% discount
    double calculateRent(int days) const override {
        return ratePerDay * days * 0.9;
    }

    // Overrides Vehicle display function
    void display() const override {
        Vehicle::display(); // Show registration number and rate
        std::cout << "Engine Capacity: " << engineCapacity << " cc\n";
    }
};

int main() { // Program entry point
    Car car("MH12AB1234", 2000.0, 5); // Create a car object
    Bike bike("MH12CD5678", 800.0, 150); // Create a bike object

    std::cout << "Car Details\n";
    car.display(); // Display car details
    std::cout << "Rent for 3 days: " << car.calculateRent(3) << "\n\n";

    std::cout << "Bike Details\n";
    bike.display(); // Display bike details
    std::cout << "Rent for 3 days: " << bike.calculateRent(3) << '\n';

    return 0; // End program successfully
}