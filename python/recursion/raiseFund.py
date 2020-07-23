'''
if (test for the simple case)
    compute a simple solution without using recursion
else:
    # Divide-and-conquer or Decrease-and-conquer
    break the problem into subproblesm to the same form
    solve each of the subproblems by calling this function recursively
    reassemble the subproblem solutions into a solution for the whole
'''

def raiseFund(amount):
    sum = 0
    if (amount <= 10):
        return amount
    else:
        
        for i in range (0, 10):
            sum += raiseFund(amount/10)

    return sum

x = raiseFund(10000)
print(x)
