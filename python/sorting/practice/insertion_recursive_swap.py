def InsertionSort(A, n):
    if n <= 1:
        return 
    InsertionSort(A, n-1)
    j = n-1
    while j>=1 and A[j-1] > A[j]:
        A[j], A[j-1] = A[j-1], A[j]
        j = j-1

    return

X = [ 3, 1, 4, 2, 0 ]

InsertionSort(X, len(X))
print(X)

