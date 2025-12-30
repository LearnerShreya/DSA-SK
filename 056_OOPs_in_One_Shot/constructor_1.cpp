#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    // Default constructor
    Student() {
        cout << "Hi, I am constructor" << endl;
        name = "Unknown";
        age = 0;
    }

    // Parameterized constructor
    Student(string n, int a) {
        name = n;
        age = a;
    }

    // Copy constructor
    Student(Student &other) {
        name = other.name;
        age = other.age;
    }

    void show() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student s1;                    // Default
    Student s2("Aditi", 21);       // Parameterized
    Student s3 = s2;               // Copy

    s1.show();
    s2.show();
    s3.show();
}


// Output:

// Hi, I am constructor
// Name: Unknown, Age: 0
// Name: Aditi, Age: 21
// Name: Aditi, Age: 21