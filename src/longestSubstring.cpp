// problem # 3: Longest Substring Without Repeating Characters
#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

/* brute force solution 
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> charsInSub {};
        int longest {0};
        int sLength { static_cast<int>(s.length()) };
        int maxLength { sLength };

        if (sLength == 1) return 1;
        if (sLength > 100) maxLength = 100;

        for (int i {0}; i < sLength; i++) {
            for (int j {i}; j < std::min(sLength, maxLength + i); j++) {
                if (charsInSub.count(s[j]) == 0) charsInSub.insert(s[j]);
                else {
                    break;
                }
            }

            int thisLength { static_cast<int>(charsInSub.size()) };
            if (longest < thisLength) longest = thisLength;
            charsInSub.clear();
        }

        return longest;
    }
};
*/

// sliding window solution
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> window {};
        int longest {0};
        int left {0};
        int sLength { static_cast<int>(s.length()) };
        int maxLength { sLength > 100 ? 100 : sLength };

        if (sLength == 1) return 1;

        for (int right {0}; right < std::min((left + maxLength), sLength); right++) {
            while (window.count(s[right]) > 0) {
                window.erase(s[left]);
                ++left;
            }
            window.insert(s[right]);
            longest = std::max(longest, right - left + 1);
        }

        return longest;
    }
};

int main() {
    std::string s1 {"abcabcbb"};
    std::string s2 {"bbbbb"};
    std::string s3 {"pwwkew"};
    std::string s4 {"S"};
    std::string s5 {"OXVM.R#x~\\\"wj7x@`pxUNj!B/qg[]2$c0g6d>l%)l&pW9Tw(+t6@@?QU-wyQN!Sozb:d<G`E?Ozf'TCFl}-*i:|iM\\\\HT|`6-k4h: vru},9^no~N|p/>;7rgC7"};

    Solution s;

    std::cout << s1 << " longest substring length (3) is: " << s.lengthOfLongestSubstring(s1) << '\n';
    std::cout << s3 << " longest substring length (1) is: " << s.lengthOfLongestSubstring(s2) << '\n';
    std::cout << s3 << " longest substring length (3) is: " << s.lengthOfLongestSubstring(s3) << '\n';
    std::cout << s4 << " longest substring length (1) is: " << s.lengthOfLongestSubstring(s4) << '\n';
    std::cout << s5 << " longest substring length (25) is: " << s.lengthOfLongestSubstring(s5) << '\n';
    
    return 0;
}