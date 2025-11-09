#include <iostream>
#include <string>
using namespace std;

int main() {
    // 1. Using cin
    string word;
    cout << "Enter one word: ";
    cin >> word;   // stops at space
    cout << "You entered (cin): " << word << endl;

    cin.ignore();  // clear leftover newline before using getline

    // 2. Using cin.getline() with character array
    char sentence[100];
    cout << "Enter a full sentence: ";
    cin.getline(sentence, 100);  // reads entire line
    cout << "You entered (cin.getline): " << sentence << endl;

    // 3. Using getline(cin, name, delimiter)
    string text;
    cout << "Enter text (stops at comma ','): ";
    getline(cin, text, ',');  // reads until comma
    cout << "You entered (getline with delimiter): " << text << endl;

    return 0;
}



// Enter one word: Shreya Singh
// You entered (cin): Shreya
// Enter a full sentence: I love coding in C++
// You entered (cin.getline): I love coding in C++
// Enter text (stops at comma ','): Hello, how are you?
// You entered (getline with delimiter): Hello
