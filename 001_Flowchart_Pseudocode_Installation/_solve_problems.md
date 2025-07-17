
# Problem-Solving Steps

(Super simple and powerful — follow this every time.)

---

### Summary: Your 4-Step Formula

| Step            | What to Do                                     |
| --------------- | ---------------------------------------------- |
| 1. Understand   | Read, rephrase, find key requirements          |
| 2. Input/Output | Identify data format and expectations          |
| 3. Solution     | Break into steps or pseudocode (dry run logic) |
| 4. Code         | Write code, test, debug, optimize              |

---

## **1. Understand the Problem**

* **Read the full question** (don’t rush).
* Highlight/Note:

  * What is **given**?
  * What is the **expected output**?
  * Are there any **constraints** (size limits, time limits)?
* Ask: Can I **rephrase the problem** in my own words?
* Think: What are the **edge cases**?

> Example:
> Problem: "Find the largest number in an array."
> → You must return the maximum value from the list of numbers.

---

## **2. Identify Input and Output**

Write this clearly in your notebook before coding.

* **Input**: What is the format of the input? (Integer, String, List?)
* **Output**: What should the output be? (A number, string, boolean?)

> Example:
> Input: `[4, 9, 1, 7]`
> Output: `9`

---

## **3. Think of the Solution (Logic Building)**

This is the **core thinking part**:

* Break the problem into **simple steps**.
* Can you solve it manually for 1–2 examples?
* Write logic in **plain English** or **pseudocode**:

  * Loops?
  * Conditions?
  * Any formula or pattern?
* Think about:

  * Can I do this in **one pass**?
  * What **data structure** fits best?

> Example Pseudocode for Max in Array:
>
> ```
> START  
> Set max = first element  
> Loop through the array:  
>   If current > max, update max  
> Return max  
> END  
> ```

---

## **4. Code the Logic**

Now convert the logic into actual code in your preferred language.

* Start simple, make it work first
* Use comments to keep logic clear
* Then test with different inputs:

  * Normal case
  * Edge case
  * Empty input or single value
* Finally, **optimize** (if needed)

> Example in Python:

```python
def find_max(arr):
    if not arr:
        return None
    max_val = arr[0]
    for num in arr:
        if num > max_val:
            max_val = num
    return max_val
```

---
---

# How to Solve Problems (Step-by-Step)

---

### Bonus: Use This Template to Solve Any Coding Problem

```
1. Understand the problem.
2. Think of examples.
3. Break down into steps.
4. Choose right data structure.
5. Write pseudocode.
6. Code the logic.
7. Test with multiple cases.
8. Optimize if needed.
```

---

## 1. **Understand the Problem Clearly**

* Read the problem **slowly and carefully**
* Identify **what is given** and **what is asked**
* Write down sample **input and output**
* Clarify:

  * Are inputs integers, strings, arrays, etc.?
  * Are there **edge cases** like empty input, large input, duplicates, etc.?

> 📌 Tip: Don’t rush to code without understanding. Misreading = Wasted effort.

---

## 2. **Think of Examples Yourself**

Before jumping into logic:

* Try at least **2–3 sample test cases**
* Manually calculate expected output

This builds your **intuition**.

---

## 3. **Break the Problem into Small Steps**

Ask:

* Can I break this into **sub-tasks**?
* Is it similar to a **known pattern** (loop, condition, recursion, etc.)?
* Can I use:

  * A loop?
  * A condition?
  * A function?
  * A data structure (array, set, map, etc.)?

Write your logic in **pseudocode** or simple steps.

---

## 4. **Choose the Right Data Structure**

This is crucial:

* Arrays → if you need a simple list of items
* HashMaps → for frequency/count/pairs
* Sets → to remove duplicates
* Stack → for "last in first out"
* Queue → for "first in first out"
* Tree/Graph → for hierarchy or connections

> Use what fits your logic — don’t memorize, **understand** when and why.

---

## 5. **Write Pseudocode or Dry Run First**

Do not code blindly.

* Write a **step-by-step plan** in plain language or comments
* Try a **dry run** on paper with sample input

This reduces errors drastically.

---

## 6. **Code Slowly and Clearly**

Once logic is ready:

* Write clean code
* Use meaningful variable names
* Don’t skip indentation and comments

> Don't aim for a perfect solution in the first attempt — just make it work.

---

## 7. **Test with Edge Cases**

Always test your solution with:

* Empty input
* Minimum/Maximum values
* Duplicates
* Negative numbers (if applicable)
* Very large input size

This shows how **strong** your solution is.

---

## 8. **Optimize (if needed)**

After your basic solution works:

* Check **time complexity** and **space complexity**
* Can you improve from O(n²) → O(n log n) or O(n)?
* Try to use better data structures or logic (sorting, binary search, hashmap, etc.)

---

## 9. **Learn from Every Mistake**

When a solution fails:

* Don’t get frustrated
* Go step-by-step and **debug**
* Ask: What did I assume wrong?

Write what you learned in your notebook.

---

## 10. **Practice Daily**

Problem-solving is like exercise:

* Start with **easy problems** and build confidence
* Then move to **medium and hard**
* Platforms: LeetCode, GFG, Codeforces, CodeChef

Follow a topic-wise plan:

* Arrays → Strings → Hashing → Recursion → LinkedList → Stack → Queue → Trees → Graphs → DP

---

## Your Goal:

> Focus not on **how fast** you solve, but **how deep** you understand.

---
