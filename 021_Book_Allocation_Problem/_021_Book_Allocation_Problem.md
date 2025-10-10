# Book Allocation Problem

---

## 1. Problem Statement

We have **n books** and each book has some number of pages. We also have **m students**.

We need to distribute the books such that:

1. Each student gets **at least one book**.
2. Books are given in **contiguous order** (no splitting or skipping).
3. The **maximum number of pages** assigned to a student is **minimized**.

If `m > n` (more students than books) → return **-1**.

---

## 2. Example

Books = `[10, 20, 30, 40]`, n = 4, m = 2

Possible allocations:

* Student1 = `[10, 20]` (30), Student2 = `[30, 40]` (70) → max = 70
* Student1 = `[10]` (10), Student2 = `[20, 30, 40]` (90) → max = 90
* Student1 = `[10, 20, 30]` (60), Student2 = `[40]` (40) → max = 60 ✅ (Best)

Answer = **60**

---

## 3. Brute Force Approach

* Try all possible contiguous partitions into `m` groups.
* For each partition, find the **maximum pages** among students.
* Return the minimum of these maximums.

**Drawback:** Exponential time → not feasible.

---

## 4. Optimized Approach (Binary Search on Answer)

### Intuition:

Instead of guessing allocations, we search for the **minimum maximum pages** using Binary Search.

* Minimum possible answer = `max(arr)` (largest single book).
* Maximum possible answer = `sum(arr)` (if one student reads all books).

Search in range `[max(arr), sum(arr)]`

---

### Step 1: The `isValid` Function

Check if we can allocate books with a limit of `maxAllowedPages`.

Algorithm:

* Keep a running sum of pages for current student.
* If sum exceeds `maxAllowedPages`, give next student the books.
* If students required > m → return **false**.
* Otherwise → return **true**.

---

### Step 2: Binary Search

1. Set `low = max(arr)`, `high = sum(arr)`.
2. While `low <= high`:

   * Find `mid = (low + high) // 2`.
   * If `isValid(mid)` → possible solution, save it and search **left half**.
   * Else search **right half**.
3. Return the best answer.

---

## 5. C++ Code

```cpp
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
```

---

## 6. Python Code

```python
def isValid(arr, n, m, maxAllowedPages):
    students = 1
    pages = 0

    for i in range(n):
        if arr[i] > maxAllowedPages:
            return False

        if pages + arr[i] > maxAllowedPages:
            students += 1
            pages = arr[i]

            if students > m:
                return False
        else:
            pages += arr[i]

    return True


def allocateBooks(arr, n, m):
    if m > n:
        return -1

    total_pages = sum(arr)
    low = max(arr)
    high = total_pages
    ans = -1

    while low <= high:
        mid = (low + high) // 2

        if isValid(arr, n, m, mid):
            ans = mid
            high = mid - 1
        else:
            low = mid + 1

    return ans


# Example
arr = [10, 20, 30, 40]
n = len(arr)
m = 2

print(allocateBooks(arr, n, m))  # Output: 60
```

---

## 7. Dry Run Example

Books = `[10, 20, 30, 40]`, m = 2

* low = 40, high = 100
* mid = 70 → isValid(70)? YES → ans = 70, search left
* low = 40, high = 69
* mid = 54 → isValid(54)? NO → search right
* low = 55, high = 69
* mid = 62 → isValid(62)? NO → search right
* low = 63, high = 69
* mid = 66 → isValid(66)? NO → search right
* low = 67, high = 69
* mid = 68 → isValid(68)? NO → search right
* low = 69, high = 69
* mid = 69 → isValid(69)? NO → search right
* low = 70, high = 69 → stop

Answer = **60**

---

## 8. Time Complexity

* `isValid` → O(N)
* Binary search range → log(sum of pages)
* Total = **O(N log(sum))**

---

## 9. Summary

* Always binary search on the **answer space**, not the array.
* Use `isValid` to check feasibility.
* Start with `low = max(arr)` and `high = sum(arr)`.
* Best allocation is the **minimum maximum pages**.

---

Book Allocation Problem

arr = [15, 17, 20], N = 3, M = 2
sum = 52
search space = 0 to 52

* mid = 26 → Invalid
* search space = 27 to 52
* mid = 39 → Valid
* search space = 27 to 38
* mid = 32 → Valid
* search space = 27 to 31
* mid = 29 → Invalid
* search space = 30 to 31
* mid = 30 → Invalid
* search space = 31 to 31
* mid = 31 → Invalid

Answer = **32** ✅

---