- https://www.youtube.com/watch?v=K2BEKh-EqqA

# 🔷 SORTING ALGORITHMS — PART 1

## ⭐ Bubble Sort + Selection Sort

---

## 1️⃣ Bubble Sort

### ✔ Definition

Bubble Sort is a simple sorting algorithm that repeatedly compares **adjacent** elements of an array and **swaps** them if they are in the wrong order.
This process continues until the array becomes completely sorted.

### ✔ Real-Life Intuition

Imagine bubbles rising to the top in water — the larger ones reach the surface after several pushes.
Similarly, **big elements “bubble” to the end** of the array after each pass.

### ✔ Working Principle

* Compare adjacent pairs
* Swap if they are out of order
* After each pass, the **largest element** reaches its correct position at the end

---

### ✔ Dry Run (Example B — Table Format)

Array = **[5, 2, 8, 3]**

| Pass | Comparison        | Swap? | Array after step |
| ---- | ----------------- | ----- | ---------------- |
| 1    | 5 vs 2            | Yes   | [2, 5, 8, 3]     |
| 1    | 5 vs 8            | No    | [2, 5, 8, 3]     |
| 1    | 8 vs 3            | Yes   | [2, 5, 3, 8]     |
| 2    | 2 vs 5            | No    | [2, 5, 3, 8]     |
| 2    | 5 vs 3            | Yes   | [2, 3, 5, 8]     |
| 2    | 5 vs 8            | No    | [2, 3, 5, 8]     |
| 3    | No swaps → sorted | —     | [2, 3, 5, 8]     |

---

### ✔ Pseudocode

```
BUBBLE-SORT(arr):
    n ← length(arr)
    for i from 0 to n-1:
        swapped ← false
        for j from 0 to n-i-2:
            if arr[j] > arr[j+1]:
                swap arr[j] and arr[j+1]
                swapped ← true
        if swapped == false:
            break
```

---

### ✔ C++ Code

```cpp
void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
```

---

### ✔ Python Code

```python
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break
```

---

### ✔ Time & Space Complexity

| Case                  | Time                                          |
| --------------------- | --------------------------------------------- |
| Best (already sorted) | **O(n)** (optimized version detects no swaps) |
| Average               | **O(n²)**                                     |
| Worst                 | **O(n²)**                                     |
| Space                 | **O(1)**                                      |

### ✔ Stability & Other Properties

| Property | Value           |
| -------- | --------------- |
| Stable   | Yes             |
| In-place | Yes             |
| Adaptive | Yes (optimized) |

### ✔ When to Use

* Teaching / learning basics
* Very small datasets
* When array is **almost sorted**

### ✔ When to Avoid

* Large data
* Performance-sensitive applications

### ❗ Interview Trap

Students forget to implement **swap check (optimized version)** which reduces worst case to best case **O(n)**.

---

---

## 2️⃣ Selection Sort

### ✔ Definition

Selection Sort repeatedly picks the **smallest (or largest)** element from the **unsorted part** of the array and places it at the **beginning** of the sorted part.

### ✔ Real-Life Intuition

Like selecting the **lowest-priced item first** from a shopping list and placing it in order.

### ✔ Working Principle

* Partition array into **sorted** and **unsorted** region
* Find **minimum in unsorted region**
* Swap it to the **front of unsorted region**
* Repeat

---

### ✔ Dry Run (Example B — Table Format)

Array = **[5, 2, 8, 3]**

| Pass | Minimum selected | Swap with | Array after step |
| ---- | ---------------- | --------- | ---------------- |
| 1    | 2                | 5         | [2, 5, 8, 3]     |
| 2    | 3                | 5         | [2, 3, 8, 5]     |
| 3    | 5                | 8         | [2, 3, 5, 8]     |
| 4    | Already sorted   | —         | [2, 3, 5, 8]     |

---

### ✔ Pseudocode

```
SELECTION-SORT(arr):
    n ← length(arr)
    for i from 0 to n-1:
        minIndex ← i
        for j from i+1 to n-1:
            if arr[j] < arr[minIndex]:
                minIndex ← j
        swap arr[i] and arr[minIndex]
```

---

### ✔ C++ Code

```cpp
void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
```

---

### ✔ Python Code

```python
def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
```

---

### ✔ Time & Space Complexity

| Case    | Time      |
| ------- | --------- |
| Best    | **O(n²)** |
| Average | **O(n²)** |
| Worst   | **O(n²)** |
| Space   | **O(1)**  |

### ✔ Stability & Other Properties

| Property | Value                                               |
| -------- | --------------------------------------------------- |
| Stable   | ❌ No (because swapping changes order of equal keys) |
| In-place | Yes                                                 |
| Adaptive | No                                                  |

### ✔ When to Use

* When **memory is extremely limited**
* When number of **swaps should be minimal**
  (Selection Sort performs only **n–1 swaps**, unlike Bubble/Insertion)

### ✔ When to Avoid

* Large datasets
* Time-sensitive systems

### ❗ Interview Trap

Candidates say it's stable — but **it is not stable** in its normal version.

---

### 🔹 Bubble vs Selection — Quick Comparison

| Feature     | Bubble    | Selection |
| ----------- | --------- | --------- |
| Comparisons | High      | High      |
| Swaps       | Very high | Very low  |
| Best Case   | O(n)      | O(n²)     |
| Stability   | ✔         | ❌         |
| Adaptive    | ✔         | ❌         |

---

---

# 🔷 SORTING ALGORITHMS — PART 2

## ⭐ Insertion Sort

---

## 1️⃣ Definition

Insertion Sort builds the final sorted array **one element at a time** by inserting each element into its correct position among the previously sorted elements.

---

## 2️⃣ Real-Life Intuition

Very similar to sorting playing cards in your hand:

* Pick the next card
* Compare it with previous cards
* Shift cards until you find the correct spot
* Insert the card in the right position

---

## 3️⃣ Working Principle

* First element is considered sorted
* Pick the next element (called **key**)
* Compare it with elements in the **sorted region**
* Shift larger elements one step right
* Insert the key at the correct position

---

## 4️⃣ Dry Run (Example B — Table Format)

Array = **[5, 2, 8, 3]**

| Pass | Key Selected | Shifting             | Array After Step |
| ---- | ------------ | -------------------- | ---------------- |
| 1    | 2            | 5 → right            | [2, 5, 8, 3]     |
| 2    | 8            | No shift             | [2, 5, 8, 3]     |
| 3    | 3            | 8 → right, 5 → right | [2, 3, 5, 8]     |

---

### Explanation of Pass 3 (important for interviews)

```
Key = 3
Compare with 8 → shift
Compare with 5 → shift
Insert before 5
```

---

## 5️⃣ Pseudocode

```
INSERTION-SORT(arr):
    n ← length(arr)
    for i from 1 to n-1:
        key ← arr[i]
        j ← i - 1
        while j ≥ 0 and arr[j] > key:
            arr[j + 1] ← arr[j]
            j ← j - 1
        arr[j + 1] ← key
```

---

## 6️⃣ C++ Code

```cpp
void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```

---

## 7️⃣ Python Code

```python
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
```

---

## 8️⃣ Time & Space Complexity

| Case                 | Time      |
| -------------------- | --------- |
| Best (nearly sorted) | **O(n)**  |
| Average              | **O(n²)** |
| Worst                | **O(n²)** |
| Space                | **O(1)**  |

---

## 9️⃣ Stability & Other Properties

| Property                   | Value                                              |
| -------------------------- | -------------------------------------------------- |
| Stable                     | ✔ Yes                                              |
| In-place                   | ✔ Yes                                              |
| Adaptive                   | ✔ Yes (performance improves on nearly sorted data) |
| Suitable for linked lists? | ✔ Very good                                        |

---

## 🔟 When to Use

* Small datasets
* Nearly sorted datasets
* Realtime insertion (e.g., online sorting)
* When stability is required

## 🚫 When to Avoid

* Large datasets (n > 10⁴)
* Performance-critical applications

---

## 🔥 Interview Traps

| Mistake                            | Correct Concept                                     |
| ---------------------------------- | --------------------------------------------------- |
| Students swap elements             | Insertion Sort **shifts**, does not swap repeatedly |
| They say complexity always O(n²)   | Best case is **O(n)** for nearly sorted             |
| They think it’s slower than Bubble | It is **faster than Bubble** in practice            |

---

### Small Comparison of Bubble, Selection & Insertion

| Feature       | Bubble    | Selection | Insertion                               |
| ------------- | --------- | --------- | --------------------------------------- |
| Best Case     | O(n)      | O(n²)     | ⭐ O(n)                                  |
| Swaps         | Very high | Very low  | Moderate                                |
| Stability     | ✔         | ❌         | ✔                                       |
| Adaptive      | ✔         | ❌         | ✔                                       |
| Practical use | Low       | Low       | ⭐ High (for small / nearly sorted data) |

---

---

# 🔷 SORTING ALGORITHMS — PART 3

## ⭐ Merge Sort + Quick Sort + Final Comparison Table

---

## 1️⃣ Merge Sort

### ✔ Definition

Merge Sort is a **divide and conquer** sorting algorithm that:

1. Divides the array into two halves
2. Recursively sorts both halves
3. Merges the two sorted halves into one sorted array

---

### ✔ Real-Life Intuition

Imagine sorting two already sorted piles of papers by **merging them** into one larger sorted pile.

---

### ✔ Working Principle

* Split → until subarrays become size 1
* Merge → compare elements from two halves and place smaller first
* Repeat until complete array is sorted

---

### ✔ Dry Run (Example B — Table Format)

Array = **[5, 2, 8, 3]**

| Step | Action      | Result              |
| ---- | ----------- | ------------------- |
| 1    | Divide      | [5, 2] and [8, 3]   |
| 2    | Divide      | [5] [2] and [8] [3] |
| 3    | Merge       | [2, 5] and [3, 8]   |
| 4    | Final Merge | [2, 3, 5, 8]        |

---

### ✔ Pseudocode

```
MERGE-SORT(arr, l, r):
    if l >= r:
        return
    mid ← (l + r) // 2
    MERGE-SORT(arr, l, mid)
    MERGE-SORT(arr, mid + 1, r)
    MERGE(arr, l, mid, r)
```

---

### ✔ C++ Code

```cpp
void merge(vector<int> &arr, int l, int m, int r) {
    vector<int> temp;
    int i = l, j = m + 1;
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while (i <= m) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);
    for (int k = 0; k < temp.size(); k++) arr[l + k] = temp[k];
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}
```

---

### ✔ Python Code

```python
def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    return merge(left, right)

def merge(left, right):
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

### ✔ Time & Space Complexity

| Case    | Time           |
| ------- | -------------- |
| Best    | **O(n log n)** |
| Average | **O(n log n)** |
| Worst   | **O(n log n)** |
| Space   | **O(n)**       |

---

### ✔ Stability & Other Properties

| Property        | Value                    |
| --------------- | ------------------------ |
| Stable          | ✔ Yes                    |
| In-place        | ❌ No (needs extra array) |
| Parallelizable  | ✔ Yes                    |
| Recursion depth | log n                    |

---

### ✔ When to Use

* Large datasets
* Stability required
* Linked list sorting

### ✔ When to Avoid

* Very memory-limited environments
* Small data where insertion sort is better

---

---

## 2️⃣ Quick Sort

### ✔ Definition

Quick Sort is a **divide and conquer** algorithm that:

1. Selects a **pivot**
2. Reorders elements so:

   * smaller → before pivot
   * greater → after pivot
3. Recursively sorts the left and right partitions

---

### ✔ Real-Life Intuition

Arranging students around a height reference:

* Shorter move to the left
* Taller move to the right

---

### ✔ Working Principle

* Partition based on pivot
* Place pivot at its correct location
* Recursively sort partitions

---

### ✔ Dry Run (Table Format)

Array = **[5, 2, 8, 3]**
Choose pivot = **5**

| Step      | Action                                 | Result       |
| --------- | -------------------------------------- | ------------ |
| Partition | Move smaller than 5 left, larger right | [3, 2, 5, 8] |
| Recursion | Left part [3,2]                        | [2, 3]       |
| Recursion | Right part [8]                         | [8]          |
| Final     | Sorted                                 | [2, 3, 5, 8] |

---

### ✔ Pseudocode

```
QUICK-SORT(arr, low, high):
    if low < high:
        p ← PARTITION(arr, low, high)
        QUICK-SORT(arr, low, p - 1)
        QUICK-SORT(arr, p + 1, high)
```

Partition:

```
PARTITION(arr, low, high):
    pivot ← arr[high]
    i ← low - 1
    for j from low to high - 1:
        if arr[j] < pivot:
            i ← i + 1
            swap arr[i] and arr[j]
    swap arr[i + 1] and arr[high]
    return i + 1
```

---

### ✔ C++ Code

```cpp
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```

---

### ✔ Python Code

```python
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[-1]
    left = [x for x in arr[:-1] if x < pivot]
    right = [x for x in arr[:-1] if x >= pivot]
    return quick_sort(left) + [pivot] + quick_sort(right)
```

---

### ✔ Time & Space Complexity

| Case              | Time           |
| ----------------- | -------------- |
| Best              | **O(n log n)** |
| Average           | **O(n log n)** |
| Worst (bad pivot) | **O(n²)**      |
| Space (recursive) | **O(log n)**   |

---

### ✔ Stability & Properties

| Property            | Value                               |
| ------------------- | ----------------------------------- |
| Stable              | ❌ No                                |
| In-place            | ✔ Yes (for partition-based version) |
| Cache optimized     | ✔ Very good                         |
| Fastest in practice | ✔ Usually                           |

---

### ✔ When to Use

* Large datasets
* Memory limited (in-place)
* Competitive programming

### ✔ When to Avoid

* Worst-case pivot risk (already sorted data)
* Stability needed

### 🔹 Interview Tip

Always mention that **randomized pivot or median-of-three** avoids worst case.

---

# ⭐ FINAL COMPARISON TABLE (All 5 Sorting Algorithms)

| Algorithm      | Best       | Average     | Worst      | Space    | Stable | In-place |
| -------------- | ---------- | ----------- | ---------- | -------- | ------ | -------- |
| Bubble Sort    | O(n)       | O(n²)       | O(n²)      | O(1)     | ✔      | ✔        |
| Selection Sort | O(n²)      | O(n²)       | O(n²)      | O(1)     | ❌      | ✔        |
| Insertion Sort | ⭐O(n)      | O(n²)       | O(n²)      | O(1)     | ✔      | ✔        |
| Merge Sort     | O(n log n) | O(n log n)  | O(n log n) | ❌ O(n)   | ✔      | ❌        |
| Quick Sort     | O(n log n) | ⭐O(n log n) | ❌O(n²)     | O(log n) | ❌      | ✔        |

---

## 🌟 BEST PRACTICAL RULE

| Dataset situation                | Best algorithm     |
| -------------------------------- | ------------------ |
| Small or nearly sorted           | **Insertion Sort** |
| Large dataset + memory available | **Merge Sort**     |
| Large dataset + memory limited   | **Quick Sort**     |
| Need minimum swaps               | **Selection Sort** |
| Teaching beginners               | **Bubble Sort**    |

---