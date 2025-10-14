#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) { // O(n^2)
    for (int i = 0; i < n - 1; i++) {
        int smallestIdx = i; // index of the smallest element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[smallestIdx]) {
            // if (arr[j] > arr[smallestIdx]) {
                smallestIdx = j;
            }
        }
        swap(arr[i], arr[smallestIdx]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {4, 1, 5, 2, 3};
    int n = 5;

    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}