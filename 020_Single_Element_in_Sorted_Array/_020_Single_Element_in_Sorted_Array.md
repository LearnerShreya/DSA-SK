# Single Element in Sorted Array

---

## **Problem Statement**

Given a **sorted array** where **every element appears exactly twice**, except for **one element that appears only once**. Your task is to find that single element.

**Example 1:**

```
Input: [1,1,2,3,3,4,4,5,5]
Output: 2
```

**Example 2:**

```
Input: [0,0,1,1,2,3,3]
Output: 2
```

**Constraints:**

* Array is **sorted**
* All elements appear **twice** except one
* Array length is **odd** (because one single element breaks pairs)

---

## **1. Brute Force Approach**

**Idea:** Check each element and see if it has a duplicate next to it.

**Steps:**

1. Traverse the array from left to right.
2. Compare each element with its neighbor.
3. If `A[i] != A[i+1]`, then `A[i]` is the single element.
4. Skip the next element if it forms a pair.

**Code (Python):**

```python
def singleNonDuplicateBrute(A):
    n = len(A)
    i = 0
    while i < n:
        # If it's the last element or not equal to next
        if i == n-1 or A[i] != A[i+1]:
            return A[i]
        i += 2  # skip the next as it is part of the pair
```

**Time Complexity:** `O(n)` – traverses the whole array
**Space Complexity:** `O(1)` – no extra space used

✅ Works for small arrays, but slow for large arrays.

---

## **2. Optimized Approach (Binary Search)**

**Idea:** Use the **sorted property** and **pair structure** to find the single element in **logarithmic time**.

### **Observation**

* In a perfectly paired array:

  * The first of the pair is at **even index** (0,2,4…)
  * The second of the pair is at **odd index** (1,3,5…)
* When the single element appears, it **shifts the pair sequence** to the right of it.
* Use **binary search** to find the breaking point.

---

### **Steps**

1. Initialize `start = 0`, `end = n-1`.
2. While `start <= end`:

   * Calculate `mid = start + (end-start)//2`.
   * **Check if mid is the single element**:

     * If `mid` is first element: `A[mid] != A[mid+1]` → single found.
     * If `mid` is last element: `A[mid] != A[mid-1]` → single found.
     * Otherwise: `A[mid] != A[mid-1]` and `A[mid] != A[mid+1]` → single found.
   * Decide which side to search:

     * If `mid` is **even**:

       * `A[mid] == A[mid+1]` → single is **right**
       * Else → single is **left**
     * If `mid` is **odd**:

       * `A[mid] == A[mid-1]` → single is **right**
       * Else → single is **left**
3. Repeat until found.

---

### **Code (Python)**

```python
from typing import List

class Solution:
    def singleNonDuplicate(self, A: List[int]) -> int:
        n = len(A)
        st, end = 0, n - 1

        while st <= end:
            mid = st + (end - st) // 2

            # Check if mid is the single element
            if (mid == 0 and A[0] != A[1]) or \
               (mid == n-1 and A[n-1] != A[n-2]) or \
               (0 < mid < n-1 and A[mid] != A[mid-1] and A[mid] != A[mid+1]):
                return A[mid]

            # Binary search logic based on index parity
            if mid % 2 == 0:  # even
                if A[mid] == A[mid+1]:
                    st = mid + 2
                else:
                    end = mid - 1
            else:  # odd
                if A[mid] == A[mid-1]:
                    st = mid + 1
                else:
                    end = mid - 1
```

**Time Complexity:** `O(log n)` – binary search
**Space Complexity:** `O(1)` – no extra space

---

### **Example Dry Run**

Array: `[1,1,2,3,3,4,4,5,5]`

| Step | st | end | mid | mid % 2 | Check             | Action     |
| ---- | -- | --- | --- | ------- | ----------------- | ---------- |
| 1    | 0  | 8   | 4   | even    | A[4]=3 != A[5]=4? | right half |
| 2    | 0  | 3   | 1   | odd     | A[1]=1 == A[0]=1? | right half |
| 3    | 2  | 3   | 2   | even    | A[2]=2 != A[3]=3? | found!     |

✅ Result: 2

---

### **Why Optimized Works**

* The array is **sorted**.
* Every pair is consecutive.
* The single element **breaks the pattern**, allowing **binary search** to locate it quickly.

---

### **Tips for Beginners**

1. Always handle **edges** first: first and last elements.
2. Remember: **even index logic** is key for pairs.
3. Dry run with a small array to **visualize how st/end moves**.
4. Time complexity drops from **O(n) → O(log n)** using binary search.

---