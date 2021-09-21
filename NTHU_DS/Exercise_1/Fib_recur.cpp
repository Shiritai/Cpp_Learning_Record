# include <iostream>

typedef long long Number;

/* Time : O(2^n)), Space : O(2^n) */
Number fib(int n){
    if (n == 1 || n == 0)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main(void){
    int n;
    while (scanf("%d", &n) != EOF)
        printf("%lld\n", fib(n));
}