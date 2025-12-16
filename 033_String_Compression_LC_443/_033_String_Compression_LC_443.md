# String Compression (LeetCode 443)

---

### Problem Summary

You are given an array of characters `chars`.
You must **compress it in-place** using the following rules:

* Consecutive repeating characters are replaced by:

  * the character
  * followed by the count (only if count > 1)
* The compressed result must be stored **in the same array**
* Return the **new length** of the array after compression

You are **not allowed** to use extra space for another array.

---

### Example

Input

```
chars = ["a","a","b","b","c","c","c"]
```

Output

```
["a","2","b","2","c","3"]
```

Return

```
6
```

---

### Key Observations

1. Compression happens **only for consecutive characters**
2. Count `1` is **not written**
3. Multi-digit counts must be split into characters

   * Example: `12` → `"1","2"`
4. In-place means:

   * No new array
   * Use indices to overwrite existing values

---

### Approach (Two Pointers)

We use:

* `i` → to read characters
* `idx` → to write compressed result

---

### Step-by-Step Logic

1. Initialize:

   * `i = 0`
   * `idx = 0`

2. While `i < n`:

   * Store current character
   * Count how many times it repeats
   * Write character at `idx`
   * If count > 1:

     * Convert count to string
     * Write each digit separately
   * Move to next group

3. Return `idx` as the new length

---

### Why Two Pointers Work

* One pointer reads original data
* One pointer overwrites compressed data
* Ensures O(1) extra space

---

### Time and Space Complexity

* **Time Complexity:**
  $$O(n)$$
  Each character is visited once

* **Space Complexity:**
  $$O(1)$$
  Only constant extra variables used

---

### Common Mistakes

1. Writing count even when it is `1`
2. Forgetting to split multi-digit counts
3. Using extra arrays (not allowed)
4. Returning wrong length instead of modified array size

---

### Intuition in One Line

> Count consecutive characters and overwrite the array with character + count (if >1), using two pointers.

---

### When to Use This Pattern

* In-place modification
* Run-length encoding problems
* Array compression questions
* String manipulation with space constraints

---
---

## 1) Dry Run (Tricky Input)

### Input

```
chars = ["a","a","a","b","b","c","c","c","c","c","c","c","c","c","c","c"]
```

That is:

* a → 3 times
* b → 2 times
* c → 10 times

---

### Initial State

```
i = 0
idx = 0
n = 16
```

---

### Step 1: Character = 'a'

* Count = 3
* Write:

```
chars[idx] = 'a' → idx = 1
chars[idx] = '3' → idx = 2
```

* Move `i` to next group

Array now:

```
["a","3", ...]
```

---

### Step 2: Character = 'b'

* Count = 2
* Write:

```
chars[idx] = 'b' → idx = 3
chars[idx] = '2' → idx = 4
```

Array now:

```
["a","3","b","2", ...]
```

---

### Step 3: Character = 'c'

* Count = 10
* Convert `10` → `"1","0"`
* Write:

```
chars[idx] = 'c' → idx = 5
chars[idx] = '1' → idx = 6
chars[idx] = '0' → idx = 7
```

---

### Final Array

```
["a","3","b","2","c","1","0"]
```

### Return

```
7
```

---

## 2) Python Solution (LeetCode Accepted)

```python
class Solution:
    def compress(self, chars: list[str]) -> int:
        n = len(chars)
        i = 0
        idx = 0

        while i < n:
            ch = chars[i]
            count = 0

            while i < n and chars[i] == ch:
                i += 1
                count += 1

            chars[idx] = ch
            idx += 1

            if count > 1:
                for d in str(count):
                    chars[idx] = d
                    idx += 1

        return idx
```

---

## 3) C++ Solution (LeetCode Accepted)

```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int idx = 0;

        while(i < n) {
            char ch = chars[i];
            int count = 0;

            while(i < n && chars[i] == ch) {
                i++;
                count++;
            }

            chars[idx++] = ch;

            if(count > 1) {
                string c = to_string(count);
                for(char d : c) {
                    chars[idx++] = d;
                }
            }
        }
        return idx;
    }
};
```

---

## 4) Edge Cases You Must Remember

### Case 1: Single Character

```
["a"]
Output → ["a"]
Return → 1
```

### Case 2: No Repetition

```
["a","b","c"]
Output → ["a","b","c"]
Return → 3
```

### Case 3: All Same

```
["a","a","a","a"]
Output → ["a","4"]
Return → 2
```

### Case 4: Count Greater Than 9

```
["a" x 12]
Output → ["a","1","2"]
Return → 3
```

### Case 5: Mixed Single and Multiple

```
["a","b","b","c"]
Output → ["a","b","2","c"]
Return → 4
```

---

## Interview One-Liner

> We scan groups of identical characters, write the character once, and append its count only if greater than one, using two pointers to modify the array in-place.

---