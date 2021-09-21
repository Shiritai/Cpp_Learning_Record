#include <stdio.h>

#define LEN 1000001

int main(){
    static int list[LEN];
    list[0] = 0;
    for (int i = 1; i < LEN; ++i){`
        list[i] = list[i - 1];
        for (int j = i; j; j /= 10)
            list[i] += (j % 10 == 1);
    }
    int n, a, b;
    scanf("%d", &n);
    while (n--){
        scanf("%d%d", &a, &b);
        printf("%d\n", list[b] - list[a] + 1);
    }
}