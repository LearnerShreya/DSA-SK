
# Homework
# 1. WAF to check if a number is prime or not.

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

n = 10
is_prime(n)
if is_prime(n) == True:
    print(f"prime numbers: {n}.")
else:
    print(f"Not a prime numbers: {n}.")



# 2. WAF to print all prime numbers from 2 to Ν.

import math

# Optimized Prime Check using sqrt(n)
def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

# Function to print all primes from 2 to N
def print_all_primes(N):
    primes = []
    for i in range(2, N + 1):
        if is_prime(i):
            primes.append(i)
    return primes

n = 50
print(f"Prime numbers from 2 to {n}: {print_all_primes(n)}")


# 3. WAF to print nth Fibonacci.

def fibo(n):
    if n == 1:
        return 0
    elif n == 2:
        return 1
    a, b = 0, 1
    for i in range(3, n + 1):
        c = a + b
        a = b
        b = c
    return c

n = 10
print(f"{n}th Fibonacci: {fibo(n)}.")