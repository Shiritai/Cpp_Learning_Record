#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

int count_one(int val){
    int ret = 0;
    while (val){
        ret += val % 10 == 1;
        val /= 10;
    }
    return ret;
}

int main(void){
    int i = 0, n;
    cin >> n;
    unordered_map<int, int> dict;
    vector<pair<int, int>> res_list(n << 1);
    while (n-- > 0){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        res_list[i++] = pair<int, int>(tmp1, tmp2);
        dict.insert(pair<int, int>(tmp1, -1));
        dict.insert(pair<int, int>(tmp2, -1));
    }
    int max = -1;
    for (auto &m : dict)
        if (m.first > max)
            max = m.first;

    vector<pair<int, int>> happy_list;
    int key = 9, val = 1;
    while (key <= max){
        happy_list.push_back(pair<int, int>(key, val));
        val = val * 10 + key + 1;
        key = (key + 1) * 10 - 1;
    }
    // for (auto & p : happy_list)
    //     cout << p.first << ", " << p.second << endl;
    
    for (auto & p : dict){
        int tar = p.first, value = 0, inc = 0, mat_ind = 0;
        if (p.first > 9){
            /* 加速 */
            while (happy_list[mat_ind + 1].first < tar)
                ++mat_ind;
            inc = happy_list[mat_ind].first;
            value += happy_list[mat_ind].second;
            /* 老實爆開 */
            while (inc < tar)
                value += count_one(++inc);
            // cout << p.first << " --> " << value << endl;
            p.second = value;
        }
        else 
            p.second = 1;
    }
    for (int j = 0; j < i; ++j)
        cout << (dict[res_list[j].second] - dict[res_list[j].first] + 1) << endl;
}