//Time Complexity: O(n)
//Runtime: 0ms

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool isValid(std::string s) {
        std::vector<char> parentheses; // Vector to track opening parentheses

        for (char character : s) {
            if (std::string("([{").find(character) != std::string::npos) { // If character is an opening parenthesis
                parentheses.push_back(character); // Add it to the vector
            }
            else { // If character is a closing parenthesis
                if (parentheses.empty() || // If vector is empty or no matching opening parenthesis
                    (character == ')' && parentheses.back() != '(') ||
                    (character == '}' && parentheses.back() != '{') ||
                    (character == ']' && parentheses.back() != '[')) {
                    return false; // Invalid parentheses expression
                }
                parentheses.pop_back(); // Remove the matching opening parenthesis from the vector
            }
        }

        return parentheses.empty(); // Return true if the vector is empty (all parentheses matched)
    }
};
