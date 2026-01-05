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

    // deep copy constructor
    Student(const Student &obj) {
        this->name = obj.name;
        cgpaPtr = new double;             // allocate new memory
        *cgpaPtr = *(obj.cgpaPtr);        // copy actual value (not address)
    }

    void getInfo() {
        cout << "name: " << name << endl;
        cout << "cgpa: " << *cgpaPtr << endl;
    }
};

int main() {
    Student s1("Rahul Kumar", 8.9);
    Student s2(s1); // deep copy

    *(s2.cgpaPtr) = 9.2;   // modifying only s2

    cout << "\ns1 details:\n";
    s1.getInfo();          // CGPA remains unchanged

    s2.name = "Neha";      // changing name only in s2

    cout << "\ns2 details:\n";
    s2.getInfo();          // CGPA and name changes only for s2

    return 0;
}
