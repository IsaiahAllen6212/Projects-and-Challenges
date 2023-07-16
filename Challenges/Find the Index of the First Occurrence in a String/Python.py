#Time Complexity: O(n)
#Runtime: 67ms

class Solution(object):
    def strStr(self, haystack, needle):
        # Use the built-in `find` method to search for the `needle` in the `haystack`
        searching = haystack.find(needle)
        return searching  # Return the index of the first occurrence of `needle` in `haystack`


# Testing the code
solution = Solution()
haystack = "Hello, World!"
needle = "World"
result = solution.strStr(haystack, needle)
print(result)  # Output: 7 (index of the first occurrence of "World" in "Hello, World!")
