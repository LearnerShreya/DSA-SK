# Search in Rotated Sorted Array

---

### Introduction

* We are given an array that was originally sorted in ascending order, but then **rotated** at some unknown pivot.
* Our task is to search for a target value in this rotated array in **O(log n)** time.
* Example:

  * Original sorted: `[1, 2, 3, 4, 5, 6, 7]`
  * Rotated: `[4, 5, 6, 7, 1, 2, 3]`

---

### Problem Statement

Given an integer array `nums` (rotated sorted array) and an integer `target`, return the index of `target` if it exists, otherwise return `-1`.

---

### Key Observations

1. A rotated sorted array always has **at least one sorted half** (either left or right).
2. We can apply a modified **binary search** by checking:

   * Which half is sorted?
   * Is the target inside that half?
   * If yes → search in that half; otherwise → search in the other half.

---

### Approach

1. Initialize `low = 0`, `high = len(nums) - 1`.
2. While `low <= high`:

   * Find `mid = low + (high - low) // 2` (to avoid overflow).
   * If `nums[mid] == target`, return `mid`.
   * Check which side is sorted:

     * **Left sorted part:** if `nums[low] <= nums[mid]`

       * If `nums[low] <= target < nums[mid]` → search left (`high = mid - 1`)
       * Else → search right (`low = mid + 1`)
     * **Right sorted part:** else

       * If `nums[mid] < target <= nums[high]` → search right (`low = mid + 1`)
       * Else → search left (`high = mid - 1`)
3. If not found, return `-1`.

---

### Iterative Python Code

```python
def search(nums, target):
    low, high = 0, len(nums) - 1
    
    while low <= high:
        mid = low + (high - low) // 2
        
        if nums[mid] == target:
            return mid
        
        # Check if left half is sorted
        if nums[low] <= nums[mid]:
            if nums[low] <= target < nums[mid]:
                high = mid - 1
            else:
                low = mid + 1
        else:  # Right half is sorted
            if nums[mid] < target <= nums[high]:
                low = mid + 1
            else:
                high = mid - 1
    
    return -1
```


### Iterative C++ Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2; // to avoid overflow
        
        if (nums[mid] == target) return mid;
        
        // Check if left half is sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } 
        // Otherwise, right half is sorted
        else {
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    
    return -1; // not found
}

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << "Index of target: " << search(nums, target) << endl;
    return 0;
}
```

---

### Dry Run Example 1

Input: `nums = [4,5,6,7,0,1,2], target = 0`

* Step 1: `low=0, high=6, mid=3 → nums[mid]=7`
  Left side `[4,5,6,7]` is sorted. Target=0 is not in `[4,7]`. Move right → `low=4`.
* Step 2: `low=4, high=6, mid=5 → nums[mid]=1`
  Left side `[0,1]` is sorted. Target=0 is in `[0,1]`. Move left → `high=4`.
* Step 3: `low=4, high=4, mid=4 → nums[mid]=0` → Found at index 4.

---

### Dry Run Example 2 (Target in initially sorted part)

Input: `nums = [6,7,8,1,2,3,4,5], target = 8`

* **Step 1:** `low=0, high=7, mid=3 → nums[mid]=1`
  Left side `[6,7,8,1]`? Check: `nums[low]=6 <= nums[mid]=1` → false, so **right half `[1,2,3,4,5]` is sorted**.
  Target=8 is **not in `[1,5]`**, so search left → `high = mid-1 = 2`.

* **Step 2:** `low=0, high=2, mid=1 → nums[mid]=7`
  Left side `[6,7]` is sorted (`nums[low]=6 <= nums[mid]=7`).
  Target=8 is **not in `[6,7]`**, so search right → `low = mid+1 = 2`.

* **Step 3:** `low=2, high=2, mid=2 → nums[mid]=8`
  Found target at index **2** ✅

---

Key points from this example:

1. Even if the target is in the **sorted part initially**, the algorithm correctly narrows the search by checking which half is sorted.
2. Binary search logic works **both when target is in sorted or unsorted halves**.

---

### Dry Run Example 5 (Target not in array)

Input: `nums = [6,7,8,1,2,3,4,5], target = 10`

* **Step 1:** `low=0, high=7, mid=3 → nums[mid]=1`
  Left side `[6,7,8,1]`? `nums[low]=6 <= nums[mid]=1` → false → right half `[1,2,3,4,5]` is sorted.
  Target=10 is **not in `[1,5]`**, so search left → `high = mid-1 = 2`.

* **Step 2:** `low=0, high=2, mid=1 → nums[mid]=7`
  Left side `[6,7]` is sorted. Target=10 is **not in `[6,7]`**, so search right → `low = mid+1 = 2`.

* **Step 3:** `low=2, high=2, mid=2 → nums[mid]=8`
  Left side `[8]` is sorted. Target=10 is **not in `[8,8]`**, so search right → `low = mid+1 = 3`.

* **Step 4:** `low=3, high=2` → `low > high`, terminate.
  Target **not found**, return `-1` ✅

---

Key takeaway:

* At every step, we **eliminate half of the array**.
* If the target is missing, eventually `low > high` and the algorithm correctly returns `-1`.
* Works **efficiently in O(log n) time** for all cases—target in sorted part, unsorted part, or absent.

---

### Time Complexity

* Each step halves the search space → **O(log n)**
* Space complexity → **O(1)** (iterative approach).

---

### Recursive Version

```python
def search_recursive(nums, target):
    def helper(low, high):
        if low > high:
            return -1
        
        mid = low + (high - low) // 2
        
        if nums[mid] == target:
            return mid
        
        # Left half is sorted
        if nums[low] <= nums[mid]:
            if nums[low] <= target < nums[mid]:
                return helper(low, mid - 1)
            else:
                return helper(mid + 1, high)
        else:  # Right half is sorted
            if nums[mid] < target <= nums[high]:
                return helper(mid + 1, high)
            else:
                return helper(low, mid - 1)
    
    return helper(0, len(nums) - 1)
```


### Recursive C++ Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int helper(vector<int>& nums, int low, int high, int target) {
    if (low > high) return -1;
    
    int mid = low + (high - low) / 2;
    
    if (nums[mid] == target) return mid;
    
    // Left half is sorted
    if (nums[low] <= nums[mid]) {
        if (nums[low] <= target && target < nums[mid]) {
            return helper(nums, low, mid - 1, target);
        } else {
            return helper(nums, mid + 1, high, target);
        }
    } 
    // Right half is sorted
    else {
        if (nums[mid] < target && target <= nums[high]) {
            return helper(nums, mid + 1, high, target);
        } else {
            return helper(nums, low, mid - 1, target);
        }
    }
}

int search_recursive(vector<int>& nums, int target) {
    return helper(nums, 0, nums.size() - 1, target);
}

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << "Index of target: " << search_recursive(nums, target) << endl;
    return 0;
}
```

---

### Summary

* The array is rotated, but always has one sorted half.
* Modified binary search helps us decide which half to search.
* Works in **O(log n)** time, **O(1)** space (iterative).

---

✅ Both iterative and recursive solutions work in **O(log n)** time and **O(1)** extra space.