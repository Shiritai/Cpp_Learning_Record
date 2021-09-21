typedef int Number;

/** 
 * 此題範例莫名其妙的存 1 開始...邪教 ?
 * Time : O(n^3)
 */
void matrix_mul(const Number ** A, const Number ** B, Number ** C, int n){
    for (int i = 0; i < n; ++i) // run n times each
        for (int j = 0; j < n; ++j) // (in this loop) run n times each, total : O(i) * n times
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) // (in this loop) run n times each, total : O(i) * O(j) * n times
                C[i][j] += A[i][k] * B[k][j];
}