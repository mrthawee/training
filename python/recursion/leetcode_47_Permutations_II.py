def permuteUnique(nums):
    """
    :type nums: List[int]
    :rtype: List[List[int]]
    """

    result = []

    # Immutable parameters
    def helper(arr, i):
        # arr[0..i-1] is the partial solution so far
        # arr[i..n-1] is the subproblem definition
        if i == len(arr):
            result.append(arr[:])
        else:
            hmap = {}
            for pick in range (i, len(arr)):
                print("arr[pick]=", arr[pick])
                if arr[pick] not in hmap:
                    print("Yah! hmap = ", hmap)
                    # Pick the number at index i
                    hmap[arr[pick]] = 1
                    arr[pick], arr[i] = arr[i], arr[pick]
                    helper(arr, i+1)
                    arr[pick], arr[i] = arr[i], arr[pick]
                else:
                    print("Nope! hmap = ", hmap)
            print("hmap=", hmap, "  result=", result)

    helper(nums, 0)
    return result

#nums = [1,1,2]
nums = [1,2,3]

print(permuteUnique(nums))
