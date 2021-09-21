# include <iostream>

using namespace std;

# define TABLE_LEN 50 // long long 裝得下的大小 : 91
typedef long long Number;

/* Time : O(n), Space : O(TABLE_LEN) */
Number fib(int n){
    /* init static variables */
    static Number table[TABLE_LEN];
    static int cur;
    static bool _has_init = false;
    if (!_has_init){
        for (int i = 0; i < TABLE_LEN; ++i) 
            table[i] = 0;
        _has_init = true;
        cur = 1;
        table[0] = table[1] = 1;
    }
    /* has value */
    if (n < TABLE_LEN && n <= cur)
        return table[n];
    /* calculate */
    Number last1 = table[cur], last2 = table[cur - 1], cur_val = 0;
    int cur_term = cur;
    while (++cur_term <= n){
        cur_val = last1 + last2;
        if (cur + 1 < TABLE_LEN)
            table[++cur] = cur_val;
        last2 = last1;
        last1 = cur_val;
    }
    return cur_val;
}

int main(void){
    int n;
    while (scanf("%d", &n) != EOF)
        cout << fib(n) << endl;
}