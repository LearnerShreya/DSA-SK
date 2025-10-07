from typing import List

class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        st, end = 0, len(arr) - 1
        while st < end:
            mid = st + (end - st) // 2
            if arr[mid] > arr[mid + 1]:
                end = mid       # peak is at mid or to the left
            else:
                st = mid + 1    # peak is to the right
        return st

# -------------------------
# Example usage
# -------------------------
if __name__ == "__main__":
    obj = Solution()
    arr1 = [0, 2, 5, 7, 6, 4, 3, 1]
    arr2 = [1, 3, 5, 4, 2]
    arr3 = [0, 10, 5, 2]

    print("Peak Index in arr1:", obj.peakIndexInMountainArray(arr1))  # Expected 3
    print("Peak Index in arr2:", obj.peakIndexInMountainArray(arr2))  # Expected 2
    print("Peak Index in arr3:", obj.peakIndexInMountainArray(arr3))  # Expected 1