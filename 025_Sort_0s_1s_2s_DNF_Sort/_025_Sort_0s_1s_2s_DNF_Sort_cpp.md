# Sort 0s 1s 2s DNF Sor - cpp

---

# **Sort 0s, 1s, and 2s (Dutch National Flag Algorithm)**

---

## **1. Problem Statement**

You are given an array `arr[]` containing only **0s, 1s, and 2s**.
You must sort it **in ascending order (0s → 1s → 2s)** without using any built-in sorting functions.

### Example

```
Input:  arr = [2, 0, 2, 1, 1, 0]
Output: arr = [0, 0, 1, 1, 2, 2]
```

### Constraints

* 1 ≤ n ≤ 10⁵
* Elements are only 0, 1, or 2

---

## **2. Why It’s Special**

Even though the array contains only three distinct values, the task looks simple but can be solved in multiple ways:

* Brute Force (using sorting)
* Better (using counting)
* Optimal (using Dutch National Flag algorithm)

We’ll go through each one carefully.

---

## **3. Approach 1: Brute Force (Using sort function)**

### **Idea**

Just use any sorting algorithm (or the built-in one like `sort()` in C++ or Python).

### **Code**

```cpp
#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    sort(nums.begin(), nums.end());
}
```

### **Complexity**

* Time: O(n log n)
* Space: O(1) (in-place)

### **Drawback**

* Not efficient since we know the values are only 0, 1, and 2.
* Doesn’t use problem-specific logic.

---

## **4. Approach 2: Counting Method (Better Approach)**

### **Idea**

Since only 3 values exist, we can count how many 0s, 1s, and 2s there are and then rewrite the array.

### **Steps**

1. Count total 0s, 1s, and 2s in one loop.
2. Overwrite the array:

   * Fill first `count0` positions with 0
   * Next `count1` positions with 1
   * Remaining positions with 2

### **Code**

```cpp
void sortColors(vector<int>& nums) {
    int count0 = 0, count1 = 0, count2 = 0;
    for (int x : nums) {
        if (x == 0) count0++;
        else if (x == 1) count1++;
        else count2++;
    }

    int i = 0;
    while (count0--) nums[i++] = 0;
    while (count1--) nums[i++] = 1;
    while (count2--) nums[i++] = 2;
}
```

### **Complexity**

* Time: O(2n) → O(n) (two passes)
* Space: O(1)
* Stable and simple, but **not one-pass**.

---

## **5. Approach 3: Dutch National Flag Algorithm (Optimal)**

### **Core Idea**

We need a **single-pass**, **in-place** algorithm.
Use **three pointers**:

* `low`: points to where next 0 should be placed
* `mid`: current index under processing
* `high`: points to where next 2 should be placed

The algorithm is named after the **Dutch National Flag** (red, white, blue) — representing three color groups.

---

### **Initial Setup**

```
low = 0
mid = 0
high = n - 1
```

### **Three Main Rules**

While `mid <= high`:

1. If `arr[mid] == 0` → swap(arr[low], arr[mid]); low++; mid++;
2. If `arr[mid] == 1` → mid++;
3. If `arr[mid] == 2` → swap(arr[mid], arr[high]); high--;

---

### **Why These Rules Work**

* `low` ensures that everything before it is **0**.
* `high` ensures that everything after it is **2**.
* `mid` processes unknown elements between `low` and `high`.

Once `mid` crosses `high`, all elements are correctly partitioned.

---

### **Code (C++)**

```cpp
#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
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

| Approach    | Description          | Time       | Space | Passes   | Efficient? |
| ----------- | -------------------- | ---------- | ----- | -------- | ---------- |
| Brute Force | Use sort()           | O(n log n) | O(1)  | Multiple | No         |
| Counting    | Count & overwrite    | O(n)       | O(1)  | Two      | Good       |
| DNF         | Three-pointer method | O(n)       | O(1)  | One      | Best       |

---

## **7. Internal Working Logic of DNF Algorithm**

Let’s break how regions form during execution:

| Region          | Meaning        | Range           |
| --------------- | -------------- | --------------- |
| `[0, low-1]`    | All 0s         | Left section    |
| `[low, mid-1]`  | All 1s         | Middle section  |
| `[mid, high]`   | Unknown region | Processing area |
| `[high+1, n-1]` | All 2s         | Right section   |

At the end:

```
low = index after last 0
mid = index after last 1
high = index before first 2
```

So when `mid > high`, all are correctly placed.

---

## **8. When to Use Which Approach**

| Situation                                 | Best Approach                   |
| ----------------------------------------- | ------------------------------- |
| Need simple logic                         | Counting Method                 |
| Need single traversal, in-place           | DNF Algorithm                   |
| Very small array                          | Any approach works              |
| General array with only few unique values | DNF or partition-based approach |

---

## **9. Real-world Applications**

* Categorizing items into 3 groups (like low, medium, high priority)
* Partitioning arrays in **QuickSort**
* Problems where elements have only a small range of discrete values
* Used conceptually in segregating **negative / zero / positive numbers**

---