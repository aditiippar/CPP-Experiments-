#include <iostream> // Provides output tools such as std::cout.
#include <string>   // Provides the std::string type.
#include <utility>  // Provides std::move.

// Base class representing a person.
class Person {

protected:          // Members here are accessible in Person and derived classes.
    std::string name; // Stores the person's name.

public:             // Members here are accessible outside the class.

    // explicit prevents automatic conversion from std::string to Person.
    // personName receives the name passed to the constructor.
    // std::move transfers personName into name efficiently.
    explicit Person(std::string personName) : name(std::move(personName)) {}

    // const means this function does not modify the Person object.
    void displayName() const {
        std::cout << "Name: " << name << '\n'; // Prints the person's name.
    }
};

// Student inherits virtually from Person.
// virtual inheritance ensures only one Person object exists
// when a class inherits through both Student and Employee.
class Student : virtual public Person {

public:
    // Student constructor.
    // Initializes Person with "Unknown" when Student is created independently.
    Student() : Person("Unknown") {}
};

// Employee also inherits virtually from Person.
class Employee : virtual public Person {

public:
    // Employee constructor.
    // Initializes Person with "Unknown" when Employee is created independently.
    Employee() : Person("Unknown") {}
};

// TeachingAssistant inherits from both Student and Employee.
// This is multiple inheritance.
class TeachingAssistant : public Student, public Employee {

public:
    // Constructor receives assistantName as the teaching assistant's name.
    explicit TeachingAssistant(std::string assistantName)

        // TeachingAssistant is the most-derived class, so it initializes
        // the shared virtual Person base class.
        : Person(std::move(assistantName)),

          // Calls the Student constructor.
          Student(),

          // Calls the Employee constructor.
          Employee() {}
};

// Program execution begins here.
int main() {

    // Creates a TeachingAssistant named assistant with the name "Riya".
    TeachingAssistant assistant("Aditi");

    // Calls the inherited Person function to display the name.
    assistant.displayName();

    return 0; // Ends the program successfully.
}