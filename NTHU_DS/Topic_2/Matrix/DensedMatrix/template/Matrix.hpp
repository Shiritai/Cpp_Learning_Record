# ifndef _MATRIX_H
# define _MATRIX_H

# include <string>

template <typename T>
class Matrix {
public:
    /* Initialize a matrix with "val" */
    Matrix(int row, int col, T val);
    /* Initialize a matrix according to a 2-dimension array */
    Matrix(int row, int col, T * arr[]);
    /* Return a zero matrix */
    // static Matrix zero(int row, int col);
    /* Return a identity matrix */
    // static Matrix identity(int side_len);
    /* Return a matrix filled with "val" */
    // static Matrix fill(int row, int col, T val);
    void Transpose();
    Matrix operator+(const Matrix & other);
    Matrix operator*(const Matrix & other);
    std::string to_string();

private:
    Matrix(int row, int col); // 所有 matrix 內容都不會被初始化
    T ** matrix;
    int row, col;
};

# endif