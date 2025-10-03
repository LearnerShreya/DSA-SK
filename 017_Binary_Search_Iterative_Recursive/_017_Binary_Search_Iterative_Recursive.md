# Binary Search - Iterative & Recursive

---

## 1. Introduction

Binary Search is one of the most efficient algorithms for searching in a **sorted dataset**. Instead of scanning elements one by one like **Linear Search**, it works on the principle of **divide and conquer** — cutting the search space into half at every step.

* **Time Complexity:** O(log n)
* **Space Complexity:** Iterative → O(1), Recursive → O(log n)

---

## 2. Binary Search in Real-Life

We unknowingly use binary search in day-to-day life:

* Searching a word in a **dictionary** (open the middle page, then decide left/right).
* Looking up a number in a **telephone directory** (old-school example).
* Searching a name in a **sorted attendance list**.
* Guessing a number in the game “**Guess the Number**” by halving the range each time.
* Navigating in **online shopping catalogs** that are sorted by price or rating.

---

## 3. Where Do We Use Binary Search?

Binary Search is widely used in:

* **Searching problems:** e.g., “find an element in sorted array.”
* **Optimization problems:** e.g., “minimum number of pages to allocate,” “minimum time to complete tasks,” etc.
* **Library Functions:** Many programming languages (like C++ STL, Java, Python) use binary search under the hood in `lower_bound`, `upper_bound`, `bisect`, etc.
* **Competitive programming & Interviews:** To reduce O(n) solutions to O(log n).

---

## 4. Binary Search Approach

The algorithm is based on these steps:

1. Start with two pointers:

   * `low = 0` (first index)
   * `high = n - 1` (last index)

2. Find the middle index:

   * **Naive way (not safe):**

     ```python
     mid = (low + high) // 2
     ```

     This can cause **integer overflow** in some languages (like C/C++) if `low + high` exceeds the maximum integer limit.

   * **Safe way (preferred):**

     ```python
     mid = low + (high - low) // 2
     ```

     Here, we subtract first and then add, which prevents overflow while still giving the correct middle value.

   > In **Python**, integers have no fixed limit (they expand automatically), so overflow won’t occur. But in languages like **C++/Java**, using `(low + high)/2` can cause overflow. That’s why the safe formula is used everywhere in practice.

3. Compare:

   * If `arr[mid] == key` → **Element found**.
   * If `arr[mid] < key` → search in **right half** (`low = mid + 1`).
   * If `arr[mid] > key` → search in **left half** (`high = mid - 1`).

4. Repeat until `low > high`.


---

## 5. Code for Binary Search (Iterative)

```cpp
#include <iostream>
using namespace std;

int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // prevents overflow
        if (arr[mid] == key)
            return mid;   // found
        else if (arr[mid] < key)
            low = mid + 1;   // right half
        else
            high = mid - 1;  // left half
    }
    return -1; // not found
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 23;

    int result = binarySearchIterative(arr, n, key);
    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";
}
```


```python
def binary_search_iterative(arr, key):
    low, high = 0, len(arr) - 1

    while low <= high:
        mid = low + (high - low) // 2  # safer than (low+high)//2

        if arr[mid] == key:
            return mid  # element found
        elif arr[mid] < key:
            low = mid + 1  # search right half
        else:
            high = mid - 1  # search left half

    return -1  # element not found


# Example usage
arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
key = 23

result = binary_search_iterative(arr, key)
if result != -1:
    print(f"Element found at index {result}")
else:
    print("Element not found")
```

---

## 6. Dry Run of Binary Search Code

Array = `[2, 5, 8, 12, 16, 23, 38, 56, 72, 91]`, Key = `23`

* Step 1: `low=0`, `high=9`, `mid=4` → arr[4]=16 < 23 → search right half.
* Step 2: `low=5`, `high=9`, `mid=7` → arr[7]=56 > 23 → search left half.
* Step 3: `low=5`, `high=6`, `mid=5` → arr[5]=23 == 23 → Found at index **5**.

✅ Output: Element found at index 5.

---

## 7. Optimization in Code

* Instead of `(low + high) / 2`, use:

  ```cpp
  mid = low + (high - low) / 2;
  ```

  This avoids **integer overflow** when `low + high` becomes too large.
* If searching for **first occurrence or last occurrence**, modify conditions accordingly.
* For larger data, prefer **iterative implementation** to save stack memory.

---

## 8. Time Complexity of Binary Search

* Each step cuts the array size by half.
* If array size is `n`:

  * Step 1 → n/2
  * Step 2 → n/4
  * Step 3 → n/8
  * ... until 1 element remains.
* So, total steps = log₂(n).

**Complexities:**

* Best Case: O(1) (element found at first mid).
* Average Case: O(log n).
* Worst Case: O(log n).

---

## 9. Recursive Binary Search

Instead of using a loop, we use recursion to divide the array until the element is found.

### Algorithm Steps

1. Base Case: If `low > high`, return -1.
2. Find mid = (low + high)/2.
3. If arr[mid] == key → return mid.
4. If arr[mid] > key → call function on left half.
5. Else → call function on right half.

---

## 10. Code for Binary Search (Recursive)

```cpp
#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return binarySearchRecursive(arr, low, mid - 1, key);
    else
        return binarySearchRecursive(arr, mid + 1, high, key);
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 23;

    int result = binarySearchRecursive(arr, 0, n - 1, key);
    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";
}
```

```python
def binary_search_recursive(arr, low, high, key):
    if low > high:
        return -1  # element not found

    mid = low + (high - low) // 2

    if arr[mid] == key:
        return mid
    elif arr[mid] > key:
        return binary_search_recursive(arr, low, mid - 1, key)
    else:
        return binary_search_recursive(arr, mid + 1, high, key)


# Example usage
arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
key = 23

result = binary_search_recursive(arr, 0, len(arr) - 1, key)
if result != -1:
    print(f"Element found at index {result}")
else:
    print("Element not found")
```

---

### ✅ Output for both codes:

```
Element found at index 5
```

---

## 11. Summary

* Binary Search is a **divide and conquer** algorithm.
* Requires **sorted array**.
* Iterative approach → efficient in space.
* Recursive approach → elegant, closer to theory.
* Time complexity: O(log n), Space: O(1) iterative / O(log n) recursive.
* Used in searching, optimization, library functions, and competitive programming.

✅ In short: **Binary Search = Fast, Reliable, Must-Know Algorithm**.