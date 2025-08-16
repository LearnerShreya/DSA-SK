#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int target = 9;
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {  // started from i+1 to avoid repeats
            if (arr[i] + arr[j] == target) {
                cout << "Pair found at indices: " << i << " and " << j << endl;
                cout << "Values: " << arr[i] << " and " << arr[j] << endl;
                return 0;
            }
        }
    }
    cout << "No pair found" << endl;
    return 0;
}