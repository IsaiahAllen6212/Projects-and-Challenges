//Time complexity: O(n)
//Runtime: 0ms

import java.util.*;

class Solution {
    public int romanToInt(String s) {
        List<Integer> nums = new ArrayList<>();
        int i = 0;
        while (i < s.length()) {
            if (i + 1 < s.length() && s.substring(i, i + 2).equals("IV")) {
                nums.add(4);
                i += 2;
            } else if (i + 1 < s.length() && s.substring(i, i + 2).equals("IX")) {
                nums.add(9);
                i += 2;
            } else if (i + 1 < s.length() && s.substring(i, i + 2).equals("XL")) {
                nums.add(40);
                i += 2;
            } else if (i + 1 < s.length() && s.substring(i, i + 2).equals("XC")) {
                nums.add(90);
                i += 2;
            } else if (i + 1 < s.length() && s.substring(i, i + 2).equals("CD")) {
                nums.add(400);
                i += 2;
            } else if (i + 1 < s.length() && s.substring(i, i + 2).equals("CM")) {
                nums.add(900);
                i += 2;
            } else if (s.charAt(i) == 'I') {
                nums.add(1);
                i += 1;
            } else if (s.charAt(i) == 'V') {
                nums.add(5);
                i += 1;
            } else if (s.charAt(i) == 'X') {
                nums.add(10);
                i += 1;
            } else if (s.charAt(i) == 'L') {
                nums.add(50);
                i += 1;
            } else if (s.charAt(i) == 'C') {
                nums.add(100);
                i += 1;
            } else if (s.charAt(i) == 'D') {
                nums.add(500);
                i += 1;
            } else if (s.charAt(i) == 'M') {
                nums.add(1000);
                i += 1;
            }
        }

        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        return sum;
    }
}
