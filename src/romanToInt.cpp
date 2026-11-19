#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        int result {0};
        int length = static_cast<int>(s.length());

        for (int i=0; i < length; i++) {
            int current = getValue(s[i]);
            if (i+1 < length && current < getValue(s[i+1])) {
                result -= current;
            } else {
                result += current;
            }

            // more of a brute force approach i used:
            // if (s[i] == 'I') {
            //     if (s[i+1] == 'V' || s[i+1] == 'X') {
            //         result += (romanNumerals.find(s[i+1])->second - romanNumerals.find(s[i])->second);
            //         i++;
            //     } else {
            //         result += romanNumerals.find(s[i])->second;
            //     }
            // } else if (s[i] == 'X') {
            //     if (s[i+1] == 'L' || s[i+1] == 'C') {
            //         result += (romanNumerals.find(s[i+1])->second - romanNumerals.find(s[i])->second);
            //         i++;
            //     } else {
            //         result += romanNumerals.find(s[i])->second;
            //     }
            // } else if (s[i] == 'C') {
            //     if (s[i+1] == 'D' || s[i+1] == 'M') {
            //         result += (romanNumerals.find(s[i+1])->second - romanNumerals.find(s[i])->second);
            //         i++;
            //     } else {
            //         result += romanNumerals.find(s[i])->second;
            //     }
            // } else {
            //     result += romanNumerals.find(s[i])->second;
            // }
        }

        return result;
    }
private:
    int getValue(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    // also i used std::unordered_map instead of a switch...
    // std::unordered_map<char, int> romanNumerals = {
    //         {'I', 1},
    //         {'V', 5},
    //         {'X', 10},
    //         {'L', 50},
    //         {'C', 100},
    //         {'D', 500},
    //         {'M', 1000},
    //     };
};

int main() {
    std::cout << "Starting program!\n";
    Solution s;
    std::string s1 {"III"}; // int 3
    std::cout << s1 << " should give 3: " << s.romanToInt(s1) << '\n';
    std::string s2 {"LVIII"}; // int 58
    std::cout << s2 << " should give 58: " << s.romanToInt(s2) << '\n';
    std::string s3 {"MCMXCIV"}; // int 1994
    std::cout << s3 << " should give 1994: " << s.romanToInt(s3) << '\n';
    std::cout << std::endl;
    std::cout << "Program finished!\n";
    return 0;
}