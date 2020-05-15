import random
import sys
import os

'''
worst case = O(n^2)
average case = O(n^2)
best case = O(n)
'''

def InsertionSort_Interative(A, n):
    cnt = 0
    if (n <= 1):
        return

    # sub-arrays are shrinking from left to right
    # 1st sub-array size = 2
    # 2nd sub-array size = 3
    # 3rd sub-array size = 4
    
    # try to insert the last element of each sub-array to the left most pos
    # - This works before all elements on left are sorted as sub-arrays grow
    for i in range(1, n):
        val = A[i]  # last element of current sub-array
        j = i-1     # j = current pos to compare with 'val'
                    #     and right shifted if A[j] > val

        # shift right current sub-array if A[j] > val
        cnt += 1
        while (j>=0) and (A[j] > val):
            cnt +=1
            A[j+1] = A[j]
            j -= 1

        # 'j+1' is where to insert val
        A[j+1] = val  # Thawee's note: j+1 because it was -1 at line 33
    print("len=%d  num comp=%d" % (n, cnt))
    return

I = [ 3 ,1, 7, 2, 10]
print(I)
#import pdb; pdb.set_trace()
InsertionSort_Interative(I,len(I))
print(I)

X = [ 30, 5, 39, 4, 2, 10, 3, 9, 8, 7]
print(X)
InsertionSort_Interative(X,len(X))
print(X)

Y = [ 1, 2, 3, 4, 5]
print(Y)
InsertionSort_Interative(Y,len(Y))
print(Y)
