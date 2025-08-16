# Majority Element Pair Sum

---

## **1. Majority Element**

**📌 Problem:**
Find the element that appears **more than ⌊n/2⌋ times** in the array.

---

### **Best Approach – Moore’s Voting Algorithm**

**Idea:** Cancel out different elements, majority survives.

**Steps:**

1. Start with `count = 0`, `candidate = None`.
2. For each element:

   * If `count == 0` → pick current as candidate.
   * If same as candidate → `count++`, else `count--`.
3. Candidate will be the majority element.

---

**Dry Run Example:**

```
nums = [2, 2, 1, 1, 1, 2, 2]
n/2 = 3

Step-by-step:
2 (c=1), 2 (c=2), 1 (c=1), 1 (c=0), 1 (c=1), 2 (c=0), 2 (c=1)
Candidate = 2
```

---

**C++ Code (O(n), O(1)):**

```cpp
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;
    for (int num : nums) {
        if (count == 0) candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate; // Majority guaranteed to exist
}

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << majorityElement(nums) << endl; // Output: 2
}
```

**Python Code (O(n), O(1)):**

```python
def majorityElement(nums):
    candidate, count = None, 0
    for num in nums:
        if count == 0:
            candidate = num
        count += 1 if num == candidate else -1
    return candidate  # Majority guaranteed to exist

nums = [2, 2, 1, 1, 1, 2, 2]
print(majorityElement(nums))  # Output: 2
```

---

## **2. Pair Sum**

**📌 Problem:**
Check if any pair in the array sums to a given target.

---

### **Best Approach – Hash Set** (for unsorted array)

**Steps:**

1. Initialize empty set.
2. For each element:

   * Calculate `need = target - num`.
   * If `need` in set → Pair found.
   * Else insert `num`.

---

**Dry Run Example:**

```
arr = [8, 4, 1, 6], target = 10
Set = {}
8 → need 2 → not found → add 8
4 → need 6 → not found → add 4
1 → need 9 → not found → add 1
6 → need 4 → found → YES
```

---

**C++ Code (O(n), O(n)):**

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

**Python Code (O(n), O(n)):**

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

## **⏳ Complexity Summary**

| Problem             | Best Approach  | Time | Space |
| ------------------- | -------------- | ---- | ----- |
| Majority Element    | Moore’s Voting | O(n) | O(1)  |
| Pair Sum (Unsorted) | Hash Set       | O(n) | O(n)  |
| Pair Sum (Sorted)   | Two Pointer    | O(n) | O(1)  |

---

