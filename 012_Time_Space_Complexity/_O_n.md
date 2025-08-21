## **O(n) — Linear Time Examples**

> Execution time grows **directly proportional** to input size `n`.
> If `n` doubles → runtime roughly doubles.

---

### **1. Calculating n! (Factorial)**

```cpp
int fact = 1;
for (int i = 1; i <= n; i++) {
    fact *= i;
}
```

* **Reason:** Loop runs `n` times → time ∝ `n`.
  **Complexity:** **O(n)**

---

### **2. Kadane’s Algorithm (Maximum Subarray Sum)**

```cpp
int currSum = 0, ans = INT_MIN;
for (int i = 0; i < n; i++) {
    currSum += arr[i];
    ans = max(currSum, ans);
    currSum = (currSum < 0) ? 0 : currSum;
}
```

* **Reason:** Single pass over array → `n` iterations.
  **Complexity:** **O(n)**

---

### **3. Nth Fibonacci (Dynamic Programming)**

```cpp
vector<long long> dp(n + 1);
dp[0] = 0;
dp[1] = 1;
for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
}
```

* **Reason:** Single loop up to `n`, each step = constant time.
  **Complexity:** **O(n)**

---

### **4. O(n × k) Variant (Multiple Passes)**

> Sometimes algorithms run a fixed number of passes (`k`) over `n` elements.
> Example — Sliding Window with fixed width `k`:

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
        // constant-time operation
    }
}
```

* If **k** is small and constant → effectively **O(n)**.
* If **k** grows with `n` → complexity changes.

---

💡 **Key Identifiers for O(n)**:

* Single loop over data.
* Processing each element once.
* No nested loop dependent on `n`.

---