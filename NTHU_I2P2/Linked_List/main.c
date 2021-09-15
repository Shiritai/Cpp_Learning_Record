# include "Linked_List.h"
# include <stdio.h>

# define STR_EXP(tok) #tok
# define STR(tok) STR_EXP(tok)
# define STR_LEN 100

int main(void){
    linked_list list;
    init_list(&list);
    int cmd;
    while (scanf("%d", &cmd) == 1){
        switch(cmd){
        case 0: // print
            print_list(&list);
            break;
        case 1: case 2: {
            // 最大接受 100 ASCII code 字串 --> 利用複合巨集
            printf("Push %s >>> ", cmd == 1 ? "Back" : "Front");
            char str[STR_LEN + 1];
            scanf("%" STR(STR_LEN) "s", str);
            if (cmd == 1)
                push_back(&list, str, strlen(str));
            else
                push_front(&list, str, strlen(str));
            break;
        }
        default:
            break;
            
        }
    }
}