//Time complexity: O(n)
//Runtime: 0ms

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        std::vector<char> num; // Vector to store individual digits

        std::string x_str = std::to_string(x); // Convert integer to string
        for (char digit : x_str) {
            num.push_back(digit); // Add each digit to the vector
        }

        int length = num.size(); // Store the length of the vector

        std::vector<char> flipped_num; // Vector to store the reversed digits

        for(int i = 0; i < length; i++) {
            flipped_num.push_back(num[length-1-i]); // Add the reversed digit to the flipped_num vector
        }

        for(int i = 0; i < num.size(); i++) {
            if(num[i] != flipped_num[i]) { // If the corresponding digits don't match
                return false; // Not a palindrome, return false
            }
        }

        return true; // All digits match, it's a palindrome
    }
};
