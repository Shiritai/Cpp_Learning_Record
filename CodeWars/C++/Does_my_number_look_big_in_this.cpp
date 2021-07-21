/* 
 * Created by Eroiko at 2021/07/20
 */

# include <iostream>
# include <vector>

bool narcissistic(int value){
    int digits = 0;
    std::vector<int> list;
    for (int i = value; i > 0; i /= 10, ++digits)
        list.push_back(i % 10);
    int sum = 0;
    for (auto i : list){
        int tmpCnt = 0, toAdd = 1;
        while (tmpCnt++ < digits) toAdd *= i;
        sum += toAdd;
        if (sum > value) return false;
    }
    return sum == value;
}

/* 
 * 優質程式碼節錄 (可以, 這很 C++)
 * #include <cmath>
 * #include <numeric>
 * bool narcissistic( int value ) {
 *     std::string sValue = std::to_string(value); // 用字串處理等於直接獲得位數長 + 各個位的值, 好方法
 *     return std::accumulate(sValue.begin(), sValue.end(), 0, [sValue](int x, char letter){ return x + pow(static_cast<int>(letter) - 48, sValue.length()); }) == value;
 * }
 */

int main(void){
    std::cout << narcissistic(7) << std::endl;
}