/* 
 * Created by Eroiko at 2021/07/19
 */

# include <iostream>
# include <vector>

std::vector<int> move_zeroes(const std::vector<int>& input) {
    std::vector<int> res(input.size(), 0);
    int tmpInd = 0;
    for (auto i : input)
        if(i) res[tmpInd++] = i;
    return res;
}

int main(void){
    std::vector<int> tmp{1, 0, 1, 2, 0, 1, 3};
    auto eroiko = move_zeroes(tmp);
    for (int i = 0; i < (int) eroiko.size(); ++i)
        std::cout << eroiko[i] << std::endl;
}