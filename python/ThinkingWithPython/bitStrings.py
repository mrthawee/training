def appendFront(x, L):
    res = []
    for s in L:
       res.append(x + s) 
    return res

def bitStrings(n):
    if n == 0:
        return []

    if n == 1:
        return ["0", "1"]

    return (appendFront("0", bitStrings(n-1)) + appendFront("1", bitStrings(n-1)))

print(bitStrings(4))
