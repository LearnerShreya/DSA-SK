from collections import Counter

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        m, n = len(s1), len(s2)  # m = window size, n = full string

        if m > n:
            return False

        freq1 = Counter(s1)
        freq2 = Counter(s2[:m])

        if freq1 == freq2:
            return True

        for i in range(m, n):
            freq2[s2[i]] += 1
            freq2[s2[i - m]] -= 1
            if freq2[s2[i - m]] == 0:
                del freq2[s2[i - m]]
            if freq1 == freq2:
                return True
        
        return False


# ---------- Function call ----------
sol = Solution()


s1 = "ab"
s2 = "eidbaooo"
result = sol.checkInclusion(s1, s2)
print(result)  # expected output: True


# Additional test cases
print(sol.checkInclusion("ab", "eidboaoo"))   # False
print(sol.checkInclusion("adc", "dcda"))      # True (because "cda" is a permutation of "adc")
print(sol.checkInclusion("hello", "ooolleoooleh")) # False
print(sol.checkInclusion("a", "a"))           # True
print(sol.checkInclusion("abc", "bbbca"))     # True (because "bca" is a permutation of "abc")