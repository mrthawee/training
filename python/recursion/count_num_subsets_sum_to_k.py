# Backtracking

def subsetsum(S, k):
    return helper(S, 0, k, [], 0)

def helper(S, i, k, slate, slatesum):
    if slatesum > k:
        return 0
    
    if slatesum == k:
        return 1

    if i == len(S):
        return 0
    else:
        return helper(S, i+1, k, slate, slatesum) + helper(S, i+1, k, slate, slatesum+S[i])

A = [ 1,2,3,4,5]
print(subsetsum(A, 4))
