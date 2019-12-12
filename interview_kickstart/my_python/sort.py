
def InsertionSort(A, n): # array A[0..(n-1)]
    if n <= 0:
        return
    for i in range(1, n-1):
        val = A[i]          # first val to be moved is at (i)th -> 1, 2, 3, 4 .. (n-1)
        j = i - 1           # j = 0, 1, 2 ... (n-2)th
        while j>=0 and A[j] > val:  # comparing val with 
            A[j+1] = A[j]   # shift A[j] to A[j+1]
            j -= 1         
        A[j+1] = val
    return A


# Bubble sort = swap sort
# - swapping each adjacent to create sorted list
def myBubbleSort(A):
    n = len(A)
    for i in range (0, n-1):
        #val = A[i]                              # start from A[0], then A[1], A[2]
        for j in range (i+1, 0, -1):            # sort(A[0..1]) then sort(A[0..2]) then sort(A[0..3])
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]     # from right most A, move the min to A[0]
        #print(A)
    return A


# Insertion sort = shift sort 
# - it shifts other val to create sorted spot for hole
# - each loop, iterate over 'sorted' part
def myInsertionSort(A):
    n = len(A)
    for i in range (1, n, 1): 
        # Hole is the right most one of the each loop
        val = A[i]
        hole_index = i

        # Shift right to find spot for hole
        # - Sorting list is grewing from left to right in each for loop
        # - So hole might be place at [0] if it is the min val
        while hole_index > 0 and  A[hole_index-1] > val:
            A[hole_index] = A[hole_index-1]
            hole_index -= 1

        # Place hole to new spot in sorted order
        A[hole_index] = val
    return A

# Seletion Sort = Find Min Sort
# - find min of unsorted part, then put into the sorted part
# - each loop, iterate over 'unsorted' part
def mySelectionSort(A):
    n = len(A)
    for i in range (1, n, 1):
        cur_idx = i-1
        min_idx = i-1
        for j in range (i, n):
            if (A[j] < A[min_idx]):
                min_idx = j

        A[cur_idx], A[min_idx] = A[min_idx], A[cur_idx]

    return A

def myMerge(A,B):
    nA = len(A)
    nB = len(B)

    i = 0
    j = 0

    O = []
    while i < nA and j < nB:
        if A[i] < B[j]:
            O.append(A[i])
            i += 1
        else:
            O.append(B[j])
            j += 1
    if (i<nA):
        while (i<nA):
            O.append(A[i])
            i += 1
    elif (j<nB):
        while (j<nB):
            O.append(B[j])
            j += 1
    return O


def myMergeSort(D):
    #print('Merge Sort', D)
    n = len(D)

    if n <= 1:
        return D

    #print("D1=",D[0:int((n+1)/2)])
    A = myMergeSort(D[0:int((n+1)/2)])
    #print("D2=",D[int((n+1)/2):n])
    B = myMergeSort(D[int((n+1)/2):n])

    #print('A=',A)
    #print('B=',B)
    E = myMerge(A, B)
    return E

def myQuickSort(D):
    pass

D = [ 8, 2, 4, 9, 1, 7, 6]
print('Bubble sort: ',end='')
E = myBubbleSort(D)
print(E)


D = [ 8, 2, 4, 9, 1, 7, 6]
print('Insertion sort:',end='')
E = myInsertionSort(D)
print(E)

#D = [ 8, 2, 4, 9, 1, 6]
D = [ 8, 2, 4, 9, 1, 7, 6]
print('Selection sort:',end='')
E = mySelectionSort(D)
print(E)

D = [ 8, 2, 4, 9, 1, 7, 6]
print('Merge sort:',end='')
E = myMergeSort(D)
print(E)
'''
A = [ 2,4,6,8,10]
B = [ 0,1]
D = myMerge(A,B)
print(D)
'''

def testPassingVars(a,b):
    print("testPassingVars:")
    print("input:", end='')
    print(a, b)
    a, b = b, a
    print("Output:", end='')
    print(a, b)

a = 10
b = 5
testPassingVars(a,b)
print(a,b)

def lomuto(A, beg_idx, end_idx):
    print("lomuto quick sort")
    if beg_idx >= end_idx:
        return

    pivot_idx = beg_idx

    pivot = A[beg_idx]
    less_idx = beg_idx
    more_idx = beg_idx
    for more_idx in range (beg_idx+1, end_idx):
        if A[more_idx] < pivot:
            less_idx += 1
            A[less_idx], A[more_idx] = A[more_idx], A[less_idx]  # swap to create contiguous A[] < pivot

    A[beg_idx], A[less_idx] = A[less_idx], A[beg_idx]    # swap pivot with the last A[less_idx]

    lomuto(A, beg_idx, less_idx - 1)
    lomuto(A, less_idx + 1, end_idx)

    return A

def hoare(A, beg, end):
    print("harse quick sort:", beg, '-',end)
    if beg >= end:
        return

    pivot = A[beg]
    less = beg+1
    more = end-1

    while less < more:
        while A[less] < pivot:
            less += 1
        while A[more] > pivot:
            more -= 1

        if less <= more:
            A[more], A[less] = A[less], A[more]
            more -= 1
            less += 1

    #if less > more:
    if A[beg] > A[more]:
        A[beg], A[more] = A[more], A[beg]
    print("A=",A)
    hoare(A, beg, more)
    hoare(A, more+1, end)

    return A

def myQuickSort(D):
    # 1. pick pivot
    # 2. QuickSort(Left) : all val <= pivot
    # 3. QuickSort(Right) : all val > pivot

    print("Input:", D)
    #A = lomuto(D, 0, len(D))
    A = hoare(D, 0, len(D))
    print("Input:", D)
    print("Sorted output:", A)

D = [ 8, 2, 4, 9, 1, 7, 6, 1, 2]
#D = [ 8, 2, 4, 9, 1, 7, 6]
#D = [ 4,2,8,7,1,3,5,6]
print('Quick sort:')
E = myQuickSort(D)
print(E)


def myCountSort(D):
    print("Count Sort:", end='')
    print(D)

    myDict = dict.fromkeys(range(10), 0)

    for i in D:
        myDict[i] += 1
    print(myDict)


D = [ 8, 2, 4, 9, 1, 7, 6, 1, 2]
#D = [ 8, 2, 4, 9, 1, 7, 6]
#D = [ 4,2,8,7,1,3,5,6]
#E = myCountSort(D)
myCountSort(D)
#print(E)
