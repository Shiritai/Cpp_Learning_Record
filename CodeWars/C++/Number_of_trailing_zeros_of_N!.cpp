/* 
 * Created by Eroiko at 2021/07/20
 */

# include <iostream>

long zeros(long n) {
    int fives = 0;
    for (long i = 5l; i <= n; i *= 5l){
        fives += n / i;
    }
    return fives;
}

/*
 * 優質程式碼節錄, 算法部分一致
 * long zeros(long n) {
 *     long result = 0;
 *     while(n)
 *         result += n/=5;
 *     return result;
 * }
 */

int main(void){
    std::cout << zeros(30) << std::endl;
}