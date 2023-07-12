#Time Complexity: O(NM)
#Runtime: 12ms

class Solution(object):
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""  # Handle empty input list

        prefix = ""
        letter = 0
        next_letter = 1

        while letter < len(strs[0]):
            common_letter = strs[0][letter]
            for word in strs[1:]:
                if letter >= len(word) or word[letter] != common_letter:
                    return prefix  # Return the common prefix if a difference is found
            prefix += common_letter
            letter += 1

        return prefix
