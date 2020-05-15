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

def factorial_recursive(n):
    if n == 1:
        return 1
    else:
        return n * factorial_recursive(n-1)

def factorial_iter(n):
    if n == 1:
        return 1
    
    res = 1
    for i in range (n, 0, -1):
        res = res * i;

    return res

x = factorial_recursive(4)
print(x)
x = factorial_iter(4)
print(x)
