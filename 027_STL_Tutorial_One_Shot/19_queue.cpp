#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Push elements into the queue
    q.push(1);
    q.push(2);
    q.push(3); // Queue: 1(front), 2, 3(back)

    // Access and remove elements (FIFO order)
    cout << "Queue elements: ";
    while (!q.empty()) {
        cout << q.front() << " "; // Access front element
        q.pop();                  // Remove front element
    }
    cout << endl;

    return 0;
}