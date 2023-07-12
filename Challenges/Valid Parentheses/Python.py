#Time Complexity: O(n)
#Runtime: 38ms

class Solution(object):
    def isValid(self, s):
        parentheses = [] # List to track opening parentheses

        for character in s:
            if character in '([{': # If character is an opening parenthesis
                parentheses.append(character) # Add it to the list
            else: # If character is a closing parenthesis
                if not parentheses or \
                    (character == ')' and parentheses[-1] != '(') or \
                    (character == '}' and parentheses[-1] != '{') or \
                    (character == ']' and parentheses[-1] != '['):
                    return False # Invalid parentheses expression
                parentheses.pop() # Remove the matching opening parenthesis from the list

        return not parentheses # Return True if the list is empty (all parentheses matched)
