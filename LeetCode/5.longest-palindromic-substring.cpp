/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
# include <string.h>
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.length(), most = -1;
        if (size == 1)
            return s;
        char str[size + 1];
        bool isPalindrome = false;
        strcpy(str, s.c_str());
        int start = -1, end = -1;
        for (int i = 0; i < size; i++){
            for (int j = size - 1; j >= i && j - i > most; --j){
                if (str[i] == str[j]){
                    isPalindrome = true;
                    for (int k = 1; k <= (j - i) / 2; ++k){
                        if (str[i + k] != str[j - k]){
                            isPalindrome = false;
                            break;
                        }
                    }
                    if (isPalindrome && most < j - i){
                        most = j - i;
                        start = i;
                        end = j;
                    }
                }
            }
        }
        char res[most + 3];
        int j = 0;
        for (int i = start; i <= end; ++i, ++j)
            res[j] = str[i];
        res[j] = '\0';
        return string(res);
    }
};
// @lc code=end