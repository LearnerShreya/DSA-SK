# Inverted triangle pattern

n = int(input("Enter n: "))

# 1 1 1 1 1 
#   2 2 2 2 
#     3 3 3 
#       4 4 
#         5
print()
for i in range(n):
    for j in range(i):
        print("", end="  ")
    for j in range(n-i):
        print(i+1, end=" ")
    print()

# 1 1 1 1 1
#  2 2 2 2
#   3 3 3
#    4 4
#     5
print()
for i in range(n):
    for j in range(i):
        print("", end=" ")
    for j in range(n-i):
        print(i+1, end=" ")
    print()

#         1
#       1 2 1
#     1 2 3 2 1
#   1 2 3 4 3 2 1
# 1 2 3 4 5 4 3 2 1
print()
for i in range(1, n+1):
    print("  "*(n-i), end="")
    print(" ".join([str(j) for j in range(1,i+1)]), end=" ")
    print(" ".join([str(j) for j in range(i-1, 0 , -1)]), end=" ")
    print()