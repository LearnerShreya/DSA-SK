
# Input an Array using Loop

size = int(input())
arr = []

for i in range(size):
    num = int(input())
    arr.append(num)

# Or

arr = list(map(int, input().split()))
size = len(arr)



# Output an Array using Loop

for i in range(size):
    print(arr[i], end=" ")

# Or

print(*arr)  # prints all elements space-separated

# Or


# Input → Process → Output

size = int(input())
arr = []

for i in range(size):
    arr.append(int(input()))

print("You entered:", *arr)