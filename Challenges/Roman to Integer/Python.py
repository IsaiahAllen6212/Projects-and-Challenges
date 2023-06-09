# Time complexity: O(n) where n is the length of the input string s
# Runtime: 28ms

class Solution(object):
    def romanToInt(self, s):
        nums = []  # Store the integer values corresponding to each Roman numeral
        i = 0
        while i < len(s):
            if i + 1 < len(s) and s[i:i+2] == 'IV':  # Check for "IV" (4)
                nums.append(4)
                i += 2
            elif i + 1 < len(s) and s[i:i+2] == 'IX':  # Check for "IX" (9)
                nums.append(9)
                i += 2
            elif i + 1 < len(s) and s[i:i+2] == 'XL':  # Check for "XL" (40)
                nums.append(40)
                i += 2
            elif i + 1 < len(s) and s[i:i+2] == 'XC':  # Check for "XC" (90)
                nums.append(90)
                i += 2
            elif i + 1 < len(s) and s[i:i+2] == 'CD':  # Check for "CD" (400)
                nums.append(400)
                i += 2
            elif i + 1 < len(s) and s[i:i+2] == 'CM':  # Check for "CM" (900)
                nums.append(900)
                i += 2
            elif s[i] == 'I':  # Check for "I" (1)
                nums.append(1)
                i += 1
            elif s[i] == 'V':  # Check for "V" (5)
                nums.append(5)
                i += 1
            elif s[i] == 'X':  # Check for "X" (10)
                nums.append(10)
                i += 1
            elif s[i] == 'L':  # Check for "L" (50)
                nums.append(50)
                i += 1
            elif s[i] == 'C':  # Check for "C" (100)
                nums.append(100)
                i += 1
            elif s[i] == 'D':  # Check for "D" (500)
                nums.append(500)
                i += 1
            elif s[i] == 'M':  # Check for "M" (1000)
                nums.append(1000)
                i += 1
        return sum(nums)  # Return the sum of all the integer values
