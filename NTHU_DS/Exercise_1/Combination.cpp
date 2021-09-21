# include <iostream>
# include <cstring>

typedef long long Number;

/** 
 * Use Dynamic Programming
 * Time : O(n * m)
 * Space : O(m)
 */
Number C(int n, int m){
    int len = n - m + 1;
    Number diamond[len];
    for (int i = 0; i < len; diamond[i++] = 1);
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j < len; ++j)
            diamond[j] += diamond[j - 1];
    return diamond[len - 1];
}

/** 
 * Normal numerical methid
 * Time : O(n - m)
 * Space : O(1)
 */
Number C_(int n, int m){
    Number res = 1;
    for (int i = 0; i < n - m; ++i)
        res *= (n - i);
    return res;
}

int main(void){
    int n, m;
    std::cin >> n >> m;
    std::cout << C(n, m) << std::endl;
}