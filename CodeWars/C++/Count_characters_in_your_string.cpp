/* 
 * Created by Eroiko at 2021/07/19
 */

# include <iostream>
# include <map>
# include <string>

std::map<char, unsigned> count(const std::string& string) {
    std::map<char, unsigned> res;
    for (int i = 0; i < (int) string.size(); ++i){
        auto add = res.insert({string[i], 1}); // 加入 pair, 用 {first, second} 自動建構, 若已存在, 返回 {剛元素迭代器, false}
        if (!add.second){ ++(add.first->second); }
    }
    return res;
}


/* 
 * 精彩解法節選
 * 這方法真的是 C++ 大師 OwO
 */
// #include <map>
// #include <string>

// std::map<char, unsigned> count(const std::string& string) {
//   std::map<char, unsigned> r;
//   for (const char& c: string) ++r[c];
//   return r;
// }


/* test */
int main(void){
    auto tmp = count("I am Eroiko, Meow!");
    for (auto i = tmp.begin(); i != tmp.end(); ++i){
        std::cout << i->first << "\t" << i->second << std::endl;
    }
}