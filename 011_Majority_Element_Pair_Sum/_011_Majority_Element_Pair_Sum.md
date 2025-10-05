# **Majority Element & Pair Sum**

---

## **1. Majority Element**

### 📌 Problem

Find the element that appears **more than ⌊n/2⌋ times** in an array.

**Example:**

```
nums = [2, 2, 1, 1, 1, 2, 2]
Majority element = 2
```

---

### 💡 Best Approach – Moore’s Voting Algorithm

**Idea:** Cancel out different elements; the majority element survives.

**Steps:**

1. Initialize `candidate = None`, `count = 0`.
2. For each element:

   * If `count == 0` → pick current element as `candidate`.
   * If element == `candidate` → `count++`, else `count--`.
3. At the end, `candidate` is the majority element.

---

### ⚡ Dry Run Example

| Element | Count | Candidate |
| ------- | ----- | --------- |
| 2       | 1     | 2         |
| 2       | 2     | 2         |
| 1       | 1     | 2         |
| 1       | 0     | 2 → reset |
| 1       | 1     | 1         |
| 2       | 0     | 1 → reset |
| 2       | 1     | 2         |

**Majority Element = 2**

---

### 🖥 C++ Code (O(n), O(1))

```cpp
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;
    for (int num : nums) {
        if (count == 0) candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << majorityElement(nums) << endl; // Output: 2
}
```

---

### 🐍 Python Code (O(n), O(1))

```python
def majorityElement(nums):
    candidate, count = None, 0
    for num in nums:
        if count == 0:
            candidate = num
        count += 1 if num == candidate else -1
    return candidate

nums = [2, 2, 1, 1, 1, 2, 2]
print(majorityElement(nums))  # Output: 2
```

---

### ✅ Key Takeaways

* Majority element survives cancellation.
* Works in **O(n) time** and **O(1) space**.
* Guaranteed to find majority if it exists.

---

## **2. Pair Sum**

### 📌 Problem

Check if **any pair in the array sums to a given target**.

**Example:**

```
arr = [8, 4, 1, 6], target = 10
Pair found: 4 + 6
```

---

### 💡 Best Approach – Hash Set (Unsorted Array)

**Idea:** Use a set to store seen elements and check for the complement.

**Steps:**

1. Initialize empty set `seen = {}`.
2. For each element `num` in array:

   * `need = target - num`
   * If `need in seen` → Pair exists
   * Else → Add `num` to `seen`

---

### ⚡ Dry Run Example

| Element | need | Seen Set  | Pair Found? |
| ------- | ---- | --------- | ----------- |
| 8       | 2    | {8}       | No          |
| 4       | 6    | {8,4}     | No          |
| 1       | 9    | {8,4,1}   | No          |
| 6       | 4    | {8,4,1,6} | Yes         |

---

### 🖥 C++ Code (O(n), O(n))

```cpp
#include <bits/stdc++.h>
using namespace std;

bool hasPairSum(vector<int>& arr, int target) {
    unordered_set<int> seen;
    for (int num : arr) {
        if (seen.count(target - num)) return true;
        seen.insert(num);
    }
    return false;
}

int main() {
    vector<int> arr = {8, 4, 1, 6};
    int target = 10;
    cout << (hasPairSum(arr, target) ? "YES" : "NO") << endl; // Output: YES
}
```

---

### 🐍 Python Code (O(n), O(n))

```python
def hasPairSum(arr, target):
    seen = set()
    for num in arr:
        if (target - num) in seen:
            return True
        seen.add(num)
    return False

arr = [8, 4, 1, 6]
target = 10
print("YES" if hasPairSum(arr, target) else "NO")  # Output: YES
```

---

### 💡 Optional: Two Pointer (Sorted Array)

* If array is sorted, use **two pointers `i=0`, `j=n-1`**:

  * Sum < target → move `i++`
  * Sum > target → move `j--`
* Time: O(n), Space: O(1)

---

### ⏳ Complexity Summary

| Problem             | Approach       | Time | Space |
| ------------------- | -------------- | ---- | ----- |
| Majority Element    | Moore’s Voting | O(n) | O(1)  |
| Pair Sum (Unsorted) | Hash Set       | O(n) | O(n)  |
| Pair Sum (Sorted)   | Two Pointer    | O(n) | O(1)  |

---