#Time Complexity: O(n)
#Runtime: 67ms

class Solution(object):
    def removeDuplicates(self, nums):
        if len(nums) <= 1:
            return len(nums)

        k = 1  # Variable to keep track of the unique elements
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]:
                nums[k] = nums[i]
                k += 1

        del nums[k:]  # Remove the remaining elements after the unique elements
        return len(nums)
