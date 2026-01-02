#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    double salary;

public:
    string name;
    string dept;
    string subject;

    // non-parameterized constructor
    Teacher() {
        dept = "Computer Science";
    }

    // parameterized constructor (using this pointer)
    Teacher(string name, string dept, string subject, double salary) {
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    // custom copy constructor (optional)
    // Teacher(const Teacher &t) {
    //     cout << "I am custom copy constructor" << endl;
    //     this->name = t.name;
    //     this->dept = t.dept;
    //     this->subject = t.subject;
    //     this->salary = t.salary;
    // }

    void changeDept(string newDept) {
        this->dept = newDept;
    }

    void getInfo() {
        cout << "name: " << this->name << endl;
        cout << "subject: " << this->subject << endl;
    }
};

int main() {
    Teacher t1("Shradha", "Computer Science", "C++", 25000);
    t1.getInfo();

    Teacher t2(t1); // default copy constructor called (custom version is commented)
    t2.getInfo();
    return 0;
}