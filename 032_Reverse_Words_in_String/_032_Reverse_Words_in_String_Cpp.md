# Reverse Words in String | Cpp

- https://leetcode.com/problems/reverse-words-in-a-string/

---

**Task:**
Given a string `s`, return another string where the **order of words** is reversed, and any **extra spaces** are removed.

Example
Input: `"  hello   world  "`
Output: `"world hello"`

---

# What counts as a “word”?

A word is a continuous sequence of non-space characters.
Spaces can appear anywhere: beginning, middle, end, or many together.

---

# Why this problem matters

Interviewers use it to check:
• String manipulation
• Pointer movement
• Understanding of in-place reversal
• Clean space handling
• Boundary condition awareness

---

# Strategy Used in the Code

This approach uses two ideas:
**(1) Reverse the whole string**
**(2) Reverse each word again**

This is a classic trick that avoids using extra arrays or vectors.

---

# Deep Explanation of the Logic

## 1. Reverse the entire string

This changes the global order of words.

Example
Before: `"the sky is blue"`
After reverse: `"eulb si yks eht"`

Now the last word is at the front, but its letters are reversed too.

---

## 2. Iterate through the reversed string

We scan left to right using an index.

During scanning, two major actions happen:

### A. Skip spaces

Spaces between words or at edges should not appear in the final result.
The code uses:

```
while(i < n && s[i] == ' ') i++;
```

### B. Collect characters of one word

We collect characters until we hit a space:

```
while(i < n && s[i] != ' ')
    word += s[i];
```

At this point, `word` contains reversed characters of a real word.

Example
Reversed string: `"eulb si yks eht"`
Collected word: `"eulb"`

---

## 3. Reverse each collected word

Since the full string was reversed earlier, each word is backward.
So we reverse the collected word again:

```
reverse(word.begin(), word.end());
```

Example
Collected: `"eulb"`
After reversing: `"blue"`

---

## 4. Append the corrected word to the final answer

We place exactly one space between words by checking:

```
if(!ans.empty()) ans += " ";
ans += word;
```

This removes all unnecessary spaces at the start, end, and middle.

---

## 5. Continue until the full string is processed

The loop repeats until index `i` reaches `n`.

---

# Complexity

**Time:** O(n)
Every character is processed a constant number of times.

**Space:** O(n)
Final output requires a new string.

---

# Why this method is preferred in interviews

• Shows strong understanding of two-pointer scanning.
• Handles edge cases smoothly.
• No large extra containers used.
• Predictable runtime and memory usage.
• Demonstrates the “double reversal” technique.

---

# Edge Cases Covered

1. `"     "` (only spaces) → `""`
2. `"word"` (single word) → `"word"`
3. `"a good   example"` → `"example good a"`
4. `"  hello"` → `"hello"`
5. `"hello  "` → `"hello"`
6. `"   hello   world   "` → `"world hello"`

All extra spaces are cleaned.

---

# Code

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        int i = 0;
        while(i < n) {
            while(i < n && s[i] == ' ') i++;

            string word = "";
            while(i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            if(!word.empty()) {
                reverse(word.begin(), word.end());

                if(!ans.empty()) ans += " ";
                ans += word;
            }
        }

        return ans;
    }
};
```
---

# Dry Run

Use a messy input so all cases are visible.

### Input

```
"  hello   world  "
```

Length n = 17

---

## Step 1: Reverse the entire string

Original

```
"  hello   world  "
```

Reversed

```
"  dlrow   olleh  "
```

Let’s index it for clarity:

| Index | Char |
| ----- | ---- |
| 0     | ' '  |
| 1     | ' '  |
| 2     | 'd'  |
| 3     | 'l'  |
| 4     | 'r'  |
| 5     | 'o'  |
| 6     | 'w'  |
| 7     | ' '  |
| 8     | ' '  |
| 9     | ' '  |
| 10    | 'o'  |
| 11    | 'l'  |
| 12    | 'l'  |
| 13    | 'e'  |
| 14    | 'h'  |
| 15    | ' '  |
| 16    | ' '  |

`i = 0`, `ans = ""`

---

# Main Loop

## 1) Skip spaces

Indices 0,1 are spaces.

`i` moves:
0 → 1 → 2

Now:
`i = 2` (s[i] = 'd')

---

## 2) Collect word

We create `word = ""`.

Characters added until next space:

| Index | Char | word    |
| ----- | ---- | ------- |
| 2     | d    | "d"     |
| 3     | l    | "dl"    |
| 4     | r    | "dlr"   |
| 5     | o    | "dlro"  |
| 6     | w    | "dlrow" |

Stop at index 7 (space).

Now:
`word = "dlrow"`

---

## 3) Reverse the word

reverse("dlrow") → `"world"`

---

## 4) Add to ans

ans is empty, so no space added.
`ans = "world"`

`i = 7`

---

## Loop continues

---

## 5) Skip spaces again

Indices 7,8,9 are spaces.

i moves:
7 → 8 → 9 → 10

Now `i = 10` (s[i] = 'o')

---

## 6) Collect next word

| Index | Char | word    |
| ----- | ---- | ------- |
| 10    | o    | "o"     |
| 11    | l    | "ol"    |
| 12    | l    | "oll"   |
| 13    | e    | "olle"  |
| 14    | h    | "olleh" |

Stop at index 15 (space).

`word = "olleh"`

---

## 7) Reverse the word

reverse("olleh") → `"hello"`

---

## 8) Append to ans

ans = "world" → add space → add "hello"
`ans = "world hello"`

`i = 15`

---

## 9) Skip spaces again

Indices 15 and 16 are spaces.

i moves: 15 → 16 → 17

Now `i = 17`, loop ends.

---

# Final Output

```
"world hello"
```

---

# Summary Notes (Dry Run Logic)

1. Reverse whole string → word order flips but letters flip too.
2. Skip initial spaces.
3. Extract reversed word.
4. Reverse it back.
5. Add to result with correct spacing.
6. Repeat until end.
7. Extra spaces naturally get removed.

---

# Summary (quick recall for interview)

• Reverse whole string.
• Skip spaces.
• Extract a word.
• Reverse extracted word.
• Add to final string with one space.
• Repeat until end.

This ensures:
• Only words are reversed.
• Letters inside words stay correct.
• All extra spaces are removed cleanly.

---