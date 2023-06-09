// Time complexity: O(n^2)
// Runtime: 0ms

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};  // Return the indices of the two numbers that sum up to the target
                }
            }
        }
        return {};  // Return an empty vector if no solution is found
    }
};
