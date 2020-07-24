def BubbleSort(A):
    for i in range(len(A)):
        for j in range(i+1,len(A)):
            if A[i] > A[j]:
                A[i], A[j] = A[j], A[i]

    return A

X = [ 10, 4, 6, 2, 9 ]

Y = BubbleSort(X)
print(Y)
