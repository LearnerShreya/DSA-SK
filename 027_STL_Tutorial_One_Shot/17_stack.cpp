#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.empty()) {
        cout << s.top() << " ";  // print top element
        s.pop();                  // remove top element
    }
    cout << endl;

    return 0;
}