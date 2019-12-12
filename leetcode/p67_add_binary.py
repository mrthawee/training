def addBinary(a, b):
    print('a=',a,'  b=', b)
    a_int = int(a, 2)
    b_int = int(b, 2)
    sum = a_int + b_int
    return '{0:b}'.format(sum)

print(addBinary('101','110'))

