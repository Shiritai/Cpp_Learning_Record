# include "SparseMatrix.hpp"
# include <iostream>
# include <cassert>

# define BASIC_CAPACITY 8

SparseMatrix::SparseMatrix(int rows, int cols, int capacity): \
    rows(rows), cols(cols), size(0), capacity(capacity) {
    matrix = new ele[capacity];
}

SparseMatrix::SparseMatrix(int rows, int cols): SparseMatrix(rows, cols, BASIC_CAPACITY) {}

/* Initialize a matrix with a DensedMatrix */
SparseMatrix::SparseMatrix(int rows, int cols, Number * arr[]): SparseMatrix(rows, cols) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (arr[i][j])
                add_term(i, j, arr[i][j]);
}

SparseMatrix::~SparseMatrix(){
    delete [] matrix;
}

/* 可添加重複項, 會以最新添加的為主 */
void SparseMatrix::add_term(int r, int c, Number val){
    if (size + 1 >= capacity)
        __resize(capacity << 1);
    if (!size || (r * cols + c > matrix[size - 1].r * cols + matrix[size - 1].c)){ // 為順序添加加速
        matrix[size++] = ele(r, c, val);
        return;
    }
    for (int i = 0; i <= size; ++i){
        if (r == matrix[i].r && c == matrix[i].c){
            matrix[i].val = val;
            ++size;
            return;
        }
        else if (r * cols + c > matrix[i].r * cols + matrix[i].c && \
            (i == size || r * cols + c < matrix[i + 1].r * cols + matrix[i + 1].c)){
            for (int j = size; j > i; --j)
                matrix[j] = matrix[j - 1];
            matrix[i] = ele(r, c, val);
            ++size;
            return;
        }
    }
    throw "Error occurs while adding term";
}

/**
 * Use fast_transpose, i.e. the thought of Counting sort
 * 用 Counting sort 來複製出新矩陣
 * Time : O(size + cols), very fast
 */
SparseMatrix SparseMatrix::transpose(void) const {
    if (!size)
        return zero(cols, rows);
    /* Prepare counting table */
    int cntTable[cols];
    for (int i = 0; i < cols; cntTable[i++] = 0);
    for (int i = 0; i < size; ++i)
        ++cntTable[matrix[i].c];
    int minus = cntTable[0];
    for (int i = 1; i < cols; ++i){
        cntTable[i] += cntTable[i - 1];
        cntTable[i - 1] -= minus;
    }
    cntTable[cols - 1] -= minus;
    
    /* Fill a new matrix */
    SparseMatrix ret(cols, rows, capacity);
    ret.size = size;
    for (int i = 0; i < size; ++i){
        int ind = cntTable[matrix[i].c]++;
        ret.matrix[ind] = ele(matrix[i].c, matrix[i].r, matrix[i].val);
    }
    std::cout << "Transpose (size = " << ret.size << "; capacity = " << ret.capacity << ")\n" << ret.to_string() << std::endl;
    return ret;
}

SparseMatrix SparseMatrix::operator+(const SparseMatrix & other) const {
    if (rows != other.rows || cols != other.cols)
        throw "Error occurs while adding matrix, since the shape of matrixes are different";
    int pos = 0, o_pos = 0, sz = 0;
    SparseMatrix ret(rows, cols, capacity > other.capacity ? capacity : other.capacity);
    while (pos < size && o_pos < other.size){
        int ind = matrix[pos].r * cols + matrix[pos].c;
        int o_ind = other.matrix[o_pos].r * cols + other.matrix[o_pos].c;
        
        int tmp;
        if (ind == o_ind && (tmp = matrix[pos].val + other.matrix[o_pos].val)){
            ret.add_term(matrix[pos].r, matrix[pos].c, tmp);
            ++pos, ++o_pos, ++sz;
        }
        else if (ind < o_ind){
            ret.add_term(matrix[pos].r, matrix[pos].c, matrix[pos].val);
            ++pos, ++sz;
        }
        else {
            ret.add_term(other.matrix[o_pos].r, other.matrix[o_pos].c, other.matrix[o_pos].val);
            ++o_pos, ++sz;
        }
    }
    while (pos < size){
        ret.add_term(matrix[pos].r, matrix[pos].c, matrix[pos].val);
        ++pos, ++sz;
    }
    while (o_pos < size){
        ret.add_term(other.matrix[o_pos].r, other.matrix[o_pos].c, other.matrix[o_pos].val);
        ++o_pos, ++sz;
    }
    ret.size = sz;
    return ret;
}

/* O(size + cols) */
SparseMatrix SparseMatrix::operator*(const SparseMatrix & other) const {
    if (cols != other.rows)
        throw "Error occurs while multiplying matrix, since the shape (row-column) of matrixes aren't match";
    if (!size || !other.size)
        return zero(rows, other.cols);
    
    SparseMatrix t_other(rows, other.cols);
    t_other = other.transpose();
    // std::cout << "Transpose (size = " << t_other.size << "; capacity = " << t_other.capacity << ")\n" << t_other.to_string() << std::endl;
    int sz = 0;
    SparseMatrix ret(rows, other.cols, capacity > other.capacity ? capacity : other.capacity);
    
    int rowInd[rows], colInd[cols];
    const int INVALID = -1;
    for (int i = 0; i < rows; rowInd[i++] = INVALID);
    for (int i = 0; i < cols; colInd[i++] = INVALID);

    for (int i = 0, curR = INVALID; i < size; ++i)
        if (matrix[i].r != curR)
            rowInd[matrix[i].r] = i;
    for (int i = 0, curC = INVALID; i < t_other.size; ++i)
        if (t_other.matrix[i].r != curC)
            colInd[t_other.matrix[i].r] = i;

    for (int i = 0; i < rows; ++i)
        std::cout << rowInd[i] << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < cols; ++i)
        std::cout << colInd[i] << std::endl;
    
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            int pos = rowInd[i], o_pos = colInd[j];

            if (pos != INVALID && o_pos != INVALID){
                Number sum = 0;

                while (matrix[pos].r == i && t_other.matrix[o_pos].r == j){
                    if (matrix[pos].c == t_other.matrix[o_pos].c)
                        sum += matrix[pos++].val * t_other.matrix[o_pos++].val;
                    else if (matrix[pos].c < t_other.matrix[o_pos].c)
                        ++pos;
                    else 
                        ++o_pos;
                }
                
                if (sum){
                    ret.add_term(i, j, sum);
                    ++sz;
                }
            }
        }
    }

    ret.size = sz;
    return ret;
}

SparseMatrix & SparseMatrix::operator=(const SparseMatrix & other){
    if (matrix)
        delete [] matrix;
    rows = other.rows;
    cols = other.cols;
    capacity = other.capacity;
    size = other.size;
    matrix = new ele[capacity];
    for (int i = 0; i < size; ++i)
        matrix[i] = other.matrix[i];
    return * this;
}

void SparseMatrix::__resize(int n_cap){
    assert(n_cap > size);
    ele * n_matrix = new ele[n_cap];
    for (int i = 0; i < size; ++i)
        n_matrix[i] = matrix[i];
    delete [] matrix;
    capacity = n_cap;
    matrix = n_matrix;
}

std::string SparseMatrix::to_string() const {
    std::string prefix("Sparse Matrix(");
    int front = prefix.length(), mid_row = rows >> 1;
    ele * arr = size ? matrix : zero(rows, cols).matrix;
    std::string ret;
    for (int i = 0, pos = 0; i < rows; ++i){
        ret.append(i != mid_row ? std::string(front, ' ') : prefix);
        if (!i)
            ret.append("/ ");
        else if (i + 1 == rows)
            ret.append("\\ ");
        else
            ret.append("| ");
        for (int j = 0; j < cols; ++j){
            if (j)
                ret.append(", ");
            if (arr[pos].r == i && arr[pos].c == j)
                ret += std::to_string(arr[pos++].val);
            else 
                ret += "0";
        }
        if (!i)
            ret.append(" \\");
        else if (i + 1 == rows)
            ret.append(" /");
        else
            ret.append(" |");
        ret.append(i != mid_row ? "\n" : ")\n");
    }
    return ret;
}

SparseMatrix SparseMatrix::identity(int side_len){
    SparseMatrix ret(side_len, side_len, side_len);
    for (int i = 0; i < side_len; ++i)
        ret.add_term(i, i, 1);
    return ret;
}

SparseMatrix SparseMatrix::zero(int side_len){
    return SparseMatrix(side_len, side_len);
}

SparseMatrix SparseMatrix::zero(int rows, int cols){
    return SparseMatrix(rows, cols);
}
