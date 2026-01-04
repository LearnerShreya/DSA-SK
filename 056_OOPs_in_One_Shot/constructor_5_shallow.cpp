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
        // cgpaPtr = new double;
        // *cgpaPtr = cgpa;
        cgpaPtr = new double(cgpa);
    }

    // shallow copy constructor
    Student(const Student &obj) {
        this->name = obj.name;
        this->cgpaPtr = obj.cgpaPtr;   // only address copied (shared memory)
    }

    void getInfo() {
        cout << "name: " << name << endl;
        cout << "cgpa: " << *cgpaPtr << endl;
    }
};

int main() {
    Student s1("Rahul Kumar", 8.9);
    
    cout << "\n--- Original Object (s1) ---\n";
    s1.getInfo();

    Student s2(s1); // shallow copy
    *(s2.cgpaPtr) = 9.2;  // updating cgpa through s2

    cout << "\n--- After modifying s2.cgpaPtr ---\n";
    cout << "\ns1 details:\n";
    s1.getInfo();           // CGPA changes here also
    cout << "\ns2 details:\n";
    s2.getInfo();

    return 0;
}
