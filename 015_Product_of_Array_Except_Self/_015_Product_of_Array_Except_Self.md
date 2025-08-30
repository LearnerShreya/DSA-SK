
# Product of Array Except Self

* [Problem: 238. Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/description/)

---

## Problem Statement

Given an array `nums`, return an array `ans` such that:

$$
ans[i] = \text{product of all elements of } nums \text{ except } nums[i]
$$

* Must run in **O(n) time**.
* Division is **not allowed**.

---

## Example

```
Input:  nums = [1,2,3,4]
Output: ans  = [24,12,8,6]
```

---

## 1. Brute Force Approach

### Idea

For each element `i`, multiply all elements except itself.

### Time Complexity

* For each index `i`, loop over `n-1` elements → **O(n²)**

### Space Complexity

* Extra output array → **O(n)**

### Code

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        for(int i = 0; i < n; i++) {
            int product = 1;
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    product *= nums[j];
                }
            }
            ans[i] = product;
        }
        return ans;
    }
};
```

### Code with Dry Run

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        for(int i = 0; i < n; i++) {
            int product = 1;
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    product *= nums[j];
                }
            }
            ans[i] = product;

            // Dry Run Print (for understanding)
            cout << "After i = " << i << ", ans = [";
            for(int k = 0; k < n; k++) cout << ans[k] << (k < n-1 ? "," : "");
            cout << "]" << endl;
        }
        return ans;
    }
};
```

### Dry Run (nums = `[1,2,3,4]`)

| i | Product (excluding nums\[i]) | ans array    |
| - | ---------------------------- | ------------ |
| 0 | 2 \* 3 \* 4 = 24             | \[24,1,1,1]  |
| 1 | 1 \* 3 \* 4 = 12             | \[24,12,1,1] |
| 2 | 1 \* 2 \* 4 = 8              | \[24,12,8,1] |
| 3 | 1 \* 2 \* 3 = 6              | \[24,12,8,6] |

---

---

## 2. Optimized Approach (Prefix + Suffix)

Absolutely, Shreya! We can merge and rewrite the two “Idea” sections for the **optimized prefix-suffix approach** to make it **crisp, clear, and beginner-friendly**. Here’s a better version:

---

### Idea

Instead of recomputing the product for every index:

1. **Prefix product:** Store the product of all elements to the **left** of the current index in the answer array.
2. **Suffix product:** Maintain a running product of all elements to the **right** of the current index.
3. **Final answer:** For each index `i`, multiply the prefix (left product) with the suffix (right product).
4. **Efficiency:** This requires **only two passes** over the array and **no extra arrays** (besides the output).

### Time Complexity

* **O(n)** (two passes)

### Space Complexity

* Only output array, no extra arrays → **O(1)** extra

### Code

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Step 1: Prefix product
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Step 2: Suffix product
        int suffix = 1;
        for(int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};
```

### Code with Dry Run

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Step 1: Prefix product
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];

            // Dry Run Print for Prefix
            cout << "Prefix i=" << i << ", ans = [";
            for(int k = 0; k < n; k++) cout << ans[k] << (k < n-1 ? "," : "");
            cout << "]" << endl;
        }

        // Step 2: Suffix product
        int suffix = 1;
        for(int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];

            // Dry Run Print for Suffix
            cout << "Suffix i=" << i << ", ans = [";
            for(int k = 0; k < n; k++) cout << ans[k] << (k < n-1 ? "," : "");
            cout << "], suffix = " << suffix << endl;
        }

        return ans;
    }
};
```

### Detailed Dry Run (nums = `[1,2,3,4]`)

**Prefix Pass** (`ans` stores left products):

```
i=1, ans = [1,1,1,1] -> ans[1] = 1*nums[0] = 1
i=2, ans[2] = ans[1]*nums[1] = 1*2 = 2 => ans = [1,1,2,1]
i=3, ans[3] = ans[2]*nums[2] = 2*3 = 6 => ans = [1,1,2,6]
```

**Suffix Pass** (multiply with right products):

```
i=3, suffix=1, ans[3]=6*1=6, suffix=4
i=2, ans[2]=2*4=8, suffix=4*3=12
i=1, ans[1]=1*12=12, suffix=12*2=24
i=0, ans[0]=1*24=24, suffix=24*1=24
Final ans = [24,12,8,6]
```

---

## Dry Run (nums = \[1,2,3,4])

**Prefix pass (ans stores left products):**

```
ans = [1, 1, 2, 6]
```

**Suffix pass (multiply with right products):**

```
ans = [24, 12, 8, 6]
```

---

## Special Case: Zeros

* If the array has more than one zero → all products are `0`.
* If the array has exactly one zero → only the index of zero has the non-zero product.
* Prefix-suffix approach **automatically handles this**.

---