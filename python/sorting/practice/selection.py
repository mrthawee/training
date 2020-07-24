def SelectionSort(A):
    for i in range(len(A)):
        cur_min_index = i
        for j in range(i+1, len(A)):
            if A[cur_min_index] > A[j]:
                cur_min_index = j
        A[i], A[cur_min_index] = A[cur_min_index], A[i]

    return A


X = [ 3, 1, 5, 4, 2]

Y = SelectionSort(X)
print(Y)

