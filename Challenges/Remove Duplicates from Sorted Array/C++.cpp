//Time Complexity: O(n)
//Runtime: 67ms

#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        int k = 1; // Variable to keep track of the unique elements
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        nums.erase(nums.begin() + k, nums.end()); // Remove the remaining elements after the unique elements
        return nums.size();
    }
};
