# ifndef _DENSEDMATRIX_HPP
# define _DENSEDMATRIX_HPP

# include <string>

class DensedMatrix {
public:
    /* Initialize a matrix with "val" */
    DensedMatrix(int row, int col, int val);

    /* Initialize a matrix according to a 2-dimension array */
    DensedMatrix(int row, int col, int * arr[]);

    ~DensedMatrix();

    /* Return a zero matrix */
    static DensedMatrix zero(int row, int col);
    
    static DensedMatrix zero(int side_len);
    
    /* Return a identity matrix */
    static DensedMatrix identity(int side_len);
    
    /* Return a matrix filled with "val" */
    static DensedMatrix fill(int row, int col, int val);

    DensedMatrix transpose(void) const;
    DensedMatrix operator+(const DensedMatrix & other) const;
    DensedMatrix operator*(const DensedMatrix & other) const;
    std::string to_string() const;

private:
    DensedMatrix(int row, int col); // 所有 matrix 內容都不會被初始化
    int ** matrix;
    int row, col;
};

# endif