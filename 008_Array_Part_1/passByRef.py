def change_arr(arr):
    print("in function")
    for i in range(len(arr)):
        arr[i] = 2 * arr[i]

# main
arr = [1, 2, 3]
change_arr(arr)
print("in main")
for i in arr:
    print(i, end=" ")
print()