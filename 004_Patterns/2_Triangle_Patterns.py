# Triangle Patterns

n = int(input("Enter n: "))

print()
for i in range(1, n+1):
    print("* "*i)

print()
for i in range(1, n+1):
    for j in range(i):
        print(i, end=" ")
    print()

print()
for i in range(n):
    for j in range(i+1):
        print(chr(65+i), end=" ")
    print()

print()
for i in range(1, n+1):
    for j in range(1, i+1):
        print(j, end=" ")
    print()

print()
for i in range(1, n+1):
    for j in range(i, 0, -1):
        print(j, end=" ")
    print()

print()
num = 65
for i in range(n):
    for j in range(i+1):
        print(chr(num), end=" ")
        num += + 1
    print()