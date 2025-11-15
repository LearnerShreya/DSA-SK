# Palindrome, Remove Occurrences

---

# **1. Palindrome Problem**

## **Definition**

A **palindrome** is a string that reads the same forward and backward, ignoring non-alphanumeric characters and case differences.
For example:

* `"A man, a plan, a canal: Panama"` → **Palindrome**
* `"race a car"` → **Not Palindrome**

---

## **Approach**

We use the **two-pointer technique**:

* One pointer starts from the **beginning** (`st`), and another from the **end** (`end`).
* We move both pointers toward the center, comparing characters.
* If any mismatch occurs, it’s not a palindrome.
* Ignore characters that are not letters or digits.

---

## **Algorithm (Step-by-Step)**

1. Initialize `st = 0` and `end = s.length() - 1`.
2. While `st < end`:

   * If `s[st]` is not alphanumeric → increment `st` and continue.
   * If `s[end]` is not alphanumeric → decrement `end` and continue.
   * Convert both characters to lowercase and compare:

     * If they differ → return false.
   * Otherwise, move both pointers (`st++`, `end--`).
3. If the loop finishes without returning false → return true.

---

## **C++ Implementation**

```cpp
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAlphaNum(char ch) {
        return (ch >= 'a' && ch <= 'z') ||
               (ch >= 'A' && ch <= 'Z') ||
               (ch >= '0' && ch <= '9');
    }

    bool isPalindrome(string s) {
        int st = 0, end = s.length() - 1;

        while (st < end) {
            if (!isAlphaNum(s[st])) {
                st++;
                continue;
            }
            if (!isAlphaNum(s[end])) {
                end--;
                continue;
            }
            if (tolower(s[st]) != tolower(s[end]))
                return false;
            st++;
            end--;
        }
        return true;
    }
};

int main() {
    Solution obj;
    string s = "A man, a plan, a canal: Panama";
    cout << (obj.isPalindrome(s) ? "Palindrome" : "Not Palindrome");
    return 0;
}
```

---

## **Python Implementation**

```python
class Solution:
    def isPalindrome(self, s: str) -> bool:
        st, end = 0, len(s) - 1

        while st < end:
            if not s[st].isalnum():
                st += 1
                continue
            if not s[end].isalnum():
                end -= 1
                continue
            if s[st].lower() != s[end].lower():
                return False
            st += 1
            end -= 1
        return True


obj = Solution()
s = "A man, a plan, a canal: Panama"
print("Palindrome" if obj.isPalindrome(s) else "Not Palindrome")
```

---

## **Complexity Analysis**

* **Time Complexity:** O(n)
  Each character is checked at most once.
* **Space Complexity:** O(1)
  No extra space apart from pointers.

---

# **2. Remove Occurrences Problem**

## **Definition**

Given two strings `s` and `part`, remove **all occurrences** of `part` from `s`.
Continue removing until `part` no longer exists in `s`.

**Example:**

```
Input: s = "daabcbaabcbc", part = "abc"  
Output: "dab"
```

---

## **Approach**

Use the built-in string methods `find()` and `erase()`:

1. While the substring `part` exists in `s`, find its position using `s.find(part)`.
2. Remove it using `s.erase(position, part.length())`.
3. Repeat until no occurrence remains.

---

## **C++ Implementation**

```cpp
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.find(part) != string::npos) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

int main() {
    Solution obj;
    string s = "daabcbaabcbc";
    string part = "abc";
    cout << obj.removeOccurrences(s, part);
    return 0;
}
```

---

## **Python Implementation**

```python
class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        while part in s:
            s = s.replace(part, "", 1)
        return s


obj = Solution()
s = "daabcbaabcbc"
part = "abc"
print(obj.removeOccurrences(s, part))
```

---

## **Step-by-Step Example**

### Input:

```
s = "daabcbaabcbc"
part = "abc"
```

### Process:

| Step | String       | Explanation                     |
| ---- | ------------ | ------------------------------- |
| 1    | daabcbaabcbc | Found "abc" → remove it         |
| 2    | dabaabcbc    | Found another "abc" → remove it |
| 3    | dabcbc       | Found "abc" again → remove it   |
| 4    | dab          | No "abc" left → stop            |

### Output:

```
dab
```

---

## **Complexity Analysis**

* **Time Complexity:** O(n × m)
  (Each removal may cause a new search.)
* **Space Complexity:** O(1)
  Uses only the given string.

---

## **Key Differences Between Problems**

| Feature        | Palindrome                           | Remove Occurrences                    |
| -------------- | ------------------------------------ | ------------------------------------- |
| Purpose        | Check if string reads same both ways | Remove all appearances of a substring |
| Core Idea      | Two-pointer comparison               | Repeated search and erase             |
| Focus          | Character-by-character validation    | Substring manipulation                |
| Complexity     | O(n)                                 | O(n × m)                              |
| Common Methods | `tolower()`, `isalnum()`             | `find()`, `erase()`                   |

---

These two problems together help strengthen understanding of **string traversal**, **two-pointer logic**, and **in-place modification**—key skills for mastering string manipulation in both C++ and Python.