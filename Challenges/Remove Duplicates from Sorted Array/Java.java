//Time Complexity: O(n)
//Runtime: 67ms

import java.util.List;

class Solution {
    public int removeDuplicates(List<Integer> nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        int k = 1; // Variable to keep track of the unique elements
        for (int i = 1; i < nums.size(); i++) {
            if (!nums.get(i).equals(nums.get(i-1))) {
                nums.set(k, nums.get(i));
                k++;
            }
        }

        nums.subList(k, nums.size()).clear(); // Remove the remaining elements after the unique elements
        return nums.size();
    }
}
