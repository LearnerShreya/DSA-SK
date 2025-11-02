#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // Push elements into stack s
    s.push(1);
    s.push(2);
    s.push(3);

    // Create another stack s2 and swap with s
    stack<int> s2;
    s2.swap(s);

    // Now s is empty, s2 has the elements
    cout << "Stack s after swap (should be empty): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    // Push some elements back to s for demonstration
    s.push(10);
    s.push(20);

    cout << "Stack s2 (elements from original s): ";
    while (!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;

    // Show sizes
    cout << "s size: " << s.size() << endl;   // 2
    cout << "s2 size: " << s2.size() << endl; // 0

    return 0;
}