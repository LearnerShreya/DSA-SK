class Solution:

        # words = s.split()
        # words.reverse()
        # return " ".join(words)

    def reverseWords(self, s: str) -> str:
        return " ".join(s.split()[::-1])

# sol = Solution()
print(Solution.reverseWords(" hello world  "))  # Output: "world hello"