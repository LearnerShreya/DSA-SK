
# 🌼 3021. Alice and Bob Playing Flower Game

- [Problem: flowerGame](https://leetcode.com/problems/alice-and-bob-playing-flower-game/)

Two players (Alice and Bob) play with **two lanes of flowers**:

* Lane 1 has `x` flowers (`1 ≤ x ≤ n`).
* Lane 2 has `y` flowers (`1 ≤ y ≤ m`).

Rules:

1. Alice always plays first.
2. On a turn, a player removes **exactly one flower** from either lane.
3. If after a move, **no flowers remain in both lanes**, the current player **wins** immediately.

We need to count:
👉 How many pairs `(x, y)` (with `1 ≤ x ≤ n` and `1 ≤ y ≤ m`) guarantee that **Alice wins**?

---

# 1. Intuition — what’s really happening?

The game is like **“take one flower per turn”**, where Alice goes first.
Key observation:

* Each turn reduces the **total flower count (x+y)** by exactly `1`.
* So if the total number of flowers is **odd**, then **Alice wins** (because she makes the last move).
* If the total is **even**, then **Bob wins**.

✔️ So, Alice wins **if and only if `x + y` is odd**.

Thus, the problem reduces to:
👉 Count pairs `(x, y)` such that `x + y` is odd.

---

# 2. How to check odd vs even?

* `odd + even = odd`
* `even + odd = odd`
* `odd + odd = even`
* `even + even = even`

So, Alice wins if:

* `x` is odd and `y` is even, OR
* `x` is even and `y` is odd.

---

# 3. Counting strategy

We need:

* Count of **odd numbers** in `[1, n]` = `(n + 1) // 2`
* Count of **even numbers** in `[1, n]` = `n // 2`
* Count of **odd numbers** in `[1, m]` = `(m + 1) // 2`
* Count of **even numbers** in `[1, m]` = `m // 2`

Valid pairs =
`(odd_n * even_m) + (even_n * odd_m)`

This counts all `(x, y)` where sum is odd.

---

# 4. Two Code Versions

### ✅ Version 1: Direct formula shortcut

```python
class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        return (m * n) // 2
```

Explanation:

* Total pairs = `n * m`
* Exactly half will have odd sums → `(n * m) // 2`

---

### ✅ Version 2: Explicit odd/even counting

```python
class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        odd_n = (n + 1) // 2
        even_n = n // 2
        odd_m = (m + 1) // 2
        even_m = m // 2
        return odd_n * even_m + even_n * odd_m
```

Explanation:

* Compute odd/even counts separately.
* Return valid combinations where sum is odd.

This version is more **beginner-friendly** and shows the logic clearly.

---

# 5. Dry Run — Example 1

Input: `n=3, m=2`

* `odd_n = (3+1)//2 = 2` → {1,3}
* `even_n = 3//2 = 1` → {2}
* `odd_m = (2+1)//2 = 1` → {1}
* `even_m = 2//2 = 1` → {2}

Pairs:

* Odd\_n × Even\_m = `2*1 = 2` → (1,2), (3,2)
* Even\_n × Odd\_m = `1*1 = 1` → (2,1)

Total = 3 ✅ (matches output).

---

# 6. Complexity

* **Time Complexity:** O(1) (just arithmetic, no loops).
* **Space Complexity:** O(1).

Works even for maximum constraints (`10^5`).

---

# 7. Common Mistakes

* Forgetting Alice always plays first (so parity matters).
* Thinking about *strategy* unnecessarily — it’s purely math (odd/even sum).
* Forgetting integer division in Python (`//`).

---

# 8. Quick Rulebook (for revision)

1. Alice wins ⟺ `x + y` is odd.
2. Total valid pairs = `(n*m)//2`.
3. Or compute explicitly: `(odd_n*even_m) + (even_n*odd_m)`.
4. Odd count in `[1, k]` = `(k+1)//2`, Even count = `k//2`.

---