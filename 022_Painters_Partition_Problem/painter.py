def is_possible(arr, n, m, max_allowed_time):
    painters = 1
    time = 0
    for i in range(n):
        if arr[i] > max_allowed_time:
            return False
        if time + arr[i] <= max_allowed_time:
            time += arr[i]
        else:
            painters += 1
            time = arr[i]
        if painters > m:
            return False
    return True

def min_time_to_paint(arr, n, m):
    total_sum = sum(arr)
    max_val = max(arr)

    st, end = max_val, total_sum
    ans = -1

    while st <= end:
        mid = st + (end - st) // 2
        if is_possible(arr, n, m, mid):
            ans = mid
            end = mid - 1
        else:
            st = mid + 1
    return ans

# Example usage
arr = [40, 30, 10, 20]
n = 4
m = 2
print(min_time_to_paint(arr, n, m))