# include "Matrix.hpp"

# define __TPL template <typename T>

# include <iostream>
__TPL
Matrix<T>::Matrix(int row, int col): row(row), col(col){
    std::cout << "init\n";
    matrix = new T*[row];
    for (int i = 0; i < row; ++i)
        matrix[i] = new T [col];
}

__TPL
Matrix<T>::Matrix(int row, int col, T val){
    Matrix<T>::Matrix(row, col);
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            matrix[i][j] = val;
}

__TPL
Matrix<T>::Matrix(int row, int col, T * arr[]){
    Matrix<T>::Matrix(row, col);
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            matrix[i][j] = arr[i][j];
}

// __TPL
// static Matrix<T> Matrix<T>::zero(int row, int col){
//     Matrix<T> ret(row, col, 0);
//     return ret;
// }

// __TPL
// static Matrix<T> Matrix<T>::identity(int len){
//     Matrix<T> ret(row, col, 0);
//     for (int i = 0; i < len; ++i)
//         ret.matrix[i][i] = 1;
//     return ret;
// }

// __TPL
// static Matrix<T> Matrix<T>::fill(int row, int col, T val){
//     Matrix<T> ret(row, col, val);
//     return ret;
// }

__TPL
void Matrix<T>::Transpose(){
    T ** n_mat = new T*[col];
    for (int i = 0; i < col; ++i){
        n_mat[i] = new T[row];
        for (int j = 0; j < row; ++j)
            n_mat[i][j] = matrix[j][i];
    }
    for (int i = 0; i < row; ++i)
        delete [] matrix[i];
    delete [] matrix;
    matrix = n_mat;
    if (row != col)
        row ^= col ^= row ^= col;
}

__TPL
Matrix<T> Matrix<T>::operator+(const Matrix & other){
    if (row != other.row || col != other.col)
        throw "the shape of two matrix doesn't match for addition";
    Matrix<T> ret(row, col);
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            ret.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
    return ret;
}

__TPL
Matrix<T> Matrix<T>::operator*(const Matrix & other){
    if (col != other.row)
        throw "the shape of two matrix doesn't match for multiplying";
    Matrix<T> ret(row, col);
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < other.col; ++j)
            for (int k = 0; k < col; ++k)
                ret.matrix[i][j] = matrix[i][k] + other.matrix[k][j];
    return ret;
}

__TPL
std::string Matrix<T>::to_string(){
    std::string prefix("Matrix(");
    int front = prefix.length(), mid_row = col >> 1;
    std::string ret;
    for (int i = 0; i < row; ++i){
        ret.append(i != mid_row ? std::string(front, ' ') : prefix);
        if (!i)
            ret.append(" /");
        else if (i + 1 == row)
            ret.append(" \\");
        else
            ret.append("|");
        for (int j = 0; j < col; ++j){
            if (j)
                ret.append(", ");
            ret += std::to_string(matrix[i][j]);
        }
        ret.append("\n");
    }
    ret.append(")");
    return ret;
}