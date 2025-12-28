#include <iostream>
using namespace std;

class Teacher {
private:
    double salary;
public:
    // properties / attributes
    string name;
    string dept;
    string subject;


    // methods / member functions
    void changeDept(string newDept) {
        dept = newDept;
    }

    // Setter for salary
    void setSalary(double s) {
        salary = s;
    }
    //Getter for salary
    double getSalary() {
        return salary;
    }
};


int main() {
    Teacher t1;
    Teacher t2;

    t1.name = "Shradha";
    t1.subject = "C++";
    t1.dept = "Computer Science";
    // t1.salary = 25000; // Error: 'salary' is private within this context
    t1.setSalary(25000);
    cout << t1.name << endl;
    cout << t1.getSalary() << endl;

    return 0;

}