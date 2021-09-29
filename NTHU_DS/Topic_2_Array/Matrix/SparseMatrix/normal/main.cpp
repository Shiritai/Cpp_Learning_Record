# include "SparseMatrix.hpp"
# include <iostream>

using namespace std;

# define SZ 4
# define SQ 2

int main(void){
    cout << "[debug] not finished yet...\n";
    
    int ** data = new int*[SZ];
    for (int i = 0; i < SZ; ++i){
        data[i] = new int[SZ];
        for(int j = 0; j < SZ; ++j)
            data[i][j] = i * SZ + j + 1;
    }
    SparseMatrix m1(SQ, SQ);
    SparseMatrix m2(SZ, SZ, data);
    auto m3 = SparseMatrix::identity(SZ);
    auto m4 = SparseMatrix::zero(SZ);

    // cout << "1\n" << m1.to_string() << endl;
    // cout << "2\n" << m2.to_string() << endl;
    // cout << "3\n" << m3.to_string() << endl;
    // cout << "4\n" << (m3 * m4).to_string() << endl;
    cout << "5\n" << (m3 * m2).to_string() << endl;
    cout << "5\n" << (m2 * m3).to_string() << endl;
    cout << "6\n" << m4.to_string() << endl;
    cout << "7\n" << (m3 + m4).to_string() << endl;
    cout << "8\n" << (m3 + m3).to_string() << endl;
    cout << "9\n" << (m2 + m4 + m3).to_string() << endl;
}