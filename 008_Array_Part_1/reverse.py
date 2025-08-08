
# Using a loop
# Using two pointers
# Using built-in functions
# Input/output

# Static list
arr = [10, 20, 30, 40, 50]
print("Original:", arr)

# 1️⃣ Method 1: Two Pointer
arr_tp = arr.copy()
left, right = 0, len(arr_tp) - 1
while left < right:
    arr_tp[left], arr_tp[right] = arr_tp[right], arr_tp[left]
    left += 1
    right -= 1
print("Reversed (Two Pointers):", arr_tp)

# 2️⃣ Method 2: Using slicing
arr_slice = arr[::-1]
print("Reversed (Slicing):", arr_slice)

# 3️⃣ Method 3: Using reverse() method (in-place)
arr_inplace = arr.copy()
arr_inplace.reverse()
print("Reversed (reverse()):", arr_inplace)

# 4️⃣ Method 4: Using loop
print("Reversed (for loop):", end=" ")
for i in range(len(arr)-1, -1, -1):
    print(arr[i], end=" ")
print()