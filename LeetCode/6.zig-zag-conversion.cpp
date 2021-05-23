/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
# include <string.h>
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        int size = s.length(), span = (numRows - 1) << 1;
        char str[size + 1], res[size + 1];
        strcpy(str, s.c_str());
        int resInd = 0;
        for (int i = 0; i <= span >> 1; ++i){
            int j = 0;
            while (i + j < size){
                res[resInd++] = str[i + j];
                if (i != 0 && i != span >> 1 && span - i + j < size)
                    res[resInd++] = str[span - i + j];
                j += span;
            }
        }
        res[resInd] = '\0';
        return string(res);
    }
};
// @lc code=end

