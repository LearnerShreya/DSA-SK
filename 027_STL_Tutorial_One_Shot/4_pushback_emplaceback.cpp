#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string n, int a) { 
        name = n; 
        age = a;
        cout << "Constructor called for " << name << endl;
    }
};

int main() {
    vector<Person> people;

    // Using push_back → creates a temporary object first
    people.push_back(Person("Alice", 25));

    // Using emplace_back → constructs directly inside the vector
    people.emplace_back("Bob", 30);

    cout << "\nPeople in vector:\n";
    for (auto &p : people)
        cout << p.name << " (" << p.age << " years old)" << endl;

    return 0;
}