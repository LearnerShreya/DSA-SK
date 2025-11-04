#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s = {5, 10, 15, 20, 25};

    cout << "Set elements: ";
    for (int x : s) cout << x << " ";
    cout << "\n\n";

    int val1 = 15;
    int val2 = 18;
    int val3 = 30;

    // Example 1: value present
    auto lb1 = s.lower_bound(val1);
    auto ub1 = s.upper_bound(val1);
    cout << "For value " << val1 << ":\n";
    cout << "  lower_bound -> " << (lb1 != s.end() ? to_string(*lb1) : "Not found") << endl;
    cout << "  upper_bound -> " << (ub1 != s.end() ? to_string(*ub1) : "Not found") << endl << endl;

    // Example 2: value not present (18)
    auto lb2 = s.lower_bound(val2);
    auto ub2 = s.upper_bound(val2);
    cout << "For value " << val2 << ":\n";
    cout << "  lower_bound -> " << (lb2 != s.end() ? to_string(*lb2) : "Not found") << endl;
    cout << "  upper_bound -> " << (ub2 != s.end() ? to_string(*ub2) : "Not found") << endl << endl;

    // Example 3: value larger than all elements (30)
    auto lb3 = s.lower_bound(val3);
    auto ub3 = s.upper_bound(val3);
    cout << "For value " << val3 << ":\n";
    cout << "  lower_bound -> " << (lb3 != s.end() ? to_string(*lb3) : "Not found") << endl;
    cout << "  upper_bound -> " << (ub3 != s.end() ? to_string(*ub3) : "Not found") << endl;

    return 0;
}



// // Output:
// Set elements: 5 10 15 20 25

// For value 15:
// // Exact match found
//   lower_bound -> 15
//   upper_bound -> 20

// For value 18:
// // Next greater element
//   lower_bound -> 20
//   upper_bound -> 20

// For value 30:
// // No element >= or > 30
//   lower_bound -> Not found
//   upper_bound -> Not found