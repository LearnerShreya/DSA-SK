# Valid Sudoku 

- [Problem: isValidSudoku](https://leetcode.com/problems/valid-sudoku/?envType=daily-question&envId=2025-08-30&difficulty=EASY)

**Goal:** Check whether a 9×9 partially-filled Sudoku board is *valid so far* (you don't need to solve it). A board is valid if:

1. Each row contains no repeated digits 1–9.
2. Each column contains no repeated digits 1–9.
3. Each 3×3 sub-box contains no repeated digits 1–9.

Empty cells are represented by `"."` and should be ignored.

---

# 1. Intuition — simple mental model

Imagine three sets of containers that collect digits as you scan the board from left→right, top→bottom:

* **Row sets**: one set per row (9 sets). When you see a digit in row `r`, you check/add to `rows[r]`.

  ```python
  rows = [ {}, {}, ..., {} ]  # 9 empty sets, one for each row
  ```

* **Column sets**: one set per column (9 sets). For a digit in column `c`, check/add to `cols[c]`.

  ```python
  cols = [ {}, {}, ..., {} ]  # 9 empty sets, one for each column
  ```

* **Box sets**: one set per 3×3 box (9 sets). For a digit at `(r, c)`, check/add to `boxes[box_index]`.

  ```python
  boxes = [ {}, {}, ..., {} ]  # 9 empty sets, one for each 3×3 sub-box
  ```

If a digit is already present in any of the three corresponding sets, the board is invalid.

Why this works: each number must be unique within its row, its column and its 3×3 box. Checking all three while scanning ensures we catch any violation the moment it appears.

---


# 2. Box indexing — how we map (r, c) → box\_index

We split the 9×9 board into nine 3×3 boxes, numbered 0 through 8, left-to-right then top-to-bottom:

```
0 0 0 | 1 1 1 | 2 2 2
0 0 0 | 1 1 1 | 2 2 2
0 0 0 | 1 1 1 | 2 2 2
------+-------+------
3 3 3 | 4 4 4 | 5 5 5
3 3 3 | 4 4 4 | 5 5 5
3 3 3 | 4 4 4 | 5 5 5
------+-------+------
6 6 6 | 7 7 7 | 8 8 8
6 6 6 | 7 7 7 | 8 8 8
6 6 6 | 7 7 7 | 8 8 8
```

Formula (Python integer division):

$box\_index = (r // 3) * 3 + (c // 3)$

* Rows 0–2 and cols 0–2 → box 0.
* Rows 0–2 and cols 3–5 → box 1.
* Rows 0–2 and cols 6–8 → box 2.
* Rows 3–5 and cols 0–2 → box 3. ... and so on.

Examples:

* `(r=0, c=0) → box_index = 0`.
* `(r=4, c=7) → (4//3)*3 + (7//3) = 1*3 + 2 = 5` → box 5.

---

# 3. Algorithm — high level (one-pass)

1. Create three arrays of sets: `rows[9]`, `cols[9]`, `boxes[9]` (each element is an empty set).
2. For each cell `(r, c)` scanning rows then columns:

   * If cell is `"."`, continue.
   * Let `val = board[r][c]` (a string digit).
   * Compute `box_index` using the formula above.
   * If `val` is in `rows[r]` or `cols[c]` or `boxes[box_index]` → **invalid** → return `False`.
   * Otherwise, add `val` to all three sets.
3. If the loop finishes with no conflicts → return `True`.

This approach checks constraints incrementally and stops early on the first detected violation.

---

# 4. Python code — beginner-friendly (well-commented)

```python
from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # Create 9 sets for rows, 9 for columns, and 9 for 3x3 boxes
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]

        # Loop over every cell in the 9x9 board
        for r in range(9):
            for c in range(9):
                val = board[r][c]

                # Skip empty cells
                if val == ".":
                    continue

                # Determine which box this cell belongs to
                box_index = (r // 3) * 3 + (c // 3)

                # If the value already exists in the same row, column or box -> invalid
                if (val in rows[r]) or (val in cols[c]) or (val in boxes[box_index]):
                    return False

                # Otherwise, add the value to row, column and box
                rows[r].add(val)
                cols[c].add(val)
                boxes[box_index].add(val)

        # All checks passed
        return True
```

---

# 5. Python alternative — single set trick (concise & memory-friendly)

Instead of three arrays of sets, you can use a single set storing identifers. Each identifier encodes a (constraint-type, index, value) pair.

```python
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        seen = set()
        for r in range(9):
            for c in range(9):
                val = board[r][c]
                if val == ".":
                    continue
                box_index = (r // 3) * 3 + (c // 3)
                # Prepare unique tokens for row, column and box
                row_tok = ("row", r, val)
                col_tok = ("col", c, val)
                box_tok = ("box", box_index, val)

                # If any token already in seen, duplicate exists
                if row_tok in seen or col_tok in seen or box_tok in seen:
                    return False

                seen.add(row_tok)
                seen.add(col_tok)
                seen.add(box_tok)
        return True
```

This is often the most succinct and easy-to-reason-about solution.

---

# 6. Common mistakes & debugging tips

* **Confusing box formula**: remember `(r // 3) * 3 + (c // 3)`. Break it down: `r//3` picks the vertical block (0,1,2), multiply by 3 to shift to boxes 0,3,6 then add `c//3` (0..2).
* **Off-by-one** errors: indices are 0..8. Don’t add or subtract 1 mistakenly.
* **Comparing ints vs strings**: The board stores digits as strings (e.g. `"5"`), so use the same type when checking/adding.
* **Not skipping '.'**: Always `continue` when you see `'.'`.
* **Using list membership instead of set**: `in` on lists is O(n); sets give O(1) on average.

---

# 7. Dry run — step-by-step narration for the example board

Board used (same as LeetCode example 1):

```text
[ ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"] ]
```

We'll show the first 12 filled-cell steps (what gets added to sets). For each step we show `(r,c)`, `val`, `box_index`, and the sets after insertion (rows\[r], cols\[c], boxes\[box\_index]).

| Step | (r,c) | val | box | rows\[r] after | cols\[c] after | boxes\[box] after |
| ---- | ----- | --- | --- | -------------- | -------------- | ----------------- |
| 1    | (0,0) | 5   | 0   | {5}            | {5}            | {5}               |
| 2    | (0,1) | 3   | 0   | {3,5}          | {3}            | {3,5}             |
| 3    | (0,4) | 7   | 1   | {3,5,7}        | {7}            | {7}               |
| 4    | (1,0) | 6   | 0   | {6}            | {5,6}          | {3,5,6}           |
| 5    | (1,3) | 1   | 1   | {1,6}          | {1}            | {1,7}             |
| 6    | (1,4) | 9   | 1   | {1,6,9}        | {7,9}          | {1,7,9}           |
| 7    | (1,5) | 5   | 1   | {1,5,6,9}      | {5}            | {1,5,7,9}         |
| 8    | (2,1) | 9   | 0   | {9}            | {3,9}          | {3,5,6,9}         |
| 9    | (2,2) | 8   | 0   | {8,9}          | {8}            | {3,5,6,8,9}       |
| 10   | (2,7) | 6   | 2   | {6}            | {6}            | {6}               |
| 11   | (3,0) | 8   | 3   | {8}            | {5,6,8}        | {8}               |
| 12   | (3,4) | 6   | 4   | {6,8}          | {6}            | {6}               |

> Note: The exact intermediate contents for every set are tracked in the algorithm — the table above summarizes the core changes so you can visualize how the sets fill up.

By step 12 we've inserted the first 12 filled digits into their row/col/box sets. If at any step a `val` had already been in any of the corresponding sets, the algorithm would immediately return `False`.

---

# 8. Example where the board becomes invalid quickly

If we change the top-left `5` to `8` (like the LeetCode example 2), the board is invalid because the 3×3 box `0` would have two `8`s. The algorithm finds this when it reaches the duplicate cell — it checks membership and returns `False` immediately.

---

# 9. Complexity

* **Time complexity:** O(81) = O(1) (we visit each cell once). In Big-O terms relative to `n` (where board is n×n), it's `O(n^2)`.
* **Space complexity:** O(81) = O(1) (we store at most 81 inserted values in sets). More generally `O(n^2)` for an n×n board.

---

# 10. Advanced optimization (bitmask approach) — optional

You can use integer bitmasks for each row/col/box instead of sets for slightly faster operations and less memory overhead. Each digit `d` maps to bit `(1 << d)`; check using bitwise AND, set using bitwise OR. This is more advanced and useful in contests.

---

# 11. Quick revision checklist (for exams/interviews)

* Use sets for O(1) membership checks.
* Skip `'.'` cells.
* Correctly compute `box_index` with `// 3`.
* Stop early on the first duplicate found.
* Practice dry runs on small boards to solidify intuition.

---

# 12. Practice tasks (to build logic)

1. Modify the board size to 4×4 with 2×2 boxes and adapt the code.
2. Implement the same validator in C++.
3. Implement the bitmask version and compare speed on random boards.
4. Write unit tests including edge cases: empty board, board with all dots, board where row is invalid, board where column is invalid, board where box is invalid.

---

---

```python
from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]

        for r in range(9):
            for c in range(9):
                val = board[r][c]
                if val == ".":
                    continue
                box_index = (r // 3) * 3 + (c // 3)
                if val in rows[r] or val in cols[c] or val in boxes[box_index]:
                    return False
                rows[r].add(val)
                cols[c].add(val)
                boxes[box_index].add(val)
        return True


# ---------------- Test Code ----------------
if __name__ == "__main__":
    board = [
        ["5","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]

    sol = Solution()
    print("Is the Sudoku valid?:", sol.isValidSudoku(board))
```

It will print:

```
Is the Sudoku valid?: True
```
---

# 🧩 Explanation

---

### **Import**

```python
from typing import List
```

We bring in `List` from Python’s `typing` module.
This lets us describe the input type (`List[List[str]]` = 2D list of strings).

---

### **Class Definition**

```python
class Solution:
```

A class named `Solution`.
LeetCode requires your solution inside a class.

---

### **Function Definition**

```python
def isValidSudoku(self, board: List[List[str]]) -> bool:
```
* `def` in Python is a keyword used to **define (create) a function** — i.e., give a block of code a name so you can reuse it later. 
* Function name: `isValidSudoku`
* Input: `board` → 9×9 grid (list of lists of strings)
* Output: Boolean (`True` if valid, `False` if not)

---

### **Tracking Structures**

```python
rows = [set() for _ in range(9)]
cols = [set() for _ in range(9)]
boxes = [set() for _ in range(9)]
```

We create 9 empty sets for each:

* `rows` → store numbers seen in each row
* `cols` → store numbers seen in each column
* `boxes` → store numbers seen in each 3×3 box

Sets are perfect because they **don’t allow duplicates**.

---

### **Row and Column Loop**

```python
for r in range(9):
    for c in range(9):
```

Nested loops → visit each cell of the board using `(r, c)` as row and column indexes.

---

### **Cell Value**

```python
val = board[r][c]
if val == ".":
    continue
```

* If the cell is `"."` (empty), skip it.
* Otherwise, `val` holds the number string like `"5"`, `"9"`, etc.

---

### **Box Index Formula**

```python
box_index = (r // 3) * 3 + (c // 3)
```

This maps each cell `(r, c)` to one of the 9 sub-boxes.
Boxes are numbered like this:

```
0 | 1 | 2
---------
3 | 4 | 5
---------
6 | 7 | 8
```

---

### **Duplicate Check**

```python
if val in rows[r] or val in cols[c] or val in boxes[box_index]:
    return False
```

If the number already exists in its row, column, or box → invalid Sudoku.

---

### **Record Number**

```python
rows[r].add(val)
cols[c].add(val)
boxes[box_index].add(val)
```

If no duplicates found, add the number into the respective row, column, and box set.

---

### **Final Validity**

```python
return True
```

If all cells are processed without conflicts → the Sudoku is valid.

---

# 🧾 Final Rulebook (Clean)

1. Create 9 sets each for rows, columns, and boxes.
2. Loop through every cell `(r, c)`.
3. Skip if empty (`"."`).
4. Find which 3×3 box the cell belongs to using `(r//3)*3 + (c//3)`.
5. If number already exists in row, column, or box → return `False`.
6. Otherwise, record the number in all three places.
7. If no issues found → return `True`.

---