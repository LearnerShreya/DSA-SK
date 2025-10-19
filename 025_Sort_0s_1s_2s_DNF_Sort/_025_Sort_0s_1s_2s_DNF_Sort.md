# Sort 0s 1s 2s DNF Sort - Python

---

# **Sort 0s, 1s, and 2s (Dutch National Flag Algorithm)**

---

## **1. Problem Statement**

You are given an array `arr[]` containing only **0s, 1s, and 2s**.
You must sort it **in ascending order (0s → 1s → 2s)** without using any built-in sorting functions.

**Example:**

```
Input:  arr = [2, 0, 2, 1, 1, 0]
Output: arr = [0, 0, 1, 1, 2, 2]
```

**Constraints**

* 1 ≤ n ≤ 10⁵
* Elements are only 0, 1, or 2

---

## **2. Why It’s Special**

Even though the array has only three unique elements, the task can be solved using different levels of optimization:

* Brute Force (using sort)
* Better (using counting)
* Optimal (using Dutch National Flag algorithm)

---

## **3. Approach 1: Brute Force (Using sort function)**

### **Idea**

Use Python’s built-in `sort()` function or any normal sorting algorithm.

### **Code**

```python
def sortColors(nums):
    nums.sort()
```

### **Complexity**

* Time: O(n log n)
* Space: O(1) (in-place)

**Drawback:** Doesn’t use the properties of having only 3 unique values.

---

## **4. Approach 2: Counting Method (Better Approach)**

### **Idea**

Since we have only 3 distinct values, count how many 0s, 1s, and 2s there are, and then overwrite the array.

### **Steps**

1. Count total 0s, 1s, and 2s in a single loop.
2. Rewrite the array using these counts.

### **Code**

```python
def sortColors(nums):
    count0 = count1 = count2 = 0

    for num in nums:
        if num == 0:
            count0 += 1
        elif num == 1:
            count1 += 1
        else:
            count2 += 1

    i = 0
    while count0 > 0:
        nums[i] = 0
        i += 1
        count0 -= 1

    while count1 > 0:
        nums[i] = 1
        i += 1
        count1 -= 1

    while count2 > 0:
        nums[i] = 2
        i += 1
        count2 -= 1
```

### **Complexity**

* Time: O(2n) ≈ O(n)
* Space: O(1)
  **Note:** Two traversals (one for counting, one for writing).

---

## **5. Approach 3: Dutch National Flag Algorithm (Optimal)**

### **Core Idea**

We need a **one-pass**, **in-place** sorting approach.
Use **three pointers**:

* `low`: points to where next 0 should go
* `mid`: current index under processing
* `high`: points to where next 2 should go

This is the **Dutch National Flag Algorithm** (by Edsger W. Dijkstra).

---

### **Initial Setup**

```
low = 0
mid = 0
high = n - 1
```

### **Three Main Rules**

While `mid <= high`:

1. If `nums[mid] == 0`:
   Swap `nums[low]` and `nums[mid]`, then `low += 1`, `mid += 1`
2. If `nums[mid] == 1`:
   Just `mid += 1`
3. If `nums[mid] == 2`:
   Swap `nums[mid]` and `nums[high]`, then `high -= 1`

---

### **Python Code**

```python
def sortColors(nums):
    low, mid, high = 0, 0, len(nums) - 1

    while mid <= high:
        if nums[mid] == 0:
            nums[low], nums[mid] = nums[mid], nums[low]
            low += 1
            mid += 1
        elif nums[mid] == 1:
            mid += 1
        else:  # nums[mid] == 2
            nums[mid], nums[high] = nums[high], nums[mid]
            high -= 1
```

---

### **Dry Run Example**

**Input:**
`nums = [2, 0, 2, 1, 1, 0]`

| Step | low | mid | high | nums[mid] | Action                       | Result Array       |
| ---- | --- | --- | ---- | --------- | ---------------------------- | ------------------ |
| 1    | 0   | 0   | 5    | 2         | swap(mid, high), high--      | [0, 0, 2, 1, 1, 2] |
| 2    | 0   | 0   | 4    | 0         | swap(low, mid), low++, mid++ | [0, 0, 2, 1, 1, 2] |
| 3    | 1   | 1   | 4    | 0         | swap(low, mid), low++, mid++ | [0, 0, 2, 1, 1, 2] |
| 4    | 2   | 2   | 4    | 2         | swap(mid, high), high--      | [0, 0, 1, 1, 2, 2] |
| 5    | 2   | 2   | 3    | 1         | mid++                        | [0, 0, 1, 1, 2, 2] |
| 6    | 2   | 3   | 3    | 1         | mid++                        | [0, 0, 1, 1, 2, 2] |

**Output:**
`[0, 0, 1, 1, 2, 2]`

---

### **Complexity Analysis**

| Metric           | Value    |
| ---------------- | -------- |
| Time Complexity  | O(n)     |
| Space Complexity | O(1)     |
| Traversals       | One-pass |
| In-place         | Yes      |

---

## **6. Comparison Table**

| Approach    | Description     | Time       | Space | Passes   | Efficiency |
| ----------- | --------------- | ---------- | ----- | -------- | ---------- |
| Brute Force | Use sort()      | O(n log n) | O(1)  | Multiple | Low        |
| Counting    | Count & rewrite | O(n)       | O(1)  | Two      | Good       |
| DNF         | Three-pointer   | O(n)       | O(1)  | One      | Best       |

---

## **7. Internal Working Logic**

At any point during the algorithm:

| Region          | Meaning | Range                |
| --------------- | ------- | -------------------- |
| `[0, low-1]`    | All 0s  | Left region          |
| `[low, mid-1]`  | All 1s  | Middle region        |
| `[mid, high]`   | Unknown | Currently processing |
| `[high+1, n-1]` | All 2s  | Right region         |

When `mid > high`, sorting is complete.

---

## **8. When to Use Which Approach**

| Situation                     | Best Approach                 |
| ----------------------------- | ----------------------------- |
| Need a simple, clear solution | Counting method               |
| Need one-pass, in-place       | Dutch National Flag algorithm |
| Small array or generic use    | Any method works fine         |

---

## **9. Real-world Applications**

* Categorizing items into 3 groups (low, medium, high priority)
* Segregating negative, zero, and positive numbers
* Partitioning in QuickSort
* Classifying categorical data with 3 fixed values

---

## **10. Summary of Core Rules**

1. Use three pointers: `low`, `mid`, `high`
2. Process while `mid <= high`
3. Follow:

   * If 0 → swap(low, mid), `low += 1`, `mid += 1`
   * If 1 → `mid += 1`
   * If 2 → swap(mid, high), `high -= 1`

**Result:** All 0s → 1s → 2s in one traversal, in-place.

---