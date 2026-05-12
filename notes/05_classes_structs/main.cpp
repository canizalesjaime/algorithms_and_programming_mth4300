#include <iostream>
using namespace std;

// Define a class
class Car {
public:
    string brand;
    string model;
    int year;

    // Constructor to initialize the object
    Car(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
    }

    // Member function to display car information
    void displayInfo() {
        cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year << endl;
    }
};


class BankAccount {
private:
    double balance;

public:
    // Constructor to initialize balance
    BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    // Public method to deposit money
    void deposit(double amount) {
        balance += amount;
    }

    // Public method to retrieve the balance
    double getBalance() {
        return balance;
    }
};

int main() {
    // // Create an object of the Car class
    // Car car1("Toyota", "Camry", 2020);
    
    // // Call the member function
    // car1.displayInfo();  // Output: Brand: Toyota, Model: Camry, Year: 2020

    // Car car2("Nissan", "Altima", 2018);
    // car2.displayInfo();

    BankAccount account(1000);  // Create an object with initial balance of 1000

    account.deposit(500);       // Deposit 500
    cout << "Current balance: " << account.getBalance() << endl;  // Output: Current balance: 1500

    return 0;
}