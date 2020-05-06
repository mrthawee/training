import random
import sys
import os

def SelectionSort(A):
    i = 0
    j = 0

    cnt = 0
    for i in range(len(A)):
        min_idx = i
        for j in range(i+1, len(A)):
            cnt += 1
            if (A[min_idx] > A[j]):
                min_idx = j 
        A[i], A[min_idx] = A[min_idx], A[i]

    print("len = %d num comparison = %d" % (len(A), cnt))

I = [ 3 ,1, 7, 2, 10]
print(I)
SelectionSort(I)
print(I)

X = [ 30, 5, 39, 4, 2, 10, 3, 9, 8, 7]
print(X)
SelectionSort(X)
print(X)
