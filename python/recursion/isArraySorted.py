# time = O(n)
# space = O(n) for recursive stack
def isArraySorted(A):
    if len(A) == 1:
        return True

    return A[0] <= A[1] and isArraySorted(A[1:])

A = [ 1, 2, 3, 4, 5 ]
print(isArraySorted(A))
B = [ 3, 2, 4 ]
print(isArraySorted(B))
