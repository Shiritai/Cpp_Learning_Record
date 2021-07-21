/* 
 * Created by Eroiko at 2021/07/21
 */

# include <iostream>
# include <string>
# include <vector>

class Fracts
{

public:
    static std::string convertFrac(std::vector<std::vector<unsigned long long>> &lst){
        int size = lst.size();
        std::vector<unsigned long long> vc(size);
        for (int i = 0; i < size; ++i){
            vc[i] = lst[i][1];
        }
        unsigned long long l = lcm(vc);
        std::string l_str = "," + std::to_string(l) + ")";
        std::string ret = "";
        for (int i = 0; i < size; ++i){
            ret += "(" + std::to_string((l / lst[i][1]) * lst[i][0]) + l_str;
        }
        return ret;
    }


private:
    static unsigned long long gcd_loop(unsigned long long a, unsigned long long b){
        while (b != 0){
            unsigned long long tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }
    static unsigned long long lcm(const std::vector<unsigned long long> &vc){
        unsigned long long ret = 1;
        for (auto i : vc){ ret = (ret * i) / gcd_loop(ret, i); }
        return ret;
    }
};

int main(void){
    std::vector<std::vector<unsigned long long>> vc = {{1, 2}, {1, 3}, {1, 4}};
    std::cout << Fracts::convertFrac(vc) << std::endl;
}
