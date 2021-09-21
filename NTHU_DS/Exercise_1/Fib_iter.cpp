# include <iostream>

using namespace std;

# define NUM_TYPE long long

/* Time : O(n), Space : O(1) */
NUM_TYPE fib(int n){
    /* calculate */
    NUM_TYPE last1 = 1, last2 = 1;
    int cur = 1;
    while (++cur <= n){
        NUM_TYPE tmp = last1 + last2;
        last2 = last1;
        last1 = tmp;
    }
    return last1;
}

int main(void){
    int n;
    while (scanf("%d", &n) != EOF)
        cout << fib(n) << endl;
}