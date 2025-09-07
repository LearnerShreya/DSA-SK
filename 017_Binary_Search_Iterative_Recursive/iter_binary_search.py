def binary_search(arr, tar):
    st, end = 0, len(arr) - 1
    
    while st <= end:
        mid = (st + end) // 2   # floor division
        
        if tar > arr[mid]:
            st = mid + 1
        elif tar < arr[mid]:
            end = mid - 1
        else:
            return mid  # Target found
    
    return -1  # Target not found


# Driver code
arr1 = [-1, 0, 3, 4, 5, 9, 12]  # odd size
tar1 = 12
print(f"Index of {tar1} = {binary_search(arr1, tar1)}")

arr2 = [-1, 0, 3, 5, 9, 12]  # even size
# tar2 = 0
tar2 = 20
print(f"Index of {tar2} = {binary_search(arr2, tar2)}")