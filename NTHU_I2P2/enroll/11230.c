#include <stdio.h>

enum PROPERTY {
    EMPTY, QUEEN, ROCK
};

static char board[10][10];
static _Bool v_av[11], h_av[10];
static int length, cnt;

void __print(int x_ind, int y_ind){
    printf("at : (%d, %d)\n", x_ind, y_ind);
    for (int i = 0; i < length; ++i){
        for (int j = 0; j < length; ++j){
            if (board[i][j] == QUEEN)
                putchar('Q');
            else if (board[i][j] == ROCK)
                putchar('R');
            else 
                putchar(' ');
        }
        puts("");
    }
    puts("--------");
}

void place_chess(int q, int r, int x_ind, int y_ind){
    if (v_av[x_ind] && h_av[y_ind]){
        _Bool av = 1, has_rock = 0;
        for (int i = 0; i < length && av; ++i){
            char tmp1 = board[(x_ind + i) % length][(y_ind + i) % length];
            char tmp2 = board[(x_ind + i) % length][(length + y_ind - i) % length];
            if (tmp1 == QUEEN || tmp2 == QUEEN)
                av = 0;
            if (tmp1 == ROCK || tmp2 == ROCK)
                has_rock = 1;
        }
        if (av){ // 可放子
            if (q && !has_rock){ // 放 QUEEN
                board[x_ind][y_ind] = QUEEN;
                v_av[x_ind] = h_av[y_ind] = 0;
                if (!(q - 1) && !r)
                    ++cnt;
                else if (x_ind + 1 != length)
                    place_chess(q - 1, r, x_ind + 1, 0);
                board[x_ind][y_ind] = EMPTY;
                v_av[x_ind] = h_av[y_ind] = 1;
            }   
            if (r){ // 放 ROCK
                board[x_ind][y_ind] = ROCK;
                v_av[x_ind] = h_av[y_ind] = 0;
                if (!(r - 1) && !q)
                    ++cnt;
                else if (x_ind + 1 != length)
                    place_chess(q, r - 1, x_ind + 1, 0);
                board[x_ind][y_ind] = EMPTY;
                v_av[x_ind] = h_av[y_ind] = 1;
            }
        }
    }
    if (q || r){
        if (y_ind + 1 != length)
            place_chess(q, r, x_ind, y_ind + 1);
        else if (x_ind + 1 != length)
            place_chess(q, r, x_ind + 1, 0);
    }
}

int main(void){
    int q, r;
    scanf("%d%d", &q, &r);
    length = q + r;
    cnt = 0;

    for (int _ = 0; _ < length; ++_){
        for (int __ = 0; __ < length; board[_][__++] = EMPTY);
        v_av[_] = h_av[_] = 1; // 一開始都 available
    }

    place_chess(q, r, 0, 0);
    printf("%d\n", cnt);
}