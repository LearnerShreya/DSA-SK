- https://www.youtube.com/watch?v=goqe7OZrJt4

# 📌 Searching Algorithms in C++ & Python (with Pseudocode)

---

## 1. Basics of Searching

**Goal:** Given a collection and a target value, determine:

* Existence
* Position
* Sometimes extra info (first position, last position, count, etc.)

Two major categories:

1. **Unsorted search → Linear Search**
2. **Sorted search → Binary Search and Variants**

---

## 2. Linear Search

### Pseudocode

```
LINEAR-SEARCH(arr, target):
    for i from 0 to length(arr) - 1:
        if arr[i] == target:
            return i
    return -1
```

### C++ Code

```cpp
int linearSearch(const vector<int> &arr, int target) {
    for (int i = 0; i < (int)arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}
```

### Python Code

```python
def linear_search(arr, target):
    for i, val in enumerate(arr):
        if val == target:
            return i
    return -1
```

---

## 3. Binary Search (Iterative)

Works only on **sorted arrays**.

### Pseudocode

```
BINARY-SEARCH(arr, target):
    low ← 0
    high ← length(arr) - 1

    while low ≤ high:
        mid ← low + (high - low) // 2

        if arr[mid] == target:
            return mid
        else if arr[mid] < target:
            low ← mid + 1
        else:
            high ← mid - 1

    return -1
```

### C++ Code

```cpp
int binarySearch(const vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

### Python Code

```python
def binary_search(arr, target):
    low, high = 0, len(arr) - 1
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

---

## 4. Binary Search (Recursive)

### Pseudocode

```
BINARY-SEARCH-REC(arr, low, high, target):
    if low > high:
        return -1

    mid ← low + (high - low) // 2

    if arr[mid] == target:
        return mid
    else if arr[mid] < target:
        return BINARY-SEARCH-REC(arr, mid + 1, high, target)
    else:
        return BINARY-SEARCH-REC(arr, low, mid - 1, target)
```

### C++ Code

```cpp
int binarySearchRecursive(const vector<int> &arr, int low, int high, int target) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target) return binarySearchRecursive(arr, mid + 1, high, target);
    return binarySearchRecursive(arr, low, mid - 1, target);
}
```

### Python Code

```python
def binary_search_recursive(arr, low, high, target):
    if low > high:
        return -1
    mid = low + (high - low) // 2
    if arr[mid] == target:
        return mid
    if arr[mid] < target:
        return binary_search_recursive(arr, mid + 1, high, target)
    return binary_search_recursive(arr, low, mid - 1, target)
```

---

## 5. First Occurrence (Binary Search Variant)

### Pseudocode

```
FIRST-OCCURRENCE(arr, target):
    low ← 0, high ← length(arr) - 1
    ans ← -1
    while low ≤ high:
        mid ← low + (high - low) // 2
        if arr[mid] == target:
            ans ← mid
            high ← mid - 1
        else if arr[mid] < target:
            low ← mid + 1
        else:
            high ← mid - 1
    return ans
```

### C++ Code

```cpp
int firstOccurrence(const vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) ans = mid, high = mid - 1;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}
```

### Python Code

```python
def first_occurrence(arr, target):
    low, high, ans = 0, len(arr) - 1, -1
    while low <= high:
        mid = low + (high - low) // 2
        if arr[mid] == target:
            ans = mid
            high = mid - 1
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return ans
```

---

## 6. Last Occurrence (Binary Search Variant)

### Pseudocode

```
LAST-OCCURRENCE(arr, target):
    low ← 0, high ← length(arr) - 1
    ans ← -1
    while low ≤ high:
        mid ← low + (high - low) // 2
        if arr[mid] == target:
            ans ← mid
            low ← mid + 1
        else if arr[mid] < target:
            low ← mid + 1
        else:
            high ← mid - 1
    return ans
```

### C++ Code

```cpp
int lastOccurrence(const vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) ans = mid, low = mid + 1;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}
```

### Python Code

```python
def last_occurrence(arr, target):
    low, high, ans = 0, len(arr) - 1, -1
    while low <= high:
        mid = low + (high - low) // 2
        if arr[mid] == target:
            ans = mid
            low = mid + 1
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return ans
```

---

## 7. Count Occurrences

```
COUNT = last_occurrence − first_occurrence + 1 
```

---

## 8. Ternary Search

Used on **unimodal functions (increasing then decreasing)**.

### Pseudocode

```
TERNARY-SEARCH(l, r):
    while r - l > ε:
        mid1 ← l + (r - l) / 3
        mid2 ← r - (r - l) / 3

        if f(mid1) < f(mid2):
            l ← mid1
        else:
            r ← mid2
    return l   // or r (approx. max/min position)
```

---

## 9. Exponential Search

### Pseudocode

```
EXPONENTIAL-SEARCH(arr, target):
    if arr[0] == target:
        return 0

    i ← 1
    while i < length(arr) and arr[i] ≤ target:
        i ← i * 2

    return BINARY-SEARCH(arr, target, i/2, min(i, length(arr)-1))
```

---

## 10. Quick Summary Table

| Method                | Sorted? | Worst Time |
| --------------------- | ------- | ---------- |
| Linear Search         | No      | O(n)       |
| Binary Search         | Yes     | O(log n)   |
| First/Last Occurrence | Yes     | O(log n)   |
| Count Occurrences     | Yes     | O(log n)   |
| Ternary Search        | Yes     | O(log n)   |
| Exponential Search    | Yes     | O(log n)   |

---