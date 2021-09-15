# include <stdio.h>

# define STR(tok) #tok

int main(void){
    printf(STR(Meow ) ", eroiko"); // 會接續印出!?
}