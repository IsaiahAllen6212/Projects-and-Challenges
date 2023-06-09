# Time complexity: O(n^2)
# Runtime: 27ms

class Solution(object):
    def twoSum(self, nums, target):
        for x in range(len(nums)): #running a for loop with the range of nums
            if nums[x] + nums[x+1] == target:
                return x, x+1 #returns the sums seperately
