#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    double* cgpaPtr;

    // parameterized constructor
    Student(string name, double cgpa) {
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }
    // destructor
    ~Student() {
        cout << "Destructor called for " << name << endl;
        cout << "Hii, i delete everything using delete , mememory allocated using new keyword and pointer cgpaPtr" << endl;
        delete cgpaPtr;  // free allocated memory
    }

    void getInfo() {
        cout << "name: " << name << endl;
        cout << "cgpa: " << *cgpaPtr << endl;
    }
};

int main() {
    Student s1("Rahul Kumar", 8.9);
    s1.getInfo();
    return 0;
}