class Solution(object):
    def twoSum(self, nums, target):
        for x in range(len(nums)):
            if nums[x] + nums[x+1] == target:
                return x,x+1
