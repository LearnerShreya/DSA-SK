
// Using a loop
// Using two pointers
// Using built-in functions
// Input/output

#include<iostream>
#include<algorithm> // for reverse()
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    // 1️⃣ Print Original
    cout << "Original Array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    // 2️⃣ Method 1: Reverse using two pointers
    int left = 0, right = size - 1;
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }

    cout << "Reversed (Two Pointers): ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    // 3️⃣ Method 2: Using STL reverse()
    reverse(arr, arr + size);  // Reverses again to original
    cout << "Reversed (STL reverse()): ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    // 4️⃣ Method 3: Using loop (manual)
    cout << "Reversed (for loop): ";
    for (int i = size - 1; i >= 0; i--) cout << arr[i] << " ";
    cout << endl;

    return 0;
}