# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define STR_LEN 1024
# define STR_NUM 100

int comp(const void * _a, const void * _b){
    char * a = (char *) _a, * b = (char *) _b;
    int len = strlen(a) + strlen(b) + 1;
    char str1[len], str2[len];
    sprintf(str1, "%s%s", a, b);
    sprintf(str2, "%s%s", b, a);
    return strcmp(str2, str1);
}

int main(void){
    int n;
    char nums[STR_NUM][STR_LEN];
    while (scanf("%d", &n) != EOF){
        for (int i = 0; i < n; ++i)
            scanf("%s", nums[i]);
        qsort(nums, n, sizeof(nums[0]), comp);
        for (int _ = 0; _ < n; ++_)
            printf("%s", nums[_]);
        puts("");
    }
}