# Container With Most Water

---

## 🔹 **Problem Statement**

You are given an array `height[]`, where each element represents the height of a vertical line drawn at index `i`.
We need to **choose two lines** that form a container with the x-axis and hold the **maximum amount of water**.

👉 **Return the maximum water area possible.**

---

## 🔹 **Concept Behind the Problem**

* Two lines and the x-axis form a **container**.
* The **capacity (area)** of this container is determined by:

  * **Width** = distance between the two lines = `j - i`
  * **Height** = shorter of the two lines = `min(height[i], height[j])`
  * **Area** = `width × height`

### Example

`height = [1,8,6,2,5,4,8,3,7]`

Pick lines at index `1 (height=8)` and `8 (height=7)`:

* Width = `8 - 1 = 7`
* Height = `min(8,7) = 7`
* Area = `7 × 7 = 49` (maximum)

---

## 🔹 **Rulebook**

### Brute Force Rulebook (O(n²)):

1. Pick every possible pair `(i, j)`.
2. Compute `width = j - i`.
3. Compute `height = min(height[i], height[j])`.
4. Area = `width × height`.
5. Track maximum.

✅ Works but very **slow** when `n` is large.

---

### Optimized Two-Pointer Rulebook (O(n)):

1. Start with **two pointers**:

   * `left = 0`
   * `right = n-1`
2. Compute area between `height[left]` and `height[right]`.
3. Update `maxArea`.
4. **Move the smaller height pointer inward**:

   * If `height[left] < height[right]` → move `left++`
   * Else → move `right--`
5. Repeat until `left < right`.

👉 Why move the smaller one?
Because the **height** limits the area. Moving the taller line won't help, but moving the smaller might give a taller line and larger area.

✅ This guarantees **O(n)** solution.

---

## 🔹 **Dry Run (Optimized Example)**

`height = [1,8,6,2,5,4,8,3,7]`

1. `left=0 (1), right=8 (7)`
   width = 8, ht = min(1,7)=1 → area=8
   move left (smaller).

2. `left=1 (8), right=8 (7)`
   width=7, ht=min(8,7)=7 → area=49 ✅ max

3. `left=1, right=7 (3)`
   width=6, ht=min(8,3)=3 → area=18
   move right (smaller).

4. `left=1, right=6 (8)`
   width=5, ht=min(8,8)=8 → area=40

…and so on.
**Final Answer = 49**

---

## 🔹 **Code Implementations**

---

### ✅ Python Code

```python
# Brute Force (O(n^2))
class SolutionBrute:
    def maxArea(self, height):
        maxWater = 0
        n = len(height)

        for i in range(n):
            for j in range(i + 1, n):
                w = j - i
                ht = min(height[i], height[j])
                area = w * ht
                maxWater = max(maxWater, area)

        return maxWater


# Optimized Two-Pointer (O(n))
class SolutionOptimized:
    def maxArea(self, height):
        maxWater = 0
        left, right = 0, len(height) - 1

        while left < right:
            w = right - left
            ht = min(height[left], height[right])
            area = w * ht
            maxWater = max(maxWater, area)

            # Move the smaller pointer
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return maxWater


# Example Run
heights = [1,8,6,2,5,4,8,3,7]
print("Brute Force:", SolutionBrute().maxArea(heights))
print("Optimized:", SolutionOptimized().maxArea(heights))
```

---

### ✅ C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

// Brute Force (O(n^2))
class SolutionBrute {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int w = j - i;
                int ht = min(height[i], height[j]);
                int area = w * ht;
                maxWater = max(maxWater, area);
            }
        }
        return maxWater;
    }
};

// Optimized Two-Pointer (O(n))
class SolutionOptimized {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int left = 0, right = height.size() - 1;

        while (left < right) {
            int w = right - left;
            int ht = min(height[left], height[right]);
            int area = w * ht;
            maxWater = max(maxWater, area);

            // Move the smaller pointer
            (height[left] < height[right]) ? left++ : right--;
        }
        return maxWater;
    }
};

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    
    SolutionBrute brute;
    SolutionOptimized opt;
    
    cout << "Brute Force: " << brute.maxArea(height) << endl;
    cout << "Optimized: " << opt.maxArea(height) << endl;

    return 0;
}
```

---

## 🔹 **Comparison**

| Approach    | Time Complexity | Space Complexity | Notes                              |
| ----------- | --------------- | ---------------- | ---------------------------------- |
| Brute Force | O(n²)           | O(1)             | Easy but too slow for large inputs |
| Two-Pointer | O(n)            | O(1)             | Best approach, used in interviews  |

---

✅ **Final Takeaway:**

* Always explain **both brute force and optimized solutions** in interviews.
* Show brute force first (clear logic), then improve it with **two-pointers**.
* The **optimized approach is the real interview-winning answer**.

---