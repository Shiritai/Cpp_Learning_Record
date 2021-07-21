/* 
 * Created by Eroiko at 2021/07/19
 */

# include <iostream>
# include <string>
# include <vector>

class LongestConsec {
public:
    static std::string longestConsec(std::vector<std::string> &strarr, int k){
        int len = strarr.size();
        if (!len || len < k || k <= 0) return "";
        if (len == k){
            auto res = strarr[0];
            for (int i = 1; i < k; ++i) res += strarr[i];
            return res;
        }

        /* manually maintain a circular queue */
        std::vector<int> lenList(k);
        int deqIndex = 0;
        
        /* init */
        int value = 0;
        for (int i = 0, tmp = strarr[0].size(); i < k; ++i, tmp = strarr[i].size()){
            lenList[i] = tmp; // store basic elements (lengths)
            value += tmp;
        }

        /* traverse strarr to get the correct result index "resIndex" */
        int resIndex = k - 1; // the end of the target index in vector "strarr"
        int maxVal = value;
        for (int i = k; i < len; ++i){
            int l = strarr[i].size(); // length of the next string
            value += l - lenList[deqIndex];
            if (value > maxVal){ // update result index
                maxVal = value;
                resIndex = i;
            }
            /* update circular queue */
            lenList[deqIndex] = l; // add new value (string length)
            if (++deqIndex == k) deqIndex = 0; // move index
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
