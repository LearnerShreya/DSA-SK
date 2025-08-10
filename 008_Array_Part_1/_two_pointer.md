The **two-pointer approach** is a common and powerful technique in problem-solving—especially in array, string, or linked list problems—used to reduce time complexity and make solutions more efficient.

---

## **What is the Two-Pointer Approach?**

Imagine you have **two fingers (pointers)** pointing at elements in your data structure (array, string, list, etc.).
You move these pointers in a **planned way** (forward, backward, or towards each other) to solve the problem without unnecessary repeated work.

---

## **Why Use It?**

* It **avoids nested loops** (O(n²) → O(n))
* Works best on **sorted arrays** or problems involving **search, matching, or optimization**
* Saves **time** and **memory**

---

## **Pointer Types**

There are generally **two main variations**:

### 1️⃣ **Opposite Ends (Left & Right Pointers)**

* **Use case:** Finding pairs that meet a condition (sum, difference, etc.) in a sorted array.
* **Example:** *Find if there are two numbers in a sorted array whose sum = target.*

```cpp
bool twoSumSorted(vector<int> &arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return true;
        else if (sum < target) left++;
        else right--;
    }
    return false;
}
```

**How it works:**

* If the sum is too small → move `left++` (increase sum)
* If the sum is too large → move `right--` (decrease sum)

⏱ **Time complexity:** O(n) instead of O(n²)

---

### 2️⃣ **Same Direction (Sliding Window)**

* **Use case:** Finding subarrays or substrings that meet some criteria.
* **Example:** *Find the length of the smallest subarray with sum ≥ target.*

```cpp
int minSubArrayLen(int target, vector<int> &nums) {
    int left = 0, sum = 0, minLen = INT_MAX;
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        while (sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left++];
        }
    }
    return (minLen == INT_MAX) ? 0 : minLen;
}
```

**How it works:**

* Expand `right` to include more elements
* Shrink `left` when the condition is met to optimize

⏱ **Time complexity:** O(n)

---

## **When to Use Two Pointers**

* Array is **sorted** (or can be sorted)
* Need to find **pairs, triplets, subarrays**
* Need to **compare elements** in a sequence
* Problems like:

  * Two Sum in sorted array
  * Remove duplicates in-place
  * Reverse part of a string/array
  * Merge two sorted arrays
  * Palindrome check

---

**Pro Tip:**
If your brute force solution has **two nested loops** (O(n²)), think if moving two pointers smartly can avoid the inner loop.

---