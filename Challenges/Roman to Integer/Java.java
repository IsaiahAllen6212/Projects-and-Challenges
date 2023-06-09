// Time complexity: O(n) where n is the length of the input string s
// Runtime: 0ms

import java.util.*;

class Solution {
    public int romanToInt(String s) {
        List<Integer> nums = new ArrayList<>(); // Store the integer values corresponding to each Roman numeral
        int i = 0;
        while (i < s.length()) {
            if (i + 1 < s.length() && s.substring(i, i + 2).equals("IV")) { // Check for "IV" (4)
                nums.add(4);
                i += 2;
            } else if (i + 1 < s.length() && s.substring(i, i + 2).equals("IX")) { // Check for "IX" (9)
                nums.add(9);
                i += 2;
            } else if (i + 1 < s.length() && s.substring(i, i + 2).equals("XL")) { // Check for "XL" (40)
                nums.add(40);
                i += 2;
            } else if (i + 1 < s.length() && s.substring(i, i + 2).equals("XC")) { // Check for "XC" (90)
                nums.add(90);
                i += 2;
            } else if (i + 1 < s.length() && s.substring(i, i + 2).equals("CD")) { // Check for "CD" (400)
                nums.add(400);
                i += 2;
            } else if (i + 1 < s.length() && s.substring(i, i + 2).equals("CM")) { // Check for "CM" (900)
                nums.add(900);
                i += 2;
            } else if (s.charAt(i) == 'I') { // Check for "I" (1)
                nums.add(1);
                i += 1;
            } else if (s.charAt(i) == 'V') { // Check for "V" (5)
                nums.add(5);
                i += 1;
            } else if (s.charAt(i) == 'X') { // Check for "X" (10)
                nums.add(10);
                i += 1;
            } else if (s.charAt(i) == 'L') { // Check for "L" (50)
                nums.add(50);
                i += 1;
            } else if (s.charAt(i) == 'C') { // Check for "C" (100)
                nums.add(100);
                i += 1;
            } else if (s.charAt(i) == 'D') { // Check for "D" (500)
                nums.add(500);
                i += 1;
            } else if (s.charAt(i) == 'M') { // Check for "M" (1000)
                nums.add(1000);
                i += 1;
            }
        }

        int sum = 0;
        for (int num : nums) { // Calculate the sum of all the integer values
            sum += num;
        }

        return sum; // Return the final sum
    }
}
