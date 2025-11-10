#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    // string class (dynamic, can be reassigned)
    string str = "apna college";  
    cout << str << endl;

    str = "hello";  // allowed - string is dynamic
    cout << str << endl;

    // character array (static, cannot be reassigned)
    char chArr[] = "apna college";
    // chArr = "hello"; // ❌ Not allowed! can’t reassign a char array like this.

    // If you want to change it, you can copy into it:
    strcpy(chArr, "hello"); // ✅ use strcpy from <cstring>
    cout << chArr << endl;

    return 0;
}