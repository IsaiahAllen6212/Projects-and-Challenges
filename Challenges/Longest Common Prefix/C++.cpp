//Time Complexity: O(NM)
//Runtime: 3ms

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";  // Handle empty input list
        }

        string prefix = "";
        int letter = 0;
        int next_letter = 1;

        while (letter < strs[0].length()) {
            char common_letter = strs[0][letter];
            for (int i = 1; i < strs.size(); i++) {
                if (letter >= strs[i].length() || strs[i][letter] != common_letter) {
                    return prefix;  // Return the common prefix if a difference is found
                }
            }
            prefix += common_letter;
            letter++;
        }

        return prefix;
    }
};
