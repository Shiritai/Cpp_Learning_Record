# include "DensedMatrix.hpp"

DensedMatrix::DensedMatrix(int row, int col): row(row), col(col){
    matrix = new int*[row];
    for (int i = 0; i < row; ++i)
        matrix[i] = new int [col];
}

DensedMatrix::DensedMatrix(int row, int col, int val): DensedMatrix::DensedMatrix(row, col) {
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            matrix[i][j] = val;
}

DensedMatrix::DensedMatrix(int row, int col, int * arr[]): DensedMatrix::DensedMatrix(row, col) {
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            matrix[i][j] = arr[i][j];
}

DensedMatrix::~DensedMatrix(){
    for (int i = 0; i < row; ++i)
        delete [] matrix[i];
    delete [] matrix;
}

DensedMatrix DensedMatrix::zero(int row, int col){
    return DensedMatrix(row, col, 0);
}

DensedMatrix DensedMatrix::zero(int side_len){
    return DensedMatrix(side_len, side_len, 0);
}

DensedMatrix DensedMatrix::identity(int len){
    DensedMatrix ret(len, len, 0);
    for (int i = 0; i < len; ++i)
        ret.matrix[i][i] = 1;
    return ret;
}

DensedMatrix DensedMatrix::fill(int row, int col, int val){
    return DensedMatrix(row, col, val);
}

DensedMatrix DensedMatrix::transpose(void){
    DensedMatrix ret(col, row);
    for (int i = 0; i < col; ++i)
        for (int j = 0; j < row; ++j)
            ret.matrix[i][j] = matrix[j][i];
    return ret;
}

/* Time : O(row * col) */
DensedMatrix DensedMatrix::operator+(const DensedMatrix & other) const {
    if (row != other.row || col != other.col)
        throw "the shape of two matrix doesn't match for addition";
    DensedMatrix ret(row, col);
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            ret.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
    return ret;
}

/* Time : O(row * col * other.col) */
DensedMatrix DensedMatrix::operator*(const DensedMatrix & other) const {
    if (col != other.row)
        throw "the shape of two matrix doesn't match for multiplying";
    DensedMatrix ret(row, other.col);
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < other.col; ++j){
            int sum = 0;
            for (int k = 0; k < col; ++k)
                sum += matrix[i][k] * other.matrix[k][j];
            ret.matrix[i][j] = sum;
        }

    }
    return ret;
}

std::string DensedMatrix::to_string() const {
    std::string prefix("Densed Matrix(");
    int front = prefix.length(), mid_row = row >> 1;
    std::string ret;
    for (int i = 0; i < row; ++i){
        ret.append(i != mid_row ? std::string(front, ' ') : prefix);
        if (!i)
            ret.append("/ ");
        else if (i + 1 == row)
            ret.append("\\ ");
        else
            ret.append("| ");
        for (int j = 0; j < col; ++j){
            if (j)
                ret.append(", ");
            ret += std::to_string(matrix[i][j]);
        }
        if (!i)
            ret.append(" \\");
        else if (i + 1 == row)
            ret.append(" /");
        else
            ret.append(" |");
        ret.append(i != mid_row ? "\n" : ")\n");
    }
    return ret;
}