//Time Complexity: O(n)
//Runtime 0ms

import java.util.ArrayList;
import java.util.List;

class Solution {
    public boolean isPalindrome(int x) {
        List<Character> num = new ArrayList<>(); // List to store individual digits

        String x_str = Integer.toString(x); // Convert integer to string
        for (char digit : x_str.toCharArray()) { // Iterate through each character in the string
            num.add(digit); // Add the digit to the list
        }

        int length = num.size(); // Store the length of the list

        List<Character> flipped_num = new ArrayList<>(); // List to store the reversed digits

        for (int i = 0; i < length; i++) { // Iterate through the original list in reverse order
            flipped_num.add(num.get(length - 1 - i)); // Add the reversed digit to the flipped_num list
        }

        for (int i = 0; i < num.size(); i++) { // Iterate through both lists
            if (num.get(i) != flipped_num.get(i)) { // If the corresponding digits don't match
                return false; // Not a palindrome, return false
            }
        }

        return true; // All digits match, it's a palindrome
    }
}
