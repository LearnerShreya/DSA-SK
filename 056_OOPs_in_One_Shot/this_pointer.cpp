#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    double salary;

public:
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

    string name;
    string dept;
    string subject;

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
    return 0;
}