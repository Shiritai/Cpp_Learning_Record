# include "DensedMatrix.hpp"
# include <iostream>

int main(void){
    // Matrix m1(5, 4, 2);
    int ** data = new int*[3];
    for (int i = 0; i < 3; ++i){
        data[i] = new int [3];
        for (int j = 0; j < 3; ++j)
            data[i][j] = i * 3 + j;
    }
    // Matrix m2(2, 3, data);
    // Matrix m3 = Matrix::identity(5);
    // Matrix m4 = Matrix::zero(2, 6);
    // Matrix m5 = Matrix::fill(3, 4, 10);
    // Matrix m6 = Matrix::zero(8);
    // std::cout << m1.to_string() << std::endl;
    // std::cout << m2.to_string() << std::endl;
    // std::cout << m3.to_string() << std::endl;
    // std::cout << m4.to_string() << std::endl;
    // std::cout << m5.to_string() << std::endl;
    // std::cout << m6.to_string() << std::endl;

    // DensedMatrix m_1(3, 3, 1);
    DensedMatrix m_1(3, 3, data);
    DensedMatrix m_2 = DensedMatrix::identity(3);
    std::cout << (m_1 + m_1).to_string() << std::endl;
    std::cout << (m_1 + m_1).transpose().to_string() << std::endl;
    std::cout << (m_1 + m_2).to_string() << std::endl;
    std::cout << (m_1 + m_2).transpose().to_string() << std::endl;
    std::cout << (m_1 * m_1).to_string() << std::endl;
    std::cout << (m_1 * m_2).to_string() << std::endl;
    std::cout << (m_2 * m_1).to_string() << std::endl;
}