# Aggressive Cows

---

## **Problem Statement**

You are given:

* `N` stalls with positions given in an array `arr[]`.
* `C` cows to be placed in these stalls.

**Objective:** Place the cows in the stalls so that the **minimum distance** between any two cows is **maximized**.

For example:

```text
arr = [1, 2, 4, 8, 9], N = 5, C = 3
```

We want to place 3 cows such that the minimum distance between any two cows is as large as possible.

---

## **Step 1: Understanding the problem**

* The problem is about **maximizing the minimum distance** between cows.
* Directly trying all placements would take too long (combinatorial problem).
* Instead, we can use **binary search on the answer**.

---

## **Step 2: Sorting the stalls**

The first step is to sort the stall positions:

```text
arr = [1, 2, 4, 8, 9] → sorted
```

Sorting is important because:

* We always place cows from left to right.
* This makes it easy to check distances.

---

## **Step 3: Binary Search on Answer**

* The **search space** for the minimum distance is `[1, arr[N-1] - arr[0]]`.

  * `1` is the smallest possible distance.
  * `arr[N-1] - arr[0]` is the largest possible distance between the first and last stall.

* Use **binary search** to find the maximum valid minimum distance.

**Binary search steps:**

1. `st = 1`
2. `end = arr[N-1] - arr[0]`
3. `while st <= end:`

   * `mid = (st + end) // 2` → candidate minimum distance
   * Check if we can place all cows with at least `mid` distance (`is_possible()` function).

     * If yes → `ans = mid` and try **larger distance** → `st = mid + 1`
     * If no → try **smaller distance** → `end = mid - 1`

---

## **Step 4: Checking possibility (`is_possible`)**

We check if it's possible to place all cows with at least `min_allowed_dist`:

```python
cows = 1
last_stall_pos = arr[0]

for i in range(1, N):
    if arr[i] - last_stall_pos >= min_allowed_dist:
        cows += 1
        last_stall_pos = arr[i]
    if cows == C:
        return True
return False
```

**Explanation:**

* Place the first cow at the first stall.
* Iterate through the remaining stalls:

  * If the distance from the last placed cow ≥ `min_allowed_dist`, place a cow.
  * If all cows are placed, return `True`.
* If we run out of stalls before placing all cows, return `False`.

This is **O(N)** for each check.

---

## **Step 5: Combining Binary Search and Check**

* Binary search tries different minimum distances.
* `is_possible()` checks if a distance is feasible.
* Binary search ensures we find the **largest minimum distance** efficiently.

**Time Complexity:**

* Sorting: `O(N log N)`
* Binary search: `O(log(range) * N)` → for each mid value, we scan stalls.
* Overall: `O(N log N + N log(range))`

---

## **Step 6: Example Walkthrough**

```text
arr = [1, 2, 4, 8, 9], N = 5, C = 3
```

1. Sort → `[1, 2, 4, 8, 9]`
2. Binary search range → `[1, 8]`

**Step 1:** mid = 4

* Place cows: 1 at 1, 2 at 8 (distance ≥ 4?), 3 at 9 (distance ≥ 4?)
* Feasible → try larger → st = 5

**Step 2:** mid = 6

* Place cows: 1 at 1, 2 at 8 (distance 7 ≥ 6), 3 → no more feasible stalls
* Not feasible → try smaller → end = 5

**Step 3:** mid = 5

* Place cows: 1 at 1, 2 at 8 (distance 7 ≥ 5), 3 → cannot place → not feasible
* Smaller → end = 4

✅ Maximum feasible distance = **3**

---

## **Step 7: Python Implementation**

```python
def is_possible(arr, N, C, min_allowed_dist):
    cows = 1
    last_stall_pos = arr[0]
    for i in range(1, N):
        if arr[i] - last_stall_pos >= min_allowed_dist:
            cows += 1
            last_stall_pos = arr[i]
        if cows == C:
            return True
    return False

def get_distance(arr, N, C):
    arr.sort()
    st, end = 1, arr[-1] - arr[0]
    ans = -1
    while st <= end:
        mid = (st + end) // 2
        if is_possible(arr, N, C, mid):
            ans = mid
            st = mid + 1
        else:
            end = mid - 1
    return ans

# Example
N = 5
C = 3
arr = [1, 2, 8, 4, 9]
print(get_distance(arr, N, C))  # Output: 3
```

---

This problem is a classic example of **“Binary Search on Answer”**, widely used in competitive programming.