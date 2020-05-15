
'''
Idea:
    QuickSort(A)
        if len(A) <= 1
            return

        Pick some x = A[i] at random - pivot
        Partition the rest of A into
            L (less than x)
            R (more than x)
        Replace A with [L, x, R]
        QuickSort(L)
        QuickSort(R)

Pseudo Code:

function QuickSort(A)
    quickSortHelper(A, 0, len(A)-1)

function quickSortHelper(A, start, end)
    if start >= end
        return

    // Pick a random index for choosing pivot
    randindex = randominteger(start, end)
    swap(A[randindex], A[start])

    // Lomuto's Partitioning: Time = O(n), Space = in-place
    // - Place Pivot at A[0]
    // - Scan from Left to Right
    // - Move bigger(orange) index one at a time
    // - Move smaller(green) index only when expand green sub-array
    // - End with placing Pivot to right-most of green sub-array since Pivot @ A[0]
    pivot = A[start]
    smaller = start
    bigger = start

    for bigger in (start+1) to end:
        if A[bigger] < pivot:
            smaller++
            swap(A[smaller], A[bigger])

    // Pivot at  A[0], swap to the largest smaller sub-array
    swap(A[start], A[smaller])
    // End of Lomuto's Partitioning

    quickSortHelper(A, start, smaller-1)
    quickSortHelper(A, smaller+1, end)

Notion:
    Orange region: vals < pivot --> smaller
    Green region: vals > pivot --> bigger
    Orange index: last check and expected to be < pivot
        Hence, if > pivot, waiting for swapping
    Green index: last check and expected to be > pivot
        Hence, if < pivot, waiting for swapping
Hoare's Partitioning: Time = O(n), Space = in-place, but less ...
1. Orange index starts at left-most - 1
2. Green index starts at right-most + 1
3. Orange region grows from left to right as long as cval is < pivot
   - stop and wait if cval is > pivot
4. Green region green from right to left as long as cval is > pivot
   - stop and wait if cval is < pivot
5. With 2 stops from 3 and 4 AND oIdx < gIdx, swap them to create contiguous orange, green
   - if 2 stops from 3 and 4 BUT orange Index > green Index, stop!
6. if orange index < green index ==> not crossing each other yet
      Goto step 3,4,5,6 again
   else // orange index > green index ==> crossing

Thawee's note: Need to identify the only needed place for index crossing chk

Next swap(Pivot, max(Orange))
      Done!
'''


'''
function quickSortHelper(A, start, end)
    if start >= end
        return

    // Pick a random index for choosing pivot
    randindex = randominteger(start, end)
    swap(A[randindex], A[start])

    // Lomuto's Partitioning: Time = O(n), Space = in-place
    // - Place Pivot at A[0]
    // - Scan from Left to Right
    // - Move bigger(orange) index one at a time
    // - Move smaller(green) index only when expand green sub-array
    // - End with placing Pivot to right-most of green sub-array since Pivot @ A[0]
    pivot = A[start]
    smaller = start
    bigger = start

    for bigger in (start+1) to end:
        if A[bigger] < pivot:
            smaller++
            swap(A[smaller], A[bigger])

    // Pivot at  A[0], swap to the largest smaller sub-array
    swap(A[start], A[smaller])
    // End of Lomuto's Partitioning

    quickSortHelper(A, start, smaller-1)
    quickSortHelper(A, smaller+1, end)
'''
import math
import random

def quickSortHelper(A, start, end):
    #print("A=", A[start:end])
    if (start >= end):
        return

    rIdx = random.randint(start, end)
    #print("rIdx=", rIdx)
    A[rIdx], A[start] = A[start], A[rIdx]

    pivot = A[start]
    #print("A=",A[start,end], "pivot=",pivot)
    oIdx = start
    gIdx = start

    for gIdx in range(start+1, end+1):
        if (A[gIdx] < pivot):
            oIdx += 1
            A[oIdx], A[gIdx] = A[gIdx], A[oIdx]
    A[start], A[oIdx] = A[oIdx], A[start]


    quickSortHelper(A, 0, oIdx-1)
    quickSortHelper(A, oIdx+1, end)

def QuickSort(A):
    quickSortHelper(A, 0, len(A)-1)


I = [ 3 ,1, 7, 2, 10]
print(I)
#import pdb; pdb.set_trace()
QuickSort(I)
print(I)

X = [ 30, 5, 39, 4, 2, 10, 3, 9, 8, 7]
print(X)
#import pdb; pdb.set_trace()
QuickSort(X)
print(X)

Y = [ 1, 2, 3, 4, 5]
print(Y)
QuickSort(Y)
print(Y)
