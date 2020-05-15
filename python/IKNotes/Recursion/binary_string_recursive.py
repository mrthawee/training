# Decrease and conquer
def binaryString(n):
    if n == 1:
        return ["0", "1"]
    else:
        prev = binaryString(n-1)
        res = []
        for s in prev:
            res.append(s + "0")
            res.append(s + "1")
        return res

print(binaryString(3))
