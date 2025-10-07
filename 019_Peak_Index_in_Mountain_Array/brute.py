from typing import List

class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        n = len(arr)
        for i in range(1, n-1):   # skip 0 and n-1 because peak is always in between
            if arr[i-1] < arr[i] > arr[i+1]:
                return i
        return -1

# -------------------------
# Example Test Cases
# -------------------------
if __name__ == "__main__":
    obj = Solution()
    arr1 = [0, 2, 5, 7, 6, 4, 3, 1]
    arr2 = [1, 3, 5, 4, 2]
    arr3 = [0, 10, 5, 2]

    print("Peak Index in arr1:", obj.peakIndexInMountainArray(arr1))  # Expected 3
    print("Peak Index in arr2:", obj.peakIndexInMountainArray(arr2))  # Expected 2
    print("Peak Index in arr3:", obj.peakIndexInMountainArray(arr3))  # Expected 1


# Example usage
print()
obj = Solution()
arr1 = [0, 2, 5, 7, 6, 4, 3, 1]
arr2 = [1, 3, 5, 4, 2]
arr3 = [0, 10, 5, 2]

print("Peak Index in arr1:", obj.peakIndexInMountainArray(arr1))  # Expected 3
print("Peak Index in arr2:", obj.peakIndexInMountainArray(arr2))  # Expected 2
print("Peak Index in arr3:", obj.peakIndexInMountainArray(arr3))  # Expected 1