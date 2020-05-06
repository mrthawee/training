import random
import sys
import os
I = [ 3 ,1, 7, 2, 10]

X = [ 30, 5, 39, 4, 2, 10, 3, 9, 8, 7]

def BubbleSort(A):
    i = 0
    j = 0

    cnt = 0
    for i in range(len(A)):
        for j in range(i+1, len(A)):
            cnt += 1
            if (A[i] > A[j]):
                A[i], A[j] = A[j], A[i]

    print("len = %d num comparison = %d" % (len(A), cnt))

print(I)
BubbleSort(I)
print(I)

print(X)
BubbleSort(X)
print(X)
