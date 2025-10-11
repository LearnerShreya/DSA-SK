# Painters Partition Problem

---

### **Problem Statement**

You are given:

* An array `arr[]` of `n` integers, where each element represents the time required to paint a board.
* `m` painters, each painter paints **consecutive boards**.

Goal: Assign boards to painters such that **the maximum time taken by any painter is minimized**.

---

### **Example**

```
arr = [40, 30, 10, 20], n = 4
m = 2
```

* Painter 1 paints [40, 30] → time = 70
* Painter 2 paints [10, 20] → time = 30

Maximum time taken = 70

If we divide as:

* Painter 1 paints [40] → time = 40
* Painter 2 paints [30, 10, 20] → time = 60

Maximum time = 60 → better!

**Answer = 60**

---

### **Approach to Solve**

#### **Step 1: Understanding the Constraints**

* Every painter must paint **consecutive boards**.
* We are trying to **minimize the maximum time** any painter spends.

#### **Step 2: Observations**

1. Minimum possible maximum time = **largest single board** (`max(arr)`)

   * Because no painter can paint a board faster than its length.
2. Maximum possible maximum time = **sum of all boards** (`sum(arr)`)

   * If only one painter paints everything.

We can **binary search** between `max(arr)` and `sum(arr)` to find the minimum possible maximum time.

---

### **Step 3: Binary Search Logic**

1. Define `is_possible(maxTime)` function:

   * Simulate assigning boards to painters.
   * Keep adding board times until `maxTime` is exceeded → assign next painter.
   * If we need **more than m painters**, return `False`.
   * Else, return `True`.

2. Binary search between `max(arr)` and `sum(arr)`:

   * If `is_possible(mid)` is True → try smaller max time (`end = mid - 1`)
   * If `is_possible(mid)` is False → increase max time (`start = mid + 1`)

3. Continue until start > end.

   * The last valid `mid` is the answer.

---

### **Step 4: Complexity Analysis**

* **Time Complexity**:

  * `O(n * log(sum(arr)))`
  * `n` for `is_possible` function, `log(sum(arr))` for binary search.

* **Space Complexity**: `O(1)` extra space

---

### **Step 5: Python Code**

```python
def is_possible(arr, n, m, max_allowed_time):
    painters = 1
    time = 0
    for i in range(n):
        if arr[i] > max_allowed_time:
            return False
        if time + arr[i] <= max_allowed_time:
            time += arr[i]
        else:
            painters += 1
            time = arr[i]
        if painters > m:
            return False
    return True

def min_time_to_paint(arr, n, m):
    total_sum = sum(arr)
    max_val = max(arr)

    st, end = max_val, total_sum
    ans = -1

    while st <= end:
        mid = st + (end - st) // 2
        if is_possible(arr, n, m, mid):
            ans = mid
            end = mid - 1
        else:
            st = mid + 1
    return ans

# Example
arr = [40, 30, 10, 20]
n = 4
m = 2
print(min_time_to_paint(arr, n, m))  # Output: 60
```

---

### **Step 6: Key Points to Remember**

1. Each painter **paints consecutive boards** only.
2. Use **binary search** to optimize the maximum time.
3. `is_possible` function checks if a given maximum time is feasible.
4. Initial search space: `[max(arr), sum(arr)]`.
5. Always check the **edge case** where a single board is larger than the allowed max time.

---