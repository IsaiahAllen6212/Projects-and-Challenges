#Time Complexity: O(log n)
#Runtime: 27ms

class Solution(object):
    def searchInsert(self, nums, target):
        for index in range(len(nums)):
            left = 0
            right = len(nums) - 1

            if target == nums[index]:
                return index  # Found the target element at the current index
            else:
                while left <= right:
                    mid = (left + right) // 2

                    if nums[mid] == target:
                        return mid  # Found the target element at the mid index
                    elif nums[mid] < target:
                        left = mid + 1  # Adjust the left pointer to search in the right half
                    else:
                        right = mid - 1  # Adjust the right pointer to search in the left half

                return left  # Target element not found, return the index where it should be inserted
