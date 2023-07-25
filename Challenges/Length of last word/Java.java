//Time Complexity: O(n)
//Runtime: 0 ms

class Solution {
    public int lengthOfLastWord(String s) {
        String stripped = s.trim(); // Strip leading and trailing whitespaces
        int count = 0;
        for (int i = stripped.length() - 1; i >= 0; i--) {
            char letter = stripped.charAt(i);
            if (letter != ' ') {
                count++;
            } else {
                break; // Exit the loop when a space is encountered
            }
        }
        return count;
    }
}
