
# Time: always O(n log n) 
# Space: O(n)

# Complexity is at 'Combine' step
# Also need extra space of size n
'''
Idea:
MergeSort(A)
    n = len(A)
    if n <= 1:
        return A

    L = MergeSort(A[1:n/2])
    R = MergeSort(A[(n/2)+1:n])

    return Merge(L,R)

Pseudo Code:
function MergeSort(A)
    mergeSortHelper(A, 0, len-1)

function MergeSortHelper(A, start, end)
    if start >= end
        return

    mid = (start + end) / 2
    mergeSortHelper(A, start, mid)
    mergeSortHelper(A, mid+1, end)

    i = start
    j = mid+1

    aux = empty array of size end - start + 1
    while i<=mid and j<=end
        if A[i] <= A[j]
            aux.append(A[i])
            i++
        else
            aux.append(A[j])
            j++
    while i<=mid
        aux.append(A[i])
        i++
    while j<=end
        aux.append(A[j])
        j++

    A[start .. end] = aux
    return 
'''
import math

def mergeSortHelper(A, start, end):
    print("start=%d end=%d" %(start, end))
    if (start >= end):
        return

    mid = math.floor((start + end) / 2)
    mergeSortHelper(A, start, mid)
    mergeSortHelper(A, mid+1, end)

    i = start
    j = mid+1

    #pdb.set_trace()
    aux = []
    while (i<=mid) and (j<=end):
        if (A[i] <= A[j]):
            aux.append(A[i])
            i += 1
        else:
            aux.append(A[j])
            j += 1
    while (i<=mid):
        aux.append(A[i])
        i += 1
    while (j<=end):
        aux.append(A[j])
        j += 1

    #print("aux=",aux)
    #print("A=",A)
    A[start:end+1] = aux  # Thawee's note: update only the 'sorted part'
    #print("A=",A)
    return

def MergeSort(A):
    mergeSortHelper(A, 0, len(A)-1)

I = [ 3 ,1, 7, 2, 10]
#I = [ 3 ,1, 2]
print(I)
#import pdb; pdb.set_trace()
#import pdb
MergeSort(I)
print(I)

X = [ 30, 5, 39, 4, 2, 10, 3, 9, 8, 7]
print(X)
MergeSort(X)
print(X)

Y = [ 1, 2, 3, 4, 5]
print(Y)
MergeSort(Y)
print(Y)
