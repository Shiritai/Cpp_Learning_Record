# include <stdio.h>

int main(void){
    char arr[9];
    arr[0] = '0';
    arr[8] = '\0';
    scanf("%s", (arr + 1));
    
    arr[1] += arr[3] - '0';
    arr[3] = arr[1];
    arr[2] += arr[2] - '0';
    
    arr[5] += arr[7] - '0';
    arr[7] = arr[5];
    arr[6] += arr[6] - '0';

    for (int i = 7; i > 0; --i){
        if (i != 4 && arr[i] > '9'){
            arr[i - 1 != 4 ? i - 1 : i - 2] += ((arr[i] - '0') / 10);
            arr[i] = (arr[i] - '0') % 10 + '0';
        }
    }

    printf("%s", (arr[0] == '0') ? (arr + 1) : arr);
}