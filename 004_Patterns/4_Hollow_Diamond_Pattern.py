
# Enter n: 4
#       * 
#     *   * 
#   *       * 
# *           * 
#   *       *     
#     *   *
#       *

# Method 1 (Using string multiplication and ternary if):
n = int(input("Enter n: "))
# top
for i in range(n):
    print(" "*(n-i-1), end="")
    print("*" if i == 0 else "*" + " " * (2 * i - 1) + "*")
# bottom
for i in range(n-2,-1,-1):
    print(" "*(n-i-1), end="")
    print("*" if i == 0 else "*" + " " * (2*i-1) + "*")


# Method 2 (Full control using nested loops):
n = int(input("Enter n: "))
# Upper half
for i in range(n):
    for j in range(n - i - 1):
        print("  ", end="")         # Leading spaces
    for j in range(2 * i + 1):
        if j == 0 or j == 2 * i:
            print("* ", end="")     # Print star at start and end
        else:
            print("  ", end="")     # Print space in between
    print()
# Lower half
for i in range(n - 2, -1, -1):      # One less row
    for j in range(n - i - 1):
        print("  ", end="")
    for j in range(2 * i + 1):
        if j == 0 or j == 2 * i:    # Use same logic as upper half
            print("* ", end="")
        else:
            print("  ", end="")
    print()


# Method 3 (Using a reusable function):
def print_hollow_line(spaces, stars):
    print("  " * spaces, end="")
    for j in range(stars):
        if j == 0 or j == stars - 1:
            print("* ", end="")
        else:
            print("  ", end="")
    print()
n = int(input("Enter n: "))
# Upper half
for i in range(n):
    print_hollow_line(n - i - 1, 2 * i + 1)
# Lower half
for i in range(n - 2, -1, -1):
    print_hollow_line(n - i - 1, 2 * i + 1)