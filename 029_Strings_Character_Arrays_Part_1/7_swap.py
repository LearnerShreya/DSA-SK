class Solution:
    def reverseString(self, s: list[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        st = 0
        en = len(s) - 1
        while st < en:
            s[st], s[en] = s[en], s[st]  # swap
            st += 1
            en -= 1


# Example usage
s = ["h", "e", "l", "l", "o"]
obj = Solution()
obj.reverseString(s)
print("Reversed string:", s)