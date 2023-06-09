//Time complexity: O(n)
//Runtime: 0ms


class Solution {
public:
    int romanToInt(string s) {
        vector<int> nums;
        int i = 0;
        while (i < s.size()) {
            if (i + 1 < s.size() && s.substr(i, 2) == "IV") {
                nums.push_back(4);
                i += 2;
            }
            else if (i + 1 < s.size() && s.substr(i, 2) == "IX") {
                nums.push_back(9);
                i += 2;
            }
            else if (i + 1 < s.size() && s.substr(i, 2) == "XL") {
                nums.push_back(40);
                i += 2;
            }
            else if (i + 1 < s.size() && s.substr(i, 2) == "XC") {
                nums.push_back(90);
                i += 2;
            }
            else if (i + 1 < s.size() && s.substr(i, 2) == "CD") {
                nums.push_back(400);
                i += 2;
            }
            else if (i + 1 < s.size() && s.substr(i, 2) == "CM") {
                nums.push_back(900);
                i += 2;
            }
            else if (s[i] == 'I') {
                nums.push_back(1);
                i += 1;
            }
            else if (s[i] == 'V') {
                nums.push_back(5);
                i += 1;
            }
            else if (s[i] == 'X') {
                nums.push_back(10);
                i += 1;
            }
            else if (s[i] == 'L') {
                nums.push_back(50);
                i += 1;
            }
            else if (s[i] == 'C') {
                nums.push_back(100);
                i += 1;
            }
            else if (s[i] == 'D') {
                nums.push_back(500);
                i += 1;
            }
            else if (s[i] == 'M') {
                nums.push_back(1000);
                i += 1;
            }
        }

        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        return sum;
    }
};
