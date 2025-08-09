import sys

# 1. Static list
arr = [10, 20, 30, 40, 50]

# Number of elements
print("Number of elements in list:", len(arr))

# Memory size of the list object
print("Memory size of list object (bytes):", sys.getsizeof(arr))

# Memory size of each element
print("Size of each element (bytes):", sys.getsizeof(arr[0]))

# Total memory of all elements (approx)
total_memory = sys.getsizeof(arr) + sum(sys.getsizeof(i) for i in arr)
print("Total memory used by list and its elements:", total_memory)

# Output
print("List elements:", *arr)

# 2. Dynamic input
n = int(input("\nEnter size of dynamic list: "))
dyn_arr = []

print(f"Enter {n} elements:")
for _ in range(n):
    dyn_arr.append(int(input()))

print("Dynamic list elements:", *dyn_arr)
print("Length of dynamic list:", len(dyn_arr))
print("sys.getsizeof(dyn_arr):", sys.getsizeof(dyn_arr))
