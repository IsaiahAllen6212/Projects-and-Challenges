//Time Complexity: O(log n)
//Runtime: 0ms

#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid; // Found the target element
            } else if (nums[mid] < target) {
                left = mid + 1; // Adjust the left pointer to search in the right half
            } else {
                right = mid - 1; // Adjust the right pointer to search in the left half
            }
        }

        return left; // Target element not found, return the index where it should be inserted
    }
};
