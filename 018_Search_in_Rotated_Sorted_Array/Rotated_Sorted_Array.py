from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        st, end = 0, len(nums) - 1

        while st <= end:
            mid = st + (end - st) // 2

            if nums[mid] == target:
                return mid

            # Left half is sorted
            if nums[st] <= nums[mid]:
                if nums[st] <= target < nums[mid]:
                    end = mid - 1
                else:
                    st = mid + 1
            # Right half is sorted
            else:
                if nums[mid] < target <= nums[end]:
                    st = mid + 1
                else:
                    end = mid - 1

        return -1


# Example usage
if __name__ == "__main__":
    sol = Solution()
    nums = [4, 5, 6, 7, 0, 1, 2]
    target = 0
    result = sol.search(nums, target)
    print("Target found at index:" if result != -1 else "Target not found", result)