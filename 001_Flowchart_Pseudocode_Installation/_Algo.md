

# Algorithm

---

## What is an Algorithm?

An **algorithm** is a **finite sequence of well-defined steps or instructions** to solve a problem or perform a task.

It is **language-independent**, focuses on **logic**, and acts like a **blueprint** for any program.
Just like a recipe in cooking — clearly defined steps, executed in order, to get a desired output.

---

## Characteristics of a Good Algorithm

| Characteristic    | Description                                                             |
| ----------------- | ----------------------------------------------------------------------- |
| **Input**         | Takes zero or more inputs                                               |
| **Output**        | Produces at least one output                                            |
| **Definiteness**  | All instructions are unambiguous and clearly defined                    |
| **Finiteness**    | Must complete after a finite number of steps                            |
| **Effectiveness** | Each operation must be simple enough to be done using basic computation |
| **Generality**    | Should work for a wide set of input values, not just one case           |

---

## Why Algorithms are Important

1. **Core of Problem-Solving** – Every software solution begins with logic
2. **Language Independent** – Algorithms define *what* to do, not *how*
3. **Optimizes Performance** – Reduces time and memory usage
4. **Interview Essential** – Major part of tech interviews (FAANG, Product-Based Companies)
5. **Applicable Everywhere** – From searching, sorting, routing, compression, AI, ML, etc.

---

## Algorithm vs Program

| Feature    | Algorithm                               | Program                                     |
| ---------- | --------------------------------------- | ------------------------------------------- |
| Definition | Logical steps to solve a problem        | Implementation of algorithm in a language   |
| Language   | Language-independent                    | Language-specific (Python, C++, Java, etc.) |
| Purpose    | Focuses on logic and strategy           | Focuses on execution                        |
| Output     | Logical solution                        | Actual result via code                      |
| Format     | Written in pseudocode or plain language | Written in source code                      |

---

## How to Write an Algorithm

Algorithms are written in **plain English** or **pseudocode**, not in any programming language.

### Example: Algorithm to Add Two Numbers

```
Step 1: Start  
Step 2: Read two numbers, num1 and num2  
Step 3: sum ← num1 + num2  
Step 4: Print sum  
Step 5: Stop
```

---

## Types of Algorithms

| Type                    | Description                                                                     |
| ----------------------- | ------------------------------------------------------------------------------- |
| **Brute Force**         | Tries all possible combinations to find a solution                              |
| **Greedy**              | Makes the locally optimal choice at each step                                   |
| **Divide and Conquer**  | Breaks the problem into smaller sub-problems, solves recursively, then combines |
| **Dynamic Programming** | Stores results of subproblems to avoid recomputation                            |
| **Backtracking**        | Tries all paths, backtracks if the solution is not valid                        |
| **Recursion**           | Solves a problem by solving smaller instances of itself                         |
| **Bit Manipulation**    | Uses bitwise operations for optimized solutions                                 |
| **Graph Algorithms**    | BFS, DFS, Dijkstra, Kruskal, Prim, etc.                                         |
| **String Algorithms**   | KMP, Rabin-Karp, Z-algorithm, etc.                                              |

---

## Example: Algorithm to Find Maximum of Three Numbers

```
Step 1: Start  
Step 2: Read a, b, c  
Step 3: If a > b and a > c  
            max ← a  
        Else if b > c  
            max ← b  
        Else  
            max ← c  
Step 4: Print max  
Step 5: Stop
```

---

## Time and Space Complexity (Intro)

* **Time Complexity** – How much time an algorithm takes as input grows
  Example: O(n), O(log n), O(n²), etc.

* **Space Complexity** – How much memory an algorithm uses during execution
  Example: O(1), O(n), etc.

> These concepts help choose the best algorithm for a task.

---

## Algorithm Format Template

```
Step 1: Start  
Step 2: Input / Initialize variables  
Step 3: Process / Loop / Condition  
Step 4: Output Result  
Step 5: Stop
```

---

## Conclusion

An algorithm is the **logical brain** behind every program.
Understanding algorithms is the **first step** to mastering DSA.

---
