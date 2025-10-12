def is_possible(arr, N, C, min_allowed_dist):
    cows = 1
    last_stall_pos = arr[0]

    for i in range(1, N):
        if arr[i] - last_stall_pos >= min_allowed_dist:
            cows += 1
            last_stall_pos = arr[i]
        if cows == C:
            return True
    return False

def get_distance(arr, N, C):
    arr.sort()  # O(N log N)
    st = 1
    end = arr[-1] - arr[0]
    ans = -1

    while st <= end:  # O(log(range) * N)
        mid = st + (end - st) // 2

        if is_possible(arr, N, C, mid):  # right
            ans = mid
            st = mid + 1
        else:  # left
            end = mid - 1
    return ans

if __name__ == "__main__":
    N = 5
    C = 3
    arr = [1, 2, 8, 4, 9]
    print(get_distance(arr, N, C))