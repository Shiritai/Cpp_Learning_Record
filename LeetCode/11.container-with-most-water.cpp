/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
# define min(a, b) (((a) < (b)) ? (a) : (b))
class Solution {
public:
    int maxArea(vector<int>& height){
        int volumeTmp = 0, volumeMax = 0, dist = height.size() - 1;
        auto l = height.begin(), r = height.end();
        --r;
        /* 逐漸變窄 */
        while (dist != 0){
            volumeTmp = min(*l, *r) * dist;
            if (volumeTmp > volumeMax)
                volumeMax = volumeTmp;
            if (*r > *l)
                ++l;
            else
                --r;
            --dist;
        }
        return volumeMax;
    }
};
// @lc code=end

