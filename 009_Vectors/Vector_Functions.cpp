#include <iostream>
#include <vector>
using namespace std;

int main() {
    // -------------------------------
    // 1. Creating and Initializing a Vector
    // -------------------------------
    vector<int> v = {10, 20, 30};
    cout << "Initial vector: ";
    for (int x : v) cout << x << " ";
    cout << "\n\n";

    // -------------------------------
    // 2. Element Access Functions
    // -------------------------------
    cout << "Access using operator[]: " << v[1] << endl;     // 20 (no bound check)
    cout << "Access using at(): " << v.at(1) << endl;        // 20 (safe)
    cout << "First element (front): " << v.front() << endl;  // 10
    cout << "Last element (back): " << v.back() << endl;     // 30
    cout << "Data pointer first element: " << *v.data() << "\n\n"; // 10

    // -------------------------------
    // 3. Capacity Functions
    // -------------------------------
    cout << "Size: " << v.size() << endl;            // 3
    cout << "Capacity: " << v.capacity() << endl;    // Usually >= 3
    cout << "Max size: " << v.max_size() << endl;    // Very large number
    cout << "Is empty? " << (v.empty() ? "Yes" : "No") << "\n";

    // Resizing vector
    v.resize(5); // Adds 0 at new positions
    cout << "After resize to 5: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    // Reserve capacity
    v.reserve(10);
    cout << "After reserve(10), capacity: " << v.capacity() << endl;

    // Shrink capacity to fit size
    v.shrink_to_fit();
    cout << "After shrink_to_fit(), capacity: " << v.capacity() << "\n\n";

    // -------------------------------
    // 4. Iterators
    // -------------------------------
    cout << "Using iterators (forward): ";
    for (auto it = v.begin(); it != v.end(); it++) cout << *it << " ";
    cout << "\n";

    cout << "Using reverse iterators: ";
    for (auto rit = v.rbegin(); rit != v.rend(); rit++) cout << *rit << " ";
    cout << "\n\n";

    // -------------------------------
    // 5. Modifiers
    // -------------------------------
    v.clear(); // Remove all elements
    cout << "After clear(), size: " << v.size() << "\n";

    v.assign(3, 100); // Assign 3 copies of 100
    cout << "After assign(3, 100): ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    v.push_back(200);
    cout << "After push_back(200): ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    v.emplace_back(300); // Faster than push_back
    cout << "After emplace_back(300): ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    v.insert(v.begin() + 1, 50); // Insert at 2nd position
    cout << "After insert at position 1 (50): ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    v.emplace(v.begin() + 2, 75); // Emplace at 3rd position
    cout << "After emplace at position 2 (75): ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    v.pop_back(); // Remove last element
    cout << "After pop_back(): ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    v.erase(v.begin() + 1); // Erase element at position 1
    cout << "After erase at position 1: ";
    for (int x : v) cout << x << " ";
    cout << "\n\n";

    // -------------------------------
    // 6. Swap two vectors
    // -------------------------------
    vector<int> v2 = {500, 600};
    v.swap(v2);
    cout << "After swap with v2: ";
    for (int x : v) cout << x << " ";
    cout << "\n\n";

    // -------------------------------
    // 7. Comparison Operators
    // -------------------------------
    vector<int> a = {1, 2, 3};
    vector<int> b = {1, 2, 3};
    vector<int> c = {1, 3};

    cout << "a == b? " << (a == b ? "Yes" : "No") << "\n"; // Yes
    cout << "a < c? " << (a < c ? "Yes" : "No") << "\n";   // Yes (lexicographically)

    return 0;
}
