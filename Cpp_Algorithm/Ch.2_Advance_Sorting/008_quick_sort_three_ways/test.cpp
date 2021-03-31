# include <iostream>
using namespace std;

int main(void){
    int i = 10;
    // cout << ((i >> 31) & 1 ? -1 : 1) << endl;
    cout << !!i * ((i >> 31) & 1 ? -1 : 1) << endl;
}