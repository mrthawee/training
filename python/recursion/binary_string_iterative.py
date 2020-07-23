# Decrease and conquer
def binaryString(n):
    res = ["0", "1"]

    for i in range (1, n):
        new_res = []
        for s in res:
            print('inner res=',res, 's=', s)
            new_res.append(s + "0")
            new_res.append(s + "1")
            print('new_res=',new_res)
        res = new_res
        print('outer res=',res)

    return res

#print(binaryString(0))
#print(binaryString(1))
#print(binaryString(2))
print(binaryString(3))
