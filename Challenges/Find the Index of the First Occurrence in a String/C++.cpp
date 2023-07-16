//Time Complexity: O(n)
//Runtime: 0ms

#include <iostream>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        // Use the built-in find method to search for the 'needle' in the 'haystack'
        size_t searching = haystack.find(needle);
        return static_cast<int>(searching);  // Return the index of the first occurrence of 'needle' in 'haystack'
    }
};

void testStrStr() {
    Solution solution;
    std::string haystack = "Hello, World!";
    std::string needle = "World";
    int result = solution.strStr(haystack, needle);
    std::cout << result << std::endl;  // Output: 7 (index of the first occurrence of "World" in "Hello, World!")
}

int main() {
    testStrStr();
    return 0;
}
