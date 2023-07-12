//Time Complexity: O(NM)
//Runtime: 11ms

import java.util.Arrays;

class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) {
            return "";  // Handle empty input list
        }

        String prefix = "";
        int letter = 0;
        int next_letter = 1;

        while (letter < strs[0].length()) {
            char common_letter = strs[0].charAt(letter);
            for (int i = 1; i < strs.length; i++) {
                if (letter >= strs[i].length() || strs[i].charAt(letter) != common_letter) {
                    return prefix;  // Return the common prefix if a difference is found
                }
            }
            prefix += common_letter;
            letter++;
        }

        return prefix;
    }
}
