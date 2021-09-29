# include <iostream>
# include <string>

using namespace std;

int failure(string str, int fail_at){
    if (!str.length())
        throw "The string is empty, cannot build a failure function.";
    int list[fail_at];
    list[0] = -1;
    /* Fill the DP table, i.e. failure list */
    for (int i = 1; i <= fail_at; ++i){
        if (list[i - 1] == -1)
            list[i] = str[i] == str[0] ? 0 : -1; // 看是否與第一位相同
        else if (str[list[i - 1] + 1] == str[i]) // 接續前面的相同字串
            list[i] = list[i - 1] + 1;
        else // 都沒有相符的
            list[i] = -1;
    }
    return list[fail_at];
}

/* DP :)  Time : O(destination.length + pattern.length) */
int findSubstring(string destination, string pattern){
    int d_ind = 0, p_ind = 0, d_len = destination.length(), p_len = pattern.length();
    while (p_ind < p_len && d_ind < d_len){
        if (destination[d_ind] == pattern[p_ind]) // 匹配一個 char
            ++d_ind, ++p_ind; // 因此移動索引繼續比較
        else {
            if (!p_ind) // 先前從未匹配 pattern 的任一 char
                ++d_ind; // 因此 destination 直接向右移
            else 
                p_ind = failure(pattern, p_ind - 1) + 1; // 藉由 failure function 提升效率
        }
    }
    return p_ind >= p_len ? d_ind - p_len : -1;
}

int main(void){
    cout << findSubstring("I am Eroiko da!", "Eroiko") << endl;
    cout << findSubstring("I am abcabcax abcabcacab Eroiko da!", "abcabcacab") << endl;
    cout << findSubstring("I am Eroiko da!", "") << endl;
    cout << findSubstring("", "") << endl;
}