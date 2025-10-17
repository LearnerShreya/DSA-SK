def merge(A, m, B, n):
    idx = m + n - 1  
    i = m - 1     
    j = n - 1   

    # Merge from the end
    while i >= 0 and j >= 0:
        if A[i] >= B[j]:
            A[idx] = A[i]
            i -= 1
        else:
            A[idx] = B[j]
            j -= 1
        idx -= 1

    # Copy remaining elements of B, if any
    while j >= 0:
        A[idx] = B[j]
        j -= 1
        idx -= 1

A = [1, 3, 5, 0, 0, 0]  # A has extra space for B
B = [2, 4, 6]
m, n = 3, 3

merge(A, m, B, n)
print("Merged array:", A)