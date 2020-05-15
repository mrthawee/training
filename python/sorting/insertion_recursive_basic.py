import random
import sys
import os

def InsertionSort_Recursive_Optimized(A, n):

    cnt = 0
    if (n <= 1):
        return cnt
    cnt += InsertionSort_Recursive_Optimized(A, n-1)

    # now insert the nth element into the right place
    j = n - 1
    cnt += 1
    while (j-1 >= 0) and (A[j-1] > A[j]):
            cnt += 1
            # Do right-shift instead of swap here
            A[j] = A[j-1]
            j -= 1

    # need this swap only once at the end
    A[j], A[n] = A[n], A[j]
    print("len = %d num comparison = %d" % (n, cnt))
    return cnt


I = [ 3 ,1, 7, 2, 10]
print(I)
InsertionSort_Recursive_Optimized(I,len(I))
print(I)

X = [ 30, 5, 39, 4, 2, 10, 3, 9, 8, 7]
print(X)
InsertionSort_Recursive_Optimized(X,len(X))
print(X)

Y = [ 1, 2, 3, 4, 5]
print(Y)
InsertionSort_Recursive_Optimized(Y,len(Y))
print(Y)
