- https://www.youtube.com/watch?v=K2BEKh-EqqA

# Sorting — Revision Notes

---

## 1) Bubble Sort

* Repeatedly compares adjacent elements and swaps if they are in the wrong order.
* After each pass, the largest element moves to its correct position.
* Best case: **O(n)** (with swap-check optimization)
* Worst and Average: **O(n²)**
* Space: **O(1)**
* Stable: **✔**
* In-place: **✔**
* Suitable for: Small or nearly sorted data
* Not suitable for: Large datasets

---

## 2) Selection Sort

* Finds the minimum element from the unsorted region and places it at the beginning.
* Performs a fixed number of swaps (n − 1).
* Best, Average, Worst: **O(n²)**
* Space: **O(1)**
* Stable: **❌**
* In-place: **✔**
* Suitable for: Situations requiring minimum swaps
* Not suitable for: Large datasets and performance-critical tasks

---

## 3) Insertion Sort

* Inserts each new element into the correct position in the already sorted portion.
* Uses shifting rather than repeated swapping.
* Best case (nearly sorted): **O(n)**
* Worst and Average: **O(n²)**
* Space: **O(1)**
* Stable: **✔**
* In-place: **✔**
* Suitable for: Nearly sorted lists, small datasets, online/streaming input
* Not suitable for: Large datasets

---

## 4) Merge Sort

* Follows Divide and Conquer: divide → sort halves → merge sorted halves.
* Always **O(n log n)** regardless of input.
* Space: **O(n)** (due to temporary arrays)
* Stable: **✔**
* In-place: **❌**
* Suitable for: Large datasets and when stability is required
* Not suitable for: Memory-restricted systems

---

## 5) Quick Sort

* Divides array based on a pivot: smaller elements go left and larger go right.
* Best and Average: **O(n log n)**
* Worst: **O(n²)** (bad pivot selection)
* Space: **O(log n)** (recursive stack)
* Stable: **❌**
* In-place: **✔**
* Suitable for: Large datasets, competitive programming
* Not suitable for: Already sorted or duplicate-heavy inputs unless randomized pivot is used

---

## Final Comparison Table

| Algorithm      | Best       | Average    | Worst      | Space    | Stable | In-place |
| -------------- | ---------- | ---------- | ---------- | -------- | ------ | -------- |
| Bubble Sort    | O(n)       | O(n²)      | O(n²)      | O(1)     | ✔      | ✔        |
| Selection Sort | O(n²)      | O(n²)      | O(n²)      | O(1)     | ❌      | ✔        |
| Insertion Sort | O(n)       | O(n²)      | O(n²)      | O(1)     | ✔      | ✔        |
| Merge Sort     | O(n log n) | O(n log n) | O(n log n) | O(n)     | ✔      | ❌        |
| Quick Sort     | O(n log n) | O(n log n) | O(n²)      | O(log n) | ❌      | ✔        |

---

## Quick Selection Guide

| Situation                             | Recommended Algorithm |
| ------------------------------------- | --------------------- |
| Nearly sorted data                    | Insertion Sort        |
| Large dataset, memory is not an issue | Merge Sort            |
| Large dataset, low memory             | Quick Sort            |
| Minimum number of swaps required      | Selection Sort        |
| Academic/learning purpose             | Bubble Sort           |

---