def merge_two_sorted_arrays(A1, A2):
    i = len(A1) - 1
    j = len(A1) - 1
    last = len(A2) - 1

    print('last=%d i=%d j=%d' % (last, i, j))

    while (i >= 0 and j >= 0):
        if (A1[i] >= A2[j]):
            A2[last] = A1[i]
            i -= 1
        else:
            A2[last] = A2[j]
            j -= 1
        last -= 1
    print('last=%d i=%d j=%d' % (last, i, j))
    print('A2=', A2)

    while i>=0:
        A2[last] = A1[i]
        i -= 1
        last -= 1
    print('last=%d i=%d j=%d' % (last, i, j))
    print('A2=', A2)


    while j>=0:
        A2[last] = A2[j]
        j -= 1
        last -= 1

    print('last=', last)
    print('A2=', A2)


a1 = [1, 4, 5]
a2 = [2, 3, 7, 0, 0, 0]

merge_two_sorted_arrays(a1, a2)
