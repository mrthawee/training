def twoSum(nums, target):
    for i in range (0,len(nums)):
        for j in range (i+1,len(nums)):
            if nums[i] + nums[j] == target:
                return [nums[i], nums[j]]

def twoSum_v2(nums, target):
    pass
nums = [ 1, 5, 7, 10]
for n in nums:
    print(n)
target = 12
ret = twoSum(nums, target)
print(ret)
