#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        for (int i = 0; i < (int)nums.size(); i++) {
            auto it = seen.find(target - nums[i]);
            if (it != seen.end()) return { it->second, i };
            seen[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    std::cout << "Starting program twoSum.cpp\n";
    Solution s;
    std::vector<int> nums = { 3, 7, 11, 6 };
    std::vector<int> r = s.twoSum(nums, 9);
    for (int x : r) std::cout << x << " ";
    std::cout << std::endl;
    std::cout << "program finished\n";
    return 0;
}