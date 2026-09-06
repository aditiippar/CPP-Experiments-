#include <iostream> // Includes input/output features such as std::cout.

// Defines a class named Account.
class Account {

private: // Members below are accessible only inside Account and its friends.
    double balance; // Stores the account balance.

    // Makes the Auditor class a friend of Account.
    // Auditor can access Account's private members, including balance.
    friend class Auditor;

public: // Members below can be accessed from outside the class.

    // Constructor for Account.
    // explicit prevents unintended automatic conversion from double to Account.
    // initialBalance is used to initialize balance.
    explicit Account(double initialBalance) : balance(initialBalance) {}
};

// Defines a class named Auditor.
class Auditor {

public:
    // inspect accepts an Account object by constant reference.
    // const Account& means: do not copy the account and do not modify it.
    // The final const means inspect does not modify the Auditor object either.
    void inspect(const Account& account) const {

        // Auditor can access account.balance even though balance is private,
        // because Auditor was declared as a friend class in Account.
        std::cout << "Account Balance: " << account.balance << '\n';
    }
};

// Program execution starts here.
int main() {

    // Creates an Account object named account with balance 5000.0.
    Account account(5000.0);

    // Creates an Auditor object named auditor.
    Auditor auditor;

    // Calls inspect() to display the private balance of account.
    auditor.inspect(account);

    return 0; // Ends the program successfully.
}