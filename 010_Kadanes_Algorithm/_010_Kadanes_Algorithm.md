# Kadanes Algorithm

## **📌 Problem Kadane’s Algorithm Solves**

It finds the **maximum sum of a contiguous subarray** within an array of integers.
Example:

```
arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Maximum sum subarray = [4, -1, 2, 1]
Maximum sum = 6
```

---

## **Core Idea**

Instead of checking every possible subarray (which is **O(n²)**), we **scan the array once** and keep track of:

1. **Current sum** of subarray (`currentSum`)
2. **Maximum sum so far** (`maxSum`)

At each element:

* Either **extend** the current subarray by adding the element, or
* **Start new subarray** from current element (if `current element > currentSum + element`).

---

## **Step-by-Step Example**

Array:

```
[-2, 1, -3, 4, -1, 2, 1, -5, 4]
```

We start with:

```
currentSum = maxSum = arr[0] = -2
```

| i | arr\[i] | currentSum (max of arr\[i], currentSum + arr\[i]) | maxSum |
| - | ------- | ------------------------------------------------- | ------ |
| 0 | -2      | -2                                                | -2     |
| 1 | 1       | max(1, -2+1) = 1                                  | 1      |
| 2 | -3      | max(-3, 1-3) = -2                                 | 1      |
| 3 | 4       | max(4, -2+4) = 4                                  | 4      |
| 4 | -1      | max(-1, 4-1) = 3                                  | 4      |
| 5 | 2       | max(2, 3+2) = 5                                   | 5      |
| 6 | 1       | max(1, 5+1) = 6                                   | 6      |
| 7 | -5      | max(-5, 6-5) = 1                                  | 6      |
| 8 | 4       | max(4, 1+4) = 5                                   | 6      |

**Answer:** `maxSum = 6`

---

## **Algorithm**

**Pseudocode**

```
currentSum = maxSum = arr[0]
for i from 1 to n-1:
    currentSum = max(arr[i], currentSum + arr[i])
    maxSum = max(maxSum, currentSum)
return maxSum
```

---

## **C++ Implementation**

```cpp
#include <iostream>
#include <vector>
#include <climits>
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

## **Time & Space Complexity**

* **Time:** O(n) — only one pass
* **Space:** O(1) — uses constant extra space

---