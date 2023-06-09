#Time complexity: O(n)
#Runtime: 28ms

class Solution(object):
    def romanToInt(self, s):
        nums = []
        i = 0
        while i < len(s):
            if i + 1 < len(s) and s[i:i+2] == 'IV':
                nums.append(4)
                i += 2
            elif i + 1 < len(s) and s[i:i+2] == 'IX':
                nums.append(9)
                i += 2
            elif i + 1 < len(s) and s[i:i+2] == 'XL':
                nums.append(40)
                i += 2
            elif i + 1 < len(s) and s[i:i+2] == 'XC':
                nums.append(90)
                i += 2
            elif i + 1 < len(s) and s[i:i+2] == 'CD':
                nums.append(400)
                i += 2
            elif i + 1 < len(s) and s[i:i+2] == 'CM':
                nums.append(900)
                i += 2
            elif s[i] == 'I':
                nums.append(1)
                i += 1
            elif s[i] == 'V':
                nums.append(5)
                i += 1
            elif s[i] == 'X':
                nums.append(10)
                i += 1
            elif s[i] == 'L':
                nums.append(50)
                i += 1
            elif s[i] == 'C':
                nums.append(100)
                i += 1
            elif s[i] == 'D':
                nums.append(500)
                i += 1
            elif s[i] == 'M':
                nums.append(1000)
                i += 1
        return sum(nums)
