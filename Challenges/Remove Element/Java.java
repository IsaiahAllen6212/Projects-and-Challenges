//Time Complexity: O(n)
//Runtime: 0ms

class Solution {
    public int removeElement(int[] nums, int val) {
        // Initialize a left pointer
        int left = 0;

        // Iterate over the elements of `nums` using a right pointer
        for (int right = 0; right < nums.length; right++) {
            // Check if the current element is not equal to `val`
            if (nums[right] != val) {
                // Overwrite the value at `left` with the current non-matching element
                nums[left] = nums[right];
                // Move the left pointer to the next position
                left++;
            }
        }

        // Calculate the length of the modified `nums` list
        int k = left;
        // Return the length
        return k;
    }
}
