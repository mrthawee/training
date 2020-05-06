import random
import sys
import os

r = random.randrange(0, 100)

while (r != 15):
    print(r, ' ', end='')
    r = random.randrange(0, 100)
print('\n')

i = 0
while (i <= 20):
    if (i%2 == 0):
        print(i, ' ', end='')
    elif (i == 9):
        break
    else:
        i += 1
        continue
    
    i += 1
print('')
