class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        while part in s:
            s = s.replace(part, "", 1)  # remove one occurrence at a time
        return s


# Example usage
obj = Solution()
s = "daabcbaabcbc"
part = "abc"
print(obj.removeOccurrences(s, part))
