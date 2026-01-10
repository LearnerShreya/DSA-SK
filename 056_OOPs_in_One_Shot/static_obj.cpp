#include <iostream>
using namespace std;

class ABC {
public:
    ABC() {
        cout << "constructor\n";
    }

    ~ABC() {
        cout << "destructor\n";
    }
};

int main() {

    if (true) {
        static ABC obj;   // static object inside block
        // ABC obj;  // (uncomment this to compare behavior of non-static object)
    }

    cout << "end of main fnx\n";

    return 0;
}


// constructor
// end of main fnx
// destructor