import sys

arr = [20, -47, 52, 59, -12]
size = len(arr)

# Find the smallest element
smaller = sys.maxsize
for i in range(size):
    smaller = min(arr[i], smaller)
print(smaller)

# Find the largest element and its index
larger = -sys.maxsize - 1
index = -1
for i in range(size):
    if arr[i] > larger:
        larger = arr[i]
        index = i
print(larger)
print(index)