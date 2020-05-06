import random
import sys
import os

def InsertionSort_Recursive_Basic(A, n):

    cnt = 0
    if (n <= 1):
        #return
        return cnt
    #InsertionSort_Recursive_Basic(A, n-1)
    cnt += InsertionSort_Recursive_Basic(A, n-1)

    # now insert the nth element into the right place
    j = n - 1
    cnt += 1
    while (j-1 >= 0) and (A[j-1] > A[j]):
            cnt += 1
            A[j], A[j-1] = A[j-1], A[j]
            j -= 1
    #return
    print("len = %d num comparison = %d" % (n, cnt))
    return cnt


I = [ 3 ,1, 7, 2, 10]
print(I)
InsertionSort_Recursive_Basic(I,len(I))
print(I)

X = [ 30, 5, 39, 4, 2, 10, 3, 9, 8, 7]
print(X)
InsertionSort_Recursive_Basic(X,len(X))
print(X)

Y = [ 1, 2, 3, 4, 5]
print(Y)
InsertionSort_Recursive_Basic(Y,len(Y))
print(Y)
