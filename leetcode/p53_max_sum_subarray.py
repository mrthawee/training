def maxSubArray(nums):
    maxSum = curSum = nums[0]
    for i in range (1, len(nums)):
        curSum = max(nums[i], nums[i] + curSum)
        maxSum = max(curSum, maxSum)
        print('curSum=',curSum,'  maxSum=',maxSum)

    return maxSum

l = [-2,1,-3,4,-1,2,1,-5,4]

print(maxSubArray(l))
