//Time Complexity: O(n)
//Runtime: 4 ms

#include <algorithm>
#include <iostream>
#include <string>

class Solution {
private:
    void strip(std::string& s) {
        size_t firstNonSpace = s.find_first_not_of(' ');
        size_t lastNonSpace = s.find_last_not_of(' ');
        s = s.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
    }


public:
    int lengthOfLastWord(std::string s) {
        std::reverse(s.begin(), s.end());
        strip(s);
        int count = 0;
        for (int letter = 0; letter < s.size(); letter++) {
            if (s[letter] != ' ') {
                count += 1;
            } else {
                break;
            }
        }
        return count;
    }
};
