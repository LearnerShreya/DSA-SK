# Square Pattern

n = int(input("Enter n: "))

# 1 2 3 
# 1 2 3 
# 1 2 3 
print()
for i in range(1,n+1):
    for j in range(1,n+1):
        print(j, end=" ")
    print()

# * * *
# * * *
# * * *
print()
for i in range(n):
    print("* "*n)

# A B C
# A B C
# A B C
print()
for i in range(n):
    for j in range(n):
        print(chr(j+65), end=" ")
    print()

# 1 2 3
# 4 5 6
# 7 8 9
print()
for i in range(n):
    for j in range(1,n+1):
        print((n*i)+j, end=" ")
    print()

# 1 2 3
# 4 5 6
# 7 8 9
print()
num = 1
for i in range(n):
    for j in range(1,n+1):
        print(num, end=" ")
        num += 1
    print()

# a b c
# a b c
# a b c
print()
row = ' '.join([chr(ord('a') + j) for j in range(n)])
for _ in range(n):
    print(row)