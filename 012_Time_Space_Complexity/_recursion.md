# Time Complexity of Recursion

---

## Introduction

Recursion is a technique where a function calls itself directly or indirectly to solve a problem.
When analyzing recursion, the **time complexity** tells us how the running time of the recursive algorithm grows with the input size.

The time complexity of recursion depends on two factors:

1. **Number of recursive calls made**
2. **Work done in each recursive call (apart from the recursive calls themselves)**

---

## Approaches to Analyze Time Complexity

### 1. Recurrence Relation Method

* A recurrence relation expresses the time complexity in terms of smaller subproblems.

* General form:

  $$
  T(n) = a \cdot T\left(\frac{n}{b}\right) + f(n)
  $$

  where:

  * $a$ = number of recursive calls per step
  * $n/b$ = size of each subproblem
  * $f(n)$ = work done outside recursion

* This method is solved using:

  * Substitution method
  * Recursion tree method
  * Master theorem

---

### 2. Counting Method (Total Calls × Work per Call)

* Instead of recurrence, directly count the **total number of recursive calls**.
* Multiply it by the **work done per call**.
* This method is more intuitive for simple recursive algorithms.

---

## Examples

### Example 1: Factorial

```cpp
int fact(int n) {
    if (n == 0) return 1;
    return n * fact(n - 1);
}
```

* Recurrence:

  $$
  T(n) = T(n-1) + O(1)
  $$
* Total calls = $n$, each call does $O(1)$ work.
* Time Complexity: **O(n)**

---

### Example 2: Fibonacci (Naive)

```cpp
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```

* Recurrence:

  $$
  T(n) = T(n-1) + T(n-2) + O(1)
  $$
* Each call generates two new calls, leading to exponential growth.
* Total calls ≈ $2^n$, each call does $O(1)$ work.
* Time Complexity: **O(2^n)**

---

### Example 3: Binary Search

```cpp
int binarySearch(int arr[], int l, int r, int x) {
    if (l > r) return -1;
    int mid = (l + r) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
}
```

* Recurrence:

  $$
  T(n) = T(n/2) + O(1)
  $$
* Total calls ≈ $\log n$, each call does $O(1)$ work.
* Time Complexity: **O(log n)**

---

### Example 4: Merge Sort

```cpp
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);  // O(n)
    }
}
```

* Recurrence:

  $$
  T(n) = 2T(n/2) + O(n)
  $$
* Solving using Master Theorem gives:

  $$
  T(n) = O(n \log n)
  $$
* Time Complexity: **O(n log n)**

---

### Example 5: Tower of Hanoi

* Recurrence:

  $$
  T(n) = 2T(n-1) + O(1)
  $$
* This grows exponentially.
* Time Complexity: **O(2^n)**

---

## Summary Table

| Problem / Algorithm | Recurrence Relation      | Counting Method           | Time Complexity |
| ------------------- | ------------------------ | ------------------------- | --------------- |
| Factorial           | $T(n) = T(n-1) + O(1)$   | $n \times O(1)$           | O(n)            |
| Fibonacci (naive)   | $T(n) = T(n-1) + T(n-2)$ | $\approx 2^n \times O(1)$ | O(2^n)          |
| Binary Search       | $T(n) = T(n/2) + O(1)$   | $\log n \times O(1)$      | O(log n)        |
| Merge Sort          | $T(n) = 2T(n/2) + O(n)$  | $(n \log n)$              | O(n log n)      |
| Tower of Hanoi      | $T(n) = 2T(n-1) + O(1)$  | $\approx 2^n \times O(1)$ | O(2^n)          |

---

## Conclusion

* Time complexity of recursion can be analyzed either by:

  1. **Recurrence relations** (formal and general method)
  2. **Counting total calls × work per call** (simpler method for basic problems)

Both approaches ultimately give the same complexity result.

* Use **recurrence relation** for complex divide-and-conquer algorithms.
* Use **counting calls** for simpler recursions like factorial and Fibonacci.

---

---

# Recursion Tree Method for Time Complexity

---

## Example 1: Fibonacci (Naive)

### Function

```cpp
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```

### Step 1: Expand calls for `fib(5)`

```
fib(5)
 ├── fib(4)
 │    ├── fib(3)
 │    │    ├── fib(2)
 │    │    │    ├── fib(1)
 │    │    │    └── fib(0)
 │    │    └── fib(1)
 │    └── fib(2)
 │         ├── fib(1)
 │         └── fib(0)
 └── fib(3)
      ├── fib(2)
      │    ├── fib(1)
      │    └── fib(0)
      └── fib(1)
```

### Step 2: Count nodes (function calls)

* Each node is one call to `fib()`.
* For `fib(5)`, we already have **15 calls**.
* As `n` grows, the number of calls grows like a binary tree.

### Step 3: Total calls estimation

* Height of recursion tree ≈ $n$
* Each level roughly doubles → total nodes ≈ $2^n$

### Time Complexity

$$
T(n) = O(2^n)
$$

---

## Example 2: Merge Sort

### Function

```cpp
mergeSort(arr, l, r):
    if l < r:
        m = (l+r)/2
        mergeSort(arr, l, m)
        mergeSort(arr, m+1, r)
        merge(arr, l, m, r)   // O(n)
```

### Step 1: Expand recurrence

For input size $n$:

$$
T(n) = 2T(n/2) + O(n)
$$

### Step 2: Build recursion tree

* Level 0 (root): 1 problem of size $n$, cost = $O(n)$
* Level 1: 2 subproblems of size $n/2$, cost = $2 \cdot O(n/2) = O(n)$
* Level 2: 4 subproblems of size $n/4$, cost = $4 \cdot O(n/4) = O(n)$
* … continues until size = 1

### Step 3: Count levels

* Depth of tree = $\log n$

### Step 4: Total cost

Each level contributes $O(n)$, and there are $\log n$ levels:

$$
T(n) = O(n \log n)
$$

---

## Key Observations

1. **Fibonacci (naive)** recursion tree grows like a full binary tree → exponential time.
2. **Merge Sort** recursion tree has same cost at each level → multiplies to $n \log n$.

---