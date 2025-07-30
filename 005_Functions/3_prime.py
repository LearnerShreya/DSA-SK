def isPrime(n):
    if n < 2:
        return False 
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False 
    return True  

def fact(a):
    if a < 0:
        return "Undefined (factorial not defined for negative numbers)"
    ans = 1
    for i in range(1, a + 1):
        ans *= i
    return ans


m = int(input("Enter num m: "))
n = int(input("Enter num n: "))

print("Is 'm' a prime number:", isPrime(m))
print("Is 'n' a prime number:", isPrime(n))
print("Is 'm-n' a prime number:", isPrime(m-n))

print("Factorial of 'm':", fact(m))
print("Factorial of 'n':", fact(n))
print("Factorial of 'm-n':", fact(m-n))

print("=========================")

# Prime Check
for num, name in [(m, 'm'), (n, 'n'), (m - n, 'm - n')]:
    if isPrime(num):
        print(f"'{name}' ({num}) is a Prime number")
    else:
        print(f"'{name}' ({num}) is NOT a Prime number")

# Factorial
for num, name in [(m, 'm'), (n, 'n'), (m - n, 'm - n')]:
    factorial_result = fact(num)
    print(f"Factorial of '{name}' ({num}): {factorial_result}")

