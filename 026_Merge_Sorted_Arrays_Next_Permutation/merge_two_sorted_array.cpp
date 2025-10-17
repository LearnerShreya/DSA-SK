#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& A, int m, vector<int>& B, int n) {
    int idx = m + n - 1; 
    int i = m - 1;   
    int j = n - 1;      
    
    // Merge from the end
    while (i >= 0 && j >= 0) {
        if (A[i] >= B[j]) {
            A[idx] = A[i];
            i--;
        } else {
            A[idx] = B[j];
            j--;
        }
        idx--;
    }

    // Copy remaining elements of B, if any
    while (j >= 0) {
        A[idx] = B[j];
        j--;
        idx--;
    }
}

int main() {
    vector<int> A = {1, 3, 5, 0, 0, 0}; // A has extra space for B
    vector<int> B = {2, 4, 6};
    int m = 3, n = 3;

    merge(A, m, B, n);

    cout << "Merged array: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}