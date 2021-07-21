/* 
 * Created by Eroiko at 2021/07/22
 * 空間複雜度 O(1) 解法 OwO
 */

# include <stdio.h>
# include <stdbool.h>

bool validSolution(unsigned int board[9][9]){
    const int complete_mask = 0x000003fe;
    for (int i = 0; i < 9; ++i){
        int ver = 0, hor = 0, box = 0;
        for (int j = 0; j < 9; ++j){
            ver |= 1 << board[i][j];
            hor |= 1 << board[j][i];
            box |= 1 << board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3];
        }
        if (ver != complete_mask || hor != complete_mask || box != complete_mask)
            return false;
    }
    return true;
}

int main(void){
    unsigned int example1[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2}, 
                             {6, 7, 2, 1, 9, 5, 3, 4, 8},
                             {1, 9, 8, 3, 4, 2, 5, 6, 7},
                             {8, 5, 9, 7, 6, 1, 4, 2, 3},
                             {4, 2, 6, 8, 5, 3, 7, 9, 1},
                             {7, 1, 3, 9, 2, 4, 8, 5, 6},
                             {9, 6, 1, 5, 3, 7, 2, 8, 4},
                             {2, 8, 7, 4, 1, 9, 6, 3, 5},
                             {3, 4, 5, 2, 8, 6, 1, 7, 9}}; 

    unsigned int example2[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2}, 
                              {6, 7, 2, 1, 9, 0, 3, 4, 8},
                              {1, 0, 0, 3, 4, 2, 5, 6, 0},
                              {8, 5, 9, 7, 6, 1, 0, 2, 0},
                              {4, 2, 6, 8, 5, 3, 7, 9, 1},
                              {7, 1, 3, 9, 2, 4, 8, 5, 6},
                              {9, 0, 1, 5, 3, 7, 2, 1, 4},
                              {2, 8, 7, 4, 1, 9, 6, 3, 5},
                              {3, 0, 0, 4, 8, 1, 1, 7, 9}};

    printf("%d\n", validSolution(example1));
}