//Time Complexity; O(n)
// Runtime: 0ms

public class Solution {
    public int strStr(String haystack, String needle) {
        // Use the built-in indexOf method to search for the 'needle' in the 'haystack'
        int searching = haystack.indexOf(needle);
        return searching;  // Return the index of the first occurrence of 'needle' in 'haystack'
    }

    public void testStrStr() {
        String haystack = "Hello, World!";
        String needle = "World";
        int result = strStr(haystack, needle);
        System.out.println(result);  // Output: 7 (index of the first occurrence of "World" in "Hello, World!")
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.testStrStr();
    }
}
