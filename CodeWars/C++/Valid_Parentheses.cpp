/* 
 * Created by Eroiko at 2021/07/20
 */

# include <stdio.h>
# include <stdbool.h>

bool validParentheses(const char *str_in) {
    int valid = 1; // 可從 0 開始, 但從 1 開始可簡化撰寫邏輯
    while (valid){
        if (* str_in == '(') ++valid;
        else if (* str_in == ')') --valid;
        else if (* str_in == '\0') return valid == 1;
        ++str_in;
    }
    return false;
}

/*
 * 我寫法的極限壓縮版
 * bool validParentheses(const char* p) {
 *     int n = 0;
 *     for (; *p; p++) if ((n += (*p == '(') - (*p == ')')) < 0) break; // 將左右括號判斷融為一式, 不過效率差不多
 *     return n == 0;
 * }
 */

int main(void){
    printf("%d\n", validParentheses("   ("));
}