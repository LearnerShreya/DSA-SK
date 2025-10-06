# Peak Index in Mountain Array

- https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

---

## **Problem Statement**

You are given an integer array `arr` that is a **mountain array**. A mountain array has the following properties:

1. `arr.length >= 3`
2. There exists some `i` (0 < i < arr.length - 1) such that:

   * `arr[0] < arr[1] < ... < arr[i]` (strictly increasing)
   * `arr[i] > arr[i + 1] > ... > arr[arr.length - 1]` (strictly decreasing)

Your task is to **find the index of the peak element** (the largest element where the increase switches to decrease).

**Example:**

```python
Input: arr = [0, 2, 4, 7, 6, 3, 1]
Output: 3
Explanation: arr[3] = 7 is the peak.
```

---

## **Observations**

1. The first and last elements cannot be the peak (since a peak must have both a left and right neighbor).
2. There is **exactly one peak** in a valid mountain array.
3. You can use:

   * **Linear search**: Simple but O(n)
   * **Binary search**: Efficient O(log n) approach

---

## **Approach 1: Linear Search (Brute Force)**

* Traverse the array.
* If `arr[i] > arr[i-1]` and `arr[i] > arr[i+1]`, return `i`.

```python
def peakIndexInMountainArray(arr):
    for i in range(1, len(arr) - 1):
        if arr[i] > arr[i - 1] and arr[i] > arr[i + 1]:
            return i
```

**Time Complexity:** O(n)
**Space Complexity:** O(1)

---

## **Approach 2: Binary Search (Optimal)**

**Idea:** The mountain array has two parts: increasing and decreasing.

* If `arr[mid] < arr[mid + 1]`, we are on the **increasing slope** → peak is to the **right**
* If `arr[mid] > arr[mid + 1]`, we are on the **decreasing slope** → peak is **mid or to the left**

**Steps:**

1. Initialize: `start = 0`, `end = len(arr) - 1`
2. While `start < end`:

   * `mid = start + (end - start) // 2`
   * Compare `arr[mid]` with `arr[mid + 1]`
   * If `arr[mid] < arr[mid + 1]`: move `start = mid + 1` (right side)
   * Else: move `end = mid` (left side including mid)
3. Return `start` (or `end`, both will be the peak index)

```python
def peakIndexInMountainArray(arr):
    start, end = 0, len(arr) - 1
    while start < end:
        mid = start + (end - start) // 2
        if arr[mid] < arr[mid + 1]:
            start = mid + 1
        else:
            end = mid
    return start
```

**Time Complexity:** O(log n)
**Space Complexity:** O(1)

---

## **Dry Run of Binary Search Example**

Array: `[0, 2, 4, 7, 6, 3, 1]`

| Iteration | start | end | mid | arr[mid] | arr[mid+1] | Decision                                  |
| --------- | ----- | --- | --- | -------- | ---------- | ----------------------------------------- |
| 1         | 0     | 6   | 3   | 7        | 6          | arr[mid] > arr[mid+1] → end = mid = 3     |
| 2         | 0     | 3   | 1   | 2        | 4          | arr[mid] < arr[mid+1] → start = mid+1 = 2 |
| 3         | 2     | 3   | 2   | 4        | 7          | arr[mid] < arr[mid+1] → start = mid+1 = 3 |

* `start == end == 3` → Peak index is `3`

---

## **Why Binary Search Works**

1. Mountain array is **strictly increasing then strictly decreasing**.
2. By comparing `arr[mid]` with `arr[mid+1]`, you know which side the peak is.
3. This reduces search space **by half every iteration** → O(log n)

---

## **Points to Remember**

1. Use `start + (end - start) // 2` to avoid **integer overflow** in other languages like C++/Java.
2. Only compare `arr[mid]` with `arr[mid+1]`, no need for `arr[mid-1]`.
3. Peak cannot be at index `0` or `len(arr)-1`.

---

## **Summary**

* Problem: Find peak index in a mountain array.
* Methods:

  1. Linear Search → O(n)
  2. Binary Search → O(log n)
* Binary search is preferred for large arrays.
* Key logic: Compare `arr[mid]` with `arr[mid+1]` to decide which half to continue.

---