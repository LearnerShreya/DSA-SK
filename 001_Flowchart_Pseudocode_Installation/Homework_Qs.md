
# Homework Questions

a. Calculate "Simple Interest" from Principal (P), Rate (R) & Time (T).
b. Calculate Max of 2 numbers.
c. Calculate Factorial of a number N.
d. Given a person's age, find if they should get a driving license or not.

---

## 🔹 a. Simple Interest

📁 `Homework_Simple_Interest.md`
**Formula**: SI = (P × R × T) / 100

### ✅ Pseudocode:

```
START
  READ P, R, T
  SI ← (P × R × T) / 100
  PRINT SI
END
```

### ✅ Flowchart:

```
[Oval]            Start
   ↓
[Parallelogram]   Input P, R, T
   ↓
[Rectangle]       SI = (P × R × T) / 100
   ↓
[Parallelogram]   Output SI
   ↓
[Oval]            End
```

---

## 🔹 b. Max of 2 Numbers

📁 `Homework_Max_of_2.md`

### ✅ Pseudocode:

```
START
  READ A, B
  IF A > B THEN
    PRINT A
  ELSE
    PRINT B
END
```

### ✅ Flowchart:

```
[Oval]            Start
   ↓
[Parallelogram]   Input A, B
   ↓
[Diamond]         Is A > B?
   ↓Yes                ↓No
[Parallelogram]     [Parallelogram]
  Output A             Output B
         ↓                   ↓
        └────────────→───────┘
              ↓
           [Oval] End
```

---

## 🔹 c. Factorial of a Number

📁 `Homework_Factorial.md`

### ✅ Pseudocode:

```
START
  READ N
  fact ← 1
  i ← 1
  WHILE i ≤ N DO
    fact ← fact × i
    i ← i + 1
  END WHILE
  PRINT fact
END
```

### ✅ Flowchart:

```
[Oval]            Start
   ↓
[Parallelogram]   Input N
   ↓
[Rectangle]       fact = 1, i = 1
   ↓
[Diamond]         Is i ≤ N?
   ↓Yes                ↓No
[Rectangle]        [Parallelogram]
 fact = fact × i     Output fact
 i = i + 1                ↓
   ↓                   [Oval]
   └────→ Back to condition
```

---

## 🔹 d. Driving License Eligibility

📁 `Homework_Driving_Eligibility.md`

### ✅ Pseudocode:

```
START
  READ age
  IF age ≥ 18 THEN
    PRINT "Eligible for License"
  ELSE
    PRINT "Not Eligible"
END
```

### ✅ Flowchart:

```
[Oval]            Start
   ↓
[Parallelogram]   Input age
   ↓
[Diamond]         Is age ≥ 18?
   ↓Yes                ↓No
[Parallelogram]     [Parallelogram]
  Output "Eligible"    Output "Not Eligible"
         ↓                   ↓
        └────────────→───────┘
              ↓
           [Oval] End
```

---