# include "Matrix.hpp"
# include <iostream>

int main(void){
    Matrix<int> m1(2, 3, 2);
    // int ** data = new int*[2];
    // for (int i  = 0; i < 2; ++i){
    //     data[i] = new int [3];
    //     for (int j = 0; j < 3; ++j)
    //         data[i][j] = i * 3 + j;
    // }
    // Matrix<int> m2(2, 3, data);
    std::cout << m1.to_string() << std::endl;
    // std::cout << m2.to_string() << std::endl;
}