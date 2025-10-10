def isValid(arr, n, m, maxAllowedPages):
    students = 1
    pages = 0

    for i in range(n):
        if arr[i] > maxAllowedPages:
            return False

        if pages + arr[i] > maxAllowedPages:
            students += 1
            pages = arr[i]

            if students > m:
                return False
        else:
            pages += arr[i]

    return True


def allocateBooks(arr, n, m):
    if m > n:
        return -1

    total_pages = sum(arr)
    low = max(arr)
    high = total_pages
    ans = -1

    while low <= high:
        mid = (low + high) // 2

        if isValid(arr, n, m, mid):
            ans = mid
            high = mid - 1
        else:
            low = mid + 1

    return ans


# Example
arr = [10, 20, 30, 40]
n = len(arr)
m = 2

print(allocateBooks(arr, n, m))  # Output: 60