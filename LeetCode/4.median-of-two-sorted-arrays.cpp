/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
# include <algorithm>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto nums = vector<int>();
        nums.insert(nums.end(), nums1.begin(), nums1.end());
        nums.insert(nums.end(), nums2.begin(), nums2.end());
        sort(nums.begin(), nums.end(), [](int i, int j){ return i < j; });
        int mid = nums.size() >> 1;
        if (nums.size() & 1){
            return double(nums[mid]);
        }
        return (mid == 0) ? double(nums[0]) : (nums[mid - 1] + nums[mid]) / 2.;
    }
};
// @lc code=end

