
# Binary Number System

---

## 🔸 What is a Number System?

A **number system** is a way to represent numbers using a set of **symbols** or **digits**.
Just like we use 0-9 in the decimal system, other systems may use fewer or more symbols.

---

## 🔸 Types of Number Systems

| Number System | Base (Radix) | Digits Used  |
| ------------- | ------------ | ------------ |
| Binary        | 2            | 0, 1         |
| Octal         | 8            | 0 – 7        |
| Decimal       | 10           | 0 – 9        |
| Hexadecimal   | 16           | 0 – 9, A – F |

---

## What is Binary Number System?

The **Binary Number System** is a **base-2** system.
It uses **only two digits**:
👉 `0` and `1`

Each digit in a binary number is called a **bit** (short for "binary digit").

---

## Why is Binary Important in DSA?

* It is the **foundation of computer architecture**.
* Used in **bit manipulation** – important in **coding interviews** and **competitive programming**.
* Powers operations like **AND, OR, XOR, NOT, shifts**, etc.
* Helps understand how data is stored, accessed, and optimized.

---

## Examples of Binary Numbers:

* `1010` (binary) = `10` (decimal)
* `110` (binary) = `6` (decimal)

---

## How Binary Works: Positional Value

Each position in a binary number has a **power of 2**.

**Example**:
Binary: `1011`
From right to left:

```
1 × 2^0 = 1
1 × 2^1 = 2
0 × 2^2 = 0
1 × 2^3 = 8
------------------
Total     = 11 (decimal)
```

✅ So, `1011₂ = 11₁₀`

---

## Binary to Decimal Conversion

### ➤ Step-by-step Method:

1. Start from rightmost digit.
2. Multiply each digit by **2^position**.
3. Add all results.

**Example:** Convert `1101` to decimal

```
1 × 2^0 = 1
0 × 2^1 = 0
1 × 2^2 = 4
1 × 2^3 = 8
------------------
Total     = 13
```

✅ `1101₂ = 13₁₀`

---

## Decimal to Binary Conversion

### ➤ Using Division by 2:

1. Divide the number by 2.
2. Write down the **remainder**.
3. Repeat until quotient is 0.
4. Read remainders **from bottom to top**.

**Example**: Convert `13` to binary

```
13 ÷ 2 = 6  remainder = 1
6 ÷ 2  = 3  remainder = 0
3 ÷ 2  = 1  remainder = 1
1 ÷ 2  = 0  remainder = 1
---------------------------
Answer = 1101
```

✅ `13₁₀ = 1101₂`

---

## Common Binary Operations (DSA Use)

| Operation   | Symbol | Meaning                       |
| ----------- | ------ | ----------------------------- |
| AND         | `&`    | 1 if both bits are 1          |
| OR          | $\mid$        | 1 if at least one bit is 1 |
| XOR         | `^`    | 1 if bits are different       |
| NOT         | `~`    | Inverts all bits              |
| Left Shift  | `<<`   | Shifts bits to the left (×2)  |
| Right Shift | `>>`   | Shifts bits to the right (÷2) |

---

## Useful Binary Concepts in DSA

| Concept               | Use in DSA                                            |
| --------------------- | ----------------------------------------------------- |
| Bitmasking            | Used in subset generation, toggling bits, permissions |
| Binary Search         | Efficient searching in sorted arrays                  |
| Power of Two          | Often checked in DSA using binary                     |
| Hamming Weight        | Count of set bits (1s), used in problems              |
| Binary Representation | Optimization & low-level understanding                |

---

## Things to Remember

* Every binary number is made of only 0s and 1s.
* 8 bits = 1 byte.
* Binary numbers grow fast in length compared to decimal.
* In C++/Java/Python, integers are stored in **binary format** internally.

---

##   Practice Problems

1. Convert binary to decimal and vice versa.
2. Count number of 1s in a binary number.
3. Check if a number is a power of two.
4. Use bitwise operators to solve problems like:

   * Find the single non-repeating number
   * Set/Clear/Toggle a bit at a given position
   * Subset generation using bitmasking

---

## 📌 Summary

* Binary = Base 2 = Only 0 & 1
* Used by computers at the hardware level
* Crucial in DSA for **bit manipulation**, **performance**, and **logical problems**
* Mastering binary helps crack many **interview questions** and boosts your low-level thinking.

---