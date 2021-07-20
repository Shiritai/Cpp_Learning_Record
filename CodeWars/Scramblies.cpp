/* 
 * Created by Eroiko at 2021/07/19
 */

# include <unordered_map>
# include <string>

bool scramble(const std::string& s1, const std::string& s2){
    std::unordered_map<char, unsigned> table;
    for (const char& c : s1) ++table[c];
    for (const char& c : s2){
        // if (!table[c]) return false;
        // else --table[c];
        /* 以上的更精簡寫法 */
        if (!(table[c]--)) return false;
    }
    return true;
}