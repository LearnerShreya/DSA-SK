

# PracticeQs

1. Practice Qs1: Area of a Square 
2. Practice Qs2 Min of 2 numbers 
3. Practice Qs3 Is number Odd or Even 
4. Practice Qs4 Sum of numbers from 1 to N 
5. Practice Qs5 Is number Prime or not

---


## Practice Qs 1: Area of a Square

📁 **File**: `PracticeQs1_Area_of_Square.md`
Formula: `Area = side × side`

### Pseudocode:

```
START
  READ side
  area ← side × side
  PRINT area
END
```

### Flowchart:

```
[Oval]            Start
   ↓
[Parallelogram]   Input side
   ↓
[Rectangle]       area = side × side
   ↓
[Parallelogram]   Output area
   ↓
[Oval]            End
```

---

## Practice Qs 2: Min of Two Numbers

📁 **File**: `PracticeQs2_Min_of_Two_Numbers.md`

### Pseudocode:

```
START
  READ A, B
  IF A < B THEN
    PRINT A
  ELSE
    PRINT B
END
```

### Flowchart:

```
[Oval]            Start
   ↓
[Parallelogram]   Input A, B
   ↓
[Diamond]         Is A < B?
   ↓Yes                ↓No
[Parallelogram]     [Parallelogram]
  Output A             Output B
      ↓                   ↓
     └────────────→───────┘
              ↓
           [Oval] End
```

---

## Practice Qs 3: Odd or Even

📁 **File**: `PracticeQs3_Odd_or_Even.md`

### Pseudocode:

```
START
  READ num
  IF num % 2 = 0 THEN
    PRINT "Even"
  ELSE
    PRINT "Odd"
END
```

### Flowchart:

```
[Oval]            Start
   ↓
[Parallelogram]   Input num
   ↓
[Diamond]         Is num % 2 == 0?
   ↓Yes                ↓No
[Parallelogram]     [Parallelogram]
 Output "Even"       Output "Odd"
      ↓                   ↓
     └────────────→───────┘
              ↓
           [Oval] End
```

---

## Practice Qs 4: Sum of 1 to N

📁 **File**: `PracticeQs4_Sum_1_to_N.md`

### Pseudocode:

```
START
  READ N
  sum ← 0
  i ← 1
  WHILE i ≤ N DO
    sum ← sum + i
    i ← i + 1
  END WHILE
  PRINT sum
END
```

### Flowchart:

```
[Oval]            Start
   ↓
[Parallelogram]   Input N
   ↓
[Rectangle]       sum = 0, i = 1
   ↓
[Diamond]         Is i ≤ N?
   ↓Yes                ↓No
[Rectangle]        [Parallelogram]
 sum = sum + i       Output sum
 i = i + 1                 ↓
   ↓                    [Oval]
   └────→ back to loop    End
```

---

## Practice Qs 5: Is Number Prime

📁 **File**: `PracticeQs5_Is_Prime.md`

### Pseudocode:

```
START
  READ num
  IF num ≤ 1 THEN
    PRINT "Not Prime"
  ELSE
    i ← 2
    flag ← 0
    WHILE i < num DO
      IF num MOD i = 0 THEN
        flag ← 1
        BREAK
      END IF
      i ← i + 1
    END WHILE
    IF flag = 0 THEN
      PRINT "Prime"
    ELSE
      PRINT "Not Prime"
END
```

### Flowchart:

```
[Oval]            Start
   ↓
[Parallelogram]   Input num
   ↓
[Diamond]         Is num ≤ 1?
   ↓Yes               ↓No
[Parallelogram]   [Rectangle]
Output "Not        i = 2, flag = 0
Prime"                  ↓
                     [Diamond] Is i < num?
                       ↓Yes          ↓No
                 [Diamond]   →   [Decision] flag = 0?
             Is num % i == 0?      ↓Yes         ↓No
               ↓Yes     ↓No   [Parallelogram] [Parallelogram]
         [Rectangle] [Rectangle]   Output       Output
         flag = 1     i = i + 1     "Prime"     "Not Prime"
         BREAK           ↓              ↓           ↓
           ↓←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←
                     Back to loop
                             ↓
                         [Oval] End
```

---