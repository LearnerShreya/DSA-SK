def binary_search(arr, target):
    st, end = 0, len(arr) - 1
    
    while st <= end:
        mid = st + (end - st) // 2  # ✅ safer mid calculation
        
        if target > arr[mid]:
            st = mid + 1
        elif target < arr[mid]:
            end = mid - 1
        else:
            return mid  # Target found
    
    return -1  # Target not found


# Case 1: Odd-sized array (target present)
arr1 = [-1, 0, 3, 4, 5, 9, 12]
tar1 = 12
print(f"Odd-sized array → Index of {tar1} = {binary_search(arr1, tar1)}")

# Case 2: Even-sized array (target present)
arr2 = [-1, 0, 3, 5, 9, 12]
tar2 = 0
print(f"Even-sized array → Index of {tar2} = {binary_search(arr2, tar2)}")

# Case 3: Target not found (-1 case)
arr3 = [2, 4, 6, 8, 10]
tar3 = 7
print(f"Target not found → Index of {tar3} = {binary_search(arr3, tar3)}")