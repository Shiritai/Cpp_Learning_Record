/* 
 * Created by Eroiko at 2021/07/20
 */

# include <iostream>
# include <cassert>
# include <vector>
# include <string>

class BigPositiveNum {
public:
    BigPositiveNum(int n){
        std::vector<bool> tmp;
        while (n > 0){
            tmp.push_back(n & 1);
            n >>= 1;    
        }
        num.bin = std::vector(tmp.rbegin(), tmp.rend());
    }

    std::string toBinString(){
        int size = num.bin.size();
        char res[size];
        res[size] = '\0';
        for (int i = 0; i < size; ++i)
            res[i] = num.bin[i] ? '1' : '0';
        return std::string(res);
    }

    std::string toDecString(){
        assert(num.bin[0]);
        std::string res = twosPowerToDecGen(num.bin.size()); // 最高位為基礎
        const int digit = res.size() + 1;
        for (int i = 1; i < size; ++i){ // traverse vector<bool> num
            if (num.bin[i]){
                std::string t = twosPowerToDecGen(digit - i - 1);
                std::string tmp = std::string(digit - t.size(), '0') + t;
                char chatArr[digit + 1];
                chatArr[digit] = '\0';
                for (int i = 0; i < digit; chatArr[i++] = '0'); // init
                for (int j = digit - 1; j >= 0; --j){ // do addition
                    int d = ((res.c_str()[j] - '0')) + ((tmp.c_str()[j] - '0'));
                    charArr[digit] += d % 10;
                    charArr[digit - 1] += d / 10;
                }
            }
        }
    }

// private:
    struct BigNum {
        std::vector<bool> bin;
    };
    BigNum num;

    std::string twosPowerToDecGen(int power){
        std::string res("1");
        /* 乘 power 次 */
        while (power-- > 0){
            /* 字串乘 2 */
            int digit = res.size() + 1; // 多留一位進位
            char tmp[digit + 1];
            tmp[digit] = '\0';
            for (int i = 0; i < digit; tmp[i++] = '0'); // init
            while (digit-- > 1){
                int d = ((res.c_str()[digit - 1] - '0') << 1);
                tmp[digit] += d % 10;
                tmp[digit - 1] += d / 10;
            }
            res = std::string((tmp[0] == '0') ? (tmp + 1) : tmp);
        }
        return res;
    }

    // std::string strAdder(std::string a, std::string b){

    // }

};

// std::string factorial(int factorial){

    

// }

int main(void){
    BigPositiveNum b(1);
    // std::cout << b.toBinString() << std::endl;
    // std::cout << b.twosPowerToDecGen(32) << std::endl;
}