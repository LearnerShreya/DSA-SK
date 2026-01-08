#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;   // private -> cannot be accessed directly from outside
    string password;  // data hiding

public:
    BankAccount(double amount) {   // constructor
        balance = amount;
    }

    // setter: deposit money safely
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Invalid deposit amount" << endl;
        }
    }

    // setter: withdraw money safely
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            cout << "Invalid withdraw amount" << endl;
        }
    }

    // getter: read balance safely
    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount acc(1000);  // initial balance

    acc.deposit(500);
    acc.withdraw(200);

    cout << "Final Balance: " << acc.getBalance() << endl;
    return 0;
}