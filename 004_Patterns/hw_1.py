
n = int(input("Enter n: "))

# A B C 
# D E F 
# G H I 
ch = ord('A')
for i in range(n):
    for j in range(n):
        print(chr(ch), end=" ")
        ch += 1
    print()


# Floyd's Triangle Pattern
# with numbers
# 1 
# 2 3 
# 4 5 6 
print()
num = 1
for i in range(n):
    for j in range(i+1):
        print(num, end=" ")
        num += 1
    print()


# A 
# B A 
# C B A 
print()
for i in range(n):
    for j in range(i, -1, -1):
        print(chr(65+j), end=" ")
    print()
    

# A A A 
#   B B 
#     C 
# print()
for i in range(n):
    for j in range(i):
        print("", end="  ")
    for j in range(n-i):
        print(chr(65+i), end=" ")
    print()


# Butterly Pattern
# *         * 
# * *     * * 
# * * * * * * 
# * * * * * * 
# * *     * * 
# *         * 
print()
for i in range(n):
    stars = "* "*(i+1)
    spaces = "  "*(2*(n-i-1))
    print(stars + spaces + stars)
for i in range(n):
    stars = "* "*(n-i)
    spaces = "  "*(2*i)
    print(stars + spaces + stars)