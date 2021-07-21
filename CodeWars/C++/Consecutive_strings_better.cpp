/* 
 * Created by Eroiko at 2021/07/19
 * 此版省去不必要的站存循環隊列
 */

# include <iostream>
# include <string>
# include <vector>

class LongestConsec {
public:
    static std::string longestConsec(std::vector<std::string> &strarr, int k){
        int len = strarr.size();
        if (!len || len < k || k <= 0) return "";
        
        /* init */
        int value = 0;
        for (int i = 0; i < k; ++i) value += strarr[i].size();

        /* traverse strarr to get the correct result index : resIndex */
        int resIndex = k - 1; // the end of the target index in vector "strarr"
        int maxVal = value;
        for (int i = k; i < len; ++i){
            value += strarr[i].size() - strarr[i - k].size();
            if (value > maxVal){ // update result index
                maxVal = value;
                resIndex = i;
            }
        }
        /* transfer to result */
        std::string res = "";
        for (int i = resIndex - k + 1; i <= resIndex; ++i) res += strarr[i];
        return res;
    }
};

int main(void){
    std::vector<std::string> data;
    data.push_back("Meow"); // 4
    data.push_back("eroiko"); // 6
    data.push_back("hi"); // 2
    data.push_back("shiritai"); // 8
    std::cout << LongestConsec::longestConsec(data, 2) << std::endl;
}
