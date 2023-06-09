// Time complexity: O(n) where n is the length of the input string s
// Runtime: 0ms

class Solution {
public:
    int romanToInt(string s) {
        vector<int> nums; // Store the integer values corresponding to each Roman numeral
        int i = 0;
        while (i < s.size()) {
            if (i + 1 < s.size() && s.substr(i, 2) == "IV") { // Check for "IV" (4)
                nums.push_back(4);
                i += 2;
            }
            else if (i + 1 < s.size() && s.substr(i, 2) == "IX") { // Check for "IX" (9)
                nums.push_back(9);
                i += 2;
            }
            else if (i + 1 < s.size() && s.substr(i, 2) == "XL") { // Check for "XL" (40)
                nums.push_back(40);
                i += 2;
            }
            else if (i + 1 < s.size() && s.substr(i, 2) == "XC") { // Check for "XC" (90)
                nums.push_back(90);
                i += 2;
            }
            else if (i + 1 < s.size() && s.substr(i, 2) == "CD") { // Check for "CD" (400)
                nums.push_back(400);
                i += 2;
            }
            else if (i + 1 < s.size() && s.substr(i, 2) == "CM") { // Check for "CM" (900)
                nums.push_back(900);
                i += 2;
            }
            else if (s[i] == 'I') { // Check for "I" (1)
                nums.push_back(1);
                i += 1;
            }
            else if (s[i] == 'V') { // Check for "V" (5)
                nums.push_back(5);
                i += 1;
            }
            else if (s[i] == 'X') { // Check for "X" (10)
                nums.push_back(10);
                i += 1;
            }
            else if (s[i] == 'L') { // Check for "L" (50)
                nums.push_back(50);
                i += 1;
            }
            else if (s[i] == 'C') { // Check for "C" (100)
                nums.push_back(100);
                i += 1;
            }
            else if (s[i] == 'D') { // Check for "D" (500)
                nums.push_back(500);
                i += 1;
            }
            else if (s[i] == 'M') { // Check for "M" (1000)
                nums.push_back(1000);
                i += 1;
            }
        }

        int sum = 0;
        for (int num : nums) { // Calculate the sum of all the integer values
            sum += num;
        }

        return sum; // Return the final sum
    }
};
