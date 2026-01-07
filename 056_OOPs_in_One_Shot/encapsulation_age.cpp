#include <iostream>
using namespace std;

class Person {
private:
    int age;                    // private → only inside Person

protected:
    string address;             // protected → inside Person + derived class

public:
    string name;                // public → anywhere

    void setAge(int a) {        // setter to update private data safely
        if (a > 0)
            age = a;
    }
    int getAge() {              // getter to read private data
        return age;
    }
};

class Student : public Person {
public:
    void setAddress(string ad) {
        address = ad;           // allowed because address is protected
    }

    void show() {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Age: " << getAge() << endl;
    }
};

int main() {
    Student s;
    s.name = "Aditi";           // public access allowed
    s.setAddress("Chandigarh");
    s.setAge(21);               // age cannot be accessed directly because it's private

    s.show();
    return 0;
}