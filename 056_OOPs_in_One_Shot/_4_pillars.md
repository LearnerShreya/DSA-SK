# **4 Pillars of OOPs (Object-Oriented Programming):**

---

### **1. Encapsulation**

Encapsulation means **binding data (variables) and methods (functions) together into a single unit (class)** and **restricting direct access to data** for safety.

**Simple meaning:** Keep data safe inside a container and allow access only through controlled methods.

**Why it matters:**

* Protects data
* Prevents accidental modification
* Makes code secure and organized

**Example:**
A class with private variables and public getter/setter functions.

---

### **2. Abstraction**

Abstraction means **showing only essential features to the user and hiding the complex internal details**.

**Simple meaning:** Tell *what* something does, not *how* it does it.

**Why it matters:**

* Reduces complexity
* Improves readability
* Makes programming easier

**Example:**
We drive a car (accelerator, brake) without knowing internal engine mechanics.

---

### **3. Inheritance**

Inheritance means **acquiring properties and methods of one class (parent/base) into another class (child/derived)**.

**Simple meaning:** Child class gets features of parent class.

**Why it matters:**

* Reusability of code
* Reduces redundancy
* Helps in hierarchical classification

**Example:**
`Dog`, `Cat`, `Horse` inherit from `Animal`.

---

### **4. Polymorphism**

Polymorphism means **one name behaving differently based on the situation**.

**Simple meaning:** Same function works in different ways.

**Why it matters:**

* Improves flexibility
* Enables method overriding and method overloading

**Example:**
A function `area()` works differently for circle, square, rectangle.

---

### **Quick Summary Table**

| Pillar        | Simple Meaning                | Key Benefits                |
| ------------- | ----------------------------- | --------------------------- |
| Encapsulation | Data hiding                   | Security, organization      |
| Abstraction   | Show only necessary info      | Less complexity, easier use |
| Inheritance   | Reuse parent class features   | Reusability, less code      |
| Polymorphism  | Same name, different behavior | Flexibility, clean code     |

---

### **Real-world example combining all pillars**

Think of a **bank ATM system**:

| Pillar        | ATM Example                                                                 |
| ------------- | --------------------------------------------------------------------------- |
| Encapsulation | User PIN and balance are hidden; only accessed via functions                |
| Abstraction   | ATM shows options (withdraw, check balance) without revealing backend logic |
| Inheritance   | Different ATM machines inherit features from a standard ATM model           |
| Polymorphism  | Withdraw function works differently for savings, current, salary accounts   |

---