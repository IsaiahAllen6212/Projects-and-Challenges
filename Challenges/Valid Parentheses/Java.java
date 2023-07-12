// Time Complexity: O(n)
// Runtime: 0ms

import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        Stack<Character> parentheses = new Stack<>();

        for (char character : s.toCharArray()) {
            if ("([{".indexOf(character) != -1) { // If character is an opening parenthesis
                parentheses.push(character); // Push it onto the stack
            } else { // If character is a closing parenthesis
                if (parentheses.empty() || // If stack is empty or no matching opening parenthesis
                    (character == ')' && parentheses.peek() != '(') ||
                    (character == '}' && parentheses.peek() != '{') ||
                    (character == ']' && parentheses.peek() != '[')) {
                    return false; // Invalid parentheses expression
                }
                parentheses.pop(); // Pop the matching opening parenthesis from the stack
            }
        }

        return parentheses.empty(); // Return true if the stack is empty (all parentheses matched)
    }
}
