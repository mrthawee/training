def factorial_recursive(n):
    if n == 1:
        return 1
    else:
        return n * factorial_recursive(n-1)

def factorial_iter(n):
    if n == 1:
        return 1
    
    res = 1
    for i in range (2, n+1):
        res = res * i;

    return res

x = factorial_recursive(4)
print(x)
x = factorial_iter(4)
print(x)
