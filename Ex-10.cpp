#include <iostream> // Includes input/output features, such as std::cout.

// Defines a base class named Vehicle.
class Vehicle {

public: // Members below can be accessed outside the class.

    // virtual allows derived classes to provide their own version of move().
    // const means this function does not modify the Vehicle object.
    virtual void move() const {
        std::cout << "Vehicle is moving\n"; // Prints a general vehicle movement message.
    }

    // virtual destructor ensures derived objects are destroyed correctly.
    // = default asks the compiler to create the normal destructor automatically.
    virtual ~Vehicle() = default;
};

// Car inherits publicly from Vehicle.
class Car : public Vehicle {

public:
    // override confirms this function replaces Vehicle::move().
    // const means the Car object is not changed by this function.
    void move() const override {
        std::cout << "Car moves on roads\n"; // Prints the car-specific movement message.
    }
};

// Boat inherits publicly from Vehicle.
class Boat : public Vehicle {

public:
    // override confirms this function replaces Vehicle::move().
    // const means the Boat object is not changed by this function.
    void move() const override {
        std::cout << "Boat moves on water\n"; // Prints the boat-specific movement message.
    }
};

// Program execution begins here.
int main() {

    Car car;   // Creates an object named car from the Car class.
    Boat boat; // Creates an object named boat from the Boat class.

    car.move();  // Calls Car::move(), printing the road message.
    boat.move(); // Calls Boat::move(), printing the water message.

    return 0; // Ends the program successfully.
}