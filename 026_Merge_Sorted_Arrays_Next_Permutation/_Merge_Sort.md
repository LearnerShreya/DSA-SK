## Merge Sort – Theory

### Overview

Merge Sort is one of the most efficient **divide and conquer** sorting algorithms. It works by dividing the array into smaller parts, sorting those parts, and then merging them back together in sorted order.

It ensures **O(n log n)** performance in all cases (best, average, worst) and is **stable**, meaning it preserves the relative order of equal elements.

---

### Concept

Merge Sort follows three main steps:

1. **Divide** – Split the array into two halves until each subarray contains one element (a single element is always sorted).
2. **Conquer** – Sort the smaller subarrays recursively.
3. **Combine** – Merge the sorted subarrays to produce a final sorted array.

---

### Working Example

Let’s sort `A = [5, 2, 4, 6, 1, 3]`

**Step 1:** Divide repeatedly

```
[5, 2, 4, 6, 1, 3]
→ [5, 2, 4] and [6, 1, 3]
→ [5], [2, 4] and [6], [1, 3]
→ [5], [2], [4], [6], [1], [3]
```

**Step 2:** Conquer and combine while merging

```
Merge [2] and [4] → [2, 4]
Merge [1] and [3] → [1, 3]
Now merge:
[5] + [2, 4] → [2, 4, 5]
[6] + [1, 3] → [1, 3, 6]
Finally:
[2, 4, 5] + [1, 3, 6] → [1, 2, 3, 4, 5, 6]
```

---

### Merge Process (Core Idea)

The **merge step** is the heart of merge sort.
When two sorted subarrays `L` and `R` are merged:

1. Compare `L[i]` and `R[j]`.
2. Place the smaller element in the result array.
3. Move the pointer in that array forward.
4. Repeat until all elements are merged.

This process is similar to **merging sorted arrays**, like in your “Merge Sorted Arrays” problem.

---

### Pseudocode

```
mergeSort(arr):
    if length(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left = mergeSort(arr[:mid])
    right = mergeSort(arr[mid:])
    return merge(left, right)

merge(left, right):
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result
```

---

### Time and Space Complexity

| Phase     | Work Done      | Explanation                                     |
| --------- | -------------- | ----------------------------------------------- |
| Divide    | O(log n)       | Array is halved each time                       |
| Merge     | O(n)           | Each element compared and merged once per level |
| **Total** | **O(n log n)** | Merging happens log n times over n elements     |

**Space Complexity:** O(n) (extra temporary arrays are used while merging)
**Stable:** Yes (keeps equal elements in the same order)

---

### Key Points to Remember

* Uses **Divide and Conquer** approach.
* Always **O(n log n)** (better than QuickSort’s worst case).
* Requires **extra space**, not in-place.
* Ideal for **linked lists** or external sorting (like files).
* **Merge operation** is the same concept used in merging two sorted arrays.

---