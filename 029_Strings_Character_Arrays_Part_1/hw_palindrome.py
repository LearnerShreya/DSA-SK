class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()  # optional: to handle case-insensitive
        s = ''.join(ch for ch in s if ch.isalnum())  # keep only letters and numbers
        
        st = 0
        en = len(s) - 1
        
        while st < en:
            if s[st] != s[en]:
                return False
            st += 1
            en -= 1
        
        return True


# Example usage
obj = Solution()
print(obj.isPalindrome("A man, a plan, a canal: Panama"))  # True
print(obj.isPalindrome("hello"))  # False