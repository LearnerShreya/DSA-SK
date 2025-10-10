#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages) {
    int students = 1, pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxAllowedPages) return false;

        if (pages + arr[i] > maxAllowedPages) {
            students++;
            pages = arr[i];
            if (students > m) return false;
        } else {
            pages += arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> &arr, int n, int m) {
    if (m > n) return -1;

    int sum = accumulate(arr.begin(), arr.end(), 0);

    int low = *max_element(arr.begin(), arr.end());
    int high = sum, ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isValid(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {10, 20, 30, 40};
    int n = arr.size(), m = 2;

    cout << allocateBooks(arr, n, m) << endl; // Output: 60
    return 0;
}