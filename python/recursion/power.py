import math

def power(x, n):
    if x == 0:
        return 0
    elif x == 1 or n == 0:
        return 1
    elif n == 1:
        return x

    if n % 2 == 0:
        return math.pow(power(x, n/2), 2)
    else:
        return x*math.pow(power(x, (n-1)/2), 2)

print(power(2, 10))
print(power(2, 5))
