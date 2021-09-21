# Exercise Ch.2 : Array

## Q1

|$Pattern$| 1  | 1  | 1  | 0  | 1  | 1  | 0  | 1  |
|---|---|---|---|---|---|---|---|---|
|$Failure Func$| -1  | 0  | 1  | -1  | 0  | 1  | -1  | 0  |

```C++
# include <string>

using namespace std;

int failure(string str, int fail_at){
    if (!str.length())
        throw "Cannot build a failure function for an empty string.";
    int list[fail_at];
    list[0] = -1;
    /* Fill the DP table, i.e. failure list */
    for (int i = 1; i <= fail_at; ++i){
        if (list[i - 1] == -1)
            list[i] = str[i] == str[0] ? 0 : -1; // 看是否與第一位相同
        else if (str[list[i - 1] + 1] == str[i]) // 接續前面的相同字串
            list[i] = list[i - 1] + 1;
        else // 都沒有相符的
            list[i] = -1;
    }
    return list[fail_at];
}
```

Time Complexity : $O(fail\_at)$, 若要求出整個 pattern 之 failure function 就是 $O(pattern.length)$

## Q2

複雜度分析, 除首項為空間複雜度外, 其餘皆時間複雜度ㄡ

||Sparse|Dense|
|---|---|---|
|Basic Space|$O(terms)$ :crown:|$O(degree)$|
|Subscript<br>*get coefficient*|$O(log(n))$<br>*binary search*|$O(1)$ :crown:|
|Traverse|$O(terms)$ :crown:|$O(degree)$|
|Add term|$O(terms)$ :crown:|$O(degree)$|
|Addition|$O(terms1 + terms2)$ :crown:|$O(degree1 + degree2)$|
|Multiplication|$O(terms1 + terms2)$ :crown:|$O(degree1 + degree2)$|
|Implementation Complexity|hard|easy :crown:|

## Q3

1. both $O(n^3)$
2. method 2 should be faster
    - 因為 C/C++ 連續索引存取時, 由於 Cache 的技術加持, 會比非連續存取快
    - 當非連續的間隔越大 (也就是 n 越大), 差異越顯著

## Q4

1. Write Array A
    ```C++
    /* {row, col, value} */
    SparseMatrix A : {{0, 1, 4}, {1, 1, 5}, {2, 0, 6}}
    ```
2. Write array stores the counting
    ```C++
    rowSize : {1, 2, 0};
    rowStart : {0, 1, 2 /* 2 = end_of_array */ };
    ```
3. Write Array $A^T$
    ```C++
    SparseMatrix A_T = {{0, 2, 6}, {1, 0, 4}, {1, 1, 5}}
    ```

## Q5

1. A sparse matrix is a matrix that only store the values which are non-zero terms
2. Memory requirement

    > 注意後者每一項都乘以三是因為 Sparse Matrix 單個元素需要三個項目才能儲存

    |   |2D Array   |SparseMatrix   |
    |---|---|---|
    |$\left[\begin{matrix}2 & 0 & 4\\6 & 7 & 33\\5 & 0 & -2\end{matrix}\right]$   |$9$ :crown:|$7 * 3$|
    |$\left[\begin{matrix}a & b & c & d & e\\f & g & h & i & j\\k & l & m & n & o\\p & q & r & s & t\end{matrix}\right]$<br><font size=2>where a ~ t are non-zero elements</font>|$20$ ::crown |$20 * 3$|
    |2000 * 2000<br>with 200 non-zero elements|$4000000$|$200 * 3$ :crown:|

## Q6

1. 當很非零稀疏的時候 (即很多 0 時)...這不是廢話嗎
2. $\left[\begin{matrix}1 & 0 & 3 & 0 & 1\\0 & 0 & 0 & 1 & 0\\0 & 0 & 1 & 0 & 0\\0 & 0 & 0 & 1 & 1\end{matrix}\right]$

    ```C++
    {0, 0, 1}, {0, 2, 3}, {0, 4, 1}, \
    {1, 3, 1}, {2, 2, 1}, {3, 3, 1}, {3, 4, 1}
    ```

## Q7 

> 想為 DP 之 Matrix Multiplication Determination 鋪路吼

單次矩陣乘法的複雜度是 $O(row1 * col1 * col2)$, 假設 $row1 == col2$ (如此一來兩個矩陣可以互乘), 則複雜度就由「$col1$ 是否為叫大值」決定。

設 $M_1 : 4 * 64$, $M_2 : 64 * 4$, 則:

1. $M_1 * M_2\rArr 4^2 * 64$
2. $M_2 * M_1\rArr 64^2 * 4$

由此可見複雜度大相逕庭。

## Q8

1. Row-major : $40 * m + 50$
2. Column-major : $40 + 50 * n$