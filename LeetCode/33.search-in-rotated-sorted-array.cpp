/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0)
            return -1;
        int maxInd;
        for (maxInd = 0; maxInd < size - 1; ++maxInd)
            if (nums[maxInd] > nums[maxInd + 1])
                break;
        int l, r;
        if (target < nums[0])
            l = maxInd + 1, r = size - 1;
        else if (target > nums[0])
            l = 0, r = maxInd;
        int mid = l + ((r - l) >> 2);
        while (nums[mid] != target){
            if (target < nums[mid])
                r = mid;
            else // target > min[mid >> 2]
                l = mid;
            mid = l + ((r - l) >> 2);
        }
        return (target == nums[mid]) ? mid : -1;
    }
};
// @lc code=end

