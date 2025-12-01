- https://www.youtube.com/watch?v=goqe7OZrJt4

# Searching algorithms in C++ Python

---

## Searching – Definition

**Searching** is the process of locating a specific element (called the *target* or *key*) within a collection of data.
The goal of searching is to determine:

1. Whether the target exists in the collection
2. If it exists, the position or index where it is found
3. In some cases, additional information such as first occurrence, last occurrence, count of occurrences, or the closest valid answer

A searching algorithm specifies the systematic steps to compare the target with elements of the dataset until the answer is found.
The efficiency of a searching algorithm is primarily measured by **time complexity** (number of comparisons) and **space complexity** (extra memory needed).

---

## 1. Basics of Searching

**Goal:** Given a collection and a target value, find:

* Whether it exists
* Its position
* Sometimes extra info (first position, last, count, minimum value that satisfies a condition, etc.)

Terms:

* $n$ = number of elements
* **Time complexity** ≈ how many comparisons in worst/average case
* Two main categories here:

  1. **Unsorted search** → usually linear search
  2. **Sorted search** → binary search and variants

---

## 2. Linear Search (Sequential Search)

### Idea

* Check elements one by one from start to end until:

  * You find the target
  * Or you reach the end

Works on **any** container, sorted or unsorted.

### C++ code

```cpp
int linearSearch(const vector<int> &arr, int target) {
    for (int i = 0; i < (int)arr.size(); i++) {
        if (arr[i] == target) {
            return i;  // found at index i
        }
    }
    return -1;  // not found
}
```

### Python code

```python
def linear_search(arr, target):
    for i, val in enumerate(arr):
        if val == target:
            return i  # found
    return -1  # not found
```

### Complexity

* Best case: $O(1)$ (first element is target)
* Worst/average: $O(n)$ comparisons
* Space: $O(1)$

### When is linear search good

* Very small $n$
* Data is unsorted and you only search once or rarely
* Container where random access is slow or not available (linked list etc.)

---

## 3. Binary Search (Basic)

### Core idea

* Only works on **sorted** data (non-decreasing or non-increasing, but you must know the order).
* Repeatedly:

  1. Look at the middle element
  2. If it is equal to target → done
  3. If target is smaller → search left half
  4. If target is larger → search right half

Each step halves the search space.

### Iterative Binary Search on ascending array

#### C++

```cpp
int binarySearch(const vector<int> &arr, int target) {
    int low = 0;
    int high = (int)arr.size() - 1;

    while (low <= high) {
        // to avoid overflow in languages with 32-bit int:
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;    // go right
        } else {
            high = mid - 1;   // go left
        }
    }

    return -1;  // not found
}
```

#### Python

```python
def binary_search(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = low + (high - low) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return -1
```

### Recursive Binary Search (for understanding)

#### C++

```cpp
int binarySearchRecursive(const vector<int> &arr, int low, int high, int target) {
    if (low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;

    if (arr[mid] == target) return mid;
    if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, high, target);
    else
        return binarySearchRecursive(arr, low, mid - 1, target);
}
```

Call with:

```cpp
int idx = binarySearchRecursive(arr, 0, arr.size() - 1, target);
```

#### Python

```python
def binary_search_recursive(arr, low, high, target):
    if low > high:
        return -1
    mid = low + (high - low) // 2

    if arr[mid] == target:
        return mid
    if arr[mid] < target:
        return binary_search_recursive(arr, mid + 1, high, target)
    else:
        return binary_search_recursive(arr, low, mid - 1, target)
```

Call with:

```python
idx = binary_search_recursive(arr, 0, len(arr) - 1, target)
```

### Complexity

If the length of the range shrinks like:

$$
n,\ \frac{n}{2},\ \frac{n}{4},\dots,\ 1
$$

Number of steps is about $\log_2 n$.

* Time: $O(\log n)$
* Space: $O(1)$ for iterative, $O(\log n)$ for recursive (call stack)

### Common binary search bugs

* Infinite loop (not updating low or high correctly)
* Wrong mid formula in languages where `low + high` can overflow
* Off by one in conditions like `low < high` vs `low <= high`
* Forgetting array must be sorted

---

## 4. Binary Search Variants (First, Last, Count)

Very common in interview/DSA questions.

### 4.1 Find first occurrence of target (lower bound style)

Example: arr = [1,2,2,2,3], target = 2 → answer index 1

Idea:

* Keep normal binary search, but:

  * When you find the target, move towards left to see if there is another occurrence
  * Track the best answer

#### C++

```cpp
int firstOccurrence(const vector<int> &arr, int target) {
    int low = 0, high = (int)arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            ans = mid;       // possible answer
            high = mid - 1;  // go left to find earlier
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
```

#### Python

```python
def first_occurrence(arr, target):
    low, high = 0, len(arr) - 1
    ans = -1

    while low <= high:
        mid = low + (high - low) // 2
        if arr[mid] == target:
            ans = mid
            high = mid - 1  # search left side
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return ans
```

### 4.2 Find last occurrence (upper bound style)

Same pattern, but when found, move right.

#### C++

```cpp
int lastOccurrence(const vector<int> &arr, int target) {
    int low = 0, high = (int)arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            ans = mid;
            low = mid + 1;  // go right
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
```

#### Python

```python
def last_occurrence(arr, target):
    low, high = 0, len(arr) - 1
    ans = -1

    while low <= high:
        mid = low + (high - low) // 2
        if arr[mid] == target:
            ans = mid
            low = mid + 1    # search right side
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return ans
```

### 4.3 Count occurrences

If first index is `f` and last index is `l` and both are not `-1`, then:

$$
\text{count} = l - f + 1
$$

---

## 5. Binary Search on Answer (Search in Monotonic Space)

Used when:

* The **answer itself** is a number (like minimum time, minimum capacity, max value satisfying constraint)
* You can check a function `can(x)` that is:

  * True for all `x` greater than or equal to some boundary
  * False for all `x` less than that boundary
    (or the reverse)

So `can(x)` is monotonic over `x`.

### Generic pattern

#### C++

```cpp
bool can(long long x) {
    // Problem-specific check:
    // return true if x is a valid answer, false otherwise
}

long long binarySearchAnswer(long long low, long long high) {
    long long ans = -1;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (can(mid)) {
            ans = mid;       // mid is a valid (maybe not optimal) answer
            high = mid - 1;  // try to find a better (smaller) one
        } else {
            low = mid + 1;   // need larger value
        }
    }
    return ans;
}
```

#### Python

```python
def can(x):
    # problem-specific
    # return True if x is a valid answer else False
    ...

def binary_search_answer(low, high):
    ans = None
    while low <= high:
        mid = low + (high - low) // 2
        if can(mid):
            ans = mid          # mid works
            high = mid - 1     # try to minimize
        else:
            low = mid + 1      # need bigger
    return ans
```

Used in problems like:

* Minimum capacity of ship to carry packages within D days
* Allocate minimum pages to students
* Aggressive cows (maximized minimum distance)
* Many LeetCode/Codeforces problems

---

## 6. Other Searching Methods on Arrays (Short Notes)

You mostly just need to know about these; they are rarely implemented in interviews compared to binary search.

### 6.1 Ternary Search

* Works on **unimodal functions** (strictly increasing then strictly decreasing, or reverse)
* Instead of splitting into 2 parts (binary), split into 3 using two mid points
* Time complexity: still $$O(\log n)$$
* Often used in **continuous** optimization with doubles (search on answer type)

### 6.2 Jump Search

* For sorted arrays
* Jump ahead by fixed steps (like $$\sqrt{n}$$) and then do linear search in the block where target can lie
* Time complexity: $$O(\sqrt{n})$$

### 6.3 Interpolation Search

* Works on sorted arrays, especially when values are **uniformly distributed**

* Instead of mid = (low + high)/2, estimate position based on value:

  $$
  \text{pos} = \text{low} + \frac{(target - arr[low]) \cdot (high - low)}{arr[high] - arr[low]}
  $$

* Average: $$O(\log \log n)$$, worst case: $$O(n)$$

### 6.4 Exponential Search

* For sorted arrays with unknown length or very large lists
* Steps:

  1. Find a range where target can lie by increasing index like 1, 2, 4, 8, 16, ...
  2. Do binary search within that range
* Complexity: $$O(\log n)$$

---

## 7. Library Functions for Searching

In real code, you usually use library functions rather than writing loops every time.

### 7.1 C++ (STL algorithms)

All in `<algorithm>`.

```cpp
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr = {1, 3, 5, 7, 9};
int target = 5;

// 1) Linear search
auto it = find(arr.begin(), arr.end(), target);
if (it != arr.end()) {
    int index = it - arr.begin();
}

// 2) Binary search (for sorted containers)
bool exists = binary_search(arr.begin(), arr.end(), target);

// 3) lower_bound and upper_bound
auto lb = lower_bound(arr.begin(), arr.end(), target); // first element >= target
auto ub = upper_bound(arr.begin(), arr.end(), target); // first element > target

int lbIndex = lb - arr.begin();
int ubIndex = ub - arr.begin();
int count = ubIndex - lbIndex; // number of occurrences
```

### 7.2 Python

```python
arr = [1, 3, 5, 7, 9]
target = 5

# 1) Linear search style
exists = target in arr              # True or False
idx = arr.index(target)             # raises ValueError if not found

# 2) Binary search using bisect on sorted arr
import bisect

# index to insert while keeping array sorted (first position >= target)
lb_index = bisect.bisect_left(arr, target)

# first index > target
ub_index = bisect.bisect_right(arr, target)

exists_sorted = (lb_index < len(arr) and arr[lb_index] == target)
count = ub_index - lb_index
```

---

## 8. Quick Summary Table

| Method                  | Needs sorted? | Typical use                  | Time (worst)              |
| ----------------------- | ------------- | ---------------------------- | ------------------------- |
| Linear search           | No            | Small or unsorted arrays     | $$O(n)$$                  |
| Binary search           | Yes           | Any sorted array             | $$O(\log n)$$             |
| First/last occurrence   | Yes           | Duplicates in sorted array   | $$O(\log n)$$             |
| Binary search on answer | Monotonic fn  | Optimization, constraints    | $$O(\log(\text{range}))$$ |
| Jump search             | Yes           | Sorted, moderate size        | $$O(\sqrt{n})$$           |
| Interpolation search    | Yes           | Sorted, uniform distribution | $$O(n)$$ worst            |
| Exponential search      | Yes           | Unknown/large size arrays    | $$O(\log n)$$             |

---