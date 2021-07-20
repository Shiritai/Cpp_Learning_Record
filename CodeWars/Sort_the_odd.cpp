/* 
 * Created by Eroiko at 2021/07/19
 */

# include <vector>
# include <algorithm>

class Kata {
public:
    std::vector<int> sortArray(std::vector<int> array) {
        std::vector<int> kata;
        for (auto i = array.begin(); i != array.end(); ++i)
            if ((*i) & 1) kata.push_back(*i);
        std::sort(kata.begin(), kata.end());
        for (auto i = array.begin(), it = kata.begin(); it != kata.end(); ++i)
            if ((*i) & 1) *i = *it++;
        return array;
    }
};