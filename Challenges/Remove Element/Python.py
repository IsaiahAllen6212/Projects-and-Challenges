#Time Complexity: O(n)
#Runtime: 22ms

class Solution(object):
    def removeElement(self, nums, val):
        # Iterate over the elements of `nums` in reverse order
        for i in reversed(nums):
            # Check if the current element is equal to `val`
            if i == val:
                # Remove the element from `nums`
                nums.remove(i)

        # Calculate the length of the modified `nums` list
        k = len(nums)
        # Return the length
        return k
