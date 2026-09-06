#include <iostream> // Includes output features such as std::cout.

// Defines a class named Academic.
class Academic {

public: // Members below can be accessed outside the class.

    // const means this function does not modify the Academic object.
    void display() const {
        std::cout << "Academic information\n"; // Prints academic-related information.
    }
};

// Defines a class named Sports.
class Sports {

public: // Members below can be accessed outside the class.

    // const means this function does not modify the Sports object.
    void display() const {
        std::cout << "Sports information\n"; // Prints sports-related information.
    }
};

// Student inherits publicly from both Academic and Sports.
class Student : public Academic, public Sports {

public:
    // Displays information from both inherited base classes.
    void displayAll() const {

        // Academic:: specifies that display() from Academic must be called.
        // This avoids ambiguity because Sports also has a display() function.
        Academic::display();

        // Sports:: specifies that display() from Sports must be called.
        Sports::display();
    }
};

// Program execution begins here.
int main() {

    Student student; // Creates a Student object named student.

    // Calls Academic's display() function through the Student object.
    // Academic:: removes ambiguity between Academic::display() and Sports::display().
    student.Academic::display();

    // Calls Sports's display() function through the Student object.
    // Sports:: removes ambiguity between Academic::display() and Sports::display().
    student.Sports::display();

    // Calls Student's function, which displays both academic and sports information.
    student.displayAll();

    return 0; // Ends the program successfully.
}