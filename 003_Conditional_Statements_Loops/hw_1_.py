# Homework
# Qs. Sum of all numbers from 1 to N which are divisible by 3.
# Qs. Print Factorial of a number N.


n = int(input("Enter num: "))
sum = 0
for i in range(1, n+1):
    if i%3==0:
        sum+=i

print(f"Sum of numbers from 1 to {n} which are divisible by 3 = {sum}")


n = int(input("Enter num: "))
i = 0
sum = 0
while(i<=n):
    i+=1
    if i % 3 == 0:
        sum += i
print(f"Sum of numbers from 1 to {n} which are divisible by 3 = {sum}")