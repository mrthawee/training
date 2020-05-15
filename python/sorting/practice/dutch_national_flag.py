def dutch_flag_sort(balls):

    i = 0
    j = 0
    k = len(balls) - 1

    print('balls=', balls)
    while (j <= k):
        if balls[j] == 'R':
            # swap to Left
            balls[i], balls[j] = balls[j], balls[i]
            i += 1  # got an 'R'
            j += 1  # because left is growing, so j must + 1
            print('1 balls=', balls)

        elif balls[j] == 'B':
            # swap to Righ
            balls[k], balls[j] = balls[j], balls[k]
            k -= 1
            #j += 1
            print('2 balls=', balls)
        else:
            # found 'G'
            j += 1
            print('3 balls=', balls)

    print('4 balls=', balls)


l = [ 'B', 'G', 'R', 'G', 'B' ]
dutch_flag_sort(l)
