def nextPermutation(nums):
    n = len(nums)
    pivot = -1

    # Step 1: find the pivot (first number from right that is smaller than its next)
    for i in range(n - 2, -1, -1):
        if nums[i] < nums[i + 1]:
            pivot = i
            break

    # If no pivot found, the array is in descending order, so reverse it
    if pivot == -1:
        nums.reverse()
        return

    # Step 2: find the next larger element to swap with pivot
    for i in range(n - 1, pivot, -1):
        if nums[i] > nums[pivot]:
            nums[i], nums[pivot] = nums[pivot], nums[i]
            break

    # Step 3: reverse the part after pivot
    nums[pivot + 1:] = reversed(nums[pivot + 1:])

# Example usage
nums = [1, 2, 3]
nextPermutation(nums)
print("Next permutation:", nums)