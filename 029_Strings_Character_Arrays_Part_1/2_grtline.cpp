#include <iostream>
#include <string>
using namespace std;

int main() {
    // 1. Basic input using cin
    string name;
    cout << "Enter your first name (cin): ";
    cin >> name;  // stops at space
    cout << "You entered (cin): " << name << endl;

    cin.ignore(); // clear leftover '\n'

    // 2. Using getline() with string
    string fullName;
    cout << "Enter your full name (getline): ";
    getline(cin, fullName);
    cout << "You entered (getline): " << fullName << endl;

    // 3. Using cin.getline() with character array
    char address[50];
    cout << "Enter your address (cin.getline): ";
    cin.getline(address, 50);
    cout << "You entered (cin.getline): " << address << endl;

    // 4. Using getline() with custom delimiter
    string text;
    cout << "Enter text (stops at comma ','): ";
    getline(cin, text, ',');
    cout << "You entered (until comma): " << text << endl;

    return 0;
}



// Enter your first name (cin): Shreya Singh
// You entered (cin): Shreya
// Enter your full name (getline): Shreya Kumari Singh
// You entered (getline): Shreya Kumari Singh
// Enter your address (cin.getline): Banka, Bihar
// You entered (cin.getline): Banka, Bihar
// Enter text (stops at comma ','): Hello, how are you?
// You entered (until comma): Hello
