class Solution:
    def compress(self, chars: list[str]) -> int:
        n = len(chars)
        i = 0
        idx = 0

        while i < n:
            ch = chars[i]
            count = 0

            while i < n and chars[i] == ch:
                i += 1
                count += 1

            chars[idx] = ch
            idx += 1

            if count > 1:
                for d in str(count):
                    chars[idx] = d
                    idx += 1

        return idx

# Example usage:
sol = Solution()
chars = ["a","a","b","b","c","c","c"]
length = sol.compress(chars)
print(length)  # Output: 6
print(chars[:length])  # Output: ["a","2","b","2","c","3"]