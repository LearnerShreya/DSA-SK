# Kadane’s Algorithm

## **📌 Problem It Solves**

Find the **maximum sum of a contiguous subarray** within an array of integers.

**Example:**

```
arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Maximum sum subarray = [4, -1, 2, 1]
Maximum sum = 6
```

---

## **Core Idea**

Instead of checking all possible subarrays (**O(n²)**), we can **scan the array once** while keeping track of:

1. `currentSum` — Maximum sum **ending at current element**
2. `maxSum` — Maximum sum **found so far**

At each element:

* Either **extend** the current subarray: `currentSum + arr[i]`
* Or **start a new subarray** from the current element: `arr[i]`

Choose the **maximum of these two**.

---

## **Step-by-Step Example**

Array:

```
[-2, 1, -3, 4, -1, 2, 1, -5, 4]
```

Initialize:

```
currentSum = maxSum = arr[0] = -2
```

| i | arr[i] | currentSum = max(arr[i], currentSum+arr[i]) | maxSum = max(maxSum, currentSum) |
| - | ------ | ------------------------------------------- | -------------------------------- |
| 0 | -2     | -2                                          | -2                               |
| 1 | 1      | 1                                           | 1                                |
| 2 | -3     | -2                                          | 1                                |
| 3 | 4      | 4                                           | 4                                |
| 4 | -1     | 3                                           | 4                                |
| 5 | 2      | 5                                           | 5                                |
| 6 | 1      | 6                                           | 6                                |
| 7 | -5     | 1                                           | 6                                |
| 8 | 4      | 5                                           | 6                                |

**Answer:** `maxSum = 6`

---

## **Algorithm (Pseudocode)**

```
currentSum = maxSum = arr[0]
for i = 1 to n-1:
    currentSum = max(arr[i], currentSum + arr[i])
    maxSum = max(maxSum, currentSum)
return maxSum
```

---

## **C++ Implementation**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int currentSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum = " << maxSubArray(arr) << endl;
    return 0;
}
```

---

## **Python Implementation**

```python
def max_subarray(arr):
    current_sum = max_sum = arr[0]
    
    for i in range(1, len(arr)):
        current_sum = max(arr[i], current_sum + arr[i])
        max_sum = max(max_sum, current_sum)
    
    return max_sum

arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
print("Maximum Subarray Sum =", max_subarray(arr))
```

---

## **Time & Space Complexity**

* **Time:** O(n) — single pass through the array
* **Space:** O(1) — constant extra space

---