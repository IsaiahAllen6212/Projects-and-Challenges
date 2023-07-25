#Time Complexity: O(n)
#Runtime: 11ms

class Solution(object):
    def lengthOfLastWord(self, s):
        reverse = reversed(s.strip())  # Strip leading and trailing whitespaces
        count = 0
        for letter in reverse:
            if letter != " ":
                count += 1
            else:
                break  # Exit the loop when a space is encountered
        return count
