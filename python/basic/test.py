a = [ 1, 2, 3, 4 ]

for i in range (len(a)-1, 0, -1):
    print(a[i], end=' ')
print('\n')

x = [1,2,3]
y = [4,5,6,0,0,0]

y[len(x):] = x
print(y)
