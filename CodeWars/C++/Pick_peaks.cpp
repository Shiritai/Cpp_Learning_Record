/* 
 * Created by Eroiko at 2021/07/19
 */

# include <iostream>
# include <vector>

struct PeakData {
    std::vector<int> pos, peaks;
};

PeakData pick_peaks(std::vector<int> v) {
    if (v.size() < 3)
        return PeakData();
    PeakData result;
    int len = v.size();
    int right = 1;
    for (int i = 1; i < len - 1; i = right){
        while (right + 1 < len){
            ++right;
            if (v[right - 1] != v[right]) break;
        }
        if (v[i] > v[i - 1] && v[i] > v[right]){
            result.pos.push_back(i);
            result.peaks.push_back(v[i]);
        }
    }
    return result;
}

int main(void){
    auto tmp = pick_peaks({3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 3});
    // auto tmp = pick_peaks({1, 2, 2, 2, 1});
    // auto tmp = pick_peaks({});
    // auto tmp = pick_peaks({0, 1, 2, 5, 1, 0});
    for (int i = 0; i < (int) tmp.pos.size(); ++i) std::cout << tmp.pos[i] << "\t" << tmp.peaks[i] << std::endl;
}