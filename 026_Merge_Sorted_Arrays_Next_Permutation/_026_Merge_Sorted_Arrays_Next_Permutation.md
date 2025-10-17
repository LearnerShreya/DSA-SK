# Merge Sorted Arrays & Next Permutation

---

## 1. Merge Sorted Arrays

### Problem

You’re given two sorted arrays, `A` and `B`.
Array `A` has enough extra space at the end to hold all elements of `B`.
You need to merge `B` into `A`, so that `A` becomes one sorted array (in-place, no extra array).

---

### Example

```
A = [1, 3, 5, 0, 0, 0]
B = [2, 4, 6]
m = 3, n = 3
```

Output:

```
A = [1, 2, 3, 4, 5, 6]
```

---

### Intuition

We have to merge two sorted arrays — like in merge sort — but since `A` already has space at the end, we can start filling it from the back to avoid overwriting elements in `A`.

---

### Approach (Two-pointer from end)

1. Set three pointers:

   * `i = m - 1` (last valid element in A)
   * `j = n - 1` (last element in B)
   * `idx = m + n - 1` (last index of A)

2. Compare `A[i]` and `B[j]`:

   * Place the larger element at `A[idx]`.
   * Move the corresponding pointer (`i` or `j`) and `idx` one step left.

3. When one array is exhausted, copy the remaining elements of the other array.

---

### Code (Python)

```python
def merge(A, m, B, n):
    idx = m + n - 1
    i = m - 1
    j = n - 1

    while i >= 0 and j >= 0:
        if A[i] >= B[j]:
            A[idx] = A[i]
            i -= 1
        else:
            A[idx] = B[j]
            j -= 1
        idx -= 1

    while j >= 0:
        A[idx] = B[j]
        j -= 1
        idx -= 1

# Example
A = [1, 3, 5, 0, 0, 0]
B = [2, 4, 6]
merge(A, 3, B, 3)
print(A)  # [1, 2, 3, 4, 5, 6]
```

---

### Time Complexity

O(m + n) — each element is processed once.
O(1) extra space — done in-place.

---

## 2. Next Permutation

### Problem

Given an array `nums` representing a number (for example, [1,2,3] → 123),
find the next lexicographically greater permutation of numbers.
If not possible (the array is in descending order), return the smallest permutation (sorted ascending).

---

### Example 1

```
Input: [1, 2, 3]
Output: [1, 3, 2]
```

### Example 2

```
Input: [3, 2, 1]
Output: [1, 2, 3]
```

---

### Intuition

We want to rearrange numbers to get the next bigger arrangement using the same digits.
Think of it like finding the next word in dictionary order.

---

### Step-by-Step Logic

1. **Find Pivot:**
   From right to left, find the first index `i` where `nums[i] < nums[i + 1]`.
   This marks the point where numbers start decreasing.

2. **If no pivot found:**
   The array is in descending order (like [3,2,1]).
   Reverse it to get the smallest permutation.

3. **Find the Next Larger Element:**
   From right to left, find the first element greater than `nums[pivot]` and swap them.

4. **Reverse the Right Half:**
   Reverse the subarray from `pivot + 1` to the end to make it the smallest possible.

---

### Code (Python)

```python
def nextPermutation(nums):
    n = len(nums)
    pivot = -1

    # Step 1: find pivot
    for i in range(n - 2, -1, -1):
        if nums[i] < nums[i + 1]:
            pivot = i
            break

    # Step 2: if no pivot, reverse entire array
    if pivot == -1:
        nums.reverse()
        return

    # Step 3: find next larger element
    for i in range(n - 1, pivot, -1):
        if nums[i] > nums[pivot]:
            nums[i], nums[pivot] = nums[pivot], nums[i]
            break

    # Step 4: reverse right half
    nums[pivot + 1:] = reversed(nums[pivot + 1:])
```

---

### Example Walkthrough

`nums = [1, 2, 3]`

* Pivot = 1 (since 2 < 3)
* Next greater element after pivot = 3
* Swap → [1, 3, 2]
* Reverse right half (already sorted) → [1, 3, 2]

---

### Time Complexity

O(n) — single pass with small reversals.
O(1) space — in-place rearrangement.

---

## Summary Table

| Problem             | Approach               | Time     | Space | Key Idea                                         |
| ------------------- | ---------------------- | -------- | ----- | ------------------------------------------------ |
| Merge Sorted Arrays | Two pointers from end  | O(m + n) | O(1)  | Merge in-place starting from the back            |
| Next Permutation    | Pivot + Swap + Reverse | O(n)     | O(1)  | Find pivot, swap with next greater, reverse rest |

---