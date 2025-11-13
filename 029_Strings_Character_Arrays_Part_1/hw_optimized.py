class Solution:
    def isAlphaNum(self, ch):
        # Check if character is alphanumeric (letter or digit)
        return ch.isalnum()

    def isPalindrome(self, s: str) -> bool:
        st, end = 0, len(s) - 1

        while st < end:
            # Skip non-alphanumeric characters from start
            if not self.isAlphaNum(s[st]):
                st += 1
                continue

            # Skip non-alphanumeric characters from end
            if not self.isAlphaNum(s[end]):
                end -= 1
                continue

            # Compare lowercase versions of characters
            if s[st].lower() != s[end].lower():
                return False

            st += 1
            end -= 1

        return True


# Example usage
obj = Solution()
s = "A man, a plan, a canal: Panama"
print("Palindrome" if obj.isPalindrome(s) else "Not Palindrome")
