#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initialize vector
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Original vector: ";
    for (int val : vec) cout << val << " ";
    cout << "\nSize: " << vec.size() << ", Capacity: " << vec.capacity() << endl;

    // Erase first element
    vec.erase(vec.begin()); // removes element at index 0

    // Erase element at index 2 (after previous erase)
    vec.erase(vec.begin() + 2); // removes element at index 2

    // Erase range: from index 4 to index 5 (end is exclusive)
    vec.erase(vec.begin() + 4, vec.begin() + 6); 

    cout << "\nVector after erase operations: ";
    for (int val : vec) cout << val << " ";
    cout << "\nSize: " << vec.size() << ", Capacity: " << vec.capacity() << endl;

    // Insert 100 at index 2
    vec.insert(vec.begin() + 2, 100);

    cout << "\nVector after insert: ";
    for (int val : vec) cout << val << " ";
    cout << "\nSize: " << vec.size() << ", Capacity: " << vec.capacity() << endl;

    // Check if vector is empty
    cout << "\nIs vector empty? " << (vec.empty() ? "Yes" : "No") << endl;

    // Clear the vector (removes all elements, size = 0, capacity unchanged)
    vec.clear();

    cout << "\nVector after clear(): ";
    cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << endl;
    cout << "Is vector empty? " << (vec.empty() ? "Yes" : "No") << endl;

    return 0;
}