#include <iostream>
using namespace std;

class Teacher {

    // properties / attributes
    string name;
    string dept;
    string subject;
    double salary;

    // methods / member functions
    void changeDept(string newDept) {
        dept = newDept;
    }

};

int main() {
    Teacher t1;
    Teacher t2;

    // t1.name = "Shradha";  // Error: 'name' is private within this context
    // t1.dept = "Computer Science";
    // t1.salary = 25000;

    // cout << t1.name << endl;

    return 0;

}