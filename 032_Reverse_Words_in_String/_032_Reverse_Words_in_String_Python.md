# Reverse Words in String | Python

- https://leetcode.com/problems/reverse-words-in-a-string/

---

**Goal:**
Given a string `s`, return another string where the **order of words** is reversed and **extra spaces** are removed.

Example
Input: `"  hello   world  "`
Output: `"world hello"`

---

# What counts as a word

A continuous block of non-space characters.

Python makes splitting easier, but an interviewer may ask you to do it manually, so both versions are explained.

---

# Approach 1 (Pythonic): split → reverse → join

Python handles space cleanup for free using `split()`.

### How it works

• `split()` without arguments removes all extra spaces
• `reverse()` or slicing reverses list order
• `join()` connects them with exactly one space

### Code

```python
class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        words.reverse()
        return " ".join(words)
```

### Time

O(n)

### Space

O(n)

---

# Approach 2 (Manual logic similar to C++ pointer approach)

This is useful when the interviewer says:
“Do not use split.”
Or they want to see your understanding of string traversal.

### Core idea

1. Reverse the whole string
2. Walk through reversed string
3. Extract each word
4. Reverse each word back
5. Build final output string cleanly

The concept is the same as the C++ solution.

---

## Why double reversal works

Full string reversal flips everything.
Reversing each word again restores its letters.
End result: only the **order of words** is reversed.

Example
Original: `"the sky is blue"`
Full reverse: `"eulb si yks eht"`
Reverse words: `"blue is sky the"`

---

# Detailed Step-by-Step Logic

### 1. Reverse the whole string

`rs = s[::-1]`
This brings last word to the front.

### 2. Traverse the reversed string

We scan character by character.

### 3. Skip spaces

Same reason as C++: avoids empty words.

### 4. Collect a word

Keep adding characters until a space is found.

### 5. Reverse collected word

Fixes letter order.

### 6. Append to result

Insert one space only if result is not empty.

---

# Full Manual-Pointer Style Python Code

```python
class Solution:
    def reverseWords(self, s: str) -> str:
        s = s[::-1]      # reverse entire string
        n = len(s)
        i = 0
        ans = []

        while i < n:
            # skip spaces
            while i < n and s[i] == ' ':
                i += 1

            word = []

            # collect characters of a word
            while i < n and s[i] != ' ':
                word.append(s[i])
                i += 1

            # if a word is collected
            if word:
                word.reverse()          # fix its letter order
                ans.append("".join(word))

        return " ".join(ans)
```

Here `ans` is a list because appending to a Python string repeatedly is slow.

---

# Why this version is interview-friendly

• Shows understanding of low-level word extraction
• Does not rely on Python’s automatic space handling
• Mirrors the C++ pointer logic
• Demonstrates clarity in algorithm design

---

# Edge Cases handled

1. `"     "` → `""`
2. `"hello"` → `"hello"`
3. `"a good   example"` → `"example good a"`
4. `"  hello"` → `"hello"`
5. `"hello  "` → `"hello"`
6. `"   hello   world   "` → `"world hello"`

---

# Comparison of the Two Python Approaches

| Approach                 | Pros                     | Cons                                                        |
| ------------------------ | ------------------------ | ----------------------------------------------------------- |
| `split → reverse → join` | Short, clean, optimal    | Uses Python built-ins; interviewer may want manual approach |
| Manual pointer method    | Shows deep understanding | More code                                                   |

Both have identical complexity.

---

# Quick Revision Summary

• Reverse full string.
• Skip spaces.
• Extract a word.
• Reverse the extracted word.
• Add to result.
• Join words with spaces.

---
---

# Code

```python
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s.split()[::-1])
```

---

# Let's dry-run with this input

```
s = "  hello   world  python  "
```

---

# **STEP 1: s.split()**

### What `split()` does when no argument is given:

* removes leading spaces
* removes trailing spaces
* collapses multiple spaces between words
* splits on whitespace
* returns a list of words only (no spaces)

### Visualizing:

```
"  hello   world  python  "
   ^    ^^^    ^^     extra spaces
```

`split()` produces:

```
s.split() → ["hello", "world", "python"]
```

So after step 1:

```
words = ["hello", "world", "python"]
```

---

# **STEP 2: Reverse the list using [::-1]**

`[::-1]` creates a reversed copy of the list.

```
["hello", "world", "python"][::-1]
→ ["python", "world", "hello"]
```

So now:

```
reversed_words = ["python", "world", "hello"]
```

---

# **STEP 3: Join them back using " ".join(...)**

`" ".join(list)` joins elements with one space:

```
" ".join(["python", "world", "hello"])
→ "python world hello"
```

This ensures:

* no extra spaces at start or end
* exactly one space between words

---

# **Final output**

```
"python world hello"
```

---

# **Putting all steps together visually**

```
Original string:
"  hello   world  python  "

split():
["hello", "world", "python"]

reverse:
["python", "world", "hello"]

join with spaces:
"python world hello"
```

---

# **Why this solution is elegant**

* Removes all extra spaces automatically
* Handles any number of spaces
* Very short, but powerful
* Uses Python’s built-in optimized operations

---