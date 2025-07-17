
# Data Structure

---

## What is a Data Structure?

A **data structure** is a **way of organizing and storing data** in a computer so that it can be accessed and modified efficiently.

It helps manage large volumes of data for efficient processing, searching, updating, and more.

---

## Characteristics of a Good Data Structure

| Characteristic         | Description                                                              |
| ---------------------- | ------------------------------------------------------------------------ |
| **Efficient Access**   | Enables quick and easy data retrieval (like using index or key)          |
| **Memory Utilization** | Makes optimal use of memory (minimizing wastage)                         |
| **Data Organization**  | Maintains a logical layout for the data (e.g., sequential, hierarchical) |
| **Data Manipulation**  | Supports operations like insertion, deletion, traversal, search, etc.    |
| **Flexibility**        | Should be adaptable to different kinds of problems                       |
| **Reusability**        | Can be reused across programs or applications                            |

---

## Why DSA is Important?

1. **Foundation of Programming** – Organizes data and solves problems effectively.
2. **Required for Placements** – Top companies test DSA in interviews.
3. **Efficient Coding** – Optimized, clean, and scalable solutions.
4. **Real-World Applications** – Used in OS, DBMS, AI, Web Development, etc.
5. **Improves Problem-Solving** – Boosts logic and algorithmic thinking.

---

## Main Classification of Data Structures

```
Data Structures
├── 1. Primitive
│   ├── int         → Integer
│   ├── float       → Decimal
│   ├── double      → High-precision float (not in Python)
│   ├── char        → Character (no char type in Python, uses strings)
│   ├── bool        → Boolean (True / False)
│   └── pointer     → Stores memory address (explicit in C/C++; implicit in Python)
│
└── 2. Non-Primitive
    ├── A. Linear
    │   ├── Static
    │   │   └── Array → Fixed-size (C, C++ arrays; Python uses list or array module)
    │   └── Dynamic
    │       ├── Vector → Resizable array (C++ STL `vector`, Python `list`)
    │       ├── Linked List
    │       │   ├── Singly Linked List
    │       │   ├── Doubly Linked List
    │       │   └── Circular Linked List
    │       ├── Stack → LIFO
    │       │   ├── Array-based (`list` in Python with `.append()` / `.pop()`)
    │       │   └── LinkedList-based (custom class)
    │       └── Queue → FIFO
    │           ├── Simple Queue
    │           ├── Circular Queue
    │           ├── Deque (Double-ended) → Python `collections.deque`
    │           └── Priority Queue (Min/Max) → Python `heapq`, `queue.PriorityQueue`
    │
    ├── B. Non-Linear
    │   ├── Tree
    │   │   ├── Binary Tree
    │   │   ├── Binary Search Tree (BST)
    │   │   ├── AVL Tree
    │   │   ├── Red-Black Tree
    │   │   ├── B Tree
    │   │   ├── B+ Tree
    │   │   ├── Heap → Python `heapq` (min heap by default)
    │   │   │   ├── Min Heap
    │   │   │   └── Max Heap (invert values for max-heap in Python)
    │   │   └── Trie → Implemented using dictionary or class
    │   └── Graph
    │       ├── Directed / Undirected
    │       ├── Weighted / Unweighted
    │       ├── Adjacency Matrix
    │       └── Adjacency List → Commonly implemented using `dict` or `defaultdict` in Python
    │
    └── C. Hash / Table / Map / Set
        ├── Hash Table → Key-value pairs using hash function (Python `dict`)
        ├── Map
        │   ├── Hash Map       → Python `dict`, C++ `unordered_map`
        │   ├── Tree Map       → Sorted map (Java), use `SortedDict` from `sortedcontainers` in Python
        │   ├── Unordered Map  → Fast lookup (C++ STL)
        │   └── Dictionary     → Python built-in key-value store
        └── Set
            ├── Hash Set       → Python built-in `set`
            ├── Tree Set       → Java `TreeSet`, use `SortedSet` in Python (`sortedcontainers`)
            ├── Unordered Set  → C++ STL
            └── Set            → Python built-in `set`
```

---

## Summary Table

| Category           | Structure                 | Notes                                                        |
| ------------------ | ------------------------- | ------------------------------------------------------------ |
| Primitive          | int, float, char, bool    | Basic raw types                                              |
|                    | pointer                   | Explicit in C/C++, implicit in Python                        |
| Linear – Static    | array                     | Python uses `array` module for fixed-type arrays             |
| Linear – Dynamic   | vector, list              | Python’s `list`, C++ `vector`                                |
|                    | linked list, stack, queue | Built-in list, `deque`, or custom classes                    |
| Non-Linear         | tree, graph               | Use class-based or library-based implementations             |
| Hash/Table/Map/Set | dict, map, set            | Python `dict`, `set`; Java `Map`, `Set`; C++ STL equivalents |

---

## Key Concepts at a Glance

### Primitive vs Non-Primitive

* **Primitive** → Single raw values (int, float, bool, etc.)
* **Non-Primitive** → Grouped or linked values (lists, trees, graphs, etc.)

### Pointer

* **C/C++**: Manual pointer declaration and memory access
* **Python**: No explicit pointer, but variables reference memory by default

### Vector (Python: List)

* Auto-resizable array
* In Python, `list` is the closest equivalent
* In C++, `vector` from STL is used

### Map vs Set

| Map                         | Set                         |
| --------------------------- | --------------------------- |
| Stores Key–Value Pairs      | Stores Only Unique Values   |
| Python: `dict`              | Python: `set`               |
| Java: `Map`, `TreeMap`      | Java: `Set`, `TreeSet`      |
| C++: `unordered_map`, `map` | C++: `unordered_set`, `set` |

---

## Use Case Table

| Structure     | Common Applications                          |
| ------------- | -------------------------------------------- |
| Array         | Static list, matrix operations               |
| List / Vector | Dynamic resizing, simple containers          |
| Linked List   | Dynamic memory, insert/delete at ends/middle |
| Stack         | Undo operations, expression evaluation       |
| Queue         | Scheduling, buffer handling                  |
| Tree          | File systems, search trees                   |
| Graph         | Routing, networking, web crawler             |
| Hash Table    | Fast lookup, symbol tables, caching          |
| Map           | Storing configs, key-value data              |
| Set           | Membership tests, removing duplicates        |

---