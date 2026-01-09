#include <iostream>
using namespace std;

// Class blueprint
class Teacher {
private:
    double salary;   // private -> cannot be accessed outside the class

public:
    string name;     // public -> can be accessed directly
    string dept;
    string subject;

    // Function to change department (Example of modifying data using method)
    void changeDept(string newDept) {
        dept = newDept;
    }

    // Setter (write-only access for private data)
    void setSalary(double s) {
        salary = s;
    }

    // Getter (read-only access for private data)
    double getSalary() {
        return salary;
    }
};

int main() {
    // Object creation
    Teacher t1;

    // Accessing public data directly
    t1.name = "Shradha";
    t1.subject = "C++";
    t1.dept = "Computer Science";

    // Accessing private data using setter
    t1.setSalary(25000);

    // Display output
    cout << t1.name << endl;
    cout << t1.getSalary() << endl;   // salary accessed using getter

    // Another object
    Teacher t2;

    return 0;
}