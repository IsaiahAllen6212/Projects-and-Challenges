# Time complexity: O(n)
# Runtime: 32 ms

class Solution(object):
    def isPalindrome(self, x):
        # Convert the input number to a list of digits
        num = []
        for integer in str(x):
            num.append(integer)

        # Initialize an empty list to store the reversed number
        flipped_Num = []

        # Calculate the length of the input number
        length = len(str(x))

        # Reverse the digits of the input number
        for integer in range(length):
            flipped_Num.append(num[length - 1])
            length = length - 1

        # Check if the original number and the reversed number are equal
        if num == flipped_Num:
            return True
        else:
            return False
