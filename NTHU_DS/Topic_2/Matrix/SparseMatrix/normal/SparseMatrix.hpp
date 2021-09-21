# ifndef _SPARSE_MATRIX_HPP
# define _SPARSE_MATRIX_HPP

typedef int Number;

# include <string>

class SparseMatrix {
public:
    SparseMatrix(int rows, int cols);
    SparseMatrix(int rows, int cols, int capacity);
    SparseMatrix(int rows, int cols, Number * arr[]);
    void add_term(int r, int c, Number val);
    SparseMatrix transpose(void) const;
    SparseMatrix operator+(const SparseMatrix & other) const;
    SparseMatrix operator*(const SparseMatrix & other) const;
    SparseMatrix & operator=(const SparseMatrix & other);

    std::string to_string() const;
    
    ~SparseMatrix();

    static SparseMatrix identity(int side_len);
    static SparseMatrix zero(int side_len);
    static SparseMatrix zero(int rows, int cols);
private:
    void __resize(int n_cap);
    struct ele {
        int r, c;
        Number val;
        ele(int r, int c, Number val){
            this->r = r, this->c = c, this->val = val;
        }
        ele(){
            this->r = -1, this->c = -1, this->val = -1;
        }
    };
    ele * matrix;
    int rows, cols, size, capacity;
};


# endif