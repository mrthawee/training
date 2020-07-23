# Thawee's note:
# 1. Assume input after sort = 1, 1, ..., 1, x, y, z, a, b, c
# 2. Does not work with 1, 1, 1, 2, 2, 2 ==> more the one dup set
def subsetsWithDup(nums):
    """
    :type nums: List[int]
    :rtype: List[List[int]]
    """

    result = []
    nums.sort()  #All duplicate values will be bunched together. This allows us to count easily how many copies of each value there are.

    def helper(S, i, slate):
        # Base Case: No more elements left to be considered
        if i == len(S): # The partial solution is the next subset, to be appended to the result
            result.append(slate[:])
        else: # Recursive Case: S[i] is the next element to examine
            # Since there may be multiple copies of S[i], count how many there are
            count = 1 # of course, we have already one copy
            j = i + 1 # but how many more are there?
            while j <= len(S)-1 and S[j] == S[i]:
                # Peek forward until you see copies of S[i]. Stop when you see something different or you reach the end.
                count += 1
                j += 1
            # "count" now stores the number of occurrences of S[i]
            # When you make a choice for S[i], it is not just about exclude or include now
            # It is also about "how many times" to include ...
            for copies in range (0, count+1): # For each choice we make about how many "copies" of S[i] to include.
                for op in range (copies): # Append those many copies of S[i] to the slate
                    slate.append(S[i])
                helper(S, i+count, slate) # Delegate the rest of the work to a subordinate
                for op in range (copies): # After the subordinate comes back, undo the work done on the mutable slate
                    slate.pop()
                    
    helper(nums, 0, [])
    return result

A = [1, 1, 3, 1]
print(subsetsWithDup(A))
