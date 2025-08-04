
def reverse_number(n):
    sign = -1 if n < 0 else 1
    n = abs(n)
    rev = 0
    while n != 0:
        digit = n % 10
        rev = rev * 10 + digit
        n = n // 10
    return sign * rev

# Test
n = int(input("Enter a number: "))
print("Reversed number:", reverse_number(n))