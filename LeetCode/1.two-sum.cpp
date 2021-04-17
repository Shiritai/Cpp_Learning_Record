/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
# include <utility>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto num1 = pair<int, int>(0, 0), num2 = pair<int, int>(0, 1);
        auto tmp = std::vector<int>(2);
        for (int h = 0; h < nums.size() - 1; ++h){
            num1.first = nums[h], num1.second = h;
            for (int i = h + 1; i < nums.size(); ++i){
                num2.first = nums[i], num2.second = i;
                if (num1.first + num2.first == target){
                    tmp[0] = num1.second, tmp[1] = num2.second;
                    return tmp;
                }
            }
        }   
        return tmp;
    }
};
// @lc code=end

