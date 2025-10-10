from typing import List

class Solution:
    def singleNonDuplicate(self, A: List[int]) -> int:
        n = len(A)
        
        # If the array has only one element, return it
        if n == 1:
            return A[0]

        st, end = 0, n - 1  # start and end pointers for binary search

        while st <= end:
            mid = st + (end - st) // 2  # calculate middle safely to avoid overflow

            # Check if mid is the single element
            # Three cases:
            # 1. mid is the first element and not equal to the next
            # 2. mid is the last element and not equal to the previous
            # 3. mid is not first/last and not equal to neighbors
            if (mid == 0 and A[0] != A[1]) or \
               (mid == n - 1 and A[n - 1] != A[n - 2]) or \
               (0 < mid < n - 1 and A[mid] != A[mid - 1] and A[mid] != A[mid + 1]):
                return A[mid]

            # Decide which side to search next based on index parity
            if mid % 2 == 0:  # mid is even
                if A[mid] == A[mid - 1]:  # pair is on the left side
                    end = mid - 1  # search left
                else:  # pair is on the right side
                    st = mid + 1  # search right
            else:  # mid is odd
                if A[mid] == A[mid - 1]:  # pair is on the left side
                    st = mid + 1  # search right
                else:  # pair is on the right side
                    end = mid - 1  # search left

        return -1  # if no single element is found (edge case)

# ------------------- Test -------------------

if __name__ == "__main__":
    sol = Solution()

    # Example array: single element is 2
    arr = [1,1,2,3,3,4,4,5,5]
    result = sol.singleNonDuplicate(arr)

    print("The single non-duplicate element is:", result)