
def is_power_of_2(n):
    return n > 0 and (n & (n - 1)) == 0

# Test
n = int(input("Enter a number: "))
if is_power_of_2(n):
    print(f"{n} is a power of 2.")
else:
    print(f"{n} is NOT a power of 2.")