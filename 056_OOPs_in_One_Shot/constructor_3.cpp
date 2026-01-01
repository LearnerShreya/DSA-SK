#include <iostream>
using namespace std;

class Teacher {
private:
    double salary;          // private → hidden from outside the class

public:
    string name;
    string dept;
    string subject;
    string branch;

    // Constructor
    // always public, it can;t be private
    Teacher() {
        cout << "Hi, I am constructor" << endl;
        salary = 0;        // initialize private data
        branch = "Not Assigned";
        dept = "Computer Science";
    }

    // Change department
    void changeDept(string newDept) {
        dept = newDept;
    }

    // Setter → write salary
    void setSalary(double s) {
        salary = s;
    }

    // Getter → read salary
    double getSalary() {
        return salary;
    }
};

int main() {
    Teacher t1;   // constructor called automatically
    Teacher t2;   // constructor called automatically

    t1.name = "Shradha";
    t1.subject = "C++";

    t1.setSalary(25000);

    cout << t1.name << endl;
    cout << t1.getSalary() << endl;
    cout << t1.branch << endl;
    cout << t2.branch << endl;
    cout << t1.dept << endl;

    return 0;
}