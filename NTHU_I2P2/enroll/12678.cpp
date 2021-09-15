#include <iostream>
#include <utility>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Counter {
public:
    Counter() : list_of_num() {
        has_changed = false;
    }
    void push_number_to_search(int num){
        has_changed = true;
        list_of_num[num] = -1;
    }
    int search(int from, int to){
        if (has_changed)
            __prepare_for_search();
        return __search(to) - __search(from) + 1;
    }
private:
    unordered_map<int, int> list_of_num;
    bool has_changed;
    /* 計算所有欲查詢數字之 1 的數量, 複雜度 O(value_of_the_biggest_number) */
    void __prepare_for_search(){
        int max = -1;
        for (auto n : list_of_num) if (n.first > max) max = n.first;
        __val(max);
    }
    int __search(int key){
        auto it = list_of_num.find(key);
        if (it != list_of_num.end())
            return list_of_num.find(key)->second;
        if (!list_of_num.size())
            cerr << "No number is ready for search!" << endl;
        else
            cerr << "Search with non-exist key!" << endl;
        return -1;
    }
    int __val(int input){
        if (!input)
            return 0;
        int ones = __count_one(input);
        int res = __val(input - 1) + ones;
        auto it = list_of_num.find(input);
        if (it != list_of_num.end())
            it->second = res;
        return res;
    }
    /* 返回該數字所含之 '1' */
    int __count_one(int number){
        auto str = to_string(number);
        int res = 0;
        for (int i = 0, len = str.length(); i < len; ++i)
            if (str[i] == '1')
                ++res;
        return res;
    }
};

int main(void){
    int n, n1, n2;
    Counter ctr;
    vector<pair<int, int>> rec_list;
    cin >> n;
    while (n-- > 0){
        cin >> n1 >> n2;
        ctr.push_number_to_search(n1);
        ctr.push_number_to_search(n2);
        rec_list.push_back(pair<int, int>(n1, n2));
    }
    for (auto & pr : rec_list)
        cout << ctr.search(pr.first, pr.second) << endl;
}