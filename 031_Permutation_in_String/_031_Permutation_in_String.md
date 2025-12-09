# Permutation in String

---

## 1) Problem Essence

Check whether **any permutation of `s1` appears as a substring in `s2`**.

A permutation means:
same characters + same frequency, **order does not matter**.

---

## 2) Key Insight

We do not generate permutations.

Instead, we compare **character frequencies**:

> Does any substring of `s2` with length `len(s1)` have the same frequency count as `s1`?

---

## 3) Why Sliding Window

A valid permutation must be the **same length** as `s1`.
So we maintain a **fixed-size window of length `len(s1)`** on `s2`, update character counts dynamically, and compare with `s1` frequency.

---

## 4) Algorithm (Optimized)

1. Build frequency count of `s1` → `freq1`
2. Build frequency for the first window of `s2` of length `len(s1)` → `freq2`
3. If equal → return True
4. Slide the window across `s2`:

   * Add the new (right) character
   * Remove the outgoing (left) character
   * Compare again
5. If no match until the end → return False

---

## 5) Python Implementation

```python
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        from collections import Counter

        m, n = len(s1), len(s2)  # m = window size, n = full string

        if m > n:
            return False

        freq1 = Counter(s1)
        freq2 = Counter(s2[:m])

        if freq1 == freq2:
            return True

        for i in range(m, n):
            freq2[s2[i]] += 1
            freq2[s2[i - m]] -= 1
            if freq2[s2[i - m]] == 0:
                del freq2[s2[i - m]]
            if freq1 == freq2:
                return True
        
        return False

# ---------- Function call ----------
sol = Solution()

s1 = "ab"
s2 = "eidbaooo"
result = sol.checkInclusion(s1, s2)
print(result)  # expected output: True

# Additional test cases
print(sol.checkInclusion("ab", "eidboaoo"))   # False
print(sol.checkInclusion("adc", "dcda"))      # True (because "cda" is a permutation of "adc")
```

---

## 6) C++ Implementation

```cpp
class Solution {
public:
    bool isFreqSame(int f1[], int f2[]) {
        for(int i = 0; i < 26; i++)
            if(f1[i] != f2[i]) return false;
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        int freq1[26] = {0}, freq2[26] = {0};
        int k = s1.length();

        for(char c : s1) freq1[c - 'a']++;
        for(int i = 0; i < k; i++) freq2[s2[i] - 'a']++;

        if(isFreqSame(freq1, freq2)) return true;

        for(int i = k; i < s2.length(); i++) {
            freq2[s2[i] - 'a']++;
            freq2[s2[i - k] - 'a']--;
            if(isFreqSame(freq1, freq2)) return true;
        }
        return false;
    }
};
```

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isFreqSame(int f1[], int f2[]) {
        for(int i = 0; i < 26; i++)
            if(f1[i] != f2[i]) return false;
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        int freq1[26] = {0}, freq2[26] = {0};
        int k = s1.length();

        for(char c : s1) freq1[c - 'a']++;
        for(int i = 0; i < k; i++) freq2[s2[i] - 'a']++;

        if(isFreqSame(freq1, freq2)) return true;

        for(int i = k; i < s2.length(); i++) {
            freq2[s2[i] - 'a']++;
            freq2[s2[i - k] - 'a']--;
            if(isFreqSame(freq1, freq2)) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;     // object creation

    string s1 = "ab";
    string s2 = "eidbaooo";

    bool result = sol.checkInclusion(s1, s2);   // function call

    cout << (result ? "true" : "false") << endl;
    return 0;
}
```

---

## 7) Complexity

| Type  | Value                                      |
| ----- | ------------------------------------------ |
| Time  | $$O(\text{len}(s2))$$ — window slides once |
| Space | $$O(1)$$ — only 26 lowercase characters    |

---

## 8) Dry Run (Precise and quick)

```
s1 = "ab"
s2 = "eidbaooo"
k = 2
```

Initial frequencies:

```
freq1 = [a:1, b:1]
freq2 (window "ei") = [e:1, i:1] → no match
```

Window movements:

| Window | Substring | Action  | Match   |
| ------ | --------- | ------- | ------- |
| 0–1    | ei        | initial | no      |
| 1–2    | id        | +d, −e  | no      |
| 2–3    | db        | +b, −i  | no      |
| 3–4    | ba        | +a, −d  | **yes** |

Window `"ba"` has same frequency as `"ab"`, so output is **True**.

---

## 9) Pattern Recognition (Summary)

If a problem mentions:

* substring is a permutation
* find an anagram inside a string
* same characters / same counts

Use:
**Sliding Window (fixed size) + Frequency Map**

---

### Result

```
True
```

---
---

## Dry Run (array format)

```
s1 = "ab"
s2 = "eidbaooo"
k = 2
```

### Step 1 — freq for s1 = "ab"

```
freq = [
 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
] 
  a  b  c  d  e  f  g  h  i  j  k  l ...
```

### Step 2 — first window of s2 = "ei"

```
windFreq = [
 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
]
  a  b  c  d  e  f  g  h  i ...
```

`freq != windFreq` → slide window.

---

## Window Sliding

### Window 1 → 2   substring `"id"`

Operation: +d, −e

```
Before: windFreq = [0,0,0,0,1,0,0,0,1,0,...]
Remove 'e'  → index 4--
Add 'd'     → index 3++

After: windFreq = [
 0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
]
                  d     i
Match? No
```

---

### Window 2 → 3   substring `"db"`

Operation: +b, −i

```
Before: windFreq = [0,0,0,1,0,0,0,0,1,0,...]
Remove 'i'  → index 8--
Add 'b'     → index 1++

After: windFreq = [
 0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
]
        b     d
Match? No
```

---

### Window 3 → 4   substring `"ba"`

Operation: +a, −d

```
Before: windFreq = [0,1,0,1,0,0,0,0,0,0,...]
Remove 'd'  → index 3--
Add 'a'     → index 0++

After: windFreq = [
 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
]
  a b
Match? YES
```

Since `windFreq == freq`, permutation exists.

---

## Final Output

```
true
```

Because `"ba"` inside `"eidbaooo"` has the same character frequency as `"ab"`.

---
---

## Dry Run

```
s1 = "ababb"
s2 = "caaabbabbde"
```

### Step 1 — Build freq1 from s1

```
s1 = a b a b b
      2 3
```

```
freq1 = [2,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
          a b
```

Window size `k = 5`

---

### Step 2 — Build first window freq2 = s2[0..4] = "caaab"

```
c a a a b
  3   1 1
```

```
freq2 = [3,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
          a b c
```

`freq2 != freq1` → slide window

---

## Sliding Window (add new char, remove old char)

| Slide | Window substring | Out | In | freq2 before | freq2 after | Match? |
| ----- | ---------------- | --- | -- | ------------ | ----------- | ------ |
| 1     | "aaabb"          | c   | b  | [3,1,1]      | [3,2,0]     | ❌ No   |
| 2     | "aabba"          | a   | a  | [3,2,0]      | [3,2,0]     | ❌ No   |
| 3     | "abbab"          | a   | b  | [3,2,0]      | [2,3,0]     | ✔ Yes  |

For slide 3:

Before:

```
freq2 = [3,2,0,...]   (3 a's, 2 b's)
```

Operation:

```
- outgoing 'a'  → a: 3 → 2
+ incoming 'b'  → b: 2 → 3
```

After:

```
freq2 = [2,3,0,...]
freq1 = [2,3,0,...]
```

These match perfectly → permutation found.

---

## Result

```
Output: true
```

because substring:

```
"abbab"
```

is a permutation of:

```
"ababb"
```

---

## Why the window matched at slide 3

| Character | Required by s1 | Present in window "abbab" |
| --------- | -------------- | ------------------------- |
| a         | 2              | 2                         |
| b         | 3              | 3                         |
| others    | 0              | 0                         |

Perfect frequency match → return `true`.

---

### Memory Hack

Sliding window checks:

```
Remove left, Add right → Compare
```

When both freq arrays identical → permutation exists.

---