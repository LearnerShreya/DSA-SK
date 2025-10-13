# Bubble Selection Insertion Sort

---

## 🔸 **1. Bubble Sort**

### 🔹 Definition

Bubble Sort is the simplest sorting algorithm that repeatedly steps through the array, compares adjacent elements, and swaps them if they are in the wrong order.
The largest element “bubbles up” to the end of the array in each pass.

### 🔹 Algorithm

1. Start from the first element.
2. Compare the current element with the next one.
3. If the current element is greater, swap them.
4. After one full pass, the largest element is at the end.
5. Repeat for all remaining elements (excluding the last sorted part).

### 🔹 Example

**Array:** [5, 1, 4, 2, 3]

* Pass 1 → [1, 4, 2, 3, 5]
* Pass 2 → [1, 2, 3, 4, 5]
* Sorted!

### 🔹 Code

```cpp
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Optimization: stop if array already sorted
    }
}
```

### 🔹 Time Complexity

| Case    | Time Complexity |
| ------- | --------------- |
| Best    | O(n)            |
| Average | O(n²)           |
| Worst   | O(n²)           |
| Space   | O(1)            |

### 🔹 Key Points

* Works by **swapping adjacent elements**.
* **Stable sort** (doesn’t change order of equal elements).
* Not suitable for large data sets.

---

## 🔸 **2. Selection Sort**

### 🔹 Definition

Selection Sort divides the array into a **sorted** and **unsorted** part. It repeatedly selects the smallest (or largest) element from the unsorted part and swaps it with the first unsorted element.

### 🔹 Algorithm

1. Find the smallest element in the unsorted part.
2. Swap it with the element at the beginning of the unsorted part.
3. Move the boundary of sorted part one step forward.
4. Repeat until the array is sorted.

### 🔹 Example

**Array:** [4, 1, 5, 2, 3]

* Pass 1 → [1, 4, 5, 2, 3]
* Pass 2 → [1, 2, 5, 4, 3]
* Pass 3 → [1, 2, 3, 4, 5]
* Sorted!

### 🔹 Code

```cpp
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}
```

### 🔹 Time Complexity

| Case    | Time Complexity |
| ------- | --------------- |
| Best    | O(n²)           |
| Average | O(n²)           |
| Worst   | O(n²)           |
| Space   | O(1)            |

### 🔹 Key Points

* Works by **selecting the smallest element** each pass.
* **Not stable** (equal elements may change order).
* Simple but inefficient for large arrays.

---

## 🔸 **3. Insertion Sort**

### 🔹 Definition

Insertion Sort builds the sorted array one element at a time by inserting each new element into its correct position among the already sorted elements.

### 🔹 Algorithm

1. Assume the first element is sorted.
2. Take the next element and compare it with elements in the sorted part.
3. Shift all elements greater than the current element one position ahead.
4. Insert the current element in its correct position.
5. Repeat until all elements are sorted.

### 🔹 Example

**Array:** [4, 1, 5, 2, 3]

* Step 1: [1, 4, 5, 2, 3]
* Step 2: [1, 4, 5, 2, 3] → Insert 2 → [1, 2, 4, 5, 3]
* Step 3: [1, 2, 3, 4, 5]

### 🔹 Code

```cpp
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}
```

### 🔹 Time Complexity

| Case    | Time Complexity |
| ------- | --------------- |
| Best    | O(n)            |
| Average | O(n²)           |
| Worst   | O(n²)           |
| Space   | O(1)            |

### 🔹 Key Points

* Works by **inserting elements** into the sorted portion.
* **Stable sort.**
* Efficient for **small** or **nearly sorted arrays.**

---

## Summary Table

| Algorithm      | Best  | Average | Worst | Stable | In-place | Logic                   |
| -------------- | ----- | ------- | ----- | ------ | -------- | ----------------------- |
| Bubble Sort    | O(n)  | O(n²)   | O(n²) | ✅      | ✅        | Repeated swapping       |
| Selection Sort | O(n²) | O(n²)   | O(n²) | ❌      | ✅        | Selecting min each pass |
| Insertion Sort | O(n)  | O(n²)   | O(n²) | ✅      | ✅        | Shifting & inserting    |

---
---

## Dry Run

---

## **1. Bubble Sort Dry Run**

### Example:

**Input:** [5, 1, 4, 2, 3]
**Goal:** Sort in ascending order

### Step-by-step process:

| Pass | Comparison & Swap          | Result after pass                   |                        |
| ---- | -------------------------- | ----------------------------------- | ---------------------- |
| 1    | (5,1) → swap → [1,5,4,2,3] |                                     |                        |
|      | (5,4) → swap → [1,4,5,2,3] |                                     |                        |
|      | (5,2) → swap → [1,4,2,5,3] |                                     |                        |
|      | (5,3) → swap → [1,4,2,3,5] | ✅ Largest element (5) is at the end |                        |
| 2    | (1,4) → ok                 |                                     |                        |
|      | (4,2) → swap → [1,2,4,3,5] |                                     |                        |
|      | (4,3) → swap → [1,2,3,4,5] | ✅ 2nd largest (4) fixed             |                        |
| 3    | (1,2) ok, (2,3) ok         | [1,2,3,4,5]                         | ✅ Array already sorted |

**Final Sorted Array:** [1, 2, 3, 4, 5]

### 🔹 Key Points:

* In each pass, the **largest element bubbles up**.
* Number of passes = n - 1.
* Stops early if no swap occurs (optimized version).

---

## **2. Selection Sort Dry Run**

### Example:

**Input:** [4, 1, 5, 2, 3]

### Step-by-step process:

| Pass | Action                                     | Result after pass |
| ---- | ------------------------------------------ | ----------------- |
| 1    | Smallest = 1 → swap with 4                 | [1, 4, 5, 2, 3]   |
| 2    | From [4,5,2,3], smallest = 2 → swap with 4 | [1, 2, 5, 4, 3]   |
| 3    | From [5,4,3], smallest = 3 → swap with 5   | [1, 2, 3, 4, 5]   |
| 4    | From [4,5], already sorted                 | [1, 2, 3, 4, 5]   |

**Final Sorted Array:** [1, 2, 3, 4, 5]

### 🔹 Key Points:

* In each pass, **select the smallest element** from the unsorted part.
* Swap it with the **first unsorted index**.
* Takes same time even if already sorted.

---

## **3. Insertion Sort Dry Run**

### Example:

**Input:** [4, 1, 5, 2, 3]

### Step-by-step process:

| Step  | Current Element | Action                            | Result                 |             |
| ----- | --------------- | --------------------------------- | ---------------------- | ----------- |
| i = 1 | curr = 1        | Compare with 4 → shift 4 right    | [4,4,5,2,3] → insert 1 | [1,4,5,2,3] |
| i = 2 | curr = 5        | Compare with 4 → no shift         | [1,4,5,2,3]            |             |
| i = 3 | curr = 2        | Compare: 5>2 → shift, 4>2 → shift | [1,4,4,5,3] → insert 2 | [1,2,4,5,3] |
| i = 4 | curr = 3        | Compare: 5>3 → shift, 4>3 → shift | [1,2,4,4,5] → insert 3 | [1,2,3,4,5] |

**Final Sorted Array:** [1, 2, 3, 4, 5]

### 🔹 Key Points:

* **Builds sorted part gradually.**
* Works great when array is **almost sorted.**
* Elements are shifted, not swapped.

---

## Quick Comparison

| Sort Type      | Working                           | Stable | Best Case | Time Complexity |
| -------------- | --------------------------------- | ------ | --------- | --------------- |
| Bubble Sort    | Repeatedly swap adjacent elements | ✅      | O(n)      | O(n²)           |
| Selection Sort | Select min & place at front       | ❌      | O(n²)     | O(n²)           |
| Insertion Sort | Insert into sorted part           | ✅      | O(n)      | O(n²)           |

---