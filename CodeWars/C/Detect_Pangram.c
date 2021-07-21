/* 
 * Created by Eroiko at 2021/07/21
 */

# include <stdio.h>
# include <stdbool.h>

bool is_pangram(const char * str_in){
    int table[26], cnt = 0;
    for (int i = 0; i < 26; table[i++] = 0); // init table
    for (char * ptr = (char *) str_in; * ptr != '\0' && cnt < 26; ptr++){
        int ind = (* ptr >= 'a') ? * ptr - 'a' : * ptr - 'A';
        if (ind >= 26 || ind < 0) continue;
        if (!table[ind]){
            table[ind] = 1;
            ++cnt;
        }
    }
    return cnt == 26;
}

int main(void){
    printf("%d\n", is_pangram("The quick, brown fox jumped over the lazy dog!"));
}